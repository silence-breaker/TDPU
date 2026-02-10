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
    VL_INW(i_data,255,0,8);
    VL_IN64(i_weight,63,0);
    VL_OUT8(o_data_ready,0,0);
    QData/*63:0*/ vec_multi_core__DOT__weight_reg;
    CData/*0:0*/ vec_multi_core__DOT__product_ready;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__4__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__3__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__2__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__1__KET__;
    CData/*0:0*/ vec_multi_core__DOT__tree_valid__BRA__0__KET__;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__287__03a279__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__278__03a270__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__269__03a261__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__260__03a252__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__251__03a243__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__242__03a234__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__233__03a225__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__224__03a216__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__215__03a207__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__206__03a198__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__197__03a189__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__188__03a180__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__179__03a171__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__170__03a162__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__161__03a153__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__152__03a144__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__143__03a135__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__134__03a126__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__125__03a117__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__116__03a108__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__107__03a99__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__98__03a90__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__89__03a81__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__80__03a72__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__71__03a63__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__62__03a54__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__53__03a45__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__44__03a36__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__35__03a27__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__26__03a18__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__17__03a9__KET__;
    SData/*8:0*/ vec_multi_core__DOT__product__BRA__8__03a0__KET__;
    VlWide<5>/*159:0*/ vec_multi_core__DOT__gen_tree__BRA__0__KET____DOT__level_data;
    VlWide<3>/*87:0*/ vec_multi_core__DOT__gen_tree__BRA__1__KET____DOT__level_data;
    QData/*47:0*/ vec_multi_core__DOT__gen_tree__BRA__2__KET____DOT__level_data;
    IData/*25:0*/ vec_multi_core__DOT__gen_tree__BRA__3__KET____DOT__level_data;
    SData/*13:0*/ vec_multi_core__DOT__gen_tree__BRA__4__KET____DOT__level_data;
    VL_OUT(o_result,31,0);
    IData/*31:0*/ __VactIterCount;
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
