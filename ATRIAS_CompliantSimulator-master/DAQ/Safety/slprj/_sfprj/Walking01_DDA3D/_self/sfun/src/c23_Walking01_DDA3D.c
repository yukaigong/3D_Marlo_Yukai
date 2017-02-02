/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c23_Walking01_DDA3D.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c23_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c23_IN_FaultRunning            ((uint8_T)1U)
#define c23_IN_Initialization          ((uint8_T)2U)
#define c23_IN_Running                 ((uint8_T)3U)
#define c23_IN_Start1                  ((uint8_T)4U)
#define c23_IN_Fault                   ((uint8_T)1U)
#define c23_IN_ReadyToSwitchOn         ((uint8_T)2U)
#define c23_IN_SwitchOnDisabled        ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c23_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c23_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c23_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c23_update_debugger_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static void ext_mode_exec_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c23_st);
static void c23_set_sim_state_side_effects_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static void finalize_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance);
static void c23_Initialization(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c23_exit_internal_Initialization(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_nargout, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static boolean_T c23_c_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_d_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static uint8_T c23_e_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_is_Initialization, const char_T
  *c23_identifier);
static uint8_T c23_f_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static void c23_g_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_dataWrittenToVector, const char_T
  *c23_identifier, boolean_T c23_y[4]);
static void c23_h_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  boolean_T c23_y[4]);
static const mxArray *c23_i_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_setSimStateSideEffectsInfo, const char_T *
  c23_identifier);
static const mxArray *c23_j_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_updateDataWrittenToVector(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c23_vectorIndex);
static void c23_errorIfDataNotWrittenToFcn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c23_vectorIndex, uint32_T c23_dataNumber, uint32_T
  c23_ssIdOfSourceObject, int32_T c23_offsetInSourceObject, int32_T
  c23_lengthInSourceObject);
static void init_dsm_address_info(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  *chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c23_doSetSimStateSideEffects = 0U;
  chartInstance->c23_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
  *chartInstance->c23_is_active_c23_Walking01_DDA3D = 0U;
  *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c23_update_debugger_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  uint32_T c23_prevAniVal;
  c23_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c23_is_active_c23_Walking01_DDA3D == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 17U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_c23_Walking01_DDA3D == c23_IN_Start1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_c23_Walking01_DDA3D == c23_IN_Initialization) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_Initialization == c23_IN_SwitchOnDisabled) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_Initialization == c23_IN_Fault) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_Initialization == c23_IN_ReadyToSwitchOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_c23_Walking01_DDA3D == c23_IN_FaultRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
  }

  if (*chartInstance->c23_is_c23_Walking01_DDA3D == c23_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
  }

  _SFD_SET_ANIMATION(c23_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  c23_update_debugger_state_c23_Walking01_DDA3D(chartInstance);
}

