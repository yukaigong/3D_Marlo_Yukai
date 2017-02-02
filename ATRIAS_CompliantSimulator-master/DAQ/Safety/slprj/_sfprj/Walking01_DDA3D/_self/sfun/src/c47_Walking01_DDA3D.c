/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c47_Walking01_DDA3D.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c47_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c47_IN_Init                    ((uint8_T)1U)
#define c47_IN_Run                     ((uint8_T)2U)
#define c47_IN_Error                   ((uint8_T)1U)
#define c47_IN_Nominal                 ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c47_debug_family_names[3] = { "nargin", "nargout", "err" };

/* Function Declarations */
static void initialize_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c47_update_debugger_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void ext_mode_exec_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c47_st);
static void c47_set_sim_state_side_effects_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void finalize_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c47_chartstep_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber);
static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static boolean_T c47_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static real_T c47_b_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_nargout, const char_T *c47_identifier);
static real_T c47_c_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static void c47_info_helper(const mxArray **c47_info);
static const mxArray *c47_emlrt_marshallOut(const char * c47_u);
static const mxArray *c47_b_emlrt_marshallOut(const uint32_T c47_u);
static boolean_T c47_check_error(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static int32_T c47_d_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static uint8_T c47_e_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_is_Run, const char_T *c47_identifier);
static uint8_T c47_f_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData);
static const mxArray *c47_e_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData);
static uint32_T c47_g_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_temporalCounter_i1, const char_T
  *c47_identifier);
static uint32_T c47_h_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static const mxArray *c47_i_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_setSimStateSideEffectsInfo, const char_T *
  c47_identifier);
static const mxArray *c47_j_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId);
static void init_dsm_address_info(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  *chartInstance->c47_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c47_doSetSimStateSideEffects = 0U;
  chartInstance->c47_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c47_temporalCounter_i1 = 0U;
  *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
  *chartInstance->c47_is_active_c47_Walking01_DDA3D = 0U;
  *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_NO_ACTIVE_CHILD;
  *chartInstance->c47_q_last = 0.0;
  *chartInstance->c47_dq_last = 0.0;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c47_q_clean = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c47_ErrorCount = 0.0;
  }
}

static void initialize_params_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  real_T c47_d0;
  real_T c47_d1;
  sf_mex_import_named("MAX_ANOMALY", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c47_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c47_MAX_ANOMALY = c47_d0;
  sf_mex_import_named("ANOMALY_INIT", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c47_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c47_ANOMALY_INIT = c47_d1;
}

static void enable_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c47_update_debugger_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  uint32_T c47_prevAniVal;
  c47_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c47_is_active_c47_Walking01_DDA3D == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 15U, *chartInstance->c47_sfEvent);
  }

  if (*chartInstance->c47_is_c47_Walking01_DDA3D == c47_IN_Run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
  }

  if (*chartInstance->c47_is_Run == c47_IN_Nominal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
  }

  if (*chartInstance->c47_is_Run == c47_IN_Error) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
  }

  if (*chartInstance->c47_is_c47_Walking01_DDA3D == c47_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
  }

  _SFD_SET_ANIMATION(c47_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  c47_update_debugger_state_c47_Walking01_DDA3D(chartInstance);
}

