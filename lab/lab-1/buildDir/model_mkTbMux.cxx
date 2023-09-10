/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Wed Sep  6 08:43:31 UTC 2023
 * 
 */
#include "bluesim_primitives.h"
#include "model_mkTbMux.h"

#include <cstdlib>
#include <time.h>
#include "bluesim_kernel_api.h"
#include "bs_vcd.h"
#include "bs_reset.h"


/* Constructor */
MODEL_mkTbMux::MODEL_mkTbMux()
{
  mkTbMux_instance = NULL;
}

/* Function for creating a new model */
void * new_MODEL_mkTbMux()
{
  MODEL_mkTbMux *model = new MODEL_mkTbMux();
  return (void *)(model);
}

/* Schedule functions */

static void schedule_posedge_CLK(tSimStateHdl simHdl, void *instance_ptr)
       {
	 MOD_mkTbMux &INST_top = *((MOD_mkTbMux *)(instance_ptr));
	 tUInt8 DEF_INST_top_DEF_randomSel_initialized__h1131;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every_1;
	 tUInt8 DEF_INST_top_DEF_randomVal1_initialized__h383;
	 tUInt8 DEF_INST_top_DEF_randomVal2_initialized__h758;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every_1;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every_1;
	 tUInt8 DEF_INST_top_DEF_CAN_FIRE_RL_test;
	 tUInt8 DEF_INST_top_DEF_WILL_FIRE_RL_test;
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every = DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every;
	 DEF_INST_top_DEF_randomSel_initialized__h1131 = INST_top.INST_randomSel_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every_1 = !DEF_INST_top_DEF_randomSel_initialized__h1131;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_randomSel_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every = DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every;
	 DEF_INST_top_DEF_randomVal1_initialized__h383 = INST_top.INST_randomVal1_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every_1 = !DEF_INST_top_DEF_randomVal1_initialized__h383;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_randomVal1_every_1;
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every = (tUInt8)1u;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every = DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every;
	 DEF_INST_top_DEF_randomVal2_initialized__h758 = INST_top.INST_randomVal2_initialized.METH_read();
	 DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every_1 = !DEF_INST_top_DEF_randomVal2_initialized__h758;
	 DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every_1 = DEF_INST_top_DEF_CAN_FIRE_RL_randomVal2_every_1;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every)
	   INST_top.RL_randomVal1_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomVal1_every_1)
	   INST_top.RL_randomVal1_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every)
	   INST_top.RL_randomVal2_every();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every)
	   INST_top.RL_randomSel_every();
	 INST_top.DEF_x_wget__h1007 = INST_top.INST_randomSel_zaz.METH_wget();
	 INST_top.DEF_randomSel_zaz_whas____d19 = INST_top.INST_randomSel_zaz.METH_whas();
	 INST_top.DEF_x__h1350 = INST_top.INST_cycle.METH_read();
	 INST_top.DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 = !(INST_top.DEF_randomSel_zaz_whas____d19) || !(INST_top.DEF_x_wget__h1007);
	 INST_top.DEF_cycle_2_EQ_128___d24 = (INST_top.DEF_x__h1350) == 128u;
	 INST_top.DEF_cycle_2_EQ_0___d23 = (INST_top.DEF_x__h1350) == 0u;
	 DEF_INST_top_DEF_CAN_FIRE_RL_test = INST_top.DEF_cycle_2_EQ_0___d23 || (INST_top.DEF_cycle_2_EQ_128___d24 || (DEF_INST_top_DEF_randomVal1_initialized__h383 && (DEF_INST_top_DEF_randomVal2_initialized__h758 && (DEF_INST_top_DEF_randomSel_initialized__h1131 && (INST_top.DEF_NOT_randomSel_zaz_whas__9_5_OR_NOT_randomSel_z_ETC___d27 ? DEF_INST_top_DEF_randomVal1_initialized__h383 : DEF_INST_top_DEF_randomVal2_initialized__h758)))));
	 DEF_INST_top_DEF_WILL_FIRE_RL_test = DEF_INST_top_DEF_CAN_FIRE_RL_test;
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomSel_every_1)
	   INST_top.RL_randomSel_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_randomVal2_every_1)
	   INST_top.RL_randomVal2_every_1();
	 if (DEF_INST_top_DEF_WILL_FIRE_RL_test)
	   INST_top.RL_test();
	 INST_top.INST_randomSel_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_randomSel_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_randomVal2_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_randomVal2_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_randomVal1_zaz.clk((tUInt8)1u, (tUInt8)1u);
	 INST_top.INST_randomVal1_ignore.clk((tUInt8)1u, (tUInt8)1u);
	 if (do_reset_ticks(simHdl))
	 {
	   INST_top.INST_cycle.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_randomVal1_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_randomVal2_initialized.rst_tick__clk__1((tUInt8)1u);
	   INST_top.INST_randomSel_initialized.rst_tick__clk__1((tUInt8)1u);
	 }
       };

/* Model creation/destruction functions */

void MODEL_mkTbMux::create_model(tSimStateHdl simHdl, bool master)
{
  sim_hdl = simHdl;
  init_reset_request_counters(sim_hdl);
  mkTbMux_instance = new MOD_mkTbMux(sim_hdl, "top", NULL);
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
  (mkTbMux_instance->INST_randomVal1_ignore.set_clk_0)("CLK");
  (mkTbMux_instance->INST_randomVal1_zaz.set_clk_0)("CLK");
  (mkTbMux_instance->INST_randomVal2_ignore.set_clk_0)("CLK");
  (mkTbMux_instance->INST_randomVal2_zaz.set_clk_0)("CLK");
  (mkTbMux_instance->INST_randomSel_ignore.set_clk_0)("CLK");
  (mkTbMux_instance->INST_randomSel_zaz.set_clk_0)("CLK");
  (mkTbMux_instance->set_clk_0)("CLK");
}
void MODEL_mkTbMux::destroy_model()
{
  delete mkTbMux_instance;
  mkTbMux_instance = NULL;
}
void MODEL_mkTbMux::reset_model(bool asserted)
{
  (mkTbMux_instance->reset_RST_N)(asserted ? (tUInt8)0u : (tUInt8)1u);
}
void * MODEL_mkTbMux::get_instance()
{
  return mkTbMux_instance;
}

/* Fill in version numbers */
void MODEL_mkTbMux::get_version(char const **name, char const **build)
{
  *name = "2023.01";
  *build = "52adafa5";
}

/* Get the model creation time */
time_t MODEL_mkTbMux::get_creation_time()
{
  
  /* Wed Sep  6 08:43:31 UTC 2023 */
  return 1693989811llu;
}

/* State dumping function */
void MODEL_mkTbMux::dump_state()
{
  (mkTbMux_instance->dump_state)(0u);
}

/* VCD dumping functions */
MOD_mkTbMux & mkTbMux_backing(tSimStateHdl simHdl)
{
  static MOD_mkTbMux *instance = NULL;
  if (instance == NULL)
  {
    vcd_set_backing_instance(simHdl, true);
    instance = new MOD_mkTbMux(simHdl, "top", NULL);
    vcd_set_backing_instance(simHdl, false);
  }
  return *instance;
}
void MODEL_mkTbMux::dump_VCD_defs()
{
  (mkTbMux_instance->dump_VCD_defs)(vcd_depth(sim_hdl));
}
void MODEL_mkTbMux::dump_VCD(tVCDDumpType dt)
{
  (mkTbMux_instance->dump_VCD)(dt, vcd_depth(sim_hdl), mkTbMux_backing(sim_hdl));
}