static const mxArray *get_sim_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_b_hoistedGlobal;
  real_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T c23_c_hoistedGlobal;
  real_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  real_T c23_d_hoistedGlobal;
  real_T c23_d_u;
  const mxArray *c23_e_y = NULL;
  uint8_T c23_e_hoistedGlobal;
  uint8_T c23_e_u;
  const mxArray *c23_f_y = NULL;
  uint8_T c23_f_hoistedGlobal;
  uint8_T c23_f_u;
  const mxArray *c23_g_y = NULL;
  uint8_T c23_g_hoistedGlobal;
  uint8_T c23_g_u;
  const mxArray *c23_h_y = NULL;
  int32_T c23_i0;
  boolean_T c23_h_u[4];
  const mxArray *c23_i_y = NULL;
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellmatrix(8, 1), false);
  c23_hoistedGlobal = *chartInstance->c23_ControlWordIndex;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = *chartInstance->c23_EnableTargetTorque;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_hoistedGlobal = *chartInstance->c23_FaultDetected;
  c23_c_u = c23_c_hoistedGlobal;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 2, c23_d_y);
  c23_d_hoistedGlobal = *chartInstance->c23_Timeout;
  c23_d_u = c23_d_hoistedGlobal;
  c23_e_y = NULL;
  sf_mex_assign(&c23_e_y, sf_mex_create("y", &c23_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 3, c23_e_y);
  c23_e_hoistedGlobal = *chartInstance->c23_is_active_c23_Walking01_DDA3D;
  c23_e_u = c23_e_hoistedGlobal;
  c23_f_y = NULL;
  sf_mex_assign(&c23_f_y, sf_mex_create("y", &c23_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 4, c23_f_y);
  c23_f_hoistedGlobal = *chartInstance->c23_is_c23_Walking01_DDA3D;
  c23_f_u = c23_f_hoistedGlobal;
  c23_g_y = NULL;
  sf_mex_assign(&c23_g_y, sf_mex_create("y", &c23_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 5, c23_g_y);
  c23_g_hoistedGlobal = *chartInstance->c23_is_Initialization;
  c23_g_u = c23_g_hoistedGlobal;
  c23_h_y = NULL;
  sf_mex_assign(&c23_h_y, sf_mex_create("y", &c23_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c23_y, 6, c23_h_y);
  for (c23_i0 = 0; c23_i0 < 4; c23_i0++) {
    c23_h_u[c23_i0] = chartInstance->c23_dataWrittenToVector[c23_i0];
  }

  c23_i_y = NULL;
  sf_mex_assign(&c23_i_y, sf_mex_create("y", c23_h_u, 11, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c23_y, 7, c23_i_y);
  sf_mex_assign(&c23_st, c23_y, false);
  return c23_st;
}

static void set_sim_state_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c23_st)
{
  const mxArray *c23_u;
  boolean_T c23_bv0[4];
  int32_T c23_i1;
  c23_u = sf_mex_dup(c23_st);
  *chartInstance->c23_ControlWordIndex = c23_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 0)), "ControlWordIndex");
  *chartInstance->c23_EnableTargetTorque = c23_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 1)), "EnableTargetTorque");
  *chartInstance->c23_FaultDetected = c23_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 2)), "FaultDetected");
  *chartInstance->c23_Timeout = c23_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 3)), "Timeout");
  *chartInstance->c23_is_active_c23_Walking01_DDA3D = c23_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 4)),
     "is_active_c23_Walking01_DDA3D");
  *chartInstance->c23_is_c23_Walking01_DDA3D = c23_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 5)),
     "is_c23_Walking01_DDA3D");
  *chartInstance->c23_is_Initialization = c23_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c23_u, 6)), "is_Initialization");
  c23_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 7)),
    "dataWrittenToVector", c23_bv0);
  for (c23_i1 = 0; c23_i1 < 4; c23_i1++) {
    chartInstance->c23_dataWrittenToVector[c23_i1] = c23_bv0[c23_i1];
  }

  sf_mex_assign(&chartInstance->c23_setSimStateSideEffectsInfo,
                c23_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c23_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c23_u);
  chartInstance->c23_doSetSimStateSideEffects = 1U;
  c23_update_debugger_state_c23_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void c23_set_sim_state_side_effects_c23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  if (chartInstance->c23_doSetSimStateSideEffects != 0) {
    chartInstance->c23_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c23_setSimStateSideEffectsInfo);
}

