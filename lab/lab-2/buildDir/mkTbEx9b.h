/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Sun Sep 10 13:14:01 UTC 2023
 * 
 */

/* Generation options: keep-fires */
#ifndef __mkTbEx9b_h__
#define __mkTbEx9b_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkTbEx9b module */
class MOD_mkTbEx9b : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_mod_i;
  MOD_Reg<tUWide> INST_mod_m_neg;
  MOD_Reg<tUWide> INST_mod_m_pos;
  MOD_Reg<tUWide> INST_mod_p;
  MOD_Reg<tUInt32> INST_tb_cycle;
  MOD_Reg<tUInt32> INST_tb_feed_count;
  MOD_Fifo<tUInt64> INST_tb_operands_fifo;
  MOD_Wire<tUInt32> INST_tb_randomA_ignore;
  MOD_Reg<tUInt8> INST_tb_randomA_initialized;
  MOD_Wire<tUInt32> INST_tb_randomA_zaz;
  MOD_Wire<tUInt32> INST_tb_randomB_ignore;
  MOD_Reg<tUInt8> INST_tb_randomB_initialized;
  MOD_Wire<tUInt32> INST_tb_randomB_zaz;
  MOD_Reg<tUInt32> INST_tb_read_count;
 
 /* Constructor */
 public:
  MOD_mkTbEx9b(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_WILL_FIRE_RL_tb_randomB_every_1;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomB_every_1;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomB_every;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomB_every;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomA_every_1;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomA_every_1;
  tUInt8 DEF_WILL_FIRE_RL_tb_randomA_every;
  tUInt8 DEF_CAN_FIRE_RL_tb_randomA_every;
  tUInt8 DEF_WILL_FIRE_RL_tb_monitor_test;
  tUInt8 DEF_CAN_FIRE_RL_tb_monitor_test;
  tUInt8 DEF_WILL_FIRE_RL_tb_read;
  tUInt8 DEF_CAN_FIRE_RL_tb_read;
  tUInt8 DEF_WILL_FIRE_RL_tb_feed;
  tUInt8 DEF_CAN_FIRE_RL_tb_feed;
  tUInt8 DEF_WILL_FIRE_RL_mod_mul_step;
  tUInt8 DEF_CAN_FIRE_RL_mod_mul_step;
  tUInt32 DEF_x_wget__h1044;
  tUInt8 DEF_x__h630;
  tUInt32 DEF_x__h3110;
  tUInt32 DEF_x__h2549;
  tUInt32 DEF_x_wget__h1458;
  tUInt8 DEF_tb_randomA_zaz_whas____d36;
  tUInt32 DEF_v__h1212;
  tUInt32 DEF_v__h1625;
  tUInt32 DEF_IF_tb_randomA_zaz_whas__6_THEN_tb_randomA_zaz__ETC___d38;
  tUInt8 DEF_tb_read_count_2_EQ_128___d73;
  tUInt8 DEF_IF_tb_randomA_zaz_whas__6_THEN_IF_tb_randomA_z_ETC___d46;
  tUInt8 DEF_IF_tb_randomB_zaz_whas__3_THEN_tb_randomB_zaz__ETC___d47;
 
 /* Local definitions */
 private:
  tUWide DEF_y__h304;
  tUWide DEF_y__h537;
  tUWide DEF_IF_mod_p_BITS_2_TO_0_EQ_0b1_OR_mod_p_BITS_2_TO_ETC___d31;
  tUWide DEF_x__h263;
  tUWide DEF_x__h349;
  tUWide DEF_x__h511;
  tUWide DEF_x__h560;
  tUWide DEF_x__h427;
  tUWide DEF_a__h530;
  tUWide DEF_a__h446;
  tUWide DEF_a__h282;
  tUWide DEF_a__h368;
  tUWide DEF_y__h453;
  tUWide DEF_y__h375;
  tUInt8 DEF_x__h626;
  tUInt32 DEF_new_value__h1594;
  tUInt32 DEF_new_value__h1180;
  tUWide DEF_mod_p__h2656;
  tUWide DEF_mod_m_neg_BITS_64_TO_0___h463;
  tUWide DEF_mod_m_pos_BITS_64_TO_0___h384;
  tUWide DEF_SEXT_tb_operands_fifo_first__9_BITS_63_TO_32_0_ETC___d84;
  tUWide DEF_x__h1891;
  tUWide DEF_x__h1924;
  tUWide DEF_x__h2217;
 
 /* Rules */
 public:
  void RL_mod_mul_step();
  void RL_tb_randomA_every();
  void RL_tb_randomA_every_1();
  void RL_tb_randomB_every();
  void RL_tb_randomB_every_1();
  void RL_tb_feed();
  void RL_tb_read();
  void RL_tb_monitor_test();
 
 /* Methods */
 public:
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkTbEx9b &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkTbEx9b &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkTbEx9b &backing);
};

#endif /* ifndef __mkTbEx9b_h__ */