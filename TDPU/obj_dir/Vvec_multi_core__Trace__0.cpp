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
    // Locals
    VlWide<5>/*159:0*/ __Vtemp_3;
    VlWide<5>/*159:0*/ __Vtemp_6;
    VlWide<9>/*287:0*/ __Vtemp_7;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        __Vtemp_3[2U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
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
                                     >> 0x0000001cU) 
                                    | ((IData)(((((QData)((IData)(
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
        __Vtemp_3[3U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__251__03a243__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__242__03a234__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__233__03a225__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__224__03a216__KET__)))))) 
                          >> 0x00000018U) | (((IData)(
                                                      (((QData)((IData)(
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
        __Vtemp_3[4U] = (((0x000000ffU & ((IData)((
                                                   ((QData)((IData)(
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
        __Vtemp_6[2U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
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
                                     >> 0x0000001cU) 
                                    | ((IData)(((((QData)((IData)(
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
        __Vtemp_6[3U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__107__03a99__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__98__03a90__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__89__03a81__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__80__03a72__KET__)))))) 
                          >> 0x00000018U) | (((IData)(
                                                      (((QData)((IData)(
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
        __Vtemp_6[4U] = (((0x000000ffU & ((IData)((
                                                   ((QData)((IData)(
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
        __Vtemp_7[0U] = (IData)((((QData)((IData)((
                                                   ((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__35__03a27__KET__) 
                                                    << 9U) 
                                                   | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__26__03a18__KET__)))) 
                                  << 0x00000012U) | (QData)((IData)(
                                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__17__03a9__KET__) 
                                                                      << 9U) 
                                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__8__03a0__KET__))))));
        __Vtemp_7[1U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__71__03a63__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__62__03a54__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
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
        __Vtemp_7[4U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__)))))) 
                          << 0x00000010U) | __Vtemp_6[4U]);
        __Vtemp_7[5U] = (((IData)((((QData)((IData)(
                                                    (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__179__03a171__KET__) 
                                                      << 9U) 
                                                     | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__170__03a162__KET__)))) 
                                    << 0x00000012U) 
                                   | (QData)((IData)(
                                                     (((IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__161__03a153__KET__) 
                                                       << 9U) 
                                                      | (IData)(vlSelfRef.vec_multi_core__DOT__product__BRA__152__03a144__KET__)))))) 
                          >> 0x00000010U) | (((IData)(
                                                      (((QData)((IData)(
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
        __Vtemp_7[6U] = (((0x0000ffffU & ((IData)((
                                                   ((QData)((IData)(
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
        bufp->chgWData(oldp+0,(__Vtemp_7),288);
        bufp->chgWData(oldp+9,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data),160);
        bufp->chgWData(oldp+14,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data),88);
        bufp->chgQData(oldp+17,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data),48);
        bufp->chgIData(oldp+19,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data),26);
        bufp->chgSData(oldp+20,(vlSelfRef.vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data),14);
    }
    bufp->chgBit(oldp+21,(vlSelfRef.clk));
    bufp->chgBit(oldp+22,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+23,(vlSelfRef.i_data_valid));
    bufp->chgBit(oldp+24,(vlSelfRef.i_load_weight));
    bufp->chgWData(oldp+25,(vlSelfRef.i_data),256);
    bufp->chgQData(oldp+33,(vlSelfRef.i_weight),64);
    bufp->chgBit(oldp+35,(vlSelfRef.o_data_ready));
    bufp->chgIData(oldp+36,(vlSelfRef.o_result),32);
    bufp->chgQData(oldp+37,(vlSelfRef.vec_multi_core__DOT__weight_reg),64);
    bufp->chgBit(oldp+39,(vlSelfRef.vec_multi_core__DOT__product_ready));
    bufp->chgCData(oldp+40,(((((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__4__KET__) 
                               << 4U) | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__3__KET__) 
                                          << 3U) | 
                                         ((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__2__KET__) 
                                          << 2U))) 
                             | (((IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__1__KET__) 
                                 << 1U) | (IData)(vlSelfRef.vec_multi_core__DOT__tree_valid__BRA__0__KET__)))),5);
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
