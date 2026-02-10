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
            VL_FATAL_MT("vec_multi_core.sv", 5, "", "Settle region did not converge after 100 tries");
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
    vlSelfRef.o_result = VL_EXTENDS_II(32,14, (IData)(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data));
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
    VL_SCOPED_RAND_RESET_W(256, vlSelf->i_data, __VscopeHash, 9289791593721341457ull);
    vlSelf->i_weight = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16135871476031686068ull);
    vlSelf->o_data_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12751862293382745632ull);
    vlSelf->o_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3390268084763049377ull);
    vlSelf->vec_multi_core__DOT__weight_reg = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16156540023285174162ull);
    vlSelf->vec_multi_core__DOT__product__BRA__287__03a279__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 835126681519919571ull);
    vlSelf->vec_multi_core__DOT__product__BRA__278__03a270__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8810919026613239535ull);
    vlSelf->vec_multi_core__DOT__product__BRA__269__03a261__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12935467730410111694ull);
    vlSelf->vec_multi_core__DOT__product__BRA__260__03a252__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6439010032962624672ull);
    vlSelf->vec_multi_core__DOT__product__BRA__251__03a243__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4266274227846783932ull);
    vlSelf->vec_multi_core__DOT__product__BRA__242__03a234__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14747315512478742713ull);
    vlSelf->vec_multi_core__DOT__product__BRA__233__03a225__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 12360404147833644403ull);
    vlSelf->vec_multi_core__DOT__product__BRA__224__03a216__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4827612743756587996ull);
    vlSelf->vec_multi_core__DOT__product__BRA__215__03a207__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4237558076696881848ull);
    vlSelf->vec_multi_core__DOT__product__BRA__206__03a198__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16358575291545690052ull);
    vlSelf->vec_multi_core__DOT__product__BRA__197__03a189__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2987769512733457185ull);
    vlSelf->vec_multi_core__DOT__product__BRA__188__03a180__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4311878460445303986ull);
    vlSelf->vec_multi_core__DOT__product__BRA__179__03a171__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9309989958422533226ull);
    vlSelf->vec_multi_core__DOT__product__BRA__170__03a162__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2569971965316755816ull);
    vlSelf->vec_multi_core__DOT__product__BRA__161__03a153__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17455211065853129394ull);
    vlSelf->vec_multi_core__DOT__product__BRA__152__03a144__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8287126920124803506ull);
    vlSelf->vec_multi_core__DOT__product__BRA__143__03a135__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 14321048492831985941ull);
    vlSelf->vec_multi_core__DOT__product__BRA__134__03a126__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5772971254644651993ull);
    vlSelf->vec_multi_core__DOT__product__BRA__125__03a117__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 8697472977637057753ull);
    vlSelf->vec_multi_core__DOT__product__BRA__116__03a108__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16245081806091931320ull);
    vlSelf->vec_multi_core__DOT__product__BRA__107__03a99__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2605104434625207049ull);
    vlSelf->vec_multi_core__DOT__product__BRA__98__03a90__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 4385850001819739088ull);
    vlSelf->vec_multi_core__DOT__product__BRA__89__03a81__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9220726751534636228ull);
    vlSelf->vec_multi_core__DOT__product__BRA__80__03a72__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 17571270451667519542ull);
    vlSelf->vec_multi_core__DOT__product__BRA__71__03a63__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13791507449628236011ull);
    vlSelf->vec_multi_core__DOT__product__BRA__62__03a54__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 13731891495398607124ull);
    vlSelf->vec_multi_core__DOT__product__BRA__53__03a45__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11706377140065587228ull);
    vlSelf->vec_multi_core__DOT__product__BRA__44__03a36__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15678715892876725592ull);
    vlSelf->vec_multi_core__DOT__product__BRA__35__03a27__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9140242257100631064ull);
    vlSelf->vec_multi_core__DOT__product__BRA__26__03a18__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9649375472549389911ull);
    vlSelf->vec_multi_core__DOT__product__BRA__17__03a9__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2361595981599319779ull);
    vlSelf->vec_multi_core__DOT__product__BRA__8__03a0__KET__ = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15820814602639846028ull);
    vlSelf->vec_multi_core__DOT__product_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13123659374951433097ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__4__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3416327937623897928ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__3__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5966440699786506477ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__2__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6927157689860437509ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__1__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7004562910471235444ull);
    vlSelf->vec_multi_core__DOT__tree_valid__BRA__0__KET__ = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9556159810553061831ull);
    VL_SCOPED_RAND_RESET_W(160, vlSelf->vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data, __VscopeHash, 13700455235544617490ull);
    VL_SCOPED_RAND_RESET_W(88, vlSelf->vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data, __VscopeHash, 16972787353956948342ull);
    vlSelf->vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8375820022203626906ull);
    vlSelf->vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data = VL_SCOPED_RAND_RESET_I(26, __VscopeHash, 12617091285741936288ull);
    vlSelf->vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data = VL_SCOPED_RAND_RESET_I(14, __VscopeHash, 15969424364037640351ull);
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