static void sf_gateway_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  uint32_T c23_debug_family_var_map[2];
  real_T c23_nargin = 0.0;
  real_T c23_nargout = 0.0;
  uint32_T c23_b_debug_family_var_map[3];
  real_T c23_b_nargin = 0.0;
  real_T c23_b_nargout = 1.0;
  boolean_T c23_out;
  real_T c23_c_nargin = 0.0;
  real_T c23_c_nargout = 0.0;
  real_T c23_d_nargin = 0.0;
  real_T c23_d_nargout = 1.0;
  boolean_T c23_b_out;
  real_T c23_e_nargin = 0.0;
  real_T c23_e_nargout = 0.0;
  real_T c23_f_nargin = 0.0;
  real_T c23_f_nargout = 1.0;
  boolean_T c23_c_out;
  real_T c23_g_nargin = 0.0;
  real_T c23_g_nargout = 0.0;
  boolean_T guard1 = false;
  c23_set_sim_state_side_effects_c23_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, *chartInstance->c23_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c23_SwitchOnDisabledMode, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c23_EnabledMode, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c23_ReadyToSwitchOnMode, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c23_FaultMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c23_MedullaCommand, 8U);
  *chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, *chartInstance->c23_sfEvent);
  if (*chartInstance->c23_is_active_c23_Walking01_DDA3D == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 17U,
                 *chartInstance->c23_sfEvent);
    *chartInstance->c23_is_active_c23_Walking01_DDA3D = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *chartInstance->c23_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c23_sfEvent);
    *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_Start1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c23_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_debug_family_names,
      c23_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    *chartInstance->c23_ControlWordIndex = 0.0;
    c23_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
    *chartInstance->c23_EnableTargetTorque = 0.0;
    c23_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
    *chartInstance->c23_FaultDetected = 0.0;
    c23_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c23_is_c23_Walking01_DDA3D) {
     case c23_IN_FaultRunning:
      CV_CHART_EVAL(17, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   *chartInstance->c23_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c23_sfEvent);
      break;

     case c23_IN_Initialization:
      CV_CHART_EVAL(17, 0, 2);
      c23_Initialization(chartInstance);
      break;

     case c23_IN_Running:
      CV_CHART_EVAL(17, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_r_debug_family_names,
        c23_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
        *chartInstance->c23_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c23_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_h_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *chartInstance->c23_ControlWordIndex = 1.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
        *chartInstance->c23_EnableTargetTorque = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
        *chartInstance->c23_FaultDetected = 1.0;
        c23_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_s_debug_family_names,
          c23_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_out, 2U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
              *chartInstance->c23_MedullaCommand, 4.0, -1, 0U,
              *chartInstance->c23_MedullaCommand == 4.0))) {
          guard1 = true;
        } else if (CV_EML_COND(12, 0, 1, CV_RELATIONAL_EVAL(5U, 12U, 1,
                     *chartInstance->c23_MedullaCommand, 5.0, -1, 0U,
                     *chartInstance->c23_MedullaCommand == 5.0))) {
          guard1 = true;
        } else {
          CV_EML_MCDC(12, 0, 0, false);
          CV_EML_IF(12, 0, 0, false);
          c23_b_out = false;
        }

        if (guard1 == true) {
          CV_EML_MCDC(12, 0, 0, true);
          CV_EML_IF(12, 0, 0, true);
          c23_b_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c23_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c23_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
          *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_FaultRunning;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_h_debug_family_names,
            c23_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          *chartInstance->c23_ControlWordIndex = 1.0;
          c23_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
          *chartInstance->c23_EnableTargetTorque = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
          *chartInstance->c23_FaultDetected = 1.0;
          c23_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       *chartInstance->c23_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c23_sfEvent);
      break;

     case c23_IN_Start1:
      CV_CHART_EVAL(17, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_p_debug_family_names,
        c23_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_c_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
        *chartInstance->c23_MedullaCommand, 2.0, -1, 0U,
        *chartInstance->c23_MedullaCommand == 2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_Initialization;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_Initialization = c23_IN_SwitchOnDisabled;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_b_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *chartInstance->c23_ControlWordIndex = 1.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
        *chartInstance->c23_Timeout = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
        *chartInstance->c23_EnableTargetTorque = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
        *chartInstance->c23_FaultDetected = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     *chartInstance->c23_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c23_sfEvent);
      break;

     default:
      CV_CHART_EVAL(17, 0, 0);
      *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, *chartInstance->c23_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c23_Walking01_DDA3D(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc23_Walking01_DDA3D
  (SFc23_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c23_Initialization(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  uint32_T c23_debug_family_var_map[3];
  real_T c23_nargin = 0.0;
  real_T c23_nargout = 1.0;
  boolean_T c23_out;
  uint32_T c23_b_debug_family_var_map[2];
  real_T c23_b_nargin = 0.0;
  real_T c23_b_nargout = 0.0;
  real_T c23_c_nargin = 0.0;
  real_T c23_c_nargout = 1.0;
  boolean_T c23_b_out;
  real_T c23_d_nargin = 0.0;
  real_T c23_d_nargout = 0.0;
  real_T c23_e_nargin = 0.0;
  real_T c23_e_nargout = 1.0;
  boolean_T c23_c_out;
  real_T c23_f_nargin = 0.0;
  real_T c23_f_nargout = 0.0;
  real_T c23_g_nargin = 0.0;
  real_T c23_g_nargout = 0.0;
  real_T c23_h_nargin = 0.0;
  real_T c23_h_nargout = 1.0;
  boolean_T c23_d_out;
  real_T c23_i_nargin = 0.0;
  real_T c23_i_nargout = 0.0;
  real_T c23_j_nargin = 0.0;
  real_T c23_j_nargout = 1.0;
  boolean_T c23_e_out;
  real_T c23_k_nargin = 0.0;
  real_T c23_k_nargout = 0.0;
  real_T c23_l_nargin = 0.0;
  real_T c23_l_nargout = 1.0;
  boolean_T c23_f_out;
  real_T c23_m_nargin = 0.0;
  real_T c23_m_nargout = 0.0;
  real_T c23_n_nargin = 0.0;
  real_T c23_n_nargout = 0.0;
  real_T c23_o_nargin = 0.0;
  real_T c23_o_nargout = 1.0;
  boolean_T c23_g_out;
  real_T c23_p_nargin = 0.0;
  real_T c23_p_nargout = 0.0;
  real_T c23_q_nargin = 0.0;
  real_T c23_q_nargout = 1.0;
  boolean_T c23_h_out;
  real_T c23_r_nargin = 0.0;
  real_T c23_r_nargout = 0.0;
  real_T c23_s_nargin = 0.0;
  real_T c23_s_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, *chartInstance->c23_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_q_debug_family_names,
    c23_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargin, 0U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_nargout, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_out, 2U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
        *chartInstance->c23_MedullaCommand, 4.0, -1, 0U,
        *chartInstance->c23_MedullaCommand == 4.0))) {
    guard3 = true;
  } else if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
               *chartInstance->c23_MedullaCommand, 5.0, -1, 0U,
               *chartInstance->c23_MedullaCommand == 5.0))) {
    guard3 = true;
  } else {
    CV_EML_MCDC(9, 0, 0, false);
    CV_EML_IF(9, 0, 0, false);
    c23_out = false;
  }

  if (guard3 == true) {
    CV_EML_MCDC(9, 0, 0, true);
    CV_EML_IF(9, 0, 0, true);
    c23_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c23_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c23_sfEvent);
    c23_exit_internal_Initialization(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
    *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_FaultRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_h_debug_family_names,
      c23_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargin, 0U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_nargout, 1U, c23_sf_marshallOut,
      c23_sf_marshallIn);
    *chartInstance->c23_ControlWordIndex = 1.0;
    c23_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
    *chartInstance->c23_EnableTargetTorque = 0.0;
    c23_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
    *chartInstance->c23_FaultDetected = 1.0;
    c23_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                 *chartInstance->c23_sfEvent);
    switch (*chartInstance->c23_is_Initialization) {
     case c23_IN_Fault:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   *chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_k_debug_family_names,
        c23_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_b_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 164U, 1, 7);
      c23_b_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
        *chartInstance->c23_Timeout, 20.0, -1, 5U, *chartInstance->c23_Timeout >=
        20.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c23_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_Initialization = c23_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_d_debug_family_names,
          c23_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *chartInstance->c23_ControlWordIndex = 3.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
        *chartInstance->c23_EnableTargetTorque = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
        *chartInstance->c23_Timeout = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
        *chartInstance->c23_FaultDetected = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_m_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_c_out, 2U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        c23_c_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
          *chartInstance->c23_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c23_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c23_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
          *chartInstance->c23_is_Initialization = c23_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_b_debug_family_names,
            c23_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          *chartInstance->c23_ControlWordIndex = 1.0;
          c23_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
          *chartInstance->c23_Timeout = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
          *chartInstance->c23_EnableTargetTorque = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
          *chartInstance->c23_FaultDetected = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_e_debug_family_names,
            c23_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          c23_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 163U, 129, 7);
          (*chartInstance->c23_Timeout)++;
          c23_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
          *chartInstance->c23_ControlWordIndex = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c23_sfEvent);
      guard1 = true;
      break;

     case c23_IN_ReadyToSwitchOn:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   *chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_o_debug_family_names,
        c23_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_h_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_h_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_d_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_d_out = CV_EML_IF(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0, (real_T)
        *chartInstance->c23_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c23_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c23_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_Initialization = c23_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_d_debug_family_names,
          c23_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_i_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_i_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *chartInstance->c23_ControlWordIndex = 3.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
        *chartInstance->c23_EnableTargetTorque = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
        *chartInstance->c23_Timeout = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
        *chartInstance->c23_FaultDetected = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_l_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_j_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_j_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_e_out, 2U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        c23_e_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
          *chartInstance->c23_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c23_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c23_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c23_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
          *chartInstance->c23_is_Initialization = c23_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_b_debug_family_names,
            c23_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_k_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_k_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          *chartInstance->c23_ControlWordIndex = 1.0;
          c23_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
          *chartInstance->c23_Timeout = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
          *chartInstance->c23_EnableTargetTorque = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
          *chartInstance->c23_FaultDetected = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_t_debug_family_names,
            c23_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_l_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_l_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_f_out, 2U,
            c23_b_sf_marshallOut, c23_b_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
                *chartInstance->c23_EnabledMode, 1.0, -1, 0U, (real_T)
                *chartInstance->c23_EnabledMode == 1.0))) {
            if (CV_EML_COND(8, 0, 1, CV_RELATIONAL_EVAL(5U, 8U, 1, (real_T)
                  *chartInstance->c23_FaultMode, 0.0, -1, 0U, (real_T)
                  *chartInstance->c23_FaultMode == 0.0))) {
              CV_EML_MCDC(8, 0, 0, true);
              CV_EML_IF(8, 0, 0, true);
              c23_f_out = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(8, 0, 0, false);
            CV_EML_IF(8, 0, 0, false);
            c23_f_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c23_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c23_sfEvent);
            *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c23_sfEvent);
            *chartInstance->c23_is_c23_Walking01_DDA3D = c23_IN_Running;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c23_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_i_debug_family_names,
              c23_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_m_nargin, 0U,
              c23_sf_marshallOut, c23_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_m_nargout, 1U,
              c23_sf_marshallOut, c23_sf_marshallIn);
            *chartInstance->c23_FaultDetected = 0.0;
            c23_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
            *chartInstance->c23_ControlWordIndex = 2.0;
            c23_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
            *chartInstance->c23_EnableTargetTorque = 1.0;
            c23_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         *chartInstance->c23_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_g_debug_family_names,
              c23_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_n_nargin, 0U,
              c23_sf_marshallOut, c23_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_n_nargout, 1U,
              c23_sf_marshallOut, c23_sf_marshallIn);
            c23_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 162U, 139, 7);
            (*chartInstance->c23_Timeout)++;
            c23_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c23_sfEvent);
      if (*chartInstance->c23_is_c23_Walking01_DDA3D != c23_IN_Initialization) {
      } else {
        guard1 = true;
      }
      break;

     case c23_IN_SwitchOnDisabled:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c23_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_n_debug_family_names,
        c23_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_o_nargin, 0U, c23_sf_marshallOut,
        c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_o_nargout, 1U,
        c23_sf_marshallOut, c23_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_g_out, 2U, c23_b_sf_marshallOut,
        c23_b_sf_marshallIn);
      c23_g_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c23_ReadyToSwitchOnMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c23_ReadyToSwitchOnMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c23_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
        *chartInstance->c23_is_Initialization = c23_IN_ReadyToSwitchOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_f_debug_family_names,
          c23_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_p_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_p_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        *chartInstance->c23_ControlWordIndex = 2.0;
        c23_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
        *chartInstance->c23_Timeout = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
        *chartInstance->c23_EnableTargetTorque = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
        *chartInstance->c23_FaultDetected = 0.0;
        c23_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     *chartInstance->c23_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c23_j_debug_family_names,
          c23_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_q_nargin, 0U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_q_nargout, 1U,
          c23_sf_marshallOut, c23_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_h_out, 2U,
          c23_b_sf_marshallOut, c23_b_sf_marshallIn);
        c23_h_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
          *chartInstance->c23_FaultMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c23_FaultMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c23_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
          *chartInstance->c23_is_Initialization = c23_IN_Fault;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_d_debug_family_names,
            c23_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_r_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_r_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          *chartInstance->c23_ControlWordIndex = 3.0;
          c23_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_ControlWordIndex, 3U);
          *chartInstance->c23_EnableTargetTorque = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_EnableTargetTorque, 4U);
          *chartInstance->c23_Timeout = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
          *chartInstance->c23_FaultDetected = 0.0;
          c23_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c23_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c23_c_debug_family_names,
            c23_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_s_nargin, 0U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c23_s_nargout, 1U,
            c23_sf_marshallOut, c23_sf_marshallIn);
          c23_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 159U, 140, 7);
          (*chartInstance->c23_Timeout)++;
          c23_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c23_Timeout, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c23_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c23_sfEvent);
  }
}

