/* Include files */

#include <stddef.h>
#include "blas.h"
#include "LibWalking_sfun.h"
#include "c13_LibWalking.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LibWalking_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c13_debug_family_names[19] = { "weight", "u_LA_R", "u_LS_R",
  "u_LA_L", "u_LS_L", "uR", "uL", "T0", "u0", "deltaS", "KASaturationLim",
  "nargin", "nargout", "u", "s", "sat", "ControlState", "ControlParams", "u_sat"
};

static const char * c13_b_debug_family_names[7] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u_opt", "L_opt" };

static const char * c13_c_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u_opt", "L_opt" };

static const char * c13_d_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u_opt", "L_opt" };

static const char * c13_e_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_min", "u_opt", "L_opt" };

static const char * c13_f_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_max", "u_opt", "L_opt" };

static const char * c13_g_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_min", "u_opt", "L_opt" };

static const char * c13_h_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_max", "u_opt", "L_opt" };

static const char * c13_i_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_min", "u_opt", "L_opt" };

static const char * c13_j_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_max", "u_opt", "L_opt" };

static const char * c13_k_debug_family_names[32] = { "u_opt_1", "L_opt_1",
  "u_opt_2", "L_opt_2", "u_opt_3", "L_opt_3", "u_opt_4", "L_opt_4", "u_opt_5",
  "L_opt_5", "u_opt_6", "L_opt_6", "u_opt_7", "L_opt_7", "u_opt_8", "L_opt_8",
  "u_opt_9", "L_opt_9", "LB", "UB", "L_opt", "case_n", "nargin", "nargout",
  "u_LS", "u_LA", "w", "u1_min", "u1_max", "u2_min", "u2_max", "u_opt" };

/* Function Declarations */
static void initialize_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void initialize_params_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void enable_c13_LibWalking(SFc13_LibWalkingInstanceStruct *chartInstance);
static void disable_c13_LibWalking(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_LibWalking
  (SFc13_LibWalkingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_LibWalking
  (SFc13_LibWalkingInstanceStruct *chartInstance);
static void set_sim_state_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_st);
static void finalize_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void sf_gateway_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void mdl_start_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void c13_chartstep_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void initSimStructsc13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void c13_LA_LS_Revised_Saturation(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u1_max, real_T c13_u2_min, real_T c13_u2_max, real_T
  c13_u_opt[2]);
static void c13_LA_LS_Revised_Saturation_Case_1(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_2(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_3(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_4(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_5(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_6(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_7(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_8(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void c13_LA_LS_Revised_Saturation_Case_9(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4]);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u_sat, const char_T *c13_identifier, real_T c13_y[6]);
static void c13_b_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[6]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_c_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_d_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y
  [36]);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_e_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[2]);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_f_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4]);
static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_info_helper(const mxArray **c13_info);
static const mxArray *c13_emlrt_marshallOut(const char * c13_b_u);
static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_b_u);
static void c13_b_info_helper(const mxArray **c13_info);
static void c13_c_info_helper(const mxArray **c13_info);
static void c13_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_threshold(SFc13_LibWalkingInstanceStruct *chartInstance);
static real_T c13_rdivide(SFc13_LibWalkingInstanceStruct *chartInstance, real_T
  c13_x, real_T c13_y);
static void c13_eml_switch_helper(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_check_forloop_overflow_error(SFc13_LibWalkingInstanceStruct
  *chartInstance, boolean_T c13_overflow);
static void c13_b_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_c_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance);
static real_T c13_eml_xdotu(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_x[2], real_T c13_y[2]);
static void c13_realmin(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_eps(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_eml_matlab_zgetrf(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_b_A[36], int32_T c13_ipiv[6], int32_T *c13_info);
static int32_T c13_eml_ixamax(SFc13_LibWalkingInstanceStruct *chartInstance,
  int32_T c13_n, real_T c13_x[36], int32_T c13_ix0);
static void c13_b_eml_switch_helper(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void c13_eml_xgeru(SFc13_LibWalkingInstanceStruct *chartInstance, int32_T
  c13_m, int32_T c13_n, real_T c13_alpha1, int32_T c13_ix0, int32_T c13_iy0,
  real_T c13_A[36], int32_T c13_ia0, real_T c13_b_A[36]);
static void c13_eml_warning(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance, real_T
  c13_A[36], real_T c13_B[6], real_T c13_b_B[6]);
static void c13_below_threshold(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_c_eml_switch_helper(SFc13_LibWalkingInstanceStruct
  *chartInstance);
static void c13_scalarEg(SFc13_LibWalkingInstanceStruct *chartInstance);
static void c13_b_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6], real_T c13_b_B[6]);
static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_g_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_ControlState_bus_io(void *chartInstanceVoid, void
  *c13_pData);
static const mxArray *c13_ControlParams_bus_io(void *chartInstanceVoid, void
  *c13_pData);
static uint8_T c13_h_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_LibWalking, const char_T
  *c13_identifier);
static uint8_T c13_i_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_eml_matlab_zgetrf(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_A[36], int32_T c13_ipiv[6], int32_T *c13_info);
static void c13_b_eml_xgeru(SFc13_LibWalkingInstanceStruct *chartInstance,
  int32_T c13_m, int32_T c13_n, real_T c13_alpha1, int32_T c13_ix0, int32_T
  c13_iy0, real_T c13_A[36], int32_T c13_ia0);
static void c13_c_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6]);
static void c13_d_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6]);
static void init_dsm_address_info(SFc13_LibWalkingInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc13_LibWalkingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_is_active_c13_LibWalking = 0U;
}

static void initialize_params_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c13_LibWalking(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c13_LibWalking(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c13_update_debugger_state_c13_LibWalking
  (SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c13_LibWalking
  (SFc13_LibWalkingInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i0;
  real_T c13_b_u[6];
  const mxArray *c13_b_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_c_y = NULL;
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(2, 1), false);
  for (c13_i0 = 0; c13_i0 < 6; c13_i0++) {
    c13_b_u[c13_i0] = (*chartInstance->c13_u_sat)[c13_i0];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal = chartInstance->c13_is_active_c13_LibWalking;
  c13_c_u = c13_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_b_u;
  real_T c13_dv0[6];
  int32_T c13_i1;
  chartInstance->c13_doneDoubleBufferReInit = true;
  c13_b_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_b_u, 0)),
                       "u_sat", c13_dv0);
  for (c13_i1 = 0; c13_i1 < 6; c13_i1++) {
    (*chartInstance->c13_u_sat)[c13_i1] = c13_dv0[c13_i1];
  }

  chartInstance->c13_is_active_c13_LibWalking = c13_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_b_u, 1)),
     "is_active_c13_LibWalking");
  sf_mex_destroy(&c13_b_u);
  c13_update_debugger_state_c13_LibWalking(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  int32_T c13_i2;
  int32_T c13_i3;
  int32_T c13_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
  for (c13_i2 = 0; c13_i2 < 6; c13_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c13_u)[c13_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c13_s, 1U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  c13_chartstep_c13_LibWalking(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LibWalkingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c13_i3 = 0; c13_i3 < 6; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c13_u_sat)[c13_i3], 2U);
  }

  for (c13_i4 = 0; c13_i4 < 2; c13_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c13_sat)[c13_i4], 3U);
  }
}

static void mdl_start_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c13_chartstep_c13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  real_T c13_hoistedGlobal;
  int32_T c13_i5;
  real_T c13_b_u[6];
  real_T c13_b_s;
  int32_T c13_i6;
  real_T c13_b_sat[2];
  c13_ControlStateBus c13_b_ControlState;
  c13_ControlParamsBus c13_b_ControlParams;
  int32_T c13_i7;
  int32_T c13_i8;
  int32_T c13_i9;
  int32_T c13_i10;
  int32_T c13_i11;
  int32_T c13_i12;
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  int32_T c13_i16;
  int32_T c13_i17;
  int32_T c13_i18;
  int32_T c13_i19;
  int32_T c13_i20;
  int32_T c13_i21;
  int32_T c13_i22;
  int32_T c13_i23;
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_i26;
  int32_T c13_i27;
  int32_T c13_i28;
  int32_T c13_i29;
  int32_T c13_i30;
  int32_T c13_i31;
  int32_T c13_i32;
  int32_T c13_i33;
  int32_T c13_i34;
  int32_T c13_i35;
  int32_T c13_i36;
  int32_T c13_i37;
  int32_T c13_i38;
  int32_T c13_i39;
  int32_T c13_i40;
  int32_T c13_i41;
  int32_T c13_i42;
  int32_T c13_i43;
  int32_T c13_i44;
  int32_T c13_i45;
  int32_T c13_i46;
  int32_T c13_i47;
  int32_T c13_i48;
  int32_T c13_i49;
  int32_T c13_i50;
  int32_T c13_i51;
  int32_T c13_i52;
  int32_T c13_i53;
  uint32_T c13_debug_family_var_map[19];
  real_T c13_weight[2];
  real_T c13_u_LA_R;
  real_T c13_u_LS_R;
  real_T c13_u_LA_L;
  real_T c13_u_LS_L;
  real_T c13_uR[2];
  real_T c13_uL[2];
  real_T c13_T0[36];
  real_T c13_u0[6];
  real_T c13_deltaS;
  real_T c13_KASaturationLim;
  real_T c13_nargin = 5.0;
  real_T c13_nargout = 1.0;
  real_T c13_b_u_sat[6];
  int32_T c13_i54;
  int32_T c13_i55;
  int32_T c13_i56;
  real_T c13_b[2];
  int32_T c13_i57;
  int32_T c13_i58;
  int32_T c13_i59;
  real_T c13_C[2];
  int32_T c13_i60;
  int32_T c13_i61;
  int32_T c13_i62;
  int32_T c13_i63;
  int32_T c13_i64;
  int32_T c13_i65;
  static real_T c13_a[4] = { 0.0, 1.0, 1.0, 0.0 };

  real_T c13_A;
  real_T c13_b_A;
  real_T c13_dv1[2];
  int32_T c13_i66;
  real_T c13_dv2[2];
  int32_T c13_i67;
  int32_T c13_i68;
  int32_T c13_i69;
  int32_T c13_i70;
  static real_T c13_dv3[36] = { 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c13_i71;
  int32_T c13_i72;
  static int32_T c13_iv0[6] = { 1, 0, 3, 2, 5, 4 };

  real_T c13_b_T0[36];
  int32_T c13_i73;
  int32_T c13_i74;
  int32_T c13_i75;
  int32_T c13_i76;
  real_T c13_b_a[36];
  int32_T c13_i77;
  real_T c13_b_b[6];
  int32_T c13_i78;
  int32_T c13_i79;
  int32_T c13_i80;
  real_T c13_b_C[6];
  int32_T c13_i81;
  int32_T c13_i82;
  int32_T c13_i83;
  int32_T c13_i84;
  int32_T c13_i85;
  int32_T c13_i86;
  real_T c13_varargin_1;
  real_T c13_varargin_2;
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_xk;
  real_T c13_c_x;
  real_T c13_c_a[2];
  int32_T c13_i87;
  real_T c13_d_a[2];
  int32_T c13_i88;
  real_T c13_c_b[2];
  real_T c13_y;
  real_T c13_c_A;
  real_T c13_B;
  real_T c13_b_varargin_1;
  real_T c13_b_varargin_2;
  real_T c13_c_varargin_2;
  real_T c13_varargin_3;
  real_T c13_d_x;
  real_T c13_b_y;
  real_T c13_e_x;
  real_T c13_c_y;
  real_T c13_b_xk;
  real_T c13_yk;
  real_T c13_f_x;
  real_T c13_d_y;
  real_T c13_minval;
  real_T c13_c_varargin_1;
  real_T c13_d_varargin_2;
  real_T c13_e_varargin_2;
  real_T c13_b_varargin_3;
  real_T c13_g_x;
  real_T c13_e_y;
  real_T c13_h_x;
  real_T c13_f_y;
  real_T c13_c_xk;
  real_T c13_b_yk;
  real_T c13_i_x;
  real_T c13_g_y;
  real_T c13_maxval;
  int32_T c13_i89;
  int32_T c13_i90;
  int32_T c13_info;
  int32_T c13_ipiv[6];
  int32_T c13_b_info;
  int32_T c13_c_info;
  int32_T c13_d_info;
  int32_T c13_i91;
  int32_T c13_xi;
  int32_T c13_b_xi;
  int32_T c13_ip;
  real_T c13_temp;
  int32_T c13_i92;
  int32_T c13_i93;
  real_T c13_e_a[36];
  int32_T c13_i94;
  int32_T c13_i95;
  int32_T c13_i96;
  real_T c13_f_a[36];
  int32_T c13_i97;
  int32_T c13_i98;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
  c13_hoistedGlobal = *chartInstance->c13_s;
  for (c13_i5 = 0; c13_i5 < 6; c13_i5++) {
    c13_b_u[c13_i5] = (*chartInstance->c13_u)[c13_i5];
  }

  c13_b_s = c13_hoistedGlobal;
  for (c13_i6 = 0; c13_i6 < 2; c13_i6++) {
    c13_b_sat[c13_i6] = (*chartInstance->c13_sat)[c13_i6];
  }

  c13_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[0];
  c13_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[8];
  c13_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[16];
  c13_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[24];
  c13_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[32];
  c13_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[40];
  c13_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c13_ControlState)[48];
  c13_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [0];
  c13_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [8];
  c13_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [16];
  c13_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [24];
  c13_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[32];
  c13_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[40];
  c13_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [48];
  c13_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [56];
  c13_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [64];
  c13_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [72];
  c13_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[80];
  for (c13_i7 = 0; c13_i7 < 2; c13_i7++) {
    c13_b_ControlParams.Supervisory.KAInjection[c13_i7] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [0])[88])[c13_i7];
  }

  c13_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [0])[104];
  c13_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [112];
  for (c13_i8 = 0; c13_i8 < 6; c13_i8++) {
    c13_b_ControlParams.Supervisory.VBLAParams[c13_i8] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [0])[120])[c13_i8];
  }

  for (c13_i9 = 0; c13_i9 < 13; c13_i9++) {
    c13_b_ControlParams.Supervisory.BalanceParams[c13_i9] = ((real_T *)&((char_T
      *)(c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [0])[168])[c13_i9];
  }

  for (c13_i10 = 0; c13_i10 < 5; c13_i10++) {
    c13_b_ControlParams.Supervisory.GaitTweaks[c13_i10] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [0])[272])[c13_i10];
  }

  c13_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [312];
  c13_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [320];
  c13_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [328];
  c13_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [336];
  for (c13_i11 = 0; c13_i11 < 6; c13_i11++) {
    c13_b_ControlParams.Supervisory.ErrorZeroFactor[c13_i11] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[344])[c13_i11];
  }

  for (c13_i12 = 0; c13_i12 < 6; c13_i12++) {
    c13_b_ControlParams.Supervisory.ErrorVelZeroFactor[c13_i12] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[392])[c13_i12];
  }

  c13_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [440];
  c13_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [448];
  c13_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [456];
  c13_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [464];
  c13_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [472];
  c13_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [480];
  c13_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [488];
  c13_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [496];
  c13_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [0])[504];
  c13_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [0])[512];
  c13_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[520];
  c13_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [528];
  c13_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [536];
  c13_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [544];
  c13_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [552];
  c13_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [560];
  c13_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [0])[568];
  c13_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [576];
  c13_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [584];
  c13_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [592];
  c13_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [600];
  for (c13_i13 = 0; c13_i13 < 6; c13_i13++) {
    c13_b_ControlParams.Supervisory.K1MidStanceUpdate[c13_i13] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[608])[c13_i13];
  }

  for (c13_i14 = 0; c13_i14 < 6; c13_i14++) {
    c13_b_ControlParams.Supervisory.K2MidStanceUpdate[c13_i14] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[656])[c13_i14];
  }

  c13_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[704];
  for (c13_i15 = 0; c13_i15 < 6; c13_i15++) {
    c13_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c13_i15] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[712])[c13_i15];
  }

  for (c13_i16 = 0; c13_i16 < 6; c13_i16++) {
    c13_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c13_i16] = ((real_T *)
      &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[0])[760])[c13_i16];
  }

  c13_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c13_ControlParams)[0])[808];
  c13_i17 = 0;
  for (c13_i18 = 0; c13_i18 < 2; c13_i18++) {
    for (c13_i19 = 0; c13_i19 < 6; c13_i19++) {
      c13_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c13_i19 +
        c13_i17] = ((real_T *)&((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[0])[816])[c13_i19 + c13_i17];
    }

    c13_i17 += 6;
  }

  c13_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[0])
    [912];
  c13_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [0];
  c13_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [8];
  c13_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [16];
  c13_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [24];
  c13_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [32];
  c13_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [40];
  c13_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [48];
  c13_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [56];
  c13_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [64];
  c13_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [72];
  c13_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[920])
    [80];
  c13_i20 = 0;
  for (c13_i21 = 0; c13_i21 < 13; c13_i21++) {
    for (c13_i22 = 0; c13_i22 < 6; c13_i22++) {
      c13_b_ControlParams.Output.H0[c13_i22 + c13_i20] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
        [1008])[0])[c13_i22 + c13_i20];
    }

    c13_i20 += 6;
  }

  c13_i23 = 0;
  for (c13_i24 = 0; c13_i24 < 6; c13_i24++) {
    for (c13_i25 = 0; c13_i25 < 6; c13_i25++) {
      c13_b_ControlParams.Output.HAlpha[c13_i25 + c13_i23] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[1008])[624])[c13_i25 + c13_i23];
    }

    c13_i23 += 6;
  }

  for (c13_i26 = 0; c13_i26 < 2; c13_i26++) {
    c13_b_ControlParams.Output.ThetaLimits[c13_i26] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
      [912])[c13_i26];
  }

  c13_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
    chartInstance->c13_ControlParams)[1008])[928])[0];
  c13_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
    chartInstance->c13_ControlParams)[1008])[928])[8];
  for (c13_i27 = 0; c13_i27 < 13; c13_i27++) {
    c13_b_ControlParams.Output.Theta.cq[c13_i27] = ((real_T *)&((char_T *)
      (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[1008])[928])[16])[c13_i27];
  }

  c13_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
    chartInstance->c13_ControlParams)[1008])[928])[120];
  for (c13_i28 = 0; c13_i28 < 7; c13_i28++) {
    c13_b_ControlParams.Output.Theta.cz[c13_i28] = ((real_T *)&((char_T *)
      (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[1008])[928])[128])[c13_i28];
  }

  c13_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [1112];
  for (c13_i29 = 0; c13_i29 < 2; c13_i29++) {
    c13_b_ControlParams.Output.SLimits[c13_i29] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
      [1120])[c13_i29];
  }

  c13_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [1136];
  c13_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [1144];
  c13_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [1152];
  c13_i30 = 0;
  for (c13_i31 = 0; c13_i31 < 5; c13_i31++) {
    for (c13_i32 = 0; c13_i32 < 6; c13_i32++) {
      c13_b_ControlParams.Output.HAlphaCorrection[c13_i32 + c13_i30] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[1008])[1160])[c13_i32 + c13_i30];
    }

    c13_i30 += 6;
  }

  c13_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c13_PhiParamsBus *)
    &((char_T *)(c13_OutputParamsBus *)&((char_T *)
    chartInstance->c13_ControlParams)[1008])[1400])[0];
  for (c13_i33 = 0; c13_i33 < 13; c13_i33++) {
    c13_b_ControlParams.Output.Phi.cq[c13_i33] = ((real_T *)&((char_T *)
      (c13_PhiParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
      chartInstance->c13_ControlParams)[1008])[1400])[8])[c13_i33];
  }

  for (c13_i34 = 0; c13_i34 < 20; c13_i34++) {
    c13_b_ControlParams.Output.PhiAlpha[c13_i34] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
      [1512])[c13_i34];
  }

  c13_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [1672];
  for (c13_i35 = 0; c13_i35 < 2; c13_i35++) {
    c13_b_ControlParams.Output.RLimits[c13_i35] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
      [1680])[c13_i35];
  }

  c13_i36 = 0;
  for (c13_i37 = 0; c13_i37 < 5; c13_i37++) {
    for (c13_i38 = 0; c13_i38 < 6; c13_i38++) {
      c13_b_ControlParams.Output.HBarAlpha[c13_i38 + c13_i36] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[1008])[1696])[c13_i38 + c13_i36];
    }

    c13_i36 += 6;
  }

  c13_i39 = 0;
  for (c13_i40 = 0; c13_i40 < 2; c13_i40++) {
    for (c13_i41 = 0; c13_i41 < 6; c13_i41++) {
      c13_b_ControlParams.Output.HBarLimits[c13_i41 + c13_i39] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[1008])[1936])[c13_i41 + c13_i39];
    }

    c13_i39 += 6;
  }

  c13_i42 = 0;
  for (c13_i43 = 0; c13_i43 < 6; c13_i43++) {
    for (c13_i44 = 0; c13_i44 < 6; c13_i44++) {
      c13_b_ControlParams.Output.HAlphaStar[c13_i44 + c13_i42] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)
        chartInstance->c13_ControlParams)[1008])[2032])[c13_i44 + c13_i42];
    }

    c13_i42 += 6;
  }

  c13_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[1008])
    [2320];
  for (c13_i45 = 0; c13_i45 < 6; c13_i45++) {
    c13_b_ControlParams.Feedback.kp[c13_i45] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[0])[c13_i45];
  }

  for (c13_i46 = 0; c13_i46 < 6; c13_i46++) {
    c13_b_ControlParams.Feedback.kd[c13_i46] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[48])[c13_i46];
  }

  for (c13_i47 = 0; c13_i47 < 2; c13_i47++) {
    c13_b_ControlParams.Feedback.epsilon[c13_i47] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[96])[c13_i47];
  }

  for (c13_i48 = 0; c13_i48 < 2; c13_i48++) {
    c13_b_ControlParams.Feedback.kff_grav[c13_i48] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[112])[c13_i48];
  }

  c13_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [128];
  for (c13_i49 = 0; c13_i49 < 2; c13_i49++) {
    c13_b_ControlParams.Feedback.kff_decoup[c13_i49] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[136])[c13_i49];
  }

  for (c13_i50 = 0; c13_i50 < 2; c13_i50++) {
    c13_b_ControlParams.Feedback.kd_torso[c13_i50] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[152])[c13_i50];
  }

  c13_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [168];
  c13_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [176];
  c13_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [184];
  c13_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [192];
  c13_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [200];
  c13_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [208];
  c13_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [216];
  c13_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [224];
  for (c13_i51 = 0; c13_i51 < 6; c13_i51++) {
    c13_b_ControlParams.Feedback.u_ff[c13_i51] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[232])[c13_i51];
  }

  c13_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [280];
  c13_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [288];
  c13_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [296];
  c13_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [304];
  c13_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [312];
  c13_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [320];
  c13_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [328];
  c13_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [336];
  c13_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [344];
  for (c13_i52 = 0; c13_i52 < 6; c13_i52++) {
    c13_b_ControlParams.Feedback.FeedforwardGain[c13_i52] = ((real_T *)&((char_T
      *)(c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3336])[352])[c13_i52];
  }

  c13_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)chartInstance->c13_ControlParams)[3336])
    [400];
  c13_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[0];
  for (c13_i53 = 0; c13_i53 < 2; c13_i53++) {
    c13_b_ControlParams.Saturation.QPWeight[c13_i53] = ((real_T *)&((char_T *)
      (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
      [3744])[8])[c13_i53];
  }

  c13_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[24];
  c13_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[32];
  c13_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[40];
  c13_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[48];
  c13_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)chartInstance->c13_ControlParams)
    [3744])[56];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c13_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_weight, 0U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA_R, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS_R, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA_L, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS_L, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_uR, 5U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_uL, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_T0, 7U, c13_f_sf_marshallOut,
    c13_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u0, 8U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_deltaS, 9U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_KASaturationLim, 10U,
    c13_e_sf_marshallOut, c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 11U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 12U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_b_u, 13U, c13_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_s, 14U, c13_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c13_b_sat, 15U, c13_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_ControlState, 16U, c13_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c13_b_ControlParams, 17U, c13_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_b_u_sat, 18U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 4);
  for (c13_i54 = 0; c13_i54 < 6; c13_i54++) {
    c13_b_u_sat[c13_i54] = c13_b_u[c13_i54];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c13_b_ControlParams.Saturation.UseQPSaturation != 0.0))
  {
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0,
          c13_b_ControlState.StanceLeg, 0.0, -1, 0U,
          c13_b_ControlState.StanceLeg == 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
      for (c13_i55 = 0; c13_i55 < 2; c13_i55++) {
        c13_weight[c13_i55] = c13_b_ControlParams.Saturation.QPWeight[c13_i55];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 10);
      for (c13_i56 = 0; c13_i56 < 2; c13_i56++) {
        c13_b[c13_i56] = c13_b_ControlParams.Saturation.QPWeight[c13_i56];
      }

      c13_eml_scalar_eg(chartInstance);
      c13_eml_scalar_eg(chartInstance);
      for (c13_i57 = 0; c13_i57 < 2; c13_i57++) {
        c13_weight[c13_i57] = 0.0;
      }

      for (c13_i58 = 0; c13_i58 < 2; c13_i58++) {
        c13_weight[c13_i58] = 0.0;
      }

      for (c13_i59 = 0; c13_i59 < 2; c13_i59++) {
        c13_C[c13_i59] = c13_weight[c13_i59];
      }

      for (c13_i60 = 0; c13_i60 < 2; c13_i60++) {
        c13_weight[c13_i60] = c13_C[c13_i60];
      }

      c13_threshold(chartInstance);
      for (c13_i61 = 0; c13_i61 < 2; c13_i61++) {
        c13_C[c13_i61] = c13_weight[c13_i61];
      }

      for (c13_i62 = 0; c13_i62 < 2; c13_i62++) {
        c13_weight[c13_i62] = c13_C[c13_i62];
      }

      for (c13_i63 = 0; c13_i63 < 2; c13_i63++) {
        c13_weight[c13_i63] = 0.0;
        c13_i64 = 0;
        for (c13_i65 = 0; c13_i65 < 2; c13_i65++) {
          c13_weight[c13_i63] += c13_a[c13_i64 + c13_i63] * c13_b[c13_i65];
          c13_i64 += 2;
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 13);
    c13_A = c13_b_u[0] + c13_b_u[1];
    c13_u_LA_R = c13_rdivide(chartInstance, c13_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 14);
    c13_u_LS_R = c13_b_u[1] - c13_b_u[0];
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 15);
    c13_b_A = c13_b_u[3] + c13_b_u[4];
    c13_u_LA_L = c13_rdivide(chartInstance, c13_b_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 16);
    c13_u_LS_L = c13_b_u[4] - c13_b_u[3];
    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 18);
    c13_LA_LS_Revised_Saturation(chartInstance, c13_u_LS_R, c13_u_LA_R,
      c13_weight[0], -c13_b_sat[0], c13_b_sat[0], -c13_b_sat[1], c13_b_sat[1],
      c13_dv1);
    for (c13_i66 = 0; c13_i66 < 2; c13_i66++) {
      c13_uR[c13_i66] = c13_dv1[c13_i66];
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 19);
    c13_LA_LS_Revised_Saturation(chartInstance, c13_u_LS_L, c13_u_LA_L,
      c13_weight[1], -c13_b_sat[0], c13_b_sat[0], -c13_b_sat[1], c13_b_sat[1],
      c13_dv2);
    for (c13_i67 = 0; c13_i67 < 2; c13_i67++) {
      c13_uL[c13_i67] = c13_dv2[c13_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 20);
    for (c13_i68 = 0; c13_i68 < 2; c13_i68++) {
      c13_b_u_sat[c13_i68] = c13_uR[c13_i68];
    }

    c13_b_u_sat[2] = c13_b_u[2];
    for (c13_i69 = 0; c13_i69 < 2; c13_i69++) {
      c13_b_u_sat[c13_i69 + 3] = c13_uL[c13_i69];
    }

    c13_b_u_sat[5] = c13_b_u[5];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 23);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 1,
        c13_b_ControlState.ControllerMode, 3.0, -1, 5U,
        c13_b_ControlState.ControllerMode >= 3.0))) {
    if (CV_EML_COND(0, 1, 1, c13_b_ControlParams.Saturation.UseKASaturation !=
                    0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 26);
      for (c13_i70 = 0; c13_i70 < 36; c13_i70++) {
        c13_T0[c13_i70] = c13_dv3[c13_i70];
      }

      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 27);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 2,
            c13_b_ControlState.StanceLeg, 1.0, -1, 0U,
            c13_b_ControlState.StanceLeg == 1.0))) {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 28);
        for (c13_i71 = 0; c13_i71 < 6; c13_i71++) {
          for (c13_i72 = 0; c13_i72 < 6; c13_i72++) {
            c13_b_T0[c13_i72 + 6 * c13_i71] = c13_T0[c13_iv0[c13_i72] + 6 *
              c13_i71];
          }
        }

        c13_i73 = 0;
        for (c13_i74 = 0; c13_i74 < 6; c13_i74++) {
          for (c13_i75 = 0; c13_i75 < 6; c13_i75++) {
            c13_T0[c13_i75 + c13_i73] = c13_b_T0[c13_i75 + c13_i73];
          }

          c13_i73 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 31);
      for (c13_i76 = 0; c13_i76 < 36; c13_i76++) {
        c13_b_a[c13_i76] = c13_T0[c13_i76];
      }

      for (c13_i77 = 0; c13_i77 < 6; c13_i77++) {
        c13_b_b[c13_i77] = c13_b_u_sat[c13_i77];
      }

      c13_b_eml_scalar_eg(chartInstance);
      c13_b_eml_scalar_eg(chartInstance);
      for (c13_i78 = 0; c13_i78 < 6; c13_i78++) {
        c13_u0[c13_i78] = 0.0;
      }

      for (c13_i79 = 0; c13_i79 < 6; c13_i79++) {
        c13_u0[c13_i79] = 0.0;
      }

      for (c13_i80 = 0; c13_i80 < 6; c13_i80++) {
        c13_b_C[c13_i80] = c13_u0[c13_i80];
      }

      for (c13_i81 = 0; c13_i81 < 6; c13_i81++) {
        c13_u0[c13_i81] = c13_b_C[c13_i81];
      }

      c13_threshold(chartInstance);
      for (c13_i82 = 0; c13_i82 < 6; c13_i82++) {
        c13_b_C[c13_i82] = c13_u0[c13_i82];
      }

      for (c13_i83 = 0; c13_i83 < 6; c13_i83++) {
        c13_u0[c13_i83] = c13_b_C[c13_i83];
      }

      for (c13_i84 = 0; c13_i84 < 6; c13_i84++) {
        c13_u0[c13_i84] = 0.0;
        c13_i85 = 0;
        for (c13_i86 = 0; c13_i86 < 6; c13_i86++) {
          c13_u0[c13_i84] += c13_b_a[c13_i85 + c13_i84] * c13_b_b[c13_i86];
          c13_i85 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 32);
      c13_deltaS = c13_b_ControlParams.Saturation.KASaturationS2 -
        c13_b_ControlParams.Saturation.KASaturationS1;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 33);
      c13_varargin_1 = c13_deltaS;
      c13_varargin_2 = c13_varargin_1;
      c13_x = c13_varargin_2;
      c13_b_x = c13_x;
      c13_c_eml_scalar_eg(chartInstance);
      c13_xk = c13_b_x;
      c13_c_x = c13_xk;
      c13_c_eml_scalar_eg(chartInstance);
      c13_deltaS = muDoubleScalarMin(c13_c_x, 1.0);
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 34);
      if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 3, c13_b_s,
            c13_b_ControlParams.Saturation.KASaturationS1, -1, 2U, c13_b_s <
            c13_b_ControlParams.Saturation.KASaturationS1))) {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 35);
        c13_KASaturationLim = c13_b_ControlParams.Saturation.KASaturationEarly;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 36);
        if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 4, c13_b_s,
              c13_b_ControlParams.Saturation.KASaturationS2, -1, 2U, c13_b_s <
              c13_b_ControlParams.Saturation.KASaturationS2))) {
          _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 37);
          c13_c_a[0] = c13_b_ControlParams.Saturation.KASaturationS2 - c13_b_s;
          c13_c_a[1] = c13_b_s - c13_b_ControlParams.Saturation.KASaturationS1;
          c13_b[0] = c13_b_ControlParams.Saturation.KASaturationEarly;
          c13_b[1] = c13_b_ControlParams.Saturation.KASaturationMax;
          for (c13_i87 = 0; c13_i87 < 2; c13_i87++) {
            c13_d_a[c13_i87] = c13_c_a[c13_i87];
          }

          for (c13_i88 = 0; c13_i88 < 2; c13_i88++) {
            c13_c_b[c13_i88] = c13_b[c13_i88];
          }

          c13_y = c13_eml_xdotu(chartInstance, c13_d_a, c13_c_b);
          c13_c_A = c13_y;
          c13_B = c13_deltaS;
          c13_KASaturationLim = c13_rdivide(chartInstance, c13_c_A, c13_B);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 40);
          c13_KASaturationLim = c13_b_ControlParams.Saturation.KASaturationMax;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 42);
      c13_b_varargin_1 = c13_u0[2];
      c13_b_varargin_2 = c13_KASaturationLim;
      c13_c_varargin_2 = c13_b_varargin_1;
      c13_varargin_3 = c13_b_varargin_2;
      c13_d_x = c13_c_varargin_2;
      c13_b_y = c13_varargin_3;
      c13_e_x = c13_d_x;
      c13_c_y = c13_b_y;
      c13_c_eml_scalar_eg(chartInstance);
      c13_b_xk = c13_e_x;
      c13_yk = c13_c_y;
      c13_f_x = c13_b_xk;
      c13_d_y = c13_yk;
      c13_c_eml_scalar_eg(chartInstance);
      c13_minval = muDoubleScalarMin(c13_f_x, c13_d_y);
      c13_c_varargin_1 = -c13_KASaturationLim;
      c13_d_varargin_2 = c13_minval;
      c13_e_varargin_2 = c13_c_varargin_1;
      c13_b_varargin_3 = c13_d_varargin_2;
      c13_g_x = c13_e_varargin_2;
      c13_e_y = c13_b_varargin_3;
      c13_h_x = c13_g_x;
      c13_f_y = c13_e_y;
      c13_c_eml_scalar_eg(chartInstance);
      c13_c_xk = c13_h_x;
      c13_b_yk = c13_f_y;
      c13_i_x = c13_c_xk;
      c13_g_y = c13_b_yk;
      c13_c_eml_scalar_eg(chartInstance);
      c13_maxval = muDoubleScalarMax(c13_i_x, c13_g_y);
      c13_u0[2] = c13_maxval;
      _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 43);
      for (c13_i89 = 0; c13_i89 < 36; c13_i89++) {
        c13_b_a[c13_i89] = c13_T0[c13_i89];
      }

      for (c13_i90 = 0; c13_i90 < 6; c13_i90++) {
        c13_b_b[c13_i90] = c13_u0[c13_i90];
      }

      c13_b_eml_matlab_zgetrf(chartInstance, c13_b_a, c13_ipiv, &c13_info);
      c13_b_info = c13_info;
      c13_c_info = c13_b_info;
      c13_d_info = c13_c_info;
      if (c13_d_info > 0) {
        c13_eml_warning(chartInstance);
      }

      c13_b_eml_scalar_eg(chartInstance);
      for (c13_i91 = 0; c13_i91 < 6; c13_i91++) {
        c13_b_u_sat[c13_i91] = c13_b_b[c13_i91];
      }

      c13_eml_switch_helper(chartInstance);
      for (c13_xi = 1; c13_xi < 6; c13_xi++) {
        c13_b_xi = c13_xi;
        if (c13_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
             ("", (real_T)c13_b_xi), 1, 6, 1, 0) - 1] != c13_b_xi) {
          c13_ip = c13_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_b_xi), 1, 6, 1, 0) - 1];
          c13_temp = c13_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_b_xi), 1, 6, 1, 0) - 1];
          c13_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_b_xi), 1, 6, 1, 0) - 1] =
            c13_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ip), 1, 6, 1, 0) - 1];
          c13_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ip), 1, 6, 1, 0) - 1] = c13_temp;
        }
      }

      for (c13_i92 = 0; c13_i92 < 6; c13_i92++) {
        c13_b_b[c13_i92] = c13_b_u_sat[c13_i92];
      }

      for (c13_i93 = 0; c13_i93 < 36; c13_i93++) {
        c13_e_a[c13_i93] = c13_b_a[c13_i93];
      }

      c13_c_eml_xtrsm(chartInstance, c13_e_a, c13_b_b);
      for (c13_i94 = 0; c13_i94 < 6; c13_i94++) {
        c13_b_u_sat[c13_i94] = c13_b_b[c13_i94];
      }

      for (c13_i95 = 0; c13_i95 < 6; c13_i95++) {
        c13_b_b[c13_i95] = c13_b_u_sat[c13_i95];
      }

      for (c13_i96 = 0; c13_i96 < 36; c13_i96++) {
        c13_f_a[c13_i96] = c13_b_a[c13_i96];
      }

      c13_d_eml_xtrsm(chartInstance, c13_f_a, c13_b_b);
      for (c13_i97 = 0; c13_i97 < 6; c13_i97++) {
        c13_b_u_sat[c13_i97] = c13_b_b[c13_i97];
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c13_i98 = 0; c13_i98 < 6; c13_i98++) {
    (*chartInstance->c13_u_sat)[c13_i98] = c13_b_u_sat[c13_i98];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
}

