// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vviterbi_accelerator.h for the primary calling header

#include "Vviterbi_accelerator__pch.h"

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_static(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_static\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_initial(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_initial\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vviterbi_accelerator___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vviterbi_accelerator___024root___stl_comb__TOP__0(Vviterbi_accelerator___024root* vlSelf);

VL_ATTR_COLD bool Vviterbi_accelerator___024root___eval_stl(Vviterbi_accelerator___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_stl\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vviterbi_accelerator___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vviterbi_accelerator___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                Vviterbi_accelerator___024root___stl_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__stl(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__stl\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vviterbi_accelerator___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__ico(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__ico\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vviterbi_accelerator___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__act(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__act\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vviterbi_accelerator___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__nba(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__nba\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vviterbi_accelerator___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__obs(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__obs\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_dump_triggers__react(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_dump_triggers__react\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vviterbi_accelerator___024root___eval_final(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___eval_final\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vviterbi_accelerator___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vviterbi_accelerator___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vviterbi_accelerator___024root___stl_comb__TOP__0(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___stl_comb__TOP__0\n"); );
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
    ::SData/*31:0*/ __VExpandSel_Lsb_1;
    ::SData/*31:0*/ __VExpandSel_Lsb_2;
    ::SData/*31:0*/ __VExpandSel_Lsb_3;
    ::SData/*31:0*/ __VExpandSel_Lsb_4;
    ::SData/*31:0*/ __VExpandSel_Lsb_5;
    ::SData/*31:0*/ __VExpandSel_Lsb_6;
    ::SData/*31:0*/ __VExpandSel_Lsb_7;
    // Body
    vlSelfRef.__VprimaryPorts.busy = (0U != (::IData)(vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__state));
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
    vlSelfRef.__Vdfg_Regularize_133 = (1U & (~ ((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                | (::IData)(vlSelfRef.__VprimaryPorts.busy))));
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
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__initialize 
        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
           & (::IData)(vlSelfRef.__VprimaryPorts.load_context));
    vlSelfRef.viterbi_accelerator__DOT__ctrl__DOT__accept 
        = ((::IData)(vlSelfRef.__Vdfg_Regularize_133) 
           & ((::IData)(vlSelfRef.__VprimaryPorts.configured) 
              & ((~ (::IData)(vlSelfRef.__VprimaryPorts.load_context)) 
                 & (::IData)(vlSelfRef.__VprimaryPorts.start))));
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

bool Vviterbi_accelerator___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vviterbi_accelerator___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( load_context)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( initial_metrics)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( start)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( received)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( output_table)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vviterbi_accelerator___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vviterbi_accelerator___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vviterbi_accelerator___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vviterbi_accelerator___024root___ctor_var_reset(Vviterbi_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vviterbi_accelerator___024root___ctor_var_reset\n"); );
    Vviterbi_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__VprimaryPorts.rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__VprimaryPorts.load_context = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4266536523962948572ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->__VprimaryPorts.initial_metrics, __VscopeHash, 6918787060581916880ull);
    vlSelf->__VprimaryPorts.start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->__VprimaryPorts.received = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4399806751793344104ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->__VprimaryPorts.output_table, __VscopeHash, 3486319436083046756ull);
    vlSelf->__VprimaryPorts.busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6386567572483775230ull);
    vlSelf->__VprimaryPorts.done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->__VprimaryPorts.configured = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8438889958579756013ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->__VprimaryPorts.metrics, __VscopeHash, 4377242961416336124ull);
    vlSelf->__VprimaryPorts.survivors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15368611518630333695ull);
    vlSelf->__VprimaryPorts.metric_overflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17894576041976075562ull);
    vlSelf->viterbi_accelerator__DOT__symbol_q = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1530939754994823928ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->viterbi_accelerator__DOT__table_q, __VscopeHash, 1135394072023166313ull);
    vlSelf->viterbi_accelerator__DOT__next_metrics = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6816677524409001873ull);
    vlSelf->viterbi_accelerator__DOT__decisions = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17144580394749765063ull);
    vlSelf->viterbi_accelerator__DOT__acs_lanes__BRA__3__KET____DOT__acs__DOT__chosen = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17879593839383327419ull);
    vlSelf->viterbi_accelerator__DOT__acs_lanes__BRA__2__KET____DOT__acs__DOT__chosen = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2635420942184209681ull);
    vlSelf->viterbi_accelerator__DOT__acs_lanes__BRA__1__KET____DOT__acs__DOT__chosen = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12516408256318778992ull);
    vlSelf->viterbi_accelerator__DOT__acs_lanes__BRA__0__KET____DOT__acs__DOT__chosen = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10879045471917279755ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17352763423315770406ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3135918004231632154ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__2__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17874651318605911555ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__3__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6342479796124441250ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__4__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10366088496016372478ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__5__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1852690969293701817ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__6__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4967826170922123971ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__7__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11545330347155742687ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__8__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5470611906540626544ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__9__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3045828182143286631ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__10__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9207723998372592713ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__11__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10653375190100154504ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__12__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6354725840820090874ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__13__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12762542971583698593ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__14__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17377656109646582278ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__15__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7356157319114031125ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__16__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8801808510841582548ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__17__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10874807252235379245ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__18__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15773979454079147306ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__19__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1942348518432477532ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__20__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6972890116325815084ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__21__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10149896006476025091ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__22__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14388996460650049080ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__23__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1918361668988771720ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__24__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2359627851728935540ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__25__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11492971527741113851ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__26__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5279555331458650013ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__27__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2936525477827047238ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__28__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15494765067680751366ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__29__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16757004110828584392ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__30__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16084097816360289453ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__current__BRA__31__KET__ = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8793744539873368723ull);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__pending[0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15649519736125285423ull);
    VL_UNPACKED_FILL(vlSelf->viterbi_accelerator__DOT__storage__DOT__pending.data(), sizeof(vlSelf->viterbi_accelerator__DOT__storage__DOT__pending[0]), 32);
    vlSelf->viterbi_accelerator__DOT__storage__DOT__pending_survivors = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9089627192107023077ull);
    vlSelf->viterbi_accelerator__DOT__ctrl__DOT__accept = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7414356094032072242ull);
    vlSelf->viterbi_accelerator__DOT__ctrl__DOT__initialize = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15146629054314378280ull);
    vlSelf->viterbi_accelerator__DOT__ctrl__DOT__group_index = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5573590413446427862ull);
    vlSelf->viterbi_accelerator__DOT__ctrl__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6935603743811295339ull);
    vlSelf->__Vdfg_Regularize_133 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__load_context__0 = 0;
    VL_ZERO_W(512, vlSelf->__Vtrigprevexpr___TOP__initial_metrics__0);
    vlSelf->__Vtrigprevexpr___TOP__start__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__received__0 = 0;
    VL_ZERO_W(128, vlSelf->__Vtrigprevexpr___TOP__output_table__0);
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
}
