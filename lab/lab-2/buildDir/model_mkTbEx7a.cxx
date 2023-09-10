/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Sun Sep 10 12:45:51 UTC 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTbEx7a.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTbEx7a::MODEL_mkTbEx7a()
{
  mkTbEx7a_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTbEx7a()
{
  MODEL_mkTbEx7a *model = new MODEL_mkTbEx7a();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTbEx7a &INST_top = *((MOD_mkTbEx7a *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_tb_randomA_initialized__h967;
	 tUInt8 DEF_INST_top_DEF_tb_randomB_initialized__h1343;
	 INST_top.DEF__read__h138 = INST_top.INST_mod_i.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_mod_mul_step = (INST_top.DEF__read__h138) < (tUInt8)8u;
	 INST_top.DEF_WILL_FIRE_RL_mod_mul_step = INST_top.DEF_CAN_FIRE_RL_mod_mul_step;
	 INST_top.DEF_CAN_FIRE_RL_tb_monitor_test = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_monitor_test = INST_top.DEF_CAN_FIRE_RL_tb_monitor_test;
	 INST_top.DEF_CAN_FIRE_RL_tb_randomA_every = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomA_every = INST_top.DEF_CAN_FIRE_RL_tb_randomA_every;
	 DEF_INST_top_DEF_tb_randomA_initialized__h967 = INST_top.INST_tb_randomA_initialized.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1 = !DEF_INST_top_DEF_tb_randomA_initialized__h967;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomA_every_1 = INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1;
	 DEF_INST_top_DEF_tb_randomB_initialized__h1343 = INST_top.INST_tb_randomB_initialized.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_tb_randomB_every_1 = !DEF_INST_top_DEF_tb_randomB_initialized__h1343;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomB_every_1 = INST_top.DEF_CAN_FIRE_RL_tb_randomB_every_1;
	 INST_top.DEF_CAN_FIRE_RL_tb_randomB_every = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomB_every = INST_top.DEF_CAN_FIRE_RL_tb_randomB_every;
	 INST_top.DEF_x__h2279 = INST_top.INST_tb_read_count.METH_read();
	 INST_top.DEF_tb_read_count_6_EQ_128___d57 = (INST_top.DEF_x__h2279) == 128u;
	 INST_top.DEF_CAN_FIRE_RL_tb_read = INST_top.INST_tb_operands_fifo.METH_i_notEmpty() && (!(INST_top.DEF_tb_read_count_6_EQ_128___d57) && (INST_top.DEF__read__h138) == (tUInt8)8u);
	 INST_top.DEF_WILL_FIRE_RL_tb_read = INST_top.DEF_CAN_FIRE_RL_tb_read;
	 if (INST_top.DEF_WILL_FIRE_RL_mod_mul_step)
	   INST_top.RL_mod_mul_step();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomA_every)
	   INST_top.RL_tb_randomA_every();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomA_every_1)
	   INST_top.RL_tb_randomA_every_1();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomB_every)
	   INST_top.RL_tb_randomB_every();
	 INST_top.DEF_x__h1722 = INST_top.INST_tb_feed_count.METH_read();
	 INST_top.DEF_x_wget__h1219 = INST_top.INST_tb_randomB_zaz.METH_wget();
	 INST_top.DEF_x_wget__h842 = INST_top.INST_tb_randomA_zaz.METH_wget();
	 INST_top.DEF_tb_randomA_zaz_whas____d21 = INST_top.INST_tb_randomA_zaz.METH_whas();
	 INST_top.DEF_IF_tb_randomA_zaz_whas__1_THEN_tb_randomA_zaz__ETC___d23 = INST_top.DEF_x_wget__h842;
	 INST_top.DEF_v__h973 = INST_top.DEF_tb_randomA_zaz_whas____d21 ? INST_top.DEF_IF_tb_randomA_zaz_whas__1_THEN_tb_randomA_zaz__ETC___d23 : (tUInt8)0u;
	 INST_top.DEF_v__h1349 = INST_top.INST_tb_randomB_zaz.METH_whas() ? INST_top.DEF_x_wget__h1219 : (tUInt8)0u;
	 INST_top.DEF_IF_tb_randomB_zaz_whas__9_THEN_tb_randomB_zaz__ETC___d33 = (INST_top.DEF_v__h1349) == (tUInt8)128u;
	 INST_top.DEF_IF_tb_randomA_zaz_whas__1_THEN_IF_tb_randomA_z_ETC___d32 = (INST_top.DEF_v__h973) == (tUInt8)128u;
	 INST_top.DEF_CAN_FIRE_RL_tb_feed = ((DEF_INST_top_DEF_tb_randomA_initialized__h967 && (DEF_INST_top_DEF_tb_randomB_initialized__h1343 && ((INST_top.DEF_IF_tb_randomA_zaz_whas__1_THEN_IF_tb_randomA_z_ETC___d32 || INST_top.DEF_IF_tb_randomB_zaz_whas__9_THEN_tb_randomB_zaz__ETC___d33) || INST_top.INST_tb_operands_fifo.METH_i_notFull()))) && (!((INST_top.DEF_x__h1722) == 128u) && (INST_top.DEF__read__h138) == (tUInt8)9u)) && !(INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1 || INST_top.DEF_CAN_FIRE_RL_mod_mul_step);
	 INST_top.DEF_WILL_FIRE_RL_tb_feed = INST_top.DEF_CAN_FIRE_RL_tb_feed;
	 if (INST_top.DEF_WILL_FIRE_RL_tb_feed)
	   INST_top.RL_tb_feed();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomB_every_1)
	   INST_top.RL_tb_randomB_every_1();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_monitor_test)
	   INST_top.RL_tb_monitor_test();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_read)
	   INST_top.RL_tb_read();
	 INST_top.INST_tb_randomB_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_tb_randomB_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_tb_randomA_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_tb_randomA_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_mod_i.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tb_cycle.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tb_feed_count.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tb_read_count.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tb_operands_fifo.rst_tick_clk((tUInt8)1u);
	   INST_top.INST_tb_randomA_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_tb_randomB_initialized.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTbEx7a::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTbEx7a_instance = new MOD_mkTbEx7a(sim_hdl, "top", NULL);
  bk_get_or_define_clock(sim_hdl, "CLK");
  if (master)
  {
    bk_alter_clock(sim_hdl, bk_get_clock_by_name(sim_hdl, "CLK"), CLK_LOW, false, 0llu, 5llu, 5llu);
    bk_use_default_reset(sim_hdl);
  }
  bk_set_clock_event_fn(sim_hdl,
			bk_get_clock_by_name(sim_hdl, "CLK"),
			schedule_posedge_CLK,
			NULL,
			(tEdgeDirection)(POSEDGE));
  (mkTbEx7a_instance->INST_tb_operands_fifo.set_clk_0)("CLK");
  (mkTbEx7a_instance->INST_tb_randomA_ignore.set_clk_0)("CLK");
  (mkTbEx7a_instance->INST_tb_randomA_zaz.set_clk_0)("CLK");
  (mkTbEx7a_instance->INST_tb_randomB_ignore.set_clk_0)("CLK");
  (mkTbEx7a_instance->INST_tb_randomB_zaz.set_clk_0)("CLK");
  (mkTbEx7a_instance->set_clk_0)("CLK");
}
void MODEL_mkTbEx7a::destroy_model()
{
  delete mkTbEx7a_instance;
  mkTbEx7a_instance = NULL;
}
void MODEL_mkTbEx7a::reset_model(bool asserted)
{
  (mkTbEx7a_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTbEx7a::get_instance()
{
  return mkTbEx7a_instance;
}

/* Fill in version numbers */
void MODEL_mkTbEx7a::get_version(char const **name, char const **build)
{
  *name = "2023.01";
  *build = "52adafa5";
}

/* Get the model creation time */
time_t MODEL_mkTbEx7a::get_creation_time()
{
  
  /* Sun Sep 10 12:45:51 UTC 2023 */
  return 1694349951llu;
}

/* State dumping function */
void MODEL_mkTbEx7a::dump_state()
{
  (mkTbEx7a_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTbEx7a & mkTbEx7a_backing(tSimStateHdl simHdl)
{
  static MOD_mkTbEx7a *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTbEx7a(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTbEx7a::dump_VCD_defs()
{
  (mkTbEx7a_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTbEx7a::dump_VCD(tVCDDumpType dt)
{
  (mkTbEx7a_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTbEx7a_backing(sim_hdl));
}