static void initSimStructsc13_LibWalking(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c13_LA_LS_Revised_Saturation(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u1_max, real_T c13_u2_min, real_T c13_u2_max, real_T
  c13_u_opt[2])
{
  uint32_T c13_debug_family_var_map[32];
  real_T c13_u_opt_1[2];
  real_T c13_L_opt_1[4];
  real_T c13_u_opt_2[2];
  real_T c13_L_opt_2[4];
  real_T c13_u_opt_3[2];
  real_T c13_L_opt_3[4];
  real_T c13_u_opt_4[2];
  real_T c13_L_opt_4[4];
  real_T c13_u_opt_5[2];
  real_T c13_L_opt_5[4];
  real_T c13_u_opt_6[2];
  real_T c13_L_opt_6[4];
  real_T c13_u_opt_7[2];
  real_T c13_L_opt_7[4];
  real_T c13_u_opt_8[2];
  real_T c13_L_opt_8[4];
  real_T c13_u_opt_9[2];
  real_T c13_L_opt_9[4];
  real_T c13_LB[2];
  real_T c13_UB[2];
  real_T c13_L_opt[4];
  real_T c13_case_n;
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 1.0;
  real_T c13_b_L_opt_1[4];
  real_T c13_b_u_opt_1[2];
  int32_T c13_i99;
  int32_T c13_i100;
  int32_T c13_i101;
  int32_T c13_i102;
  int32_T c13_i103;
  int32_T c13_i104;
  int32_T c13_i105;
  int32_T c13_i106;
  int32_T c13_i107;
  int32_T c13_i108;
  int32_T c13_i109;
  int32_T c13_i110;
  int32_T c13_i111;
  int32_T c13_i112;
  int32_T c13_i113;
  int32_T c13_i114;
  int32_T c13_i115;
  int32_T c13_i116;
  int32_T c13_i117;
  int32_T c13_i118;
  int32_T c13_i119;
  int32_T c13_ixstart;
  real_T c13_mtmp;
  real_T c13_x;
  boolean_T c13_b;
  int32_T c13_ix;
  int32_T c13_b_ix;
  real_T c13_b_x;
  boolean_T c13_b_b;
  int32_T c13_a;
  int32_T c13_b_a;
  int32_T c13_i120;
  int32_T c13_c_a;
  int32_T c13_d_a;
  boolean_T c13_overflow;
  int32_T c13_c_ix;
  real_T c13_e_a;
  real_T c13_c_b;
  boolean_T c13_p;
  real_T c13_b_mtmp;
  real_T c13_d0;
  int32_T c13_i121;
  int32_T c13_b_ixstart;
  real_T c13_c_mtmp;
  real_T c13_c_x;
  boolean_T c13_d_b;
  int32_T c13_d_ix;
  int32_T c13_e_ix;
  real_T c13_d_x;
  boolean_T c13_e_b;
  int32_T c13_f_a;
  int32_T c13_g_a;
  int32_T c13_i122;
  int32_T c13_h_a;
  int32_T c13_i_a;
  boolean_T c13_b_overflow;
  int32_T c13_f_ix;
  real_T c13_j_a;
  real_T c13_f_b;
  boolean_T c13_b_p;
  real_T c13_d_mtmp;
  real_T c13_d1;
  int32_T c13_i123;
  int32_T c13_c_ixstart;
  real_T c13_e_mtmp;
  real_T c13_e_x;
  boolean_T c13_g_b;
  int32_T c13_g_ix;
  int32_T c13_h_ix;
  real_T c13_f_x;
  boolean_T c13_h_b;
  int32_T c13_k_a;
  int32_T c13_l_a;
  int32_T c13_i124;
  int32_T c13_m_a;
  int32_T c13_n_a;
  boolean_T c13_c_overflow;
  int32_T c13_i_ix;
  real_T c13_o_a;
  real_T c13_i_b;
  boolean_T c13_c_p;
  real_T c13_f_mtmp;
  real_T c13_d2;
  int32_T c13_i125;
  int32_T c13_i126;
  int32_T c13_i127;
  int32_T c13_d_ixstart;
  real_T c13_g_mtmp;
  real_T c13_g_x;
  boolean_T c13_j_b;
  int32_T c13_j_ix;
  int32_T c13_k_ix;
  real_T c13_h_x;
  boolean_T c13_k_b;
  int32_T c13_p_a;
  int32_T c13_q_a;
  int32_T c13_i128;
  int32_T c13_r_a;
  int32_T c13_s_a;
  boolean_T c13_d_overflow;
  int32_T c13_l_ix;
  real_T c13_t_a;
  real_T c13_l_b;
  boolean_T c13_d_p;
  real_T c13_h_mtmp;
  real_T c13_d3;
  int32_T c13_i129;
  int32_T c13_e_ixstart;
  real_T c13_i_mtmp;
  real_T c13_i_x;
  boolean_T c13_m_b;
  int32_T c13_m_ix;
  int32_T c13_n_ix;
  real_T c13_j_x;
  boolean_T c13_n_b;
  int32_T c13_u_a;
  int32_T c13_v_a;
  int32_T c13_i130;
  int32_T c13_w_a;
  int32_T c13_x_a;
  boolean_T c13_e_overflow;
  int32_T c13_o_ix;
  real_T c13_y_a;
  real_T c13_o_b;
  boolean_T c13_e_p;
  real_T c13_j_mtmp;
  real_T c13_d4;
  int32_T c13_i131;
  int32_T c13_f_ixstart;
  real_T c13_k_mtmp;
  real_T c13_k_x;
  boolean_T c13_p_b;
  int32_T c13_p_ix;
  int32_T c13_q_ix;
  real_T c13_l_x;
  boolean_T c13_q_b;
  int32_T c13_ab_a;
  int32_T c13_bb_a;
  int32_T c13_i132;
  int32_T c13_cb_a;
  int32_T c13_db_a;
  boolean_T c13_f_overflow;
  int32_T c13_r_ix;
  real_T c13_eb_a;
  real_T c13_r_b;
  boolean_T c13_f_p;
  real_T c13_l_mtmp;
  real_T c13_d5;
  int32_T c13_i133;
  int32_T c13_i134;
  int32_T c13_i135;
  int32_T c13_g_ixstart;
  real_T c13_m_mtmp;
  real_T c13_m_x;
  boolean_T c13_s_b;
  int32_T c13_s_ix;
  int32_T c13_t_ix;
  real_T c13_n_x;
  boolean_T c13_t_b;
  int32_T c13_fb_a;
  int32_T c13_gb_a;
  int32_T c13_i136;
  int32_T c13_hb_a;
  int32_T c13_ib_a;
  boolean_T c13_g_overflow;
  int32_T c13_u_ix;
  real_T c13_jb_a;
  real_T c13_u_b;
  boolean_T c13_g_p;
  real_T c13_n_mtmp;
  real_T c13_d6;
  int32_T c13_i137;
  int32_T c13_h_ixstart;
  real_T c13_o_mtmp;
  real_T c13_o_x;
  boolean_T c13_v_b;
  int32_T c13_v_ix;
  int32_T c13_w_ix;
  real_T c13_p_x;
  boolean_T c13_w_b;
  int32_T c13_kb_a;
  int32_T c13_lb_a;
  int32_T c13_i138;
  int32_T c13_mb_a;
  int32_T c13_nb_a;
  boolean_T c13_h_overflow;
  int32_T c13_x_ix;
  real_T c13_ob_a;
  real_T c13_x_b;
  boolean_T c13_h_p;
  real_T c13_p_mtmp;
  real_T c13_d7;
  int32_T c13_i139;
  int32_T c13_i_ixstart;
  real_T c13_q_mtmp;
  real_T c13_q_x;
  boolean_T c13_y_b;
  int32_T c13_y_ix;
  int32_T c13_ab_ix;
  real_T c13_r_x;
  boolean_T c13_ab_b;
  int32_T c13_pb_a;
  int32_T c13_qb_a;
  int32_T c13_i140;
  int32_T c13_rb_a;
  int32_T c13_sb_a;
  boolean_T c13_i_overflow;
  int32_T c13_bb_ix;
  real_T c13_tb_a;
  real_T c13_bb_b;
  boolean_T c13_i_p;
  real_T c13_r_mtmp;
  real_T c13_d8;
  int32_T c13_i141;
  int32_T c13_i142;
  int32_T c13_i143;
  int32_T c13_j_ixstart;
  real_T c13_s_mtmp;
  real_T c13_s_x;
  boolean_T c13_cb_b;
  int32_T c13_cb_ix;
  int32_T c13_db_ix;
  real_T c13_t_x;
  boolean_T c13_db_b;
  int32_T c13_ub_a;
  int32_T c13_vb_a;
  int32_T c13_i144;
  int32_T c13_wb_a;
  int32_T c13_xb_a;
  boolean_T c13_j_overflow;
  int32_T c13_eb_ix;
  real_T c13_yb_a;
  real_T c13_eb_b;
  boolean_T c13_j_p;
  real_T c13_t_mtmp;
  real_T c13_d9;
  int32_T c13_i145;
  int32_T c13_k_ixstart;
  real_T c13_u_mtmp;
  real_T c13_u_x;
  boolean_T c13_fb_b;
  int32_T c13_fb_ix;
  int32_T c13_gb_ix;
  real_T c13_v_x;
  boolean_T c13_gb_b;
  int32_T c13_ac_a;
  int32_T c13_bc_a;
  int32_T c13_i146;
  int32_T c13_cc_a;
  int32_T c13_dc_a;
  boolean_T c13_k_overflow;
  int32_T c13_hb_ix;
  real_T c13_ec_a;
  real_T c13_hb_b;
  boolean_T c13_k_p;
  real_T c13_v_mtmp;
  real_T c13_d10;
  int32_T c13_i147;
  int32_T c13_l_ixstart;
  real_T c13_w_mtmp;
  real_T c13_w_x;
  boolean_T c13_ib_b;
  int32_T c13_ib_ix;
  int32_T c13_jb_ix;
  real_T c13_x_x;
  boolean_T c13_jb_b;
  int32_T c13_fc_a;
  int32_T c13_gc_a;
  int32_T c13_i148;
  int32_T c13_hc_a;
  int32_T c13_ic_a;
  boolean_T c13_l_overflow;
  int32_T c13_kb_ix;
  real_T c13_jc_a;
  real_T c13_kb_b;
  boolean_T c13_l_p;
  real_T c13_x_mtmp;
  real_T c13_d11;
  int32_T c13_i149;
  int32_T c13_i150;
  int32_T c13_i151;
  int32_T c13_m_ixstart;
  real_T c13_y_mtmp;
  real_T c13_y_x;
  boolean_T c13_lb_b;
  int32_T c13_lb_ix;
  int32_T c13_mb_ix;
  real_T c13_ab_x;
  boolean_T c13_mb_b;
  int32_T c13_kc_a;
  int32_T c13_lc_a;
  int32_T c13_i152;
  int32_T c13_mc_a;
  int32_T c13_nc_a;
  boolean_T c13_m_overflow;
  int32_T c13_nb_ix;
  real_T c13_oc_a;
  real_T c13_nb_b;
  boolean_T c13_m_p;
  real_T c13_ab_mtmp;
  real_T c13_d12;
  int32_T c13_i153;
  int32_T c13_n_ixstart;
  real_T c13_bb_mtmp;
  real_T c13_bb_x;
  boolean_T c13_ob_b;
  int32_T c13_ob_ix;
  int32_T c13_pb_ix;
  real_T c13_cb_x;
  boolean_T c13_pb_b;
  int32_T c13_pc_a;
  int32_T c13_qc_a;
  int32_T c13_i154;
  int32_T c13_rc_a;
  int32_T c13_sc_a;
  boolean_T c13_n_overflow;
  int32_T c13_qb_ix;
  real_T c13_tc_a;
  real_T c13_qb_b;
  boolean_T c13_n_p;
  real_T c13_cb_mtmp;
  real_T c13_d13;
  int32_T c13_i155;
  int32_T c13_o_ixstart;
  real_T c13_db_mtmp;
  real_T c13_db_x;
  boolean_T c13_rb_b;
  int32_T c13_rb_ix;
  int32_T c13_sb_ix;
  real_T c13_eb_x;
  boolean_T c13_sb_b;
  int32_T c13_uc_a;
  int32_T c13_vc_a;
  int32_T c13_i156;
  int32_T c13_wc_a;
  int32_T c13_xc_a;
  boolean_T c13_o_overflow;
  int32_T c13_tb_ix;
  real_T c13_yc_a;
  real_T c13_tb_b;
  boolean_T c13_o_p;
  real_T c13_eb_mtmp;
  real_T c13_d14;
  int32_T c13_i157;
  int32_T c13_i158;
  int32_T c13_i159;
  int32_T c13_p_ixstart;
  real_T c13_fb_mtmp;
  real_T c13_fb_x;
  boolean_T c13_ub_b;
  int32_T c13_ub_ix;
  int32_T c13_vb_ix;
  real_T c13_gb_x;
  boolean_T c13_vb_b;
  int32_T c13_ad_a;
  int32_T c13_bd_a;
  int32_T c13_i160;
  int32_T c13_cd_a;
  int32_T c13_dd_a;
  boolean_T c13_p_overflow;
  int32_T c13_wb_ix;
  real_T c13_ed_a;
  real_T c13_wb_b;
  boolean_T c13_p_p;
  real_T c13_gb_mtmp;
  real_T c13_d15;
  int32_T c13_i161;
  int32_T c13_q_ixstart;
  real_T c13_hb_mtmp;
  real_T c13_hb_x;
  boolean_T c13_xb_b;
  int32_T c13_xb_ix;
  int32_T c13_yb_ix;
  real_T c13_ib_x;
  boolean_T c13_yb_b;
  int32_T c13_fd_a;
  int32_T c13_gd_a;
  int32_T c13_i162;
  int32_T c13_hd_a;
  int32_T c13_id_a;
  boolean_T c13_q_overflow;
  int32_T c13_ac_ix;
  real_T c13_jd_a;
  real_T c13_ac_b;
  boolean_T c13_q_p;
  real_T c13_ib_mtmp;
  real_T c13_d16;
  int32_T c13_i163;
  int32_T c13_r_ixstart;
  real_T c13_jb_mtmp;
  real_T c13_jb_x;
  boolean_T c13_bc_b;
  int32_T c13_bc_ix;
  int32_T c13_cc_ix;
  real_T c13_kb_x;
  boolean_T c13_cc_b;
  int32_T c13_kd_a;
  int32_T c13_ld_a;
  int32_T c13_i164;
  int32_T c13_md_a;
  int32_T c13_nd_a;
  boolean_T c13_r_overflow;
  int32_T c13_dc_ix;
  real_T c13_od_a;
  real_T c13_dc_b;
  boolean_T c13_r_p;
  real_T c13_kb_mtmp;
  real_T c13_d17;
  int32_T c13_i165;
  int32_T c13_i166;
  int32_T c13_i167;
  int32_T c13_s_ixstart;
  real_T c13_lb_mtmp;
  real_T c13_lb_x;
  boolean_T c13_ec_b;
  int32_T c13_ec_ix;
  int32_T c13_fc_ix;
  real_T c13_mb_x;
  boolean_T c13_fc_b;
  int32_T c13_pd_a;
  int32_T c13_qd_a;
  int32_T c13_i168;
  int32_T c13_rd_a;
  int32_T c13_sd_a;
  boolean_T c13_s_overflow;
  int32_T c13_gc_ix;
  real_T c13_td_a;
  real_T c13_gc_b;
  boolean_T c13_s_p;
  real_T c13_mb_mtmp;
  real_T c13_d18;
  int32_T c13_i169;
  int32_T c13_t_ixstart;
  real_T c13_nb_mtmp;
  real_T c13_nb_x;
  boolean_T c13_hc_b;
  int32_T c13_hc_ix;
  int32_T c13_ic_ix;
  real_T c13_ob_x;
  boolean_T c13_ic_b;
  int32_T c13_ud_a;
  int32_T c13_vd_a;
  int32_T c13_i170;
  int32_T c13_wd_a;
  int32_T c13_xd_a;
  boolean_T c13_t_overflow;
  int32_T c13_jc_ix;
  real_T c13_yd_a;
  real_T c13_jc_b;
  boolean_T c13_t_p;
  real_T c13_ob_mtmp;
  real_T c13_d19;
  int32_T c13_i171;
  int32_T c13_u_ixstart;
  real_T c13_pb_mtmp;
  real_T c13_pb_x;
  boolean_T c13_kc_b;
  int32_T c13_kc_ix;
  int32_T c13_lc_ix;
  real_T c13_qb_x;
  boolean_T c13_lc_b;
  int32_T c13_ae_a;
  int32_T c13_be_a;
  int32_T c13_i172;
  int32_T c13_ce_a;
  int32_T c13_de_a;
  boolean_T c13_u_overflow;
  int32_T c13_mc_ix;
  real_T c13_ee_a;
  real_T c13_mc_b;
  boolean_T c13_u_p;
  real_T c13_qb_mtmp;
  real_T c13_d20;
  int32_T c13_i173;
  int32_T c13_i174;
  int32_T c13_i175;
  int32_T c13_v_ixstart;
  real_T c13_rb_mtmp;
  real_T c13_rb_x;
  boolean_T c13_nc_b;
  int32_T c13_nc_ix;
  int32_T c13_oc_ix;
  real_T c13_sb_x;
  boolean_T c13_oc_b;
  int32_T c13_fe_a;
  int32_T c13_ge_a;
  int32_T c13_i176;
  int32_T c13_he_a;
  int32_T c13_ie_a;
  boolean_T c13_v_overflow;
  int32_T c13_pc_ix;
  real_T c13_je_a;
  real_T c13_pc_b;
  boolean_T c13_v_p;
  real_T c13_sb_mtmp;
  real_T c13_d21;
  int32_T c13_i177;
  int32_T c13_w_ixstart;
  real_T c13_tb_mtmp;
  real_T c13_tb_x;
  boolean_T c13_qc_b;
  int32_T c13_qc_ix;
  int32_T c13_rc_ix;
  real_T c13_ub_x;
  boolean_T c13_rc_b;
  int32_T c13_ke_a;
  int32_T c13_le_a;
  int32_T c13_i178;
  int32_T c13_me_a;
  int32_T c13_ne_a;
  boolean_T c13_w_overflow;
  int32_T c13_sc_ix;
  real_T c13_oe_a;
  real_T c13_sc_b;
  boolean_T c13_w_p;
  real_T c13_ub_mtmp;
  real_T c13_d22;
  int32_T c13_i179;
  int32_T c13_x_ixstart;
  real_T c13_vb_mtmp;
  real_T c13_vb_x;
  boolean_T c13_tc_b;
  int32_T c13_tc_ix;
  int32_T c13_uc_ix;
  real_T c13_wb_x;
  boolean_T c13_uc_b;
  int32_T c13_pe_a;
  int32_T c13_qe_a;
  int32_T c13_i180;
  int32_T c13_re_a;
  int32_T c13_se_a;
  boolean_T c13_x_overflow;
  int32_T c13_vc_ix;
  real_T c13_te_a;
  real_T c13_vc_b;
  boolean_T c13_x_p;
  real_T c13_wb_mtmp;
  real_T c13_d23;
  int32_T c13_i181;
  int32_T c13_i182;
  int32_T c13_i183;
  int32_T c13_y_ixstart;
  real_T c13_xb_mtmp;
  real_T c13_xb_x;
  boolean_T c13_wc_b;
  int32_T c13_wc_ix;
  int32_T c13_xc_ix;
  real_T c13_yb_x;
  boolean_T c13_xc_b;
  int32_T c13_ue_a;
  int32_T c13_ve_a;
  int32_T c13_i184;
  int32_T c13_we_a;
  int32_T c13_xe_a;
  boolean_T c13_y_overflow;
  int32_T c13_yc_ix;
  real_T c13_ye_a;
  real_T c13_yc_b;
  boolean_T c13_y_p;
  real_T c13_yb_mtmp;
  real_T c13_d24;
  int32_T c13_i185;
  int32_T c13_ab_ixstart;
  real_T c13_ac_mtmp;
  real_T c13_ac_x;
  boolean_T c13_ad_b;
  int32_T c13_ad_ix;
  int32_T c13_bd_ix;
  real_T c13_bc_x;
  boolean_T c13_bd_b;
  int32_T c13_af_a;
  int32_T c13_bf_a;
  int32_T c13_i186;
  int32_T c13_cf_a;
  int32_T c13_df_a;
  boolean_T c13_ab_overflow;
  int32_T c13_cd_ix;
  real_T c13_ef_a;
  real_T c13_cd_b;
  boolean_T c13_ab_p;
  real_T c13_bc_mtmp;
  real_T c13_d25;
  int32_T c13_i187;
  int32_T c13_bb_ixstart;
  real_T c13_cc_mtmp;
  real_T c13_cc_x;
  boolean_T c13_dd_b;
  int32_T c13_dd_ix;
  int32_T c13_ed_ix;
  real_T c13_dc_x;
  boolean_T c13_ed_b;
  int32_T c13_ff_a;
  int32_T c13_gf_a;
  int32_T c13_i188;
  int32_T c13_hf_a;
  int32_T c13_if_a;
  boolean_T c13_bb_overflow;
  int32_T c13_fd_ix;
  real_T c13_jf_a;
  real_T c13_fd_b;
  boolean_T c13_bb_p;
  real_T c13_dc_mtmp;
  real_T c13_d26;
  int32_T c13_i189;
  int32_T c13_i190;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  boolean_T guard16 = false;
  boolean_T guard17 = false;
  boolean_T guard18 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T exitg8;
  boolean_T exitg9;
  boolean_T exitg10;
  boolean_T exitg11;
  boolean_T exitg12;
  boolean_T exitg13;
  boolean_T exitg14;
  boolean_T exitg15;
  boolean_T exitg16;
  boolean_T exitg17;
  boolean_T exitg18;
  boolean_T exitg19;
  boolean_T exitg20;
  boolean_T exitg21;
  boolean_T exitg22;
  boolean_T exitg23;
  boolean_T exitg24;
  boolean_T exitg25;
  boolean_T exitg26;
  boolean_T exitg27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 32U, c13_k_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_1, 0U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_1, 1U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_2, 2U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_2, 3U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_3, 4U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_3, 5U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_4, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_4, 7U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_5, 8U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_5, 9U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_6, 10U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_6, 11U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_7, 12U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_7, 13U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_8, 14U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_8, 15U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt_9, 16U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt_9, 17U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_LB, 18U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_UB, 19U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 20U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_case_n, 21U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 22U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 23U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 24U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 25U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 26U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_min, 27U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_max, 28U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_min, 29U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_max, 30U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 31U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 30);
  c13_LA_LS_Revised_Saturation_Case_1(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i99 = 0; c13_i99 < 2; c13_i99++) {
    c13_u_opt_1[c13_i99] = c13_b_u_opt_1[c13_i99];
  }

  for (c13_i100 = 0; c13_i100 < 4; c13_i100++) {
    c13_L_opt_1[c13_i100] = c13_b_L_opt_1[c13_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 31);
  c13_LA_LS_Revised_Saturation_Case_2(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_min, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i101 = 0; c13_i101 < 2; c13_i101++) {
    c13_u_opt_2[c13_i101] = c13_b_u_opt_1[c13_i101];
  }

  for (c13_i102 = 0; c13_i102 < 4; c13_i102++) {
    c13_L_opt_2[c13_i102] = c13_b_L_opt_1[c13_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 32);
  c13_LA_LS_Revised_Saturation_Case_3(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_max, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i103 = 0; c13_i103 < 2; c13_i103++) {
    c13_u_opt_3[c13_i103] = c13_b_u_opt_1[c13_i103];
  }

  for (c13_i104 = 0; c13_i104 < 4; c13_i104++) {
    c13_L_opt_3[c13_i104] = c13_b_L_opt_1[c13_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 33);
  c13_LA_LS_Revised_Saturation_Case_4(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u2_min, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i105 = 0; c13_i105 < 2; c13_i105++) {
    c13_u_opt_4[c13_i105] = c13_b_u_opt_1[c13_i105];
  }

  for (c13_i106 = 0; c13_i106 < 4; c13_i106++) {
    c13_L_opt_4[c13_i106] = c13_b_L_opt_1[c13_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 34);
  c13_LA_LS_Revised_Saturation_Case_5(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u2_max, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i107 = 0; c13_i107 < 2; c13_i107++) {
    c13_u_opt_5[c13_i107] = c13_b_u_opt_1[c13_i107];
  }

  for (c13_i108 = 0; c13_i108 < 4; c13_i108++) {
    c13_L_opt_5[c13_i108] = c13_b_L_opt_1[c13_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 35);
  c13_LA_LS_Revised_Saturation_Case_6(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_min, c13_u2_min, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i109 = 0; c13_i109 < 2; c13_i109++) {
    c13_u_opt_6[c13_i109] = c13_b_u_opt_1[c13_i109];
  }

  for (c13_i110 = 0; c13_i110 < 4; c13_i110++) {
    c13_L_opt_6[c13_i110] = c13_b_L_opt_1[c13_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 36);
  c13_LA_LS_Revised_Saturation_Case_7(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_min, c13_u2_max, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i111 = 0; c13_i111 < 2; c13_i111++) {
    c13_u_opt_7[c13_i111] = c13_b_u_opt_1[c13_i111];
  }

  for (c13_i112 = 0; c13_i112 < 4; c13_i112++) {
    c13_L_opt_7[c13_i112] = c13_b_L_opt_1[c13_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 37);
  c13_LA_LS_Revised_Saturation_Case_8(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_max, c13_u2_min, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i113 = 0; c13_i113 < 2; c13_i113++) {
    c13_u_opt_8[c13_i113] = c13_b_u_opt_1[c13_i113];
  }

  for (c13_i114 = 0; c13_i114 < 4; c13_i114++) {
    c13_L_opt_8[c13_i114] = c13_b_L_opt_1[c13_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 38);
  c13_LA_LS_Revised_Saturation_Case_9(chartInstance, c13_u_LS, c13_u_LA, c13_w,
    c13_u1_max, c13_u2_max, c13_b_u_opt_1, c13_b_L_opt_1);
  for (c13_i115 = 0; c13_i115 < 2; c13_i115++) {
    c13_u_opt_9[c13_i115] = c13_b_u_opt_1[c13_i115];
  }

  for (c13_i116 = 0; c13_i116 < 4; c13_i116++) {
    c13_L_opt_9[c13_i116] = c13_b_L_opt_1[c13_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 41);
  c13_LB[0] = c13_u1_min;
  c13_LB[1] = c13_u2_min;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 42);
  c13_UB[0] = c13_u1_max;
  c13_UB[1] = c13_u2_max;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 45);
  for (c13_i117 = 0; c13_i117 < 2; c13_i117++) {
    c13_u_opt[c13_i117] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 46);
  for (c13_i118 = 0; c13_i118 < 4; c13_i118++) {
    c13_L_opt[c13_i118] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 47);
  c13_case_n = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 49);
  for (c13_i119 = 0; c13_i119 < 2; c13_i119++) {
    c13_b_u_opt_1[c13_i119] = c13_u_opt_1[c13_i119] - c13_UB[c13_i119];
  }

  c13_ixstart = 1;
  c13_mtmp = c13_b_u_opt_1[0];
  c13_x = c13_mtmp;
  c13_b = muDoubleScalarIsNaN(c13_x);
  if (c13_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_ix = 2;
    exitg27 = false;
    while ((exitg27 == false) && (c13_ix < 3)) {
      c13_b_ix = c13_ix;
      c13_ixstart = c13_b_ix;
      c13_b_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_b_ix), 1, 2, 1, 0) - 1];
      c13_b_b = muDoubleScalarIsNaN(c13_b_x);
      if (!c13_b_b) {
        c13_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_b_ix), 1, 2, 1, 0) - 1];
        exitg27 = true;
      } else {
        c13_ix++;
      }
    }
  }

  if (c13_ixstart < 2) {
    c13_a = c13_ixstart;
    c13_b_a = c13_a + 1;
    c13_i120 = c13_b_a;
    c13_c_a = c13_i120;
    c13_d_a = c13_c_a;
    if (c13_d_a > 2) {
      c13_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_overflow = false;
    }

    if (c13_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_overflow);
    }

    for (c13_c_ix = c13_i120; c13_c_ix < 3; c13_c_ix++) {
      c13_b_ix = c13_c_ix;
      c13_e_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_b_ix), 1, 2, 1, 0) - 1];
      c13_c_b = c13_mtmp;
      c13_p = (c13_e_a > c13_c_b);
      if (c13_p) {
        c13_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_b_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_b_mtmp = c13_mtmp;
  c13_d0 = c13_b_mtmp;
  guard17 = false;
  guard18 = false;
  if (CV_SCRIPT_COND(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c13_d0, 0.0, -1, 3U,
        c13_d0 <= 0.0))) {
    for (c13_i121 = 0; c13_i121 < 2; c13_i121++) {
      c13_b_u_opt_1[c13_i121] = c13_u_opt_1[c13_i121] - c13_LB[c13_i121];
    }

    c13_b_ixstart = 1;
    c13_c_mtmp = c13_b_u_opt_1[0];
    c13_c_x = c13_c_mtmp;
    c13_d_b = muDoubleScalarIsNaN(c13_c_x);
    if (c13_d_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_d_ix = 2;
      exitg26 = false;
      while ((exitg26 == false) && (c13_d_ix < 3)) {
        c13_e_ix = c13_d_ix;
        c13_b_ixstart = c13_e_ix;
        c13_d_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_e_ix), 1, 2, 1, 0) - 1];
        c13_e_b = muDoubleScalarIsNaN(c13_d_x);
        if (!c13_e_b) {
          c13_c_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_e_ix), 1, 2, 1, 0) - 1];
          exitg26 = true;
        } else {
          c13_d_ix++;
        }
      }
    }

    if (c13_b_ixstart < 2) {
      c13_f_a = c13_b_ixstart;
      c13_g_a = c13_f_a + 1;
      c13_i122 = c13_g_a;
      c13_h_a = c13_i122;
      c13_i_a = c13_h_a;
      if (c13_i_a > 2) {
        c13_b_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_b_overflow = false;
      }

      if (c13_b_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_b_overflow);
      }

      for (c13_f_ix = c13_i122; c13_f_ix < 3; c13_f_ix++) {
        c13_e_ix = c13_f_ix;
        c13_j_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_e_ix), 1, 2, 1, 0) - 1];
        c13_f_b = c13_c_mtmp;
        c13_b_p = (c13_j_a < c13_f_b);
        if (c13_b_p) {
          c13_c_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_e_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_d_mtmp = c13_c_mtmp;
    c13_d1 = c13_d_mtmp;
    if (CV_SCRIPT_COND(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c13_d1, 0.0, -1, 5U,
          c13_d1 >= 0.0))) {
      for (c13_i123 = 0; c13_i123 < 4; c13_i123++) {
        c13_b_L_opt_1[c13_i123] = c13_L_opt_1[c13_i123];
      }

      c13_c_ixstart = 1;
      c13_e_mtmp = c13_b_L_opt_1[0];
      c13_e_x = c13_e_mtmp;
      c13_g_b = muDoubleScalarIsNaN(c13_e_x);
      if (c13_g_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_g_ix = 2;
        exitg25 = false;
        while ((exitg25 == false) && (c13_g_ix < 5)) {
          c13_h_ix = c13_g_ix;
          c13_c_ixstart = c13_h_ix;
          c13_f_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_h_ix), 1, 4, 1, 0) - 1];
          c13_h_b = muDoubleScalarIsNaN(c13_f_x);
          if (!c13_h_b) {
            c13_e_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_h_ix), 1, 4, 1, 0) - 1];
            exitg25 = true;
          } else {
            c13_g_ix++;
          }
        }
      }

      if (c13_c_ixstart < 4) {
        c13_k_a = c13_c_ixstart;
        c13_l_a = c13_k_a + 1;
        c13_i124 = c13_l_a;
        c13_m_a = c13_i124;
        c13_n_a = c13_m_a;
        if (c13_n_a > 4) {
          c13_c_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_c_overflow = false;
        }

        if (c13_c_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_c_overflow);
        }

        for (c13_i_ix = c13_i124; c13_i_ix < 5; c13_i_ix++) {
          c13_h_ix = c13_i_ix;
          c13_o_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_h_ix), 1, 4, 1, 0) - 1];
          c13_i_b = c13_e_mtmp;
          c13_c_p = (c13_o_a < c13_i_b);
          if (c13_c_p) {
            c13_e_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_h_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_f_mtmp = c13_e_mtmp;
      c13_d2 = c13_f_mtmp;
      if (CV_SCRIPT_COND(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c13_d2, 0.0, -1,
            5U, c13_d2 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 0, true);
        CV_SCRIPT_IF(0, 0, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 50);
        for (c13_i125 = 0; c13_i125 < 2; c13_i125++) {
          c13_u_opt[c13_i125] = c13_u_opt_1[c13_i125];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 51);
        for (c13_i126 = 0; c13_i126 < 4; c13_i126++) {
          c13_L_opt[c13_i126] = c13_L_opt_1[c13_i126];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 52);
        c13_case_n = 1.0;
      } else {
        guard17 = true;
      }
    } else {
      guard18 = true;
    }
  } else {
    guard18 = true;
  }

  if (guard18 == true) {
    guard17 = true;
  }

  if (guard17 == true) {
    CV_SCRIPT_MCDC(0, 0, false);
    CV_SCRIPT_IF(0, 0, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 56);
  for (c13_i127 = 0; c13_i127 < 2; c13_i127++) {
    c13_b_u_opt_1[c13_i127] = c13_u_opt_2[c13_i127] - c13_UB[c13_i127];
  }

  c13_d_ixstart = 1;
  c13_g_mtmp = c13_b_u_opt_1[0];
  c13_g_x = c13_g_mtmp;
  c13_j_b = muDoubleScalarIsNaN(c13_g_x);
  if (c13_j_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_j_ix = 2;
    exitg24 = false;
    while ((exitg24 == false) && (c13_j_ix < 3)) {
      c13_k_ix = c13_j_ix;
      c13_d_ixstart = c13_k_ix;
      c13_h_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_k_ix), 1, 2, 1, 0) - 1];
      c13_k_b = muDoubleScalarIsNaN(c13_h_x);
      if (!c13_k_b) {
        c13_g_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_k_ix), 1, 2, 1, 0) - 1];
        exitg24 = true;
      } else {
        c13_j_ix++;
      }
    }
  }

  if (c13_d_ixstart < 2) {
    c13_p_a = c13_d_ixstart;
    c13_q_a = c13_p_a + 1;
    c13_i128 = c13_q_a;
    c13_r_a = c13_i128;
    c13_s_a = c13_r_a;
    if (c13_s_a > 2) {
      c13_d_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_d_overflow = false;
    }

    if (c13_d_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_d_overflow);
    }

    for (c13_l_ix = c13_i128; c13_l_ix < 3; c13_l_ix++) {
      c13_k_ix = c13_l_ix;
      c13_t_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_k_ix), 1, 2, 1, 0) - 1];
      c13_l_b = c13_g_mtmp;
      c13_d_p = (c13_t_a > c13_l_b);
      if (c13_d_p) {
        c13_g_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_k_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_h_mtmp = c13_g_mtmp;
  c13_d3 = c13_h_mtmp;
  guard15 = false;
  guard16 = false;
  if (CV_SCRIPT_COND(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c13_d3, 0.0, -1, 3U,
        c13_d3 <= 0.0))) {
    for (c13_i129 = 0; c13_i129 < 2; c13_i129++) {
      c13_b_u_opt_1[c13_i129] = c13_u_opt_2[c13_i129] - c13_LB[c13_i129];
    }

    c13_e_ixstart = 1;
    c13_i_mtmp = c13_b_u_opt_1[0];
    c13_i_x = c13_i_mtmp;
    c13_m_b = muDoubleScalarIsNaN(c13_i_x);
    if (c13_m_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_m_ix = 2;
      exitg23 = false;
      while ((exitg23 == false) && (c13_m_ix < 3)) {
        c13_n_ix = c13_m_ix;
        c13_e_ixstart = c13_n_ix;
        c13_j_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_n_ix), 1, 2, 1, 0) - 1];
        c13_n_b = muDoubleScalarIsNaN(c13_j_x);
        if (!c13_n_b) {
          c13_i_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_n_ix), 1, 2, 1, 0) - 1];
          exitg23 = true;
        } else {
          c13_m_ix++;
        }
      }
    }

    if (c13_e_ixstart < 2) {
      c13_u_a = c13_e_ixstart;
      c13_v_a = c13_u_a + 1;
      c13_i130 = c13_v_a;
      c13_w_a = c13_i130;
      c13_x_a = c13_w_a;
      if (c13_x_a > 2) {
        c13_e_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_e_overflow = false;
      }

      if (c13_e_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_e_overflow);
      }

      for (c13_o_ix = c13_i130; c13_o_ix < 3; c13_o_ix++) {
        c13_n_ix = c13_o_ix;
        c13_y_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_n_ix), 1, 2, 1, 0) - 1];
        c13_o_b = c13_i_mtmp;
        c13_e_p = (c13_y_a < c13_o_b);
        if (c13_e_p) {
          c13_i_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_n_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_j_mtmp = c13_i_mtmp;
    c13_d4 = c13_j_mtmp;
    if (CV_SCRIPT_COND(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c13_d4, 0.0, -1, 5U,
          c13_d4 >= 0.0))) {
      for (c13_i131 = 0; c13_i131 < 4; c13_i131++) {
        c13_b_L_opt_1[c13_i131] = c13_L_opt_2[c13_i131];
      }

      c13_f_ixstart = 1;
      c13_k_mtmp = c13_b_L_opt_1[0];
      c13_k_x = c13_k_mtmp;
      c13_p_b = muDoubleScalarIsNaN(c13_k_x);
      if (c13_p_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_p_ix = 2;
        exitg22 = false;
        while ((exitg22 == false) && (c13_p_ix < 5)) {
          c13_q_ix = c13_p_ix;
          c13_f_ixstart = c13_q_ix;
          c13_l_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_q_ix), 1, 4, 1, 0) - 1];
          c13_q_b = muDoubleScalarIsNaN(c13_l_x);
          if (!c13_q_b) {
            c13_k_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_q_ix), 1, 4, 1, 0) - 1];
            exitg22 = true;
          } else {
            c13_p_ix++;
          }
        }
      }

      if (c13_f_ixstart < 4) {
        c13_ab_a = c13_f_ixstart;
        c13_bb_a = c13_ab_a + 1;
        c13_i132 = c13_bb_a;
        c13_cb_a = c13_i132;
        c13_db_a = c13_cb_a;
        if (c13_db_a > 4) {
          c13_f_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_f_overflow = false;
        }

        if (c13_f_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_f_overflow);
        }

        for (c13_r_ix = c13_i132; c13_r_ix < 5; c13_r_ix++) {
          c13_q_ix = c13_r_ix;
          c13_eb_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_q_ix), 1, 4, 1, 0) - 1];
          c13_r_b = c13_k_mtmp;
          c13_f_p = (c13_eb_a < c13_r_b);
          if (c13_f_p) {
            c13_k_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_q_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_l_mtmp = c13_k_mtmp;
      c13_d5 = c13_l_mtmp;
      if (CV_SCRIPT_COND(0, 5, CV_RELATIONAL_EVAL(14U, 0U, 5, c13_d5, 0.0, -1,
            5U, c13_d5 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 1, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 57);
        for (c13_i133 = 0; c13_i133 < 2; c13_i133++) {
          c13_u_opt[c13_i133] = c13_u_opt_2[c13_i133];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 58);
        for (c13_i134 = 0; c13_i134 < 4; c13_i134++) {
          c13_L_opt[c13_i134] = c13_L_opt_2[c13_i134];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 59);
        c13_case_n = 2.0;
      } else {
        guard15 = true;
      }
    } else {
      guard16 = true;
    }
  } else {
    guard16 = true;
  }

  if (guard16 == true) {
    guard15 = true;
  }

  if (guard15 == true) {
    CV_SCRIPT_MCDC(0, 1, false);
    CV_SCRIPT_IF(0, 1, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 63);
  for (c13_i135 = 0; c13_i135 < 2; c13_i135++) {
    c13_b_u_opt_1[c13_i135] = c13_u_opt_3[c13_i135] - c13_UB[c13_i135];
  }

  c13_g_ixstart = 1;
  c13_m_mtmp = c13_b_u_opt_1[0];
  c13_m_x = c13_m_mtmp;
  c13_s_b = muDoubleScalarIsNaN(c13_m_x);
  if (c13_s_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_s_ix = 2;
    exitg21 = false;
    while ((exitg21 == false) && (c13_s_ix < 3)) {
      c13_t_ix = c13_s_ix;
      c13_g_ixstart = c13_t_ix;
      c13_n_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_t_ix), 1, 2, 1, 0) - 1];
      c13_t_b = muDoubleScalarIsNaN(c13_n_x);
      if (!c13_t_b) {
        c13_m_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_t_ix), 1, 2, 1, 0) - 1];
        exitg21 = true;
      } else {
        c13_s_ix++;
      }
    }
  }

  if (c13_g_ixstart < 2) {
    c13_fb_a = c13_g_ixstart;
    c13_gb_a = c13_fb_a + 1;
    c13_i136 = c13_gb_a;
    c13_hb_a = c13_i136;
    c13_ib_a = c13_hb_a;
    if (c13_ib_a > 2) {
      c13_g_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_g_overflow = false;
    }

    if (c13_g_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_g_overflow);
    }

    for (c13_u_ix = c13_i136; c13_u_ix < 3; c13_u_ix++) {
      c13_t_ix = c13_u_ix;
      c13_jb_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_t_ix), 1, 2, 1, 0) - 1];
      c13_u_b = c13_m_mtmp;
      c13_g_p = (c13_jb_a > c13_u_b);
      if (c13_g_p) {
        c13_m_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_t_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_n_mtmp = c13_m_mtmp;
  c13_d6 = c13_n_mtmp;
  guard13 = false;
  guard14 = false;
  if (CV_SCRIPT_COND(0, 6, CV_RELATIONAL_EVAL(14U, 0U, 6, c13_d6, 0.0, -1, 3U,
        c13_d6 <= 0.0))) {
    for (c13_i137 = 0; c13_i137 < 2; c13_i137++) {
      c13_b_u_opt_1[c13_i137] = c13_u_opt_3[c13_i137] - c13_LB[c13_i137];
    }

    c13_h_ixstart = 1;
    c13_o_mtmp = c13_b_u_opt_1[0];
    c13_o_x = c13_o_mtmp;
    c13_v_b = muDoubleScalarIsNaN(c13_o_x);
    if (c13_v_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_v_ix = 2;
      exitg20 = false;
      while ((exitg20 == false) && (c13_v_ix < 3)) {
        c13_w_ix = c13_v_ix;
        c13_h_ixstart = c13_w_ix;
        c13_p_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_w_ix), 1, 2, 1, 0) - 1];
        c13_w_b = muDoubleScalarIsNaN(c13_p_x);
        if (!c13_w_b) {
          c13_o_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_w_ix), 1, 2, 1, 0) - 1];
          exitg20 = true;
        } else {
          c13_v_ix++;
        }
      }
    }

    if (c13_h_ixstart < 2) {
      c13_kb_a = c13_h_ixstart;
      c13_lb_a = c13_kb_a + 1;
      c13_i138 = c13_lb_a;
      c13_mb_a = c13_i138;
      c13_nb_a = c13_mb_a;
      if (c13_nb_a > 2) {
        c13_h_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_h_overflow = false;
      }

      if (c13_h_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_h_overflow);
      }

      for (c13_x_ix = c13_i138; c13_x_ix < 3; c13_x_ix++) {
        c13_w_ix = c13_x_ix;
        c13_ob_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_w_ix), 1, 2, 1, 0) - 1];
        c13_x_b = c13_o_mtmp;
        c13_h_p = (c13_ob_a < c13_x_b);
        if (c13_h_p) {
          c13_o_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_w_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_p_mtmp = c13_o_mtmp;
    c13_d7 = c13_p_mtmp;
    if (CV_SCRIPT_COND(0, 7, CV_RELATIONAL_EVAL(14U, 0U, 7, c13_d7, 0.0, -1, 5U,
          c13_d7 >= 0.0))) {
      for (c13_i139 = 0; c13_i139 < 4; c13_i139++) {
        c13_b_L_opt_1[c13_i139] = c13_L_opt_3[c13_i139];
      }

      c13_i_ixstart = 1;
      c13_q_mtmp = c13_b_L_opt_1[0];
      c13_q_x = c13_q_mtmp;
      c13_y_b = muDoubleScalarIsNaN(c13_q_x);
      if (c13_y_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_y_ix = 2;
        exitg19 = false;
        while ((exitg19 == false) && (c13_y_ix < 5)) {
          c13_ab_ix = c13_y_ix;
          c13_i_ixstart = c13_ab_ix;
          c13_r_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ab_ix), 1, 4, 1, 0) - 1];
          c13_ab_b = muDoubleScalarIsNaN(c13_r_x);
          if (!c13_ab_b) {
            c13_q_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_ab_ix), 1, 4, 1, 0) - 1];
            exitg19 = true;
          } else {
            c13_y_ix++;
          }
        }
      }

      if (c13_i_ixstart < 4) {
        c13_pb_a = c13_i_ixstart;
        c13_qb_a = c13_pb_a + 1;
        c13_i140 = c13_qb_a;
        c13_rb_a = c13_i140;
        c13_sb_a = c13_rb_a;
        if (c13_sb_a > 4) {
          c13_i_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_i_overflow = false;
        }

        if (c13_i_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_i_overflow);
        }

        for (c13_bb_ix = c13_i140; c13_bb_ix < 5; c13_bb_ix++) {
          c13_ab_ix = c13_bb_ix;
          c13_tb_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ab_ix), 1, 4, 1, 0) - 1];
          c13_bb_b = c13_q_mtmp;
          c13_i_p = (c13_tb_a < c13_bb_b);
          if (c13_i_p) {
            c13_q_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_ab_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_r_mtmp = c13_q_mtmp;
      c13_d8 = c13_r_mtmp;
      if (CV_SCRIPT_COND(0, 8, CV_RELATIONAL_EVAL(14U, 0U, 8, c13_d8, 0.0, -1,
            5U, c13_d8 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 2, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 64);
        for (c13_i141 = 0; c13_i141 < 2; c13_i141++) {
          c13_u_opt[c13_i141] = c13_u_opt_3[c13_i141];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 65);
        for (c13_i142 = 0; c13_i142 < 4; c13_i142++) {
          c13_L_opt[c13_i142] = c13_L_opt_3[c13_i142];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 66);
        c13_case_n = 3.0;
      } else {
        guard13 = true;
      }
    } else {
      guard14 = true;
    }
  } else {
    guard14 = true;
  }

  if (guard14 == true) {
    guard13 = true;
  }

  if (guard13 == true) {
    CV_SCRIPT_MCDC(0, 2, false);
    CV_SCRIPT_IF(0, 2, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 70);
  for (c13_i143 = 0; c13_i143 < 2; c13_i143++) {
    c13_b_u_opt_1[c13_i143] = c13_u_opt_4[c13_i143] - c13_UB[c13_i143];
  }

  c13_j_ixstart = 1;
  c13_s_mtmp = c13_b_u_opt_1[0];
  c13_s_x = c13_s_mtmp;
  c13_cb_b = muDoubleScalarIsNaN(c13_s_x);
  if (c13_cb_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_cb_ix = 2;
    exitg18 = false;
    while ((exitg18 == false) && (c13_cb_ix < 3)) {
      c13_db_ix = c13_cb_ix;
      c13_j_ixstart = c13_db_ix;
      c13_t_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_db_ix), 1, 2, 1, 0) - 1];
      c13_db_b = muDoubleScalarIsNaN(c13_t_x);
      if (!c13_db_b) {
        c13_s_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_db_ix), 1, 2, 1, 0) - 1];
        exitg18 = true;
      } else {
        c13_cb_ix++;
      }
    }
  }

  if (c13_j_ixstart < 2) {
    c13_ub_a = c13_j_ixstart;
    c13_vb_a = c13_ub_a + 1;
    c13_i144 = c13_vb_a;
    c13_wb_a = c13_i144;
    c13_xb_a = c13_wb_a;
    if (c13_xb_a > 2) {
      c13_j_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_j_overflow = false;
    }

    if (c13_j_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_j_overflow);
    }

    for (c13_eb_ix = c13_i144; c13_eb_ix < 3; c13_eb_ix++) {
      c13_db_ix = c13_eb_ix;
      c13_yb_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_db_ix), 1, 2, 1, 0) - 1];
      c13_eb_b = c13_s_mtmp;
      c13_j_p = (c13_yb_a > c13_eb_b);
      if (c13_j_p) {
        c13_s_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_db_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_t_mtmp = c13_s_mtmp;
  c13_d9 = c13_t_mtmp;
  guard11 = false;
  guard12 = false;
  if (CV_SCRIPT_COND(0, 9, CV_RELATIONAL_EVAL(14U, 0U, 9, c13_d9, 0.0, -1, 3U,
        c13_d9 <= 0.0))) {
    for (c13_i145 = 0; c13_i145 < 2; c13_i145++) {
      c13_b_u_opt_1[c13_i145] = c13_u_opt_4[c13_i145] - c13_LB[c13_i145];
    }

    c13_k_ixstart = 1;
    c13_u_mtmp = c13_b_u_opt_1[0];
    c13_u_x = c13_u_mtmp;
    c13_fb_b = muDoubleScalarIsNaN(c13_u_x);
    if (c13_fb_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_fb_ix = 2;
      exitg17 = false;
      while ((exitg17 == false) && (c13_fb_ix < 3)) {
        c13_gb_ix = c13_fb_ix;
        c13_k_ixstart = c13_gb_ix;
        c13_v_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_gb_ix), 1, 2, 1, 0) - 1];
        c13_gb_b = muDoubleScalarIsNaN(c13_v_x);
        if (!c13_gb_b) {
          c13_u_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_gb_ix), 1, 2, 1, 0) - 1];
          exitg17 = true;
        } else {
          c13_fb_ix++;
        }
      }
    }

    if (c13_k_ixstart < 2) {
      c13_ac_a = c13_k_ixstart;
      c13_bc_a = c13_ac_a + 1;
      c13_i146 = c13_bc_a;
      c13_cc_a = c13_i146;
      c13_dc_a = c13_cc_a;
      if (c13_dc_a > 2) {
        c13_k_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_k_overflow = false;
      }

      if (c13_k_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_k_overflow);
      }

      for (c13_hb_ix = c13_i146; c13_hb_ix < 3; c13_hb_ix++) {
        c13_gb_ix = c13_hb_ix;
        c13_ec_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_gb_ix), 1, 2, 1, 0) - 1];
        c13_hb_b = c13_u_mtmp;
        c13_k_p = (c13_ec_a < c13_hb_b);
        if (c13_k_p) {
          c13_u_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_gb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_v_mtmp = c13_u_mtmp;
    c13_d10 = c13_v_mtmp;
    if (CV_SCRIPT_COND(0, 10, CV_RELATIONAL_EVAL(14U, 0U, 10, c13_d10, 0.0, -1,
          5U, c13_d10 >= 0.0))) {
      for (c13_i147 = 0; c13_i147 < 4; c13_i147++) {
        c13_b_L_opt_1[c13_i147] = c13_L_opt_4[c13_i147];
      }

      c13_l_ixstart = 1;
      c13_w_mtmp = c13_b_L_opt_1[0];
      c13_w_x = c13_w_mtmp;
      c13_ib_b = muDoubleScalarIsNaN(c13_w_x);
      if (c13_ib_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_ib_ix = 2;
        exitg16 = false;
        while ((exitg16 == false) && (c13_ib_ix < 5)) {
          c13_jb_ix = c13_ib_ix;
          c13_l_ixstart = c13_jb_ix;
          c13_x_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_jb_ix), 1, 4, 1, 0) - 1];
          c13_jb_b = muDoubleScalarIsNaN(c13_x_x);
          if (!c13_jb_b) {
            c13_w_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_jb_ix), 1, 4, 1, 0) - 1];
            exitg16 = true;
          } else {
            c13_ib_ix++;
          }
        }
      }

      if (c13_l_ixstart < 4) {
        c13_fc_a = c13_l_ixstart;
        c13_gc_a = c13_fc_a + 1;
        c13_i148 = c13_gc_a;
        c13_hc_a = c13_i148;
        c13_ic_a = c13_hc_a;
        if (c13_ic_a > 4) {
          c13_l_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_l_overflow = false;
        }

        if (c13_l_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_l_overflow);
        }

        for (c13_kb_ix = c13_i148; c13_kb_ix < 5; c13_kb_ix++) {
          c13_jb_ix = c13_kb_ix;
          c13_jc_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_jb_ix), 1, 4, 1, 0) - 1];
          c13_kb_b = c13_w_mtmp;
          c13_l_p = (c13_jc_a < c13_kb_b);
          if (c13_l_p) {
            c13_w_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_jb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_x_mtmp = c13_w_mtmp;
      c13_d11 = c13_x_mtmp;
      if (CV_SCRIPT_COND(0, 11, CV_RELATIONAL_EVAL(14U, 0U, 11, c13_d11, 0.0, -1,
            5U, c13_d11 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 3, true);
        CV_SCRIPT_IF(0, 3, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 71);
        for (c13_i149 = 0; c13_i149 < 2; c13_i149++) {
          c13_u_opt[c13_i149] = c13_u_opt_4[c13_i149];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 72);
        for (c13_i150 = 0; c13_i150 < 4; c13_i150++) {
          c13_L_opt[c13_i150] = c13_L_opt_4[c13_i150];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 73);
        c13_case_n = 4.0;
      } else {
        guard11 = true;
      }
    } else {
      guard12 = true;
    }
  } else {
    guard12 = true;
  }

  if (guard12 == true) {
    guard11 = true;
  }

  if (guard11 == true) {
    CV_SCRIPT_MCDC(0, 3, false);
    CV_SCRIPT_IF(0, 3, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 77);
  for (c13_i151 = 0; c13_i151 < 2; c13_i151++) {
    c13_b_u_opt_1[c13_i151] = c13_u_opt_5[c13_i151] - c13_UB[c13_i151];
  }

  c13_m_ixstart = 1;
  c13_y_mtmp = c13_b_u_opt_1[0];
  c13_y_x = c13_y_mtmp;
  c13_lb_b = muDoubleScalarIsNaN(c13_y_x);
  if (c13_lb_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_lb_ix = 2;
    exitg15 = false;
    while ((exitg15 == false) && (c13_lb_ix < 3)) {
      c13_mb_ix = c13_lb_ix;
      c13_m_ixstart = c13_mb_ix;
      c13_ab_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_mb_ix), 1, 2, 1, 0) - 1];
      c13_mb_b = muDoubleScalarIsNaN(c13_ab_x);
      if (!c13_mb_b) {
        c13_y_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_mb_ix), 1, 2, 1, 0) - 1];
        exitg15 = true;
      } else {
        c13_lb_ix++;
      }
    }
  }

  if (c13_m_ixstart < 2) {
    c13_kc_a = c13_m_ixstart;
    c13_lc_a = c13_kc_a + 1;
    c13_i152 = c13_lc_a;
    c13_mc_a = c13_i152;
    c13_nc_a = c13_mc_a;
    if (c13_nc_a > 2) {
      c13_m_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_m_overflow = false;
    }

    if (c13_m_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_m_overflow);
    }

    for (c13_nb_ix = c13_i152; c13_nb_ix < 3; c13_nb_ix++) {
      c13_mb_ix = c13_nb_ix;
      c13_oc_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_mb_ix), 1, 2, 1, 0) - 1];
      c13_nb_b = c13_y_mtmp;
      c13_m_p = (c13_oc_a > c13_nb_b);
      if (c13_m_p) {
        c13_y_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_mb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_ab_mtmp = c13_y_mtmp;
  c13_d12 = c13_ab_mtmp;
  guard9 = false;
  guard10 = false;
  if (CV_SCRIPT_COND(0, 12, CV_RELATIONAL_EVAL(14U, 0U, 12, c13_d12, 0.0, -1, 3U,
        c13_d12 <= 0.0))) {
    for (c13_i153 = 0; c13_i153 < 2; c13_i153++) {
      c13_b_u_opt_1[c13_i153] = c13_u_opt_5[c13_i153] - c13_LB[c13_i153];
    }

    c13_n_ixstart = 1;
    c13_bb_mtmp = c13_b_u_opt_1[0];
    c13_bb_x = c13_bb_mtmp;
    c13_ob_b = muDoubleScalarIsNaN(c13_bb_x);
    if (c13_ob_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_ob_ix = 2;
      exitg14 = false;
      while ((exitg14 == false) && (c13_ob_ix < 3)) {
        c13_pb_ix = c13_ob_ix;
        c13_n_ixstart = c13_pb_ix;
        c13_cb_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_pb_ix), 1, 2, 1, 0) - 1];
        c13_pb_b = muDoubleScalarIsNaN(c13_cb_x);
        if (!c13_pb_b) {
          c13_bb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_pb_ix), 1, 2, 1, 0) - 1];
          exitg14 = true;
        } else {
          c13_ob_ix++;
        }
      }
    }

    if (c13_n_ixstart < 2) {
      c13_pc_a = c13_n_ixstart;
      c13_qc_a = c13_pc_a + 1;
      c13_i154 = c13_qc_a;
      c13_rc_a = c13_i154;
      c13_sc_a = c13_rc_a;
      if (c13_sc_a > 2) {
        c13_n_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_n_overflow = false;
      }

      if (c13_n_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_n_overflow);
      }

      for (c13_qb_ix = c13_i154; c13_qb_ix < 3; c13_qb_ix++) {
        c13_pb_ix = c13_qb_ix;
        c13_tc_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_pb_ix), 1, 2, 1, 0) - 1];
        c13_qb_b = c13_bb_mtmp;
        c13_n_p = (c13_tc_a < c13_qb_b);
        if (c13_n_p) {
          c13_bb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_pb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_cb_mtmp = c13_bb_mtmp;
    c13_d13 = c13_cb_mtmp;
    if (CV_SCRIPT_COND(0, 13, CV_RELATIONAL_EVAL(14U, 0U, 13, c13_d13, 0.0, -1,
          5U, c13_d13 >= 0.0))) {
      for (c13_i155 = 0; c13_i155 < 4; c13_i155++) {
        c13_b_L_opt_1[c13_i155] = c13_L_opt_5[c13_i155];
      }

      c13_o_ixstart = 1;
      c13_db_mtmp = c13_b_L_opt_1[0];
      c13_db_x = c13_db_mtmp;
      c13_rb_b = muDoubleScalarIsNaN(c13_db_x);
      if (c13_rb_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_rb_ix = 2;
        exitg13 = false;
        while ((exitg13 == false) && (c13_rb_ix < 5)) {
          c13_sb_ix = c13_rb_ix;
          c13_o_ixstart = c13_sb_ix;
          c13_eb_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_sb_ix), 1, 4, 1, 0) - 1];
          c13_sb_b = muDoubleScalarIsNaN(c13_eb_x);
          if (!c13_sb_b) {
            c13_db_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_sb_ix), 1, 4, 1, 0) - 1];
            exitg13 = true;
          } else {
            c13_rb_ix++;
          }
        }
      }

      if (c13_o_ixstart < 4) {
        c13_uc_a = c13_o_ixstart;
        c13_vc_a = c13_uc_a + 1;
        c13_i156 = c13_vc_a;
        c13_wc_a = c13_i156;
        c13_xc_a = c13_wc_a;
        if (c13_xc_a > 4) {
          c13_o_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_o_overflow = false;
        }

        if (c13_o_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_o_overflow);
        }

        for (c13_tb_ix = c13_i156; c13_tb_ix < 5; c13_tb_ix++) {
          c13_sb_ix = c13_tb_ix;
          c13_yc_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_sb_ix), 1, 4, 1, 0) - 1];
          c13_tb_b = c13_db_mtmp;
          c13_o_p = (c13_yc_a < c13_tb_b);
          if (c13_o_p) {
            c13_db_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_sb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_eb_mtmp = c13_db_mtmp;
      c13_d14 = c13_eb_mtmp;
      if (CV_SCRIPT_COND(0, 14, CV_RELATIONAL_EVAL(14U, 0U, 14, c13_d14, 0.0, -1,
            5U, c13_d14 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 4, true);
        CV_SCRIPT_IF(0, 4, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 78);
        for (c13_i157 = 0; c13_i157 < 2; c13_i157++) {
          c13_u_opt[c13_i157] = c13_u_opt_5[c13_i157];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 79);
        for (c13_i158 = 0; c13_i158 < 4; c13_i158++) {
          c13_L_opt[c13_i158] = c13_L_opt_5[c13_i158];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 80);
        c13_case_n = 5.0;
      } else {
        guard9 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 == true) {
    guard9 = true;
  }

  if (guard9 == true) {
    CV_SCRIPT_MCDC(0, 4, false);
    CV_SCRIPT_IF(0, 4, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 84);
  for (c13_i159 = 0; c13_i159 < 2; c13_i159++) {
    c13_b_u_opt_1[c13_i159] = c13_u_opt_6[c13_i159] - c13_UB[c13_i159];
  }

  c13_p_ixstart = 1;
  c13_fb_mtmp = c13_b_u_opt_1[0];
  c13_fb_x = c13_fb_mtmp;
  c13_ub_b = muDoubleScalarIsNaN(c13_fb_x);
  if (c13_ub_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_ub_ix = 2;
    exitg12 = false;
    while ((exitg12 == false) && (c13_ub_ix < 3)) {
      c13_vb_ix = c13_ub_ix;
      c13_p_ixstart = c13_vb_ix;
      c13_gb_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_vb_ix), 1, 2, 1, 0) - 1];
      c13_vb_b = muDoubleScalarIsNaN(c13_gb_x);
      if (!c13_vb_b) {
        c13_fb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_vb_ix), 1, 2, 1, 0) - 1];
        exitg12 = true;
      } else {
        c13_ub_ix++;
      }
    }
  }

  if (c13_p_ixstart < 2) {
    c13_ad_a = c13_p_ixstart;
    c13_bd_a = c13_ad_a + 1;
    c13_i160 = c13_bd_a;
    c13_cd_a = c13_i160;
    c13_dd_a = c13_cd_a;
    if (c13_dd_a > 2) {
      c13_p_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_p_overflow = false;
    }

    if (c13_p_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_p_overflow);
    }

    for (c13_wb_ix = c13_i160; c13_wb_ix < 3; c13_wb_ix++) {
      c13_vb_ix = c13_wb_ix;
      c13_ed_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_vb_ix), 1, 2, 1, 0) - 1];
      c13_wb_b = c13_fb_mtmp;
      c13_p_p = (c13_ed_a > c13_wb_b);
      if (c13_p_p) {
        c13_fb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_vb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_gb_mtmp = c13_fb_mtmp;
  c13_d15 = c13_gb_mtmp;
  guard7 = false;
  guard8 = false;
  if (CV_SCRIPT_COND(0, 15, CV_RELATIONAL_EVAL(14U, 0U, 15, c13_d15, 0.0, -1, 3U,
        c13_d15 <= 0.0))) {
    for (c13_i161 = 0; c13_i161 < 2; c13_i161++) {
      c13_b_u_opt_1[c13_i161] = c13_u_opt_6[c13_i161] - c13_LB[c13_i161];
    }

    c13_q_ixstart = 1;
    c13_hb_mtmp = c13_b_u_opt_1[0];
    c13_hb_x = c13_hb_mtmp;
    c13_xb_b = muDoubleScalarIsNaN(c13_hb_x);
    if (c13_xb_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_xb_ix = 2;
      exitg11 = false;
      while ((exitg11 == false) && (c13_xb_ix < 3)) {
        c13_yb_ix = c13_xb_ix;
        c13_q_ixstart = c13_yb_ix;
        c13_ib_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_yb_ix), 1, 2, 1, 0) - 1];
        c13_yb_b = muDoubleScalarIsNaN(c13_ib_x);
        if (!c13_yb_b) {
          c13_hb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_yb_ix), 1, 2, 1, 0) - 1];
          exitg11 = true;
        } else {
          c13_xb_ix++;
        }
      }
    }

    if (c13_q_ixstart < 2) {
      c13_fd_a = c13_q_ixstart;
      c13_gd_a = c13_fd_a + 1;
      c13_i162 = c13_gd_a;
      c13_hd_a = c13_i162;
      c13_id_a = c13_hd_a;
      if (c13_id_a > 2) {
        c13_q_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_q_overflow = false;
      }

      if (c13_q_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_q_overflow);
      }

      for (c13_ac_ix = c13_i162; c13_ac_ix < 3; c13_ac_ix++) {
        c13_yb_ix = c13_ac_ix;
        c13_jd_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_yb_ix), 1, 2, 1, 0) - 1];
        c13_ac_b = c13_hb_mtmp;
        c13_q_p = (c13_jd_a < c13_ac_b);
        if (c13_q_p) {
          c13_hb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_yb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_ib_mtmp = c13_hb_mtmp;
    c13_d16 = c13_ib_mtmp;
    if (CV_SCRIPT_COND(0, 16, CV_RELATIONAL_EVAL(14U, 0U, 16, c13_d16, 0.0, -1,
          5U, c13_d16 >= 0.0))) {
      for (c13_i163 = 0; c13_i163 < 4; c13_i163++) {
        c13_b_L_opt_1[c13_i163] = c13_L_opt_6[c13_i163];
      }

      c13_r_ixstart = 1;
      c13_jb_mtmp = c13_b_L_opt_1[0];
      c13_jb_x = c13_jb_mtmp;
      c13_bc_b = muDoubleScalarIsNaN(c13_jb_x);
      if (c13_bc_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_bc_ix = 2;
        exitg10 = false;
        while ((exitg10 == false) && (c13_bc_ix < 5)) {
          c13_cc_ix = c13_bc_ix;
          c13_r_ixstart = c13_cc_ix;
          c13_kb_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_cc_ix), 1, 4, 1, 0) - 1];
          c13_cc_b = muDoubleScalarIsNaN(c13_kb_x);
          if (!c13_cc_b) {
            c13_jb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_cc_ix), 1, 4, 1, 0) - 1];
            exitg10 = true;
          } else {
            c13_bc_ix++;
          }
        }
      }

      if (c13_r_ixstart < 4) {
        c13_kd_a = c13_r_ixstart;
        c13_ld_a = c13_kd_a + 1;
        c13_i164 = c13_ld_a;
        c13_md_a = c13_i164;
        c13_nd_a = c13_md_a;
        if (c13_nd_a > 4) {
          c13_r_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_r_overflow = false;
        }

        if (c13_r_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_r_overflow);
        }

        for (c13_dc_ix = c13_i164; c13_dc_ix < 5; c13_dc_ix++) {
          c13_cc_ix = c13_dc_ix;
          c13_od_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_cc_ix), 1, 4, 1, 0) - 1];
          c13_dc_b = c13_jb_mtmp;
          c13_r_p = (c13_od_a < c13_dc_b);
          if (c13_r_p) {
            c13_jb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_cc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_kb_mtmp = c13_jb_mtmp;
      c13_d17 = c13_kb_mtmp;
      if (CV_SCRIPT_COND(0, 17, CV_RELATIONAL_EVAL(14U, 0U, 17, c13_d17, 0.0, -1,
            5U, c13_d17 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 5, true);
        CV_SCRIPT_IF(0, 5, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 85);
        for (c13_i165 = 0; c13_i165 < 2; c13_i165++) {
          c13_u_opt[c13_i165] = c13_u_opt_6[c13_i165];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 86);
        for (c13_i166 = 0; c13_i166 < 4; c13_i166++) {
          c13_L_opt[c13_i166] = c13_L_opt_6[c13_i166];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 87);
        c13_case_n = 6.0;
      } else {
        guard7 = true;
      }
    } else {
      guard8 = true;
    }
  } else {
    guard8 = true;
  }

  if (guard8 == true) {
    guard7 = true;
  }

  if (guard7 == true) {
    CV_SCRIPT_MCDC(0, 5, false);
    CV_SCRIPT_IF(0, 5, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 91);
  for (c13_i167 = 0; c13_i167 < 2; c13_i167++) {
    c13_b_u_opt_1[c13_i167] = c13_u_opt_7[c13_i167] - c13_UB[c13_i167];
  }

  c13_s_ixstart = 1;
  c13_lb_mtmp = c13_b_u_opt_1[0];
  c13_lb_x = c13_lb_mtmp;
  c13_ec_b = muDoubleScalarIsNaN(c13_lb_x);
  if (c13_ec_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_ec_ix = 2;
    exitg9 = false;
    while ((exitg9 == false) && (c13_ec_ix < 3)) {
      c13_fc_ix = c13_ec_ix;
      c13_s_ixstart = c13_fc_ix;
      c13_mb_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_fc_ix), 1, 2, 1, 0) - 1];
      c13_fc_b = muDoubleScalarIsNaN(c13_mb_x);
      if (!c13_fc_b) {
        c13_lb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_fc_ix), 1, 2, 1, 0) - 1];
        exitg9 = true;
      } else {
        c13_ec_ix++;
      }
    }
  }

  if (c13_s_ixstart < 2) {
    c13_pd_a = c13_s_ixstart;
    c13_qd_a = c13_pd_a + 1;
    c13_i168 = c13_qd_a;
    c13_rd_a = c13_i168;
    c13_sd_a = c13_rd_a;
    if (c13_sd_a > 2) {
      c13_s_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_s_overflow = false;
    }

    if (c13_s_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_s_overflow);
    }

    for (c13_gc_ix = c13_i168; c13_gc_ix < 3; c13_gc_ix++) {
      c13_fc_ix = c13_gc_ix;
      c13_td_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_fc_ix), 1, 2, 1, 0) - 1];
      c13_gc_b = c13_lb_mtmp;
      c13_s_p = (c13_td_a > c13_gc_b);
      if (c13_s_p) {
        c13_lb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_fc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_mb_mtmp = c13_lb_mtmp;
  c13_d18 = c13_mb_mtmp;
  guard5 = false;
  guard6 = false;
  if (CV_SCRIPT_COND(0, 18, CV_RELATIONAL_EVAL(14U, 0U, 18, c13_d18, 0.0, -1, 3U,
        c13_d18 <= 0.0))) {
    for (c13_i169 = 0; c13_i169 < 2; c13_i169++) {
      c13_b_u_opt_1[c13_i169] = c13_u_opt_7[c13_i169] - c13_LB[c13_i169];
    }

    c13_t_ixstart = 1;
    c13_nb_mtmp = c13_b_u_opt_1[0];
    c13_nb_x = c13_nb_mtmp;
    c13_hc_b = muDoubleScalarIsNaN(c13_nb_x);
    if (c13_hc_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_hc_ix = 2;
      exitg8 = false;
      while ((exitg8 == false) && (c13_hc_ix < 3)) {
        c13_ic_ix = c13_hc_ix;
        c13_t_ixstart = c13_ic_ix;
        c13_ob_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_ic_ix), 1, 2, 1, 0) - 1];
        c13_ic_b = muDoubleScalarIsNaN(c13_ob_x);
        if (!c13_ic_b) {
          c13_nb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ic_ix), 1, 2, 1, 0) - 1];
          exitg8 = true;
        } else {
          c13_hc_ix++;
        }
      }
    }

    if (c13_t_ixstart < 2) {
      c13_ud_a = c13_t_ixstart;
      c13_vd_a = c13_ud_a + 1;
      c13_i170 = c13_vd_a;
      c13_wd_a = c13_i170;
      c13_xd_a = c13_wd_a;
      if (c13_xd_a > 2) {
        c13_t_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_t_overflow = false;
      }

      if (c13_t_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_t_overflow);
      }

      for (c13_jc_ix = c13_i170; c13_jc_ix < 3; c13_jc_ix++) {
        c13_ic_ix = c13_jc_ix;
        c13_yd_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_ic_ix), 1, 2, 1, 0) - 1];
        c13_jc_b = c13_nb_mtmp;
        c13_t_p = (c13_yd_a < c13_jc_b);
        if (c13_t_p) {
          c13_nb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ic_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_ob_mtmp = c13_nb_mtmp;
    c13_d19 = c13_ob_mtmp;
    if (CV_SCRIPT_COND(0, 19, CV_RELATIONAL_EVAL(14U, 0U, 19, c13_d19, 0.0, -1,
          5U, c13_d19 >= 0.0))) {
      for (c13_i171 = 0; c13_i171 < 4; c13_i171++) {
        c13_b_L_opt_1[c13_i171] = c13_L_opt_7[c13_i171];
      }

      c13_u_ixstart = 1;
      c13_pb_mtmp = c13_b_L_opt_1[0];
      c13_pb_x = c13_pb_mtmp;
      c13_kc_b = muDoubleScalarIsNaN(c13_pb_x);
      if (c13_kc_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_kc_ix = 2;
        exitg7 = false;
        while ((exitg7 == false) && (c13_kc_ix < 5)) {
          c13_lc_ix = c13_kc_ix;
          c13_u_ixstart = c13_lc_ix;
          c13_qb_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_lc_ix), 1, 4, 1, 0) - 1];
          c13_lc_b = muDoubleScalarIsNaN(c13_qb_x);
          if (!c13_lc_b) {
            c13_pb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_lc_ix), 1, 4, 1, 0) - 1];
            exitg7 = true;
          } else {
            c13_kc_ix++;
          }
        }
      }

      if (c13_u_ixstart < 4) {
        c13_ae_a = c13_u_ixstart;
        c13_be_a = c13_ae_a + 1;
        c13_i172 = c13_be_a;
        c13_ce_a = c13_i172;
        c13_de_a = c13_ce_a;
        if (c13_de_a > 4) {
          c13_u_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_u_overflow = false;
        }

        if (c13_u_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_u_overflow);
        }

        for (c13_mc_ix = c13_i172; c13_mc_ix < 5; c13_mc_ix++) {
          c13_lc_ix = c13_mc_ix;
          c13_ee_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_lc_ix), 1, 4, 1, 0) - 1];
          c13_mc_b = c13_pb_mtmp;
          c13_u_p = (c13_ee_a < c13_mc_b);
          if (c13_u_p) {
            c13_pb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_lc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_qb_mtmp = c13_pb_mtmp;
      c13_d20 = c13_qb_mtmp;
      if (CV_SCRIPT_COND(0, 20, CV_RELATIONAL_EVAL(14U, 0U, 20, c13_d20, 0.0, -1,
            5U, c13_d20 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 6, true);
        CV_SCRIPT_IF(0, 6, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 92);
        for (c13_i173 = 0; c13_i173 < 2; c13_i173++) {
          c13_u_opt[c13_i173] = c13_u_opt_7[c13_i173];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 93);
        for (c13_i174 = 0; c13_i174 < 4; c13_i174++) {
          c13_L_opt[c13_i174] = c13_L_opt_7[c13_i174];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 94);
        c13_case_n = 7.0;
      } else {
        guard5 = true;
      }
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    guard5 = true;
  }

  if (guard5 == true) {
    CV_SCRIPT_MCDC(0, 6, false);
    CV_SCRIPT_IF(0, 6, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 98);
  for (c13_i175 = 0; c13_i175 < 2; c13_i175++) {
    c13_b_u_opt_1[c13_i175] = c13_u_opt_8[c13_i175] - c13_UB[c13_i175];
  }

  c13_v_ixstart = 1;
  c13_rb_mtmp = c13_b_u_opt_1[0];
  c13_rb_x = c13_rb_mtmp;
  c13_nc_b = muDoubleScalarIsNaN(c13_rb_x);
  if (c13_nc_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_nc_ix = 2;
    exitg6 = false;
    while ((exitg6 == false) && (c13_nc_ix < 3)) {
      c13_oc_ix = c13_nc_ix;
      c13_v_ixstart = c13_oc_ix;
      c13_sb_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_oc_ix), 1, 2, 1, 0) - 1];
      c13_oc_b = muDoubleScalarIsNaN(c13_sb_x);
      if (!c13_oc_b) {
        c13_rb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_oc_ix), 1, 2, 1, 0) - 1];
        exitg6 = true;
      } else {
        c13_nc_ix++;
      }
    }
  }

  if (c13_v_ixstart < 2) {
    c13_fe_a = c13_v_ixstart;
    c13_ge_a = c13_fe_a + 1;
    c13_i176 = c13_ge_a;
    c13_he_a = c13_i176;
    c13_ie_a = c13_he_a;
    if (c13_ie_a > 2) {
      c13_v_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_v_overflow = false;
    }

    if (c13_v_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_v_overflow);
    }

    for (c13_pc_ix = c13_i176; c13_pc_ix < 3; c13_pc_ix++) {
      c13_oc_ix = c13_pc_ix;
      c13_je_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_oc_ix), 1, 2, 1, 0) - 1];
      c13_pc_b = c13_rb_mtmp;
      c13_v_p = (c13_je_a > c13_pc_b);
      if (c13_v_p) {
        c13_rb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_oc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_sb_mtmp = c13_rb_mtmp;
  c13_d21 = c13_sb_mtmp;
  guard3 = false;
  guard4 = false;
  if (CV_SCRIPT_COND(0, 21, CV_RELATIONAL_EVAL(14U, 0U, 21, c13_d21, 0.0, -1, 3U,
        c13_d21 <= 0.0))) {
    for (c13_i177 = 0; c13_i177 < 2; c13_i177++) {
      c13_b_u_opt_1[c13_i177] = c13_u_opt_8[c13_i177] - c13_LB[c13_i177];
    }

    c13_w_ixstart = 1;
    c13_tb_mtmp = c13_b_u_opt_1[0];
    c13_tb_x = c13_tb_mtmp;
    c13_qc_b = muDoubleScalarIsNaN(c13_tb_x);
    if (c13_qc_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_qc_ix = 2;
      exitg5 = false;
      while ((exitg5 == false) && (c13_qc_ix < 3)) {
        c13_rc_ix = c13_qc_ix;
        c13_w_ixstart = c13_rc_ix;
        c13_ub_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_rc_ix), 1, 2, 1, 0) - 1];
        c13_rc_b = muDoubleScalarIsNaN(c13_ub_x);
        if (!c13_rc_b) {
          c13_tb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_rc_ix), 1, 2, 1, 0) - 1];
          exitg5 = true;
        } else {
          c13_qc_ix++;
        }
      }
    }

    if (c13_w_ixstart < 2) {
      c13_ke_a = c13_w_ixstart;
      c13_le_a = c13_ke_a + 1;
      c13_i178 = c13_le_a;
      c13_me_a = c13_i178;
      c13_ne_a = c13_me_a;
      if (c13_ne_a > 2) {
        c13_w_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_w_overflow = false;
      }

      if (c13_w_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_w_overflow);
      }

      for (c13_sc_ix = c13_i178; c13_sc_ix < 3; c13_sc_ix++) {
        c13_rc_ix = c13_sc_ix;
        c13_oe_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_rc_ix), 1, 2, 1, 0) - 1];
        c13_sc_b = c13_tb_mtmp;
        c13_w_p = (c13_oe_a < c13_sc_b);
        if (c13_w_p) {
          c13_tb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_rc_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_ub_mtmp = c13_tb_mtmp;
    c13_d22 = c13_ub_mtmp;
    if (CV_SCRIPT_COND(0, 22, CV_RELATIONAL_EVAL(14U, 0U, 22, c13_d22, 0.0, -1,
          5U, c13_d22 >= 0.0))) {
      for (c13_i179 = 0; c13_i179 < 4; c13_i179++) {
        c13_b_L_opt_1[c13_i179] = c13_L_opt_8[c13_i179];
      }

      c13_x_ixstart = 1;
      c13_vb_mtmp = c13_b_L_opt_1[0];
      c13_vb_x = c13_vb_mtmp;
      c13_tc_b = muDoubleScalarIsNaN(c13_vb_x);
      if (c13_tc_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_tc_ix = 2;
        exitg4 = false;
        while ((exitg4 == false) && (c13_tc_ix < 5)) {
          c13_uc_ix = c13_tc_ix;
          c13_x_ixstart = c13_uc_ix;
          c13_wb_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_uc_ix), 1, 4, 1, 0) - 1];
          c13_uc_b = muDoubleScalarIsNaN(c13_wb_x);
          if (!c13_uc_b) {
            c13_vb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_uc_ix), 1, 4, 1, 0) - 1];
            exitg4 = true;
          } else {
            c13_tc_ix++;
          }
        }
      }

      if (c13_x_ixstart < 4) {
        c13_pe_a = c13_x_ixstart;
        c13_qe_a = c13_pe_a + 1;
        c13_i180 = c13_qe_a;
        c13_re_a = c13_i180;
        c13_se_a = c13_re_a;
        if (c13_se_a > 4) {
          c13_x_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_x_overflow = false;
        }

        if (c13_x_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_x_overflow);
        }

        for (c13_vc_ix = c13_i180; c13_vc_ix < 5; c13_vc_ix++) {
          c13_uc_ix = c13_vc_ix;
          c13_te_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_uc_ix), 1, 4, 1, 0) - 1];
          c13_vc_b = c13_vb_mtmp;
          c13_x_p = (c13_te_a < c13_vc_b);
          if (c13_x_p) {
            c13_vb_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_uc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_wb_mtmp = c13_vb_mtmp;
      c13_d23 = c13_wb_mtmp;
      if (CV_SCRIPT_COND(0, 23, CV_RELATIONAL_EVAL(14U, 0U, 23, c13_d23, 0.0, -1,
            5U, c13_d23 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 7, true);
        CV_SCRIPT_IF(0, 7, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 99);
        for (c13_i181 = 0; c13_i181 < 2; c13_i181++) {
          c13_u_opt[c13_i181] = c13_u_opt_8[c13_i181];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 100);
        for (c13_i182 = 0; c13_i182 < 4; c13_i182++) {
          c13_L_opt[c13_i182] = c13_L_opt_8[c13_i182];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 101);
        c13_case_n = 8.0;
      } else {
        guard3 = true;
      }
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    guard3 = true;
  }

  if (guard3 == true) {
    CV_SCRIPT_MCDC(0, 7, false);
    CV_SCRIPT_IF(0, 7, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 105);
  for (c13_i183 = 0; c13_i183 < 2; c13_i183++) {
    c13_b_u_opt_1[c13_i183] = c13_u_opt_9[c13_i183] - c13_UB[c13_i183];
  }

  c13_y_ixstart = 1;
  c13_xb_mtmp = c13_b_u_opt_1[0];
  c13_xb_x = c13_xb_mtmp;
  c13_wc_b = muDoubleScalarIsNaN(c13_xb_x);
  if (c13_wc_b) {
    c13_eml_switch_helper(chartInstance);
    c13_eml_switch_helper(chartInstance);
    c13_wc_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c13_wc_ix < 3)) {
      c13_xc_ix = c13_wc_ix;
      c13_y_ixstart = c13_xc_ix;
      c13_yb_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_xc_ix), 1, 2, 1, 0) - 1];
      c13_xc_b = muDoubleScalarIsNaN(c13_yb_x);
      if (!c13_xc_b) {
        c13_xb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_xc_ix), 1, 2, 1, 0) - 1];
        exitg3 = true;
      } else {
        c13_wc_ix++;
      }
    }
  }

  if (c13_y_ixstart < 2) {
    c13_ue_a = c13_y_ixstart;
    c13_ve_a = c13_ue_a + 1;
    c13_i184 = c13_ve_a;
    c13_we_a = c13_i184;
    c13_xe_a = c13_we_a;
    if (c13_xe_a > 2) {
      c13_y_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_y_overflow = false;
    }

    if (c13_y_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_y_overflow);
    }

    for (c13_yc_ix = c13_i184; c13_yc_ix < 3; c13_yc_ix++) {
      c13_xc_ix = c13_yc_ix;
      c13_ye_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_xc_ix), 1, 2, 1, 0) - 1];
      c13_yc_b = c13_xb_mtmp;
      c13_y_p = (c13_ye_a > c13_yc_b);
      if (c13_y_p) {
        c13_xb_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_xc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c13_yb_mtmp = c13_xb_mtmp;
  c13_d24 = c13_yb_mtmp;
  guard1 = false;
  guard2 = false;
  if (CV_SCRIPT_COND(0, 24, CV_RELATIONAL_EVAL(14U, 0U, 24, c13_d24, 0.0, -1, 3U,
        c13_d24 <= 0.0))) {
    for (c13_i185 = 0; c13_i185 < 2; c13_i185++) {
      c13_b_u_opt_1[c13_i185] = c13_u_opt_9[c13_i185] - c13_LB[c13_i185];
    }

    c13_ab_ixstart = 1;
    c13_ac_mtmp = c13_b_u_opt_1[0];
    c13_ac_x = c13_ac_mtmp;
    c13_ad_b = muDoubleScalarIsNaN(c13_ac_x);
    if (c13_ad_b) {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_ad_ix = 2;
      exitg2 = false;
      while ((exitg2 == false) && (c13_ad_ix < 3)) {
        c13_bd_ix = c13_ad_ix;
        c13_ab_ixstart = c13_bd_ix;
        c13_bc_x = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_bd_ix), 1, 2, 1, 0) - 1];
        c13_bd_b = muDoubleScalarIsNaN(c13_bc_x);
        if (!c13_bd_b) {
          c13_ac_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_bd_ix), 1, 2, 1, 0) - 1];
          exitg2 = true;
        } else {
          c13_ad_ix++;
        }
      }
    }

    if (c13_ab_ixstart < 2) {
      c13_af_a = c13_ab_ixstart;
      c13_bf_a = c13_af_a + 1;
      c13_i186 = c13_bf_a;
      c13_cf_a = c13_i186;
      c13_df_a = c13_cf_a;
      if (c13_df_a > 2) {
        c13_ab_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_ab_overflow = false;
      }

      if (c13_ab_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_ab_overflow);
      }

      for (c13_cd_ix = c13_i186; c13_cd_ix < 3; c13_cd_ix++) {
        c13_bd_ix = c13_cd_ix;
        c13_ef_a = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_bd_ix), 1, 2, 1, 0) - 1];
        c13_cd_b = c13_ac_mtmp;
        c13_ab_p = (c13_ef_a < c13_cd_b);
        if (c13_ab_p) {
          c13_ac_mtmp = c13_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_bd_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c13_bc_mtmp = c13_ac_mtmp;
    c13_d25 = c13_bc_mtmp;
    if (CV_SCRIPT_COND(0, 25, CV_RELATIONAL_EVAL(14U, 0U, 25, c13_d25, 0.0, -1,
          5U, c13_d25 >= 0.0))) {
      for (c13_i187 = 0; c13_i187 < 4; c13_i187++) {
        c13_b_L_opt_1[c13_i187] = c13_L_opt_9[c13_i187];
      }

      c13_bb_ixstart = 1;
      c13_cc_mtmp = c13_b_L_opt_1[0];
      c13_cc_x = c13_cc_mtmp;
      c13_dd_b = muDoubleScalarIsNaN(c13_cc_x);
      if (c13_dd_b) {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_dd_ix = 2;
        exitg1 = false;
        while ((exitg1 == false) && (c13_dd_ix < 5)) {
          c13_ed_ix = c13_dd_ix;
          c13_bb_ixstart = c13_ed_ix;
          c13_dc_x = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ed_ix), 1, 4, 1, 0) - 1];
          c13_ed_b = muDoubleScalarIsNaN(c13_dc_x);
          if (!c13_ed_b) {
            c13_cc_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_ed_ix), 1, 4, 1, 0) - 1];
            exitg1 = true;
          } else {
            c13_dd_ix++;
          }
        }
      }

      if (c13_bb_ixstart < 4) {
        c13_ff_a = c13_bb_ixstart;
        c13_gf_a = c13_ff_a + 1;
        c13_i188 = c13_gf_a;
        c13_hf_a = c13_i188;
        c13_if_a = c13_hf_a;
        if (c13_if_a > 4) {
          c13_bb_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_bb_overflow = false;
        }

        if (c13_bb_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_bb_overflow);
        }

        for (c13_fd_ix = c13_i188; c13_fd_ix < 5; c13_fd_ix++) {
          c13_ed_ix = c13_fd_ix;
          c13_jf_a = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ed_ix), 1, 4, 1, 0) - 1];
          c13_fd_b = c13_cc_mtmp;
          c13_bb_p = (c13_jf_a < c13_fd_b);
          if (c13_bb_p) {
            c13_cc_mtmp = c13_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c13_ed_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c13_dc_mtmp = c13_cc_mtmp;
      c13_d26 = c13_dc_mtmp;
      if (CV_SCRIPT_COND(0, 26, CV_RELATIONAL_EVAL(14U, 0U, 26, c13_d26, 0.0, -1,
            5U, c13_d26 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 8, true);
        CV_SCRIPT_IF(0, 8, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 106);
        for (c13_i189 = 0; c13_i189 < 2; c13_i189++) {
          c13_u_opt[c13_i189] = c13_u_opt_9[c13_i189];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 107);
        for (c13_i190 = 0; c13_i190 < 4; c13_i190++) {
          c13_L_opt[c13_i190] = c13_L_opt_9[c13_i190];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 108);
        c13_case_n = 9.0;
      } else {
        guard1 = true;
      }
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(0, 8, false);
    CV_SCRIPT_IF(0, 8, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 111);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, -111);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_1(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[7];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i191;
  real_T c13_A;
  real_T c13_B;
  real_T c13_y;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_b_y;
  real_T c13_c_A;
  real_T c13_c_B;
  real_T c13_c_y;
  real_T c13_d_A;
  real_T c13_d_B;
  real_T c13_d_y;
  int32_T c13_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c13_b_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 5U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 6U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 9);
  for (c13_i191 = 0; c13_i191 < 2; c13_i191++) {
    c13_u_opt[c13_i191] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 10);
  c13_A = -((2.0 * c13_u_LS + c13_u_LA * c13_w) * (c13_w - 4.0));
  c13_B = 8.0 * c13_w;
  c13_y = c13_rdivide(chartInstance, c13_A, c13_B);
  c13_b_A = (2.0 * c13_u_LS - c13_u_LA * c13_w) * (c13_w + 4.0);
  c13_b_B = 8.0 * c13_w;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, c13_b_B);
  c13_u_opt[0] = c13_y - c13_b_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 11);
  c13_c_A = (2.0 * c13_u_LS + c13_u_LA * c13_w) * (c13_w + 4.0);
  c13_c_B = 8.0 * c13_w;
  c13_c_y = c13_rdivide(chartInstance, c13_c_A, c13_c_B);
  c13_d_A = (2.0 * c13_u_LS - c13_u_LA * c13_w) * (c13_w - 4.0);
  c13_d_B = 8.0 * c13_w;
  c13_d_y = c13_rdivide(chartInstance, c13_d_A, c13_d_B);
  c13_u_opt[1] = c13_c_y + c13_d_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 14);
  for (c13_i192 = 0; c13_i192 < 4; c13_i192++) {
    c13_L_opt[c13_i192] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_2(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[8];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i193;
  real_T c13_A;
  real_T c13_B;
  real_T c13_y;
  int32_T c13_i194;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c13_c_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_min, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 7U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 9);
  for (c13_i193 = 0; c13_i193 < 2; c13_i193++) {
    c13_u_opt[c13_i193] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_min;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 11);
  c13_A = ((4.0 * c13_u1_min + 4.0 * c13_u_LS) - c13_u1_min * c13_w) + 2.0 *
    c13_u_LA * c13_w;
  c13_B = c13_w + 4.0;
  c13_y = c13_rdivide(chartInstance, c13_A, c13_B);
  c13_u_opt[1] = c13_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 14);
  for (c13_i194 = 0; c13_i194 < 4; c13_i194++) {
    c13_L_opt[c13_i194] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 15);
  c13_b_A = (8.0 * c13_u1_min * c13_w - 8.0 * c13_u_LA * c13_w) + 4.0 * c13_u_LS
    * c13_w;
  c13_b_B = c13_w + 4.0;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, c13_b_B);
  c13_L_opt[0] = c13_b_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(2U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_3(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[8];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i195;
  real_T c13_A;
  real_T c13_B;
  real_T c13_y;
  int32_T c13_i196;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c13_d_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_max, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 7U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 9);
  for (c13_i195 = 0; c13_i195 < 2; c13_i195++) {
    c13_u_opt[c13_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_max;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 11);
  c13_A = ((4.0 * c13_u1_max + 4.0 * c13_u_LS) - c13_u1_max * c13_w) + 2.0 *
    c13_u_LA * c13_w;
  c13_B = c13_w + 4.0;
  c13_y = c13_rdivide(chartInstance, c13_A, c13_B);
  c13_u_opt[1] = c13_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 14);
  for (c13_i196 = 0; c13_i196 < 4; c13_i196++) {
    c13_L_opt[c13_i196] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 16);
  c13_b_A = -((8.0 * c13_u1_max * c13_w - 8.0 * c13_u_LA * c13_w) + 4.0 *
              c13_u_LS * c13_w);
  c13_b_B = c13_w + 4.0;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, c13_b_B);
  c13_L_opt[1] = c13_b_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(3U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_4(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[8];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i197;
  real_T c13_A;
  real_T c13_B;
  real_T c13_y;
  int32_T c13_i198;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c13_e_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_min, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 7U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 9);
  for (c13_i197 = 0; c13_i197 < 2; c13_i197++) {
    c13_u_opt[c13_i197] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 10);
  c13_A = ((4.0 * c13_u2_min - 4.0 * c13_u_LS) - c13_u2_min * c13_w) + 2.0 *
    c13_u_LA * c13_w;
  c13_B = c13_w + 4.0;
  c13_y = c13_rdivide(chartInstance, c13_A, c13_B);
  c13_u_opt[0] = c13_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_min;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 14);
  for (c13_i198 = 0; c13_i198 < 4; c13_i198++) {
    c13_L_opt[c13_i198] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 17);
  c13_b_A = -((8.0 * c13_u_LA * c13_w - 8.0 * c13_u2_min * c13_w) + 4.0 *
              c13_u_LS * c13_w);
  c13_b_B = c13_w + 4.0;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, c13_b_B);
  c13_L_opt[2] = c13_b_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(4U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_5(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[8];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i199;
  real_T c13_A;
  real_T c13_B;
  real_T c13_y;
  int32_T c13_i200;
  real_T c13_b_A;
  real_T c13_b_B;
  real_T c13_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c13_f_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_max, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 6U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 7U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 9);
  for (c13_i199 = 0; c13_i199 < 2; c13_i199++) {
    c13_u_opt[c13_i199] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 10);
  c13_A = ((4.0 * c13_u2_max - 4.0 * c13_u_LS) - c13_u2_max * c13_w) + 2.0 *
    c13_u_LA * c13_w;
  c13_B = c13_w + 4.0;
  c13_y = c13_rdivide(chartInstance, c13_A, c13_B);
  c13_u_opt[0] = c13_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_max;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 14);
  for (c13_i200 = 0; c13_i200 < 4; c13_i200++) {
    c13_L_opt[c13_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 18);
  c13_b_A = (8.0 * c13_u_LA * c13_w - 8.0 * c13_u2_max * c13_w) + 4.0 * c13_u_LS
    * c13_w;
  c13_b_B = c13_w + 4.0;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, c13_b_B);
  c13_L_opt[3] = c13_b_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(5U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_6(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[9];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i201;
  int32_T c13_i202;
  real_T c13_A;
  real_T c13_y;
  real_T c13_b_A;
  real_T c13_b_y;
  real_T c13_c_A;
  real_T c13_c_y;
  real_T c13_d_A;
  real_T c13_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c13_g_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_min, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_min, 6U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 7U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 8U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 9);
  for (c13_i201 = 0; c13_i201 < 2; c13_i201++) {
    c13_u_opt[c13_i201] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 14);
  for (c13_i202 = 0; c13_i202 < 4; c13_i202++) {
    c13_L_opt[c13_i202] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 15);
  c13_A = c13_u1_min;
  c13_y = c13_rdivide(chartInstance, c13_A, 2.0);
  c13_b_A = c13_u2_min;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, 2.0);
  c13_L_opt[0] = ((2.0 * c13_u1_min - 2.0 * c13_u2_min) + 2.0 * c13_u_LS) +
    c13_w * ((c13_y + c13_b_y) - c13_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 17);
  c13_c_A = c13_u1_min;
  c13_c_y = c13_rdivide(chartInstance, c13_c_A, 2.0);
  c13_d_A = c13_u2_min;
  c13_d_y = c13_rdivide(chartInstance, c13_d_A, 2.0);
  c13_L_opt[2] = ((2.0 * c13_u2_min - 2.0 * c13_u1_min) - 2.0 * c13_u_LS) +
    c13_w * ((c13_c_y + c13_d_y) - c13_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(6U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_7(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_min, real_T c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[9];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i203;
  int32_T c13_i204;
  real_T c13_A;
  real_T c13_y;
  real_T c13_b_A;
  real_T c13_b_y;
  real_T c13_c_A;
  real_T c13_c_y;
  real_T c13_d_A;
  real_T c13_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c13_h_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_min, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_max, 6U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 7U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 8U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(7, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 9);
  for (c13_i203 = 0; c13_i203 < 2; c13_i203++) {
    c13_u_opt[c13_i203] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_min;
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_max;
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 14);
  for (c13_i204 = 0; c13_i204 < 4; c13_i204++) {
    c13_L_opt[c13_i204] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 15);
  c13_A = c13_u1_min;
  c13_y = c13_rdivide(chartInstance, c13_A, 2.0);
  c13_b_A = c13_u2_max;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, 2.0);
  c13_L_opt[0] = ((2.0 * c13_u1_min - 2.0 * c13_u2_max) + 2.0 * c13_u_LS) +
    c13_w * ((c13_y + c13_b_y) - c13_u_LA);
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 16);
  c13_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 18);
  c13_c_A = c13_u1_min * c13_w;
  c13_c_y = c13_rdivide(chartInstance, c13_c_A, 2.0);
  c13_d_A = c13_u2_max * c13_w;
  c13_d_y = c13_rdivide(chartInstance, c13_d_A, 2.0);
  c13_L_opt[3] = ((((2.0 * c13_u1_min - 2.0 * c13_u2_max) + 2.0 * c13_u_LS) -
                   c13_c_y) - c13_d_y) + c13_u_LA * c13_w;
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(7U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_8(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u2_min, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[9];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i205;
  int32_T c13_i206;
  real_T c13_A;
  real_T c13_y;
  real_T c13_b_A;
  real_T c13_b_y;
  real_T c13_c_A;
  real_T c13_c_y;
  real_T c13_d_A;
  real_T c13_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c13_i_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_max, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_min, 6U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 7U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 8U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(8, 0);
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 9);
  for (c13_i205 = 0; c13_i205 < 2; c13_i205++) {
    c13_u_opt[c13_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_max;
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_min;
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 14);
  for (c13_i206 = 0; c13_i206 < 4; c13_i206++) {
    c13_L_opt[c13_i206] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 16);
  c13_A = c13_u2_min * c13_w;
  c13_y = c13_rdivide(chartInstance, c13_A, 2.0);
  c13_b_A = c13_u1_max * c13_w;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, 2.0);
  c13_L_opt[1] = ((((2.0 * c13_u2_min - 2.0 * c13_u1_max) - 2.0 * c13_u_LS) -
                   c13_y) - c13_b_y) + c13_u_LA * c13_w;
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 17);
  c13_c_A = c13_u2_min;
  c13_c_y = c13_rdivide(chartInstance, c13_c_A, 2.0);
  c13_d_A = c13_u1_max;
  c13_d_y = c13_rdivide(chartInstance, c13_d_A, 2.0);
  c13_L_opt[2] = ((2.0 * c13_u2_min - 2.0 * c13_u1_max) - 2.0 * c13_u_LS) +
    c13_w * ((c13_c_y + c13_d_y) - c13_u_LA);
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 18);
  c13_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(8U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c13_LA_LS_Revised_Saturation_Case_9(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_u_LS, real_T c13_u_LA, real_T c13_w, real_T
  c13_u1_max, real_T c13_u2_max, real_T c13_u_opt[2], real_T c13_L_opt[4])
{
  uint32_T c13_debug_family_var_map[9];
  real_T c13_nargin = 7.0;
  real_T c13_nargout = 2.0;
  int32_T c13_i207;
  int32_T c13_i208;
  real_T c13_A;
  real_T c13_y;
  real_T c13_b_A;
  real_T c13_b_y;
  real_T c13_c_A;
  real_T c13_c_y;
  real_T c13_d_A;
  real_T c13_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c13_j_debug_family_names,
    c13_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LS, 2U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u_LA, 3U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_w, 4U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u1_max, 5U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_u2_max, 6U, c13_e_sf_marshallOut,
    c13_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_u_opt, 7U, c13_d_sf_marshallOut,
    c13_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c13_L_opt, 8U, c13_g_sf_marshallOut,
    c13_e_sf_marshallIn);
  CV_SCRIPT_FCN(9, 0);
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 9);
  for (c13_i207 = 0; c13_i207 < 2; c13_i207++) {
    c13_u_opt[c13_i207] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 10);
  c13_u_opt[0] = c13_u1_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 11);
  c13_u_opt[1] = c13_u2_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 14);
  for (c13_i208 = 0; c13_i208 < 4; c13_i208++) {
    c13_L_opt[c13_i208] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 15);
  c13_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 16);
  c13_A = c13_u1_max * c13_w;
  c13_y = c13_rdivide(chartInstance, c13_A, 2.0);
  c13_b_A = c13_u2_max * c13_w;
  c13_b_y = c13_rdivide(chartInstance, c13_b_A, 2.0);
  c13_L_opt[1] = ((((2.0 * c13_u2_max - 2.0 * c13_u1_max) - 2.0 * c13_u_LS) -
                   c13_y) - c13_b_y) + c13_u_LA * c13_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 17);
  c13_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 18);
  c13_c_A = c13_u1_max * c13_w;
  c13_c_y = c13_rdivide(chartInstance, c13_c_A, 2.0);
  c13_d_A = c13_u2_max * c13_w;
  c13_d_y = c13_rdivide(chartInstance, c13_d_A, 2.0);
  c13_L_opt[3] = ((((2.0 * c13_u1_max - 2.0 * c13_u2_max) + 2.0 * c13_u_LS) -
                   c13_c_y) - c13_d_y) + c13_u_LA * c13_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, 19);
  _SFD_SCRIPT_CALL(9U, chartInstance->c13_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_1.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_2.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_3.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_4.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 5U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_5.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 6U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_6.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 7U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_7.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 8U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_8.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, c13_instanceNumber, 9U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_9.m"));
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i209;
  real_T c13_b_inData[6];
  int32_T c13_i210;
  real_T c13_b_u[6];
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i209 = 0; c13_i209 < 6; c13_i209++) {
    c13_b_inData[c13_i209] = (*(real_T (*)[6])c13_inData)[c13_i209];
  }

  for (c13_i210 = 0; c13_i210 < 6; c13_i210++) {
    c13_b_u[c13_i210] = c13_b_inData[c13_i210];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u_sat, const char_T *c13_identifier, real_T c13_y[6])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_u_sat), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_b_u_sat);
}

