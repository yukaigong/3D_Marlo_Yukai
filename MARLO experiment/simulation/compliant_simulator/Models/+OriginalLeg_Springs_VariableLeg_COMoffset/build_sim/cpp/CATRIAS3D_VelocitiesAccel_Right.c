/* ATRIAS3D_VELOCITIESACCEL_RIGHT 
 * Generated by writeOptimizedFunctions (17 Oct 2016 14:01:38)
 */

#include <mex.h>
#include "ATRIAS3D_VelocitiesAccel_Right.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	double * q ;
	double * dq ;
	double * extra_vars ;
	double *vcm ;
	double (*J_cm)[][3] ;
	double (*dJ_cm)[][3] ;
	double *v0T ;
	double *vHL ;
	double *vHR ;
	double *v0 ;

	/* Check for proper number of arguments. */
	if(nlhs!=7) mexErrMsgTxt("MEX function ATRIAS3D_VelocitiesAccel_Right expects 7 output arguments.");
	if(nrhs!=3) mexErrMsgTxt("MEX function ATRIAS3D_VelocitiesAccel_Right expects 3 input arguments.");

	/* Process Inputs */
	if(!(mxGetM(prhs[0])==13 && mxGetN(prhs[0])==1) && !(mxGetM(prhs[0])==1 && mxGetN(prhs[0])==13) )
		mexErrMsgTxt("Incorrect dimensions for input #1 - Should be a vector of length 13") ;
	q = mxGetPr(prhs[0]) ;

	if(!(mxGetM(prhs[1])==13 && mxGetN(prhs[1])==1) && !(mxGetM(prhs[1])==1 && mxGetN(prhs[1])==13) )
		mexErrMsgTxt("Incorrect dimensions for input #2 - Should be a vector of length 13") ;
	dq = mxGetPr(prhs[1]) ;

	if(!(mxGetM(prhs[2])==4 && mxGetN(prhs[2])==1) && !(mxGetM(prhs[2])==1 && mxGetN(prhs[2])==4) )
		mexErrMsgTxt("Incorrect dimensions for input #3 - Should be a vector of length 4") ;
	extra_vars = mxGetPr(prhs[2]) ;


	/* Define Output variables */
	plhs[0] = mxCreateDoubleMatrix(3,1, mxREAL);
	vcm = mxGetPr(plhs[0]) ;
	plhs[1] = mxCreateDoubleMatrix(3,13, mxREAL);
	J_cm = (double (*)[][3]) mxGetPr(plhs[1]) ;
	plhs[2] = mxCreateDoubleMatrix(3,13, mxREAL);
	dJ_cm = (double (*)[][3]) mxGetPr(plhs[2]) ;
	plhs[3] = mxCreateDoubleMatrix(3,1, mxREAL);
	v0T = mxGetPr(plhs[3]) ;
	plhs[4] = mxCreateDoubleMatrix(3,1, mxREAL);
	vHL = mxGetPr(plhs[4]) ;
	plhs[5] = mxCreateDoubleMatrix(3,1, mxREAL);
	vHR = mxGetPr(plhs[5]) ;
	plhs[6] = mxCreateDoubleMatrix(3,1, mxREAL);
	v0 = mxGetPr(plhs[6]) ;

	/* Invoke function */
	ATRIAS3D_VelocitiesAccel_Right(q, dq, extra_vars, vcm, *J_cm, *dJ_cm, v0T, vHL, vHR, v0) ;
}