static void c23_exit_internal_Initialization(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  switch (*chartInstance->c23_is_Initialization) {
   case c23_IN_Fault:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
    break;

   case c23_IN_ReadyToSwitchOn:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c23_sfEvent);
    break;

   case c23_IN_SwitchOnDisabled:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c23_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c23_is_Initialization = c23_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c23_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber, uint32_T c23_instanceNumber)
{
  (void)c23_machineNumber;
  (void)c23_chartNumber;
  (void)c23_instanceNumber;
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_nargout, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  return c23_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  boolean_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(boolean_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static boolean_T c23_c_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  boolean_T c23_y;
  boolean_T c23_b0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_b0, 1, 11, 0U, 0, 0U, 0);
  c23_y = c23_b0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_sf_internal_predicateOutput;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  boolean_T c23_y;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_sf_internal_predicateOutput = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_sf_internal_predicateOutput), &c23_thisId);
  sf_mex_destroy(&c23_sf_internal_predicateOutput);
  *(boolean_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static int32_T c23_d_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i2;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i2, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i2;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  uint8_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(uint8_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, false);
  return c23_mxArrayOutData;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_is_Initialization, const char_T
  *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_Initialization), &c23_thisId);
  sf_mex_destroy(&c23_b_is_Initialization);
  return c23_y;
}

