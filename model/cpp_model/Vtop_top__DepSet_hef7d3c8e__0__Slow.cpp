// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vtop_top.h"

VL_ATTR_COLD void Vtop_top___initial__TOP__top__0(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___initial__TOP__top__0\n"); );
    // Body
    vlSelf->ram__DOT__last_w_addr = 0U;
    vlSelf->regfile_w_enable = 1U;
    vlSelf->exec__DOT__load_hazard = 0U;
    vlSelf->exec__DOT__wait_for_pc = 0U;
    vlSelf->decoder__DOT__ecall_ebreak_encountered = 0U;
    vlSelf->regfile__DOT__w_enable = vlSelf->regfile_w_enable;
    vlSelf->writeback__DOT__regfile_w_en = vlSelf->regfile_w_enable;
}

VL_ATTR_COLD void Vtop_top___settle__TOP__top__0(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___settle__TOP__top__0\n"); );
    // Body
    vlSelf->regfile__DOT__r1_reg_name = vlSelf->regfile_r1_reg;
    vlSelf->regfile__DOT__r2_reg_name = vlSelf->regfile_r2_reg;
    vlSelf->decoder__DOT__rs1 = vlSelf->regfile_r1_reg;
    vlSelf->decoder__DOT__rs2 = vlSelf->regfile_r2_reg;
    vlSelf->exec__DOT__bp_mem_reg = vlSelf->mem_ex_bypass_reg;
    vlSelf->exec__DOT__bp_mem_val = vlSelf->mem_ex_bypass_val;
    vlSelf->mem__DOT__bp_mem_reg = vlSelf->mem_ex_bypass_reg;
    vlSelf->mem__DOT__bp_mem_val = vlSelf->mem_ex_bypass_val;
    vlSelf->mem__DOT__insn_type_r = vlSelf->mem2wb_insn_type;
    vlSelf->writeback__DOT__insn_type = vlSelf->mem2wb_insn_type;
    vlSelf->regfile_r2_val = ((0U == (IData)(vlSelf->regfile_r2_reg))
                               ? 0U : vlSelf->regfile__DOT__regs
                              [vlSelf->regfile_r2_reg]);
    vlSelf->regfile_r1_val = ((0U == (IData)(vlSelf->regfile_r1_reg))
                               ? 0U : vlSelf->regfile__DOT__regs
                              [vlSelf->regfile_r1_reg]);
    vlSelf->ram_r2_addr = (vlSelf->fetch__DOT__pc >> 2U);
    vlSelf->ram__DOT__r1_addr_e = vlSelf->ram_r1_addr;
    vlSelf->ram__DOT__w_enable = vlSelf->ram_w_enable;
    vlSelf->ram__DOT__w_addr_e = vlSelf->ram_w_addr;
    vlSelf->ram__DOT__w_val = vlSelf->ram_w_val;
    vlSelf->ram__DOT__byte_en = vlSelf->ram_w_byte_en;
    vlSelf->ram__DOT__w_addr = (0x1ffffU & vlSelf->ram_w_addr);
    vlSelf->mem__DOT__wb_reg_r = vlSelf->wb_reg;
    vlSelf->mem__DOT__wb_val = vlSelf->wb_val;
    vlSelf->mem__DOT__ram_r_addr = vlSelf->ram_r1_addr;
    vlSelf->mem__DOT__ram_w_addr = vlSelf->ram_w_addr;
    vlSelf->mem__DOT__ram_w_data = vlSelf->ram_w_val;
    vlSelf->mem__DOT__ram_byte_en = vlSelf->ram_w_byte_en;
    vlSelf->mem__DOT__ram_w_en = vlSelf->ram_w_enable;
    vlSelf->mem__DOT__use_mem_output = vlSelf->use_mem_output;
    vlSelf->writeback__DOT__rd = vlSelf->wb_reg;
    vlSelf->writeback__DOT__ex_val = vlSelf->wb_val;
    vlSelf->wb_ex_bypass_reg = vlSelf->wb_reg;
    vlSelf->regfile_w_reg = vlSelf->wb_reg;
    vlSelf->ram__DOT__r1_addr = (0x1ffffU & vlSelf->ram_r1_addr);
    vlSelf->fetch__DOT__pc_ex_off = vlSelf->ex_pc_offset;
    vlSelf->fetch__DOT__pc_ex_base = vlSelf->ex_pc_base;
    vlSelf->fetch__DOT__pc_ex_valid = vlSelf->ex_pc_valid;
    vlSelf->exec__DOT__next_stage_val = vlSelf->ex2mem_val;
    vlSelf->exec__DOT__rd_ex = vlSelf->rd_ex;
    vlSelf->exec__DOT__pc_offset = vlSelf->ex_pc_offset;
    vlSelf->exec__DOT__pc_base = vlSelf->ex_pc_base;
    vlSelf->exec__DOT__pc_redirect_valid = vlSelf->ex_pc_valid;
    vlSelf->exec__DOT__store_val = vlSelf->ex_store_val;
    vlSelf->exec__DOT__insn_type_r = vlSelf->ex2mem_insn_type;
    vlSelf->exec__DOT__insn_sub_type_r = vlSelf->ex2mem_insn_sub_type;
    vlSelf->mem__DOT__insn_type = vlSelf->ex2mem_insn_type;
    vlSelf->mem__DOT__insn_sub_type = vlSelf->ex2mem_insn_sub_type;
    vlSelf->mem__DOT__ex_val = vlSelf->ex2mem_val;
    vlSelf->mem__DOT__store_val = vlSelf->ex_store_val;
    vlSelf->mem__DOT__wb_reg = vlSelf->rd_ex;
    vlSelf->pc_de = vlSelf->fetch__DOT__pc;
    vlSelf->decoder__DOT__rd = vlSelf->rd;
    vlSelf->decoder__DOT__alu_code = vlSelf->alu_code;
    vlSelf->decoder__DOT__pc_de = vlSelf->pc_ex;
    vlSelf->decoder__DOT__imm = vlSelf->imm;
    vlSelf->decoder__DOT__ex_use_imm = vlSelf->ex_use_imm;
    vlSelf->decoder__DOT__rs1_reg = vlSelf->rs1_reg;
    vlSelf->decoder__DOT__rs2_reg = vlSelf->rs2_reg;
    vlSelf->decoder__DOT__insn_type = vlSelf->insn_type_decode2exec;
    vlSelf->decoder__DOT__insn_sub_type = vlSelf->insn_sub_type_decode2exec;
    vlSelf->exec__DOT__insn_type = vlSelf->insn_type_decode2exec;
    vlSelf->exec__DOT__insn_sub_type = vlSelf->insn_sub_type_decode2exec;
    vlSelf->exec__DOT__rs1_reg = vlSelf->rs1_reg;
    vlSelf->exec__DOT__rs2_reg = vlSelf->rs2_reg;
    vlSelf->exec__DOT__pc_de = vlSelf->pc_ex;
    vlSelf->exec__DOT__imm = vlSelf->imm;
    vlSelf->exec__DOT__use_imm = vlSelf->ex_use_imm;
    vlSelf->exec__DOT__de_rd = vlSelf->rd;
    vlSelf->exec__DOT__awaited_pc_valid = (vlSelf->pc_ex 
                                           == vlSelf->exec__DOT__next_valid_pc);
    vlSelf->exec__DOT__alu_code = vlSelf->alu_code;
    vlSelf->regfile__DOT__w_enable = vlSelf->regfile_w_enable;
    vlSelf->writeback__DOT__regfile_w_en = vlSelf->regfile_w_enable;
    vlSelf->from_ex_to_decode_stall = (IData)((0U != (IData)(vlSelf->exec__DOT__load_hazard)));
    vlSelf->ram__DOT__clk = vlSelf->clk;
    vlSelf->regfile__DOT__clk = vlSelf->clk;
    vlSelf->fetch__DOT__clk = vlSelf->clk;
    vlSelf->decoder__DOT__clk = vlSelf->clk;
    vlSelf->exec__DOT__clk = vlSelf->clk;
    vlSelf->mem__DOT__clk = vlSelf->clk;
    vlSelf->writeback__DOT__clk = vlSelf->clk;
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
    vlSelf->ram__DOT__r2_addr_e = vlSelf->ram_r2_addr;
    vlSelf->fetch__DOT__mem_addr = vlSelf->ram_r2_addr;
    vlSelf->ram__DOT__r2_addr = (0x1ffffU & vlSelf->ram_r2_addr);
    vlSelf->exec__DOT__bp_wb_reg = vlSelf->wb_ex_bypass_reg;
    vlSelf->writeback__DOT__wb_bp_reg = vlSelf->wb_ex_bypass_reg;
    vlSelf->regfile__DOT__w_reg_name = vlSelf->regfile_w_reg;
    vlSelf->writeback__DOT__regfile_w_reg = vlSelf->regfile_w_reg;
    vlSelf->ram_r1_val = ((0x10000U >= vlSelf->ram__DOT__r1_addr)
                           ? vlSelf->ram__DOT__data
                          [vlSelf->ram__DOT__r1_addr]
                           : 0U);
    vlSelf->fetch__DOT__pc_de = vlSelf->pc_de;
    vlSelf->decoder__DOT__pc = vlSelf->pc_de;
    vlSelf->exec__DOT__alu__DOT__alu_code = vlSelf->exec__DOT__alu_code;
    vlSelf->decoder__DOT__ex_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->exec__DOT__ex_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->from_decode_to_fetch_stall = vlSelf->from_ex_to_decode_stall;
    vlSelf->exec__DOT__alu_rs2 = ((IData)(vlSelf->ex_use_imm)
                                   ? vlSelf->imm : vlSelf->exec__DOT__rs2_actual);
    vlSelf->exec__DOT__alu_rs1 = ((1U == (IData)(vlSelf->insn_type_decode2exec))
                                   ? vlSelf->exec__DOT__rs1_actual
                                   : (((0U == (IData)(vlSelf->insn_type_decode2exec)) 
                                       & (3U == (IData)(vlSelf->insn_sub_type_decode2exec)))
                                       ? vlSelf->pc_ex
                                       : vlSelf->exec__DOT__rs1_actual));
    vlSelf->ram_r2_val = ((0x10000U >= vlSelf->ram__DOT__r2_addr)
                           ? vlSelf->ram__DOT__data
                          [vlSelf->ram__DOT__r2_addr]
                           : 0U);
    vlSelf->ram__DOT__r1_val = vlSelf->ram_r1_val;
    vlSelf->writeback__DOT__mem_r_data = vlSelf->ram_r1_val;
    if ((2U == (IData)(vlSelf->mem2wb_insn_type))) {
        vlSelf->wb_ex_bypass_val = vlSelf->ram_r1_val;
        vlSelf->regfile_w_val = vlSelf->ram_r1_val;
    } else {
        vlSelf->wb_ex_bypass_val = vlSelf->wb_val;
        vlSelf->regfile_w_val = vlSelf->wb_val;
    }
    vlSelf->fetch__DOT__ex_stall = vlSelf->from_decode_to_fetch_stall;
    vlSelf->decoder__DOT__ex_stall_to_fetch = vlSelf->from_decode_to_fetch_stall;
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
    vlSelf->ram__DOT__r2_val = vlSelf->ram_r2_val;
    vlSelf->fetch__DOT__mem_data = vlSelf->ram_r2_val;
    vlSelf->insn = vlSelf->ram_r2_val;
    vlSelf->exec__DOT__bp_wb_val = vlSelf->wb_ex_bypass_val;
    vlSelf->writeback__DOT__wb_bp_val = vlSelf->wb_ex_bypass_val;
    vlSelf->regfile__DOT__w_reg_val = vlSelf->regfile_w_val;
    vlSelf->writeback__DOT__regfile_w_data = vlSelf->regfile_w_val;
    vlSelf->exec__DOT__w_alu_res = vlSelf->exec__DOT__alu__DOT__xres;
    vlSelf->fetch__DOT__insn = vlSelf->insn;
    vlSelf->decoder__DOT__insn = vlSelf->insn;
    vlSelf->decoder__DOT__rs1_wire = (0x1fU & (vlSelf->insn 
                                               >> 0xfU));
    vlSelf->decoder__DOT__rs2_wire = (0x1fU & (vlSelf->insn 
                                               >> 0x14U));
    vlSelf->decoder__DOT__opcode = (0x7fU & vlSelf->insn);
    vlSelf->decoder__DOT__funct3 = (7U & (vlSelf->insn 
                                          >> 0xcU));
    vlSelf->decoder__DOT__funct7 = (vlSelf->insn >> 0x19U);
    vlSelf->decoder__DOT__w_rd = (0x1fU & (vlSelf->insn 
                                           >> 7U));
    vlSelf->decoder__DOT__ecall_ebreak_field = (vlSelf->insn 
                                                >> 7U);
    vlSelf->decoder__DOT__u_imm = (0xfffff000U & vlSelf->insn);
    vlSelf->decoder__DOT__i_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0xbU) | (0x7ffU 
                                                & (vlSelf->insn 
                                                   >> 0x14U)));
    vlSelf->decoder__DOT__s_imm = (((- (IData)((vlSelf->insn 
                                                >> 0x1fU))) 
                                    << 0xbU) | ((0x7e0U 
                                                 & (vlSelf->insn 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->insn 
                                                      >> 7U))));
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
    vlSelf->decoder__DOT__shamt = (0x1fU & (vlSelf->insn 
                                            >> 0x14U));
    vlSelf->exec__DOT__cmp_eq = (1U & vlSelf->exec__DOT__w_alu_res);
    vlSelf->exec__DOT__cmp_less = (1U & (vlSelf->exec__DOT__w_alu_res 
                                         >> 1U));
    vlSelf->exec__DOT__alu__DOT__res = vlSelf->exec__DOT__w_alu_res;
}

