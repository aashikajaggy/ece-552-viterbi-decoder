// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vviterbi_accelerator.h for the primary calling header

#ifndef VERILATED_VVITERBI_ACCELERATOR___024ROOT_H_
#define VERILATED_VVITERBI_ACCELERATOR___024ROOT_H_  // guard

#include "verilated.h"


class Vviterbi_accelerator__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vviterbi_accelerator___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(rst,0,0);
            VL_IN8(load_context,0,0);
            VL_INW(initial_metrics,511,0,16);
            VL_IN8(start,0,0);
            VL_IN8(received,1,0);
            VL_INW(output_table,127,0,4);
            VL_OUT8(busy,0,0);
            VL_OUT8(done,0,0);
            VL_OUT8(configured,0,0);
            VL_OUTW(metrics,511,0,16);
            VL_OUT(survivors,31,0);
            VL_OUT8(metric_overflow,0,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*1:0*/ viterbi_accelerator__DOT__symbol_q;
    ::CData/*3:0*/ viterbi_accelerator__DOT__decisions;
    ::CData/*0:0*/ viterbi_accelerator__DOT__ctrl__DOT__accept;
    ::CData/*0:0*/ viterbi_accelerator__DOT__ctrl__DOT__initialize;
    ::CData/*2:0*/ viterbi_accelerator__DOT__ctrl__DOT__group_index;
    ::CData/*1:0*/ viterbi_accelerator__DOT__ctrl__DOT__state;
    ::CData/*0:0*/ __Vdfg_Regularize_133;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__load_context__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__start__0;
    ::CData/*1:0*/ __Vtrigprevexpr___TOP__received__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__;
    ::SData/*15:0*/ viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__;
    ::VlWide<4>/*127:0*/ viterbi_accelerator__DOT__table_q;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen;
    ::IData/*31:0*/ viterbi_accelerator__DOT__storage__DOT__pending_survivors;
    ::VlWide<16>/*511:0*/ __Vtrigprevexpr___TOP__initial_metrics__0;
    ::VlWide<4>/*127:0*/ __Vtrigprevexpr___TOP__output_table__0;
    ::QData/*63:0*/ viterbi_accelerator__DOT__next_metrics;
    ::VlUnpacked<::SData/*15:0*/, 32> viterbi_accelerator__DOT__storage__DOT__pending;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vviterbi_accelerator__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vviterbi_accelerator___024root(Vviterbi_accelerator__Syms* symsp, const char* namep);
    ~Vviterbi_accelerator___024root();
    VL_UNCOPYABLE(Vviterbi_accelerator___024root);
    VL_UNMOVABLE(Vviterbi_accelerator___024root);

    // INTERNAL METHODS
};


#endif  // guard
