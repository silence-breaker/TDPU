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
    // Locals
    VlWide<16>/*511:0*/ __Vdly__vec_multi_core__DOT__product;
    VL_ZERO_W(512, __Vdly__vec_multi_core__DOT__product);
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v0;
    __VdlyVal__vec_multi_core__DOT__tree_data__v0 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v0;
    __VdlySet__vec_multi_core__DOT__tree_data__v0 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v1;
    __VdlySet__vec_multi_core__DOT__tree_data__v1 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v2;
    __VdlyVal__vec_multi_core__DOT__tree_data__v2 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v2;
    __VdlySet__vec_multi_core__DOT__tree_data__v2 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v3;
    __VdlySet__vec_multi_core__DOT__tree_data__v3 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v4;
    __VdlyVal__vec_multi_core__DOT__tree_data__v4 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v4;
    __VdlySet__vec_multi_core__DOT__tree_data__v4 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v5;
    __VdlySet__vec_multi_core__DOT__tree_data__v5 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v6;
    __VdlyVal__vec_multi_core__DOT__tree_data__v6 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v6;
    __VdlySet__vec_multi_core__DOT__tree_data__v6 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v7;
    __VdlySet__vec_multi_core__DOT__tree_data__v7 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v8;
    __VdlyVal__vec_multi_core__DOT__tree_data__v8 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v8;
    __VdlySet__vec_multi_core__DOT__tree_data__v8 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v9;
    __VdlySet__vec_multi_core__DOT__tree_data__v9 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v10;
    __VdlyVal__vec_multi_core__DOT__tree_data__v10 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v10;
    __VdlySet__vec_multi_core__DOT__tree_data__v10 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v11;
    __VdlySet__vec_multi_core__DOT__tree_data__v11 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v12;
    __VdlyVal__vec_multi_core__DOT__tree_data__v12 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v12;
    __VdlySet__vec_multi_core__DOT__tree_data__v12 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v13;
    __VdlySet__vec_multi_core__DOT__tree_data__v13 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v14;
    __VdlyVal__vec_multi_core__DOT__tree_data__v14 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v14;
    __VdlySet__vec_multi_core__DOT__tree_data__v14 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v15;
    __VdlySet__vec_multi_core__DOT__tree_data__v15 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v16;
    __VdlyVal__vec_multi_core__DOT__tree_data__v16 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v16;
    __VdlySet__vec_multi_core__DOT__tree_data__v16 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v17;
    __VdlySet__vec_multi_core__DOT__tree_data__v17 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v18;
    __VdlyVal__vec_multi_core__DOT__tree_data__v18 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v18;
    __VdlySet__vec_multi_core__DOT__tree_data__v18 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v19;
    __VdlySet__vec_multi_core__DOT__tree_data__v19 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v20;
    __VdlyVal__vec_multi_core__DOT__tree_data__v20 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v20;
    __VdlySet__vec_multi_core__DOT__tree_data__v20 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v21;
    __VdlySet__vec_multi_core__DOT__tree_data__v21 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v22;
    __VdlyVal__vec_multi_core__DOT__tree_data__v22 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v22;
    __VdlySet__vec_multi_core__DOT__tree_data__v22 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v23;
    __VdlySet__vec_multi_core__DOT__tree_data__v23 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v24;
    __VdlyVal__vec_multi_core__DOT__tree_data__v24 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v24;
    __VdlySet__vec_multi_core__DOT__tree_data__v24 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v25;
    __VdlySet__vec_multi_core__DOT__tree_data__v25 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v26;
    __VdlyVal__vec_multi_core__DOT__tree_data__v26 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v26;
    __VdlySet__vec_multi_core__DOT__tree_data__v26 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v27;
    __VdlySet__vec_multi_core__DOT__tree_data__v27 = 0;
    IData/*31:0*/ __VdlyVal__vec_multi_core__DOT__tree_data__v28;
    __VdlyVal__vec_multi_core__DOT__tree_data__v28 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v28;
    __VdlySet__vec_multi_core__DOT__tree_data__v28 = 0;
    CData/*0:0*/ __VdlySet__vec_multi_core__DOT__tree_data__v29;
    __VdlySet__vec_multi_core__DOT__tree_data__v29 = 0;
    // Body
    __Vdly__vec_multi_core__DOT__product[0U] = vlSelfRef.vec_multi_core__DOT__product[0U];
    __Vdly__vec_multi_core__DOT__product[1U] = vlSelfRef.vec_multi_core__DOT__product[1U];
    __Vdly__vec_multi_core__DOT__product[2U] = vlSelfRef.vec_multi_core__DOT__product[2U];
    __Vdly__vec_multi_core__DOT__product[3U] = vlSelfRef.vec_multi_core__DOT__product[3U];
    __Vdly__vec_multi_core__DOT__product[4U] = vlSelfRef.vec_multi_core__DOT__product[4U];
    __Vdly__vec_multi_core__DOT__product[5U] = vlSelfRef.vec_multi_core__DOT__product[5U];
    __Vdly__vec_multi_core__DOT__product[6U] = vlSelfRef.vec_multi_core__DOT__product[6U];
    __Vdly__vec_multi_core__DOT__product[7U] = vlSelfRef.vec_multi_core__DOT__product[7U];
    __Vdly__vec_multi_core__DOT__product[8U] = vlSelfRef.vec_multi_core__DOT__product[8U];
    __Vdly__vec_multi_core__DOT__product[9U] = vlSelfRef.vec_multi_core__DOT__product[9U];
    __Vdly__vec_multi_core__DOT__product[0x0000000aU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000aU];
    __Vdly__vec_multi_core__DOT__product[0x0000000bU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000bU];
    __Vdly__vec_multi_core__DOT__product[0x0000000cU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000cU];
    __Vdly__vec_multi_core__DOT__product[0x0000000dU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000dU];
    __Vdly__vec_multi_core__DOT__product[0x0000000eU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000eU];
    __Vdly__vec_multi_core__DOT__product[0x0000000fU] 
        = vlSelfRef.vec_multi_core__DOT__product[0x0000000fU];
    __VdlySet__vec_multi_core__DOT__tree_data__v0 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v1 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v2 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v3 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v4 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v5 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v6 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v7 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v8 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v9 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v10 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v11 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v12 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v13 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v14 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v15 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v16 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v17 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v18 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v19 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v20 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v21 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v22 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v23 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v24 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v25 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v26 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v27 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v28 = 0U;
    __VdlySet__vec_multi_core__DOT__tree_data__v29 = 0U;
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__));
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.vec_multi_core__DOT__product_ready) {
            __VdlyVal__vec_multi_core__DOT__tree_data__v0 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][1U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v0 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v2 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][2U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][3U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v2 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v4 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][4U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][5U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v4 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v6 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][6U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][7U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v6 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v8 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][8U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][9U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v8 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v10 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0aU] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0bU]);
            __VdlySet__vec_multi_core__DOT__tree_data__v10 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v12 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0cU] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0dU]);
            __VdlySet__vec_multi_core__DOT__tree_data__v12 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v14 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0eU] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [0U][0x0fU]);
            __VdlySet__vec_multi_core__DOT__tree_data__v14 = 1U;
        }
        if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) {
            __VdlyVal__vec_multi_core__DOT__tree_data__v16 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][0U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][1U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v16 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v18 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][2U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][3U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v18 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v20 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][4U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][5U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v20 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v22 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][6U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [1U][7U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v22 = 1U;
        }
        if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) {
            __VdlyVal__vec_multi_core__DOT__tree_data__v24 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [2U][0U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [2U][1U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v24 = 1U;
            __VdlyVal__vec_multi_core__DOT__tree_data__v26 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [2U][2U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [2U][3U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v26 = 1U;
        }
        if (vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) {
            __VdlyVal__vec_multi_core__DOT__tree_data__v28 
                = (vlSelfRef.vec_multi_core__DOT__tree_data
                   [3U][0U] + vlSelfRef.vec_multi_core__DOT__tree_data
                   [3U][1U]);
            __VdlySet__vec_multi_core__DOT__tree_data__v28 = 1U;
        }
    } else {
        __VdlySet__vec_multi_core__DOT__tree_data__v1 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v3 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v5 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v7 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v9 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v11 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v13 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v15 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v17 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v19 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v21 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v23 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v25 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v27 = 1U;
        __VdlySet__vec_multi_core__DOT__tree_data__v29 = 1U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v0) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][0U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v0;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v1) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][0U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v2) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][1U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v2;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v3) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][1U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v4) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][2U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v4;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v5) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][2U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v6) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][3U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v6;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v7) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][3U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v8) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][4U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v8;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v9) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][4U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v10) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][5U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v10;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v11) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][5U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v12) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][6U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v12;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v13) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][6U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v14) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][7U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v14;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v15) {
        vlSelfRef.vec_multi_core__DOT__tree_data[1U][7U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v16) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][0U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v16;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v17) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][0U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v18) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][1U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v18;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v19) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][1U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v20) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][2U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v20;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v21) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][2U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v22) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][3U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v22;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v23) {
        vlSelfRef.vec_multi_core__DOT__tree_data[2U][3U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v24) {
        vlSelfRef.vec_multi_core__DOT__tree_data[3U][0U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v24;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v25) {
        vlSelfRef.vec_multi_core__DOT__tree_data[3U][0U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v26) {
        vlSelfRef.vec_multi_core__DOT__tree_data[3U][1U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v26;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v27) {
        vlSelfRef.vec_multi_core__DOT__tree_data[3U][1U] = 0U;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v28) {
        vlSelfRef.vec_multi_core__DOT__tree_data[4U][0U] 
            = __VdlyVal__vec_multi_core__DOT__tree_data__v28;
    }
    if (__VdlySet__vec_multi_core__DOT__tree_data__v29) {
        vlSelfRef.vec_multi_core__DOT__tree_data[4U][0U] = 0U;
    }
    vlSelfRef.o_data_ready = vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__;
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__));
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__));
    vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__ 
        = ((IData)(vlSelfRef.rst_n) && (IData)(vlSelfRef.vec_multi_core__DOT__product_ready));
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlSelfRef.vec_multi_core__DOT__weight_reg)) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & vlSelfRef.vec_multi_core__DOT__weight_reg)) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & vlSelfRef.vec_multi_core__DOT__weight_reg)))))))))) {
                if ((0U != (((1U == (3U & vlSelfRef.vec_multi_core__DOT__weight_reg)) 
                             << 2U) | (((0U == (3U 
                                                & vlSelfRef.vec_multi_core__DOT__weight_reg)) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & vlSelfRef.vec_multi_core__DOT__weight_reg)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[0]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & vlSelfRef.vec_multi_core__DOT__weight_reg));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0U] 
                = ((2U == (3U & vlSelfRef.vec_multi_core__DOT__weight_reg))
                    ? VL_EXTENDS_II(32,8, (0x000000ffU 
                                           & vlSelfRef.i_data[0U]))
                    : ((0U == (3U & vlSelfRef.vec_multi_core__DOT__weight_reg))
                        ? (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                                  & vlSelfRef.i_data[0U])))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0U] 
                = vlSelfRef.vec_multi_core__DOT__product[0U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 2U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 2U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 2U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 2U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 2U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 2U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[1]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 2U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[1U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 2U))) ? VL_EXTENDS_II(32,8, 
                                                          (0x000000ffU 
                                                           & (vlSelfRef.i_data[0U] 
                                                              >> 8U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 2U))) ? (- 
                                                 VL_EXTENDS_II(32,8, 
                                                               (0x000000ffU 
                                                                & (vlSelfRef.i_data[0U] 
                                                                   >> 8U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[1U] 
                = vlSelfRef.vec_multi_core__DOT__product[1U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[1U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 4U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 4U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 4U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 4U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 4U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 4U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[2]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 4U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[2U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 4U))) ? VL_EXTENDS_II(32,8, 
                                                          (0x000000ffU 
                                                           & (vlSelfRef.i_data[0U] 
                                                              >> 0x00000010U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 4U))) ? (- 
                                                 VL_EXTENDS_II(32,8, 
                                                               (0x000000ffU 
                                                                & (vlSelfRef.i_data[0U] 
                                                                   >> 0x00000010U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[2U] 
                = vlSelfRef.vec_multi_core__DOT__product[2U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[2U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 6U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 6U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 6U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 6U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 6U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 6U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[3]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 6U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[3U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 6U))) ? VL_EXTENDS_II(32,8, 
                                                          (vlSelfRef.i_data[0U] 
                                                           >> 0x00000018U))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 6U))) ? (- 
                                                 VL_EXTENDS_II(32,8, 
                                                               (vlSelfRef.i_data[0U] 
                                                                >> 0x00000018U)))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[3U] 
                = vlSelfRef.vec_multi_core__DOT__product[3U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[3U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 8U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 8U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 8U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 8U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 8U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 8U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[4]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 8U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[4U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 8U))) ? VL_EXTENDS_II(32,8, 
                                                          (0x000000ffU 
                                                           & vlSelfRef.i_data[1U]))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 8U))) ? (- 
                                                 VL_EXTENDS_II(32,8, 
                                                               (0x000000ffU 
                                                                & vlSelfRef.i_data[1U])))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[4U] 
                = vlSelfRef.vec_multi_core__DOT__product[4U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[4U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x0aU))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x0aU))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0aU))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x0aU))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x0aU))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x0aU))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[5]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x0aU)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[5U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x0aU))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[1U] 
                                                                 >> 8U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x0aU))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[1U] 
                                                  >> 8U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[5U] 
                = vlSelfRef.vec_multi_core__DOT__product[5U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[5U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x0cU))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x0cU))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0cU))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x0cU))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x0cU))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x0cU))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[6]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x0cU)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[6U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x0cU))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[1U] 
                                                                 >> 0x00000010U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x0cU))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[1U] 
                                                  >> 0x00000010U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[6U] 
                = vlSelfRef.vec_multi_core__DOT__product[6U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[6U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x0eU))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x0eU))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x0eU))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x0eU))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x0eU))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x0eU))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[7]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x0eU)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[7U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x0eU))) ? VL_EXTENDS_II(32,8, 
                                                             (vlSelfRef.i_data[1U] 
                                                              >> 0x00000018U))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x0eU))) ? 
                       (- VL_EXTENDS_II(32,8, (vlSelfRef.i_data[1U] 
                                               >> 0x00000018U)))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[7U] 
                = vlSelfRef.vec_multi_core__DOT__product[7U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[7U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x10U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x10U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x10U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x10U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x10U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x10U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[8]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x10U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[8U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x10U))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & vlSelfRef.i_data[2U]))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x10U))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & vlSelfRef.i_data[2U])))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[8U] 
                = vlSelfRef.vec_multi_core__DOT__product[8U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[8U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x12U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x12U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x12U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x12U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x12U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x12U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[9]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x12U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[9U] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x12U))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[2U] 
                                                                 >> 8U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x12U))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[2U] 
                                                  >> 8U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[9U] 
                = vlSelfRef.vec_multi_core__DOT__product[9U];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[9U] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x14U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x14U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x14U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x14U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x14U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x14U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[10]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x14U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000aU] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x14U))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[2U] 
                                                                 >> 0x00000010U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x14U))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[2U] 
                                                  >> 0x00000010U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000aU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000aU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000aU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x16U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x16U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x16U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x16U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x16U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x16U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[11]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x16U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000bU] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x16U))) ? VL_EXTENDS_II(32,8, 
                                                             (vlSelfRef.i_data[2U] 
                                                              >> 0x00000018U))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x16U))) ? 
                       (- VL_EXTENDS_II(32,8, (vlSelfRef.i_data[2U] 
                                               >> 0x00000018U)))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000bU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000bU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000bU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x18U))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x18U))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x18U))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x18U))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x18U))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x18U))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[12]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x18U)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000cU] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x18U))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & vlSelfRef.i_data[3U]))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x18U))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & vlSelfRef.i_data[3U])))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000cU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000cU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000cU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x1aU))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x1aU))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1aU))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x1aU))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x1aU))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x1aU))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[13]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x1aU)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000dU] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x1aU))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[3U] 
                                                                 >> 8U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x1aU))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[3U] 
                                                  >> 8U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000dU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000dU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000dU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x1cU))) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (3U 
                                                         & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                            >> 0x1cU))) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (3U 
                                                          & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                             >> 0x1cU))))))))))) {
                if ((0U != (((1U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                           >> 0x1cU))) 
                             << 2U) | (((0U == (3U 
                                                & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                   >> 0x1cU))) 
                                        << 1U) | (2U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x1cU))))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[14]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                              >> 0x1cU)));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000eU] 
                = ((2U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                 >> 0x1cU))) ? VL_EXTENDS_II(32,8, 
                                                             (0x000000ffU 
                                                              & (vlSelfRef.i_data[3U] 
                                                                 >> 0x00000010U)))
                    : ((0U == (3U & (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x1cU))) ? 
                       (- VL_EXTENDS_II(32,8, (0x000000ffU 
                                               & (vlSelfRef.i_data[3U] 
                                                  >> 0x00000010U))))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000eU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000eU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000eU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_data_valid) {
            if (VL_UNLIKELY(((1U & (~ VL_ONEHOT_I((
                                                   ((1U 
                                                     == 
                                                     (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                      >> 0x1eU)) 
                                                    << 2U) 
                                                   | (((0U 
                                                        == 
                                                        (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                         >> 0x1eU)) 
                                                       << 1U) 
                                                      | (2U 
                                                         == 
                                                         (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                          >> 0x1eU)))))))))) {
                if ((0U != (((1U == (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                     >> 0x1eU)) << 2U) 
                            | (((0U == (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                        >> 0x1eU)) 
                                << 1U) | (2U == (vlSelfRef.vec_multi_core__DOT__weight_reg 
                                                 >> 0x1eU)))))) {
                    if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                        VL_WRITEF_NX("[%0t] %%Error: vec_multi_core.sv:49: Assertion failed in %Nvec_multi_core.gen_PE[15]: unique case, but multiple matches found for '2'h%x'\n",0,
                                     64,VL_TIME_UNITED_Q(1000),
                                     -9,vlSymsp->name(),
                                     2,(vlSelfRef.vec_multi_core__DOT__weight_reg 
                                        >> 0x1eU));
                        VL_STOP_MT("vec_multi_core.sv", 49, "");
                    }
                }
            }
            __Vdly__vec_multi_core__DOT__product[0x0000000fU] 
                = ((2U == (vlSelfRef.vec_multi_core__DOT__weight_reg 
                           >> 0x1eU)) ? VL_EXTENDS_II(32,8, 
                                                      (vlSelfRef.i_data[3U] 
                                                       >> 0x00000018U))
                    : ((0U == (vlSelfRef.vec_multi_core__DOT__weight_reg 
                               >> 0x1eU)) ? (- VL_EXTENDS_II(32,8, 
                                                             (vlSelfRef.i_data[3U] 
                                                              >> 0x00000018U)))
                        : 0U));
        } else {
            __Vdly__vec_multi_core__DOT__product[0x0000000fU] 
                = vlSelfRef.vec_multi_core__DOT__product[0x0000000fU];
        }
        vlSelfRef.vec_multi_core__DOT__product_ready 
            = vlSelfRef.i_data_valid;
    } else {
        __Vdly__vec_multi_core__DOT__product[0x0000000fU] = 0U;
        vlSelfRef.vec_multi_core__DOT__product_ready = 0U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.i_load_weight) {
            vlSelfRef.vec_multi_core__DOT__weight_reg 
                = vlSelfRef.i_weight;
        }
    } else {
        vlSelfRef.vec_multi_core__DOT__weight_reg = 0x55555555U;
    }
    vlSelfRef.vec_multi_core__DOT__product[0U] = __Vdly__vec_multi_core__DOT__product[0U];
    vlSelfRef.vec_multi_core__DOT__product[1U] = __Vdly__vec_multi_core__DOT__product[1U];
    vlSelfRef.vec_multi_core__DOT__product[2U] = __Vdly__vec_multi_core__DOT__product[2U];
    vlSelfRef.vec_multi_core__DOT__product[3U] = __Vdly__vec_multi_core__DOT__product[3U];
    vlSelfRef.vec_multi_core__DOT__product[4U] = __Vdly__vec_multi_core__DOT__product[4U];
    vlSelfRef.vec_multi_core__DOT__product[5U] = __Vdly__vec_multi_core__DOT__product[5U];
    vlSelfRef.vec_multi_core__DOT__product[6U] = __Vdly__vec_multi_core__DOT__product[6U];
    vlSelfRef.vec_multi_core__DOT__product[7U] = __Vdly__vec_multi_core__DOT__product[7U];
    vlSelfRef.vec_multi_core__DOT__product[8U] = __Vdly__vec_multi_core__DOT__product[8U];
    vlSelfRef.vec_multi_core__DOT__product[9U] = __Vdly__vec_multi_core__DOT__product[9U];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000aU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000aU];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000bU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000bU];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000cU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000cU];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000dU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000dU];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000eU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000eU];
    vlSelfRef.vec_multi_core__DOT__product[0x0000000fU] 
        = __Vdly__vec_multi_core__DOT__product[0x0000000fU];
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

void Vvec_multi_core___024root___eval_nba(Vvec_multi_core___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root___eval_nba\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vvec_multi_core___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
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
            VL_FATAL_MT("vec_multi_core.sv", 7, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vvec_multi_core___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vec_multi_core.sv", 7, "", "Active region did not converge after 100 tries");
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