static void c13_b_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[6])
{
  real_T c13_dv4[6];
  int32_T c13_i211;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), c13_dv4, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c13_i211 = 0; c13_i211 < 6; c13_i211++) {
    c13_y[c13_i211] = c13_dv4[c13_i211];
  }

  sf_mex_destroy(&c13_b_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_u_sat;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[6];
  int32_T c13_i212;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_b_u_sat = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_u_sat), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_b_u_sat);
  for (c13_i212 = 0; c13_i212 < 6; c13_i212++) {
    (*(real_T (*)[6])c13_outData)[c13_i212] = c13_y[c13_i212];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData;
  c13_ControlParamsBus c13_b_u;
  const mxArray *c13_y = NULL;
  c13_SupervisoryParamsBus c13_c_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_e_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_f_u;
  const mxArray *c13_e_y = NULL;
  real_T c13_g_u;
  const mxArray *c13_f_y = NULL;
  real_T c13_h_u;
  const mxArray *c13_g_y = NULL;
  real_T c13_i_u;
  const mxArray *c13_h_y = NULL;
  real_T c13_j_u;
  const mxArray *c13_i_y = NULL;
  real_T c13_k_u;
  const mxArray *c13_j_y = NULL;
  real_T c13_l_u;
  const mxArray *c13_k_y = NULL;
  real_T c13_m_u;
  const mxArray *c13_l_y = NULL;
  real_T c13_n_u;
  const mxArray *c13_m_y = NULL;
  int32_T c13_i213;
  real_T c13_o_u[2];
  const mxArray *c13_n_y = NULL;
  real_T c13_p_u;
  const mxArray *c13_o_y = NULL;
  real_T c13_q_u;
  const mxArray *c13_p_y = NULL;
  int32_T c13_i214;
  real_T c13_r_u[6];
  const mxArray *c13_q_y = NULL;
  int32_T c13_i215;
  real_T c13_s_u[13];
  const mxArray *c13_r_y = NULL;
  int32_T c13_i216;
  real_T c13_t_u[5];
  const mxArray *c13_s_y = NULL;
  real_T c13_u_u;
  const mxArray *c13_t_y = NULL;
  real_T c13_v_u;
  const mxArray *c13_u_y = NULL;
  real_T c13_w_u;
  const mxArray *c13_v_y = NULL;
  real_T c13_x_u;
  const mxArray *c13_w_y = NULL;
  int32_T c13_i217;
  real_T c13_y_u[6];
  const mxArray *c13_x_y = NULL;
  int32_T c13_i218;
  real_T c13_ab_u[6];
  const mxArray *c13_y_y = NULL;
  real_T c13_bb_u;
  const mxArray *c13_ab_y = NULL;
  real_T c13_cb_u;
  const mxArray *c13_bb_y = NULL;
  real_T c13_db_u;
  const mxArray *c13_cb_y = NULL;
  real_T c13_eb_u;
  const mxArray *c13_db_y = NULL;
  real_T c13_fb_u;
  const mxArray *c13_eb_y = NULL;
  real_T c13_gb_u;
  const mxArray *c13_fb_y = NULL;
  real_T c13_hb_u;
  const mxArray *c13_gb_y = NULL;
  real_T c13_ib_u;
  const mxArray *c13_hb_y = NULL;
  real_T c13_jb_u;
  const mxArray *c13_ib_y = NULL;
  real_T c13_kb_u;
  const mxArray *c13_jb_y = NULL;
  real_T c13_lb_u;
  const mxArray *c13_kb_y = NULL;
  real_T c13_mb_u;
  const mxArray *c13_lb_y = NULL;
  real_T c13_nb_u;
  const mxArray *c13_mb_y = NULL;
  real_T c13_ob_u;
  const mxArray *c13_nb_y = NULL;
  real_T c13_pb_u;
  const mxArray *c13_ob_y = NULL;
  real_T c13_qb_u;
  const mxArray *c13_pb_y = NULL;
  real_T c13_rb_u;
  const mxArray *c13_qb_y = NULL;
  real_T c13_sb_u;
  const mxArray *c13_rb_y = NULL;
  real_T c13_tb_u;
  const mxArray *c13_sb_y = NULL;
  real_T c13_ub_u;
  const mxArray *c13_tb_y = NULL;
  real_T c13_vb_u;
  const mxArray *c13_ub_y = NULL;
  int32_T c13_i219;
  real_T c13_wb_u[6];
  const mxArray *c13_vb_y = NULL;
  int32_T c13_i220;
  real_T c13_xb_u[6];
  const mxArray *c13_wb_y = NULL;
  real_T c13_yb_u;
  const mxArray *c13_xb_y = NULL;
  int32_T c13_i221;
  real_T c13_ac_u[6];
  const mxArray *c13_yb_y = NULL;
  int32_T c13_i222;
  real_T c13_bc_u[6];
  const mxArray *c13_ac_y = NULL;
  real_T c13_cc_u;
  const mxArray *c13_bc_y = NULL;
  int32_T c13_i223;
  real_T c13_dc_u[12];
  const mxArray *c13_cc_y = NULL;
  real_T c13_ec_u;
  const mxArray *c13_dc_y = NULL;
  c13_DiscreteParamsBus c13_fc_u;
  const mxArray *c13_ec_y = NULL;
  real_T c13_gc_u;
  const mxArray *c13_fc_y = NULL;
  real_T c13_hc_u;
  const mxArray *c13_gc_y = NULL;
  real_T c13_ic_u;
  const mxArray *c13_hc_y = NULL;
  real_T c13_jc_u;
  const mxArray *c13_ic_y = NULL;
  real_T c13_kc_u;
  const mxArray *c13_jc_y = NULL;
  real_T c13_lc_u;
  const mxArray *c13_kc_y = NULL;
  real_T c13_mc_u;
  const mxArray *c13_lc_y = NULL;
  real_T c13_nc_u;
  const mxArray *c13_mc_y = NULL;
  real_T c13_oc_u;
  const mxArray *c13_nc_y = NULL;
  real_T c13_pc_u;
  const mxArray *c13_oc_y = NULL;
  real_T c13_qc_u;
  const mxArray *c13_pc_y = NULL;
  c13_OutputParamsBus c13_rc_u;
  const mxArray *c13_qc_y = NULL;
  int32_T c13_i224;
  real_T c13_sc_u[78];
  const mxArray *c13_rc_y = NULL;
  int32_T c13_i225;
  real_T c13_tc_u[36];
  const mxArray *c13_sc_y = NULL;
  int32_T c13_i226;
  real_T c13_uc_u[2];
  const mxArray *c13_tc_y = NULL;
  c13_ThetaParamsBus c13_vc_u;
  const mxArray *c13_uc_y = NULL;
  real_T c13_wc_u;
  const mxArray *c13_vc_y = NULL;
  real_T c13_xc_u;
  const mxArray *c13_wc_y = NULL;
  int32_T c13_i227;
  real_T c13_yc_u[13];
  const mxArray *c13_xc_y = NULL;
  real_T c13_ad_u;
  const mxArray *c13_yc_y = NULL;
  int32_T c13_i228;
  real_T c13_bd_u[7];
  const mxArray *c13_ad_y = NULL;
  real_T c13_cd_u;
  const mxArray *c13_bd_y = NULL;
  int32_T c13_i229;
  real_T c13_dd_u[2];
  const mxArray *c13_cd_y = NULL;
  real_T c13_ed_u;
  const mxArray *c13_dd_y = NULL;
  real_T c13_fd_u;
  const mxArray *c13_ed_y = NULL;
  real_T c13_gd_u;
  const mxArray *c13_fd_y = NULL;
  int32_T c13_i230;
  real_T c13_hd_u[30];
  const mxArray *c13_gd_y = NULL;
  c13_PhiParamsBus c13_id_u;
  const mxArray *c13_hd_y = NULL;
  real_T c13_jd_u;
  const mxArray *c13_id_y = NULL;
  int32_T c13_i231;
  real_T c13_kd_u[13];
  const mxArray *c13_jd_y = NULL;
  int32_T c13_i232;
  real_T c13_ld_u[20];
  const mxArray *c13_kd_y = NULL;
  real_T c13_md_u;
  const mxArray *c13_ld_y = NULL;
  int32_T c13_i233;
  real_T c13_nd_u[2];
  const mxArray *c13_md_y = NULL;
  int32_T c13_i234;
  real_T c13_od_u[30];
  const mxArray *c13_nd_y = NULL;
  int32_T c13_i235;
  real_T c13_pd_u[12];
  const mxArray *c13_od_y = NULL;
  int32_T c13_i236;
  real_T c13_qd_u[36];
  const mxArray *c13_pd_y = NULL;
  real_T c13_rd_u;
  const mxArray *c13_qd_y = NULL;
  c13_FeedbackParamsBus c13_sd_u;
  const mxArray *c13_rd_y = NULL;
  int32_T c13_i237;
  real_T c13_td_u[6];
  const mxArray *c13_sd_y = NULL;
  int32_T c13_i238;
  real_T c13_ud_u[6];
  const mxArray *c13_td_y = NULL;
  int32_T c13_i239;
  real_T c13_vd_u[2];
  const mxArray *c13_ud_y = NULL;
  int32_T c13_i240;
  real_T c13_wd_u[2];
  const mxArray *c13_vd_y = NULL;
  real_T c13_xd_u;
  const mxArray *c13_wd_y = NULL;
  int32_T c13_i241;
  real_T c13_yd_u[2];
  const mxArray *c13_xd_y = NULL;
  int32_T c13_i242;
  real_T c13_ae_u[2];
  const mxArray *c13_yd_y = NULL;
  real_T c13_be_u;
  const mxArray *c13_ae_y = NULL;
  real_T c13_ce_u;
  const mxArray *c13_be_y = NULL;
  real_T c13_de_u;
  const mxArray *c13_ce_y = NULL;
  real_T c13_ee_u;
  const mxArray *c13_de_y = NULL;
  real_T c13_fe_u;
  const mxArray *c13_ee_y = NULL;
  real_T c13_ge_u;
  const mxArray *c13_fe_y = NULL;
  real_T c13_he_u;
  const mxArray *c13_ge_y = NULL;
  real_T c13_ie_u;
  const mxArray *c13_he_y = NULL;
  int32_T c13_i243;
  real_T c13_je_u[6];
  const mxArray *c13_ie_y = NULL;
  real_T c13_ke_u;
  const mxArray *c13_je_y = NULL;
  real_T c13_le_u;
  const mxArray *c13_ke_y = NULL;
  real_T c13_me_u;
  const mxArray *c13_le_y = NULL;
  real_T c13_ne_u;
  const mxArray *c13_me_y = NULL;
  real_T c13_oe_u;
  const mxArray *c13_ne_y = NULL;
  real_T c13_pe_u;
  const mxArray *c13_oe_y = NULL;
  real_T c13_qe_u;
  const mxArray *c13_pe_y = NULL;
  real_T c13_re_u;
  const mxArray *c13_qe_y = NULL;
  real_T c13_se_u;
  const mxArray *c13_re_y = NULL;
  int32_T c13_i244;
  real_T c13_te_u[6];
  const mxArray *c13_se_y = NULL;
  real_T c13_ue_u;
  const mxArray *c13_te_y = NULL;
  c13_SaturationParamsBus c13_ve_u;
  const mxArray *c13_ue_y = NULL;
  real_T c13_we_u;
  const mxArray *c13_ve_y = NULL;
  int32_T c13_i245;
  real_T c13_xe_u[2];
  const mxArray *c13_we_y = NULL;
  real_T c13_ye_u;
  const mxArray *c13_xe_y = NULL;
  real_T c13_af_u;
  const mxArray *c13_ye_y = NULL;
  real_T c13_bf_u;
  const mxArray *c13_af_y = NULL;
  real_T c13_cf_u;
  const mxArray *c13_bf_y = NULL;
  real_T c13_df_u;
  const mxArray *c13_cf_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_mxArrayOutData = NULL;
  c13_b_u = *(c13_ControlParamsBus *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_c_u = c13_b_u.Supervisory;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_d_u = c13_c_u.EnableSwapOnKAAccel;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_c_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c13_e_u = c13_c_u.EnableSwapOnKASpring;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_d_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c13_f_u = c13_c_u.EnableBackwardSwap;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_e_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c13_g_u = c13_c_u.ImpactThresholdKAAccel;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_f_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c13_h_u = c13_c_u.ImpactThresholdKASpringAbs;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_g_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c13_i_u = c13_c_u.ImpactThresholdKASpringRel;
  c13_h_y = NULL;
  sf_mex_assign(&c13_h_y, sf_mex_create("y", &c13_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_h_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c13_j_u = c13_c_u.SwapThresholdS;
  c13_i_y = NULL;
  sf_mex_assign(&c13_i_y, sf_mex_create("y", &c13_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_i_y, "SwapThresholdS", "SwapThresholdS", 0);
  c13_k_u = c13_c_u.AllowDoubleSupport;
  c13_j_y = NULL;
  sf_mex_assign(&c13_j_y, sf_mex_create("y", &c13_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_j_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c13_l_u = c13_c_u.UseGaitTransition;
  c13_k_y = NULL;
  sf_mex_assign(&c13_k_y, sf_mex_create("y", &c13_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_k_y, "UseGaitTransition", "UseGaitTransition", 0);
  c13_m_u = c13_c_u.NumTransitionSteps;
  c13_l_y = NULL;
  sf_mex_assign(&c13_l_y, sf_mex_create("y", &c13_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_l_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c13_n_u = c13_c_u.TransitionThresholdTorsoVel;
  c13_m_y = NULL;
  sf_mex_assign(&c13_m_y, sf_mex_create("y", &c13_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_m_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c13_i213 = 0; c13_i213 < 2; c13_i213++) {
    c13_o_u[c13_i213] = c13_c_u.KAInjection[c13_i213];
  }

  c13_n_y = NULL;
  sf_mex_assign(&c13_n_y, sf_mex_create("y", c13_o_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_b_y, c13_n_y, "KAInjection", "KAInjection", 0);
  c13_p_u = c13_c_u.MinDeltaThetaTransition;
  c13_o_y = NULL;
  sf_mex_assign(&c13_o_y, sf_mex_create("y", &c13_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_o_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c13_q_u = c13_c_u.StartSecondGaitOnStep;
  c13_p_y = NULL;
  sf_mex_assign(&c13_p_y, sf_mex_create("y", &c13_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_p_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c13_i214 = 0; c13_i214 < 6; c13_i214++) {
    c13_r_u[c13_i214] = c13_c_u.VBLAParams[c13_i214];
  }

  c13_q_y = NULL;
  sf_mex_assign(&c13_q_y, sf_mex_create("y", c13_r_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_q_y, "VBLAParams", "VBLAParams", 0);
  for (c13_i215 = 0; c13_i215 < 13; c13_i215++) {
    c13_s_u[c13_i215] = c13_c_u.BalanceParams[c13_i215];
  }

  c13_r_y = NULL;
  sf_mex_assign(&c13_r_y, sf_mex_create("y", c13_s_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c13_b_y, c13_r_y, "BalanceParams", "BalanceParams", 0);
  for (c13_i216 = 0; c13_i216 < 5; c13_i216++) {
    c13_t_u[c13_i216] = c13_c_u.GaitTweaks[c13_i216];
  }

  c13_s_y = NULL;
  sf_mex_assign(&c13_s_y, sf_mex_create("y", c13_t_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c13_b_y, c13_s_y, "GaitTweaks", "GaitTweaks", 0);
  c13_u_u = c13_c_u.TStepInitial;
  c13_t_y = NULL;
  sf_mex_assign(&c13_t_y, sf_mex_create("y", &c13_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_t_y, "TStepInitial", "TStepInitial", 0);
  c13_v_u = c13_c_u.TMaxUpdate;
  c13_u_y = NULL;
  sf_mex_assign(&c13_u_y, sf_mex_create("y", &c13_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_u_y, "TMaxUpdate", "TMaxUpdate", 0);
  c13_w_u = c13_c_u.RunMode;
  c13_v_y = NULL;
  sf_mex_assign(&c13_v_y, sf_mex_create("y", &c13_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_v_y, "RunMode", "RunMode", 0);
  c13_x_u = c13_c_u.UseAbsoluteSwingLA;
  c13_w_y = NULL;
  sf_mex_assign(&c13_w_y, sf_mex_create("y", &c13_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_b_y, c13_w_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c13_i217 = 0; c13_i217 < 6; c13_i217++) {
    c13_y_u[c13_i217] = c13_c_u.ErrorZeroFactor[c13_i217];
  }

  c13_x_y = NULL;
  sf_mex_assign(&c13_x_y, sf_mex_create("y", c13_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_x_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c13_i218 = 0; c13_i218 < 6; c13_i218++) {
    c13_ab_u[c13_i218] = c13_c_u.ErrorVelZeroFactor[c13_i218];
  }

  c13_y_y = NULL;
  sf_mex_assign(&c13_y_y, sf_mex_create("y", c13_ab_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_y_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c13_bb_u = c13_c_u.StanceLegInit;
  c13_ab_y = NULL;
  sf_mex_assign(&c13_ab_y, sf_mex_create("y", &c13_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_ab_y, "StanceLegInit", "StanceLegInit", 0);
  c13_cb_u = c13_c_u.ControllerModeInit;
  c13_bb_y = NULL;
  sf_mex_assign(&c13_bb_y, sf_mex_create("y", &c13_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_bb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c13_db_u = c13_c_u.UsePosingControl;
  c13_cb_y = NULL;
  sf_mex_assign(&c13_cb_y, sf_mex_create("y", &c13_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_cb_y, "UsePosingControl", "UsePosingControl", 0);
  c13_eb_u = c13_c_u.TPosing;
  c13_db_y = NULL;
  sf_mex_assign(&c13_db_y, sf_mex_create("y", &c13_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_db_y, "TPosing", "TPosing", 0);
  c13_fb_u = c13_c_u.TorsoBackAngle;
  c13_eb_y = NULL;
  sf_mex_assign(&c13_eb_y, sf_mex_create("y", &c13_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_eb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c13_gb_u = c13_c_u.TorsoBackOnStep;
  c13_fb_y = NULL;
  sf_mex_assign(&c13_fb_y, sf_mex_create("y", &c13_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_fb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c13_hb_u = c13_c_u.EnergyControlGain;
  c13_gb_y = NULL;
  sf_mex_assign(&c13_gb_y, sf_mex_create("y", &c13_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_gb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c13_ib_u = c13_c_u.EnergyControlPhi0;
  c13_hb_y = NULL;
  sf_mex_assign(&c13_hb_y, sf_mex_create("y", &c13_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_hb_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c13_jb_u = c13_c_u.VelocityControlTorsoMax;
  c13_ib_y = NULL;
  sf_mex_assign(&c13_ib_y, sf_mex_create("y", &c13_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_ib_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c13_kb_u = c13_c_u.VelocityControlTorsoMin;
  c13_jb_y = NULL;
  sf_mex_assign(&c13_jb_y, sf_mex_create("y", &c13_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_jb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c13_lb_u = c13_c_u.VelocityControlTorsoGain;
  c13_kb_y = NULL;
  sf_mex_assign(&c13_kb_y, sf_mex_create("y", &c13_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_kb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c13_mb_u = c13_c_u.VelocityControlTorsoV0;
  c13_lb_y = NULL;
  sf_mex_assign(&c13_lb_y, sf_mex_create("y", &c13_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_lb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c13_nb_u = c13_c_u.MinDeltaTheta;
  c13_mb_y = NULL;
  sf_mex_assign(&c13_mb_y, sf_mex_create("y", &c13_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_mb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c13_ob_u = c13_c_u.Theta0;
  c13_nb_y = NULL;
  sf_mex_assign(&c13_nb_y, sf_mex_create("y", &c13_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_nb_y, "Theta0", "Theta0", 0);
  c13_pb_u = c13_c_u.KThetaPlus;
  c13_ob_y = NULL;
  sf_mex_assign(&c13_ob_y, sf_mex_create("y", &c13_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_ob_y, "KThetaPlus", "KThetaPlus", 0);
  c13_qb_u = c13_c_u.KThetaMinus;
  c13_pb_y = NULL;
  sf_mex_assign(&c13_pb_y, sf_mex_create("y", &c13_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_pb_y, "KThetaMinus", "KThetaMinus", 0);
  c13_rb_u = c13_c_u.RollPhaseVelocityThresh;
  c13_qb_y = NULL;
  sf_mex_assign(&c13_qb_y, sf_mex_create("y", &c13_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_qb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c13_sb_u = c13_c_u.RollPhaseSThresh;
  c13_rb_y = NULL;
  sf_mex_assign(&c13_rb_y, sf_mex_create("y", &c13_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_rb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c13_tb_u = c13_c_u.MaxError;
  c13_sb_y = NULL;
  sf_mex_assign(&c13_sb_y, sf_mex_create("y", &c13_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_sb_y, "MaxError", "MaxError", 0);
  c13_ub_u = c13_c_u.MaxErrorVel;
  c13_tb_y = NULL;
  sf_mex_assign(&c13_tb_y, sf_mex_create("y", &c13_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_tb_y, "MaxErrorVel", "MaxErrorVel", 0);
  c13_vb_u = c13_c_u.MaxErrorCount;
  c13_ub_y = NULL;
  sf_mex_assign(&c13_ub_y, sf_mex_create("y", &c13_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_ub_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c13_i219 = 0; c13_i219 < 6; c13_i219++) {
    c13_wb_u[c13_i219] = c13_c_u.K1MidStanceUpdate[c13_i219];
  }

  c13_vb_y = NULL;
  sf_mex_assign(&c13_vb_y, sf_mex_create("y", c13_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_vb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c13_i220 = 0; c13_i220 < 6; c13_i220++) {
    c13_xb_u[c13_i220] = c13_c_u.K2MidStanceUpdate[c13_i220];
  }

  c13_wb_y = NULL;
  sf_mex_assign(&c13_wb_y, sf_mex_create("y", c13_xb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_wb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c13_yb_u = c13_c_u.EnableVelocityBasedUpdate;
  c13_xb_y = NULL;
  sf_mex_assign(&c13_xb_y, sf_mex_create("y", &c13_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_xb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c13_i221 = 0; c13_i221 < 6; c13_i221++) {
    c13_ac_u[c13_i221] = c13_c_u.VelocityBasedUpdateK1[c13_i221];
  }

  c13_yb_y = NULL;
  sf_mex_assign(&c13_yb_y, sf_mex_create("y", c13_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_yb_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c13_i222 = 0; c13_i222 < 6; c13_i222++) {
    c13_bc_u[c13_i222] = c13_c_u.VelocityBasedUpdateK2[c13_i222];
  }

  c13_ac_y = NULL;
  sf_mex_assign(&c13_ac_y, sf_mex_create("y", c13_bc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_b_y, c13_ac_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c13_cc_u = c13_c_u.VelocityBasedUpdateDTheta0;
  c13_bc_y = NULL;
  sf_mex_assign(&c13_bc_y, sf_mex_create("y", &c13_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_bc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c13_i223 = 0; c13_i223 < 12; c13_i223++) {
    c13_dc_u[c13_i223] = c13_c_u.VelocityBasedUpdateLimits[c13_i223];
  }

  c13_cc_y = NULL;
  sf_mex_assign(&c13_cc_y, sf_mex_create("y", c13_dc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c13_b_y, c13_cc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c13_ec_u = c13_c_u.DesiredYawOffset;
  c13_dc_y = NULL;
  sf_mex_assign(&c13_dc_y, sf_mex_create("y", &c13_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_b_y, c13_dc_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  sf_mex_addfield(c13_y, c13_b_y, "Supervisory", "Supervisory", 0);
  c13_fc_u = c13_b_u.Discrete;
  c13_ec_y = NULL;
  sf_mex_assign(&c13_ec_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_gc_u = c13_fc_u.TLastUpdate;
  c13_fc_y = NULL;
  sf_mex_assign(&c13_fc_y, sf_mex_create("y", &c13_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_fc_y, "TLastUpdate", "TLastUpdate", 0);
  c13_hc_u = c13_fc_u.VelocityControlLADelta;
  c13_gc_y = NULL;
  sf_mex_assign(&c13_gc_y, sf_mex_create("y", &c13_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_gc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c13_ic_u = c13_fc_u.VelocityControlTorsoDelta;
  c13_hc_y = NULL;
  sf_mex_assign(&c13_hc_y, sf_mex_create("y", &c13_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_hc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c13_jc_u = c13_fc_u.VelocityControlHipDistCur;
  c13_ic_y = NULL;
  sf_mex_assign(&c13_ic_y, sf_mex_create("y", &c13_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_ic_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c13_kc_u = c13_fc_u.VelocityControlHipDistPrev;
  c13_jc_y = NULL;
  sf_mex_assign(&c13_jc_y, sf_mex_create("y", &c13_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_jc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c13_lc_u = c13_fc_u.VirtualSpringMode;
  c13_kc_y = NULL;
  sf_mex_assign(&c13_kc_y, sf_mex_create("y", &c13_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_kc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c13_mc_u = c13_fc_u.VirtualSpringStiffness;
  c13_lc_y = NULL;
  sf_mex_assign(&c13_lc_y, sf_mex_create("y", &c13_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_lc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c13_nc_u = c13_fc_u.VirtualSpringDamping;
  c13_mc_y = NULL;
  sf_mex_assign(&c13_mc_y, sf_mex_create("y", &c13_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_mc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c13_oc_u = c13_fc_u.VirtualSpringModAmplitude;
  c13_nc_y = NULL;
  sf_mex_assign(&c13_nc_y, sf_mex_create("y", &c13_oc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_nc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c13_pc_u = c13_fc_u.VirtualSpringModRate;
  c13_oc_y = NULL;
  sf_mex_assign(&c13_oc_y, sf_mex_create("y", &c13_pc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_oc_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c13_qc_u = c13_fc_u.VirtualSpringRestPos;
  c13_pc_y = NULL;
  sf_mex_assign(&c13_pc_y, sf_mex_create("y", &c13_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ec_y, c13_pc_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c13_y, c13_ec_y, "Discrete", "Discrete", 0);
  c13_rc_u = c13_b_u.Output;
  c13_qc_y = NULL;
  sf_mex_assign(&c13_qc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i224 = 0; c13_i224 < 78; c13_i224++) {
    c13_sc_u[c13_i224] = c13_rc_u.H0[c13_i224];
  }

  c13_rc_y = NULL;
  sf_mex_assign(&c13_rc_y, sf_mex_create("y", c13_sc_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c13_qc_y, c13_rc_y, "H0", "H0", 0);
  for (c13_i225 = 0; c13_i225 < 36; c13_i225++) {
    c13_tc_u[c13_i225] = c13_rc_u.HAlpha[c13_i225];
  }

  c13_sc_y = NULL;
  sf_mex_assign(&c13_sc_y, sf_mex_create("y", c13_tc_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c13_qc_y, c13_sc_y, "HAlpha", "HAlpha", 0);
  for (c13_i226 = 0; c13_i226 < 2; c13_i226++) {
    c13_uc_u[c13_i226] = c13_rc_u.ThetaLimits[c13_i226];
  }

  c13_tc_y = NULL;
  sf_mex_assign(&c13_tc_y, sf_mex_create("y", c13_uc_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c13_qc_y, c13_tc_y, "ThetaLimits", "ThetaLimits", 0);
  c13_vc_u = c13_rc_u.Theta;
  c13_uc_y = NULL;
  sf_mex_assign(&c13_uc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_wc_u = c13_vc_u.c0;
  c13_vc_y = NULL;
  sf_mex_assign(&c13_vc_y, sf_mex_create("y", &c13_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_uc_y, c13_vc_y, "c0", "c0", 0);
  c13_xc_u = c13_vc_u.ct;
  c13_wc_y = NULL;
  sf_mex_assign(&c13_wc_y, sf_mex_create("y", &c13_xc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_uc_y, c13_wc_y, "ct", "ct", 0);
  for (c13_i227 = 0; c13_i227 < 13; c13_i227++) {
    c13_yc_u[c13_i227] = c13_vc_u.cq[c13_i227];
  }

  c13_xc_y = NULL;
  sf_mex_assign(&c13_xc_y, sf_mex_create("y", c13_yc_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c13_uc_y, c13_xc_y, "cq", "cq", 0);
  c13_ad_u = c13_vc_u.t0;
  c13_yc_y = NULL;
  sf_mex_assign(&c13_yc_y, sf_mex_create("y", &c13_ad_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_uc_y, c13_yc_y, "t0", "t0", 0);
  for (c13_i228 = 0; c13_i228 < 7; c13_i228++) {
    c13_bd_u[c13_i228] = c13_vc_u.cz[c13_i228];
  }

  c13_ad_y = NULL;
  sf_mex_assign(&c13_ad_y, sf_mex_create("y", c13_bd_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c13_uc_y, c13_ad_y, "cz", "cz", 0);
  sf_mex_addfield(c13_qc_y, c13_uc_y, "Theta", "Theta", 0);
  c13_cd_u = c13_rc_u.SaturateS;
  c13_bd_y = NULL;
  sf_mex_assign(&c13_bd_y, sf_mex_create("y", &c13_cd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_bd_y, "SaturateS", "SaturateS", 0);
  for (c13_i229 = 0; c13_i229 < 2; c13_i229++) {
    c13_dd_u[c13_i229] = c13_rc_u.SLimits[c13_i229];
  }

  c13_cd_y = NULL;
  sf_mex_assign(&c13_cd_y, sf_mex_create("y", c13_dd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c13_qc_y, c13_cd_y, "SLimits", "SLimits", 0);
  c13_ed_u = c13_rc_u.EnforceIncreasingS;
  c13_dd_y = NULL;
  sf_mex_assign(&c13_dd_y, sf_mex_create("y", &c13_ed_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_dd_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c13_fd_u = c13_rc_u.UseCorrection;
  c13_ed_y = NULL;
  sf_mex_assign(&c13_ed_y, sf_mex_create("y", &c13_fd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_ed_y, "UseCorrection", "UseCorrection", 0);
  c13_gd_u = c13_rc_u.SMaxCorrection;
  c13_fd_y = NULL;
  sf_mex_assign(&c13_fd_y, sf_mex_create("y", &c13_gd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_fd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c13_i230 = 0; c13_i230 < 30; c13_i230++) {
    c13_hd_u[c13_i230] = c13_rc_u.HAlphaCorrection[c13_i230];
  }

  c13_gd_y = NULL;
  sf_mex_assign(&c13_gd_y, sf_mex_create("y", c13_hd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c13_qc_y, c13_gd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c13_id_u = c13_rc_u.Phi;
  c13_hd_y = NULL;
  sf_mex_assign(&c13_hd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_jd_u = c13_id_u.c0;
  c13_id_y = NULL;
  sf_mex_assign(&c13_id_y, sf_mex_create("y", &c13_jd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_hd_y, c13_id_y, "c0", "c0", 0);
  for (c13_i231 = 0; c13_i231 < 13; c13_i231++) {
    c13_kd_u[c13_i231] = c13_id_u.cq[c13_i231];
  }

  c13_jd_y = NULL;
  sf_mex_assign(&c13_jd_y, sf_mex_create("y", c13_kd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c13_hd_y, c13_jd_y, "cq", "cq", 0);
  sf_mex_addfield(c13_qc_y, c13_hd_y, "Phi", "Phi", 0);
  for (c13_i232 = 0; c13_i232 < 20; c13_i232++) {
    c13_ld_u[c13_i232] = c13_rc_u.PhiAlpha[c13_i232];
  }

  c13_kd_y = NULL;
  sf_mex_assign(&c13_kd_y, sf_mex_create("y", c13_ld_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c13_qc_y, c13_kd_y, "PhiAlpha", "PhiAlpha", 0);
  c13_md_u = c13_rc_u.SaturateR;
  c13_ld_y = NULL;
  sf_mex_assign(&c13_ld_y, sf_mex_create("y", &c13_md_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_ld_y, "SaturateR", "SaturateR", 0);
  for (c13_i233 = 0; c13_i233 < 2; c13_i233++) {
    c13_nd_u[c13_i233] = c13_rc_u.RLimits[c13_i233];
  }

  c13_md_y = NULL;
  sf_mex_assign(&c13_md_y, sf_mex_create("y", c13_nd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c13_qc_y, c13_md_y, "RLimits", "RLimits", 0);
  for (c13_i234 = 0; c13_i234 < 30; c13_i234++) {
    c13_od_u[c13_i234] = c13_rc_u.HBarAlpha[c13_i234];
  }

  c13_nd_y = NULL;
  sf_mex_assign(&c13_nd_y, sf_mex_create("y", c13_od_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c13_qc_y, c13_nd_y, "HBarAlpha", "HBarAlpha", 0);
  for (c13_i235 = 0; c13_i235 < 12; c13_i235++) {
    c13_pd_u[c13_i235] = c13_rc_u.HBarLimits[c13_i235];
  }

  c13_od_y = NULL;
  sf_mex_assign(&c13_od_y, sf_mex_create("y", c13_pd_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c13_qc_y, c13_od_y, "HBarLimits", "HBarLimits", 0);
  for (c13_i236 = 0; c13_i236 < 36; c13_i236++) {
    c13_qd_u[c13_i236] = c13_rc_u.HAlphaStar[c13_i236];
  }

  c13_pd_y = NULL;
  sf_mex_assign(&c13_pd_y, sf_mex_create("y", c13_qd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c13_qc_y, c13_pd_y, "HAlphaStar", "HAlphaStar", 0);
  c13_rd_u = c13_rc_u.YawLimit;
  c13_qd_y = NULL;
  sf_mex_assign(&c13_qd_y, sf_mex_create("y", &c13_rd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_qc_y, c13_qd_y, "YawLimit", "YawLimit", 0);
  sf_mex_addfield(c13_y, c13_qc_y, "Output", "Output", 0);
  c13_sd_u = c13_b_u.Feedback;
  c13_rd_y = NULL;
  sf_mex_assign(&c13_rd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c13_i237 = 0; c13_i237 < 6; c13_i237++) {
    c13_td_u[c13_i237] = c13_sd_u.kp[c13_i237];
  }

  c13_sd_y = NULL;
  sf_mex_assign(&c13_sd_y, sf_mex_create("y", c13_td_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_rd_y, c13_sd_y, "kp", "kp", 0);
  for (c13_i238 = 0; c13_i238 < 6; c13_i238++) {
    c13_ud_u[c13_i238] = c13_sd_u.kd[c13_i238];
  }

  c13_td_y = NULL;
  sf_mex_assign(&c13_td_y, sf_mex_create("y", c13_ud_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_rd_y, c13_td_y, "kd", "kd", 0);
  for (c13_i239 = 0; c13_i239 < 2; c13_i239++) {
    c13_vd_u[c13_i239] = c13_sd_u.epsilon[c13_i239];
  }

  c13_ud_y = NULL;
  sf_mex_assign(&c13_ud_y, sf_mex_create("y", c13_vd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_rd_y, c13_ud_y, "epsilon", "epsilon", 0);
  for (c13_i240 = 0; c13_i240 < 2; c13_i240++) {
    c13_wd_u[c13_i240] = c13_sd_u.kff_grav[c13_i240];
  }

  c13_vd_y = NULL;
  sf_mex_assign(&c13_vd_y, sf_mex_create("y", c13_wd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_rd_y, c13_vd_y, "kff_grav", "kff_grav", 0);
  c13_xd_u = c13_sd_u.delta_grav;
  c13_wd_y = NULL;
  sf_mex_assign(&c13_wd_y, sf_mex_create("y", &c13_xd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_wd_y, "delta_grav", "delta_grav", 0);
  for (c13_i241 = 0; c13_i241 < 2; c13_i241++) {
    c13_yd_u[c13_i241] = c13_sd_u.kff_decoup[c13_i241];
  }

  c13_xd_y = NULL;
  sf_mex_assign(&c13_xd_y, sf_mex_create("y", c13_yd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_rd_y, c13_xd_y, "kff_decoup", "kff_decoup", 0);
  for (c13_i242 = 0; c13_i242 < 2; c13_i242++) {
    c13_ae_u[c13_i242] = c13_sd_u.kd_torso[c13_i242];
  }

  c13_yd_y = NULL;
  sf_mex_assign(&c13_yd_y, sf_mex_create("y", c13_ae_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_rd_y, c13_yd_y, "kd_torso", "kd_torso", 0);
  c13_be_u = c13_sd_u.kp_2dof;
  c13_ae_y = NULL;
  sf_mex_assign(&c13_ae_y, sf_mex_create("y", &c13_be_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ae_y, "kp_2dof", "kp_2dof", 0);
  c13_ce_u = c13_sd_u.kd_2dof;
  c13_be_y = NULL;
  sf_mex_assign(&c13_be_y, sf_mex_create("y", &c13_ce_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_be_y, "kd_2dof", "kd_2dof", 0);
  c13_de_u = c13_sd_u.kpre_2dof;
  c13_ce_y = NULL;
  sf_mex_assign(&c13_ce_y, sf_mex_create("y", &c13_de_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ce_y, "kpre_2dof", "kpre_2dof", 0);
  c13_ee_u = c13_sd_u.kp_lat;
  c13_de_y = NULL;
  sf_mex_assign(&c13_de_y, sf_mex_create("y", &c13_ee_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_de_y, "kp_lat", "kp_lat", 0);
  c13_fe_u = c13_sd_u.kd_lat;
  c13_ee_y = NULL;
  sf_mex_assign(&c13_ee_y, sf_mex_create("y", &c13_fe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ee_y, "kd_lat", "kd_lat", 0);
  c13_ge_u = c13_sd_u.q3d_min_lat;
  c13_fe_y = NULL;
  sf_mex_assign(&c13_fe_y, sf_mex_create("y", &c13_ge_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_fe_y, "q3d_min_lat", "q3d_min_lat", 0);
  c13_he_u = c13_sd_u.q3d_max_lat;
  c13_ge_y = NULL;
  sf_mex_assign(&c13_ge_y, sf_mex_create("y", &c13_he_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ge_y, "q3d_max_lat", "q3d_max_lat", 0);
  c13_ie_u = c13_sd_u.w_torso_lat;
  c13_he_y = NULL;
  sf_mex_assign(&c13_he_y, sf_mex_create("y", &c13_ie_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_he_y, "w_torso_lat", "w_torso_lat", 0);
  for (c13_i243 = 0; c13_i243 < 6; c13_i243++) {
    c13_je_u[c13_i243] = c13_sd_u.u_ff[c13_i243];
  }

  c13_ie_y = NULL;
  sf_mex_assign(&c13_ie_y, sf_mex_create("y", c13_je_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_rd_y, c13_ie_y, "u_ff", "u_ff", 0);
  c13_ke_u = c13_sd_u.LateralControlMode;
  c13_je_y = NULL;
  sf_mex_assign(&c13_je_y, sf_mex_create("y", &c13_ke_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_je_y, "LateralControlMode", "LateralControlMode",
                  0);
  c13_le_u = c13_sd_u.DecouplingMode;
  c13_ke_y = NULL;
  sf_mex_assign(&c13_ke_y, sf_mex_create("y", &c13_le_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ke_y, "DecouplingMode", "DecouplingMode", 0);
  c13_me_u = c13_sd_u.Use2DOF;
  c13_le_y = NULL;
  sf_mex_assign(&c13_le_y, sf_mex_create("y", &c13_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_le_y, "Use2DOF", "Use2DOF", 0);
  c13_ne_u = c13_sd_u.UseDSGravComp;
  c13_me_y = NULL;
  sf_mex_assign(&c13_me_y, sf_mex_create("y", &c13_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_me_y, "UseDSGravComp", "UseDSGravComp", 0);
  c13_oe_u = c13_sd_u.lat_bias;
  c13_ne_y = NULL;
  sf_mex_assign(&c13_ne_y, sf_mex_create("y", &c13_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_ne_y, "lat_bias", "lat_bias", 0);
  c13_pe_u = c13_sd_u.lat_bias2;
  c13_oe_y = NULL;
  sf_mex_assign(&c13_oe_y, sf_mex_create("y", &c13_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_oe_y, "lat_bias2", "lat_bias2", 0);
  c13_qe_u = c13_sd_u.linkFeedback;
  c13_pe_y = NULL;
  sf_mex_assign(&c13_pe_y, sf_mex_create("y", &c13_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_pe_y, "linkFeedback", "linkFeedback", 0);
  c13_re_u = c13_sd_u.RIO;
  c13_qe_y = NULL;
  sf_mex_assign(&c13_qe_y, sf_mex_create("y", &c13_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_qe_y, "RIO", "RIO", 0);
  c13_se_u = c13_sd_u.SelectFeedforward;
  c13_re_y = NULL;
  sf_mex_assign(&c13_re_y, sf_mex_create("y", &c13_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_re_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c13_i244 = 0; c13_i244 < 6; c13_i244++) {
    c13_te_u[c13_i244] = c13_sd_u.FeedforwardGain[c13_i244];
  }

  c13_se_y = NULL;
  sf_mex_assign(&c13_se_y, sf_mex_create("y", c13_te_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c13_rd_y, c13_se_y, "FeedforwardGain", "FeedforwardGain", 0);
  c13_ue_u = c13_sd_u.EnableFeedforwardOnStep;
  c13_te_y = NULL;
  sf_mex_assign(&c13_te_y, sf_mex_create("y", &c13_ue_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_rd_y, c13_te_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c13_y, c13_rd_y, "Feedback", "Feedback", 0);
  c13_ve_u = c13_b_u.Saturation;
  c13_ue_y = NULL;
  sf_mex_assign(&c13_ue_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_we_u = c13_ve_u.UseQPSaturation;
  c13_ve_y = NULL;
  sf_mex_assign(&c13_ve_y, sf_mex_create("y", &c13_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_ve_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c13_i245 = 0; c13_i245 < 2; c13_i245++) {
    c13_xe_u[c13_i245] = c13_ve_u.QPWeight[c13_i245];
  }

  c13_we_y = NULL;
  sf_mex_assign(&c13_we_y, sf_mex_create("y", c13_xe_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c13_ue_y, c13_we_y, "QPWeight", "QPWeight", 0);
  c13_ye_u = c13_ve_u.UseKASaturation;
  c13_xe_y = NULL;
  sf_mex_assign(&c13_xe_y, sf_mex_create("y", &c13_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_xe_y, "UseKASaturation", "UseKASaturation", 0);
  c13_af_u = c13_ve_u.KASaturationS1;
  c13_ye_y = NULL;
  sf_mex_assign(&c13_ye_y, sf_mex_create("y", &c13_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_ye_y, "KASaturationS1", "KASaturationS1", 0);
  c13_bf_u = c13_ve_u.KASaturationS2;
  c13_af_y = NULL;
  sf_mex_assign(&c13_af_y, sf_mex_create("y", &c13_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_af_y, "KASaturationS2", "KASaturationS2", 0);
  c13_cf_u = c13_ve_u.KASaturationEarly;
  c13_bf_y = NULL;
  sf_mex_assign(&c13_bf_y, sf_mex_create("y", &c13_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_bf_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c13_df_u = c13_ve_u.KASaturationMax;
  c13_cf_y = NULL;
  sf_mex_assign(&c13_cf_y, sf_mex_create("y", &c13_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c13_ue_y, c13_cf_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c13_y, c13_ue_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  c13_ControlStateBus c13_b_u;
  const mxArray *c13_y = NULL;
  real_T c13_c_u;
  const mxArray *c13_b_y = NULL;
  real_T c13_d_u;
  const mxArray *c13_c_y = NULL;
  real_T c13_e_u;
  const mxArray *c13_d_y = NULL;
  real_T c13_f_u;
  const mxArray *c13_e_y = NULL;
  real_T c13_g_u;
  const mxArray *c13_f_y = NULL;
  real_T c13_h_u;
  const mxArray *c13_g_y = NULL;
  real_T c13_i_u;
  const mxArray *c13_h_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_b_u = *(c13_ControlStateBus *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c13_c_u = c13_b_u.ControllerMode;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_b_y, "ControllerMode", "ControllerMode", 0);
  c13_d_u = c13_b_u.SupportState;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_c_y, "SupportState", "SupportState", 0);
  c13_e_u = c13_b_u.StanceLeg;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_d_y, "StanceLeg", "StanceLeg", 0);
  c13_f_u = c13_b_u.InDoubleSupport;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_e_y, "InDoubleSupport", "InDoubleSupport", 0);
  c13_g_u = c13_b_u.RollPhase;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_f_y, "RollPhase", "RollPhase", 0);
  c13_h_u = c13_b_u.StepCount;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_g_y, "StepCount", "StepCount", 0);
  c13_i_u = c13_b_u.Error;
  c13_h_y = NULL;
  sf_mex_assign(&c13_h_y, sf_mex_create("y", &c13_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c13_y, c13_h_y, "Error", "Error", 0);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i246;
  real_T c13_b_inData[2];
  int32_T c13_i247;
  real_T c13_b_u[2];
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i246 = 0; c13_i246 < 2; c13_i246++) {
    c13_b_inData[c13_i246] = (*(real_T (*)[2])c13_inData)[c13_i246];
  }

  for (c13_i247 = 0; c13_i247 < 2; c13_i247++) {
    c13_b_u[c13_i247] = c13_b_inData[c13_i247];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_b_u;
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_b_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_c_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d27;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), &c13_d27, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d27;
  sf_mex_destroy(&c13_b_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i248;
  int32_T c13_i249;
  int32_T c13_i250;
  real_T c13_b_inData[36];
  int32_T c13_i251;
  int32_T c13_i252;
  int32_T c13_i253;
  real_T c13_b_u[36];
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_i248 = 0;
  for (c13_i249 = 0; c13_i249 < 6; c13_i249++) {
    for (c13_i250 = 0; c13_i250 < 6; c13_i250++) {
      c13_b_inData[c13_i250 + c13_i248] = (*(real_T (*)[36])c13_inData)[c13_i250
        + c13_i248];
    }

    c13_i248 += 6;
  }

  c13_i251 = 0;
  for (c13_i252 = 0; c13_i252 < 6; c13_i252++) {
    for (c13_i253 = 0; c13_i253 < 6; c13_i253++) {
      c13_b_u[c13_i253 + c13_i251] = c13_b_inData[c13_i253 + c13_i251];
    }

    c13_i251 += 6;
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_d_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y
  [36])
{
  real_T c13_dv5[36];
  int32_T c13_i254;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), c13_dv5, 1, 0, 0U, 1, 0U, 2,
                6, 6);
  for (c13_i254 = 0; c13_i254 < 36; c13_i254++) {
    c13_y[c13_i254] = c13_dv5[c13_i254];
  }

  sf_mex_destroy(&c13_b_u);
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_T0;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[36];
  int32_T c13_i255;
  int32_T c13_i256;
  int32_T c13_i257;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_T0 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_T0), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_T0);
  c13_i255 = 0;
  for (c13_i256 = 0; c13_i256 < 6; c13_i256++) {
    for (c13_i257 = 0; c13_i257 < 6; c13_i257++) {
      (*(real_T (*)[36])c13_outData)[c13_i257 + c13_i255] = c13_y[c13_i257 +
        c13_i255];
    }

    c13_i255 += 6;
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static void c13_e_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[2])
{
  real_T c13_dv6[2];
  int32_T c13_i258;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), c13_dv6, 1, 0, 0U, 1, 0U, 1,
                2);
  for (c13_i258 = 0; c13_i258 < 2; c13_i258++) {
    c13_y[c13_i258] = c13_dv6[c13_i258];
  }

  sf_mex_destroy(&c13_b_u);
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_uL;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[2];
  int32_T c13_i259;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_uL = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_uL), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_uL);
  for (c13_i259 = 0; c13_i259 < 2; c13_i259++) {
    (*(real_T (*)[2])c13_outData)[c13_i259] = c13_y[c13_i259];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i260;
  real_T c13_b_inData[4];
  int32_T c13_i261;
  real_T c13_b_u[4];
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i260 = 0; c13_i260 < 4; c13_i260++) {
    c13_b_inData[c13_i260] = (*(real_T (*)[4])c13_inData)[c13_i260];
  }

  for (c13_i261 = 0; c13_i261 < 4; c13_i261++) {
    c13_b_u[c13_i261] = c13_b_inData[c13_i261];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static void c13_f_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId, real_T c13_y[4])
{
  real_T c13_dv7[4];
  int32_T c13_i262;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), c13_dv7, 1, 0, 0U, 1, 0U, 1,
                4);
  for (c13_i262 = 0; c13_i262 < 4; c13_i262++) {
    c13_y[c13_i262] = c13_dv7[c13_i262];
  }

  sf_mex_destroy(&c13_b_u);
}

static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_L_opt;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[4];
  int32_T c13_i263;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_L_opt = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_L_opt), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_L_opt);
  for (c13_i263 = 0; c13_i263 < 4; c13_i263++) {
    (*(real_T (*)[4])c13_outData)[c13_i263] = c13_y[c13_i263];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_LibWalking_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_createstruct("structure", 2, 190, 1),
                false);
  c13_info_helper(&c13_nameCaptureInfo);
  c13_b_info_helper(&c13_nameCaptureInfo);
  c13_c_info_helper(&c13_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs0 = NULL;
  const mxArray *c13_lhs0 = NULL;
  const mxArray *c13_rhs1 = NULL;
  const mxArray *c13_lhs1 = NULL;
  const mxArray *c13_rhs2 = NULL;
  const mxArray *c13_lhs2 = NULL;
  const mxArray *c13_rhs3 = NULL;
  const mxArray *c13_lhs3 = NULL;
  const mxArray *c13_rhs4 = NULL;
  const mxArray *c13_lhs4 = NULL;
  const mxArray *c13_rhs5 = NULL;
  const mxArray *c13_lhs5 = NULL;
  const mxArray *c13_rhs6 = NULL;
  const mxArray *c13_lhs6 = NULL;
  const mxArray *c13_rhs7 = NULL;
  const mxArray *c13_lhs7 = NULL;
  const mxArray *c13_rhs8 = NULL;
  const mxArray *c13_lhs8 = NULL;
  const mxArray *c13_rhs9 = NULL;
  const mxArray *c13_lhs9 = NULL;
  const mxArray *c13_rhs10 = NULL;
  const mxArray *c13_lhs10 = NULL;
  const mxArray *c13_rhs11 = NULL;
  const mxArray *c13_lhs11 = NULL;
  const mxArray *c13_rhs12 = NULL;
  const mxArray *c13_lhs12 = NULL;
  const mxArray *c13_rhs13 = NULL;
  const mxArray *c13_lhs13 = NULL;
  const mxArray *c13_rhs14 = NULL;
  const mxArray *c13_lhs14 = NULL;
  const mxArray *c13_rhs15 = NULL;
  const mxArray *c13_lhs15 = NULL;
  const mxArray *c13_rhs16 = NULL;
  const mxArray *c13_lhs16 = NULL;
  const mxArray *c13_rhs17 = NULL;
  const mxArray *c13_lhs17 = NULL;
  const mxArray *c13_rhs18 = NULL;
  const mxArray *c13_lhs18 = NULL;
  const mxArray *c13_rhs19 = NULL;
  const mxArray *c13_lhs19 = NULL;
  const mxArray *c13_rhs20 = NULL;
  const mxArray *c13_lhs20 = NULL;
  const mxArray *c13_rhs21 = NULL;
  const mxArray *c13_lhs21 = NULL;
  const mxArray *c13_rhs22 = NULL;
  const mxArray *c13_lhs22 = NULL;
  const mxArray *c13_rhs23 = NULL;
  const mxArray *c13_lhs23 = NULL;
  const mxArray *c13_rhs24 = NULL;
  const mxArray *c13_lhs24 = NULL;
  const mxArray *c13_rhs25 = NULL;
  const mxArray *c13_lhs25 = NULL;
  const mxArray *c13_rhs26 = NULL;
  const mxArray *c13_lhs26 = NULL;
  const mxArray *c13_rhs27 = NULL;
  const mxArray *c13_lhs27 = NULL;
  const mxArray *c13_rhs28 = NULL;
  const mxArray *c13_lhs28 = NULL;
  const mxArray *c13_rhs29 = NULL;
  const mxArray *c13_lhs29 = NULL;
  const mxArray *c13_rhs30 = NULL;
  const mxArray *c13_lhs30 = NULL;
  const mxArray *c13_rhs31 = NULL;
  const mxArray *c13_lhs31 = NULL;
  const mxArray *c13_rhs32 = NULL;
  const mxArray *c13_lhs32 = NULL;
  const mxArray *c13_rhs33 = NULL;
  const mxArray *c13_lhs33 = NULL;
  const mxArray *c13_rhs34 = NULL;
  const mxArray *c13_lhs34 = NULL;
  const mxArray *c13_rhs35 = NULL;
  const mxArray *c13_lhs35 = NULL;
  const mxArray *c13_rhs36 = NULL;
  const mxArray *c13_lhs36 = NULL;
  const mxArray *c13_rhs37 = NULL;
  const mxArray *c13_lhs37 = NULL;
  const mxArray *c13_rhs38 = NULL;
  const mxArray *c13_lhs38 = NULL;
  const mxArray *c13_rhs39 = NULL;
  const mxArray *c13_lhs39 = NULL;
  const mxArray *c13_rhs40 = NULL;
  const mxArray *c13_lhs40 = NULL;
  const mxArray *c13_rhs41 = NULL;
  const mxArray *c13_lhs41 = NULL;
  const mxArray *c13_rhs42 = NULL;
  const mxArray *c13_lhs42 = NULL;
  const mxArray *c13_rhs43 = NULL;
  const mxArray *c13_lhs43 = NULL;
  const mxArray *c13_rhs44 = NULL;
  const mxArray *c13_lhs44 = NULL;
  const mxArray *c13_rhs45 = NULL;
  const mxArray *c13_lhs45 = NULL;
  const mxArray *c13_rhs46 = NULL;
  const mxArray *c13_lhs46 = NULL;
  const mxArray *c13_rhs47 = NULL;
  const mxArray *c13_lhs47 = NULL;
  const mxArray *c13_rhs48 = NULL;
  const mxArray *c13_lhs48 = NULL;
  const mxArray *c13_rhs49 = NULL;
  const mxArray *c13_lhs49 = NULL;
  const mxArray *c13_rhs50 = NULL;
  const mxArray *c13_lhs50 = NULL;
  const mxArray *c13_rhs51 = NULL;
  const mxArray *c13_lhs51 = NULL;
  const mxArray *c13_rhs52 = NULL;
  const mxArray *c13_lhs52 = NULL;
  const mxArray *c13_rhs53 = NULL;
  const mxArray *c13_lhs53 = NULL;
  const mxArray *c13_rhs54 = NULL;
  const mxArray *c13_lhs54 = NULL;
  const mxArray *c13_rhs55 = NULL;
  const mxArray *c13_lhs55 = NULL;
  const mxArray *c13_rhs56 = NULL;
  const mxArray *c13_lhs56 = NULL;
  const mxArray *c13_rhs57 = NULL;
  const mxArray *c13_lhs57 = NULL;
  const mxArray *c13_rhs58 = NULL;
  const mxArray *c13_lhs58 = NULL;
  const mxArray *c13_rhs59 = NULL;
  const mxArray *c13_lhs59 = NULL;
  const mxArray *c13_rhs60 = NULL;
  const mxArray *c13_lhs60 = NULL;
  const mxArray *c13_rhs61 = NULL;
  const mxArray *c13_lhs61 = NULL;
  const mxArray *c13_rhs62 = NULL;
  const mxArray *c13_lhs62 = NULL;
  const mxArray *c13_rhs63 = NULL;
  const mxArray *c13_lhs63 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c13_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c13_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c13_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c13_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c13_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c13_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c13_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c13_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c13_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c13_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c13_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c13_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c13_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c13_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c13_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c13_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c13_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c13_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c13_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c13_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("LA_LS_Revised_Saturation"),
                  "name", "name", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c13_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_1"), "name", "name", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c13_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c13_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_2"), "name", "name", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c13_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c13_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_3"), "name", "name", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c13_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c13_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_4"), "name", "name", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c13_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c13_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_5"), "name", "name", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c13_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c13_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_6"), "name", "name", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c13_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c13_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_7"), "name", "name", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c13_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c13_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_8"), "name", "name", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c13_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c13_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_9"), "name", "name", 37);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1432837249U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c13_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mrdivide"), "name", "name",
                  38);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c13_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("max"), "name", "name", 39);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c13_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 40);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c13_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 41);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c13_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 42);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c13_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 43);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 43);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c13_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 44);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 44);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c13_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 45);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 45);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c13_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 46);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isnan"), "name", "name", 46);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c13_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 47);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c13_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 48);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 48);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c13_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 49);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c13_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 50);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 50);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c13_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 51);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isfi"), "name", "name", 51);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c13_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 52);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c13_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 53);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmax"), "name", "name", 53);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c13_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 54);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c13_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 55);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmin"), "name", "name", 55);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c13_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c13_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 57);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_relop"), "name", "name",
                  57);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 57);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c13_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("min"), "name", "name", 58);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c13_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c13_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 60);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("min"), "name", "name", 60);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c13_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 61);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 61);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c13_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 62);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 62);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c13_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 63);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c13_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c13_rhs0);
  sf_mex_destroy(&c13_lhs0);
  sf_mex_destroy(&c13_rhs1);
  sf_mex_destroy(&c13_lhs1);
  sf_mex_destroy(&c13_rhs2);
  sf_mex_destroy(&c13_lhs2);
  sf_mex_destroy(&c13_rhs3);
  sf_mex_destroy(&c13_lhs3);
  sf_mex_destroy(&c13_rhs4);
  sf_mex_destroy(&c13_lhs4);
  sf_mex_destroy(&c13_rhs5);
  sf_mex_destroy(&c13_lhs5);
  sf_mex_destroy(&c13_rhs6);
  sf_mex_destroy(&c13_lhs6);
  sf_mex_destroy(&c13_rhs7);
  sf_mex_destroy(&c13_lhs7);
  sf_mex_destroy(&c13_rhs8);
  sf_mex_destroy(&c13_lhs8);
  sf_mex_destroy(&c13_rhs9);
  sf_mex_destroy(&c13_lhs9);
  sf_mex_destroy(&c13_rhs10);
  sf_mex_destroy(&c13_lhs10);
  sf_mex_destroy(&c13_rhs11);
  sf_mex_destroy(&c13_lhs11);
  sf_mex_destroy(&c13_rhs12);
  sf_mex_destroy(&c13_lhs12);
  sf_mex_destroy(&c13_rhs13);
  sf_mex_destroy(&c13_lhs13);
  sf_mex_destroy(&c13_rhs14);
  sf_mex_destroy(&c13_lhs14);
  sf_mex_destroy(&c13_rhs15);
  sf_mex_destroy(&c13_lhs15);
  sf_mex_destroy(&c13_rhs16);
  sf_mex_destroy(&c13_lhs16);
  sf_mex_destroy(&c13_rhs17);
  sf_mex_destroy(&c13_lhs17);
  sf_mex_destroy(&c13_rhs18);
  sf_mex_destroy(&c13_lhs18);
  sf_mex_destroy(&c13_rhs19);
  sf_mex_destroy(&c13_lhs19);
  sf_mex_destroy(&c13_rhs20);
  sf_mex_destroy(&c13_lhs20);
  sf_mex_destroy(&c13_rhs21);
  sf_mex_destroy(&c13_lhs21);
  sf_mex_destroy(&c13_rhs22);
  sf_mex_destroy(&c13_lhs22);
  sf_mex_destroy(&c13_rhs23);
  sf_mex_destroy(&c13_lhs23);
  sf_mex_destroy(&c13_rhs24);
  sf_mex_destroy(&c13_lhs24);
  sf_mex_destroy(&c13_rhs25);
  sf_mex_destroy(&c13_lhs25);
  sf_mex_destroy(&c13_rhs26);
  sf_mex_destroy(&c13_lhs26);
  sf_mex_destroy(&c13_rhs27);
  sf_mex_destroy(&c13_lhs27);
  sf_mex_destroy(&c13_rhs28);
  sf_mex_destroy(&c13_lhs28);
  sf_mex_destroy(&c13_rhs29);
  sf_mex_destroy(&c13_lhs29);
  sf_mex_destroy(&c13_rhs30);
  sf_mex_destroy(&c13_lhs30);
  sf_mex_destroy(&c13_rhs31);
  sf_mex_destroy(&c13_lhs31);
  sf_mex_destroy(&c13_rhs32);
  sf_mex_destroy(&c13_lhs32);
  sf_mex_destroy(&c13_rhs33);
  sf_mex_destroy(&c13_lhs33);
  sf_mex_destroy(&c13_rhs34);
  sf_mex_destroy(&c13_lhs34);
  sf_mex_destroy(&c13_rhs35);
  sf_mex_destroy(&c13_lhs35);
  sf_mex_destroy(&c13_rhs36);
  sf_mex_destroy(&c13_lhs36);
  sf_mex_destroy(&c13_rhs37);
  sf_mex_destroy(&c13_lhs37);
  sf_mex_destroy(&c13_rhs38);
  sf_mex_destroy(&c13_lhs38);
  sf_mex_destroy(&c13_rhs39);
  sf_mex_destroy(&c13_lhs39);
  sf_mex_destroy(&c13_rhs40);
  sf_mex_destroy(&c13_lhs40);
  sf_mex_destroy(&c13_rhs41);
  sf_mex_destroy(&c13_lhs41);
  sf_mex_destroy(&c13_rhs42);
  sf_mex_destroy(&c13_lhs42);
  sf_mex_destroy(&c13_rhs43);
  sf_mex_destroy(&c13_lhs43);
  sf_mex_destroy(&c13_rhs44);
  sf_mex_destroy(&c13_lhs44);
  sf_mex_destroy(&c13_rhs45);
  sf_mex_destroy(&c13_lhs45);
  sf_mex_destroy(&c13_rhs46);
  sf_mex_destroy(&c13_lhs46);
  sf_mex_destroy(&c13_rhs47);
  sf_mex_destroy(&c13_lhs47);
  sf_mex_destroy(&c13_rhs48);
  sf_mex_destroy(&c13_lhs48);
  sf_mex_destroy(&c13_rhs49);
  sf_mex_destroy(&c13_lhs49);
  sf_mex_destroy(&c13_rhs50);
  sf_mex_destroy(&c13_lhs50);
  sf_mex_destroy(&c13_rhs51);
  sf_mex_destroy(&c13_lhs51);
  sf_mex_destroy(&c13_rhs52);
  sf_mex_destroy(&c13_lhs52);
  sf_mex_destroy(&c13_rhs53);
  sf_mex_destroy(&c13_lhs53);
  sf_mex_destroy(&c13_rhs54);
  sf_mex_destroy(&c13_lhs54);
  sf_mex_destroy(&c13_rhs55);
  sf_mex_destroy(&c13_lhs55);
  sf_mex_destroy(&c13_rhs56);
  sf_mex_destroy(&c13_lhs56);
  sf_mex_destroy(&c13_rhs57);
  sf_mex_destroy(&c13_lhs57);
  sf_mex_destroy(&c13_rhs58);
  sf_mex_destroy(&c13_lhs58);
  sf_mex_destroy(&c13_rhs59);
  sf_mex_destroy(&c13_lhs59);
  sf_mex_destroy(&c13_rhs60);
  sf_mex_destroy(&c13_lhs60);
  sf_mex_destroy(&c13_rhs61);
  sf_mex_destroy(&c13_lhs61);
  sf_mex_destroy(&c13_rhs62);
  sf_mex_destroy(&c13_lhs62);
  sf_mex_destroy(&c13_rhs63);
  sf_mex_destroy(&c13_lhs63);
}

static const mxArray *c13_emlrt_marshallOut(const char * c13_b_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c13_b_u)), false);
  return c13_y;
}

static const mxArray *c13_b_emlrt_marshallOut(const uint32_T c13_b_u)
{
  const mxArray *c13_y = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_b_u, 7, 0U, 0U, 0U, 0), false);
  return c13_y;
}

static void c13_b_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs64 = NULL;
  const mxArray *c13_lhs64 = NULL;
  const mxArray *c13_rhs65 = NULL;
  const mxArray *c13_lhs65 = NULL;
  const mxArray *c13_rhs66 = NULL;
  const mxArray *c13_lhs66 = NULL;
  const mxArray *c13_rhs67 = NULL;
  const mxArray *c13_lhs67 = NULL;
  const mxArray *c13_rhs68 = NULL;
  const mxArray *c13_lhs68 = NULL;
  const mxArray *c13_rhs69 = NULL;
  const mxArray *c13_lhs69 = NULL;
  const mxArray *c13_rhs70 = NULL;
  const mxArray *c13_lhs70 = NULL;
  const mxArray *c13_rhs71 = NULL;
  const mxArray *c13_lhs71 = NULL;
  const mxArray *c13_rhs72 = NULL;
  const mxArray *c13_lhs72 = NULL;
  const mxArray *c13_rhs73 = NULL;
  const mxArray *c13_lhs73 = NULL;
  const mxArray *c13_rhs74 = NULL;
  const mxArray *c13_lhs74 = NULL;
  const mxArray *c13_rhs75 = NULL;
  const mxArray *c13_lhs75 = NULL;
  const mxArray *c13_rhs76 = NULL;
  const mxArray *c13_lhs76 = NULL;
  const mxArray *c13_rhs77 = NULL;
  const mxArray *c13_lhs77 = NULL;
  const mxArray *c13_rhs78 = NULL;
  const mxArray *c13_lhs78 = NULL;
  const mxArray *c13_rhs79 = NULL;
  const mxArray *c13_lhs79 = NULL;
  const mxArray *c13_rhs80 = NULL;
  const mxArray *c13_lhs80 = NULL;
  const mxArray *c13_rhs81 = NULL;
  const mxArray *c13_lhs81 = NULL;
  const mxArray *c13_rhs82 = NULL;
  const mxArray *c13_lhs82 = NULL;
  const mxArray *c13_rhs83 = NULL;
  const mxArray *c13_lhs83 = NULL;
  const mxArray *c13_rhs84 = NULL;
  const mxArray *c13_lhs84 = NULL;
  const mxArray *c13_rhs85 = NULL;
  const mxArray *c13_lhs85 = NULL;
  const mxArray *c13_rhs86 = NULL;
  const mxArray *c13_lhs86 = NULL;
  const mxArray *c13_rhs87 = NULL;
  const mxArray *c13_lhs87 = NULL;
  const mxArray *c13_rhs88 = NULL;
  const mxArray *c13_lhs88 = NULL;
  const mxArray *c13_rhs89 = NULL;
  const mxArray *c13_lhs89 = NULL;
  const mxArray *c13_rhs90 = NULL;
  const mxArray *c13_lhs90 = NULL;
  const mxArray *c13_rhs91 = NULL;
  const mxArray *c13_lhs91 = NULL;
  const mxArray *c13_rhs92 = NULL;
  const mxArray *c13_lhs92 = NULL;
  const mxArray *c13_rhs93 = NULL;
  const mxArray *c13_lhs93 = NULL;
  const mxArray *c13_rhs94 = NULL;
  const mxArray *c13_lhs94 = NULL;
  const mxArray *c13_rhs95 = NULL;
  const mxArray *c13_lhs95 = NULL;
  const mxArray *c13_rhs96 = NULL;
  const mxArray *c13_lhs96 = NULL;
  const mxArray *c13_rhs97 = NULL;
  const mxArray *c13_lhs97 = NULL;
  const mxArray *c13_rhs98 = NULL;
  const mxArray *c13_lhs98 = NULL;
  const mxArray *c13_rhs99 = NULL;
  const mxArray *c13_lhs99 = NULL;
  const mxArray *c13_rhs100 = NULL;
  const mxArray *c13_lhs100 = NULL;
  const mxArray *c13_rhs101 = NULL;
  const mxArray *c13_lhs101 = NULL;
  const mxArray *c13_rhs102 = NULL;
  const mxArray *c13_lhs102 = NULL;
  const mxArray *c13_rhs103 = NULL;
  const mxArray *c13_lhs103 = NULL;
  const mxArray *c13_rhs104 = NULL;
  const mxArray *c13_lhs104 = NULL;
  const mxArray *c13_rhs105 = NULL;
  const mxArray *c13_lhs105 = NULL;
  const mxArray *c13_rhs106 = NULL;
  const mxArray *c13_lhs106 = NULL;
  const mxArray *c13_rhs107 = NULL;
  const mxArray *c13_lhs107 = NULL;
  const mxArray *c13_rhs108 = NULL;
  const mxArray *c13_lhs108 = NULL;
  const mxArray *c13_rhs109 = NULL;
  const mxArray *c13_lhs109 = NULL;
  const mxArray *c13_rhs110 = NULL;
  const mxArray *c13_lhs110 = NULL;
  const mxArray *c13_rhs111 = NULL;
  const mxArray *c13_lhs111 = NULL;
  const mxArray *c13_rhs112 = NULL;
  const mxArray *c13_lhs112 = NULL;
  const mxArray *c13_rhs113 = NULL;
  const mxArray *c13_lhs113 = NULL;
  const mxArray *c13_rhs114 = NULL;
  const mxArray *c13_lhs114 = NULL;
  const mxArray *c13_rhs115 = NULL;
  const mxArray *c13_lhs115 = NULL;
  const mxArray *c13_rhs116 = NULL;
  const mxArray *c13_lhs116 = NULL;
  const mxArray *c13_rhs117 = NULL;
  const mxArray *c13_lhs117 = NULL;
  const mxArray *c13_rhs118 = NULL;
  const mxArray *c13_lhs118 = NULL;
  const mxArray *c13_rhs119 = NULL;
  const mxArray *c13_lhs119 = NULL;
  const mxArray *c13_rhs120 = NULL;
  const mxArray *c13_lhs120 = NULL;
  const mxArray *c13_rhs121 = NULL;
  const mxArray *c13_lhs121 = NULL;
  const mxArray *c13_rhs122 = NULL;
  const mxArray *c13_lhs122 = NULL;
  const mxArray *c13_rhs123 = NULL;
  const mxArray *c13_lhs123 = NULL;
  const mxArray *c13_rhs124 = NULL;
  const mxArray *c13_lhs124 = NULL;
  const mxArray *c13_rhs125 = NULL;
  const mxArray *c13_lhs125 = NULL;
  const mxArray *c13_rhs126 = NULL;
  const mxArray *c13_lhs126 = NULL;
  const mxArray *c13_rhs127 = NULL;
  const mxArray *c13_lhs127 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 64);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 64);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c13_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 65);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 65);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c13_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 66);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 66);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c13_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 67);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c13_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 68);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  68);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c13_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 69);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c13_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 70);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c13_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 71);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c13_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 72);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c13_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 73);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 73);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c13_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 74);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 74);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c13_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 75);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c13_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 76);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c13_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 77);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c13_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 78);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c13_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 79);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c13_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 80);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 80);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c13_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 81);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("max"), "name", "name", 81);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c13_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "context", "context", 82);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("mldivide"), "name", "name",
                  82);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c13_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 83);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 83);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c13_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 84);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  84);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840406U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c13_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 85);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840410U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c13_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 86);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1302710594U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c13_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("realmin"), "name", "name",
                  87);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c13_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 88);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c13_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 89);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c13_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eps"), "name", "name", 90);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c13_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 91);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c13_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 92);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_eps"), "name", "name",
                  92);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c13_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 93);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 93);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c13_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 94);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("min"), "name", "name", 94);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 94);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c13_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 95);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 95);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 95);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c13_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 96);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 96);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 96);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c13_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 97);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 97);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 97);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c13_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 98);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 98);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 98);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c13_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 99);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 99);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 99);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c13_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 100);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 100);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 100);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c13_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 101);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("colon"), "name", "name", 101);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c13_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("colon"), "name", "name", 102);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 102);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c13_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 103);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 103);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c13_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 104);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c13_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 105);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("floor"), "name", "name", 105);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c13_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 106);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c13_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 107);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c13_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 108);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmin"), "name", "name",
                  108);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c13_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 109);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmax"), "name", "name",
                  109);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c13_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 110);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmin"), "name", "name",
                  110);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 110);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c13_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 111);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmax"), "name", "name",
                  111);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c13_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 112);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 112);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 112);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c13_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 113);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c13_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 114);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 114);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c13_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 115);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 115);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c13_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 116);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 116);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c13_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 117);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 117);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c13_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 118);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 118);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c13_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 119);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmax"), "name", "name",
                  119);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c13_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 120);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 120);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 120);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 120);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c13_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 121);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 121);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c13_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 122);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c13_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 123);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 123);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c13_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 124);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 124);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c13_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 125);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 125);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c13_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 126);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c13_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 127);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c13_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c13_rhs64);
  sf_mex_destroy(&c13_lhs64);
  sf_mex_destroy(&c13_rhs65);
  sf_mex_destroy(&c13_lhs65);
  sf_mex_destroy(&c13_rhs66);
  sf_mex_destroy(&c13_lhs66);
  sf_mex_destroy(&c13_rhs67);
  sf_mex_destroy(&c13_lhs67);
  sf_mex_destroy(&c13_rhs68);
  sf_mex_destroy(&c13_lhs68);
  sf_mex_destroy(&c13_rhs69);
  sf_mex_destroy(&c13_lhs69);
  sf_mex_destroy(&c13_rhs70);
  sf_mex_destroy(&c13_lhs70);
  sf_mex_destroy(&c13_rhs71);
  sf_mex_destroy(&c13_lhs71);
  sf_mex_destroy(&c13_rhs72);
  sf_mex_destroy(&c13_lhs72);
  sf_mex_destroy(&c13_rhs73);
  sf_mex_destroy(&c13_lhs73);
  sf_mex_destroy(&c13_rhs74);
  sf_mex_destroy(&c13_lhs74);
  sf_mex_destroy(&c13_rhs75);
  sf_mex_destroy(&c13_lhs75);
  sf_mex_destroy(&c13_rhs76);
  sf_mex_destroy(&c13_lhs76);
  sf_mex_destroy(&c13_rhs77);
  sf_mex_destroy(&c13_lhs77);
  sf_mex_destroy(&c13_rhs78);
  sf_mex_destroy(&c13_lhs78);
  sf_mex_destroy(&c13_rhs79);
  sf_mex_destroy(&c13_lhs79);
  sf_mex_destroy(&c13_rhs80);
  sf_mex_destroy(&c13_lhs80);
  sf_mex_destroy(&c13_rhs81);
  sf_mex_destroy(&c13_lhs81);
  sf_mex_destroy(&c13_rhs82);
  sf_mex_destroy(&c13_lhs82);
  sf_mex_destroy(&c13_rhs83);
  sf_mex_destroy(&c13_lhs83);
  sf_mex_destroy(&c13_rhs84);
  sf_mex_destroy(&c13_lhs84);
  sf_mex_destroy(&c13_rhs85);
  sf_mex_destroy(&c13_lhs85);
  sf_mex_destroy(&c13_rhs86);
  sf_mex_destroy(&c13_lhs86);
  sf_mex_destroy(&c13_rhs87);
  sf_mex_destroy(&c13_lhs87);
  sf_mex_destroy(&c13_rhs88);
  sf_mex_destroy(&c13_lhs88);
  sf_mex_destroy(&c13_rhs89);
  sf_mex_destroy(&c13_lhs89);
  sf_mex_destroy(&c13_rhs90);
  sf_mex_destroy(&c13_lhs90);
  sf_mex_destroy(&c13_rhs91);
  sf_mex_destroy(&c13_lhs91);
  sf_mex_destroy(&c13_rhs92);
  sf_mex_destroy(&c13_lhs92);
  sf_mex_destroy(&c13_rhs93);
  sf_mex_destroy(&c13_lhs93);
  sf_mex_destroy(&c13_rhs94);
  sf_mex_destroy(&c13_lhs94);
  sf_mex_destroy(&c13_rhs95);
  sf_mex_destroy(&c13_lhs95);
  sf_mex_destroy(&c13_rhs96);
  sf_mex_destroy(&c13_lhs96);
  sf_mex_destroy(&c13_rhs97);
  sf_mex_destroy(&c13_lhs97);
  sf_mex_destroy(&c13_rhs98);
  sf_mex_destroy(&c13_lhs98);
  sf_mex_destroy(&c13_rhs99);
  sf_mex_destroy(&c13_lhs99);
  sf_mex_destroy(&c13_rhs100);
  sf_mex_destroy(&c13_lhs100);
  sf_mex_destroy(&c13_rhs101);
  sf_mex_destroy(&c13_lhs101);
  sf_mex_destroy(&c13_rhs102);
  sf_mex_destroy(&c13_lhs102);
  sf_mex_destroy(&c13_rhs103);
  sf_mex_destroy(&c13_lhs103);
  sf_mex_destroy(&c13_rhs104);
  sf_mex_destroy(&c13_lhs104);
  sf_mex_destroy(&c13_rhs105);
  sf_mex_destroy(&c13_lhs105);
  sf_mex_destroy(&c13_rhs106);
  sf_mex_destroy(&c13_lhs106);
  sf_mex_destroy(&c13_rhs107);
  sf_mex_destroy(&c13_lhs107);
  sf_mex_destroy(&c13_rhs108);
  sf_mex_destroy(&c13_lhs108);
  sf_mex_destroy(&c13_rhs109);
  sf_mex_destroy(&c13_lhs109);
  sf_mex_destroy(&c13_rhs110);
  sf_mex_destroy(&c13_lhs110);
  sf_mex_destroy(&c13_rhs111);
  sf_mex_destroy(&c13_lhs111);
  sf_mex_destroy(&c13_rhs112);
  sf_mex_destroy(&c13_lhs112);
  sf_mex_destroy(&c13_rhs113);
  sf_mex_destroy(&c13_lhs113);
  sf_mex_destroy(&c13_rhs114);
  sf_mex_destroy(&c13_lhs114);
  sf_mex_destroy(&c13_rhs115);
  sf_mex_destroy(&c13_lhs115);
  sf_mex_destroy(&c13_rhs116);
  sf_mex_destroy(&c13_lhs116);
  sf_mex_destroy(&c13_rhs117);
  sf_mex_destroy(&c13_lhs117);
  sf_mex_destroy(&c13_rhs118);
  sf_mex_destroy(&c13_lhs118);
  sf_mex_destroy(&c13_rhs119);
  sf_mex_destroy(&c13_lhs119);
  sf_mex_destroy(&c13_rhs120);
  sf_mex_destroy(&c13_lhs120);
  sf_mex_destroy(&c13_rhs121);
  sf_mex_destroy(&c13_lhs121);
  sf_mex_destroy(&c13_rhs122);
  sf_mex_destroy(&c13_lhs122);
  sf_mex_destroy(&c13_rhs123);
  sf_mex_destroy(&c13_lhs123);
  sf_mex_destroy(&c13_rhs124);
  sf_mex_destroy(&c13_lhs124);
  sf_mex_destroy(&c13_rhs125);
  sf_mex_destroy(&c13_lhs125);
  sf_mex_destroy(&c13_rhs126);
  sf_mex_destroy(&c13_lhs126);
  sf_mex_destroy(&c13_rhs127);
  sf_mex_destroy(&c13_lhs127);
}