static const mxArray *get_sim_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c47_st;
  const mxArray *c47_y = NULL;
  real_T c47_hoistedGlobal;
  real_T c47_u;
  const mxArray *c47_b_y = NULL;
  real_T c47_b_hoistedGlobal;
  real_T c47_b_u;
  const mxArray *c47_c_y = NULL;
  real_T c47_c_hoistedGlobal;
  real_T c47_c_u;
  const mxArray *c47_d_y = NULL;
  real_T c47_d_hoistedGlobal;
  real_T c47_d_u;
  const mxArray *c47_e_y = NULL;
  uint8_T c47_e_hoistedGlobal;
  uint8_T c47_e_u;
  const mxArray *c47_f_y = NULL;
  uint8_T c47_f_hoistedGlobal;
  uint8_T c47_f_u;
  const mxArray *c47_g_y = NULL;
  uint8_T c47_g_hoistedGlobal;
  uint8_T c47_g_u;
  const mxArray *c47_h_y = NULL;
  uint32_T c47_h_hoistedGlobal;
  uint32_T c47_h_u;
  const mxArray *c47_i_y = NULL;
  c47_st = NULL;
  c47_st = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_createcellmatrix(8, 1), false);
  c47_hoistedGlobal = *chartInstance->c47_ErrorCount;
  c47_u = c47_hoistedGlobal;
  c47_b_y = NULL;
  sf_mex_assign(&c47_b_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 0, c47_b_y);
  c47_b_hoistedGlobal = *chartInstance->c47_q_clean;
  c47_b_u = c47_b_hoistedGlobal;
  c47_c_y = NULL;
  sf_mex_assign(&c47_c_y, sf_mex_create("y", &c47_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 1, c47_c_y);
  c47_c_hoistedGlobal = *chartInstance->c47_dq_last;
  c47_c_u = c47_c_hoistedGlobal;
  c47_d_y = NULL;
  sf_mex_assign(&c47_d_y, sf_mex_create("y", &c47_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 2, c47_d_y);
  c47_d_hoistedGlobal = *chartInstance->c47_q_last;
  c47_d_u = c47_d_hoistedGlobal;
  c47_e_y = NULL;
  sf_mex_assign(&c47_e_y, sf_mex_create("y", &c47_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 3, c47_e_y);
  c47_e_hoistedGlobal = *chartInstance->c47_is_active_c47_Walking01_DDA3D;
  c47_e_u = c47_e_hoistedGlobal;
  c47_f_y = NULL;
  sf_mex_assign(&c47_f_y, sf_mex_create("y", &c47_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 4, c47_f_y);
  c47_f_hoistedGlobal = *chartInstance->c47_is_c47_Walking01_DDA3D;
  c47_f_u = c47_f_hoistedGlobal;
  c47_g_y = NULL;
  sf_mex_assign(&c47_g_y, sf_mex_create("y", &c47_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 5, c47_g_y);
  c47_g_hoistedGlobal = *chartInstance->c47_is_Run;
  c47_g_u = c47_g_hoistedGlobal;
  c47_h_y = NULL;
  sf_mex_assign(&c47_h_y, sf_mex_create("y", &c47_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 6, c47_h_y);
  c47_h_hoistedGlobal = *chartInstance->c47_temporalCounter_i1;
  c47_h_u = c47_h_hoistedGlobal;
  c47_i_y = NULL;
  sf_mex_assign(&c47_i_y, sf_mex_create("y", &c47_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c47_y, 7, c47_i_y);
  sf_mex_assign(&c47_st, c47_y, false);
  return c47_st;
}

static void set_sim_state_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c47_st)
{
  const mxArray *c47_u;
  c47_u = sf_mex_dup(c47_st);
  *chartInstance->c47_ErrorCount = c47_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c47_u, 0)), "ErrorCount");
  *chartInstance->c47_q_clean = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c47_u, 1)), "q_clean");
  *chartInstance->c47_dq_last = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c47_u, 2)), "dq_last");
  *chartInstance->c47_q_last = c47_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c47_u, 3)), "q_last");
  *chartInstance->c47_is_active_c47_Walking01_DDA3D = c47_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 4)),
     "is_active_c47_Walking01_DDA3D");
  *chartInstance->c47_is_c47_Walking01_DDA3D = c47_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c47_u, 5)),
     "is_c47_Walking01_DDA3D");
  *chartInstance->c47_is_Run = c47_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c47_u, 6)), "is_Run");
  *chartInstance->c47_temporalCounter_i1 = c47_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c47_u, 7)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c47_setSimStateSideEffectsInfo,
                c47_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c47_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c47_u);
  chartInstance->c47_doSetSimStateSideEffects = 1U;
  c47_update_debugger_state_c47_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c47_st);
}

static void c47_set_sim_state_side_effects_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  if (chartInstance->c47_doSetSimStateSideEffects != 0) {
    if (*chartInstance->c47_is_c47_Walking01_DDA3D == c47_IN_Init) {
      if (sf_mex_sub(chartInstance->c47_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        *chartInstance->c47_temporalCounter_i1 = 0U;
      }
    }

    chartInstance->c47_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c47_setSimStateSideEffectsInfo);
}

