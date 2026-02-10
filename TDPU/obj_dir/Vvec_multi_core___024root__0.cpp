// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvec_multi_core.h for the primary calling header

#include "Vvec_multi_core__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvec_multi_core___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vvec_multi_core___024root___eval_triggers__act(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_triggers__act\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vvec_multi_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vvec_multi_core___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___trigger_anySet__act\n"); );
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

void Vvec_multi_core___024root___nba_sequent__TOP__0(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___nba_sequent__TOP__0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__));
    vlSelfRef.o_data_ready = vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__;
}

void Vvec_multi_core___024root___nba_sequent__TOP__1(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___nba_sequent__TOP__1\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) {
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data 
            = (0x00003fffU & (VL_EXTENDS_II(14,13, 
                                            (0x00001fffU 
                                             & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data)) 
                              + VL_EXTENDS_II(14,13, 
                                              (0x00001fffU 
                                               & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data 
                                                  >> 0x0dU)))));
    }
    vlSelfRef.o_result = VL_EXTENDS_II(32,14, (IData)(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data));
    if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) {
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data 
            = ((0x03ffe000U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data) 
               | (0x00001fffU & (VL_EXTENDS_II(13,12, 
                                               (0x00000fffU 
                                                & (IData)(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data))) 
                                 + VL_EXTENDS_II(13,12, 
                                                 (0x00000fffU 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
                                                             >> 0x0cU)))))));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data 
            = ((0x00001fffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data) 
               | (0x03ffe000U & ((VL_EXTENDS_II(13,12, 
                                                (0x00000fffU 
                                                 & (IData)(
                                                           (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
                                                            >> 0x18U)))) 
                                  + VL_EXTENDS_II(13,12, 
                                                  (0x00000fffU 
                                                   & (IData)(
                                                             (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
                                                              >> 0x24U))))) 
                                 << 0x0000000dU)));
    }
    if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) {
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
            = ((0x0000fffffffff000ULL & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data) 
               | (IData)((IData)((0x00000fffU & (VL_EXTENDS_II(12,11, 
                                                               (0x000007ffU 
                                                                & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U])) 
                                                 + 
                                                 VL_EXTENDS_II(12,11, 
                                                               (0x000007ffU 
                                                                & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U] 
                                                                   >> 0x0000000bU))))))));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
            = ((0x0000ffffff000fffULL & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data) 
               | ((QData)((IData)((0x00000fffU & (VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
                                                                     << 0x0000000aU) 
                                                                    | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U] 
                                                                       >> 0x00000016U)))) 
                                                  + 
                                                  VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
                                                                    >> 1U))))))) 
                  << 0x0000000cU));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
            = ((0x0000fff000ffffffULL & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data) 
               | ((QData)((IData)((0x00000fffU & (VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
                                                                    >> 0x0000000cU))) 
                                                  + 
                                                  VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
                                                                     << 9U) 
                                                                    | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
                                                                       >> 0x00000017U)))))))) 
                  << 0x00000018U));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data 
            = ((0x0000000fffffffffULL & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data) 
               | ((QData)((IData)((0x00000fffU & (VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
                                                                    >> 2U))) 
                                                  + 
                                                  VL_EXTENDS_II(12,11, 
                                                                (0x000007ffU 
                                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
                                                                    >> 0x0000000dU))))))) 
                  << 0x00000024U));
    }
    if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__0__KET__) {
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U] 
            = ((0xfffff800U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U]) 
               | (0x000007ffU & (VL_EXTENDS_II(11,10, 
                                               (0x000003ffU 
                                                & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U])) 
                                 + VL_EXTENDS_II(11,10, 
                                                 (0x000003ffU 
                                                  & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
                                                     >> 0x0000000aU))))));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U] 
            = ((0xffc007ffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U]) 
               | (0x003ff800U & ((VL_EXTENDS_II(11,10, 
                                                (0x000003ffU 
                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
                                                    >> 0x00000014U))) 
                                  + VL_EXTENDS_II(11,10, 
                                                  (0x000003ffU 
                                                   & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                                       << 2U) 
                                                      | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
                                                         >> 0x0000001eU))))) 
                                 << 0x0000000bU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U] 
            = ((0x003fffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[0U]) 
               | ((VL_EXTENDS_II(11,10, (0x000003ffU 
                                         & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                            >> 8U))) 
                   + VL_EXTENDS_II(11,10, (0x000003ffU 
                                           & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                              >> 0x00000012U)))) 
                  << 0x00000016U));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
            = ((0xfffffffeU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U]) 
               | (1U & ((VL_EXTENDS_II(11,10, (0x000003ffU 
                                               & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                                  >> 8U))) 
                         + VL_EXTENDS_II(11,10, (0x000003ffU 
                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                                    >> 0x00000012U)))) 
                        >> 0x0000000aU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
            = ((0xfffff001U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U]) 
               | (0x00000ffeU & ((VL_EXTENDS_II(11,10, 
                                                (0x000003ffU 
                                                 & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
                                                     << 4U) 
                                                    | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
                                                       >> 0x0000001cU)))) 
                                  + VL_EXTENDS_II(11,10, 
                                                  (0x000003ffU 
                                                   & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
                                                      >> 6U)))) 
                                 << 1U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
            = ((0xff800fffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U]) 
               | (0x007ff000U & ((VL_EXTENDS_II(11,10, 
                                                (0x000003ffU 
                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
                                                    >> 0x00000010U))) 
                                  + VL_EXTENDS_II(11,10, 
                                                  (0x000003ffU 
                                                   & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                                       << 6U) 
                                                      | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
                                                         >> 0x0000001aU))))) 
                                 << 0x0000000cU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U] 
            = ((0x007fffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[1U]) 
               | ((VL_EXTENDS_II(11,10, (0x000003ffU 
                                         & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                            >> 4U))) 
                   + VL_EXTENDS_II(11,10, (0x000003ffU 
                                           & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                              >> 0x0000000eU)))) 
                  << 0x00000017U));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
            = ((0x00fffffcU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U]) 
               | (3U & ((VL_EXTENDS_II(11,10, (0x000003ffU 
                                               & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                                  >> 4U))) 
                         + VL_EXTENDS_II(11,10, (0x000003ffU 
                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                                    >> 0x0000000eU)))) 
                        >> 9U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
            = ((0x00ffe003U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U]) 
               | (0x00001ffcU & ((VL_EXTENDS_II(11,10, 
                                                (0x000003ffU 
                                                 & ((vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
                                                     << 8U) 
                                                    | (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
                                                       >> 0x00000018U)))) 
                                  + VL_EXTENDS_II(11,10, 
                                                  (0x000003ffU 
                                                   & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
                                                      >> 2U)))) 
                                 << 2U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U] 
            = ((0x00001fffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data[2U]) 
               | (0x00ffe000U & ((VL_EXTENDS_II(11,10, 
                                                (0x000003ffU 
                                                 & (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
                                                    >> 0x0000000cU))) 
                                  + VL_EXTENDS_II(11,10, 
                                                  (vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
                                                   >> 0x00000016U))) 
                                 << 0x0000000dU)));
    }
    if (vlSelfRef.vec_multi_core__DOT__product_ready) {
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
            = ((0xfffffc00U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U]) 
               | (0x000003ffU & (VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__8__03a0__KET__)) 
                                 + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__17__03a9__KET__)))));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
            = ((0xfff003ffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U]) 
               | (0x000ffc00U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__26__03a18__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__35__03a27__KET__))) 
                                 << 0x0000000aU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
            = ((0xc00fffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U]) 
               | (0x3ff00000U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__44__03a36__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__53__03a45__KET__))) 
                                 << 0x00000014U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U] 
            = ((0x3fffffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[0U]) 
               | ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)) 
                   + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__))) 
                  << 0x0000001eU));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
            = ((0xffffff00U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U]) 
               | (0x000000ffU & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__))) 
                                 >> 2U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
            = ((0xfffc00ffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U]) 
               | (0x0003ff00U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__))) 
                                 << 8U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
            = ((0xf003ffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U]) 
               | (0x0ffc0000U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__))) 
                                 << 0x00000012U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U] 
            = ((0x0fffffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[1U]) 
               | ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__)) 
                   + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__))) 
                  << 0x0000001cU));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
            = ((0xffffffc0U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U]) 
               | (0x0000003fU & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__))) 
                                 >> 4U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
            = ((0xffff003fU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U]) 
               | (0x0000ffc0U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__))) 
                                 << 6U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
            = ((0xfc00ffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U]) 
               | (0x03ff0000U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__))) 
                                 << 0x00000010U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U] 
            = ((0x03ffffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[2U]) 
               | ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)) 
                   + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__))) 
                  << 0x0000001aU));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
            = ((0xfffffff0U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U]) 
               | (0x0000000fU & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__))) 
                                 >> 6U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
            = ((0xffffc00fU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U]) 
               | (0x00003ff0U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__))) 
                                 << 4U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
            = ((0xff003fffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U]) 
               | (0x00ffc000U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__))) 
                                 << 0x0000000eU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U] 
            = ((0x00ffffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[3U]) 
               | ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__)) 
                   + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__))) 
                  << 0x00000018U));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
            = ((0xfffffffcU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U]) 
               | (3U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__)) 
                         + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__))) 
                        >> 8U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
            = ((0xfffff003U & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U]) 
               | (0x00000ffcU & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__))) 
                                 << 2U)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
            = ((0xffc00fffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U]) 
               | (0x003ff000U & ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__)) 
                                  + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__))) 
                                 << 0x0000000cU)));
        vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U] 
            = ((0x003fffffU & vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data[4U]) 
               | ((VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__)) 
                   + VL_EXTENDS_II(10,9, (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__))) 
                  << 0x00000016U));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))))))))))) {
            if ((0U != (((1U == (3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))) 
                         << 2U) | (((0U == (3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[0]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg)));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__8__03a0__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg)))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[0U]))
                               : ((0U == (3U & (IData)(vlSelfRef.vec_multi_core__DOT__weight_reg)))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[0U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 2U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 2U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 2U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 2U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 2U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 2U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[1]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 2U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__17__03a9__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 2U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[0U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 2U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[0U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 4U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 4U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 4U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 4U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 4U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 4U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[2]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 4U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__26__03a18__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 4U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[0U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 4U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[0U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 6U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 6U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 6U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 6U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 6U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 6U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[3]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 6U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__35__03a27__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 6U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[0U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 6U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[0U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 8U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 8U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 8U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 8U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 8U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 8U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[4]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 8U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__44__03a36__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 8U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[1U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 8U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[1U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0aU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x0aU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x0aU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x0aU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x0aU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0aU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[5]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x0aU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__53__03a45__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x0aU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[1U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x0aU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[1U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0cU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x0cU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x0cU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x0cU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x0cU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0cU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[6]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x0cU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x0cU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[1U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x0cU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[1U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0eU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x0eU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x0eU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x0eU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x0eU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0eU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[7]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x0eU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x0eU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[1U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x0eU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[1U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x10U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x10U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x10U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x10U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x10U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x10U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[8]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x10U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x10U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[2U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x10U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[2U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x12U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x12U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x12U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x12U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x12U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x12U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[9]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x12U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x12U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[2U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x12U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[2U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x14U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x14U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x14U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x14U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x14U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x14U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[10]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x14U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x14U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[2U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x14U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[2U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x16U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x16U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x16U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x16U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x16U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x16U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[11]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x16U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x16U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[2U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x16U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[2U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x18U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x18U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x18U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x18U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x18U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x18U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[12]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x18U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x18U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[3U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x18U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[3U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1aU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x1aU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x1aU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x1aU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x1aU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1aU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[13]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x1aU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x1aU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[3U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x1aU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[3U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1cU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x1cU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x1cU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x1cU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x1cU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1cU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[14]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x1cU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x1cU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[3U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x1cU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[3U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1eU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x1eU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x1eU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x1eU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x1eU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1eU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[15]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x1eU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x1eU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[3U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x1eU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[3U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x20U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x20U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x20U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x20U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x20U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x20U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[16]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x20U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x20U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[4U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x20U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[4U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x22U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x22U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x22U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x22U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x22U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x22U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[17]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x22U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x22U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[4U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x22U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[4U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x24U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x24U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x24U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x24U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x24U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x24U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[18]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x24U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x24U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[4U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x24U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[4U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x26U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x26U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x26U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x26U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x26U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x26U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[19]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x26U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x26U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[4U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x26U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[4U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x28U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x28U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x28U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x28U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x28U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x28U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[20]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x28U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x28U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[5U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x28U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[5U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2aU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x2aU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x2aU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x2aU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x2aU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2aU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[21]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x2aU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x2aU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[5U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x2aU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[5U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2cU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x2cU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x2cU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x2cU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x2cU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2cU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[22]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x2cU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x2cU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[5U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x2cU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[5U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2eU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x2eU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x2eU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x2eU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x2eU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x2eU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[23]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x2eU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x2eU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[5U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x2eU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[5U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x30U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x30U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x30U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x30U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x30U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x30U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[24]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x30U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x30U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[6U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x30U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[6U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x32U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x32U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x32U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x32U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x32U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x32U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[25]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x32U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x32U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[6U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x32U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[6U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x34U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x34U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x34U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x34U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x34U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x34U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[26]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x34U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x34U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[6U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x34U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[6U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x36U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x36U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x36U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x36U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x36U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x36U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[27]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x36U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x36U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[6U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x36U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[6U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x38U)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x38U)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x38U)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x38U)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x38U)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x38U)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[28]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x38U))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x38U))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & vlSelfRef.i_data[7U]))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x38U))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & vlSelfRef.i_data[7U])))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3aU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x3aU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x3aU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x3aU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x3aU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3aU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[29]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x3aU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x3aU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[7U] 
                                                   >> 8U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x3aU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[7U] 
                                                          >> 8U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3cU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x3cU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x3cU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x3cU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x3cU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3cU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[30]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x3cU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x3cU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (0x000000ffU 
                                                & (vlSelfRef.i_data[7U] 
                                                   >> 0x00000010U)))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x3cU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (0x000000ffU 
                                                       & (vlSelfRef.i_data[7U] 
                                                          >> 0x00000010U))))
                                   : 0U)));
    }
    if (vlSelfRef.i_data_valid) {
        if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((((1U 
                                                 == 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3eU)))) 
                                                << 2U) 
                                               | (((0U 
                                                    == 
                                                    (3U 
                                                     & (IData)(
                                                               (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                >> 0x3eU)))) 
                                                   << 1U) 
                                                  | (2U 
                                                     == 
                                                     (3U 
                                                      & (IData)(
                                                                (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                                 >> 0x3eU)))))))))))) {
            if ((0U != (((1U == (3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                               >> 0x3eU)))) 
                         << 2U) | (((0U == (3U & (IData)(
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x3eU)))) 
                                    << 1U) | (2U == 
                                              (3U & (IData)(
                                                            (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x3eU)))))))) {
                if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                    VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:44: Assertion failed in %Nvec_multi_core.gen_PE[31]: unique case, but multiple matches found for '2'h%x'\n",0,
                                 64,VL_TIME_UNITED_Q(1000),
                                 -9,vlSymsp->name(),
                                 2,(3U & (IData)((vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                  >> 0x3eU))));
                    VL_STOP_MT("vec_multi_core.sv", 44, "");
                }
            }
        }
        vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__ 
            = (0x000001ffU & ((2U == (3U & (IData)(
                                                   (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                    >> 0x3eU))))
                               ? VL_EXTENDS_II(9,8, 
                                               (vlSelfRef.i_data[7U] 
                                                >> 0x00000018U))
                               : ((0U == (3U & (IData)(
                                                       (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                        >> 0x3eU))))
                                   ? (- VL_EXTENDS_II(9,8, 
                                                      (vlSelfRef.i_data[7U] 
                                                       >> 0x00000018U)))
                                   : 0U)));
    }
}

void Vvec_multi_core___024root___nba_sequent__TOP__2(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___nba_sequent__TOP__2\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__));
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_load_weight) {
            vlSelfRef.vec_multi_core__DOT__weight_reg 
                = vlSelfRef.i_weight;
        }
    } else {
        vlSelfRef.vec_multi_core__DOT__weight_reg = 0x5555555555555555ULL;
    }
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__));
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__0__KET__));
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__0__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__product_ready));
    vlSelfRef.vec_multi_core__DOT__product_ready = 
        ((IData)(vlSelfRef.rst_n) & (IData)(vlSelfRef.i_data_valid));
}

void Vvec_multi_core___024root___eval_nba(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_nba\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vvec_multi_core___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vvec_multi_core___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vvec_multi_core___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vvec_multi_core___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vvec_multi_core___024root___eval_phase__act(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_phase__act\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vvec_multi_core___024root___eval_triggers__act(vlSelf);
    Vvec_multi_core___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vvec_multi_core___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vvec_multi_core___024root___eval_phase__nba(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_phase__nba\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vvec_multi_core___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vvec_multi_core___024root___eval_nba(vlSelf);
        Vvec_multi_core___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vvec_multi_core___024root___eval(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vvec_multi_core___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vec_multi_core.sv", 5, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vvec_multi_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vec_multi_core.sv", 5, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vvec_multi_core___024root___eval_phase__act(vlSelf));
    } while (Vvec_multi_core___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vvec_multi_core___024root___eval_debug_assertions(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_debug_assertions\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.i_data_valid & 0xfeU)))) {
        Verilated::overWidthError("i_data_valid");
    }
    if (VL_UNLIKELY(((vlSelfRef.i_load_weight & 0xfeU)))) {
        Verilated::overWidthError("i_load_weight");
    }
}
#endif  // VL_DEBUG
