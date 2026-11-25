#!/usr/bin/env python3
"""Render actual simulation traces as a self-contained browser report. Stdlib only."""
import csv
import json
from pathlib import Path

root = Path(__file__).resolve().parent.parent
build = root / 'build'
def read(name):
    with (build / name).open() as f:
        return [{k: int(v) for k, v in row.items()} for row in csv.DictReader(f)]
rows = read('acs_trace.csv')
commits = read('commits.csv')
if not rows or not commits:
    raise SystemExit('No completed trace data. Run sh scripts/visualize.sh first.')
# Check trace completeness and correspondence to published DUT outputs.
for request in sorted({r['request'] for r in rows}):
    rr = [r for r in rows if r['request'] == request]
    cc = [c for c in commits if c['request'] == request]
    assert len(rr) == len(cc) == 32, 'Incomplete request'
    assert {r['state'] for r in rr} == set(range(32))
    for c in cc:
        a = next(r for r in rr if r['state'] == c['state'])
        assert (a['new_metric'], a['survivor']) == (c['metric'], c['survivor'])
html = r'''<!doctype html>
<html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Viterbi: inside a metric update</title>
<style>
*{box-sizing:border-box}body{margin:0;background:#f2f5fa;color:#17263c;font:16px system-ui,sans-serif}main{max-width:1200px;margin:auto;padding:30px}h1{font-size:30px;margin-bottom:8px}h2{font-size:20px}p{line-height:1.5}.muted{color:#53637a}.controls,.panel{background:white;border:1px solid #d4deea;border-radius:12px;padding:20px;margin:18px 0}.controls{display:flex;align-items:center;gap:16px;flex-wrap:wrap}button,select{padding:8px;font:inherit}input{min-width:180px;flex:1}.flow{display:flex;gap:8px;align-items:center;flex-wrap:wrap}.box{padding:12px;border-radius:8px;background:#edf2f8}.active{background:#d5f6e8;border:2px solid #148560}.grid{display:grid;grid-template-columns:repeat(4,1fr);gap:12px}.lane{background:#f5f8fc;padding:14px;border:1px solid #d4deea;border-radius:10px}.branch{padding:8px;margin:8px 0;background:white;border:2px solid transparent}.winner{border-color:#148560;background:#e5f7ef}.metric-grid{display:grid;grid-template-columns:repeat(8,1fr);gap:7px}.cell{padding:8px;background:#f0f3f8;border-radius:6px;font-size:14px}.cell.updated{background:#d5f6e8}.cell small{display:block;color:#53637a}table{border-collapse:collapse;width:100%}td,th{text-align:left;padding:7px;border-bottom:1px solid #d4deea}summary{cursor:pointer}code{font-size:14px}@media(max-width:850px){.grid{grid-template-columns:repeat(2,1fr)}.metric-grid{grid-template-columns:repeat(4,1fr)}}@media(max-width:480px){.grid{grid-template-columns:1fr}main{padding:12px}}
</style><main>
<h1>Inside one Viterbi metric update</h1>
<p class="muted">Actual DUT simulation data • K=6 • 32 states • four parallel ACS units • hard decisions</p>
<p>Select a received symbol, then step through its eight compute edges and final commit. Green highlights the selected branch or newly written metric. This shows metric computation, not traceback or decoded message bits.</p>
<div class="controls"><label>Request <select id="request"></select></label><button id="prev">← Back</button><input aria-label="Cycle" id="cycle" type="range" min="0" max="9" value="1"><button id="next">Next →</button><strong id="phase"></strong></div>
<div class="panel"><div class="flow" id="flow"></div><p id="status"></p></div>
<h2>Four ACS calculations at this edge</h2><p class="muted">Each branch adds its Hamming distance to the predecessor's old metric. Lower cost wins; ties select A. INF means unreachable.</p><div class="grid" id="lanes"></div>
<div class="panel"><h2 id="current-title">Current metric table</h2><div class="metric-grid" id="current"></div></div>
<div class="panel"><h2>Pending metric table</h2><p class="muted">These results accumulate four at a time. All computations still read the old current table. “—” means not written for this request yet; the physical register may contain older data.</p><div class="metric-grid" id="pending"></div></div>
<div class="panel"><h2>Survivor decisions</h2><p class="muted">Pending decisions appear during compute and publish together at commit. 0 selects predecessor A; 1 selects B. Decisions for unreachable states are placeholders.</p><div class="metric-grid" id="survivors"></div></div>
<details class="panel"><summary>Expected-output lookup table: all 64 transitions</summary><p>This table is latched on start and does not update during computation. Entry = 32 × input bit + predecessor state. The changing metric table above is separate from FPGA LUT resource counts.</p><table><thead><tr><th>Predecessor</th><th>Input 0: expected symbol</th><th>Input 1: expected symbol</th></tr></thead><tbody id="lookup"></tbody></table></details>
<p class="muted">Example-code test inputs, not a measured channel transmission. Trace values are captured before each compute edge and after commit; the existing independent scoreboard checks every completed column. The report generator also checks trace results against committed DUT outputs.</p>
</main><script>
const data=__DATA__;
const $=id=>document.getElementById(id), bin=n=>n.toString(2).padStart(2,'0');
const ids=[...new Set(data.rows.map(r=>r.request))];
$('request').innerHTML=ids.map(i=>`<option>${i}</option>`).join('');
function render(){
 const req=+$('request').value,c=+$('cycle').value,rs=data.rows.filter(r=>r.request===req),cs=data.commits.filter(r=>r.request===req),inf=rs[0].infinity;
 const fmt=n=>n>=inf?'INF':n;
 const old=Array(32),lut=[Array(32),Array(32)];
 rs.forEach(r=>{old[r.pred_a]=r.metric_a;old[r.pred_b]=r.metric_b;lut[r.state>>4][r.pred_a]=r.expected_a;lut[r.state>>4][r.pred_b]=r.expected_b});
 const current=c===9?Array.from({length:32},(_,s)=>cs.find(r=>r.state===s).metric):old;
 $('phase').textContent=c===0?'E0: Accept':c===9?'E9: Commit':`E${c}: Compute ${c}/8`;
 $('flow').innerHTML=[['Latch symbol + table',c===0],['Old metrics → 4 × ACS',c>0&&c<9],['Pending metrics',c>0&&c<9],['Commit → done',c===9]].map(([t,a])=>`<span class="box ${a?'active':''}">${t}</span>`).join('<span>→</span>');
 $('status').textContent=`Received symbol: ${bin(rs[0].received)}. `+(c===0?'Inputs captured; busy=1, done=0.':c===9?'All 32 metrics and survivors published; busy=0, done=1.':`States ${(c-1)*4}–${c*4-1} written to pending storage; busy=1, done=0. Current metrics remain unchanged.`);
 $('lanes').innerHTML=c===0||c===9?'<p>No ACS result is written at this edge.</p>':rs.filter(r=>r.cycle===c).map(r=>{
  const branch=(name,p,m,e,d,win)=>`<div class="branch ${win?'winner':''}"><strong>${name}: state ${p}</strong><br>Expected ${bin(e)} ⊕ received ${bin(r.received)}<br>Distance = ${d}<br>${fmt(m)} + ${d} = ${m===inf?'INF':m+d}${win?' ✓':''}</div>`;
  return `<div class="lane"><strong>ACS ${r.lane} → state ${r.state}</strong>${branch('A',r.pred_a,r.metric_a,r.expected_a,r.distance_a,!r.survivor)}${branch('B',r.pred_b,r.metric_b,r.expected_b,r.distance_b,r.survivor)}<strong>New metric: ${fmt(r.new_metric)}</strong><br>Survivor: ${r.survivor}</div>`
 }).join('');
 function cells(fn){return Array.from({length:32},(_,s)=>{const r=rs.find(r=>r.state===s);return `<div class="cell ${c===9||(c>0&&r.cycle===c)?'updated':''}"><small>State ${s}</small>${fn(s,r)}</div>`}).join('')}
 $('current').innerHTML=cells(s=>fmt(current[s]));
 // Current bank is unchanged during compute, so only highlight it at commit.
 if(c!==9)$('current').querySelectorAll('.updated').forEach(e=>e.classList.remove('updated'));
 $('current-title').textContent=c===9?'Current metric table — committed result':'Current metric table — old column';
 $('pending').innerHTML=cells((s,r)=>r.cycle<=c?fmt(r.new_metric):'—');
 $('survivors').innerHTML=cells((s,r)=>r.cycle<=c?`${r.survivor} → predecessor ${r.survivor?r.pred_b:r.pred_a}`:'—');
 $('lookup').innerHTML=Array.from({length:32},(_,s)=>`<tr><td>${s}</td><td>${bin(lut[0][s])}</td><td>${bin(lut[1][s])}</td></tr>`).join('');
 $('prev').disabled=c===0;$('next').disabled=c===9;
}
$('request').onchange=render;$('cycle').oninput=render;
$('prev').onclick=()=>{$('cycle').value=Math.max(0,+$('cycle').value-1);render()};
$('next').onclick=()=>{$('cycle').value=Math.min(9,+$('cycle').value+1);render()};render();
</script></html>'''
(build / 'viterbi_trace.html').write_text(html.replace('__DATA__', json.dumps({'rows': rows, 'commits': commits})))
print(f'Report generated and trace/commit consistency checked: {len(commits)//32} requests.')
