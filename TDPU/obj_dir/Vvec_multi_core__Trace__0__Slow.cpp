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
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"i_data_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"i_load_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+26,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declQuad(c+34,0,"i_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+36,0,"o_data_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("vec_multi_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+42,0,"LEN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+43,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"i_data_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"i_load_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+26,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declQuad(c+34,0,"i_weight",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+36,0,"o_data_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"o_result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+38,0,"weight_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+44,0,"PROD_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+1,0,"product",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 287,0);
    tracep->declBit(c+40,0,"product_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"TREE_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+41,0,"tree_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("gen_tree[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"OUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+47,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+10,0,"level_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 159,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+48,0,"OUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+43,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+15,0,"level_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 87,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+49,0,"OUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+50,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declQuad(c+18,0,"level_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"OUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+52,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+20,0,"level_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 25,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_tree[4]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+53,0,"OUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+54,0,"NUM_NODES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+21,0,"level_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
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
    bufp->fullIData(oldp+42,(0x00000020U),32);
    bufp->fullIData(oldp+43,(8U),32);
    bufp->fullIData(oldp+44,(9U),32);
    bufp->fullIData(oldp+45,(5U),32);
    bufp->fullIData(oldp+46,(0x0000000aU),32);
    bufp->fullIData(oldp+47,(0x00000010U),32);
    bufp->fullIData(oldp+48,(0x0000000bU),32);
    bufp->fullIData(oldp+49,(0x0000000cU),32);
    bufp->fullIData(oldp+50,(4U),32);
    bufp->fullIData(oldp+51,(0x0000000dU),32);
    bufp->fullIData(oldp+52,(2U),32);
    bufp->fullIData(oldp+53,(0x0000000eU),32);
    bufp->fullIData(oldp+54,(1U),32);
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
    // Locals
    VlWide<5>/*159:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_6;
    VlWide<9>/*287:0*/ __Vtemp_7;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    __Vtemp_3[2U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__)))))) 
                      << 8U) | (((IData)((((QData)((IData)(
                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__) 
                                                             << 9U) 
                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__)))) 
                                           << 0x00000012U) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__) 
                                                              << 9U) 
                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__)))))) 
                                 >> 0x0000001cU) | 
                                ((IData)(((((QData)((IData)(
                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__) 
                                                              << 9U) 
                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__)))) 
                                            << 0x00000012U) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__) 
                                                               << 9U) 
                                                              | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__))))) 
                                          >> 0x00000020U)) 
                                 << 4U)));
    __Vtemp_3[3U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__)))))) 
                      >> 0x00000018U) | (((IData)((
                                                   ((QData)((IData)(
                                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__) 
                                                                      << 9U) 
                                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__)))) 
                                                    << 0x00000012U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__) 
                                                                       << 9U) 
                                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__)))))) 
                                          << 0x0000000cU) 
                                         | ((IData)(
                                                    ((((QData)((IData)(
                                                                       (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                                         << 9U) 
                                                                        | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                                       << 0x00000012U) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__) 
                                                                          << 9U) 
                                                                         | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__))))) 
                                                     >> 0x00000020U)) 
                                            << 8U)));
    __Vtemp_3[4U] = (((0x000000ffU & ((IData)((((QData)((IData)(
                                                                (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__) 
                                                                  << 9U) 
                                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__)))) 
                                                << 0x00000012U) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__)))))) 
                                      >> 0x00000014U)) 
                      | ((IData)(((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__))))) 
                                  >> 0x00000020U)) 
                         >> 0x00000018U)) | ((0x00000f00U 
                                              & ((IData)(
                                                         (((QData)((IData)(
                                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__)))) 
                                                           << 0x00000012U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__) 
                                                                              << 9U) 
                                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__)))))) 
                                                 >> 0x00000014U)) 
                                             | ((IData)(
                                                        ((((QData)((IData)(
                                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__287__03a279__KET__) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__278__03a270__KET__)))) 
                                                           << 0x00000012U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__269__03a261__KET__) 
                                                                              << 9U) 
                                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__260__03a252__KET__))))) 
                                                         >> 0x00000020U)) 
                                                << 0x0000000cU)));
    __Vtemp_6[2U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__)))))) 
                      << 8U) | (((IData)((((QData)((IData)(
                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__) 
                                                             << 9U) 
                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)))) 
                                           << 0x00000012U) 
                                          | (QData)((IData)(
                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__53__03a45__KET__) 
                                                              << 9U) 
                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__44__03a36__KET__)))))) 
                                 >> 0x0000001cU) | 
                                ((IData)(((((QData)((IData)(
                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__) 
                                                              << 9U) 
                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)))) 
                                            << 0x00000012U) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__53__03a45__KET__) 
                                                               << 9U) 
                                                              | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__44__03a36__KET__))))) 
                                          >> 0x00000020U)) 
                                 << 4U)));
    __Vtemp_6[3U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__)))))) 
                      >> 0x00000018U) | (((IData)((
                                                   ((QData)((IData)(
                                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__) 
                                                                      << 9U) 
                                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__)))) 
                                                    << 0x00000012U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__) 
                                                                       << 9U) 
                                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__)))))) 
                                          << 0x0000000cU) 
                                         | ((IData)(
                                                    ((((QData)((IData)(
                                                                       (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                                         << 9U) 
                                                                        | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                                       << 0x00000012U) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__) 
                                                                          << 9U) 
                                                                         | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__))))) 
                                                     >> 0x00000020U)) 
                                            << 8U)));
    __Vtemp_6[4U] = (((0x000000ffU & ((IData)((((QData)((IData)(
                                                                (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__) 
                                                                  << 9U) 
                                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__)))) 
                                                << 0x00000012U) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__)))))) 
                                      >> 0x00000014U)) 
                      | ((IData)(((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__))))) 
                                  >> 0x00000020U)) 
                         >> 0x00000018U)) | ((0x00000f00U 
                                              & ((IData)(
                                                         (((QData)((IData)(
                                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__)))) 
                                                           << 0x00000012U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__) 
                                                                              << 9U) 
                                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__)))))) 
                                                 >> 0x00000014U)) 
                                             | ((IData)(
                                                        ((((QData)((IData)(
                                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__143__03a135__KET__) 
                                                                             << 9U) 
                                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__134__03a126__KET__)))) 
                                                           << 0x00000012U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__125__03a117__KET__) 
                                                                              << 9U) 
                                                                             | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__116__03a108__KET__))))) 
                                                         >> 0x00000020U)) 
                                                << 0x0000000cU)));
    __Vtemp_7[0U] = (IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__35__03a27__KET__) 
                                                << 9U) 
                                               | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__26__03a18__KET__)))) 
                              << 0x00000012U) | (QData)((IData)(
                                                                (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__17__03a9__KET__) 
                                                                  << 9U) 
                                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__8__03a0__KET__))))));
    __Vtemp_7[1U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__53__03a45__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__44__03a36__KET__)))))) 
                      << 4U) | (IData)(((((QData)((IData)(
                                                          (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__35__03a27__KET__) 
                                                            << 9U) 
                                                           | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__26__03a18__KET__)))) 
                                          << 0x00000012U) 
                                         | (QData)((IData)(
                                                           (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__17__03a9__KET__) 
                                                             << 9U) 
                                                            | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__8__03a0__KET__))))) 
                                        >> 0x00000020U)));
    __Vtemp_7[2U] = __Vtemp_6[2U];
    __Vtemp_7[3U] = __Vtemp_6[3U];
    __Vtemp_7[4U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__)))))) 
                      << 0x00000010U) | __Vtemp_6[4U]);
    __Vtemp_7[5U] = (((IData)((((QData)((IData)((((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                  << 9U) 
                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                << 0x00000012U) | (QData)((IData)(
                                                                  (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                                    << 9U) 
                                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__)))))) 
                      >> 0x00000010U) | (((IData)((
                                                   ((QData)((IData)(
                                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__) 
                                                                      << 9U) 
                                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__)))) 
                                                    << 0x00000012U) 
                                                   | (QData)((IData)(
                                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__) 
                                                                       << 9U) 
                                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__)))))) 
                                          << 0x00000014U) 
                                         | ((IData)(
                                                    ((((QData)((IData)(
                                                                       (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                                         << 9U) 
                                                                        | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                                       << 0x00000012U) 
                                                      | (QData)((IData)(
                                                                        (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                                          << 9U) 
                                                                         | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__))))) 
                                                     >> 0x00000020U)) 
                                            << 0x00000010U)));
    __Vtemp_7[6U] = (((0x0000ffffU & ((IData)((((QData)((IData)(
                                                                (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__215__03a207__KET__) 
                                                                  << 9U) 
                                                                 | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__206__03a198__KET__)))) 
                                                << 0x00000012U) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__197__03a189__KET__) 
                                                                   << 9U) 
                                                                  | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__188__03a180__KET__)))))) 
                                      >> 0x0000000cU)) 
                      | ((IData)(((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__))))) 
                                  >> 0x00000020U)) 
                         >> 0x00000010U)) | (__Vtemp_3[2U] 
                                             << 0x00000010U));
    __Vtemp_7[7U] = ((__Vtemp_3[2U] >> 0x00000010U) 
                     | (__Vtemp_3[3U] << 0x00000010U));
    __Vtemp_7[8U] = ((__Vtemp_3[3U] >> 0x00000010U) 
                     | (__Vtemp_3[4U] << 0x00000010U));
    bufp->fullWData(oldp+1,(__Vtemp_7),288);
    bufp->fullWData(oldp+10,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data),160);
    bufp->fullWData(oldp+15,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data),88);
    bufp->fullQData(oldp+18,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data),48);
    bufp->fullIData(oldp+20,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data),26);
    bufp->fullSData(oldp+21,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data),14);
    bufp->fullBit(oldp+22,(vlSelfRef.clk));
    bufp->fullBit(oldp+23,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+24,(vlSelfRef.i_data_valid));
    bufp->fullBit(oldp+25,(vlSelfRef.i_load_weight));
    bufp->fullWData(oldp+26,(vlSelfRef.i_data),256);
    bufp->fullQData(oldp+34,(vlSelfRef.i_weight),64);
    bufp->fullBit(oldp+36,(vlSelfRef.o_data_ready));
    bufp->fullIData(oldp+37,(vlSelfRef.o_result),32);
    bufp->fullQData(oldp+38,(vlSelfRef.vec_multi_core__DOT__weight_reg),64);
    bufp->fullBit(oldp+40,(vlSelfRef.vec_multi_core__DOT__product_ready));
    bufp->fullCData(oldp+41,(((((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__) 
                                << 4U) | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) 
                                           << 2U))) 
                              | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) 
                                  << 1U) | (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__0__KET__)))),5);
}