VL_ATTR_COLD void Vtop_top___ctor_var_reset(Vtop_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->ram_r1_addr = VL_RAND_RESET_I(30);
    vlSelf->ram_r1_val = VL_RAND_RESET_I(32);
    vlSelf->ram_r2_addr = VL_RAND_RESET_I(30);
    vlSelf->ram_r2_val = VL_RAND_RESET_I(32);
    vlSelf->ram_w_enable = VL_RAND_RESET_I(1);
    vlSelf->ram_w_addr = VL_RAND_RESET_I(30);
    vlSelf->ram_w_val = VL_RAND_RESET_I(32);
    vlSelf->ram_w_byte_en = VL_RAND_RESET_I(4);
    vlSelf->regfile_r1_reg = VL_RAND_RESET_I(5);
    vlSelf->regfile_r1_val = VL_RAND_RESET_I(32);
    vlSelf->regfile_r2_reg = VL_RAND_RESET_I(5);
    vlSelf->regfile_r2_val = VL_RAND_RESET_I(32);
    vlSelf->regfile_w_enable = VL_RAND_RESET_I(1);
    vlSelf->regfile_w_reg = VL_RAND_RESET_I(5);
    vlSelf->regfile_w_val = VL_RAND_RESET_I(32);
    vlSelf->ex_pc_offset = VL_RAND_RESET_I(32);
    vlSelf->ex_pc_base = VL_RAND_RESET_I(32);
    vlSelf->ex_pc_valid = VL_RAND_RESET_I(1);
    vlSelf->from_decode_to_fetch_stall = VL_RAND_RESET_I(1);
    vlSelf->insn = VL_RAND_RESET_I(32);
    vlSelf->pc_de = VL_RAND_RESET_I(32);
    vlSelf->from_ex_to_decode_stall = VL_RAND_RESET_I(1);
    vlSelf->rd = VL_RAND_RESET_I(5);
    vlSelf->alu_code = VL_RAND_RESET_I(4);
    vlSelf->imm = VL_RAND_RESET_I(32);
    vlSelf->ex_use_imm = VL_RAND_RESET_I(1);
    vlSelf->rs1_reg = VL_RAND_RESET_I(5);
    vlSelf->rs2_reg = VL_RAND_RESET_I(5);
    vlSelf->insn_type_decode2exec = VL_RAND_RESET_I(4);
    vlSelf->insn_sub_type_decode2exec = VL_RAND_RESET_I(4);
    vlSelf->pc_ex = VL_RAND_RESET_I(32);
    vlSelf->wb_ex_bypass_reg = VL_RAND_RESET_I(5);
    vlSelf->wb_ex_bypass_val = VL_RAND_RESET_I(32);
    vlSelf->mem_ex_bypass_reg = VL_RAND_RESET_I(5);
    vlSelf->mem_ex_bypass_val = VL_RAND_RESET_I(32);
    vlSelf->ex2mem_val = VL_RAND_RESET_I(32);
    vlSelf->rd_ex = VL_RAND_RESET_I(5);
    vlSelf->ex_store_val = VL_RAND_RESET_I(32);
    vlSelf->ex2mem_insn_type = VL_RAND_RESET_I(4);
    vlSelf->ex2mem_insn_sub_type = VL_RAND_RESET_I(4);
    vlSelf->wb_reg = VL_RAND_RESET_I(5);
    vlSelf->wb_val = VL_RAND_RESET_I(32);
    vlSelf->use_mem_output = VL_RAND_RESET_I(1);
    vlSelf->mem2wb_insn_type = VL_RAND_RESET_I(4);
    vlSelf->ram__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->ram__DOT__r1_addr_e = VL_RAND_RESET_I(30);
    vlSelf->ram__DOT__r1_val = VL_RAND_RESET_I(32);
    vlSelf->ram__DOT__r2_addr_e = VL_RAND_RESET_I(30);
    vlSelf->ram__DOT__r2_val = VL_RAND_RESET_I(32);
    vlSelf->ram__DOT__w_enable = VL_RAND_RESET_I(1);
    vlSelf->ram__DOT__w_addr_e = VL_RAND_RESET_I(30);
    vlSelf->ram__DOT__w_val = VL_RAND_RESET_I(32);
    vlSelf->ram__DOT__byte_en = VL_RAND_RESET_I(4);
    for (int __Vi0=0; __Vi0<65537; ++__Vi0) {
        vlSelf->ram__DOT__data[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->ram__DOT__r1_addr = VL_RAND_RESET_I(17);
    vlSelf->ram__DOT__r2_addr = VL_RAND_RESET_I(17);
    vlSelf->ram__DOT__w_addr = VL_RAND_RESET_I(17);
    vlSelf->ram__DOT__last_w_addr = VL_RAND_RESET_I(17);
    vlSelf->ram__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->ram__DOT____Vlvbound_h8f22570d__0 = VL_RAND_RESET_I(8);
    vlSelf->ram__DOT____Vlvbound_had4cc1fd__0 = VL_RAND_RESET_I(8);
    vlSelf->ram__DOT____Vlvbound_h8f232cba__0 = VL_RAND_RESET_I(8);
    vlSelf->ram__DOT____Vlvbound_h8f21afc2__0 = VL_RAND_RESET_I(8);
    vlSelf->regfile__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->regfile__DOT__r1_reg_name = VL_RAND_RESET_I(5);
    vlSelf->regfile__DOT__r1_reg_val = VL_RAND_RESET_I(32);
    vlSelf->regfile__DOT__r2_reg_name = VL_RAND_RESET_I(5);
    vlSelf->regfile__DOT__r2_reg_val = VL_RAND_RESET_I(32);
    vlSelf->regfile__DOT__w_enable = VL_RAND_RESET_I(1);
    vlSelf->regfile__DOT__w_reg_name = VL_RAND_RESET_I(5);
    vlSelf->regfile__DOT__w_reg_val = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->regfile__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->fetch__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->fetch__DOT__pc_ex_off = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__pc_ex_base = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__pc_ex_valid = VL_RAND_RESET_I(1);
    vlSelf->fetch__DOT__mem_data = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__ex_stall = VL_RAND_RESET_I(1);
    vlSelf->fetch__DOT__mem_addr = VL_RAND_RESET_I(30);
    vlSelf->fetch__DOT__insn = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__pc_de = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__pc_prev = VL_RAND_RESET_I(32);
    vlSelf->fetch__DOT__prev_insn = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->decoder__DOT__insn = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__ex_stall = VL_RAND_RESET_I(1);
    vlSelf->decoder__DOT__rs1 = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__rs2 = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__alu_code = VL_RAND_RESET_I(4);
    vlSelf->decoder__DOT__pc_de = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__ex_use_imm = VL_RAND_RESET_I(1);
    vlSelf->decoder__DOT__rs1_reg = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__rs2_reg = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__insn_type = VL_RAND_RESET_I(4);
    vlSelf->decoder__DOT__insn_sub_type = VL_RAND_RESET_I(4);
    vlSelf->decoder__DOT__ex_stall_to_fetch = VL_RAND_RESET_I(1);
    vlSelf->decoder__DOT__ecall_ebreak_encountered = VL_RAND_RESET_I(1);
    vlSelf->decoder__DOT__opcode = VL_RAND_RESET_I(7);
    vlSelf->decoder__DOT__funct3 = VL_RAND_RESET_I(3);
    vlSelf->decoder__DOT__funct7 = VL_RAND_RESET_I(7);
    vlSelf->decoder__DOT__u_imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__i_imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__j_imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__b_imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__s_imm = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__shamt = VL_RAND_RESET_I(32);
    vlSelf->decoder__DOT__rs1_wire = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__rs2_wire = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__w_rd = VL_RAND_RESET_I(5);
    vlSelf->decoder__DOT__ecall_ebreak_field = VL_RAND_RESET_I(25);
    vlSelf->exec__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__insn_type = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__insn_sub_type = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__alu_code = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__rs1_reg = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__rs1_regfile_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__rs2_reg = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__rs2_regfile_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__pc_de = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__use_imm = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__bp_wb_reg = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__bp_wb_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__bp_mem_reg = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__bp_mem_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__de_rd = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__next_stage_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__rd_ex = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__pc_offset = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__pc_base = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__pc_redirect_valid = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__store_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__insn_type_r = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__insn_sub_type_r = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__ex_stall = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__ex_bp_reg = VL_RAND_RESET_I(5);
    vlSelf->exec__DOT__ex_bp_val = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__next_valid_pc = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__wait_for_pc = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__load_hazard = VL_RAND_RESET_I(2);
    vlSelf->exec__DOT__w_alu_res = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__alu_rs1 = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__alu_rs2 = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__rs1_actual = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__rs2_actual = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__cmp_eq = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__cmp_less = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__awaited_pc_valid = VL_RAND_RESET_I(1);
    vlSelf->exec__DOT__alu__DOT__alu_code = VL_RAND_RESET_I(4);
    vlSelf->exec__DOT__alu__DOT__op1 = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__alu__DOT__op2 = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__alu__DOT__res = VL_RAND_RESET_I(32);
    vlSelf->exec__DOT__alu__DOT__xres = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->mem__DOT__insn_type = VL_RAND_RESET_I(4);
    vlSelf->mem__DOT__insn_sub_type = VL_RAND_RESET_I(4);
    vlSelf->mem__DOT__ex_val = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__store_val = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__wb_reg = VL_RAND_RESET_I(5);
    vlSelf->mem__DOT__wb_reg_r = VL_RAND_RESET_I(5);
    vlSelf->mem__DOT__wb_val = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__bp_mem_reg = VL_RAND_RESET_I(5);
    vlSelf->mem__DOT__bp_mem_val = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__ram_r_addr = VL_RAND_RESET_I(30);
    vlSelf->mem__DOT__ram_w_addr = VL_RAND_RESET_I(30);
    vlSelf->mem__DOT__ram_w_data = VL_RAND_RESET_I(32);
    vlSelf->mem__DOT__ram_byte_en = VL_RAND_RESET_I(4);
    vlSelf->mem__DOT__ram_w_en = VL_RAND_RESET_I(1);
    vlSelf->mem__DOT__use_mem_output = VL_RAND_RESET_I(1);
    vlSelf->mem__DOT__insn_type_r = VL_RAND_RESET_I(4);
    vlSelf->writeback__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->writeback__DOT__insn_type = VL_RAND_RESET_I(4);
    vlSelf->writeback__DOT__rd = VL_RAND_RESET_I(5);
    vlSelf->writeback__DOT__ex_val = VL_RAND_RESET_I(32);
    vlSelf->writeback__DOT__mem_r_data = VL_RAND_RESET_I(32);
    vlSelf->writeback__DOT__regfile_w_reg = VL_RAND_RESET_I(5);
    vlSelf->writeback__DOT__regfile_w_en = VL_RAND_RESET_I(1);
    vlSelf->writeback__DOT__regfile_w_data = VL_RAND_RESET_I(32);
    vlSelf->writeback__DOT__wb_bp_reg = VL_RAND_RESET_I(5);
    vlSelf->writeback__DOT__wb_bp_val = VL_RAND_RESET_I(32);
}
