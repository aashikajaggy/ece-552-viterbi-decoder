// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vviterbi_accelerator.h for the primary calling header

#include "Vviterbi_accelerator__pch.h"

void Vviterbi_accelerator___024root___ctor_var_reset(Vviterbi_accelerator___024root* vlSelf);

void Vviterbi_accelerator___024root__ctor(Vviterbi_accelerator___024root* vlSelf, Vviterbi_accelerator__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vviterbi_accelerator___024root___ctor_var_reset(vlSelf);
}

Vviterbi_accelerator___024root::Vviterbi_accelerator___024root(Vviterbi_accelerator__Syms* symsp, const char* namep) {
    Vviterbi_accelerator___024root__ctor(this, symsp, namep);
}

void Vviterbi_accelerator___024root__dtor(Vviterbi_accelerator___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vviterbi_accelerator___024root::~Vviterbi_accelerator___024root() {
    Vviterbi_accelerator___024root__dtor(this);
}
