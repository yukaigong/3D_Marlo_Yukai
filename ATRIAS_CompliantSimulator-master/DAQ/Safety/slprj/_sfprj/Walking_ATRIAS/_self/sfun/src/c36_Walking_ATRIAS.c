/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c36_Walking_ATRIAS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking_ATRIAS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c36_debug_family_names[6] = { "MEDULLA_ADC_MAX_VOLTS",
  "MEDULLA_ADC_OFFSET_COUNTS", "nargin", "nargout", "adc_value", "logicVoltage"
};

/* Function Declarations */
static void initialize_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c36_update_debugger_state_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c36_st);
static void finalize_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initSimStructsc36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber);
static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static void c36_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_b_logicVoltage, const char_T
  *c36_identifier, real_T c36_y[6]);
static void c36_b_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[6]);
static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static real_T c36_c_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static void c36_info_helper(const mxArray **c36_info);
static const mxArray *c36_emlrt_marshallOut(const char * c36_u);
static const mxArray *c36_b_emlrt_marshallOut(const uint32_T c36_u);
static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData);
static int32_T c36_d_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData);
static uint8_T c36_e_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_Walking_ATRIAS, const
  char_T *c36_identifier);
static uint8_T c36_f_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId);
static void init_dsm_address_info(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c36_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c36_is_active_c36_Walking_ATRIAS = 0U;
}

static void initialize_params_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c36_update_debugger_state_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c36_Walking_ATRIAS
  (SFc36_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c36_st;
  const mxArray *c36_y = NULL;
  int32_T c36_i0;
  real_T c36_u[6];
  const mxArray *c36_b_y = NULL;
  uint8_T c36_hoistedGlobal;
  uint8_T c36_b_u;
  const mxArray *c36_c_y = NULL;
  c36_st = NULL;
  c36_st = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_createcellmatrix(2, 1), false);
  for (c36_i0 = 0; c36_i0 < 6; c36_i0++) {
    c36_u[c36_i0] = (*chartInstance->c36_logicVoltage)[c36_i0];
  }

  c36_b_y = NULL;
  sf_mex_assign(&c36_b_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c36_y, 0, c36_b_y);
  c36_hoistedGlobal = chartInstance->c36_is_active_c36_Walking_ATRIAS;
  c36_b_u = c36_hoistedGlobal;
  c36_c_y = NULL;
  sf_mex_assign(&c36_c_y, sf_mex_create("y", &c36_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c36_y, 1, c36_c_y);
  sf_mex_assign(&c36_st, c36_y, false);
  return c36_st;
}

static void set_sim_state_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c36_st)
{
  const mxArray *c36_u;
  real_T c36_dv0[6];
  int32_T c36_i1;
  chartInstance->c36_doneDoubleBufferReInit = true;
  c36_u = sf_mex_dup(c36_st);
  c36_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 0)),
                       "logicVoltage", c36_dv0);
  for (c36_i1 = 0; c36_i1 < 6; c36_i1++) {
    (*chartInstance->c36_logicVoltage)[c36_i1] = c36_dv0[c36_i1];
  }

  chartInstance->c36_is_active_c36_Walking_ATRIAS = c36_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c36_u, 1)),
     "is_active_c36_Walking_ATRIAS");
  sf_mex_destroy(&c36_u);
  c36_update_debugger_state_c36_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c36_st);
}

static void finalize_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  int32_T c36_i2;
  int32_T c36_i3;
  real_T c36_b_adc_value[6];
  uint32_T c36_debug_family_var_map[6];
  real_T c36_MEDULLA_ADC_MAX_VOLTS;
  real_T c36_MEDULLA_ADC_OFFSET_COUNTS;
  real_T c36_nargin = 1.0;
  real_T c36_nargout = 1.0;
  real_T c36_b_logicVoltage[6];
  int32_T c36_i4;
  real_T c36_a[6];
  int32_T c36_i5;
  int32_T c36_i6;
  int32_T c36_i7;
  int32_T c36_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c36_sfEvent);
  for (c36_i2 = 0; c36_i2 < 6; c36_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_adc_value)[c36_i2], 0U);
  }

  chartInstance->c36_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c36_sfEvent);
  for (c36_i3 = 0; c36_i3 < 6; c36_i3++) {
    c36_b_adc_value[c36_i3] = (*chartInstance->c36_adc_value)[c36_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c36_debug_family_names,
    c36_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c36_MEDULLA_ADC_MAX_VOLTS, 0U, c36_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_MEDULLA_ADC_OFFSET_COUNTS, 1U,
    c36_b_sf_marshallOut, c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargin, 2U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c36_nargout, 3U, c36_b_sf_marshallOut,
    c36_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c36_b_adc_value, 4U, c36_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c36_b_logicVoltage, 5U,
    c36_sf_marshallOut, c36_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 4);
  c36_MEDULLA_ADC_MAX_VOLTS = 2.7;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 5);
  c36_MEDULLA_ADC_OFFSET_COUNTS = 172.0;
  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, 7);
  for (c36_i4 = 0; c36_i4 < 6; c36_i4++) {
    c36_a[c36_i4] = c36_b_adc_value[c36_i4] - c36_MEDULLA_ADC_OFFSET_COUNTS;
  }

  for (c36_i5 = 0; c36_i5 < 6; c36_i5++) {
    c36_a[c36_i5] *= 0.00065934065934065934;
  }

  for (c36_i6 = 0; c36_i6 < 6; c36_i6++) {
    c36_b_logicVoltage[c36_i6] = c36_a[c36_i6] * 6.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c36_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c36_i7 = 0; c36_i7 < 6; c36_i7++) {
    (*chartInstance->c36_logicVoltage)[c36_i7] = c36_b_logicVoltage[c36_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c36_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c36_i8 = 0; c36_i8 < 6; c36_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c36_logicVoltage)[c36_i8], 1U);
  }
}