static uint8_T c23_f_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_is_Initialization;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  uint8_T c23_y;
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c23_b_is_Initialization = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_Initialization), &c23_thisId);
  sf_mex_destroy(&c23_b_is_Initialization);
  *(uint8_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static void c23_g_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_dataWrittenToVector, const char_T
  *c23_identifier, boolean_T c23_y[4])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_dataWrittenToVector),
    &c23_thisId, c23_y);
  sf_mex_destroy(&c23_b_dataWrittenToVector);
}

static void c23_h_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  boolean_T c23_y[4])
{
  boolean_T c23_bv1[4];
  int32_T c23_i3;
  (void)chartInstance;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c23_i3 = 0; c23_i3 < 4; c23_i3++) {
    c23_y[c23_i3] = c23_bv1[c23_i3];
  }

  sf_mex_destroy(&c23_u);
}

static const mxArray *c23_i_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_b_setSimStateSideEffectsInfo, const char_T *
  c23_identifier)
{
  const mxArray *c23_y = NULL;
  emlrtMsgIdentifier c23_thisId;
  c23_y = NULL;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  sf_mex_assign(&c23_y, c23_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_setSimStateSideEffectsInfo), &c23_thisId), false);
  sf_mex_destroy(&c23_b_setSimStateSideEffectsInfo);
  return c23_y;
}