static void sf_gateway_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c47_i0;
  c47_set_sim_state_side_effects_c47_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, *chartInstance->c47_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c47_MAX_ANOMALY, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c47_ANOMALY_INIT, 7U);
  for (c47_i0 = 0; c47_i0 < 2; c47_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c47_q_limits)[c47_i0], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_Threshold, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c47_Reset, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ANOMALY_DT, 11U);
  *chartInstance->c47_sfEvent = CALL_EVENT;
  if (*chartInstance->c47_temporalCounter_i1 < MAX_uint32_T) {
    (*chartInstance->c47_temporalCounter_i1)++;
  }

  c47_chartstep_c47_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c47_Walking01_DDA3D(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c47_chartstep_c47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  boolean_T c47_temp;
  uint32_T c47_u0;
  boolean_T c47_out;
  boolean_T c47_b_out;
  boolean_T c47_c_out;
  boolean_T c47_d_out;
  boolean_T c47_e_out;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, *chartInstance->c47_sfEvent);
  if (*chartInstance->c47_is_active_c47_Walking01_DDA3D == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 15U,
                 *chartInstance->c47_sfEvent);
    *chartInstance->c47_is_active_c47_Walking01_DDA3D = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *chartInstance->c47_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
    *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
    *chartInstance->c47_temporalCounter_i1 = 0U;
    *chartInstance->c47_q_clean = *chartInstance->c47_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
    *chartInstance->c47_q_last = *chartInstance->c47_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
    *chartInstance->c47_dq_last = *chartInstance->c47_dq;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
    *chartInstance->c47_ErrorCount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
  } else {
    switch (*chartInstance->c47_is_c47_Walking01_DDA3D) {
     case c47_IN_Init:
      CV_CHART_EVAL(15, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c47_sfEvent);
      c47_temp = !(_SFD_CCP_CALL(3U, 0, *chartInstance->c47_Reset != 0U,
        *chartInstance->c47_sfEvent) != 0);
      if (c47_temp) {
        c47_u0 = _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
          chartInstance->c47_ANOMALY_INIT, 32U, 3U);
        c47_temp = (_SFD_CCP_CALL(3U, 1, *chartInstance->c47_temporalCounter_i1 >=
          c47_u0 != 0U, *chartInstance->c47_sfEvent) != 0);
      }

      c47_out = (CV_TRANSITION_EVAL(3U, (int32_T)c47_temp) != 0);
      if (c47_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
        *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c47_sfEvent);
        *chartInstance->c47_is_Run = c47_IN_Nominal;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
        *chartInstance->c47_q_clean = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
        *chartInstance->c47_q_last = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
        *chartInstance->c47_dq_last = *chartInstance->c47_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
        *chartInstance->c47_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     *chartInstance->c47_sfEvent);
        *chartInstance->c47_q_clean = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
        *chartInstance->c47_q_last = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
        *chartInstance->c47_dq_last = *chartInstance->c47_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
        *chartInstance->c47_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c47_sfEvent);
      break;

     case c47_IN_Run:
      CV_CHART_EVAL(15, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   *chartInstance->c47_sfEvent);
      c47_b_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
        *chartInstance->c47_Reset != 0U, *chartInstance->c47_sfEvent)) != 0);
      guard1 = false;
      if (c47_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c47_sfEvent);
        switch (*chartInstance->c47_is_Run) {
         case c47_IN_Error:
          CV_STATE_EVAL(1, 1, 1);
          *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
          break;

         case c47_IN_Nominal:
          CV_STATE_EVAL(1, 1, 2);
          *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
          break;

         default:
          CV_STATE_EVAL(1, 1, 0);
          *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
          break;
        }

        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
        *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
        *chartInstance->c47_temporalCounter_i1 = 0U;
        *chartInstance->c47_q_clean = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
        *chartInstance->c47_q_last = *chartInstance->c47_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
        *chartInstance->c47_dq_last = *chartInstance->c47_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
        *chartInstance->c47_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
        guard1 = true;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     *chartInstance->c47_sfEvent);
        switch (*chartInstance->c47_is_Run) {
         case c47_IN_Error:
          CV_STATE_EVAL(1, 0, 1);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                       *chartInstance->c47_sfEvent);
          c47_c_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
            CV_RELATIONAL_EVAL(5U, 1U, 0, *chartInstance->c47_ErrorCount,
                               chartInstance->c47_MAX_ANOMALY, -1, 4U,
                               *chartInstance->c47_ErrorCount >
                               chartInstance->c47_MAX_ANOMALY) != 0U,
            *chartInstance->c47_sfEvent)) != 0);
          if (c47_c_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
            *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c47_sfEvent);
            *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_Init;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
            *chartInstance->c47_temporalCounter_i1 = 0U;
            *chartInstance->c47_q_clean = *chartInstance->c47_q;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
            *chartInstance->c47_q_last = *chartInstance->c47_q;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
            *chartInstance->c47_dq_last = *chartInstance->c47_dq;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
            *chartInstance->c47_ErrorCount = 0.0;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
          } else {
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                         *chartInstance->c47_sfEvent);
            c47_d_out = (CV_TRANSITION_EVAL(6U, !(_SFD_CCP_CALL(6U, 0,
              c47_check_error(chartInstance) != 0U, *chartInstance->c47_sfEvent)
              != 0)) != 0);
            if (c47_d_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U,
                           *chartInstance->c47_sfEvent);
              _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
              *chartInstance->c47_is_Run = c47_IN_Nominal;
              _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
              *chartInstance->c47_q_clean = *chartInstance->c47_q;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
              *chartInstance->c47_q_last = *chartInstance->c47_q;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
              *chartInstance->c47_dq_last = *chartInstance->c47_dq;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
              *chartInstance->c47_ErrorCount = 0.0;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
            } else {
              _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                           *chartInstance->c47_sfEvent);
              (*chartInstance->c47_ErrorCount)++;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
              *chartInstance->c47_q_clean = *chartInstance->c47_q_last +
                *chartInstance->c47_ErrorCount * *chartInstance->c47_dq_last *
                *chartInstance->c47_ANOMALY_DT;
              _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
            }
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c47_sfEvent);
          if (*chartInstance->c47_is_c47_Walking01_DDA3D != c47_IN_Run) {
          } else {
            guard1 = true;
          }
          break;

         case c47_IN_Nominal:
          CV_STATE_EVAL(1, 0, 2);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                       *chartInstance->c47_sfEvent);
          c47_e_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0,
            c47_check_error(chartInstance) != 0U, *chartInstance->c47_sfEvent))
                       != 0);
          if (c47_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c47_sfEvent);
            *chartInstance->c47_is_Run = c47_IN_Error;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
            *chartInstance->c47_dq_last = *chartInstance->c47_dq;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
            (*chartInstance->c47_ErrorCount)++;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
            *chartInstance->c47_q_clean = *chartInstance->c47_q_last +
              *chartInstance->c47_ErrorCount * *chartInstance->c47_dq_last *
              *chartInstance->c47_ANOMALY_DT;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         *chartInstance->c47_sfEvent);
            *chartInstance->c47_q_clean = *chartInstance->c47_q;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_clean, 2U);
            *chartInstance->c47_q_last = *chartInstance->c47_q;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_q_last, 5U);
            *chartInstance->c47_dq_last = *chartInstance->c47_dq;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_dq_last, 6U);
            *chartInstance->c47_ErrorCount = 0.0;
            _SFD_DATA_RANGE_CHECK(*chartInstance->c47_ErrorCount, 3U);
          }

          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c47_sfEvent);
          guard1 = true;
          break;

         default:
          CV_STATE_EVAL(1, 0, 0);
          *chartInstance->c47_is_Run = c47_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c47_sfEvent);
          guard1 = true;
          break;
        }
      }

      if (guard1 == true) {
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c47_sfEvent);
      }
      break;

     default:
      CV_CHART_EVAL(15, 0, 0);
      *chartInstance->c47_is_c47_Walking01_DDA3D = c47_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c47_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, *chartInstance->c47_sfEvent);
}

