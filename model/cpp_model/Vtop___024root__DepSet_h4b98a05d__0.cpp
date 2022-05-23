// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSymsp->TOP__top.clk = vlSelf->clk;
}

void Vtop_top___combo__TOP__top__0(Vtop_top* vlSelf);
void Vtop_top___sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_top___sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop_top___multiclk__TOP__top__0(Vtop_top* vlSelf);

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__0(vlSelf);
    Vtop_top___combo__TOP__top__0((&vlSymsp->TOP__top));
    if (((IData)(vlSymsp->TOP__top.clk) & (~ (IData)(vlSelf->__Vclklast__TOP__top__clk)))) {
        Vtop_top___sequent__TOP__top__0((&vlSymsp->TOP__top));
    }
    if (((~ (IData)(vlSymsp->TOP__top.clk)) & (IData)(vlSelf->__Vclklast__TOP__top__clk))) {
        Vtop_top___sequent__TOP__top__1((&vlSymsp->TOP__top));
    }
    if (((IData)(vlSymsp->TOP__top.clk) ^ (IData)(vlSelf->__Vclklast__TOP__top__clk))) {
        Vtop_top___multiclk__TOP__top__0((&vlSymsp->TOP__top));
    }
    // Final
    vlSelf->__Vclklast__TOP__top__clk = vlSymsp->TOP__top.clk;
}
