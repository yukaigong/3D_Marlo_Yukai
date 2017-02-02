#ifndef __c36_Walking_ATRIAS_h__
#define __c36_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc36_Walking_ATRIASInstanceStruct
#define typedef_SFc36_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c36_sfEvent;
  boolean_T c36_isStable;
  boolean_T c36_doneDoubleBufferReInit;
  uint8_T c36_is_active_c36_Walking_ATRIAS;
  real_T (*c36_adc_value)[6];
  real_T (*c36_logicVoltage)[6];
} SFc36_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc36_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c36_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c36_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c36_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
