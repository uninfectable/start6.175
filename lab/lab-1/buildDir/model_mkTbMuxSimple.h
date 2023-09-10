/*
 * Generated by Bluespec Compiler, version 2023.01 (build 52adafa5)
 * 
 * On Wed Sep  6 08:43:33 UTC 2023
 * 
 */

/* Generation options: */
#ifndef __model_mkTbMuxSimple_h__
#define __model_mkTbMuxSimple_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"

#include "bs_model.h"
#include "mkTbMuxSimple.h"

/* Class declaration for a model of mkTbMuxSimple */
class MODEL_mkTbMuxSimple : public Model {
 
 /* Top-level module instance */
 private:
  MOD_mkTbMuxSimple *mkTbMuxSimple_instance;
 
 /* Handle to the simulation kernel */
 private:
  tSimStateHdl sim_hdl;
 
 /* Constructor */
 public:
  MODEL_mkTbMuxSimple();
 
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
  void * new_MODEL_mkTbMuxSimple();
}

#endif /* ifndef __model_mkTbMuxSimple_h__ */