static const mxArray *c23_j_emlrt_marshallIn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  const mxArray *c23_y = NULL;
  (void)chartInstance;
  (void)c23_parentId;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_duplicatearraysafe(&c23_u), false);
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_updateDataWrittenToVector(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c23_vectorIndex)
{
  chartInstance->c23_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
    (0U, (int32_T)c23_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c23_errorIfDataNotWrittenToFcn(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c23_vectorIndex, uint32_T c23_dataNumber, uint32_T
  c23_ssIdOfSourceObject, int32_T c23_offsetInSourceObject, int32_T
  c23_lengthInSourceObject)
{
  (void)c23_ssIdOfSourceObject;
  (void)c23_offsetInSourceObject;
  (void)c23_lengthInSourceObject;
  if (!chartInstance->c23_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c23_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c23_dataNumber);
  }
}

static void init_dsm_address_info(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc23_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c23_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c23_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c23_is_active_c23_Walking01_DDA3D = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c23_is_c23_Walking01_DDA3D = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c23_is_Initialization = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c23_SwitchOnDisabledMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c23_EnabledMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c23_ReadyToSwitchOnMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c23_ControlWordIndex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c23_EnableTargetTorque = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c23_Timeout = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c23_FaultMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c23_FaultDetected = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c23_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
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
void sf_c23_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2160475896U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1717963147U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2216511939U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1856603302U);
}

