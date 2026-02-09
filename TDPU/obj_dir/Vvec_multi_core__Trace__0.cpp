// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vvec_multi_core__Syms.h"


void Vvec_multi_core___024root__trace_chg_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vvec_multi_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_chg_0\n"); );
    // Body
    Vvec_multi_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvec_multi_core___024root*>(voidSelf);
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vvec_multi_core___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vvec_multi_core___024root__trace_chg_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_chg_0_sub_0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.vec_multi_core__DOT__weight_reg),32);
        bufp->chgWData(oldp+1,(vlSelfRef.vec_multi_core__DOT__product),512);
        bufp->chgBit(oldp+17,(vlSelfRef.vec_multi_core__DOT__product_ready));
        bufp->chgCData(oldp+18,(((((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__) 
                                   << 4U) | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) 
                                              << 3U) 
                                             | ((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) 
                                                << 2U))) 
                                 | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) 
                                     << 1U) | (IData)(vlSelfRef.vec_multi_core__DOT__product_ready)))),5);
    }
    bufp->chgBit(oldp+19,(vlSelfRef.clk));
    bufp->chgBit(oldp+20,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+21,(vlSelfRef.i_data_valid));
    bufp->chgBit(oldp+22,(vlSelfRef.i_load_weight));
    bufp->chgWData(oldp+23,(vlSelfRef.i_data),128);
    bufp->chgIData(oldp+27,(vlSelfRef.i_weight),32);
    bufp->chgBit(oldp+28,(vlSelfRef.o_data_ready));
    bufp->chgIData(oldp+29,(vlSelfRef.o_result),32);
}

void Vvec_multi_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_cleanup\n"); );
    // Body
    Vvec_multi_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvec_multi_core___024root*>(voidSelf);
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
