// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vviterbi_accelerator.h for the primary calling header

#include "Vviterbi_accelerator__pch.h"

void Vviterbi_accelerator___024root___eval_sample(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_sample\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vviterbi_accelerator___024root___eval_triggers_vec__ico(Vviterbi_accelerator___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vviterbi_accelerator___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

bool Vviterbi_accelerator___024root___eval_ico(Vviterbi_accelerator___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_ico\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    Vviterbi_accelerator___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vviterbi_accelerator___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vviterbi_accelerator___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((2ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.__Vdfg_Regularize_133 
                        = (1U & (~ ((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                    | (::IData)(vlSelfRef.__VprimaryPorts.busy))));
                }
            }
            if ((((6ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__1
                    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__initialize 
                        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
                           & (::IData)(vlSelfRef.__VprimaryPorts.load_context));
                }
            }
            if ((((0x0000000000000016ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__2
                    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__accept 
                        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
                           & ((::IData)(vlSelfRef.__VprimaryPorts.configured) 
                              & ((~ (::IData)(vlSelfRef.__VprimaryPorts.load_context)) 
                                 & (::IData)(vlSelfRef.__VprimaryPorts.start))));
                }
            }
        }
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vviterbi_accelerator___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vviterbi_accelerator___024root___eval_act(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_act\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                             & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vviterbi_accelerator___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vviterbi_accelerator___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vviterbi_accelerator___024root___eval_inact(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_inact\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vviterbi_accelerator___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vviterbi_accelerator___024root___nba_sequent__TOP__0(Vviterbi_accelerator___024root* vlSelf);
void Vviterbi_accelerator___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vviterbi_accelerator___024root___eval_nba(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_nba\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vviterbi_accelerator___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vviterbi_accelerator___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vviterbi_accelerator___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vviterbi_accelerator___024root___eval_obs(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_obs\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vviterbi_accelerator___024root___eval_react(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_react\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vviterbi_accelerator___024root___eval_postponed(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_postponed\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vviterbi_accelerator___024root___eval_triggers_vec__ico(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_triggers_vec__ico\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                        ((((0U 
                                                            != 
                                                            ((((vlSelfRef.__VprimaryPorts.output_table[0U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[0U]) 
                                                               | (vlSelfRef.__VprimaryPorts.output_table[1U] 
                                                                  ^ vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[1U])) 
                                                              | (vlSelfRef.__VprimaryPorts.output_table[2U] 
                                                                 ^ vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[2U])) 
                                                             | (vlSelfRef.__VprimaryPorts.output_table[3U] 
                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[3U]))) 
                                                           << 6U) 
                                                          | ((((::IData)(vlSelfRef.__VprimaryPorts.received) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__received__0)) 
                                                              << 5U) 
                                                             | (((::IData)(vlSelfRef.__VprimaryPorts.start) 
                                                                 != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__start__0)) 
                                                                << 4U))) 
                                                         | ((((0U 
                                                               != 
                                                               ((((((((((((((((vlSelfRef.__VprimaryPorts.initial_metrics[0U] 
                                                                               ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[0U]) 
                                                                              | (vlSelfRef.__VprimaryPorts.initial_metrics[1U] 
                                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[1U])) 
                                                                             | (vlSelfRef.__VprimaryPorts.initial_metrics[2U] 
                                                                                ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[2U])) 
                                                                            | (vlSelfRef.__VprimaryPorts.initial_metrics[3U] 
                                                                               ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[3U])) 
                                                                           | (vlSelfRef.__VprimaryPorts.initial_metrics[4U] 
                                                                              ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[4U])) 
                                                                          | (vlSelfRef.__VprimaryPorts.initial_metrics[5U] 
                                                                             ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[5U])) 
                                                                         | (vlSelfRef.__VprimaryPorts.initial_metrics[6U] 
                                                                            ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[6U])) 
                                                                        | (vlSelfRef.__VprimaryPorts.initial_metrics[7U] 
                                                                           ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[7U])) 
                                                                       | (vlSelfRef.__VprimaryPorts.initial_metrics[8U] 
                                                                          ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[8U])) 
                                                                      | (vlSelfRef.__VprimaryPorts.initial_metrics[9U] 
                                                                         ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[9U])) 
                                                                     | (vlSelfRef.__VprimaryPorts.initial_metrics[10U] 
                                                                        ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[10U])) 
                                                                    | (vlSelfRef.__VprimaryPorts.initial_metrics[11U] 
                                                                       ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[11U])) 
                                                                   | (vlSelfRef.__VprimaryPorts.initial_metrics[12U] 
                                                                      ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[12U])) 
                                                                  | (vlSelfRef.__VprimaryPorts.initial_metrics[13U] 
                                                                     ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[13U])) 
                                                                 | (vlSelfRef.__VprimaryPorts.initial_metrics[14U] 
                                                                    ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[14U])) 
                                                                | (vlSelfRef.__VprimaryPorts.initial_metrics[15U] 
                                                                   ^ vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[15U]))) 
                                                              << 3U) 
                                                             | (((::IData)(vlSelfRef.__VprimaryPorts.load_context) 
                                                                 != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__load_context__0)) 
                                                                << 2U)) 
                                                            | ((((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                                 != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)) 
                                                                << 1U) 
                                                               | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__load_context__0 
        = vlSelfRef.__VprimaryPorts.load_context;
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[0U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[1U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[2U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[3U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[3U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[4U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[4U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[5U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[5U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[6U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[6U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[7U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[7U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[8U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[8U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[9U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[9U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[10U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[10U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[11U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[11U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[12U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[12U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[13U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[13U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[14U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[14U];
    vlSelfRef.__Vtrigprevexpr___TOP__initial_metrics__0[15U] 
        = vlSelfRef.__VprimaryPorts.initial_metrics[15U];
    vlSelfRef.__Vtrigprevexpr___TOP__start__0 = vlSelfRef.__VprimaryPorts.start;
    vlSelfRef.__Vtrigprevexpr___TOP__received__0 = vlSelfRef.__VprimaryPorts.received;
    vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[0U] 
        = vlSelfRef.__VprimaryPorts.output_table[0U];
    vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[1U] 
        = vlSelfRef.__VprimaryPorts.output_table[1U];
    vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[2U] 
        = vlSelfRef.__VprimaryPorts.output_table[2U];
    vlSelfRef.__Vtrigprevexpr___TOP__output_table__0[3U] 
        = vlSelfRef.__VprimaryPorts.output_table[3U];
}

bool Vviterbi_accelerator___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vviterbi_accelerator___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const ::VlUnpacked<::CData/*2:0*/, 128> Vviterbi_accelerator__ConstPool__CONSARRAY_0;
extern const ::VlUnpacked<::CData/*1:0*/, 128> Vviterbi_accelerator__ConstPool__CONSARRAY_1;
extern const ::VlUnpacked<::CData/*2:0*/, 128> Vviterbi_accelerator__ConstPool__CONSARRAY_2;
extern const ::VlUnpacked<::CData/*0:0*/, 128> Vviterbi_accelerator__ConstPool__CONSARRAY_3;

void Vviterbi_accelerator___024root___nba_sequent__TOP__0(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___nba_sequent__TOP__0\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_b;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_b = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_a;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_a = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_b;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_b = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_a;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_a = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_b;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_b = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_a;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_a = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_b;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_b = 0;
    ::SData/*15:0*/ viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_a;
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_a = 0;
    ::CData/*0:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__survivor;
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__survivor = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__ca;
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__ca = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__cb;
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__cb = 0;
    ::CData/*0:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__survivor;
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__survivor = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__ca;
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__ca = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__cb;
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__cb = 0;
    ::CData/*0:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__survivor;
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__survivor = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__ca;
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__ca = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__cb;
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__cb = 0;
    ::CData/*0:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__survivor;
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__survivor = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__ca;
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__ca = 0;
    ::IData/*16:0*/ viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__cb;
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__cb = 0;
    ::CData/*6:0*/ __Vtableidx_0;
    __Vtableidx_0 = 0;
    ::CData/*1:0*/ __Vdly__viterbi_accelerator__DOT__ctrl__DOT__state_38;
    __Vdly__viterbi_accelerator__DOT__ctrl__DOT__state_38 = 0;
    ::CData/*2:0*/ __Vdly__viterbi_accelerator__DOT__ctrl__DOT__group_index_39;
    __Vdly__viterbi_accelerator__DOT__ctrl__DOT__group_index_39 = 0;
    ::CData/*0:0*/ __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_41;
    __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_41 = 0;
    ::SData/*15:0*/ __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_42;
    __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_42 = 0;
    ::CData/*4:0*/ __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_43;
    __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_43 = 0;
    ::CData/*0:0*/ __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_44;
    __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_44 = 0;
    ::SData/*15:0*/ __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_45;
    __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_45 = 0;
    ::CData/*4:0*/ __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_46;
    __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_46 = 0;
    ::SData/*15:0*/ __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_47;
    __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_47 = 0;
    ::CData/*4:0*/ __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_48;
    __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_48 = 0;
    ::SData/*15:0*/ __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_49;
    __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_49 = 0;
    ::CData/*4:0*/ __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_50;
    __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_50 = 0;
    ::SData/*31:0*/ __VExpandSel_Lsb_1;
    ::SData/*31:0*/ __VExpandSel_Lsb_2;
    ::SData/*31:0*/ __VExpandSel_Lsb_3;
    ::SData/*31:0*/ __VExpandSel_Lsb_4;
    ::SData/*31:0*/ __VExpandSel_Lsb_5;
    ::SData/*31:0*/ __VExpandSel_Lsb_6;
    ::SData/*31:0*/ __VExpandSel_Lsb_7;
    // Body
    __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_41 = 0U;
    __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_44 = 0U;
    __Vdly__viterbi_accelerator__DOT__ctrl__DOT__state_38 
        = vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state;
    __Vdly__viterbi_accelerator__DOT__ctrl__DOT__group_index_39 
        = vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index;
    if (((::IData)(vlSelfRef.__VprimaryPorts.rst) | (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__initialize))) {
        __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_41 = 1U;
        if (vlSelfRef.__VprimaryPorts.rst) {
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__ = 0x0000ffffU;
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__ = 0x0000ffffU;
        } else {
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[0U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[0U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[1U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[1U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[2U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[2U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[3U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[3U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[4U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[4U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[5U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[5U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[6U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[6U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[7U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[7U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[8U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[8U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[9U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[9U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[10U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[10U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[11U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[11U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[12U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[12U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[13U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[13U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[14U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[14U] 
                   >> 0x00000010U);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__ 
                = (0x0000ffffU & vlSelfRef.__VprimaryPorts.initial_metrics[15U]);
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__ 
                = (vlSelfRef.__VprimaryPorts.initial_metrics[15U] 
                   >> 0x00000010U);
        }
        vlSelfRef.__VprimaryPorts.survivors = 0U;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors = 0U;
    } else {
        if ((2U == (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state))) {
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[0U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[1U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[2U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[3U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[4U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[5U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[6U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[7U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[8U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[9U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[10U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[11U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[12U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[13U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[14U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[15U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[16U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[17U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[18U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[19U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[20U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[21U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[22U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[23U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[24U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[25U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[26U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[27U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[28U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[29U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[30U];
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__ 
                = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[31U];
            vlSelfRef.__VprimaryPorts.survivors = vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors;
        }
        if ((1U == (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state))) {
            __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_42 
                = (0x0000ffffU & (::IData)(vlSelfRef.viterbi_accelerator__DOT__next_metrics));
            __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_43 
                = (0x0000001fU & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                  << 2U));
            __Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_44 = 1U;
            __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_45 
                = (0x0000ffffU & (::IData)((vlSelfRef.viterbi_accelerator__DOT__next_metrics 
                                            >> 0x10U)));
            __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_46 
                = (0x0000001fU & ((::IData)(1U) + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                   << 2U)));
            __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_47 
                = (0x0000ffffU & (::IData)((vlSelfRef.viterbi_accelerator__DOT__next_metrics 
                                            >> 0x20U)));
            __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_48 
                = (0x0000001fU & ((::IData)(2U) + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                   << 2U)));
            __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_49 
                = (0x0000ffffU & (::IData)((vlSelfRef.viterbi_accelerator__DOT__next_metrics 
                                            >> 0x30U)));
            __Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_50 
                = (0x0000001fU & ((::IData)(3U) + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                   << 2U)));
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors 
                = (((~ ((::IData)(1U) << (0x0000001fU 
                                          & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                             << 2U)))) 
                    & vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors) 
                   | (0x00000000ffffffffULL & ((1U 
                                                & (::IData)(vlSelfRef.viterbi_accelerator__DOT__decisions)) 
                                               << (0x0000001fU 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                      << 2U)))));
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors 
                = (((~ ((::IData)(1U) << (0x0000001fU 
                                          & ((::IData)(1U) 
                                             + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                << 2U))))) 
                    & vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors) 
                   | (0x00000000ffffffffULL & ((1U 
                                                & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__decisions) 
                                                   >> 1U)) 
                                               << (0x0000001fU 
                                                   & ((::IData)(1U) 
                                                      + 
                                                      ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                       << 2U))))));
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors 
                = (((~ ((::IData)(1U) << (0x0000001fU 
                                          & ((::IData)(2U) 
                                             + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                << 2U))))) 
                    & vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors) 
                   | (0x00000000ffffffffULL & ((1U 
                                                & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__decisions) 
                                                   >> 2U)) 
                                               << (0x0000001fU 
                                                   & ((::IData)(2U) 
                                                      + 
                                                      ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                       << 2U))))));
            vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors 
                = (((~ ((::IData)(1U) << (0x0000001fU 
                                          & ((::IData)(3U) 
                                             + ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                << 2U))))) 
                    & vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending_survivors) 
                   | (0x00000000ffffffffULL & ((1U 
                                                & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__decisions) 
                                                   >> 3U)) 
                                               << (0x0000001fU 
                                                   & ((::IData)(3U) 
                                                      + 
                                                      ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                       << 2U))))));
        }
    }
    if (vlSelfRef.__VprimaryPorts.rst) {
        vlSelfRef.__VprimaryPorts.configured = 0U;
        vlSelfRef.__VprimaryPorts.metric_overflow = 0U;
        vlSelfRef.viterbi_accelerator__DOT__symbol_q = 0U;
        vlSelfRef.viterbi_accelerator__DOT__table_q[0U] = 0U;
        vlSelfRef.viterbi_accelerator__DOT__table_q[1U] = 0U;
        vlSelfRef.viterbi_accelerator__DOT__table_q[2U] = 0U;
        vlSelfRef.viterbi_accelerator__DOT__table_q[3U] = 0U;
    } else {
        if (vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__initialize) {
            vlSelfRef.__VprimaryPorts.configured = 1U;
            vlSelfRef.__VprimaryPorts.metric_overflow = 0U;
            vlSelfRef.viterbi_accelerator__DOT__table_q[0U] 
                = vlSelfRef.__VprimaryPorts.output_table[0U];
            vlSelfRef.viterbi_accelerator__DOT__table_q[1U] 
                = vlSelfRef.__VprimaryPorts.output_table[1U];
            vlSelfRef.viterbi_accelerator__DOT__table_q[2U] 
                = vlSelfRef.__VprimaryPorts.output_table[2U];
            vlSelfRef.viterbi_accelerator__DOT__table_q[3U] 
                = vlSelfRef.__VprimaryPorts.output_table[3U];
        } else if (((1U == (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state)) 
                    & (((0x0001ffffU != vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen) 
                        & (0x0000ffffU <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen)) 
                       | (((0x0001ffffU != vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen) 
                           & (0x0000ffffU <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen)) 
                          | (((0x0001ffffU != vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen) 
                              & (0x0000ffffU <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen)) 
                             | ((0x0001ffffU != vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen) 
                                & (0x0000ffffU <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen))))))) {
            vlSelfRef.__VprimaryPorts.metric_overflow = 1U;
        }
        if (vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__accept) {
            vlSelfRef.viterbi_accelerator__DOT__symbol_q 
                = vlSelfRef.__VprimaryPorts.received;
        }
    }
    __Vtableidx_0 = ((((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                       << 4U) | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__accept) 
                                 << 3U)) | (((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state) 
                                             << 1U) 
                                            | (::IData)(vlSelfRef.__VprimaryPorts.rst)));
    if ((0U != (1U & Vviterbi_accelerator__ConstPool__CONSARRAY_0
                [__Vtableidx_0]))) {
        __Vdly__viterbi_accelerator__DOT__ctrl__DOT__state_38 
            = Vviterbi_accelerator__ConstPool__CONSARRAY_1
            [__Vtableidx_0];
    }
    if ((0U != (2U & Vviterbi_accelerator__ConstPool__CONSARRAY_0
                [__Vtableidx_0]))) {
        __Vdly__viterbi_accelerator__DOT__ctrl__DOT__group_index_39 
            = Vviterbi_accelerator__ConstPool__CONSARRAY_2
            [__Vtableidx_0];
    }
    vlSelfRef.__VprimaryPorts.done = Vviterbi_accelerator__ConstPool__CONSARRAY_3
        [__Vtableidx_0];
    if (__Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_41) {
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[0U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[1U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[2U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[3U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[4U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[5U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[6U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[7U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[8U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[9U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[10U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[11U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[12U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[13U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[14U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[15U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[16U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[17U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[18U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[19U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[20U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[21U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[22U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[23U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[24U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[25U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[26U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[27U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[28U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[29U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[30U] = 0xffffU;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[31U] = 0xffffU;
    }
    if (__Vdly_Set__viterbi_accelerator__DOT__storage__DOT__pending_44) {
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[__Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_43] 
            = __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_42;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[__Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_46] 
            = __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_45;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[__Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_48] 
            = __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_47;
        vlSelfRef.viterbi_accelerator__DOT__storage__DOT__pending[__Vdly_Dim0__viterbi_accelerator__DOT__storage__DOT__pending_50] 
            = __Vdly_Val__viterbi_accelerator__DOT__storage__DOT__pending_49;
    }
    vlSelfRef.__VprimaryPorts.metrics[0U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__) 
                                              << 0x00000010U) 
                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__));
    vlSelfRef.__VprimaryPorts.metrics[1U] = (::IData)(
                                                      (((::QData)((::IData)(
                                                                            (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__) 
                                                                              << 0x00000010U) 
                                                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__)))) 
                                                        << 0x00000020U) 
                                                       | (::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__))))));
    vlSelfRef.__VprimaryPorts.metrics[2U] = (::IData)(
                                                      ((((::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__)))) 
                                                         << 0x00000020U) 
                                                        | (::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__))))) 
                                                       >> 0x00000020U));
    vlSelfRef.__VprimaryPorts.metrics[3U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__) 
                                              << 0x00000010U) 
                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__));
    vlSelfRef.__VprimaryPorts.metrics[4U] = (::IData)(
                                                      (((::QData)((::IData)(
                                                                            (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__) 
                                                                              << 0x00000010U) 
                                                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__)))) 
                                                        << 0x00000020U) 
                                                       | (::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__))))));
    vlSelfRef.__VprimaryPorts.metrics[5U] = (::IData)(
                                                      ((((::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__)))) 
                                                         << 0x00000020U) 
                                                        | (::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__))))) 
                                                       >> 0x00000020U));
    vlSelfRef.__VprimaryPorts.metrics[6U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__) 
                                              << 0x00000010U) 
                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__));
    vlSelfRef.__VprimaryPorts.metrics[7U] = (::IData)(
                                                      (((::QData)((::IData)(
                                                                            (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__) 
                                                                              << 0x00000010U) 
                                                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__)))) 
                                                        << 0x00000020U) 
                                                       | (::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__))))));
    vlSelfRef.__VprimaryPorts.metrics[8U] = (::IData)(
                                                      ((((::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__)))) 
                                                         << 0x00000020U) 
                                                        | (::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__))))) 
                                                       >> 0x00000020U));
    vlSelfRef.__VprimaryPorts.metrics[9U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__) 
                                              << 0x00000010U) 
                                             | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__));
    vlSelfRef.__VprimaryPorts.metrics[10U] = (::IData)(
                                                       (((::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__)))) 
                                                         << 0x00000020U) 
                                                        | (::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__))))));
    vlSelfRef.__VprimaryPorts.metrics[11U] = (::IData)(
                                                       ((((::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__)))) 
                                                          << 0x00000020U) 
                                                         | (::QData)((::IData)(
                                                                               (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__) 
                                                                                << 0x00000010U) 
                                                                                | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__))))) 
                                                        >> 0x00000020U));
    vlSelfRef.__VprimaryPorts.metrics[12U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__) 
                                               << 0x00000010U) 
                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__));
    vlSelfRef.__VprimaryPorts.metrics[13U] = (::IData)(
                                                       (((::QData)((::IData)(
                                                                             (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__) 
                                                                               << 0x00000010U) 
                                                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__)))) 
                                                         << 0x00000020U) 
                                                        | (::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__))))));
    vlSelfRef.__VprimaryPorts.metrics[14U] = (::IData)(
                                                       ((((::QData)((::IData)(
                                                                              (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__) 
                                                                                << 0x00000010U) 
                                                                               | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__)))) 
                                                          << 0x00000020U) 
                                                         | (::QData)((::IData)(
                                                                               (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__) 
                                                                                << 0x00000010U) 
                                                                                | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__))))) 
                                                        >> 0x00000020U));
    vlSelfRef.__VprimaryPorts.metrics[15U] = (((::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__) 
                                               << 0x00000010U) 
                                              | (::IData)(vlSelfRef.viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__));
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state 
        = __Vdly__viterbi_accelerator__DOT__ctrl__DOT__state_38;
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index 
        = __Vdly__viterbi_accelerator__DOT__ctrl__DOT__group_index_39;
    vlSelfRef.__VprimaryPorts.busy = (0U != (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state));
    __VExpandSel_Lsb_1 = (0x10U | (0x00000180U & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                  << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_b 
        = (0x0000ffffU & (((0U == (0x0000001fU & __VExpandSel_Lsb_1))
                            ? 0U : (vlSelfRef.__VprimaryPorts.metrics
                                    [(((::IData)(0x0000000fU) 
                                       + __VExpandSel_Lsb_1) 
                                      >> 5U)] << ((::IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & __VExpandSel_Lsb_1)))) 
                          | (vlSelfRef.__VprimaryPorts.metrics
                             [(0x0000000cU & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                              << 2U))] 
                             >> (0x0000001fU & __VExpandSel_Lsb_1))));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_a 
        = (0x0000ffffU & vlSelfRef.__VprimaryPorts.metrics
           [(0x0000000cU & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                            << 2U))]);
    __VExpandSel_Lsb_2 = (0x30U | (0x00000180U & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                  << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_b 
        = (0x0000ffffU & (((0U == (0x0000001fU & __VExpandSel_Lsb_2))
                            ? 0U : (vlSelfRef.__VprimaryPorts.metrics
                                    [(((::IData)(0x0000000fU) 
                                       + __VExpandSel_Lsb_2) 
                                      >> 5U)] << ((::IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & __VExpandSel_Lsb_2)))) 
                          | (vlSelfRef.__VprimaryPorts.metrics
                             [(1U | (0x0000000cU & 
                                     ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                      << 2U)))] >> 
                             (0x0000001fU & __VExpandSel_Lsb_2))));
    __VExpandSel_Lsb_3 = (0x000001f0U & (0x00000020U 
                                         | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                            << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_a 
        = (0x0000ffffU & vlSelfRef.__VprimaryPorts.metrics
           [(__VExpandSel_Lsb_3 >> 5U)]);
    __VExpandSel_Lsb_4 = (0x50U | (0x00000180U & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                  << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_b 
        = (0x0000ffffU & (((0U == (0x0000001fU & __VExpandSel_Lsb_4))
                            ? 0U : (vlSelfRef.__VprimaryPorts.metrics
                                    [(((::IData)(0x0000000fU) 
                                       + __VExpandSel_Lsb_4) 
                                      >> 5U)] << ((::IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & __VExpandSel_Lsb_4)))) 
                          | (vlSelfRef.__VprimaryPorts.metrics
                             [(2U | (0x0000000cU & 
                                     ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                      << 2U)))] >> 
                             (0x0000001fU & __VExpandSel_Lsb_4))));
    __VExpandSel_Lsb_5 = (0x000001f0U & (0x00000040U 
                                         | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                            << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_a 
        = (0x0000ffffU & vlSelfRef.__VprimaryPorts.metrics
           [(__VExpandSel_Lsb_5 >> 5U)]);
    __VExpandSel_Lsb_6 = (0x70U | (0x00000180U & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                  << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_b 
        = (0x0000ffffU & (((0U == (0x0000001fU & __VExpandSel_Lsb_6))
                            ? 0U : (vlSelfRef.__VprimaryPorts.metrics
                                    [(((::IData)(0x0000000fU) 
                                       + __VExpandSel_Lsb_6) 
                                      >> 5U)] << ((::IData)(0x00000020U) 
                                                  - 
                                                  (0x0000001fU 
                                                   & __VExpandSel_Lsb_6)))) 
                          | (vlSelfRef.__VprimaryPorts.metrics
                             [(3U | (0x0000000cU & 
                                     ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                      << 2U)))] >> 
                             (0x0000001fU & __VExpandSel_Lsb_6))));
    __VExpandSel_Lsb_7 = (0x000001f0U & (0x00000060U 
                                         | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                            << 7U)));
    viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_a 
        = (0x0000ffffU & vlSelfRef.__VprimaryPorts.metrics
           [(__VExpandSel_Lsb_7 >> 5U)]);
    vlSelfRef.__Vdfg_Regularize_133 = (1U & (~ ((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                | (::IData)(vlSelfRef.__VprimaryPorts.busy))));
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__cb 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_b)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (2U 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (2U 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (2U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (2U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_b))));
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__ca 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_a)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                             << 4U)))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                            << 4U)) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              << 4U))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              << 4U)))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__0__KET____DOT__acs__metric_a))));
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__cb 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_b)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (6U 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (6U 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (6U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (6U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_b))));
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__ca 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_a)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (4U 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (4U 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (4U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (4U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__1__KET____DOT__acs__metric_a))));
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__cb 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_b)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (0x0aU 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (0x0aU 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (0x0aU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (0x0aU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_b))));
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__ca 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_a)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (8U 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (8U 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (8U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (8U 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__2__KET____DOT__acs__metric_a))));
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__cb 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_b)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (0x0eU 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (0x0eU 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (0x0eU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (0x0eU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_b))));
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__ca 
        = (0x0001ffffU & ((- (::IData)((0xffffU == (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_a)))) 
                          | ((3U & VL_COUNTONES_I((3U 
                                                   & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__symbol_q) 
                                                      ^ 
                                                      (((0U 
                                                         == 
                                                         (0x0000001fU 
                                                          & (0x0cU 
                                                             | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                << 4U))))
                                                         ? 0U
                                                         : 
                                                        (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                         [
                                                         (((::IData)(1U) 
                                                           + 
                                                           (0x0cU 
                                                            | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                               << 4U))) 
                                                          >> 5U)] 
                                                         << 
                                                         ((::IData)(0x00000020U) 
                                                          - 
                                                          (0x0000001fU 
                                                           & (0x0cU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U)))))) 
                                                       | (vlSelfRef.viterbi_accelerator__DOT__table_q
                                                          [
                                                          (0x07ffffffU 
                                                           & ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                              >> 1U))] 
                                                          >> 
                                                          (0x0000001fU 
                                                           & (0x0cU 
                                                              | ((::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__group_index) 
                                                                 << 4U))))))))) 
                             + (::IData)(viterbi_accelerator__DOT____Vcellinp__acs_lanes__BRA__3__KET____DOT__acs__metric_a))));
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__initialize 
        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
           & (::IData)(vlSelfRef.__VprimaryPorts.load_context));
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__accept 
        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
           & ((::IData)(vlSelfRef.__VprimaryPorts.configured) 
              & ((~ (::IData)(vlSelfRef.__VprimaryPorts.load_context)) 
                 & (::IData)(vlSelfRef.__VprimaryPorts.start))));
    viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__survivor 
        = (viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__cb 
           < viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__ca);
    viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__survivor 
        = (viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__cb 
           < viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__ca);
    viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__survivor 
        = (viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__cb 
           < viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__ca);
    viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__survivor 
        = (viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__cb 
           < viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__ca);
    vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen 
        = ((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__survivor)
            ? viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__cb
            : viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__ca);
    vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen 
        = ((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__survivor)
            ? viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__cb
            : viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__ca);
    vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen 
        = ((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__survivor)
            ? viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__cb
            : viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__ca);
    vlSelfRef.viterbi_accelerator__DOT__decisions = 
        ((((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__survivor) 
           << 3U) | ((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__survivor) 
                     << 2U)) | (((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__survivor) 
                                 << 1U) | (::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__survivor)));
    vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen 
        = ((::IData)(viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__survivor)
            ? viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__cb
            : viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__ca);
    vlSelfRef.viterbi_accelerator__DOT__next_metrics 
        = (((::QData)((::IData)((((vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen 
                                   | (- (::IData)((0x0000ffffU 
                                                   <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen)))) 
                                  << 0x00000010U) | 
                                 (0x0000ffffU & (vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen 
                                                 | (- (::IData)(
                                                                (0x0000ffffU 
                                                                 <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen)))))))) 
            << 0x00000020U) | (::QData)((::IData)((
                                                   ((vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen 
                                                     | (- (::IData)(
                                                                    (0x0000ffffU 
                                                                     <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen)))) 
                                                    << 0x00000010U) 
                                                   | (0x0000ffffU 
                                                      & (vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen 
                                                         | (- (::IData)(
                                                                        (0x0000ffffU 
                                                                         <= vlSelfRef.viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen)))))))));
}

void Vviterbi_accelerator___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vviterbi_accelerator___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vviterbi_accelerator___024root___eval_debug_assertions(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_debug_assertions\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.rst 
                      & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.load_context 
                      & 0xfeU)))) {
        Verilated::overWidthError("load_context");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.start 
                      & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.received 
                      & 0xfcU)))) {
        Verilated::overWidthError("received");
    }
}
#endif  // VL_DEBUG