mxArray* sf_c23_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c23_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TxaujBQiZR71hjzOPc7piE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c23_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c23_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c23_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c23_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c23_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c23_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[23],T\"ControlWordIndex\",},{M[1],M[24],T\"EnableTargetTorque\",},{M[1],M[64],T\"FaultDetected\",},{M[3],M[25],T\"Timeout\",},{M[8],M[0],T\"is_active_c23_Walking01_DDA3D\",},{M[9],M[0],T\"is_c23_Walking01_DDA3D\",},{M[9],M[144],T\"is_Initialization\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           23,
           7,
           13,
           0,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"SwitchOnDisabledMode");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EnabledMode");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ReadyToSwitchOnMode");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ControlWordIndex");
          _SFD_SET_DATA_PROPS(4,2,0,1,"EnableTargetTorque");
          _SFD_SET_DATA_PROPS(5,0,0,0,"Timeout");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FaultMode");
          _SFD_SET_DATA_PROPS(7,2,0,1,"FaultDetected");
          _SFD_SET_DATA_PROPS(8,1,1,0,"MedullaCommand");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_CH_SUBSTATE_INDEX(3,6);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,1,1,0,0,NULL,NULL);
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

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,13,1,13);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,13,-1,5);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,25,1,25);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,25,-1,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,20,1,20);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 20, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(12,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 20, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 17, 35 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,35,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,17,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,1,21,35,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c23_SwitchOnDisabledMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c23_EnabledMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c23_ReadyToSwitchOnMode);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c23_ControlWordIndex);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c23_EnableTargetTorque);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c23_Timeout);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c23_FaultMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c23_FaultDetected);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c23_MedullaCommand);
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
  return "VA7C3SkkKJYTGOIpcl5SmH";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 23, "dworkChecksum");
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

static void sf_opaque_initialize_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  ext_mode_exec_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c23_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c23_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c23_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c23_Walking01_DDA3D((SFc23_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

mxArray *sf_c23_Walking01_DDA3D_get_testpoint_info(void)
{
  return NULL;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x6'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 6, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 681835801U, 929203061U, 1272024938U,
    1618980159U };

  return checksum;
}

static void mdlSetWorkWidths_c23_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,23,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,23);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,23,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,23,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2442605241U));
  ssSetChecksum1(S,(2326670610U));
  ssSetChecksum2(S,(702605032U));
  ssSetChecksum3(S,(564155161U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c23_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c23_Walking01_DDA3D(SimStruct *S)
{
  SFc23_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc23_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc23_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c23_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c23_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_Walking01_DDA3D;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_Walking01_DDA3D;
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

void c23_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
