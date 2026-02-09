// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vvec_multi_core__Syms.h"


VL_ATTR_COLD void Vvec_multi_core___024root__trace_init_sub__TOP__0(Vvec_multi_core___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_init_sub__TOP__0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+20,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"i_data_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_load_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+24,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+28,0,"i_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"o_data_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("vec_multi_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+31,0,"LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+32,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+20,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"i_data_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_load_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+24,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+28,0,"i_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"o_data_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"weight_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+2,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBit(c+18,0,"product_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"TREE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+19,0,"tree_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("gen_tree_level[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree_level[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree_level[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree_level[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+35,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+36,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_init_top(Vvec_multi_core___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_init_top\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vvec_multi_core___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vvec_multi_core___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vvec_multi_core___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vvec_multi_core___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vvec_multi_core___024root__trace_register(Vvec_multi_core___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_register\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vvec_multi_core___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vvec_multi_core___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vvec_multi_core___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vvec_multi_core___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_const_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vvec_multi_core___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_const_0\n"); );
    // Body
    Vvec_multi_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvec_multi_core___024root*>(voidSelf);
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vvec_multi_core___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_const_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_const_0_sub_0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+31,(0x00000010U),32);
    bufp->fullIData(oldp+32,(8U),32);
    bufp->fullIData(oldp+33,(4U),32);
    bufp->fullIData(oldp+34,(2U),32);
    bufp->fullIData(oldp+35,(1U),32);
    bufp->fullIData(oldp+36,(0x00000010U),32);
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_full_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vvec_multi_core___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_full_0\n"); );
    // Body
    Vvec_multi_core___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vvec_multi_core___024root*>(voidSelf);
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vvec_multi_core___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vvec_multi_core___024root__trace_full_0_sub_0(Vvec_multi_core___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvec_multi_core___024root__trace_full_0_sub_0\n"); );
    Vvec_multi_core__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+1,(vlSelfRef.vec_multi_core__DOT__weight_reg),32);
    bufp->fullWData(oldp+2,(vlSelfRef.vec_multi_core__DOT__product),512);
    bufp->fullBit(oldp+18,(vlSelfRef.vec_multi_core__DOT__product_ready));
    bufp->fullCData(oldp+19,(((((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__) 
                                << 4U) | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) 
                                           << 2U))) 
                              | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.vec_multi_core__DOT__product_ready)))),5);
    bufp->fullBit(oldp+20,(vlSelfRef.clk));
    bufp->fullBit(oldp+21,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+22,(vlSelfRef.i_data_valid));
    bufp->fullBit(oldp+23,(vlSelfRef.i_load_weight));
    bufp->fullWData(oldp+24,(vlSelfRef.i_data),128);
    bufp->fullIData(oldp+28,(vlSelfRef.i_weight),32);
    bufp->fullBit(oldp+29,(vlSelfRef.o_data_ready));
    bufp->fullIData(oldp+30,(vlSelfRef.o_result),32);
}