static void c13_c_info_helper(const mxArray **c13_info)
{
  const mxArray *c13_rhs128 = NULL;
  const mxArray *c13_lhs128 = NULL;
  const mxArray *c13_rhs129 = NULL;
  const mxArray *c13_lhs129 = NULL;
  const mxArray *c13_rhs130 = NULL;
  const mxArray *c13_lhs130 = NULL;
  const mxArray *c13_rhs131 = NULL;
  const mxArray *c13_lhs131 = NULL;
  const mxArray *c13_rhs132 = NULL;
  const mxArray *c13_lhs132 = NULL;
  const mxArray *c13_rhs133 = NULL;
  const mxArray *c13_lhs133 = NULL;
  const mxArray *c13_rhs134 = NULL;
  const mxArray *c13_lhs134 = NULL;
  const mxArray *c13_rhs135 = NULL;
  const mxArray *c13_lhs135 = NULL;
  const mxArray *c13_rhs136 = NULL;
  const mxArray *c13_lhs136 = NULL;
  const mxArray *c13_rhs137 = NULL;
  const mxArray *c13_lhs137 = NULL;
  const mxArray *c13_rhs138 = NULL;
  const mxArray *c13_lhs138 = NULL;
  const mxArray *c13_rhs139 = NULL;
  const mxArray *c13_lhs139 = NULL;
  const mxArray *c13_rhs140 = NULL;
  const mxArray *c13_lhs140 = NULL;
  const mxArray *c13_rhs141 = NULL;
  const mxArray *c13_lhs141 = NULL;
  const mxArray *c13_rhs142 = NULL;
  const mxArray *c13_lhs142 = NULL;
  const mxArray *c13_rhs143 = NULL;
  const mxArray *c13_lhs143 = NULL;
  const mxArray *c13_rhs144 = NULL;
  const mxArray *c13_lhs144 = NULL;
  const mxArray *c13_rhs145 = NULL;
  const mxArray *c13_lhs145 = NULL;
  const mxArray *c13_rhs146 = NULL;
  const mxArray *c13_lhs146 = NULL;
  const mxArray *c13_rhs147 = NULL;
  const mxArray *c13_lhs147 = NULL;
  const mxArray *c13_rhs148 = NULL;
  const mxArray *c13_lhs148 = NULL;
  const mxArray *c13_rhs149 = NULL;
  const mxArray *c13_lhs149 = NULL;
  const mxArray *c13_rhs150 = NULL;
  const mxArray *c13_lhs150 = NULL;
  const mxArray *c13_rhs151 = NULL;
  const mxArray *c13_lhs151 = NULL;
  const mxArray *c13_rhs152 = NULL;
  const mxArray *c13_lhs152 = NULL;
  const mxArray *c13_rhs153 = NULL;
  const mxArray *c13_lhs153 = NULL;
  const mxArray *c13_rhs154 = NULL;
  const mxArray *c13_lhs154 = NULL;
  const mxArray *c13_rhs155 = NULL;
  const mxArray *c13_lhs155 = NULL;
  const mxArray *c13_rhs156 = NULL;
  const mxArray *c13_lhs156 = NULL;
  const mxArray *c13_rhs157 = NULL;
  const mxArray *c13_lhs157 = NULL;
  const mxArray *c13_rhs158 = NULL;
  const mxArray *c13_lhs158 = NULL;
  const mxArray *c13_rhs159 = NULL;
  const mxArray *c13_lhs159 = NULL;
  const mxArray *c13_rhs160 = NULL;
  const mxArray *c13_lhs160 = NULL;
  const mxArray *c13_rhs161 = NULL;
  const mxArray *c13_lhs161 = NULL;
  const mxArray *c13_rhs162 = NULL;
  const mxArray *c13_lhs162 = NULL;
  const mxArray *c13_rhs163 = NULL;
  const mxArray *c13_lhs163 = NULL;
  const mxArray *c13_rhs164 = NULL;
  const mxArray *c13_lhs164 = NULL;
  const mxArray *c13_rhs165 = NULL;
  const mxArray *c13_lhs165 = NULL;
  const mxArray *c13_rhs166 = NULL;
  const mxArray *c13_lhs166 = NULL;
  const mxArray *c13_rhs167 = NULL;
  const mxArray *c13_lhs167 = NULL;
  const mxArray *c13_rhs168 = NULL;
  const mxArray *c13_lhs168 = NULL;
  const mxArray *c13_rhs169 = NULL;
  const mxArray *c13_lhs169 = NULL;
  const mxArray *c13_rhs170 = NULL;
  const mxArray *c13_lhs170 = NULL;
  const mxArray *c13_rhs171 = NULL;
  const mxArray *c13_lhs171 = NULL;
  const mxArray *c13_rhs172 = NULL;
  const mxArray *c13_lhs172 = NULL;
  const mxArray *c13_rhs173 = NULL;
  const mxArray *c13_lhs173 = NULL;
  const mxArray *c13_rhs174 = NULL;
  const mxArray *c13_lhs174 = NULL;
  const mxArray *c13_rhs175 = NULL;
  const mxArray *c13_lhs175 = NULL;
  const mxArray *c13_rhs176 = NULL;
  const mxArray *c13_lhs176 = NULL;
  const mxArray *c13_rhs177 = NULL;
  const mxArray *c13_lhs177 = NULL;
  const mxArray *c13_rhs178 = NULL;
  const mxArray *c13_lhs178 = NULL;
  const mxArray *c13_rhs179 = NULL;
  const mxArray *c13_lhs179 = NULL;
  const mxArray *c13_rhs180 = NULL;
  const mxArray *c13_lhs180 = NULL;
  const mxArray *c13_rhs181 = NULL;
  const mxArray *c13_lhs181 = NULL;
  const mxArray *c13_rhs182 = NULL;
  const mxArray *c13_lhs182 = NULL;
  const mxArray *c13_rhs183 = NULL;
  const mxArray *c13_lhs183 = NULL;
  const mxArray *c13_rhs184 = NULL;
  const mxArray *c13_lhs184 = NULL;
  const mxArray *c13_rhs185 = NULL;
  const mxArray *c13_lhs185 = NULL;
  const mxArray *c13_rhs186 = NULL;
  const mxArray *c13_lhs186 = NULL;
  const mxArray *c13_rhs187 = NULL;
  const mxArray *c13_lhs187 = NULL;
  const mxArray *c13_rhs188 = NULL;
  const mxArray *c13_lhs188 = NULL;
  const mxArray *c13_rhs189 = NULL;
  const mxArray *c13_lhs189 = NULL;
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 128);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c13_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 129);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 129);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 129);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c13_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 130);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 130);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 130);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c13_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 131);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 131);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 131);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c13_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 132);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 132);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 132);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c13_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 133);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c13_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  134);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c13_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 135);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c13_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 136);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 136);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c13_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 137);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 137);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c13_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 138);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 138);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c13_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 139);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("length"), "name", "name",
                  139);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 139);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c13_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 140);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 140);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c13_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 141);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.ixamax"), "name", "name", 141);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c13_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 142);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 142);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c13_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 143);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("abs"), "name", "name", 143);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 143);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c13_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 144);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 144);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c13_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 145);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 145);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c13_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 146);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 146);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c13_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 147);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 147);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 147);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c13_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xswap"), "name", "name",
                  148);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c13_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 149);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c13_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 150);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 150);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c13_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 151);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 151);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c13_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 152);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 152);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c13_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xswap"), "name", "name", 153);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c13_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("abs"), "name", "name", 154);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 154);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c13_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 155);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 155);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c13_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 156);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 156);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c13_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 157);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 157);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c13_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 158);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 158);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 158);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c13_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 159);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_div"), "name", "name",
                  159);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c13_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 160);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  160);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c13_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 161);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c13_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 162);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 162);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c13_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 163);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 163);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 163);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c13_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 164);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 164);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c13_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 165);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 165);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c13_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 166);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 166);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c13_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 167);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("intmax"), "name", "name",
                  167);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 167);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c13_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 168);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("min"), "name", "name", 168);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c13_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 169);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 169);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c13_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 170);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xgerx"), "name", "name", 170);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c13_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 171);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("abs"), "name", "name", 171);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 171);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 171);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c13_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 172);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 172);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c13_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 173);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 173);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c13_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 174);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 174);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c13_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 175);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 175);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 175);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c13_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 176);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_warning"), "name",
                  "name", 176);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 176);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c13_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 177);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 177);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c13_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 178);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 178);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c13_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 179);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  179);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c13_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 180);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c13_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 181);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 181);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c13_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 182);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 182);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c13_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 183);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 183);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c13_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 184);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 184);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c13_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs184), "rhs",
                  "rhs", 184);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs184), "lhs",
                  "lhs", 184);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 185);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "coder.internal.refblas.xtrsm"), "name", "name", 185);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c13_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs185), "rhs",
                  "rhs", 185);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs185), "lhs",
                  "lhs", 185);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 186);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 186);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c13_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs186), "rhs",
                  "rhs", 186);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs186), "lhs",
                  "lhs", 186);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 187);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 187);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 187);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c13_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs187), "rhs",
                  "rhs", 187);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs187), "lhs",
                  "lhs", 187);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 188);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 188);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c13_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs188), "rhs",
                  "rhs", 188);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs188), "lhs",
                  "lhs", 188);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 189);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("rdivide"), "name", "name",
                  189);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 189);
  sf_mex_addfield(*c13_info, c13_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 189);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c13_info, c13_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c13_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c13_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_rhs189), "rhs",
                  "rhs", 189);
  sf_mex_addfield(*c13_info, sf_mex_duplicatearraysafe(&c13_lhs189), "lhs",
                  "lhs", 189);
  sf_mex_destroy(&c13_rhs128);
  sf_mex_destroy(&c13_lhs128);
  sf_mex_destroy(&c13_rhs129);
  sf_mex_destroy(&c13_lhs129);
  sf_mex_destroy(&c13_rhs130);
  sf_mex_destroy(&c13_lhs130);
  sf_mex_destroy(&c13_rhs131);
  sf_mex_destroy(&c13_lhs131);
  sf_mex_destroy(&c13_rhs132);
  sf_mex_destroy(&c13_lhs132);
  sf_mex_destroy(&c13_rhs133);
  sf_mex_destroy(&c13_lhs133);
  sf_mex_destroy(&c13_rhs134);
  sf_mex_destroy(&c13_lhs134);
  sf_mex_destroy(&c13_rhs135);
  sf_mex_destroy(&c13_lhs135);
  sf_mex_destroy(&c13_rhs136);
  sf_mex_destroy(&c13_lhs136);
  sf_mex_destroy(&c13_rhs137);
  sf_mex_destroy(&c13_lhs137);
  sf_mex_destroy(&c13_rhs138);
  sf_mex_destroy(&c13_lhs138);
  sf_mex_destroy(&c13_rhs139);
  sf_mex_destroy(&c13_lhs139);
  sf_mex_destroy(&c13_rhs140);
  sf_mex_destroy(&c13_lhs140);
  sf_mex_destroy(&c13_rhs141);
  sf_mex_destroy(&c13_lhs141);
  sf_mex_destroy(&c13_rhs142);
  sf_mex_destroy(&c13_lhs142);
  sf_mex_destroy(&c13_rhs143);
  sf_mex_destroy(&c13_lhs143);
  sf_mex_destroy(&c13_rhs144);
  sf_mex_destroy(&c13_lhs144);
  sf_mex_destroy(&c13_rhs145);
  sf_mex_destroy(&c13_lhs145);
  sf_mex_destroy(&c13_rhs146);
  sf_mex_destroy(&c13_lhs146);
  sf_mex_destroy(&c13_rhs147);
  sf_mex_destroy(&c13_lhs147);
  sf_mex_destroy(&c13_rhs148);
  sf_mex_destroy(&c13_lhs148);
  sf_mex_destroy(&c13_rhs149);
  sf_mex_destroy(&c13_lhs149);
  sf_mex_destroy(&c13_rhs150);
  sf_mex_destroy(&c13_lhs150);
  sf_mex_destroy(&c13_rhs151);
  sf_mex_destroy(&c13_lhs151);
  sf_mex_destroy(&c13_rhs152);
  sf_mex_destroy(&c13_lhs152);
  sf_mex_destroy(&c13_rhs153);
  sf_mex_destroy(&c13_lhs153);
  sf_mex_destroy(&c13_rhs154);
  sf_mex_destroy(&c13_lhs154);
  sf_mex_destroy(&c13_rhs155);
  sf_mex_destroy(&c13_lhs155);
  sf_mex_destroy(&c13_rhs156);
  sf_mex_destroy(&c13_lhs156);
  sf_mex_destroy(&c13_rhs157);
  sf_mex_destroy(&c13_lhs157);
  sf_mex_destroy(&c13_rhs158);
  sf_mex_destroy(&c13_lhs158);
  sf_mex_destroy(&c13_rhs159);
  sf_mex_destroy(&c13_lhs159);
  sf_mex_destroy(&c13_rhs160);
  sf_mex_destroy(&c13_lhs160);
  sf_mex_destroy(&c13_rhs161);
  sf_mex_destroy(&c13_lhs161);
  sf_mex_destroy(&c13_rhs162);
  sf_mex_destroy(&c13_lhs162);
  sf_mex_destroy(&c13_rhs163);
  sf_mex_destroy(&c13_lhs163);
  sf_mex_destroy(&c13_rhs164);
  sf_mex_destroy(&c13_lhs164);
  sf_mex_destroy(&c13_rhs165);
  sf_mex_destroy(&c13_lhs165);
  sf_mex_destroy(&c13_rhs166);
  sf_mex_destroy(&c13_lhs166);
  sf_mex_destroy(&c13_rhs167);
  sf_mex_destroy(&c13_lhs167);
  sf_mex_destroy(&c13_rhs168);
  sf_mex_destroy(&c13_lhs168);
  sf_mex_destroy(&c13_rhs169);
  sf_mex_destroy(&c13_lhs169);
  sf_mex_destroy(&c13_rhs170);
  sf_mex_destroy(&c13_lhs170);
  sf_mex_destroy(&c13_rhs171);
  sf_mex_destroy(&c13_lhs171);
  sf_mex_destroy(&c13_rhs172);
  sf_mex_destroy(&c13_lhs172);
  sf_mex_destroy(&c13_rhs173);
  sf_mex_destroy(&c13_lhs173);
  sf_mex_destroy(&c13_rhs174);
  sf_mex_destroy(&c13_lhs174);
  sf_mex_destroy(&c13_rhs175);
  sf_mex_destroy(&c13_lhs175);
  sf_mex_destroy(&c13_rhs176);
  sf_mex_destroy(&c13_lhs176);
  sf_mex_destroy(&c13_rhs177);
  sf_mex_destroy(&c13_lhs177);
  sf_mex_destroy(&c13_rhs178);
  sf_mex_destroy(&c13_lhs178);
  sf_mex_destroy(&c13_rhs179);
  sf_mex_destroy(&c13_lhs179);
  sf_mex_destroy(&c13_rhs180);
  sf_mex_destroy(&c13_lhs180);
  sf_mex_destroy(&c13_rhs181);
  sf_mex_destroy(&c13_lhs181);
  sf_mex_destroy(&c13_rhs182);
  sf_mex_destroy(&c13_lhs182);
  sf_mex_destroy(&c13_rhs183);
  sf_mex_destroy(&c13_lhs183);
  sf_mex_destroy(&c13_rhs184);
  sf_mex_destroy(&c13_lhs184);
  sf_mex_destroy(&c13_rhs185);
  sf_mex_destroy(&c13_lhs185);
  sf_mex_destroy(&c13_rhs186);
  sf_mex_destroy(&c13_lhs186);
  sf_mex_destroy(&c13_rhs187);
  sf_mex_destroy(&c13_lhs187);
  sf_mex_destroy(&c13_rhs188);
  sf_mex_destroy(&c13_lhs188);
  sf_mex_destroy(&c13_rhs189);
  sf_mex_destroy(&c13_lhs189);
}