static void mdl_start_c36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc36_Walking_ATRIAS(SFc36_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c36_machineNumber, uint32_T
  c36_chartNumber, uint32_T c36_instanceNumber)
{
  (void)c36_machineNumber;
  (void)c36_chartNumber;
  (void)c36_instanceNumber;
}

static const mxArray *c36_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_i9;
  real_T c36_b_inData[6];
  int32_T c36_i10;
  real_T c36_u[6];
  const mxArray *c36_y = NULL;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  for (c36_i9 = 0; c36_i9 < 6; c36_i9++) {
    c36_b_inData[c36_i9] = (*(real_T (*)[6])c36_inData)[c36_i9];
  }

  for (c36_i10 = 0; c36_i10 < 6; c36_i10++) {
    c36_u[c36_i10] = c36_b_inData[c36_i10];
  }

  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static void c36_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_b_logicVoltage, const char_T
  *c36_identifier, real_T c36_y[6])
{
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_logicVoltage),
    &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_logicVoltage);
}

static void c36_b_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId,
  real_T c36_y[6])
{
  real_T c36_dv1[6];
  int32_T c36_i11;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), c36_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c36_i11 = 0; c36_i11 < 6; c36_i11++) {
    c36_y[c36_i11] = c36_dv1[c36_i11];
  }

  sf_mex_destroy(&c36_u);
}

static void c36_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_logicVoltage;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y[6];
  int32_T c36_i12;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_b_logicVoltage = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_logicVoltage),
    &c36_thisId, c36_y);
  sf_mex_destroy(&c36_b_logicVoltage);
  for (c36_i12 = 0; c36_i12 < 6; c36_i12++) {
    (*(real_T (*)[6])c36_outData)[c36_i12] = c36_y[c36_i12];
  }

  sf_mex_destroy(&c36_mxArrayInData);
}

static const mxArray *c36_b_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  real_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(real_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static real_T c36_c_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  real_T c36_y;
  real_T c36_d0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_d0, 1, 0, 0U, 0, 0U, 0);
  c36_y = c36_d0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_nargout;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  real_T c36_y;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_nargout = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_nargout),
    &c36_thisId);
  sf_mex_destroy(&c36_nargout);
  *(real_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

const mxArray *sf_c36_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c36_nameCaptureInfo = NULL;
  c36_nameCaptureInfo = NULL;
  sf_mex_assign(&c36_nameCaptureInfo, sf_mex_createstruct("structure", 2, 9, 1),
                false);
  c36_info_helper(&c36_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c36_nameCaptureInfo);
  return c36_nameCaptureInfo;
}

static void c36_info_helper(const mxArray **c36_info)
{
  const mxArray *c36_rhs0 = NULL;
  const mxArray *c36_lhs0 = NULL;
  const mxArray *c36_rhs1 = NULL;
  const mxArray *c36_lhs1 = NULL;
  const mxArray *c36_rhs2 = NULL;
  const mxArray *c36_lhs2 = NULL;
  const mxArray *c36_rhs3 = NULL;
  const mxArray *c36_lhs3 = NULL;
  const mxArray *c36_rhs4 = NULL;
  const mxArray *c36_lhs4 = NULL;
  const mxArray *c36_rhs5 = NULL;
  const mxArray *c36_lhs5 = NULL;
  const mxArray *c36_rhs6 = NULL;
  const mxArray *c36_lhs6 = NULL;
  const mxArray *c36_rhs7 = NULL;
  const mxArray *c36_lhs7 = NULL;
  const mxArray *c36_rhs8 = NULL;
  const mxArray *c36_lhs8 = NULL;
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c36_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c36_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c36_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c36_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c36_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c36_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c36_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c36_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c36_info, c36_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c36_info, c36_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c36_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c36_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c36_info, sf_mex_duplicatearraysafe(&c36_lhs8), "lhs", "lhs",
                  8);
  sf_mex_destroy(&c36_rhs0);
  sf_mex_destroy(&c36_lhs0);
  sf_mex_destroy(&c36_rhs1);
  sf_mex_destroy(&c36_lhs1);
  sf_mex_destroy(&c36_rhs2);
  sf_mex_destroy(&c36_lhs2);
  sf_mex_destroy(&c36_rhs3);
  sf_mex_destroy(&c36_lhs3);
  sf_mex_destroy(&c36_rhs4);
  sf_mex_destroy(&c36_lhs4);
  sf_mex_destroy(&c36_rhs5);
  sf_mex_destroy(&c36_lhs5);
  sf_mex_destroy(&c36_rhs6);
  sf_mex_destroy(&c36_lhs6);
  sf_mex_destroy(&c36_rhs7);
  sf_mex_destroy(&c36_lhs7);
  sf_mex_destroy(&c36_rhs8);
  sf_mex_destroy(&c36_lhs8);
}

