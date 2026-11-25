// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVITERBI_ACCELERATOR__SYMS_H_
#define VERILATED_VVITERBI_ACCELERATOR__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vviterbi_accelerator.h"

// INCLUDE MODULE CLASSES
#include "Vviterbi_accelerator___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vviterbi_accelerator__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vviterbi_accelerator* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            Vviterbi_accelerator___024root TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    Vviterbi_accelerator__Syms(VerilatedContext* contextp, Vviterbi_accelerator* modelp, const char* namep, bool isRoot);
    ~Vviterbi_accelerator__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