static void c13_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_threshold(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c13_rdivide(SFc13_LibWalkingInstanceStruct *chartInstance, real_T
  c13_x, real_T c13_y)
{
  real_T c13_b_x;
  real_T c13_b_y;
  real_T c13_c_x;
  real_T c13_c_y;
  (void)chartInstance;
  c13_b_x = c13_x;
  c13_b_y = c13_y;
  c13_c_x = c13_b_x;
  c13_c_y = c13_b_y;
  return c13_c_x / c13_c_y;
}

static void c13_eml_switch_helper(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_check_forloop_overflow_error(SFc13_LibWalkingInstanceStruct
  *chartInstance, boolean_T c13_overflow)
{
  int32_T c13_i264;
  static char_T c13_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c13_b_u[34];
  const mxArray *c13_y = NULL;
  int32_T c13_i265;
  static char_T c13_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c13_c_u[5];
  const mxArray *c13_b_y = NULL;
  (void)chartInstance;
  if (!c13_overflow) {
  } else {
    for (c13_i264 = 0; c13_i264 < 34; c13_i264++) {
      c13_b_u[c13_i264] = c13_cv0[c13_i264];
    }

    c13_y = NULL;
    sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c13_i265 = 0; c13_i265 < 5; c13_i265++) {
      c13_c_u[c13_i265] = c13_cv1[c13_i265];
    }

    c13_b_y = NULL;
    sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c13_y, 14, c13_b_y));
  }
}

