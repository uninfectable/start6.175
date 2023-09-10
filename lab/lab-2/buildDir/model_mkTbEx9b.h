/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Sun Sep 10 13:16:15 UTC 2023
 * 
 */

/* Generation options: keep-fires */
#ifndef __model_mkTbEx9b_h__
#define __model_mkTbEx9b_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTbEx9b.h"

/* Class declaration for a model of mkTbEx9b */
class MODEL_mkTbEx9b : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTbEx9b *mkTbEx9b_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTbEx9b();
 
 /* Functions required by the kernel */
 public:
  void create_model(tSimStateHdl simHdl, bool master);
  void destroy_model();
  void reset_model(bool asserted);
  void get_version(char const **name, char const **build);
  time_t get_creation_time();
  void * get_instance();
  void dump_state();
  void dump_VCD_defs();
  void dump_VCD(tVCDDumpType dt);
};

/* Function for creating a new model */
extern "C" {
  void * new_MODEL_mkTbEx9b();
}

#endif /* ifndef __model_mkTbEx9b_h__ */