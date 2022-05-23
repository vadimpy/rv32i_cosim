// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"

class Vtop__Syms;
VL_MODULE(Vtop_top) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        CData/*0:0*/ ram_w_enable;
        CData/*3:0*/ ram_w_byte_en;
        CData/*4:0*/ regfile_r1_reg;
        CData/*4:0*/ regfile_r2_reg;
        CData/*0:0*/ regfile_w_enable;
        CData/*4:0*/ regfile_w_reg;
        CData/*0:0*/ ex_pc_valid;
        CData/*0:0*/ from_decode_to_fetch_stall;
        CData/*0:0*/ from_ex_to_decode_stall;
        CData/*4:0*/ rd;
        CData/*3:0*/ alu_code;
        CData/*0:0*/ ex_use_imm;
        CData/*4:0*/ rs1_reg;
        CData/*4:0*/ rs2_reg;
        CData/*3:0*/ insn_type_decode2exec;
        CData/*3:0*/ insn_sub_type_decode2exec;
        CData/*4:0*/ wb_ex_bypass_reg;
        CData/*4:0*/ mem_ex_bypass_reg;
        CData/*4:0*/ rd_ex;
        CData/*3:0*/ ex2mem_insn_type;
        CData/*3:0*/ ex2mem_insn_sub_type;
        CData/*4:0*/ wb_reg;
        CData/*0:0*/ use_mem_output;
        CData/*3:0*/ mem2wb_insn_type;
        CData/*0:0*/ ram__DOT__clk;
        CData/*0:0*/ ram__DOT__w_enable;
        CData/*3:0*/ ram__DOT__byte_en;
        CData/*7:0*/ ram__DOT____Vlvbound_h8f22570d__0;
        CData/*7:0*/ ram__DOT____Vlvbound_had4cc1fd__0;
        CData/*7:0*/ ram__DOT____Vlvbound_h8f232cba__0;
        CData/*7:0*/ ram__DOT____Vlvbound_h8f21afc2__0;
        CData/*0:0*/ regfile__DOT__clk;
        CData/*4:0*/ regfile__DOT__r1_reg_name;
        CData/*4:0*/ regfile__DOT__r2_reg_name;
        CData/*0:0*/ regfile__DOT__w_enable;
        CData/*4:0*/ regfile__DOT__w_reg_name;
        CData/*0:0*/ fetch__DOT__clk;
        CData/*0:0*/ fetch__DOT__pc_ex_valid;
        CData/*0:0*/ fetch__DOT__ex_stall;
        CData/*0:0*/ decoder__DOT__clk;
        CData/*0:0*/ decoder__DOT__ex_stall;
        CData/*4:0*/ decoder__DOT__rs1;
        CData/*4:0*/ decoder__DOT__rs2;
        CData/*4:0*/ decoder__DOT__rd;
        CData/*3:0*/ decoder__DOT__alu_code;
        CData/*0:0*/ decoder__DOT__ex_use_imm;
        CData/*4:0*/ decoder__DOT__rs1_reg;
        CData/*4:0*/ decoder__DOT__rs2_reg;
        CData/*3:0*/ decoder__DOT__insn_type;
        CData/*3:0*/ decoder__DOT__insn_sub_type;
        CData/*0:0*/ decoder__DOT__ex_stall_to_fetch;
        CData/*0:0*/ decoder__DOT__ecall_ebreak_encountered;
        CData/*6:0*/ decoder__DOT__opcode;
        CData/*2:0*/ decoder__DOT__funct3;
        CData/*6:0*/ decoder__DOT__funct7;
        CData/*4:0*/ decoder__DOT__rs1_wire;
        CData/*4:0*/ decoder__DOT__rs2_wire;
        CData/*4:0*/ decoder__DOT__w_rd;
        CData/*0:0*/ exec__DOT__clk;
        CData/*3:0*/ exec__DOT__insn_type;
        CData/*3:0*/ exec__DOT__insn_sub_type;
        CData/*3:0*/ exec__DOT__alu_code;
        CData/*4:0*/ exec__DOT__rs1_reg;
    };
    struct {
        CData/*4:0*/ exec__DOT__rs2_reg;
        CData/*0:0*/ exec__DOT__use_imm;
        CData/*4:0*/ exec__DOT__bp_wb_reg;
        CData/*4:0*/ exec__DOT__bp_mem_reg;
        CData/*4:0*/ exec__DOT__de_rd;
        CData/*4:0*/ exec__DOT__rd_ex;
        CData/*0:0*/ exec__DOT__pc_redirect_valid;
        CData/*3:0*/ exec__DOT__insn_type_r;
        CData/*3:0*/ exec__DOT__insn_sub_type_r;
        CData/*0:0*/ exec__DOT__ex_stall;
        CData/*4:0*/ exec__DOT__ex_bp_reg;
        CData/*0:0*/ exec__DOT__wait_for_pc;
        CData/*1:0*/ exec__DOT__load_hazard;
        CData/*0:0*/ exec__DOT__cmp_eq;
        CData/*0:0*/ exec__DOT__cmp_less;
        CData/*0:0*/ exec__DOT__awaited_pc_valid;
        CData/*3:0*/ exec__DOT__alu__DOT__alu_code;
        CData/*0:0*/ mem__DOT__clk;
        CData/*3:0*/ mem__DOT__insn_type;
        CData/*3:0*/ mem__DOT__insn_sub_type;
        CData/*4:0*/ mem__DOT__wb_reg;
        CData/*4:0*/ mem__DOT__wb_reg_r;
        CData/*4:0*/ mem__DOT__bp_mem_reg;
        CData/*3:0*/ mem__DOT__ram_byte_en;
        CData/*0:0*/ mem__DOT__ram_w_en;
        CData/*0:0*/ mem__DOT__use_mem_output;
        CData/*3:0*/ mem__DOT__insn_type_r;
        CData/*0:0*/ writeback__DOT__clk;
        CData/*3:0*/ writeback__DOT__insn_type;
        CData/*4:0*/ writeback__DOT__rd;
        CData/*4:0*/ writeback__DOT__regfile_w_reg;
        CData/*0:0*/ writeback__DOT__regfile_w_en;
        CData/*4:0*/ writeback__DOT__wb_bp_reg;
        IData/*29:0*/ ram_r1_addr;
        IData/*31:0*/ ram_r1_val;
        IData/*29:0*/ ram_r2_addr;
        IData/*31:0*/ ram_r2_val;
        IData/*29:0*/ ram_w_addr;
        IData/*31:0*/ ram_w_val;
        IData/*31:0*/ regfile_r1_val;
        IData/*31:0*/ regfile_r2_val;
        IData/*31:0*/ regfile_w_val;
        IData/*31:0*/ ex_pc_offset;
        IData/*31:0*/ ex_pc_base;
        IData/*31:0*/ insn;
        IData/*31:0*/ pc_de;
        IData/*31:0*/ imm;
        IData/*31:0*/ pc_ex;
        IData/*31:0*/ wb_ex_bypass_val;
        IData/*31:0*/ mem_ex_bypass_val;
        IData/*31:0*/ ex2mem_val;
        IData/*31:0*/ ex_store_val;
        IData/*31:0*/ wb_val;
        IData/*29:0*/ ram__DOT__r1_addr_e;
        IData/*31:0*/ ram__DOT__r1_val;
        IData/*29:0*/ ram__DOT__r2_addr_e;
        IData/*31:0*/ ram__DOT__r2_val;
        IData/*29:0*/ ram__DOT__w_addr_e;
        IData/*31:0*/ ram__DOT__w_val;
        IData/*16:0*/ ram__DOT__r1_addr;
        IData/*16:0*/ ram__DOT__r2_addr;
        IData/*16:0*/ ram__DOT__w_addr;
        IData/*16:0*/ ram__DOT__last_w_addr;
        IData/*31:0*/ ram__DOT__i;
    };
    struct {
        IData/*31:0*/ regfile__DOT__r1_reg_val;
        IData/*31:0*/ regfile__DOT__r2_reg_val;
        IData/*31:0*/ regfile__DOT__w_reg_val;
        IData/*31:0*/ fetch__DOT__pc_ex_off;
        IData/*31:0*/ fetch__DOT__pc_ex_base;
        IData/*31:0*/ fetch__DOT__mem_data;
        IData/*29:0*/ fetch__DOT__mem_addr;
        IData/*31:0*/ fetch__DOT__insn;
        IData/*31:0*/ fetch__DOT__pc_de;
        IData/*31:0*/ fetch__DOT__pc;
        IData/*31:0*/ fetch__DOT__pc_prev;
        IData/*31:0*/ fetch__DOT__prev_insn;
        IData/*31:0*/ decoder__DOT__insn;
        IData/*31:0*/ decoder__DOT__pc;
        IData/*31:0*/ decoder__DOT__pc_de;
        IData/*31:0*/ decoder__DOT__imm;
        IData/*31:0*/ decoder__DOT__u_imm;
        IData/*31:0*/ decoder__DOT__i_imm;
        IData/*31:0*/ decoder__DOT__j_imm;
        IData/*31:0*/ decoder__DOT__b_imm;
        IData/*31:0*/ decoder__DOT__s_imm;
        IData/*31:0*/ decoder__DOT__shamt;
        IData/*24:0*/ decoder__DOT__ecall_ebreak_field;
        IData/*31:0*/ exec__DOT__rs1_regfile_val;
        IData/*31:0*/ exec__DOT__rs2_regfile_val;
        IData/*31:0*/ exec__DOT__pc_de;
        IData/*31:0*/ exec__DOT__imm;
        IData/*31:0*/ exec__DOT__bp_wb_val;
        IData/*31:0*/ exec__DOT__bp_mem_val;
        IData/*31:0*/ exec__DOT__next_stage_val;
        IData/*31:0*/ exec__DOT__pc_offset;
        IData/*31:0*/ exec__DOT__pc_base;
        IData/*31:0*/ exec__DOT__store_val;
        IData/*31:0*/ exec__DOT__ex_bp_val;
        IData/*31:0*/ exec__DOT__next_valid_pc;
        IData/*31:0*/ exec__DOT__w_alu_res;
        IData/*31:0*/ exec__DOT__alu_rs1;
        IData/*31:0*/ exec__DOT__alu_rs2;
        IData/*31:0*/ exec__DOT__rs1_actual;
        IData/*31:0*/ exec__DOT__rs2_actual;
        IData/*31:0*/ exec__DOT__alu__DOT__op1;
        IData/*31:0*/ exec__DOT__alu__DOT__op2;
        IData/*31:0*/ exec__DOT__alu__DOT__res;
        IData/*31:0*/ exec__DOT__alu__DOT__xres;
        IData/*31:0*/ mem__DOT__ex_val;
        IData/*31:0*/ mem__DOT__store_val;
        IData/*31:0*/ mem__DOT__wb_val;
        IData/*31:0*/ mem__DOT__bp_mem_val;
        IData/*29:0*/ mem__DOT__ram_r_addr;
        IData/*29:0*/ mem__DOT__ram_w_addr;
        IData/*31:0*/ mem__DOT__ram_w_data;
        IData/*31:0*/ writeback__DOT__ex_val;
        IData/*31:0*/ writeback__DOT__mem_r_data;
        IData/*31:0*/ writeback__DOT__regfile_w_data;
        IData/*31:0*/ writeback__DOT__wb_bp_val;
        VlUnpacked<IData/*31:0*/, 65537> ram__DOT__data;
        VlUnpacked<IData/*31:0*/, 32> regfile__DOT__regs;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vtop_top(const char* name);
    ~Vtop_top();
    VL_UNCOPYABLE(Vtop_top);

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
