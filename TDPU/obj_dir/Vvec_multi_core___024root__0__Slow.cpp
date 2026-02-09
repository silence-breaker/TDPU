// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvec_multi_core.h for the primary calling header

#include "Vvec_multi_core__pch.h"

VL_ATTR_COLD void Vvec_multi_core___024root___eval_static(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_static\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vvec_multi_core___024root___eval_initial(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_initial\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vvec_multi_core___024root___eval_final(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_final\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvec_multi_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vvec_multi_core___024root___eval_phase__stl(Vvec_multi_core___024root* vlSelf);

VL_ATTR_COLD void Vvec_multi_core___024root___eval_settle(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_settle\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vvec_multi_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("vec_multi_core.sv", 7, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vvec_multi_core___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vvec_multi_core___024root___eval_triggers__stl(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_triggers__stl\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vvec_multi_core___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vvec_multi_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvec_multi_core___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vvec_multi_core___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vvec_multi_core___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vvec_multi_core___024root___stl_sequent__TOP__0(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___stl_sequent__TOP__0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.o_data_ready = vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__;
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0U] 
        = vlSelfRef.vec_multi_core__DOT__product[0U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][1U] 
        = vlSelfRef.vec_multi_core__DOT__product[1U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][2U] 
        = vlSelfRef.vec_multi_core__DOT__product[2U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][3U] 
        = vlSelfRef.vec_multi_core__DOT__product[3U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][4U] 
        = vlSelfRef.vec_multi_core__DOT__product[4U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][5U] 
        = vlSelfRef.vec_multi_core__DOT__product[5U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][6U] 
        = vlSelfRef.vec_multi_core__DOT__product[6U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][7U] 
        = vlSelfRef.vec_multi_core__DOT__product[7U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][8U] 
        = vlSelfRef.vec_multi_core__DOT__product[8U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][9U] 
        = vlSelfRef.vec_multi_core__DOT__product[9U];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0aU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000aU];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0bU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000bU];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0cU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000cU];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0dU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000dU];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0eU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000eU];
    vlSelfRef.vec_multi_core__DOT__tree_data[0U][0x0fU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000fU];
    vlSelfRef.o_result = vlSelfRef.vec_multi_core__DOT__tree_data
        [4U][0U];
}

VL_ATTR_COLD void Vvec_multi_core___024root___eval_stl(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_stl\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vvec_multi_core___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vvec_multi_core___024root___eval_phase__stl(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_phase__stl\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vvec_multi_core___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vvec_multi_core___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vvec_multi_core___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vvec_multi_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvec_multi_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vvec_multi_core___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvec_multi_core___024root___ctor_var_reset(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___ctor_var_reset\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->i_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15782147128264288011ull);
    vlSelf->i_load_weight = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4599034397521178552ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->i_data, __VscopeHash, 9289791593721341457ull);
    vlSelf->i_weight = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16135871476031686068ull);
    vlSelf->o_data_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12751862293382745632ull);
    vlSelf->o_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3390268084763049377ull);
    vlSelf->vec_multi_core__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16156540023285174162ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->vec_multi_core__DOT__product, __VscopeHash, 13997464768990214222ull);
    vlSelf->vec_multi_core__DOT__product_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13123659374951433097ull);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->vec_multi_core__DOT__tree_data[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13495378495166964474ull);
        }
    }
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__4__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3416327937623897928ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__3__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5966440699786506477ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__2__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6927157689860437509ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7004562910471235444ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