static void c13_b_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_c_eml_scalar_eg(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c13_eml_xdotu(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_x[2], real_T c13_y[2])
{
  real_T c13_d;
  int32_T c13_k;
  int32_T c13_b_k;
  c13_d = 0.0;
  c13_eml_switch_helper(chartInstance);
  for (c13_k = 1; c13_k < 3; c13_k++) {
    c13_b_k = c13_k;
    c13_d += c13_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c13_b_k), 1, 2, 1, 0) - 1] * c13_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c13_b_k), 1, 2, 1, 0) - 1];
  }

  return c13_d;
}

static void c13_realmin(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_eps(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_eml_matlab_zgetrf(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_b_A[36], int32_T c13_ipiv[6], int32_T *c13_info)
{
  int32_T c13_i266;
  for (c13_i266 = 0; c13_i266 < 36; c13_i266++) {
    c13_b_A[c13_i266] = c13_A[c13_i266];
  }

  c13_b_eml_matlab_zgetrf(chartInstance, c13_b_A, c13_ipiv, c13_info);
}

static int32_T c13_eml_ixamax(SFc13_LibWalkingInstanceStruct *chartInstance,
  int32_T c13_n, real_T c13_x[36], int32_T c13_ix0)
{
  int32_T c13_idxmax;
  int32_T c13_b_n;
  int32_T c13_b_ix0;
  int32_T c13_c_n;
  int32_T c13_c_ix0;
  int32_T c13_ix;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_y;
  real_T c13_e_x;
  real_T c13_f_x;
  real_T c13_b_y;
  real_T c13_smax;
  int32_T c13_d_n;
  int32_T c13_b;
  int32_T c13_b_b;
  boolean_T c13_overflow;
  int32_T c13_k;
  int32_T c13_b_k;
  int32_T c13_a;
  real_T c13_g_x;
  real_T c13_h_x;
  real_T c13_i_x;
  real_T c13_c_y;
  real_T c13_j_x;
  real_T c13_k_x;
  real_T c13_d_y;
  real_T c13_b_s;
  c13_b_n = c13_n;
  c13_b_ix0 = c13_ix0;
  c13_c_n = c13_b_n;
  c13_c_ix0 = c13_b_ix0;
  if (c13_c_n < 1) {
    c13_idxmax = 0;
  } else {
    c13_idxmax = 1;
    if (c13_c_n > 1) {
      c13_ix = c13_c_ix0;
      c13_b_x = c13_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_ix), 1, 36, 1, 0) - 1];
      c13_c_x = c13_b_x;
      c13_d_x = c13_c_x;
      c13_y = muDoubleScalarAbs(c13_d_x);
      c13_e_x = 0.0;
      c13_f_x = c13_e_x;
      c13_b_y = muDoubleScalarAbs(c13_f_x);
      c13_smax = c13_y + c13_b_y;
      c13_d_n = c13_c_n;
      c13_b = c13_d_n;
      c13_b_b = c13_b;
      if (2 > c13_b_b) {
        c13_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_overflow = (c13_b_b > 2147483646);
      }

      if (c13_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_overflow);
      }

      for (c13_k = 2; c13_k <= c13_d_n; c13_k++) {
        c13_b_k = c13_k;
        c13_a = c13_ix + 1;
        c13_ix = c13_a;
        c13_g_x = c13_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_ix), 1, 36, 1, 0) - 1];
        c13_h_x = c13_g_x;
        c13_i_x = c13_h_x;
        c13_c_y = muDoubleScalarAbs(c13_i_x);
        c13_j_x = 0.0;
        c13_k_x = c13_j_x;
        c13_d_y = muDoubleScalarAbs(c13_k_x);
        c13_b_s = c13_c_y + c13_d_y;
        if (c13_b_s > c13_smax) {
          c13_idxmax = c13_b_k;
          c13_smax = c13_b_s;
        }
      }
    }
  }

  return c13_idxmax;
}

