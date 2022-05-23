// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_top.h"

VL_INLINE_OPT void Vtop_top___combo__TOP__top__0(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___combo__TOP__top__0\n"); );
    // Body
    vlSelf->ram__DOT__clk = vlSelf->clk;
    vlSelf->regfile__DOT__clk = vlSelf->clk;
    vlSelf->fetch__DOT__clk = vlSelf->clk;
    vlSelf->decoder__DOT__clk = vlSelf->clk;
    vlSelf->exec__DOT__clk = vlSelf->clk;
    vlSelf->mem__DOT__clk = vlSelf->clk;
    vlSelf->writeback__DOT__clk = vlSelf->clk;
}

VL_INLINE_OPT void Vtop_top___sequent__TOP__top__0(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___sequent__TOP__top__0\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__ram__DOT__data__v0;
    CData/*4:0*/ __Vdlyvlsb__ram__DOT__data__v0;
    CData/*7:0*/ __Vdlyvval__ram__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__ram__DOT__data__v0;
    IData/*16:0*/ __Vdlyvdim0__ram__DOT__data__v1;
    CData/*4:0*/ __Vdlyvlsb__ram__DOT__data__v1;
    CData/*7:0*/ __Vdlyvval__ram__DOT__data__v1;
    CData/*0:0*/ __Vdlyvset__ram__DOT__data__v1;
    IData/*16:0*/ __Vdlyvdim0__ram__DOT__data__v2;
    CData/*4:0*/ __Vdlyvlsb__ram__DOT__data__v2;
    CData/*7:0*/ __Vdlyvval__ram__DOT__data__v2;
    CData/*0:0*/ __Vdlyvset__ram__DOT__data__v2;
    IData/*16:0*/ __Vdlyvdim0__ram__DOT__data__v3;
    CData/*4:0*/ __Vdlyvlsb__ram__DOT__data__v3;
    CData/*7:0*/ __Vdlyvval__ram__DOT__data__v3;
    CData/*0:0*/ __Vdlyvset__ram__DOT__data__v3;
    CData/*0:0*/ __Vdly__exec__DOT__wait_for_pc;
    CData/*4:0*/ __Vdly__exec__DOT__ex_bp_reg;
    IData/*31:0*/ __Vdly__exec__DOT__ex_bp_val;
    // Body
    __Vdly__exec__DOT__ex_bp_val = vlSelf->exec__DOT__ex_bp_val;
    __Vdly__exec__DOT__ex_bp_reg = vlSelf->exec__DOT__ex_bp_reg;
    __Vdly__exec__DOT__wait_for_pc = vlSelf->exec__DOT__wait_for_pc;
    __Vdlyvset__ram__DOT__data__v0 = 0U;
    __Vdlyvset__ram__DOT__data__v1 = 0U;
    __Vdlyvset__ram__DOT__data__v2 = 0U;
    __Vdlyvset__ram__DOT__data__v3 = 0U;
    vlSelf->mem_ex_bypass_val = 0U;
    vlSelf->mem_ex_bypass_reg = 0U;
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        vlSelf->regfile_r2_reg = vlSelf->decoder__DOT__rs2_wire;
        vlSelf->regfile_r1_reg = vlSelf->decoder__DOT__rs1_wire;
    }
    if (vlSelf->decoder__DOT__ecall_ebreak_encountered) {
        vlSelf->ex_use_imm = 0U;
    }
    vlSelf->mem2wb_insn_type = vlSelf->ex2mem_insn_type;
    if (vlSelf->from_ex_to_decode_stall) {
        vlSelf->exec__DOT__load_hazard = (3U & ((IData)(vlSelf->exec__DOT__load_hazard) 
                                                - (IData)(1U)));
    }
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        if ((((1U != (IData)(vlSelf->insn_type_decode2exec)) 
              & (4U != (IData)(vlSelf->insn_type_decode2exec))) 
             & (vlSelf->pc_ex == vlSelf->exec__DOT__next_valid_pc))) {
            __Vdly__exec__DOT__wait_for_pc = 0U;
            vlSelf->exec__DOT__next_valid_pc = 0U;
        }
    }
    if ((1U & (~ (IData)(vlSelf->from_decode_to_fetch_stall)))) {
        vlSelf->fetch__DOT__pc = ((IData)(vlSelf->ex_pc_valid)
                                   ? (vlSelf->ex_pc_base 
                                      + vlSelf->ex_pc_offset)
                                   : ((IData)(4U) + vlSelf->fetch__DOT__pc));
    }
    vlSelf->wb_reg = vlSelf->rd_ex;
    vlSelf->wb_val = vlSelf->ex2mem_val;
    if (VL_UNLIKELY(vlSelf->ram_w_enable)) {
        VL_WRITEF("STORE: ram[%x]=%10#\n",17,vlSelf->ram__DOT__w_addr,
                  32,vlSelf->ram_w_val);
        vlSelf->ram__DOT__last_w_addr = vlSelf->ram__DOT__w_addr;
        if ((1U & (IData)(vlSelf->ram_w_byte_en))) {
            vlSelf->ram__DOT____Vlvbound_h8f22570d__0 
                = (0xffU & vlSelf->ram_w_val);
            if ((0x10000U >= vlSelf->ram__DOT__w_addr)) {
                __Vdlyvval__ram__DOT__data__v0 = vlSelf->ram__DOT____Vlvbound_h8f22570d__0;
                __Vdlyvset__ram__DOT__data__v0 = 1U;
                __Vdlyvlsb__ram__DOT__data__v0 = 0U;
                __Vdlyvdim0__ram__DOT__data__v0 = vlSelf->ram__DOT__w_addr;
            }
        }
        if ((2U & (IData)(vlSelf->ram_w_byte_en))) {
            vlSelf->ram__DOT____Vlvbound_had4cc1fd__0 
                = (0xffU & (vlSelf->ram_w_val >> 8U));
            if ((0x10000U >= vlSelf->ram__DOT__w_addr)) {
                __Vdlyvval__ram__DOT__data__v1 = vlSelf->ram__DOT____Vlvbound_had4cc1fd__0;
                __Vdlyvset__ram__DOT__data__v1 = 1U;
                __Vdlyvlsb__ram__DOT__data__v1 = 8U;
                __Vdlyvdim0__ram__DOT__data__v1 = vlSelf->ram__DOT__w_addr;
            }
        }
        if ((4U & (IData)(vlSelf->ram_w_byte_en))) {
            vlSelf->ram__DOT____Vlvbound_h8f232cba__0 
                = (0xffU & (vlSelf->ram_w_val >> 0x10U));
            if ((0x10000U >= vlSelf->ram__DOT__w_addr)) {
                __Vdlyvval__ram__DOT__data__v2 = vlSelf->ram__DOT____Vlvbound_h8f232cba__0;
                __Vdlyvset__ram__DOT__data__v2 = 1U;
                __Vdlyvlsb__ram__DOT__data__v2 = 0x10U;
                __Vdlyvdim0__ram__DOT__data__v2 = vlSelf->ram__DOT__w_addr;
            }
        }
        if ((8U & (IData)(vlSelf->ram_w_byte_en))) {
            vlSelf->ram__DOT____Vlvbound_h8f21afc2__0 
                = (vlSelf->ram_w_val >> 0x18U);
            if ((0x10000U >= vlSelf->ram__DOT__w_addr)) {
                __Vdlyvval__ram__DOT__data__v3 = vlSelf->ram__DOT____Vlvbound_h8f21afc2__0;
                __Vdlyvset__ram__DOT__data__v3 = 1U;
                __Vdlyvlsb__ram__DOT__data__v3 = 0x18U;
                __Vdlyvdim0__ram__DOT__data__v3 = vlSelf->ram__DOT__w_addr;
            }
        }
    }
    if (__Vdlyvset__ram__DOT__data__v0) {
        vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__ram__DOT__data__v0))) 
                & vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__ram__DOT__data__v0) 
                                   << (IData)(__Vdlyvlsb__ram__DOT__data__v0))));
    }
    if (__Vdlyvset__ram__DOT__data__v1) {
        vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__ram__DOT__data__v1))) 
                & vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__ram__DOT__data__v1) 
                                   << (IData)(__Vdlyvlsb__ram__DOT__data__v1))));
    }
    if (__Vdlyvset__ram__DOT__data__v2) {
        vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__ram__DOT__data__v2))) 
                & vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__ram__DOT__data__v2) 
                                   << (IData)(__Vdlyvlsb__ram__DOT__data__v2))));
    }
    if (__Vdlyvset__ram__DOT__data__v3) {
        vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__ram__DOT__data__v3))) 
                & vlSelf->ram__DOT__data[__Vdlyvdim0__ram__DOT__data__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__ram__DOT__data__v3) 
                                   << (IData)(__Vdlyvlsb__ram__DOT__data__v3))));
    }
    vlSelf->exec__DOT__bp_mem_val = vlSelf->mem_ex_bypass_val;
    vlSelf->mem__DOT__bp_mem_val = vlSelf->mem_ex_bypass_val;
    vlSelf->exec__DOT__bp_mem_reg = vlSelf->mem_ex_bypass_reg;
    vlSelf->mem__DOT__bp_mem_reg = vlSelf->mem_ex_bypass_reg;
    vlSelf->regfile__DOT__r2_reg_name = vlSelf->regfile_r2_reg;
    vlSelf->decoder__DOT__rs2 = vlSelf->regfile_r2_reg;
    vlSelf->regfile__DOT__r1_reg_name = vlSelf->regfile_r1_reg;
    vlSelf->decoder__DOT__rs1 = vlSelf->regfile_r1_reg;
    vlSelf->mem__DOT__insn_type_r = vlSelf->mem2wb_insn_type;
    vlSelf->writeback__DOT__insn_type = vlSelf->mem2wb_insn_type;
    vlSelf->ram_r2_addr = (vlSelf->fetch__DOT__pc >> 2U);
    if (VL_UNLIKELY((2U == (IData)(vlSelf->ex2mem_insn_type)))) {
        VL_WRITEF("Read RAM: %x\n",30,(0x3fffffffU 
                                       & (vlSelf->ram_r1_addr 
                                          << 2U)));
        vlSelf->use_mem_output = 1U;
        vlSelf->ram_w_enable = 0U;
        vlSelf->ram_r1_addr = (vlSelf->ex2mem_val >> 2U);
    } else if ((3U == (IData)(vlSelf->ex2mem_insn_type))) {
        vlSelf->use_mem_output = 0U;
        vlSelf->ram_w_enable = 1U;
        vlSelf->ram_w_addr = (vlSelf->ex2mem_val >> 2U);
        if ((2U == (IData)(vlSelf->ex2mem_insn_sub_type))) {
            vlSelf->ram_w_byte_en = 0xfU;
            vlSelf->ram_w_val = vlSelf->ex_store_val;
        } else if ((1U == (IData)(vlSelf->ex2mem_insn_sub_type))) {
            if ((0U == (3U & vlSelf->ex2mem_val))) {
                vlSelf->ram_w_byte_en = 3U;
                vlSelf->ram_w_val = vlSelf->ex_store_val;
            } else if (VL_LIKELY((2U == (3U & vlSelf->ex2mem_val)))) {
                vlSelf->ram_w_byte_en = 0xcU;
                vlSelf->ram_w_val = (vlSelf->ex_store_val 
                                     << 0x10U);
            } else {
                VL_WRITEF("bad ma\n");
                VL_FINISH_MT("modules/mem/mem.v", 63, "");
            }
        } else if (VL_LIKELY((0U == (IData)(vlSelf->ex2mem_insn_sub_type)))) {
            if ((2U & vlSelf->ex2mem_val)) {
                if ((1U & vlSelf->ex2mem_val)) {
                    vlSelf->ram_w_byte_en = 8U;
                    vlSelf->ram_w_val = (vlSelf->ex_store_val 
                                         << 0x18U);
                } else {
                    vlSelf->ram_w_byte_en = 4U;
                    vlSelf->ram_w_val = (vlSelf->ex_store_val 
                                         << 0x10U);
                }
            } else if ((1U & vlSelf->ex2mem_val)) {
                vlSelf->ram_w_byte_en = 2U;
                vlSelf->ram_w_val = (vlSelf->ex_store_val 
                                     << 8U);
            } else {
                vlSelf->ram_w_byte_en = 1U;
                vlSelf->ram_w_val = vlSelf->ex_store_val;
            }
        } else {
            VL_WRITEF("Unreachable!\n");
            VL_FINISH_MT("modules/mem/mem.v", 93, "");
        }
    } else {
        vlSelf->use_mem_output = 0U;
        vlSelf->wb_val = vlSelf->ex2mem_val;
        vlSelf->wb_reg = vlSelf->rd_ex;
        vlSelf->ram_w_enable = 0U;
    }
    vlSelf->ram__DOT__r2_addr_e = vlSelf->ram_r2_addr;
    vlSelf->fetch__DOT__mem_addr = vlSelf->ram_r2_addr;
    vlSelf->ram__DOT__r2_addr = (0x1ffffU & vlSelf->ram_r2_addr);
    vlSelf->ram_r2_val = ((0x10000U >= vlSelf->ram__DOT__r2_addr)
                           ? vlSelf->ram__DOT__data
                          [vlSelf->ram__DOT__r2_addr]
                           : 0U);
    vlSelf->mem__DOT__use_mem_output = vlSelf->use_mem_output;
    vlSelf->ram__DOT__w_enable = vlSelf->ram_w_enable;
    vlSelf->mem__DOT__ram_w_en = vlSelf->ram_w_enable;
    vlSelf->ram__DOT__byte_en = vlSelf->ram_w_byte_en;
    vlSelf->mem__DOT__ram_byte_en = vlSelf->ram_w_byte_en;
    vlSelf->ram__DOT__w_val = vlSelf->ram_w_val;
    vlSelf->mem__DOT__ram_w_data = vlSelf->ram_w_val;
    vlSelf->ram__DOT__w_addr_e = vlSelf->ram_w_addr;
    vlSelf->ram__DOT__w_addr = (0x1ffffU & vlSelf->ram_w_addr);
    vlSelf->mem__DOT__ram_w_addr = vlSelf->ram_w_addr;
    vlSelf->mem__DOT__wb_reg_r = vlSelf->wb_reg;
    vlSelf->writeback__DOT__rd = vlSelf->wb_reg;
    vlSelf->wb_ex_bypass_reg = vlSelf->wb_reg;
    vlSelf->regfile_w_reg = vlSelf->wb_reg;
    vlSelf->mem__DOT__wb_val = vlSelf->wb_val;
    vlSelf->writeback__DOT__ex_val = vlSelf->wb_val;
    vlSelf->ram__DOT__r1_addr_e = vlSelf->ram_r1_addr;
    vlSelf->mem__DOT__ram_r_addr = vlSelf->ram_r1_addr;
    vlSelf->ram__DOT__r1_addr = (0x1ffffU & vlSelf->ram_r1_addr);
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        vlSelf->ex2mem_insn_sub_type = vlSelf->insn_sub_type_decode2exec;
        vlSelf->ex2mem_insn_type = vlSelf->insn_type_decode2exec;
    }
    VL_WRITEF("EXEC PC: 0x%x\n",32,vlSelf->pc_ex);
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        if (vlSelf->exec__DOT__wait_for_pc) {
            vlSelf->ex_pc_valid = 0U;
        }
        if ((1U & ((~ (IData)(vlSelf->exec__DOT__wait_for_pc)) 
                   | ((IData)(vlSelf->exec__DOT__awaited_pc_valid) 
                      & (~ (IData)(vlSelf->from_ex_to_decode_stall)))))) {
            if (VL_UNLIKELY((8U & (IData)(vlSelf->insn_type_decode2exec)))) {
                VL_WRITEF("Unreachable!\n");
                VL_FINISH_MT("modules/exec/exec.v", 256, "");
            } else if ((4U & (IData)(vlSelf->insn_type_decode2exec))) {
                if (VL_UNLIKELY((2U & (IData)(vlSelf->insn_type_decode2exec)))) {
                    VL_WRITEF("Unreachable!\n");
                    VL_FINISH_MT("modules/exec/exec.v", 256, "");
                } else if (VL_UNLIKELY((1U & (IData)(vlSelf->insn_type_decode2exec)))) {
                    VL_WRITEF("Unreachable!\n");
                    VL_FINISH_MT("modules/exec/exec.v", 256, "");
                } else {
                    vlSelf->exec__DOT__load_hazard = 0U;
                    vlSelf->ex_pc_valid = 1U;
                    vlSelf->ex_pc_base = vlSelf->exec__DOT__alu_rs1;
                    vlSelf->ex_pc_offset = vlSelf->imm;
                    vlSelf->ex2mem_val = ((IData)(4U) 
                                          + vlSelf->pc_ex);
                    __Vdly__exec__DOT__ex_bp_reg = vlSelf->rd;
                    __Vdly__exec__DOT__ex_bp_val = 
                        ((0U == (IData)(vlSelf->rd))
                          ? 0U : ((IData)(4U) + vlSelf->pc_ex));
                    vlSelf->exec__DOT__next_valid_pc 
                        = vlSelf->exec__DOT__w_alu_res;
                    __Vdly__exec__DOT__wait_for_pc = 1U;
                }
            } else if ((2U & (IData)(vlSelf->insn_type_decode2exec))) {
                if ((1U & (IData)(vlSelf->insn_type_decode2exec))) {
                    vlSelf->exec__DOT__load_hazard = 0U;
                    vlSelf->ex_pc_valid = 0U;
                    vlSelf->ex2mem_val = vlSelf->exec__DOT__w_alu_res;
                    __Vdly__exec__DOT__ex_bp_reg = 0U;
                    __Vdly__exec__DOT__ex_bp_val = 0U;
                    vlSelf->ex_store_val = vlSelf->exec__DOT__rs2_actual;
                } else {
                    vlSelf->exec__DOT__load_hazard = 2U;
                    vlSelf->ex_pc_valid = 0U;
                    vlSelf->ex2mem_val = vlSelf->exec__DOT__w_alu_res;
                    __Vdly__exec__DOT__ex_bp_reg = 0U;
                    __Vdly__exec__DOT__ex_bp_val = 0U;
                }
            } else if ((1U & (IData)(vlSelf->insn_type_decode2exec))) {
                vlSelf->exec__DOT__load_hazard = 0U;
                if (VL_UNLIKELY((8U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                    VL_WRITEF("Unreachable!\n");
                    VL_FINISH_MT("modules/exec/exec.v", 239, "");
                } else if ((4U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                    if (VL_UNLIKELY((2U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                        VL_WRITEF("Unreachable!\n");
                        VL_FINISH_MT("modules/exec/exec.v", 239, "");
                    } else if (VL_UNLIKELY((1U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                        VL_WRITEF("Unreachable!\n");
                        VL_FINISH_MT("modules/exec/exec.v", 239, "");
                    } else {
                        vlSelf->ex_pc_offset = vlSelf->imm;
                        vlSelf->ex_pc_base = vlSelf->pc_ex;
                        vlSelf->ex_pc_valid = 1U;
                        vlSelf->ex2mem_val = ((IData)(4U) 
                                              + vlSelf->pc_ex);
                        __Vdly__exec__DOT__ex_bp_reg 
                            = vlSelf->rd;
                        __Vdly__exec__DOT__ex_bp_val 
                            = ((0U == (IData)(vlSelf->rd))
                                ? 0U : ((IData)(4U) 
                                        + vlSelf->pc_ex));
                        vlSelf->exec__DOT__next_valid_pc 
                            = (vlSelf->pc_ex + vlSelf->imm);
                        __Vdly__exec__DOT__wait_for_pc = 1U;
                    }
                } else if ((2U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                        if (VL_LIKELY(vlSelf->exec__DOT__cmp_less)) {
                            vlSelf->ex_pc_valid = 0U;
                            __Vdly__exec__DOT__wait_for_pc = 0U;
                        } else {
                            VL_WRITEF("rs1_reg %2# rs2_reg %2#\nex_bp_reg %2#\n",
                                      5,vlSelf->rs1_reg,
                                      5,(IData)(vlSelf->rs2_reg),
                                      5,vlSelf->exec__DOT__ex_bp_reg);
                            vlSelf->ex_pc_offset = vlSelf->imm;
                            vlSelf->ex_pc_base = vlSelf->pc_ex;
                            vlSelf->ex_pc_valid = 1U;
                            vlSelf->exec__DOT__next_valid_pc 
                                = (vlSelf->pc_ex + vlSelf->imm);
                            __Vdly__exec__DOT__wait_for_pc = 1U;
                            VL_WRITEF("ex_bp_val %10#\nalu_rs1 %10# alu_rs2 %10#\n",
                                      32,vlSelf->exec__DOT__ex_bp_val,
                                      32,vlSelf->exec__DOT__alu_rs1,
                                      32,vlSelf->exec__DOT__alu_rs2);
                        }
                        __Vdly__exec__DOT__ex_bp_reg = 0U;
                        __Vdly__exec__DOT__ex_bp_val = 0U;
                    } else {
                        VL_WRITEF("BLT!BLT!BLT!BLT!BLT!BLT!BLT!\nTAKEN?: %1#\n",
                                  1,vlSelf->exec__DOT__cmp_less);
                        __Vdly__exec__DOT__ex_bp_reg = 0U;
                        __Vdly__exec__DOT__ex_bp_val = 0U;
                        if (VL_UNLIKELY(vlSelf->exec__DOT__cmp_less)) {
                            VL_WRITEF("NEXT VALID PC 0x%x\n",
                                      32,(vlSelf->pc_ex 
                                          + vlSelf->imm));
                            vlSelf->ex_pc_offset = vlSelf->imm;
                            vlSelf->ex_pc_base = vlSelf->pc_ex;
                            vlSelf->ex_pc_valid = 1U;
                            vlSelf->exec__DOT__next_valid_pc 
                                = (vlSelf->pc_ex + vlSelf->imm);
                            __Vdly__exec__DOT__wait_for_pc = 1U;
                        } else {
                            vlSelf->ex_pc_valid = 0U;
                            __Vdly__exec__DOT__wait_for_pc = 0U;
                        }
                    }
                } else if ((1U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                    __Vdly__exec__DOT__ex_bp_reg = 0U;
                    __Vdly__exec__DOT__ex_bp_val = 0U;
                    if (vlSelf->exec__DOT__cmp_eq) {
                        vlSelf->ex_pc_valid = 0U;
                        __Vdly__exec__DOT__wait_for_pc = 0U;
                    } else {
                        vlSelf->ex_pc_offset = vlSelf->imm;
                        vlSelf->ex_pc_base = vlSelf->pc_ex;
                        vlSelf->ex_pc_valid = 1U;
                        vlSelf->exec__DOT__next_valid_pc 
                            = (vlSelf->pc_ex + vlSelf->imm);
                        __Vdly__exec__DOT__wait_for_pc = 1U;
                    }
                } else {
                    __Vdly__exec__DOT__ex_bp_reg = 0U;
                    __Vdly__exec__DOT__ex_bp_val = 0U;
                    if (vlSelf->exec__DOT__cmp_eq) {
                        VL_WRITEF("BEQ taken\n");
                        vlSelf->ex_pc_offset = vlSelf->imm;
                        vlSelf->ex_pc_base = vlSelf->pc_ex;
                        vlSelf->ex_pc_valid = 1U;
                        vlSelf->exec__DOT__next_valid_pc 
                            = (vlSelf->pc_ex + vlSelf->imm);
                        __Vdly__exec__DOT__wait_for_pc = 1U;
                    } else {
                        VL_WRITEF("BEQ not taken\n");
                        vlSelf->ex_pc_valid = 0U;
                        __Vdly__exec__DOT__wait_for_pc = 0U;
                    }
                }
            } else {
                vlSelf->exec__DOT__load_hazard = 0U;
                vlSelf->ex_pc_valid = 0U;
                if (VL_UNLIKELY((8U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                    VL_WRITEF("Unreachable!\n");
                    VL_FINISH_MT("modules/exec/exec.v", 136, "");
                } else if (VL_UNLIKELY((4U & (IData)(vlSelf->insn_sub_type_decode2exec)))) {
                    VL_WRITEF("Unreachable!\n");
                    VL_FINISH_MT("modules/exec/exec.v", 136, "");
                } else if ((2U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                    if ((1U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                        vlSelf->ex2mem_val = vlSelf->exec__DOT__w_alu_res;
                        __Vdly__exec__DOT__ex_bp_val 
                            = ((0U == (IData)(vlSelf->rd))
                                ? 0U : vlSelf->pc_ex);
                        __Vdly__exec__DOT__ex_bp_reg 
                            = vlSelf->rd;
                    } else {
                        vlSelf->ex2mem_val = vlSelf->exec__DOT__w_alu_res;
                        __Vdly__exec__DOT__ex_bp_val 
                            = ((0U == (IData)(vlSelf->rd))
                                ? 0U : vlSelf->exec__DOT__w_alu_res);
                        __Vdly__exec__DOT__ex_bp_reg 
                            = vlSelf->rd;
                    }
                } else if ((1U & (IData)(vlSelf->insn_sub_type_decode2exec))) {
                    __Vdly__exec__DOT__ex_bp_reg = vlSelf->rd;
                    if (vlSelf->exec__DOT__cmp_less) {
                        __Vdly__exec__DOT__ex_bp_val 
                            = ((0U == (IData)(vlSelf->rd))
                                ? 0U : vlSelf->exec__DOT__alu_rs2);
                        vlSelf->ex2mem_val = vlSelf->exec__DOT__alu_rs2;
                    } else {
                        __Vdly__exec__DOT__ex_bp_val = 0U;
                        vlSelf->ex2mem_val = 0U;
                    }
                } else {
                    vlSelf->ex2mem_val = vlSelf->imm;
                    __Vdly__exec__DOT__ex_bp_val = 
                        ((0U == (IData)(vlSelf->rd))
                          ? 0U : vlSelf->imm);
                    __Vdly__exec__DOT__ex_bp_reg = vlSelf->rd;
                }
            }
            vlSelf->rd_ex = vlSelf->rd;
        }
    }
    vlSelf->ram__DOT__r2_val = vlSelf->ram_r2_val;
    vlSelf->fetch__DOT__mem_data = vlSelf->ram_r2_val;
    vlSelf->insn = vlSelf->ram_r2_val;
    vlSelf->exec__DOT__bp_wb_reg = vlSelf->wb_ex_bypass_reg;
    vlSelf->writeback__DOT__wb_bp_reg = vlSelf->wb_ex_bypass_reg;
    vlSelf->regfile__DOT__w_reg_name = vlSelf->regfile_w_reg;
    vlSelf->writeback__DOT__regfile_w_reg = vlSelf->regfile_w_reg;
    vlSelf->ram_r1_val = ((0x10000U >= vlSelf->ram__DOT__r1_addr)
                           ? vlSelf->ram__DOT__data
                          [vlSelf->ram__DOT__r1_addr]
                           : 0U);
    vlSelf->exec__DOT__wait_for_pc = __Vdly__exec__DOT__wait_for_pc;
    vlSelf->exec__DOT__ex_bp_reg = __Vdly__exec__DOT__ex_bp_reg;
    vlSelf->exec__DOT__ex_bp_val = __Vdly__exec__DOT__ex_bp_val;
    vlSelf->fetch__DOT__insn = vlSelf->insn;
    vlSelf->decoder__DOT__insn = vlSelf->insn;
    vlSelf->ram__DOT__r1_val = vlSelf->ram_r1_val;
    vlSelf->writeback__DOT__mem_r_data = vlSelf->ram_r1_val;
    if ((2U == (IData)(vlSelf->mem2wb_insn_type))) {
        vlSelf->wb_ex_bypass_val = vlSelf->ram_r1_val;
        vlSelf->regfile_w_val = vlSelf->ram_r1_val;
    } else {
        vlSelf->wb_ex_bypass_val = vlSelf->wb_val;
        vlSelf->regfile_w_val = vlSelf->wb_val;
    }
    vlSelf->exec__DOT__insn_sub_type_r = vlSelf->ex2mem_insn_sub_type;
    vlSelf->mem__DOT__insn_sub_type = vlSelf->ex2mem_insn_sub_type;
    vlSelf->exec__DOT__insn_type_r = vlSelf->ex2mem_insn_type;
    vlSelf->mem__DOT__insn_type = vlSelf->ex2mem_insn_type;
    vlSelf->fetch__DOT__pc_ex_valid = vlSelf->ex_pc_valid;
    vlSelf->exec__DOT__pc_redirect_valid = vlSelf->ex_pc_valid;
    vlSelf->fetch__DOT__pc_ex_base = vlSelf->ex_pc_base;
    vlSelf->exec__DOT__pc_base = vlSelf->ex_pc_base;
    vlSelf->fetch__DOT__pc_ex_off = vlSelf->ex_pc_offset;
    vlSelf->exec__DOT__pc_offset = vlSelf->ex_pc_offset;
    vlSelf->exec__DOT__next_stage_val = vlSelf->ex2mem_val;
    vlSelf->mem__DOT__ex_val = vlSelf->ex2mem_val;
    vlSelf->exec__DOT__store_val = vlSelf->ex_store_val;
    vlSelf->mem__DOT__store_val = vlSelf->ex_store_val;
    vlSelf->exec__DOT__rd_ex = vlSelf->rd_ex;
    vlSelf->mem__DOT__wb_reg = vlSelf->rd_ex;
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        vlSelf->pc_ex = vlSelf->pc_de;
    }
    if (vlSelf->decoder__DOT__ecall_ebreak_encountered) {
        vlSelf->rd = 0U;
        vlSelf->insn_sub_type_decode2exec = 2U;
        vlSelf->insn_type_decode2exec = 0U;
        vlSelf->rs2_reg = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        vlSelf->rs2_reg = vlSelf->decoder__DOT__rs2_wire;
    }
    if (vlSelf->decoder__DOT__ecall_ebreak_encountered) {
        vlSelf->rs1_reg = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
        vlSelf->rs1_reg = vlSelf->decoder__DOT__rs1_wire;
    }
    if ((1U & (~ (IData)(vlSelf->decoder__DOT__ecall_ebreak_encountered)))) {
        if ((1U & (~ (IData)(vlSelf->from_ex_to_decode_stall)))) {
            if ((0x40U & (IData)(vlSelf->decoder__DOT__opcode))) {
                if (VL_LIKELY((0x20U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    if ((0x10U & (IData)(vlSelf->decoder__DOT__opcode))) {
                        if (VL_UNLIKELY((8U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            VL_WRITEF("Incorrect insn\n");
                        } else if (VL_UNLIKELY((4U 
                                                & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            VL_WRITEF("Incorrect insn\n");
                        } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                                if (VL_UNLIKELY((0U 
                                                 == vlSelf->decoder__DOT__ecall_ebreak_field))) {
                                    VL_WRITEF("%x ecall\n",
                                              32,vlSelf->pc_de);
                                    vlSelf->decoder__DOT__ecall_ebreak_encountered = 1U;
                                    vlSelf->ex_use_imm = 0U;
                                    vlSelf->insn_type_decode2exec = 0U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                    vlSelf->rs1_reg = 0U;
                                    vlSelf->rs2_reg = 0U;
                                    vlSelf->rd = 0U;
                                } else if (VL_UNLIKELY(
                                                       (0x2000U 
                                                        == vlSelf->decoder__DOT__ecall_ebreak_field))) {
                                    VL_WRITEF("%x ebreak\n",
                                              32,vlSelf->pc_de);
                                    vlSelf->decoder__DOT__ecall_ebreak_encountered = 1U;
                                    vlSelf->ex_use_imm = 0U;
                                    vlSelf->insn_type_decode2exec = 0U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                    vlSelf->rs1_reg = 0U;
                                    vlSelf->rs2_reg = 0U;
                                    vlSelf->rd = 0U;
                                } else if ((4U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                        if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                            VL_WRITEF("%x csrrci\n",
                                                      32,
                                                      vlSelf->pc_de);
                                        } else {
                                            VL_WRITEF("%x csrrsi\n",
                                                      32,
                                                      vlSelf->pc_de);
                                        }
                                    } else if (VL_LIKELY(
                                                         (1U 
                                                          & (IData)(vlSelf->decoder__DOT__funct3)))) {
                                        VL_WRITEF("%x csrrwi\n",
                                                  32,
                                                  vlSelf->pc_de);
                                    } else {
                                        VL_WRITEF("Unreachable!\n");
                                        VL_FINISH_MT("modules/decoder/decoder.v", 472, "");
                                    }
                                } else if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                        VL_WRITEF("%x csrrc\n",
                                                  32,
                                                  vlSelf->pc_de);
                                    } else {
                                        VL_WRITEF("%x csrrs\n",
                                                  32,
                                                  vlSelf->pc_de);
                                    }
                                } else if (VL_LIKELY(
                                                     (1U 
                                                      & (IData)(vlSelf->decoder__DOT__funct3)))) {
                                    VL_WRITEF("%x csrrw\n",
                                              32,vlSelf->pc_de);
                                } else {
                                    VL_WRITEF("Unreachable!\n");
                                    VL_FINISH_MT("modules/decoder/decoder.v", 472, "");
                                }
                            } else {
                                VL_WRITEF("Incorrect insn\n");
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else if ((8U & (IData)(vlSelf->decoder__DOT__opcode))) {
                        if (VL_LIKELY((4U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                                if ((1U & (IData)(vlSelf->decoder__DOT__opcode))) {
                                    VL_WRITEF("%x jal %2#, %x\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              32,vlSelf->decoder__DOT__j_imm);
                                    vlSelf->imm = vlSelf->decoder__DOT__j_imm;
                                    vlSelf->ex_use_imm = 0U;
                                    vlSelf->insn_type_decode2exec = 1U;
                                    vlSelf->insn_sub_type_decode2exec = 4U;
                                    vlSelf->alu_code = 0U;
                                    vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                                } else {
                                    VL_WRITEF("Incorrect insn\n");
                                }
                            } else {
                                VL_WRITEF("Incorrect insn\n");
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else if ((4U & (IData)(vlSelf->decoder__DOT__opcode))) {
                        if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            if ((1U & (IData)(vlSelf->decoder__DOT__opcode))) {
                                VL_WRITEF("%x jalr %2# %x(%2#)\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          32,vlSelf->decoder__DOT__i_imm,
                                          5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                                vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                vlSelf->ex_use_imm = 0U;
                                vlSelf->insn_type_decode2exec = 4U;
                                vlSelf->insn_sub_type_decode2exec = 0U;
                                vlSelf->alu_code = 1U;
                                vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                            } else {
                                VL_WRITEF("Incorrect insn\n");
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            vlSelf->insn_type_decode2exec = 1U;
                            vlSelf->rd = 0U;
                            vlSelf->imm = vlSelf->decoder__DOT__b_imm;
                            vlSelf->ex_use_imm = 0U;
                            if ((4U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                        VL_WRITEF("%x bgeu %2# %2# %11d (0x%x)\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs1_wire),
                                                  5,
                                                  vlSelf->decoder__DOT__rs2_wire,
                                                  32,
                                                  vlSelf->decoder__DOT__b_imm,
                                                  32,
                                                  vlSelf->decoder__DOT__b_imm);
                                        vlSelf->alu_code = 7U;
                                        vlSelf->insn_sub_type_decode2exec = 3U;
                                    } else {
                                        VL_WRITEF("%x bltu %2# %2# %11d (0x%x)\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs1_wire),
                                                  5,
                                                  vlSelf->decoder__DOT__rs2_wire,
                                                  32,
                                                  vlSelf->decoder__DOT__b_imm,
                                                  32,
                                                  vlSelf->decoder__DOT__b_imm);
                                        vlSelf->alu_code = 7U;
                                        vlSelf->insn_sub_type_decode2exec = 2U;
                                    }
                                } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    VL_WRITEF("%x bge %2# %2# %11d (0x%x)\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__rs1_wire),
                                              5,vlSelf->decoder__DOT__rs2_wire,
                                              32,vlSelf->decoder__DOT__b_imm,
                                              32,vlSelf->decoder__DOT__b_imm);
                                    vlSelf->alu_code = 6U;
                                    vlSelf->insn_sub_type_decode2exec = 3U;
                                } else {
                                    VL_WRITEF("%x blt %2# %2# %11d (0x%x)\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__rs1_wire),
                                              5,vlSelf->decoder__DOT__rs2_wire,
                                              32,vlSelf->decoder__DOT__b_imm,
                                              32,vlSelf->decoder__DOT__b_imm);
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                    vlSelf->alu_code = 6U;
                                }
                            } else if (VL_UNLIKELY(
                                                   (2U 
                                                    & (IData)(vlSelf->decoder__DOT__funct3)))) {
                                VL_WRITEF("Unreachable!\n");
                                VL_FINISH_MT("modules/decoder/decoder.v", 172, "");
                            } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                VL_WRITEF("%x bne %2# %2# %11d (0x%x)\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__rs1_wire),
                                          5,vlSelf->decoder__DOT__rs2_wire,
                                          32,vlSelf->decoder__DOT__b_imm,
                                          32,vlSelf->decoder__DOT__b_imm);
                                vlSelf->insn_sub_type_decode2exec = 1U;
                                vlSelf->alu_code = 6U;
                            } else {
                                VL_WRITEF("%x beq %2# %2# %11d (0x%x)\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__rs1_wire),
                                          5,vlSelf->decoder__DOT__rs2_wire,
                                          32,vlSelf->decoder__DOT__b_imm,
                                          32,vlSelf->decoder__DOT__b_imm);
                                vlSelf->insn_sub_type_decode2exec = 0U;
                                vlSelf->alu_code = 6U;
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else {
                    VL_WRITEF("Incorrect insn\n");
                }
            } else if ((0x20U & (IData)(vlSelf->decoder__DOT__opcode))) {
                if ((0x10U & (IData)(vlSelf->decoder__DOT__opcode))) {
                    if (VL_UNLIKELY((8U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        VL_WRITEF("Incorrect insn\n");
                    } else if ((4U & (IData)(vlSelf->decoder__DOT__opcode))) {
                        if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            if ((1U & (IData)(vlSelf->decoder__DOT__opcode))) {
                                VL_WRITEF("%x lui %2# %x\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          32,vlSelf->decoder__DOT__u_imm);
                                vlSelf->imm = vlSelf->decoder__DOT__u_imm;
                                vlSelf->ex_use_imm = 1U;
                                vlSelf->insn_type_decode2exec = 0U;
                                vlSelf->insn_sub_type_decode2exec = 0U;
                                vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                            } else {
                                VL_WRITEF("Incorrect insn\n");
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            vlSelf->ex_use_imm = 0U;
                            vlSelf->insn_type_decode2exec = 0U;
                            vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                            if ((4U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                        if (VL_UNLIKELY(
                                                        (0U 
                                                         == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                            VL_WRITEF("%x and %2# %2# %2#\n",
                                                      32,
                                                      vlSelf->pc_de,
                                                      5,
                                                      (IData)(vlSelf->decoder__DOT__w_rd),
                                                      5,
                                                      vlSelf->decoder__DOT__rs1_wire,
                                                      5,
                                                      (IData)(vlSelf->decoder__DOT__rs2_wire));
                                            vlSelf->alu_code = 9U;
                                            vlSelf->insn_sub_type_decode2exec = 2U;
                                        }
                                    } else if (VL_UNLIKELY(
                                                           (0U 
                                                            == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                        VL_WRITEF("%x or %2# %2# %2#\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__w_rd),
                                                  5,
                                                  vlSelf->decoder__DOT__rs1_wire,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs2_wire));
                                        vlSelf->alu_code = 8U;
                                        vlSelf->insn_sub_type_decode2exec = 2U;
                                    }
                                } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if (VL_UNLIKELY(
                                                    (0U 
                                                     == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                        VL_WRITEF("%x srl %2# %2# %2#\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__w_rd),
                                                  5,
                                                  vlSelf->decoder__DOT__rs1_wire,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs2_wire));
                                        vlSelf->alu_code = 5U;
                                        vlSelf->insn_sub_type_decode2exec = 2U;
                                    } else if (VL_LIKELY(
                                                         (0x20U 
                                                          == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                        VL_WRITEF("%x sra %2# %2# %2#\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__w_rd),
                                                  5,
                                                  vlSelf->decoder__DOT__rs1_wire,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs2_wire));
                                        vlSelf->alu_code = 4U;
                                        vlSelf->insn_sub_type_decode2exec = 2U;
                                    } else {
                                        VL_WRITEF("Unreachable!\n");
                                        VL_FINISH_MT("modules/decoder/decoder.v", 384, "");
                                    }
                                } else if (VL_UNLIKELY(
                                                       (0U 
                                                        == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x xor %2# %2# %2#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              5,(IData)(vlSelf->decoder__DOT__rs2_wire));
                                    vlSelf->alu_code = 0xaU;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                }
                            } else if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    if (VL_UNLIKELY(
                                                    (0U 
                                                     == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                        VL_WRITEF("%x sltu %2# %2# %2#\n",
                                                  32,
                                                  vlSelf->pc_de,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__w_rd),
                                                  5,
                                                  vlSelf->decoder__DOT__rs1_wire,
                                                  5,
                                                  (IData)(vlSelf->decoder__DOT__rs2_wire));
                                        vlSelf->alu_code = 7U;
                                        vlSelf->insn_sub_type_decode2exec = 1U;
                                    }
                                } else if (VL_UNLIKELY(
                                                       (0U 
                                                        == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x slt %2# %2# %2#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              5,(IData)(vlSelf->decoder__DOT__rs2_wire));
                                    vlSelf->alu_code = 6U;
                                    vlSelf->insn_sub_type_decode2exec = 1U;
                                }
                            } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                if (VL_UNLIKELY((0U 
                                                 == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x sll %2# %2# %2#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              5,(IData)(vlSelf->decoder__DOT__rs2_wire));
                                    vlSelf->alu_code = 3U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                }
                            } else {
                                vlSelf->insn_sub_type_decode2exec = 2U;
                                if (VL_UNLIKELY((0U 
                                                 == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x add %2# %2# %2#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              5,(IData)(vlSelf->decoder__DOT__rs2_wire));
                                    vlSelf->alu_code = 1U;
                                } else if (VL_LIKELY(
                                                     (0x20U 
                                                      == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x sub %2# %2# %2#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              5,(IData)(vlSelf->decoder__DOT__rs2_wire));
                                    vlSelf->alu_code = 2U;
                                } else {
                                    VL_WRITEF("Unreachable!\n");
                                    VL_FINISH_MT("modules/decoder/decoder.v", 338, "");
                                }
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else if (VL_UNLIKELY((8U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    VL_WRITEF("Incorrect insn\n");
                } else if (VL_UNLIKELY((4U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    VL_WRITEF("Incorrect insn\n");
                } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        vlSelf->insn_type_decode2exec = 3U;
                        vlSelf->rd = 0U;
                        vlSelf->imm = vlSelf->decoder__DOT__s_imm;
                        vlSelf->ex_use_imm = 1U;
                        vlSelf->alu_code = 1U;
                        if (VL_UNLIKELY((0U == (IData)(vlSelf->decoder__DOT__funct3)))) {
                            VL_WRITEF("%x sb %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__rs2_wire),
                                      32,vlSelf->decoder__DOT__s_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 0U;
                        } else if (VL_UNLIKELY((1U 
                                                == (IData)(vlSelf->decoder__DOT__funct3)))) {
                            VL_WRITEF("%x sh %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__rs2_wire),
                                      32,vlSelf->decoder__DOT__s_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 1U;
                        } else if (VL_LIKELY((2U == (IData)(vlSelf->decoder__DOT__funct3)))) {
                            VL_WRITEF("%x sw %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__rs2_wire),
                                      32,vlSelf->decoder__DOT__s_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 2U;
                        } else {
                            VL_WRITEF("Unreachable!\n");
                            VL_FINISH_MT("modules/decoder/decoder.v", 236, "");
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else {
                    VL_WRITEF("Incorrect insn\n");
                }
            } else if ((0x10U & (IData)(vlSelf->decoder__DOT__opcode))) {
                if (VL_UNLIKELY((8U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    VL_WRITEF("Incorrect insn\n");
                } else if ((4U & (IData)(vlSelf->decoder__DOT__opcode))) {
                    if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        if ((1U & (IData)(vlSelf->decoder__DOT__opcode))) {
                            VL_WRITEF("%x auipc %2# %x + %x\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__w_rd),
                                      32,vlSelf->decoder__DOT__u_imm,
                                      32,vlSelf->pc_de);
                            vlSelf->imm = vlSelf->decoder__DOT__u_imm;
                            vlSelf->ex_use_imm = 1U;
                            vlSelf->insn_type_decode2exec = 0U;
                            vlSelf->insn_sub_type_decode2exec = 3U;
                            vlSelf->alu_code = 1U;
                            vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        vlSelf->ex_use_imm = 1U;
                        vlSelf->insn_type_decode2exec = 0U;
                        vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                        if ((4U & (IData)(vlSelf->decoder__DOT__funct3))) {
                            if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                    VL_WRITEF("%x andi %2# %2# %x\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              32,vlSelf->decoder__DOT__i_imm);
                                    vlSelf->alu_code = 9U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                    vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                } else {
                                    VL_WRITEF("%x ori %2# %2# %x\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              32,vlSelf->decoder__DOT__i_imm);
                                    vlSelf->alu_code = 8U;
                                    vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                }
                            } else if (VL_LIKELY((1U 
                                                  & (IData)(vlSelf->decoder__DOT__funct3)))) {
                                vlSelf->imm = vlSelf->decoder__DOT__shamt;
                                if (VL_UNLIKELY((0U 
                                                 == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x srli%2#%2#%10#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              32,vlSelf->decoder__DOT__shamt);
                                    vlSelf->alu_code = 5U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                } else if (VL_LIKELY(
                                                     (0x20U 
                                                      == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                    VL_WRITEF("%x srai%2#%2#%10#\n",
                                              32,vlSelf->pc_de,
                                              5,(IData)(vlSelf->decoder__DOT__w_rd),
                                              5,vlSelf->decoder__DOT__rs1_wire,
                                              32,vlSelf->decoder__DOT__shamt);
                                    vlSelf->alu_code = 4U;
                                    vlSelf->insn_sub_type_decode2exec = 2U;
                                } else {
                                    VL_WRITEF("Unreachable!\n");
                                    VL_FINISH_MT("modules/decoder/decoder.v", 307, "");
                                }
                            } else {
                                VL_WRITEF("%x xori %2# %2# %x\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          5,vlSelf->decoder__DOT__rs1_wire,
                                          32,vlSelf->decoder__DOT__i_imm);
                                vlSelf->alu_code = 0xaU;
                                vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                vlSelf->insn_sub_type_decode2exec = 2U;
                            }
                        } else if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                            if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                                VL_WRITEF("%x sltiu %2# %2# %x\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          5,vlSelf->decoder__DOT__rs1_wire,
                                          32,vlSelf->decoder__DOT__i_imm);
                                vlSelf->alu_code = 7U;
                                vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                vlSelf->insn_sub_type_decode2exec = 1U;
                            } else {
                                VL_WRITEF("%x slti %2# %2# %x\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          5,vlSelf->decoder__DOT__rs1_wire,
                                          32,vlSelf->decoder__DOT__i_imm);
                                vlSelf->alu_code = 6U;
                                vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                                vlSelf->insn_sub_type_decode2exec = 1U;
                            }
                        } else if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__funct3)))) {
                            if (VL_UNLIKELY((0U == (IData)(vlSelf->decoder__DOT__funct7)))) {
                                VL_WRITEF("%x slli %2# %2# %x\n",
                                          32,vlSelf->pc_de,
                                          5,(IData)(vlSelf->decoder__DOT__w_rd),
                                          5,vlSelf->decoder__DOT__rs1_wire,
                                          32,vlSelf->decoder__DOT__i_imm);
                                vlSelf->alu_code = 3U;
                                vlSelf->insn_sub_type_decode2exec = 2U;
                                vlSelf->imm = vlSelf->decoder__DOT__shamt;
                            }
                        } else {
                            VL_WRITEF("%x addi %2# %2# %x\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__w_rd),
                                      5,vlSelf->decoder__DOT__rs1_wire,
                                      32,vlSelf->decoder__DOT__i_imm);
                            vlSelf->alu_code = 1U;
                            vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                            vlSelf->insn_sub_type_decode2exec = 2U;
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else {
                    VL_WRITEF("Incorrect insn\n");
                }
            } else if ((8U & (IData)(vlSelf->decoder__DOT__opcode))) {
                if (VL_LIKELY((4U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                        if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                            if (VL_UNLIKELY((0U == (IData)(vlSelf->decoder__DOT__funct3)))) {
                                VL_WRITEF("%x fence\n",
                                          32,vlSelf->pc_de);
                            } else if (VL_LIKELY((1U 
                                                  == (IData)(vlSelf->decoder__DOT__funct3)))) {
                                VL_WRITEF("%x fence.i\n",
                                          32,vlSelf->pc_de);
                            } else {
                                VL_WRITEF("Unreachable!\n");
                                VL_FINISH_MT("modules/decoder/decoder.v", 421, "");
                            }
                        } else {
                            VL_WRITEF("Incorrect insn\n");
                        }
                    } else {
                        VL_WRITEF("Incorrect insn\n");
                    }
                } else {
                    VL_WRITEF("Incorrect insn\n");
                }
            } else if (VL_UNLIKELY((4U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                VL_WRITEF("Incorrect insn\n");
            } else if (VL_LIKELY((2U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                if (VL_LIKELY((1U & (IData)(vlSelf->decoder__DOT__opcode)))) {
                    vlSelf->insn_type_decode2exec = 2U;
                    vlSelf->rd = vlSelf->decoder__DOT__w_rd;
                    vlSelf->alu_code = 1U;
                    vlSelf->imm = vlSelf->decoder__DOT__i_imm;
                    vlSelf->ex_use_imm = 1U;
                    if ((4U & (IData)(vlSelf->decoder__DOT__funct3))) {
                        if (VL_UNLIKELY((2U & (IData)(vlSelf->decoder__DOT__funct3)))) {
                            VL_WRITEF("Unreachable!\n");
                            VL_FINISH_MT("modules/decoder/decoder.v", 208, "");
                        } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                            VL_WRITEF("%x lhu %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__w_rd),
                                      32,vlSelf->decoder__DOT__i_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 3U;
                        } else {
                            VL_WRITEF("%x lbu %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__w_rd),
                                      32,vlSelf->decoder__DOT__i_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 1U;
                        }
                    } else if ((2U & (IData)(vlSelf->decoder__DOT__funct3))) {
                        if (VL_UNLIKELY((1U & (IData)(vlSelf->decoder__DOT__funct3)))) {
                            VL_WRITEF("Unreachable!\n");
                            VL_FINISH_MT("modules/decoder/decoder.v", 208, "");
                        } else {
                            VL_WRITEF("%x lw %2# %11d(%2#)\n",
                                      32,vlSelf->pc_de,
                                      5,(IData)(vlSelf->decoder__DOT__w_rd),
                                      32,vlSelf->decoder__DOT__i_imm,
                                      5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                            vlSelf->insn_sub_type_decode2exec = 4U;
                        }
                    } else if ((1U & (IData)(vlSelf->decoder__DOT__funct3))) {
                        VL_WRITEF("%x lh %2# %11d(%2#)\n",
                                  32,vlSelf->pc_de,
                                  5,(IData)(vlSelf->decoder__DOT__w_rd),
                                  32,vlSelf->decoder__DOT__i_imm,
                                  5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                        vlSelf->insn_sub_type_decode2exec = 2U;
                    } else {
                        VL_WRITEF("%x lb %2# %11d(%2#)\n",
                                  32,vlSelf->pc_de,
                                  5,(IData)(vlSelf->decoder__DOT__w_rd),
                                  32,vlSelf->decoder__DOT__i_imm,
                                  5,(IData)(vlSelf->decoder__DOT__rs1_wire));
                        vlSelf->insn_sub_type_decode2exec = 0U;
                    }
                } else {
                    VL_WRITEF("Incorrect insn\n");
                }
            } else {
                VL_WRITEF("Incorrect insn\n");
            }
        }
    }
    vlSelf->exec__DOT__bp_wb_val = vlSelf->wb_ex_bypass_val;
    vlSelf->writeback__DOT__wb_bp_val = vlSelf->wb_ex_bypass_val;
    vlSelf->regfile__DOT__w_reg_val = vlSelf->regfile_w_val;
    vlSelf->writeback__DOT__regfile_w_data = vlSelf->regfile_w_val;
    vlSelf->decoder__DOT__opcode = (0x7fU & vlSelf->insn);
    vlSelf->decoder__DOT__ecall_ebreak_field = (vlSelf->insn 
                                                >> 7U);
    vlSelf->decoder__DOT__funct3 = (7U & (vlSelf->insn 
                                          >> 0xcU));
    vlSelf->decoder__DOT__w_rd = (0x1fU & (vlSelf->insn 
                                           >> 7U));
    vlSelf->decoder__DOT__j_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0x14U) | ((0xff000U 
                                                  & vlSelf->insn) 
                                                 | ((0x800U 
                                                     & (vlSelf->insn 
                                                        >> 9U)) 
                                                    | ((0x7e0U 
                                                        & (vlSelf->insn 
                                                           >> 0x14U)) 
                                                       | (0x1eU 
                                                          & (vlSelf->insn 
                                                             >> 0x14U))))));
    vlSelf->decoder__DOT__i_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0xbU) | (0x7ffU 
                                                & (vlSelf->insn 
                                                   >> 0x14U)));
    vlSelf->decoder__DOT__b_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0x800U 
                                                 & (vlSelf->insn 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->insn 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->insn 
                                                         >> 7U)))));
    vlSelf->decoder__DOT__u_imm = (0xfffff000U & vlSelf->insn);
    vlSelf->decoder__DOT__funct7 = (vlSelf->insn >> 0x19U);
    vlSelf->decoder__DOT__s_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0xbU) | ((0x7e0U 
                                                 & (vlSelf->insn 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->insn 
                                                      >> 7U))));
    vlSelf->decoder__DOT__shamt = (0x1fU & (vlSelf->insn 
                                            >> 0x14U));
    vlSelf->decoder__DOT__rs1_wire = (0x1fU & (vlSelf->insn 
                                               >> 0xfU));
    vlSelf->decoder__DOT__rs2_wire = (0x1fU & (vlSelf->insn 
                                               >> 0x14U));
    vlSelf->pc_de = vlSelf->fetch__DOT__pc;
    vlSelf->from_ex_to_decode_stall = (IData)((0U != (IData)(vlSelf->exec__DOT__load_hazard)));
    vlSelf->decoder__DOT__pc_de = vlSelf->pc_ex;
    vlSelf->exec__DOT__pc_de = vlSelf->pc_ex;
    vlSelf->exec__DOT__awaited_pc_valid = (vlSelf->pc_ex 
                                           == vlSelf->exec__DOT__next_valid_pc);
    vlSelf->decoder__DOT__rd = vlSelf->rd;
    vlSelf->exec__DOT__de_rd = vlSelf->rd;
    vlSelf->fetch__DOT__pc_de = vlSelf->pc_de;
    vlSelf->decoder__DOT__pc = vlSelf->pc_de;
    vlSelf->decoder__DOT__ex_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->exec__DOT__ex_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->from_decode_to_fetch_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->decoder__DOT__alu_code = vlSelf->alu_code;
    vlSelf->exec__DOT__alu_code = vlSelf->alu_code;
    vlSelf->decoder__DOT__imm = vlSelf->imm;
    vlSelf->exec__DOT__imm = vlSelf->imm;
    vlSelf->decoder__DOT__ex_use_imm = vlSelf->ex_use_imm;
    vlSelf->exec__DOT__use_imm = vlSelf->ex_use_imm;
    vlSelf->decoder__DOT__insn_type = vlSelf->insn_type_decode2exec;
    vlSelf->exec__DOT__insn_type = vlSelf->insn_type_decode2exec;
    vlSelf->decoder__DOT__insn_sub_type = vlSelf->insn_sub_type_decode2exec;
    vlSelf->exec__DOT__insn_sub_type = vlSelf->insn_sub_type_decode2exec;
    vlSelf->decoder__DOT__rs2_reg = vlSelf->rs2_reg;
    vlSelf->exec__DOT__rs2_reg = vlSelf->rs2_reg;
    vlSelf->decoder__DOT__rs1_reg = vlSelf->rs1_reg;
    vlSelf->exec__DOT__rs1_reg = vlSelf->rs1_reg;
    vlSelf->fetch__DOT__ex_stall = vlSelf->from_decode_to_fetch_stall;
    vlSelf->decoder__DOT__ex_stall_to_fetch = vlSelf->from_decode_to_fetch_stall;
    vlSelf->exec__DOT__alu__DOT__alu_code = vlSelf->exec__DOT__alu_code;
}

VL_INLINE_OPT void Vtop_top___sequent__TOP__top__1(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___sequent__TOP__top__1\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__regfile__DOT__regs__v0;
    IData/*31:0*/ __Vdlyvval__regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__regfile__DOT__regs__v0;
    // Body
    __Vdlyvset__regfile__DOT__regs__v0 = 0U;
    if (vlSelf->regfile_w_enable) {
        if ((0U != (IData)(vlSelf->regfile_w_reg))) {
            __Vdlyvval__regfile__DOT__regs__v0 = vlSelf->regfile_w_val;
            __Vdlyvset__regfile__DOT__regs__v0 = 1U;
            __Vdlyvdim0__regfile__DOT__regs__v0 = vlSelf->regfile_w_reg;
        }
    }
    if (__Vdlyvset__regfile__DOT__regs__v0) {
        vlSelf->regfile__DOT__regs[__Vdlyvdim0__regfile__DOT__regs__v0] 
            = __Vdlyvval__regfile__DOT__regs__v0;
    }
}

VL_INLINE_OPT void Vtop_top___multiclk__TOP__top__0(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___multiclk__TOP__top__0\n"); );
    // Body
    vlSelf->regfile_r2_val = ((0U == (IData)(vlSelf->regfile_r2_reg))
                               ? 0U : vlSelf->regfile__DOT__regs
                              [vlSelf->regfile_r2_reg]);
    vlSelf->regfile_r1_val = ((0U == (IData)(vlSelf->regfile_r1_reg))
                               ? 0U : vlSelf->regfile__DOT__regs
                              [vlSelf->regfile_r1_reg]);
    vlSelf->regfile__DOT__r2_reg_val = vlSelf->regfile_r2_val;
    vlSelf->exec__DOT__rs2_regfile_val = vlSelf->regfile_r2_val;
    vlSelf->exec__DOT__rs2_actual = (((IData)(vlSelf->rs2_reg) 
                                      == (IData)(vlSelf->exec__DOT__ex_bp_reg))
                                      ? vlSelf->exec__DOT__ex_bp_val
                                      : (((IData)(vlSelf->rs2_reg) 
                                          == (IData)(vlSelf->mem_ex_bypass_reg))
                                          ? vlSelf->mem_ex_bypass_val
                                          : vlSelf->regfile_r2_val));
    vlSelf->regfile__DOT__r1_reg_val = vlSelf->regfile_r1_val;
    vlSelf->exec__DOT__rs1_regfile_val = vlSelf->regfile_r1_val;
    vlSelf->exec__DOT__rs1_actual = (((IData)(vlSelf->rs1_reg) 
                                      == (IData)(vlSelf->exec__DOT__ex_bp_reg))
                                      ? vlSelf->exec__DOT__ex_bp_val
                                      : (((IData)(vlSelf->rs1_reg) 
                                          == (IData)(vlSelf->mem_ex_bypass_reg))
                                          ? vlSelf->mem_ex_bypass_val
                                          : vlSelf->regfile_r1_val));
    vlSelf->exec__DOT__alu_rs2 = ((IData)(vlSelf->ex_use_imm)
                                   ? vlSelf->imm : vlSelf->exec__DOT__rs2_actual);
    vlSelf->exec__DOT__alu_rs1 = ((1U == (IData)(vlSelf->insn_type_decode2exec))
                                   ? vlSelf->exec__DOT__rs1_actual
                                   : (((0U == (IData)(vlSelf->insn_type_decode2exec)) 
                                       & (3U == (IData)(vlSelf->insn_sub_type_decode2exec)))
                                       ? vlSelf->pc_ex
                                       : vlSelf->exec__DOT__rs1_actual));
    vlSelf->exec__DOT__alu__DOT__op2 = vlSelf->exec__DOT__alu_rs2;
    vlSelf->exec__DOT__alu__DOT__op1 = vlSelf->exec__DOT__alu_rs1;
    if ((8U & (IData)(vlSelf->alu_code))) {
        if (VL_UNLIKELY((4U & (IData)(vlSelf->alu_code)))) {
            VL_WRITEF("Unreachable!\n");
            vlSelf->exec__DOT__alu__DOT__xres = 0U;
            VL_FINISH_MT("modules/exec/alu.v", 31, "");
        } else if ((2U & (IData)(vlSelf->alu_code))) {
            if (VL_UNLIKELY((1U & (IData)(vlSelf->alu_code)))) {
                vlSelf->exec__DOT__alu__DOT__xres = 0U;
                VL_WRITEF("Unreachable!\n");
                VL_FINISH_MT("modules/exec/alu.v", 31, "");
            } else {
                vlSelf->exec__DOT__alu__DOT__xres = 
                    (vlSelf->exec__DOT__alu_rs1 ^ vlSelf->exec__DOT__alu_rs2);
            }
        } else {
            vlSelf->exec__DOT__alu__DOT__xres = ((1U 
                                                  & (IData)(vlSelf->alu_code))
                                                  ? 
                                                 (vlSelf->exec__DOT__alu_rs1 
                                                  & vlSelf->exec__DOT__alu_rs2)
                                                  : 
                                                 (vlSelf->exec__DOT__alu_rs1 
                                                  | vlSelf->exec__DOT__alu_rs2));
        }
    } else {
        vlSelf->exec__DOT__alu__DOT__xres = ((4U & (IData)(vlSelf->alu_code))
                                              ? ((2U 
                                                  & (IData)(vlSelf->alu_code))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->alu_code))
                                                   ? 
                                                  (((vlSelf->exec__DOT__alu_rs1 
                                                     < vlSelf->exec__DOT__alu_rs2) 
                                                    << 1U) 
                                                   | (vlSelf->exec__DOT__alu_rs1 
                                                      == vlSelf->exec__DOT__alu_rs2))
                                                   : 
                                                  ((VL_LTS_III(32, vlSelf->exec__DOT__alu_rs1, vlSelf->exec__DOT__alu_rs2) 
                                                    << 1U) 
                                                   | (vlSelf->exec__DOT__alu_rs1 
                                                      == vlSelf->exec__DOT__alu_rs2)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->alu_code))
                                                   ? 
                                                  ((0x1fU 
                                                    >= vlSelf->exec__DOT__alu_rs2)
                                                    ? 
                                                   (vlSelf->exec__DOT__alu_rs1 
                                                    >> vlSelf->exec__DOT__alu_rs2)
                                                    : 0U)
                                                   : 
                                                  ((0x1fU 
                                                    >= vlSelf->exec__DOT__alu_rs2)
                                                    ? 
                                                   VL_SHIFTRS_III(32,32,32, vlSelf->exec__DOT__alu_rs1, vlSelf->exec__DOT__alu_rs2)
                                                    : 
                                                   (- 
                                                    (vlSelf->exec__DOT__alu_rs1 
                                                     >> 0x1fU)))))
                                              : ((2U 
                                                  & (IData)(vlSelf->alu_code))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelf->alu_code))
                                                   ? 
                                                  ((0x1fU 
                                                    >= vlSelf->exec__DOT__alu_rs2)
                                                    ? 
                                                   (vlSelf->exec__DOT__alu_rs1 
                                                    << vlSelf->exec__DOT__alu_rs2)
                                                    : 0U)
                                                   : 
                                                  (vlSelf->exec__DOT__alu_rs1 
                                                   - vlSelf->exec__DOT__alu_rs2))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelf->alu_code))
                                                   ? 
                                                  (vlSelf->exec__DOT__alu_rs1 
                                                   + vlSelf->exec__DOT__alu_rs2)
                                                   : 0U)));
    }
    vlSelf->exec__DOT__w_alu_res = vlSelf->exec__DOT__alu__DOT__xres;
    vlSelf->exec__DOT__cmp_eq = (1U & vlSelf->exec__DOT__w_alu_res);
    vlSelf->exec__DOT__cmp_less = (1U & (vlSelf->exec__DOT__w_alu_res 
                                         >> 1U));
    vlSelf->exec__DOT__alu__DOT__res = vlSelf->exec__DOT__w_alu_res;
}
