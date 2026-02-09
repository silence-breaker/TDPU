// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vvec_multi_core.h for the primary calling header

#ifndef VERILATED_VVEC_MULTI_CORE___024ROOT_H_
#define VERILATED_VVEC_MULTI_CORE___024ROOT_H_  // guard

#include "verilated.h"


class Vvec_multi_core__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vvec_multi_core___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(i_data_valid,0,0);
    VL_IN8(i_load_weight,0,0);
    VL_INW(i_data,127,0,4);
    VL_IN(i_weight,31,0);
    VL_OUT8(o_data_ready,0,0);
    IData/*31:0*/ vec_multi_core__DOT__weight_reg;
    CData/*0:0*/ vec_multi_core__DOT__product_ready;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__4__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__3__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__2__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__1__KET__;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    VL_OUT(o_result,31,0);
    VlWide<16>/*511:0*/ vec_multi_core__DOT__product;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 16>, 5> vec_multi_core__DOT__tree_data;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vvec_multi_core__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vvec_multi_core___024root(Vvec_multi_core__Syms* symsp, const char* namep);
    ~Vvec_multi_core___024root();
    VL_UNCOPYABLE(Vvec_multi_core___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
