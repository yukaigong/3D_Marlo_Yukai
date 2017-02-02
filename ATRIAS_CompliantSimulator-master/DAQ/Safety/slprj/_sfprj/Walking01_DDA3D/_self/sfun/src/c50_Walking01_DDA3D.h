#ifndef __c50_Walking01_DDA3D_h__
#define __c50_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc50_Walking01_DDA3DInstanceStruct
#define typedef_SFc50_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c50_sfEvent;
  boolean_T c50_isStable;
  boolean_T c50_doneDoubleBufferReInit;
  uint8_T c50_is_active_c50_Walking01_DDA3D;
  real_T (*c50_params)[9];
  real_T (*c50_u)[6];
  real_T (*c50_y)[6];
  boolean_T *c50_Reset;
} SFc50_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc50_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c50_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c50_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c50_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