static void c13_b_eml_switch_helper(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c13_eml_xgeru(SFc13_LibWalkingInstanceStruct *chartInstance, int32_T
  c13_m, int32_T c13_n, real_T c13_alpha1, int32_T c13_ix0, int32_T c13_iy0,
  real_T c13_A[36], int32_T c13_ia0, real_T c13_b_A[36])
{
  int32_T c13_i267;
  for (c13_i267 = 0; c13_i267 < 36; c13_i267++) {
    c13_b_A[c13_i267] = c13_A[c13_i267];
  }

  c13_b_eml_xgeru(chartInstance, c13_m, c13_n, c13_alpha1, c13_ix0, c13_iy0,
                  c13_b_A, c13_ia0);
}

static void c13_eml_warning(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  int32_T c13_i268;
  static char_T c13_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c13_b_u[27];
  const mxArray *c13_y = NULL;
  (void)chartInstance;
  for (c13_i268 = 0; c13_i268 < 27; c13_i268++) {
    c13_b_u[c13_i268] = c13_varargin_1[c13_i268];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c13_y));
}

static void c13_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance, real_T
  c13_A[36], real_T c13_B[6], real_T c13_b_B[6])
{
  int32_T c13_i269;
  int32_T c13_i270;
  real_T c13_b_A[36];
  for (c13_i269 = 0; c13_i269 < 6; c13_i269++) {
    c13_b_B[c13_i269] = c13_B[c13_i269];
  }

  for (c13_i270 = 0; c13_i270 < 36; c13_i270++) {
    c13_b_A[c13_i270] = c13_A[c13_i270];
  }

  c13_c_eml_xtrsm(chartInstance, c13_b_A, c13_b_B);
}

static void c13_below_threshold(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  c13_c_eml_switch_helper(chartInstance);
}

static void c13_c_eml_switch_helper(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c13_scalarEg(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c13_b_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6], real_T c13_b_B[6])
{
  int32_T c13_i271;
  int32_T c13_i272;
  real_T c13_b_A[36];
  for (c13_i271 = 0; c13_i271 < 6; c13_i271++) {
    c13_b_B[c13_i271] = c13_B[c13_i271];
  }

  for (c13_i272 = 0; c13_i272 < 36; c13_i272++) {
    c13_b_A[c13_i272] = c13_A[c13_i272];
  }

  c13_d_eml_xtrsm(chartInstance, c13_b_A, c13_b_B);
}

static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_b_u;
  const mxArray *c13_y = NULL;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_b_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_g_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i273;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), &c13_i273, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i273;
  sf_mex_destroy(&c13_b_u);
  return c13_y;
}

static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_ControlState_bus_io(void *chartInstanceVoid, void
  *c13_pData)
{
  const mxArray *c13_mxVal = NULL;
  c13_ControlStateBus c13_tmp;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxVal = NULL;
  c13_tmp.ControllerMode = *(real_T *)&((char_T *)(c13_ControlStateBus *)
    c13_pData)[0];
  c13_tmp.SupportState = *(real_T *)&((char_T *)(c13_ControlStateBus *)c13_pData)
    [8];
  c13_tmp.StanceLeg = *(real_T *)&((char_T *)(c13_ControlStateBus *)c13_pData)
    [16];
  c13_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c13_ControlStateBus *)
    c13_pData)[24];
  c13_tmp.RollPhase = *(real_T *)&((char_T *)(c13_ControlStateBus *)c13_pData)
    [32];
  c13_tmp.StepCount = *(real_T *)&((char_T *)(c13_ControlStateBus *)c13_pData)
    [40];
  c13_tmp.Error = *(real_T *)&((char_T *)(c13_ControlStateBus *)c13_pData)[48];
  sf_mex_assign(&c13_mxVal, c13_c_sf_marshallOut(chartInstance, &c13_tmp), false);
  return c13_mxVal;
}