static const mxArray *c36_emlrt_marshallOut(const char * c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", c36_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c36_u)), false);
  return c36_y;
}

static const mxArray *c36_b_emlrt_marshallOut(const uint32_T c36_u)
{
  const mxArray *c36_y = NULL;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 7, 0U, 0U, 0U, 0), false);
  return c36_y;
}

static const mxArray *c36_c_sf_marshallOut(void *chartInstanceVoid, void
  *c36_inData)
{
  const mxArray *c36_mxArrayOutData = NULL;
  int32_T c36_u;
  const mxArray *c36_y = NULL;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_mxArrayOutData = NULL;
  c36_u = *(int32_T *)c36_inData;
  c36_y = NULL;
  sf_mex_assign(&c36_y, sf_mex_create("y", &c36_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c36_mxArrayOutData, c36_y, false);
  return c36_mxArrayOutData;
}

static int32_T c36_d_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  int32_T c36_y;
  int32_T c36_i13;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_i13, 1, 6, 0U, 0, 0U, 0);
  c36_y = c36_i13;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void c36_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c36_mxArrayInData, const char_T *c36_varName, void *c36_outData)
{
  const mxArray *c36_b_sfEvent;
  const char_T *c36_identifier;
  emlrtMsgIdentifier c36_thisId;
  int32_T c36_y;
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c36_b_sfEvent = sf_mex_dup(c36_mxArrayInData);
  c36_identifier = c36_varName;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c36_b_sfEvent),
    &c36_thisId);
  sf_mex_destroy(&c36_b_sfEvent);
  *(int32_T *)c36_outData = c36_y;
  sf_mex_destroy(&c36_mxArrayInData);
}

static uint8_T c36_e_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_b_is_active_c36_Walking_ATRIAS, const
  char_T *c36_identifier)
{
  uint8_T c36_y;
  emlrtMsgIdentifier c36_thisId;
  c36_thisId.fIdentifier = c36_identifier;
  c36_thisId.fParent = NULL;
  c36_y = c36_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c36_b_is_active_c36_Walking_ATRIAS), &c36_thisId);
  sf_mex_destroy(&c36_b_is_active_c36_Walking_ATRIAS);
  return c36_y;
}

static uint8_T c36_f_emlrt_marshallIn(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c36_u, const emlrtMsgIdentifier *c36_parentId)
{
  uint8_T c36_y;
  uint8_T c36_u0;
  (void)chartInstance;
  sf_mex_import(c36_parentId, sf_mex_dup(c36_u), &c36_u0, 1, 3, 0U, 0, 0U, 0);
  c36_y = c36_u0;
  sf_mex_destroy(&c36_u);
  return c36_y;
}

static void init_dsm_address_info(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc36_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c36_adc_value = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c36_logicVoltage = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c36_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1604576149U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1189651982U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(758676633U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(286021486U);
}

mxArray* sf_c36_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c36_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vgH1OJuVPdEocvJupYgJ6B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c36_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c36_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c36_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c36_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c36_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c36_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"logicVoltage\",},{M[8],M[0],T\"is_active_c36_Walking_ATRIAS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c36_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc36_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           36,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Walking_ATRIASMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking_ATRIASMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking_ATRIASMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"adc_value");
          _SFD_SET_DATA_PROPS(1,2,0,1,"logicVoltage");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,247);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c36_sf_marshallOut,(MexInFcnForType)
            c36_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c36_adc_value);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c36_logicVoltage);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking_ATRIASMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "fRYnfhRY9uzxFezFZl0zND";
}

static void sf_opaque_initialize_c36_Walking_ATRIAS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c36_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c36_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c36_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c36_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c36_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c36_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc36_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c36_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c36_Walking_ATRIAS((SFc36_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c36_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      36);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,36,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,36,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,36);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,36,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,36,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,36);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1358814147U));
  ssSetChecksum1(S,(2006134296U));
  ssSetChecksum2(S,(3736841882U));
  ssSetChecksum3(S,(949975737U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c36_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c36_Walking_ATRIAS(SimStruct *S)
{
  SFc36_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc36_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc36_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc36_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c36_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c36_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c36_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c36_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c36_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c36_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c36_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c36_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c36_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c36_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c36_Walking_ATRIAS;
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

void c36_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c36_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c36_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c36_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c36_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
