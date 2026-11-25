// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vviterbi_accelerator__pch.h"

//============================================================
// Constructors

Vviterbi_accelerator::Vviterbi_accelerator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vviterbi_accelerator{_vcontextp__, _vcname__, true} {}

Vviterbi_accelerator::Vviterbi_accelerator(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vviterbi_accelerator__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->vlInst.TOP.__VprimaryPorts.clk}
    , rst{vlSymsp->vlInst.TOP.__VprimaryPorts.rst}
    , load_context{vlSymsp->vlInst.TOP.__VprimaryPorts.load_context}
    , initial_metrics{vlSymsp->vlInst.TOP.__VprimaryPorts.initial_metrics}
    , start{vlSymsp->vlInst.TOP.__VprimaryPorts.start}
    , received{vlSymsp->vlInst.TOP.__VprimaryPorts.received}
    , output_table{vlSymsp->vlInst.TOP.__VprimaryPorts.output_table}
    , busy{vlSymsp->vlInst.TOP.__VprimaryPorts.busy}
    , done{vlSymsp->vlInst.TOP.__VprimaryPorts.done}
    , configured{vlSymsp->vlInst.TOP.__VprimaryPorts.configured}
    , metrics{vlSymsp->vlInst.TOP.__VprimaryPorts.metrics}
    , survivors{vlSymsp->vlInst.TOP.__VprimaryPorts.survivors}
    , metric_overflow{vlSymsp->vlInst.TOP.__VprimaryPorts.metric_overflow}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vviterbi_accelerator::Vviterbi_accelerator(const char* _vcname__)
    : Vviterbi_accelerator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vviterbi_accelerator::~Vviterbi_accelerator() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vviterbi_accelerator___024root___eval_debug_assertions(Vviterbi_accelerator___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_static(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_initial(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD bool Vviterbi_accelerator___024root___eval_stl(Vviterbi_accelerator___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vviterbi_accelerator___024root___eval_sample(Vviterbi_accelerator___024root* vlSelf);
bool Vviterbi_accelerator___024root___eval_ico(Vviterbi_accelerator___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vviterbi_accelerator___024root___eval_act(Vviterbi_accelerator___024root* vlSelf);
bool Vviterbi_accelerator___024root___eval_inact(Vviterbi_accelerator___024root* vlSelf);
bool Vviterbi_accelerator___024root___eval_nba(Vviterbi_accelerator___024root* vlSelf);
bool Vviterbi_accelerator___024root___eval_obs(Vviterbi_accelerator___024root* vlSelf);
bool Vviterbi_accelerator___024root___eval_react(Vviterbi_accelerator___024root* vlSelf);
void Vviterbi_accelerator___024root___eval_postponed(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_final(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__stl(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__ico(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__act(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__nba(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__obs(Vviterbi_accelerator___024root* vlSelf);
VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__react(Vviterbi_accelerator___024root* vlSelf);

void Vviterbi_accelerator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vviterbi_accelerator::eval_step\n"); );
    m_evalLoop.eval();
}

void Vviterbi_accelerator::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vviterbi_accelerator___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vviterbi_accelerator::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vviterbi_accelerator::evalStatic() {
    Vviterbi_accelerator___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vviterbi_accelerator::evalInitial() {
    Vviterbi_accelerator___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalStl(bool firstIteration) {
    return Vviterbi_accelerator___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vviterbi_accelerator::evalSample() {
    Vviterbi_accelerator___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalIco(bool firstIteration) {
    return Vviterbi_accelerator___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vviterbi_accelerator::evalAct() {
    return Vviterbi_accelerator___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalInact() {
    return Vviterbi_accelerator___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalNba() {
    return Vviterbi_accelerator___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalObs() {
    return Vviterbi_accelerator___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vviterbi_accelerator::evalReact() {
    return Vviterbi_accelerator___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vviterbi_accelerator::evalPostponed() {
    Vviterbi_accelerator___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vviterbi_accelerator::evalFinal() {
    Vviterbi_accelerator___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersStl() {
    Vviterbi_accelerator___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersIco() {
    Vviterbi_accelerator___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersAct() {
    Vviterbi_accelerator___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersNba() {
    Vviterbi_accelerator___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersObs() {
    Vviterbi_accelerator___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vviterbi_accelerator::dumpTriggersReact() {
    Vviterbi_accelerator___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vviterbi_accelerator::eventsPending() { return false; }

uint64_t Vviterbi_accelerator::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vviterbi_accelerator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vviterbi_accelerator::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vviterbi_accelerator::hierName() const { return vlSymsp->name(); }
const char* Vviterbi_accelerator::modelName() const { return "Vviterbi_accelerator"; }
unsigned Vviterbi_accelerator::threads() const { return 1; }
void Vviterbi_accelerator::prepareClone() const { contextp()->prepareClone(); }
void Vviterbi_accelerator::atClone() const {
    contextp()->threadPoolpOnClone();
}