static const mxArray *c13_ControlParams_bus_io(void *chartInstanceVoid, void
  *c13_pData)
{
  const mxArray *c13_mxVal = NULL;
  c13_ControlParamsBus c13_tmp;
  int32_T c13_i274;
  int32_T c13_i275;
  int32_T c13_i276;
  int32_T c13_i277;
  int32_T c13_i278;
  int32_T c13_i279;
  int32_T c13_i280;
  int32_T c13_i281;
  int32_T c13_i282;
  int32_T c13_i283;
  int32_T c13_i284;
  int32_T c13_i285;
  int32_T c13_i286;
  int32_T c13_i287;
  int32_T c13_i288;
  int32_T c13_i289;
  int32_T c13_i290;
  int32_T c13_i291;
  int32_T c13_i292;
  int32_T c13_i293;
  int32_T c13_i294;
  int32_T c13_i295;
  int32_T c13_i296;
  int32_T c13_i297;
  int32_T c13_i298;
  int32_T c13_i299;
  int32_T c13_i300;
  int32_T c13_i301;
  int32_T c13_i302;
  int32_T c13_i303;
  int32_T c13_i304;
  int32_T c13_i305;
  int32_T c13_i306;
  int32_T c13_i307;
  int32_T c13_i308;
  int32_T c13_i309;
  int32_T c13_i310;
  int32_T c13_i311;
  int32_T c13_i312;
  int32_T c13_i313;
  int32_T c13_i314;
  int32_T c13_i315;
  int32_T c13_i316;
  int32_T c13_i317;
  int32_T c13_i318;
  int32_T c13_i319;
  int32_T c13_i320;
  SFc13_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc13_LibWalkingInstanceStruct *)chartInstanceVoid;
  c13_mxVal = NULL;
  c13_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [0];
  c13_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [8];
  c13_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [16];
  c13_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [24];
  c13_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [32];
  c13_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [40];
  c13_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [48];
  c13_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [56];
  c13_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [64];
  c13_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [72];
  c13_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [80];
  for (c13_i274 = 0; c13_i274 < 2; c13_i274++) {
    c13_tmp.Supervisory.KAInjection[c13_i274] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[88])[c13_i274];
  }

  c13_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [104];
  c13_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [112];
  for (c13_i275 = 0; c13_i275 < 6; c13_i275++) {
    c13_tmp.Supervisory.VBLAParams[c13_i275] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[120])[c13_i275];
  }

  for (c13_i276 = 0; c13_i276 < 13; c13_i276++) {
    c13_tmp.Supervisory.BalanceParams[c13_i276] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[168])[c13_i276];
  }

  for (c13_i277 = 0; c13_i277 < 5; c13_i277++) {
    c13_tmp.Supervisory.GaitTweaks[c13_i277] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[272])[c13_i277];
  }

  c13_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [312];
  c13_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [320];
  c13_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c13_SupervisoryParamsBus
    *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])[328];
  c13_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [336];
  for (c13_i278 = 0; c13_i278 < 6; c13_i278++) {
    c13_tmp.Supervisory.ErrorZeroFactor[c13_i278] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[344])[c13_i278];
  }

  for (c13_i279 = 0; c13_i279 < 6; c13_i279++) {
    c13_tmp.Supervisory.ErrorVelZeroFactor[c13_i279] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[392])[c13_i279];
  }

  c13_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [440];
  c13_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [448];
  c13_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [456];
  c13_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c13_SupervisoryParamsBus
    *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])[464];
  c13_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [472];
  c13_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [480];
  c13_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [488];
  c13_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [496];
  c13_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [504];
  c13_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [512];
  c13_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [520];
  c13_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [528];
  c13_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [536];
  c13_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c13_SupervisoryParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[0])[544];
  c13_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [552];
  c13_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [560];
  c13_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [568];
  c13_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [576];
  c13_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [584];
  c13_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [592];
  c13_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [600];
  for (c13_i280 = 0; c13_i280 < 6; c13_i280++) {
    c13_tmp.Supervisory.K1MidStanceUpdate[c13_i280] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[608])[c13_i280];
  }

  for (c13_i281 = 0; c13_i281 < 6; c13_i281++) {
    c13_tmp.Supervisory.K2MidStanceUpdate[c13_i281] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[656])[c13_i281];
  }

  c13_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [704];
  for (c13_i282 = 0; c13_i282 < 6; c13_i282++) {
    c13_tmp.Supervisory.VelocityBasedUpdateK1[c13_i282] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[712])[c13_i282];
  }

  for (c13_i283 = 0; c13_i283 < 6; c13_i283++) {
    c13_tmp.Supervisory.VelocityBasedUpdateK2[c13_i283] = ((real_T *)&((char_T *)
      (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [0])[760])[c13_i283];
  }

  c13_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [808];
  c13_i284 = 0;
  for (c13_i285 = 0; c13_i285 < 2; c13_i285++) {
    for (c13_i286 = 0; c13_i286 < 6; c13_i286++) {
      c13_tmp.Supervisory.VelocityBasedUpdateLimits[c13_i286 + c13_i284] =
        ((real_T *)&((char_T *)(c13_SupervisoryParamsBus *)&((char_T *)
           (c13_ControlParamsBus *)c13_pData)[0])[816])[c13_i286 + c13_i284];
    }

    c13_i284 += 6;
  }

  c13_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c13_SupervisoryParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[0])
    [912];
  c13_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c13_DiscreteParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[920])[0];
  c13_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [8];
  c13_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [16];
  c13_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [24];
  c13_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [32];
  c13_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [40];
  c13_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [48];
  c13_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [56];
  c13_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [64];
  c13_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [72];
  c13_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c13_DiscreteParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[920])
    [80];
  c13_i287 = 0;
  for (c13_i288 = 0; c13_i288 < 13; c13_i288++) {
    for (c13_i289 = 0; c13_i289 < 6; c13_i289++) {
      c13_tmp.Output.H0[c13_i289 + c13_i287] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
        [1008])[0])[c13_i289 + c13_i287];
    }

    c13_i287 += 6;
  }

  c13_i290 = 0;
  for (c13_i291 = 0; c13_i291 < 6; c13_i291++) {
    for (c13_i292 = 0; c13_i292 < 6; c13_i292++) {
      c13_tmp.Output.HAlpha[c13_i292 + c13_i290] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
        [1008])[624])[c13_i292 + c13_i290];
    }

    c13_i290 += 6;
  }

  for (c13_i293 = 0; c13_i293 < 2; c13_i293++) {
    c13_tmp.Output.ThetaLimits[c13_i293] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])
      [912])[c13_i293];
  }

  c13_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c13_ThetaParamsBus *)
    &((char_T *)(c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)
    c13_pData)[1008])[928])[0];
  c13_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c13_ThetaParamsBus *)
    &((char_T *)(c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)
    c13_pData)[1008])[928])[8];
  for (c13_i294 = 0; c13_i294 < 13; c13_i294++) {
    c13_tmp.Output.Theta.cq[c13_i294] = ((real_T *)&((char_T *)
      (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
      (c13_ControlParamsBus *)c13_pData)[1008])[928])[16])[c13_i294];
  }

  c13_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c13_ThetaParamsBus *)
    &((char_T *)(c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)
    c13_pData)[1008])[928])[120];
  for (c13_i295 = 0; c13_i295 < 7; c13_i295++) {
    c13_tmp.Output.Theta.cz[c13_i295] = ((real_T *)&((char_T *)
      (c13_ThetaParamsBus *)&((char_T *)(c13_OutputParamsBus *)&((char_T *)
      (c13_ControlParamsBus *)c13_pData)[1008])[928])[128])[c13_i295];
  }

  c13_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c13_OutputParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])[1112];
  for (c13_i296 = 0; c13_i296 < 2; c13_i296++) {
    c13_tmp.Output.SLimits[c13_i296] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])
      [1120])[c13_i296];
  }

  c13_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])
    [1136];
  c13_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c13_OutputParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])[1144];
  c13_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c13_OutputParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])[1152];
  c13_i297 = 0;
  for (c13_i298 = 0; c13_i298 < 5; c13_i298++) {
    for (c13_i299 = 0; c13_i299 < 6; c13_i299++) {
      c13_tmp.Output.HAlphaCorrection[c13_i299 + c13_i297] = ((real_T *)
        &((char_T *)(c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)
        c13_pData)[1008])[1160])[c13_i299 + c13_i297];
    }

    c13_i297 += 6;
  }

  c13_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c13_PhiParamsBus *)&((char_T *)
                                        (c13_OutputParamsBus *)&((char_T *)
    (c13_ControlParamsBus *)c13_pData)[1008])[1400])[0];
  for (c13_i300 = 0; c13_i300 < 13; c13_i300++) {
    c13_tmp.Output.Phi.cq[c13_i300] = ((real_T *)&((char_T *)(c13_PhiParamsBus *)
      &((char_T *)(c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)
      c13_pData)[1008])[1400])[8])[c13_i300];
  }

  for (c13_i301 = 0; c13_i301 < 20; c13_i301++) {
    c13_tmp.Output.PhiAlpha[c13_i301] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])
      [1512])[c13_i301];
  }

  c13_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c13_OutputParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])[1672];
  for (c13_i302 = 0; c13_i302 < 2; c13_i302++) {
    c13_tmp.Output.RLimits[c13_i302] = ((real_T *)&((char_T *)
      (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])
      [1680])[c13_i302];
  }

  c13_i303 = 0;
  for (c13_i304 = 0; c13_i304 < 5; c13_i304++) {
    for (c13_i305 = 0; c13_i305 < 6; c13_i305++) {
      c13_tmp.Output.HBarAlpha[c13_i305 + c13_i303] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
        [1008])[1696])[c13_i305 + c13_i303];
    }

    c13_i303 += 6;
  }

  c13_i306 = 0;
  for (c13_i307 = 0; c13_i307 < 2; c13_i307++) {
    for (c13_i308 = 0; c13_i308 < 6; c13_i308++) {
      c13_tmp.Output.HBarLimits[c13_i308 + c13_i306] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
        [1008])[1936])[c13_i308 + c13_i306];
    }

    c13_i306 += 6;
  }

  c13_i309 = 0;
  for (c13_i310 = 0; c13_i310 < 6; c13_i310++) {
    for (c13_i311 = 0; c13_i311 < 6; c13_i311++) {
      c13_tmp.Output.HAlphaStar[c13_i311 + c13_i309] = ((real_T *)&((char_T *)
        (c13_OutputParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
        [1008])[2032])[c13_i311 + c13_i309];
    }

    c13_i309 += 6;
  }

  c13_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c13_OutputParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[1008])[2320];
  for (c13_i312 = 0; c13_i312 < 6; c13_i312++) {
    c13_tmp.Feedback.kp[c13_i312] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[0])[c13_i312];
  }

  for (c13_i313 = 0; c13_i313 < 6; c13_i313++) {
    c13_tmp.Feedback.kd[c13_i313] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[48])[c13_i313];
  }

  for (c13_i314 = 0; c13_i314 < 2; c13_i314++) {
    c13_tmp.Feedback.epsilon[c13_i314] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[96])[c13_i314];
  }

  for (c13_i315 = 0; c13_i315 < 2; c13_i315++) {
    c13_tmp.Feedback.kff_grav[c13_i315] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[112])[c13_i315];
  }

  c13_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[128];
  for (c13_i316 = 0; c13_i316 < 2; c13_i316++) {
    c13_tmp.Feedback.kff_decoup[c13_i316] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[136])[c13_i316];
  }

  for (c13_i317 = 0; c13_i317 < 2; c13_i317++) {
    c13_tmp.Feedback.kd_torso[c13_i317] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[152])[c13_i317];
  }

  c13_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[168];
  c13_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[176];
  c13_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[184];
  c13_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[192];
  c13_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[200];
  c13_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[208];
  c13_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[216];
  c13_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[224];
  for (c13_i318 = 0; c13_i318 < 6; c13_i318++) {
    c13_tmp.Feedback.u_ff[c13_i318] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[232])[c13_i318];
  }

  c13_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])
    [280];
  c13_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])
    [288];
  c13_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[296];
  c13_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c13_FeedbackParamsBus
    *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[304];
  c13_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[312];
  c13_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[320];
  c13_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[328];
  c13_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c13_FeedbackParamsBus *)
    &((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])[336];
  c13_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])
    [344];
  for (c13_i319 = 0; c13_i319 < 6; c13_i319++) {
    c13_tmp.Feedback.FeedforwardGain[c13_i319] = ((real_T *)&((char_T *)
      (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3336])[352])[c13_i319];
  }

  c13_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c13_FeedbackParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)[3336])
    [400];
  c13_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[0];
  for (c13_i320 = 0; c13_i320 < 2; c13_i320++) {
    c13_tmp.Saturation.QPWeight[c13_i320] = ((real_T *)&((char_T *)
      (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
      [3744])[8])[c13_i320];
  }

  c13_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[24];
  c13_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[32];
  c13_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[40];
  c13_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[48];
  c13_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c13_SaturationParamsBus *)&((char_T *)(c13_ControlParamsBus *)c13_pData)
    [3744])[56];
  sf_mex_assign(&c13_mxVal, c13_b_sf_marshallOut(chartInstance, &c13_tmp), false);
  return c13_mxVal;
}

static uint8_T c13_h_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_is_active_c13_LibWalking, const char_T
  *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_LibWalking), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_LibWalking);
  return c13_y;
}

static uint8_T c13_i_emlrt_marshallIn(SFc13_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c13_b_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_b_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_b_u);
  return c13_y;
}

static void c13_b_eml_matlab_zgetrf(SFc13_LibWalkingInstanceStruct
  *chartInstance, real_T c13_A[36], int32_T c13_ipiv[6], int32_T *c13_info)
{
  int32_T c13_i321;
  int32_T c13_j;
  int32_T c13_b_j;
  int32_T c13_a;
  int32_T c13_b_a;
  int32_T c13_jm1;
  int32_T c13_b;
  int32_T c13_b_b;
  int32_T c13_mmj;
  int32_T c13_c_a;
  int32_T c13_d_a;
  int32_T c13_c;
  int32_T c13_c_b;
  int32_T c13_d_b;
  int32_T c13_jj;
  int32_T c13_e_a;
  int32_T c13_f_a;
  int32_T c13_jp1j;
  int32_T c13_g_a;
  int32_T c13_h_a;
  int32_T c13_b_c;
  int32_T c13_i322;
  real_T c13_b_A[36];
  int32_T c13_i_a;
  int32_T c13_j_a;
  int32_T c13_jpiv_offset;
  int32_T c13_k_a;
  int32_T c13_e_b;
  int32_T c13_l_a;
  int32_T c13_f_b;
  int32_T c13_jpiv;
  int32_T c13_m_a;
  int32_T c13_g_b;
  int32_T c13_n_a;
  int32_T c13_h_b;
  int32_T c13_c_c;
  int32_T c13_i_b;
  int32_T c13_j_b;
  int32_T c13_jrow;
  int32_T c13_o_a;
  int32_T c13_k_b;
  int32_T c13_p_a;
  int32_T c13_l_b;
  int32_T c13_jprow;
  int32_T c13_ix0;
  int32_T c13_iy0;
  int32_T c13_b_ix0;
  int32_T c13_b_iy0;
  int32_T c13_c_ix0;
  int32_T c13_c_iy0;
  int32_T c13_ix;
  int32_T c13_iy;
  int32_T c13_k;
  real_T c13_temp;
  int32_T c13_q_a;
  int32_T c13_r_a;
  int32_T c13_b_jp1j;
  int32_T c13_s_a;
  int32_T c13_t_a;
  int32_T c13_d_c;
  int32_T c13_u_a;
  int32_T c13_m_b;
  int32_T c13_v_a;
  int32_T c13_n_b;
  int32_T c13_i323;
  int32_T c13_w_a;
  int32_T c13_o_b;
  int32_T c13_x_a;
  int32_T c13_p_b;
  boolean_T c13_overflow;
  int32_T c13_i;
  int32_T c13_b_i;
  real_T c13_x;
  real_T c13_y;
  real_T c13_b_x;
  real_T c13_b_y;
  real_T c13_z;
  int32_T c13_q_b;
  int32_T c13_r_b;
  int32_T c13_e_c;
  int32_T c13_y_a;
  int32_T c13_ab_a;
  int32_T c13_f_c;
  int32_T c13_bb_a;
  int32_T c13_cb_a;
  int32_T c13_g_c;
  c13_realmin(chartInstance);
  c13_eps(chartInstance);
  for (c13_i321 = 0; c13_i321 < 6; c13_i321++) {
    c13_ipiv[c13_i321] = 1 + c13_i321;
  }

  *c13_info = 0;
  c13_eml_switch_helper(chartInstance);
  for (c13_j = 1; c13_j < 6; c13_j++) {
    c13_b_j = c13_j;
    c13_a = c13_b_j;
    c13_b_a = c13_a - 1;
    c13_jm1 = c13_b_a;
    c13_b = c13_b_j;
    c13_b_b = c13_b;
    c13_mmj = 6 - c13_b_b;
    c13_c_a = c13_jm1;
    c13_d_a = c13_c_a;
    c13_c = c13_d_a * 7;
    c13_c_b = c13_c;
    c13_d_b = c13_c_b + 1;
    c13_jj = c13_d_b;
    c13_e_a = c13_jj;
    c13_f_a = c13_e_a + 1;
    c13_jp1j = c13_f_a;
    c13_g_a = c13_mmj;
    c13_h_a = c13_g_a;
    c13_b_c = c13_h_a;
    for (c13_i322 = 0; c13_i322 < 36; c13_i322++) {
      c13_b_A[c13_i322] = c13_A[c13_i322];
    }

    c13_i_a = c13_eml_ixamax(chartInstance, c13_b_c + 1, c13_b_A, c13_jj);
    c13_j_a = c13_i_a - 1;
    c13_jpiv_offset = c13_j_a;
    c13_k_a = c13_jj;
    c13_e_b = c13_jpiv_offset;
    c13_l_a = c13_k_a;
    c13_f_b = c13_e_b;
    c13_jpiv = c13_l_a + c13_f_b;
    if (c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c13_jpiv_offset != 0) {
        c13_m_a = c13_b_j;
        c13_g_b = c13_jpiv_offset;
        c13_n_a = c13_m_a;
        c13_h_b = c13_g_b;
        c13_c_c = c13_n_a + c13_h_b;
        c13_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_j), 1, 6, 1, 0) - 1] = c13_c_c;
        c13_i_b = c13_jm1;
        c13_j_b = c13_i_b + 1;
        c13_jrow = c13_j_b;
        c13_o_a = c13_jrow;
        c13_k_b = c13_jpiv_offset;
        c13_p_a = c13_o_a;
        c13_l_b = c13_k_b;
        c13_jprow = c13_p_a + c13_l_b;
        c13_ix0 = c13_jrow;
        c13_iy0 = c13_jprow;
        c13_b_ix0 = c13_ix0;
        c13_b_iy0 = c13_iy0;
        c13_b_eml_switch_helper(chartInstance);
        c13_c_ix0 = c13_b_ix0;
        c13_c_iy0 = c13_b_iy0;
        c13_ix = c13_c_ix0;
        c13_iy = c13_c_iy0;
        c13_eml_switch_helper(chartInstance);
        for (c13_k = 1; c13_k < 7; c13_k++) {
          c13_temp = c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c13_ix), 1, 36, 1, 0) - 1];
          c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_ix), 1, 36, 1, 0) - 1] =
            c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_iy), 1, 36, 1, 0) - 1];
          c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_iy), 1, 36, 1, 0) - 1] = c13_temp;
          c13_q_a = c13_ix + 6;
          c13_ix = c13_q_a;
          c13_r_a = c13_iy + 6;
          c13_iy = c13_r_a;
        }
      }

      c13_b_jp1j = c13_jp1j;
      c13_s_a = c13_mmj;
      c13_t_a = c13_s_a;
      c13_d_c = c13_t_a;
      c13_u_a = c13_jp1j;
      c13_m_b = c13_d_c - 1;
      c13_v_a = c13_u_a;
      c13_n_b = c13_m_b;
      c13_i323 = c13_v_a + c13_n_b;
      c13_w_a = c13_b_jp1j;
      c13_o_b = c13_i323;
      c13_x_a = c13_w_a;
      c13_p_b = c13_o_b;
      if (c13_x_a > c13_p_b) {
        c13_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_overflow = (c13_p_b > 2147483646);
      }

      if (c13_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_overflow);
      }

      for (c13_i = c13_b_jp1j; c13_i <= c13_i323; c13_i++) {
        c13_b_i = c13_i;
        c13_x = c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_b_i), 1, 36, 1, 0) - 1];
        c13_y = c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c13_jj), 1, 36, 1, 0) - 1];
        c13_b_x = c13_x;
        c13_b_y = c13_y;
        c13_z = c13_b_x / c13_b_y;
        c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_i), 1, 36, 1, 0) - 1] = c13_z;
      }
    } else {
      *c13_info = c13_b_j;
    }

    c13_q_b = c13_b_j;
    c13_r_b = c13_q_b;
    c13_e_c = 6 - c13_r_b;
    c13_y_a = c13_jj;
    c13_ab_a = c13_y_a;
    c13_f_c = c13_ab_a;
    c13_bb_a = c13_jj;
    c13_cb_a = c13_bb_a;
    c13_g_c = c13_cb_a;
    c13_b_eml_xgeru(chartInstance, c13_mmj, c13_e_c, -1.0, c13_jp1j, c13_f_c + 6,
                    c13_A, c13_g_c + 7);
  }

  if (*c13_info == 0) {
    if (!(c13_A[35] != 0.0)) {
      *c13_info = 6;
    }
  }
}

static void c13_b_eml_xgeru(SFc13_LibWalkingInstanceStruct *chartInstance,
  int32_T c13_m, int32_T c13_n, real_T c13_alpha1, int32_T c13_ix0, int32_T
  c13_iy0, real_T c13_A[36], int32_T c13_ia0)
{
  int32_T c13_b_m;
  int32_T c13_b_n;
  real_T c13_b_alpha1;
  int32_T c13_b_ix0;
  int32_T c13_b_iy0;
  int32_T c13_b_ia0;
  int32_T c13_c_m;
  int32_T c13_c_n;
  real_T c13_c_alpha1;
  int32_T c13_c_ix0;
  int32_T c13_c_iy0;
  int32_T c13_c_ia0;
  int32_T c13_d_m;
  int32_T c13_d_n;
  real_T c13_d_alpha1;
  int32_T c13_d_ix0;
  int32_T c13_d_iy0;
  int32_T c13_d_ia0;
  int32_T c13_e_m;
  int32_T c13_e_n;
  real_T c13_e_alpha1;
  int32_T c13_e_ix0;
  int32_T c13_e_iy0;
  int32_T c13_e_ia0;
  int32_T c13_ixstart;
  int32_T c13_a;
  int32_T c13_jA;
  int32_T c13_jy;
  int32_T c13_f_n;
  int32_T c13_b;
  int32_T c13_b_b;
  boolean_T c13_overflow;
  int32_T c13_j;
  real_T c13_yjy;
  real_T c13_temp;
  int32_T c13_ix;
  int32_T c13_c_b;
  int32_T c13_i324;
  int32_T c13_b_a;
  int32_T c13_d_b;
  int32_T c13_i325;
  int32_T c13_c_a;
  int32_T c13_e_b;
  int32_T c13_d_a;
  int32_T c13_f_b;
  boolean_T c13_b_overflow;
  int32_T c13_ijA;
  int32_T c13_b_ijA;
  int32_T c13_e_a;
  int32_T c13_f_a;
  int32_T c13_g_a;
  c13_b_m = c13_m;
  c13_b_n = c13_n;
  c13_b_alpha1 = c13_alpha1;
  c13_b_ix0 = c13_ix0;
  c13_b_iy0 = c13_iy0;
  c13_b_ia0 = c13_ia0;
  c13_c_m = c13_b_m;
  c13_c_n = c13_b_n;
  c13_c_alpha1 = c13_b_alpha1;
  c13_c_ix0 = c13_b_ix0;
  c13_c_iy0 = c13_b_iy0;
  c13_c_ia0 = c13_b_ia0;
  c13_d_m = c13_c_m;
  c13_d_n = c13_c_n;
  c13_d_alpha1 = c13_c_alpha1;
  c13_d_ix0 = c13_c_ix0;
  c13_d_iy0 = c13_c_iy0;
  c13_d_ia0 = c13_c_ia0;
  c13_e_m = c13_d_m;
  c13_e_n = c13_d_n;
  c13_e_alpha1 = c13_d_alpha1;
  c13_e_ix0 = c13_d_ix0;
  c13_e_iy0 = c13_d_iy0;
  c13_e_ia0 = c13_d_ia0;
  if (c13_e_alpha1 == 0.0) {
  } else {
    c13_ixstart = c13_e_ix0;
    c13_a = c13_e_ia0 - 1;
    c13_jA = c13_a;
    c13_jy = c13_e_iy0;
    c13_f_n = c13_e_n;
    c13_b = c13_f_n;
    c13_b_b = c13_b;
    if (1 > c13_b_b) {
      c13_overflow = false;
    } else {
      c13_eml_switch_helper(chartInstance);
      c13_eml_switch_helper(chartInstance);
      c13_overflow = (c13_b_b > 2147483646);
    }

    if (c13_overflow) {
      c13_check_forloop_overflow_error(chartInstance, c13_overflow);
    }

    for (c13_j = 1; c13_j <= c13_f_n; c13_j++) {
      c13_yjy = c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c13_jy), 1, 36, 1, 0) - 1];
      if (c13_yjy != 0.0) {
        c13_temp = c13_yjy * c13_e_alpha1;
        c13_ix = c13_ixstart;
        c13_c_b = c13_jA + 1;
        c13_i324 = c13_c_b;
        c13_b_a = c13_e_m;
        c13_d_b = c13_jA;
        c13_i325 = c13_b_a + c13_d_b;
        c13_c_a = c13_i324;
        c13_e_b = c13_i325;
        c13_d_a = c13_c_a;
        c13_f_b = c13_e_b;
        if (c13_d_a > c13_f_b) {
          c13_b_overflow = false;
        } else {
          c13_eml_switch_helper(chartInstance);
          c13_eml_switch_helper(chartInstance);
          c13_b_overflow = (c13_f_b > 2147483646);
        }

        if (c13_b_overflow) {
          c13_check_forloop_overflow_error(chartInstance, c13_b_overflow);
        }

        for (c13_ijA = c13_i324; c13_ijA <= c13_i325; c13_ijA++) {
          c13_b_ijA = c13_ijA;
          c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_b_ijA), 1, 36, 1, 0) - 1] =
            c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_b_ijA), 1, 36, 1, 0) - 1] +
            c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c13_ix), 1, 36, 1, 0) - 1] * c13_temp;
          c13_e_a = c13_ix + 1;
          c13_ix = c13_e_a;
        }
      }

      c13_f_a = c13_jy + 6;
      c13_jy = c13_f_a;
      c13_g_a = c13_jA + 6;
      c13_jA = c13_g_a;
    }
  }
}

static void c13_c_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6])
{
  int32_T c13_k;
  int32_T c13_b_k;
  int32_T c13_kAcol;
  int32_T c13_i326;
  int32_T c13_a;
  int32_T c13_b_a;
  boolean_T c13_overflow;
  int32_T c13_i;
  int32_T c13_b_i;
  c13_below_threshold(chartInstance);
  c13_scalarEg(chartInstance);
  c13_eml_switch_helper(chartInstance);
  for (c13_k = 1; c13_k < 7; c13_k++) {
    c13_b_k = c13_k;
    c13_kAcol = 6 * (c13_b_k - 1);
    if (c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c13_i326 = c13_b_k + 1;
      c13_a = c13_i326;
      c13_b_a = c13_a;
      if (c13_b_a > 6) {
        c13_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_overflow = false;
      }

      if (c13_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_overflow);
      }

      for (c13_i = c13_i326; c13_i < 7; c13_i++) {
        c13_b_i = c13_i;
        c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_i), 1, 6, 1, 0) - 1] = c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c13_b_i), 1, 6, 1, 0) - 1]
          - c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_k), 1, 6, 1, 0) - 1] * c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c13_b_i + c13_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void c13_d_eml_xtrsm(SFc13_LibWalkingInstanceStruct *chartInstance,
  real_T c13_A[36], real_T c13_B[6])
{
  int32_T c13_k;
  int32_T c13_b_k;
  int32_T c13_kAcol;
  int32_T c13_i327;
  int32_T c13_b;
  int32_T c13_b_b;
  boolean_T c13_overflow;
  int32_T c13_i;
  int32_T c13_b_i;
  c13_below_threshold(chartInstance);
  c13_scalarEg(chartInstance);
  c13_eml_switch_helper(chartInstance);
  for (c13_k = 6; c13_k > 0; c13_k--) {
    c13_b_k = c13_k;
    c13_kAcol = 6 * (c13_b_k - 1);
    if (c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c13_b_k), 1, 6, 1, 0) - 1] = c13_rdivide(chartInstance,
        c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c13_b_k), 1, 6, 1, 0) - 1], c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c13_b_k + c13_kAcol)), 1, 36, 1,
        0) - 1]);
      c13_i327 = c13_b_k - 1;
      c13_b = c13_i327;
      c13_b_b = c13_b;
      if (1 > c13_b_b) {
        c13_overflow = false;
      } else {
        c13_eml_switch_helper(chartInstance);
        c13_eml_switch_helper(chartInstance);
        c13_overflow = (c13_b_b > 2147483646);
      }

      if (c13_overflow) {
        c13_check_forloop_overflow_error(chartInstance, c13_overflow);
      }

      for (c13_i = 1; c13_i <= c13_i327; c13_i++) {
        c13_b_i = c13_i;
        c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_i), 1, 6, 1, 0) - 1] = c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c13_b_i), 1, 6, 1, 0) - 1]
          - c13_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c13_b_k), 1, 6, 1, 0) - 1] * c13_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c13_b_i + c13_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void init_dsm_address_info(SFc13_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc13_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c13_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c13_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c13_u_sat = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c13_sat = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c13_ControlState = (c13_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c13_ControlParams = (c13_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c13_LibWalking_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(575371607U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4017536523U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2595409945U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(734668672U);
}

mxArray* sf_c13_LibWalking_get_post_codegen_info(void);
mxArray *sf_c13_LibWalking_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("o1hm4vkhKUV3wzhDDCFrxF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c13_LibWalking_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_LibWalking_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_LibWalking_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c13_LibWalking_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c13_LibWalking_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c13_LibWalking(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_sat\",},{M[8],M[0],T\"is_active_c13_LibWalking\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_LibWalking_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_LibWalkingInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_LibWalkingInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LibWalkingMachineNumber_,
           13,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           10,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_LibWalkingMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_LibWalkingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _LibWalkingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"s");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u_sat");
          _SFD_SET_DATA_PROPS(3,1,1,0,"sat");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ControlState");
          _SFD_SET_DATA_PROPS(5,1,1,0,"ControlParams");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1951);
        _SFD_CV_INIT_EML_IF(0,1,0,104,149,-1,707);
        _SFD_CV_INIT_EML_IF(0,1,1,158,188,253,336);
        _SFD_CV_INIT_EML_IF(0,1,2,717,797,-1,1947);
        _SFD_CV_INIT_EML_IF(0,1,3,1079,1109,-1,1159);
        _SFD_CV_INIT_EML_IF(0,1,4,1335,1383,1466,1848);
        _SFD_CV_INIT_EML_IF(0,1,5,1466,1518,1760,1848);

        {
          static int condStart[] = { 721, 756 };

          static int condEnd[] = { 751, 796 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,721,796,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,162,187,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,721,751,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1083,1108,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1339,1382,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1474,1517,-1,2);
        _SFD_CV_INIT_SCRIPT(0,1,9,0,0,0,0,0,27,9);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"LA_LS_Revised_Saturation",0,-1,3133);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1867,1935,-1,1997);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2008,2076,-1,2138);
        _SFD_CV_INIT_SCRIPT_IF(0,2,2149,2217,-1,2279);
        _SFD_CV_INIT_SCRIPT_IF(0,3,2290,2358,-1,2420);
        _SFD_CV_INIT_SCRIPT_IF(0,4,2431,2499,-1,2561);
        _SFD_CV_INIT_SCRIPT_IF(0,5,2572,2640,-1,2702);
        _SFD_CV_INIT_SCRIPT_IF(0,6,2713,2781,-1,2843);
        _SFD_CV_INIT_SCRIPT_IF(0,7,2854,2922,-1,2984);
        _SFD_CV_INIT_SCRIPT_IF(0,8,2995,3063,-1,3125);

        {
          static int condStart[] = { 1871, 1895, 1919 };

          static int condEnd[] = { 1889, 1913, 1934 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,1870,1935,3,0,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2012, 2036, 2060 };

          static int condEnd[] = { 2030, 2054, 2075 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,2011,2076,3,3,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2153, 2177, 2201 };

          static int condEnd[] = { 2171, 2195, 2216 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,2,2152,2217,3,6,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2294, 2318, 2342 };

          static int condEnd[] = { 2312, 2336, 2357 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,3,2293,2358,3,9,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2435, 2459, 2483 };

          static int condEnd[] = { 2453, 2477, 2498 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,4,2434,2499,3,12,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2576, 2600, 2624 };

          static int condEnd[] = { 2594, 2618, 2639 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,5,2575,2640,3,15,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2717, 2741, 2765 };

          static int condEnd[] = { 2735, 2759, 2780 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,6,2716,2781,3,18,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2858, 2882, 2906 };

          static int condEnd[] = { 2876, 2900, 2921 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,7,2857,2922,3,21,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2999, 3023, 3047 };

          static int condEnd[] = { 3017, 3041, 3062 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,8,2998,3063,3,24,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,1871,1889,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,1895,1913,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,2,1919,1934,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,3,2012,2030,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,4,2036,2054,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,5,2060,2075,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,6,2153,2171,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,7,2177,2195,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,8,2201,2216,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,9,2294,2312,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,10,2318,2336,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,11,2342,2357,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,12,2435,2453,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,13,2459,2477,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,14,2483,2498,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,15,2576,2594,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,16,2600,2618,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,17,2624,2639,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,18,2717,2735,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,19,2741,2759,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,20,2765,2780,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,21,2858,2876,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,22,2882,2900,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,23,2906,2921,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,24,2999,3017,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,25,3023,3041,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,26,3047,3062,-1,5);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"LA_LS_Revised_Saturation_Case_1",0,-1,543);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"LA_LS_Revised_Saturation_Case_2",0,-1,499);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"LA_LS_Revised_Saturation_Case_3",0,-1,500);
        _SFD_CV_INIT_SCRIPT(4,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"LA_LS_Revised_Saturation_Case_4",0,-1,500);
        _SFD_CV_INIT_SCRIPT(5,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"LA_LS_Revised_Saturation_Case_5",0,-1,499);
        _SFD_CV_INIT_SCRIPT(6,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"LA_LS_Revised_Saturation_Case_6",0,-1,535);
        _SFD_CV_INIT_SCRIPT(7,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(7,0,"LA_LS_Revised_Saturation_Case_7",0,-1,541);
        _SFD_CV_INIT_SCRIPT(8,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(8,0,"LA_LS_Revised_Saturation_Case_8",0,-1,541);
        _SFD_CV_INIT_SCRIPT(9,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(9,0,"LA_LS_Revised_Saturation_Case_9",0,-1,547);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c13_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c13_s);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c13_u_sat);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c13_sat);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c13_ControlState);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c13_ControlParams);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _LibWalkingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "LuzVU0U1PyESmKdnlgrsEF";
}

static void sf_opaque_initialize_c13_LibWalking(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_LibWalkingInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c13_LibWalking((SFc13_LibWalkingInstanceStruct*)
    chartInstanceVar);
  initialize_c13_LibWalking((SFc13_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_LibWalking(void *chartInstanceVar)
{
  enable_c13_LibWalking((SFc13_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_LibWalking(void *chartInstanceVar)
{
  disable_c13_LibWalking((SFc13_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_LibWalking(void *chartInstanceVar)
{
  sf_gateway_c13_LibWalking((SFc13_LibWalkingInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c13_LibWalking(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c13_LibWalking((SFc13_LibWalkingInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c13_LibWalking(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c13_LibWalking((SFc13_LibWalkingInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c13_LibWalking(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_LibWalkingInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LibWalking_optimization_info();
    }

    finalize_c13_LibWalking((SFc13_LibWalkingInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_LibWalking((SFc13_LibWalkingInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_LibWalking(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c13_LibWalking((SFc13_LibWalkingInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_LibWalking_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2667028860U));
  ssSetChecksum1(S,(187039526U));
  ssSetChecksum2(S,(2959217453U));
  ssSetChecksum3(S,(3137811774U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_LibWalking(SimStruct *S)
{
  SFc13_LibWalkingInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_LibWalkingInstanceStruct *)utMalloc(sizeof
    (SFc13_LibWalkingInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_LibWalkingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c13_LibWalking;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c13_LibWalking;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c13_LibWalking;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_LibWalking;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_LibWalking;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c13_LibWalking;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c13_LibWalking;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_LibWalking;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_LibWalking;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_LibWalking;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c13_LibWalking;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c13_LibWalking_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_LibWalking(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_LibWalking(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_LibWalking(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_LibWalking_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