static void initSimStructsc47_Walking01_DDA3D
  (SFc47_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c47_machineNumber, uint32_T
  c47_chartNumber, uint32_T c47_instanceNumber)
{
  (void)c47_machineNumber;
  (void)c47_chartNumber;
  (void)c47_instanceNumber;
}

static const mxArray *c47_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  boolean_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(boolean_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static boolean_T c47_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  boolean_T c47_y;
  boolean_T c47_b0;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_b0, 1, 11, 0U, 0, 0U, 0);
  c47_y = c47_b0;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_err;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  boolean_T c47_y;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_err = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_err), &c47_thisId);
  sf_mex_destroy(&c47_err);
  *(boolean_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_b_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  real_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(real_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static real_T c47_b_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_nargout, const char_T *c47_identifier)
{
  real_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_nargout),
    &c47_thisId);
  sf_mex_destroy(&c47_nargout);
  return c47_y;
}

static real_T c47_c_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  real_T c47_y;
  real_T c47_d2;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_d2, 1, 0, 0U, 0, 0U, 0);
  c47_y = c47_d2;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_nargout;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  real_T c47_y;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_nargout = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_nargout),
    &c47_thisId);
  sf_mex_destroy(&c47_nargout);
  *(real_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

const mxArray *sf_c47_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c47_nameCaptureInfo = NULL;
  c47_nameCaptureInfo = NULL;
  sf_mex_assign(&c47_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
                false);
  c47_info_helper(&c47_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c47_nameCaptureInfo);
  return c47_nameCaptureInfo;
}

