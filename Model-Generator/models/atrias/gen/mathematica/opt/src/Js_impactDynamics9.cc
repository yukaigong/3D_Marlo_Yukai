/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:56 GMT-05:00
 */
#include "math2mat.hpp"

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var)
{
  double _NotUsed;
  NULL;
  p_output1[0]=1.;
  p_output1[1]=1.;
  p_output1[2]=1.;
  p_output1[3]=1.;
  p_output1[4]=1.;
  p_output1[5]=1.;
  p_output1[6]=1.;
  p_output1[7]=1.;
  p_output1[8]=1.;
  p_output1[9]=1.;
  p_output1[10]=1.;
  p_output1[11]=1.;
  p_output1[12]=1.;
  p_output1[13]=1.;
  p_output1[14]=1.;
  p_output1[15]=1.;
  p_output1[16]=1.;
  p_output1[17]=1.;
  p_output1[18]=1.;
  p_output1[19]=1.;
  p_output1[20]=1.;
  p_output1[21]=1.;
  p_output1[22]=1.;
  p_output1[23]=1.;
  p_output1[24]=4.;
  p_output1[25]=5.;
  p_output1[26]=6.;
  p_output1[27]=7.;
  p_output1[28]=9.;
  p_output1[29]=11.;
  p_output1[30]=17.;
  p_output1[31]=18.;
  p_output1[32]=19.;
  p_output1[33]=20.;
  p_output1[34]=21.;
  p_output1[35]=22.;
  p_output1[36]=23.;
  p_output1[37]=25.;
  p_output1[38]=27.;
  p_output1[39]=33.;
  p_output1[40]=34.;
  p_output1[41]=35.;
  p_output1[42]=36.;
  p_output1[43]=37.;
  p_output1[44]=38.;
  p_output1[45]=39.;
  p_output1[46]=41.;
  p_output1[47]=43.;
}



#ifdef MATLAB_MEX_FILE

#include "mex.h"
#include "matrix.h"

/*
 * Main function
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  size_t mrows, ncols;

  double *var;
  double *p_output1;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (var).");
    }
  else if( nlhs > 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 1 && ncols == 1) && 
      !(mrows == 1 && ncols == 1))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var is wrong.");
    }

  /*  Assign pointers to each input.  */
  var = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 24, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_impactDynamics9.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_impactDynamics9_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE