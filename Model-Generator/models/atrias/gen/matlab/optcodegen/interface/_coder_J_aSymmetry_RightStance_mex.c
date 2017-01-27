/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_J_aSymmetry_RightStance_mex.c
 *
 * Code generation for function '_coder_J_aSymmetry_RightStance_mex'
 *
 */

/* Include files */
#include "J_aSymmetry_RightStance.h"
#include "_coder_J_aSymmetry_RightStance_mex.h"
#include "J_aSymmetry_RightStance_terminate.h"
#include "_coder_J_aSymmetry_RightStance_api.h"
#include "J_aSymmetry_RightStance_initialize.h"
#include "J_aSymmetry_RightStance_data.h"

/* Function Declarations */
static void c_J_aSymmetry_RightStance_mexFu(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void c_J_aSymmetry_RightStance_mexFu(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        23, "J_aSymmetry_RightStance");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "J_aSymmetry_RightStance");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  J_aSymmetry_RightStance_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  J_aSymmetry_RightStance_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(J_aSymmetry_RightStance_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  J_aSymmetry_RightStance_initialize();

  /* Dispatch the entry-point. */
  c_J_aSymmetry_RightStance_mexFu(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_J_aSymmetry_RightStance_mex.c) */