static void c47_info_helper(const mxArray **c47_info)
{
  const mxArray *c47_rhs0 = NULL;
  const mxArray *c47_lhs0 = NULL;
  const mxArray *c47_rhs1 = NULL;
  const mxArray *c47_lhs1 = NULL;
  const mxArray *c47_rhs2 = NULL;
  const mxArray *c47_lhs2 = NULL;
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c47_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c47_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c47_info, c47_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c47_info, c47_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c47_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c47_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c47_info, sf_mex_duplicatearraysafe(&c47_lhs2), "lhs", "lhs",
                  2);
  sf_mex_destroy(&c47_rhs0);
  sf_mex_destroy(&c47_lhs0);
  sf_mex_destroy(&c47_rhs1);
  sf_mex_destroy(&c47_lhs1);
  sf_mex_destroy(&c47_rhs2);
  sf_mex_destroy(&c47_lhs2);
}

static const mxArray *c47_emlrt_marshallOut(const char * c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c47_u)), false);
  return c47_y;
}

static const mxArray *c47_b_emlrt_marshallOut(const uint32_T c47_u)
{
  const mxArray *c47_y = NULL;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 7, 0U, 0U, 0U, 0), false);
  return c47_y;
}

static boolean_T c47_check_error(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  boolean_T c47_err;
  uint32_T c47_debug_family_var_map[3];
  real_T c47_nargin = 0.0;
  real_T c47_nargout = 1.0;
  real_T c47_hoistedGlobal;
  real_T c47_b_hoistedGlobal;
  real_T c47_x;
  real_T c47_b_x;
  real_T c47_y;
  boolean_T c47_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SET_DATA_VALUE_PTR(12U, &c47_err);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c47_debug_family_names,
    c47_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargin, 0U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_nargout, 1U, c47_b_sf_marshallOut,
    c47_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c47_err, 2U, c47_sf_marshallOut,
    c47_sf_marshallIn);
  CV_EML_FCN(4, 0);
  _SFD_EML_CALL(4U, *chartInstance->c47_sfEvent, 3);
  guard1 = false;
  guard2 = false;
  if (*chartInstance->c47_q < (*chartInstance->c47_q_limits)[0]) {
    guard2 = true;
  } else if (*chartInstance->c47_q > (*chartInstance->c47_q_limits)[1]) {
    guard2 = true;
  } else {
    c47_hoistedGlobal = *chartInstance->c47_q;
    c47_b_hoistedGlobal = *chartInstance->c47_q_clean;
    c47_x = c47_hoistedGlobal - c47_b_hoistedGlobal;
    c47_b_x = c47_x;
    c47_y = muDoubleScalarAbs(c47_b_x);
    if (c47_y > (*chartInstance->c47_ErrorCount + 1.0) *
        *chartInstance->c47_Threshold) {
      guard1 = true;
    } else {
      c47_b1 = false;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c47_b1 = true;
  }

  c47_err = c47_b1;
  _SFD_EML_CALL(4U, *chartInstance->c47_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_UNSET_DATA_VALUE_PTR(12U);
  return c47_err;
}

static const mxArray *c47_c_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(int32_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static int32_T c47_d_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  int32_T c47_y;
  int32_T c47_i1;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_i1, 1, 6, 0U, 0, 0U, 0);
  c47_y = c47_i1;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_sfEvent;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  int32_T c47_y;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_b_sfEvent = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_sfEvent),
    &c47_thisId);
  sf_mex_destroy(&c47_b_sfEvent);
  *(int32_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_d_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  uint8_T c47_u;
  const mxArray *c47_y = NULL;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  c47_u = *(uint8_T *)c47_inData;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", &c47_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static uint8_T c47_e_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_is_Run, const char_T *c47_identifier)
{
  uint8_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_is_Run),
    &c47_thisId);
  sf_mex_destroy(&c47_b_is_Run);
  return c47_y;
}

