/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Sun Sep 10 13:17:09 UTC 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTbEx9a.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTbEx9a::MODEL_mkTbEx9a()
{
  mkTbEx9a_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTbEx9a()
{
  MODEL_mkTbEx9a *model = new MODEL_mkTbEx9a();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTbEx9a &INST_top = *((MOD_mkTbEx9a *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_tb_randomA_initialized__h1245;
	 tUInt8 DEF_INST_top_DEF_tb_randomB_initialized__h1697;
	 INST_top.DEF_x__h630 = INST_top.INST_mod_i.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_mod_mul_step = (INST_top.DEF_x__h630) < (tUInt8)32u;
	 INST_top.DEF_WILL_FIRE_RL_mod_mul_step = INST_top.DEF_CAN_FIRE_RL_mod_mul_step;
	 INST_top.DEF_CAN_FIRE_RL_tb_monitor_test = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_monitor_test = INST_top.DEF_CAN_FIRE_RL_tb_monitor_test;
	 INST_top.DEF_CAN_FIRE_RL_tb_randomA_every = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomA_every = INST_top.DEF_CAN_FIRE_RL_tb_randomA_every;
	 DEF_INST_top_DEF_tb_randomA_initialized__h1245 = INST_top.INST_tb_randomA_initialized.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1 = !DEF_INST_top_DEF_tb_randomA_initialized__h1245;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomA_every_1 = INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1;
	 DEF_INST_top_DEF_tb_randomB_initialized__h1697 = INST_top.INST_tb_randomB_initialized.METH_read();
	 INST_top.DEF_CAN_FIRE_RL_tb_randomB_every_1 = !DEF_INST_top_DEF_tb_randomB_initialized__h1697;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomB_every_1 = INST_top.DEF_CAN_FIRE_RL_tb_randomB_every_1;
	 INST_top.DEF_CAN_FIRE_RL_tb_randomB_every = (tUInt8)1u;
	 INST_top.DEF_WILL_FIRE_RL_tb_randomB_every = INST_top.DEF_CAN_FIRE_RL_tb_randomB_every;
	 INST_top.DEF_x__h3636 = INST_top.INST_tb_read_count.METH_read();
	 INST_top.DEF_tb_read_count_6_EQ_128___d77 = (INST_top.DEF_x__h3636) == 128u;
	 INST_top.DEF_CAN_FIRE_RL_tb_read = INST_top.INST_tb_operands_fifo.METH_i_notEmpty() && (!(INST_top.DEF_tb_read_count_6_EQ_128___d77) && (INST_top.DEF_x__h630) == (tUInt8)32u);
	 INST_top.DEF_WILL_FIRE_RL_tb_read = INST_top.DEF_CAN_FIRE_RL_tb_read;
	 if (INST_top.DEF_WILL_FIRE_RL_mod_mul_step)
	   INST_top.RL_mod_mul_step();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomA_every)
	   INST_top.RL_tb_randomA_every();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomA_every_1)
	   INST_top.RL_tb_randomA_every_1();
	 if (INST_top.DEF_WILL_FIRE_RL_tb_randomB_every)
	   INST_top.RL_tb_randomB_every();
	 INST_top.DEF_x_wget__h1497 = INST_top.INST_tb_randomB_zaz.METH_wget();
	 INST_top.DEF_x_wget__h1044 = INST_top.INST_tb_randomA_zaz.METH_wget();
	 INST_top.DEF_x__h3075 = INST_top.INST_tb_feed_count.METH_read();
	 INST_top.DEF_tb_randomA_zaz_whas____d38 = INST_top.INST_tb_randomA_zaz.METH_whas();
	 INST_top.DEF_v__h1703 = INST_top.INST_tb_randomB_zaz.METH_whas() ? INST_top.DEF_x_wget__h1497 : 0llu;
	 INST_top.DEF_IF_tb_randomA_zaz_whas__8_THEN_tb_randomA_zaz__ETC___d40 = INST_top.DEF_x_wget__h1044;
	 INST_top.DEF_v__h1251 = INST_top.DEF_tb_randomA_zaz_whas____d38 ? INST_top.DEF_IF_tb_randomA_zaz_whas__8_THEN_tb_randomA_zaz__ETC___d40 : 0llu;
	 INST_top.DEF_IF_tb_randomA_zaz_whas__8_THEN_IF_tb_randomA_z_ETC___d50 = (INST_top.DEF_v__h1251) == 9223372036854775808llu;
	 INST_top.DEF_IF_tb_randomB_zaz_whas__7_THEN_tb_randomB_zaz__ETC___d51 = (INST_top.DEF_v__h1703) == 9223372036854775808llu;
	 INST_top.DEF_CAN_FIRE_RL_tb_feed = ((DEF_INST_top_DEF_tb_randomA_initialized__h1245 && (DEF_INST_top_DEF_tb_randomB_initialized__h1697 && ((INST_top.DEF_IF_tb_randomA_zaz_whas__8_THEN_IF_tb_randomA_z_ETC___d50 || INST_top.DEF_IF_tb_randomB_zaz_whas__7_THEN_tb_randomB_zaz__ETC___d51) || INST_top.INST_tb_operands_fifo.METH_i_notFull()))) && (!((INST_top.DEF_x__h3075) == 128u) && (INST_top.DEF_x__h630) == (tUInt8)33u)) && !(INST_top.DEF_CAN_FIRE_RL_tb_randomA_every_1 || INST_top.DEF_CAN_FIRE_RL_mod_mul_step);
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

void MODEL_mkTbEx9a::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTbEx9a_instance = new MOD_mkTbEx9a(sim_hdl, "top", NULL);
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
  (mkTbEx9a_instance->INST_tb_operands_fifo.set_clk_0)("CLK");
  (mkTbEx9a_instance->INST_tb_randomA_ignore.set_clk_0)("CLK");
  (mkTbEx9a_instance->INST_tb_randomA_zaz.set_clk_0)("CLK");
  (mkTbEx9a_instance->INST_tb_randomB_ignore.set_clk_0)("CLK");
  (mkTbEx9a_instance->INST_tb_randomB_zaz.set_clk_0)("CLK");
  (mkTbEx9a_instance->set_clk_0)("CLK");
}
void MODEL_mkTbEx9a::destroy_model()
{
  delete mkTbEx9a_instance;
  mkTbEx9a_instance = NULL;
}
void MODEL_mkTbEx9a::reset_model(bool asserted)
{
  (mkTbEx9a_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTbEx9a::get_instance()
{
  return mkTbEx9a_instance;
}

/* Fill in version numbers */
void MODEL_mkTbEx9a::get_version(char const **name, char const **build)
{
  *name = "2023.01";
  *build = "52adafa5";
}

/* Get the model creation time */
time_t MODEL_mkTbEx9a::get_creation_time()
{
  
  /* Sun Sep 10 13:17:09 UTC 2023 */
  return 1694351829llu;
}

/* State dumping function */
void MODEL_mkTbEx9a::dump_state()
{
  (mkTbEx9a_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTbEx9a & mkTbEx9a_backing(tSimStateHdl simHdl)
{
  static MOD_mkTbEx9a *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTbEx9a(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTbEx9a::dump_VCD_defs()
{
  (mkTbEx9a_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTbEx9a::dump_VCD(tVCDDumpType dt)
{
  (mkTbEx9a_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTbEx9a_backing(sim_hdl));
}