static uint8_T c47_f_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint8_T c47_y;
  uint8_T c47_u1;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u1, 1, 3, 0U, 0, 0U, 0);
  c47_y = c47_u1;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void c47_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c47_mxArrayInData, const char_T *c47_varName, void *c47_outData)
{
  const mxArray *c47_b_is_Run;
  const char_T *c47_identifier;
  emlrtMsgIdentifier c47_thisId;
  uint8_T c47_y;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_b_is_Run = sf_mex_dup(c47_mxArrayInData);
  c47_identifier = c47_varName;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c47_b_is_Run),
    &c47_thisId);
  sf_mex_destroy(&c47_b_is_Run);
  *(uint8_T *)c47_outData = c47_y;
  sf_mex_destroy(&c47_mxArrayInData);
}

static const mxArray *c47_e_sf_marshallOut(void *chartInstanceVoid, void
  *c47_inData)
{
  const mxArray *c47_mxArrayOutData = NULL;
  int32_T c47_i2;
  real_T c47_b_inData[2];
  int32_T c47_i3;
  real_T c47_u[2];
  const mxArray *c47_y = NULL;
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c47_mxArrayOutData = NULL;
  for (c47_i2 = 0; c47_i2 < 2; c47_i2++) {
    c47_b_inData[c47_i2] = (*(real_T (*)[2])c47_inData)[c47_i2];
  }

  for (c47_i3 = 0; c47_i3 < 2; c47_i3++) {
    c47_u[c47_i3] = c47_b_inData[c47_i3];
  }

  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_create("y", c47_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c47_mxArrayOutData, c47_y, false);
  return c47_mxArrayOutData;
}

static uint32_T c47_g_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_temporalCounter_i1, const char_T
  *c47_identifier)
{
  uint32_T c47_y;
  emlrtMsgIdentifier c47_thisId;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  c47_y = c47_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_temporalCounter_i1), &c47_thisId);
  sf_mex_destroy(&c47_b_temporalCounter_i1);
  return c47_y;
}

static uint32_T c47_h_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  uint32_T c47_y;
  uint32_T c47_u2;
  (void)chartInstance;
  sf_mex_import(c47_parentId, sf_mex_dup(c47_u), &c47_u2, 1, 7, 0U, 0, 0U, 0);
  c47_y = c47_u2;
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static const mxArray *c47_i_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_b_setSimStateSideEffectsInfo, const char_T *
  c47_identifier)
{
  const mxArray *c47_y = NULL;
  emlrtMsgIdentifier c47_thisId;
  c47_y = NULL;
  c47_thisId.fIdentifier = c47_identifier;
  c47_thisId.fParent = NULL;
  sf_mex_assign(&c47_y, c47_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c47_b_setSimStateSideEffectsInfo), &c47_thisId), false);
  sf_mex_destroy(&c47_b_setSimStateSideEffectsInfo);
  return c47_y;
}

static const mxArray *c47_j_emlrt_marshallIn(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c47_u, const emlrtMsgIdentifier *c47_parentId)
{
  const mxArray *c47_y = NULL;
  (void)chartInstance;
  (void)c47_parentId;
  c47_y = NULL;
  sf_mex_assign(&c47_y, sf_mex_duplicatearraysafe(&c47_u), false);
  sf_mex_destroy(&c47_u);
  return c47_y;
}

static void init_dsm_address_info(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc47_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c47_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c47_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c47_is_active_c47_Walking01_DDA3D = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c47_is_c47_Walking01_DDA3D = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c47_is_Run = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c47_q = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c47_dq = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c47_q_clean = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c47_ErrorCount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c47_q_last = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c47_dq_last = (real_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c47_q_limits = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c47_Threshold = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c47_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c47_ANOMALY_DT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c47_temporalCounter_i1 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 7);
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

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c47_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2608545269U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2378567437U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(223846838U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4171864177U);
}

mxArray* sf_c47_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c47_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hHNt928gQKItxqEcoHjKRF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c47_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c47_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c47_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c47_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c47_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c47_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[12],T\"ErrorCount\",},{M[1],M[8],T\"q_clean\",},{M[3],M[18],T\"dq_last\",},{M[3],M[17],T\"q_last\",},{M[8],M[0],T\"is_active_c47_Walking01_DDA3D\",},{M[9],M[0],T\"is_c47_Walking01_DDA3D\",},{M[9],M[27],T\"is_Run\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M[20],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c47_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           47,
           5,
           7,
           0,
           13,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Walking01_DDA3DMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking01_DDA3DMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking01_DDA3DMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(2,2,0,1,"q_clean");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ErrorCount");
          _SFD_SET_DATA_PROPS(4,10,0,0,"MAX_ANOMALY");
          _SFD_SET_DATA_PROPS(5,0,0,0,"q_last");
          _SFD_SET_DATA_PROPS(6,0,0,0,"dq_last");
          _SFD_SET_DATA_PROPS(7,10,0,0,"ANOMALY_INIT");
          _SFD_SET_DATA_PROPS(8,1,1,0,"q_limits");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Threshold");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Reset");
          _SFD_SET_DATA_PROPS(11,1,1,0,"ANOMALY_DT");
          _SFD_SET_DATA_PROPS(12,9,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 11 };

          static unsigned int sEndGuardMap[] = { 7, 36 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),4,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 4 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(4,0,"check_error",0,-1,140);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)
          c47_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c47_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c47_sf_marshallOut,(MexInFcnForType)c47_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(12,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c47_q);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c47_dq);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c47_q_clean);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c47_ErrorCount);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c47_MAX_ANOMALY);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c47_q_last);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c47_dq_last);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c47_ANOMALY_INIT);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c47_q_limits);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c47_Threshold);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c47_Reset);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c47_ANOMALY_DT);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking01_DDA3DMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "SjtkZZxyw5jP8NWyl6PAiB";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 47, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  ext_mode_exec_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c47_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c47_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c47_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc47_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c47_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c47_Walking01_DDA3D((SFc47_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

mxArray *sf_c47_Walking01_DDA3D_get_testpoint_info(void)
{
  return NULL;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x8'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"uint32\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 8, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 1724620448U, 3335412165U, 3353573579U,
    4259520096U };

  return checksum;
}

static void mdlSetWorkWidths_c47_Walking01_DDA3D(SimStruct *S)
{
  /* Actual parameters from chart:
     ANOMALY_INIT MAX_ANOMALY
   */
  const char_T *rtParamNames[] = { "ANOMALY_INIT", "MAX_ANOMALY" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for ANOMALY_INIT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for MAX_ANOMALY*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      47);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,47,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,47,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,47);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,47,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,47,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,47);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(277054885U));
  ssSetChecksum1(S,(320012024U));
  ssSetChecksum2(S,(1782341178U));
  ssSetChecksum3(S,(903248797U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c47_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c47_Walking01_DDA3D(SimStruct *S)
{
  SFc47_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc47_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc47_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc47_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c47_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c47_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c47_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c47_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c47_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c47_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c47_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c47_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c47_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c47_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c47_Walking01_DDA3D;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c47_Walking01_DDA3D;
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

void c47_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c47_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c47_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c47_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c47_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
