/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:05 GMT-05:00
 */
#include "math2mat.hpp"

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  t1 = x[11];
  t2 = x[4];
  t3 = Cos(t1);
  t4 = Cos(t2);
  t5 = x[5];
  t6 = Cos(t5);
  t7 = Sin(t1);
  t8 = Sin(t2);
  t9 = x[6];
  t10 = Cos(t9);
  t11 = Sin(t9);
  t12 = Sin(t5);
  t13 = -0.00025*t4*t12;
  t14 = x[0];
  t15 = t3*t4*t6;
  t16 = -1.*t7*t8;
  t17 = t15 + t16;
  t18 = t4*t6*t7;
  t19 = t3*t8;
  t20 = t18 + t19;
  t21 = x[12];
  t22 = Cos(t21);
  t23 = Sin(t21);
  t24 = t10*t4*t6;
  t25 = -1.*t11*t8;
  t26 = t24 + t25;
  t27 = t4*t6*t11;
  t28 = t10*t8;
  t29 = t27 + t28;
  t30 = x[7];
  t31 = Cos(t30);
  t32 = Sin(t30);
  t33 = x[13];
  t34 = Cos(t33);
  t35 = Sin(t33);
  t36 = x[8];
  t37 = Cos(t36);
  t38 = Sin(t36);
  t39 = t23*t20;
  t40 = -1.*t22*t4*t12;
  t41 = t39 + t40;
  t42 = x[14];
  t43 = t22*t20;
  t44 = t4*t23*t12;
  t45 = t43 + t44;
  t46 = Sin(t42);
  t47 = Cos(t42);
  t48 = t32*t29;
  t49 = -1.*t31*t4*t12;
  t50 = t48 + t49;
  t51 = x[9];
  t52 = t31*t29;
  t53 = t4*t32*t12;
  t54 = t52 + t53;
  t55 = Sin(t51);
  t56 = Cos(t51);
  t57 = t35*t20;
  t58 = -1.*t34*t4*t12;
  t59 = t57 + t58;
  t60 = x[15];
  t61 = t34*t20;
  t62 = t4*t35*t12;
  t63 = t61 + t62;
  t64 = Sin(t60);
  t65 = Cos(t60);
  t66 = t38*t29;
  t67 = -1.*t37*t4*t12;
  t68 = t66 + t67;
  t69 = x[10];
  t70 = t37*t29;
  t71 = t4*t38*t12;
  t72 = t70 + t71;
  t73 = Sin(t69);
  t74 = Cos(t69);
  p_output1[0]=0.245484455592049*(t13 + t14 - 0.1834*t17 + 0.00678*t20) + 0.245484455592049*(t13 + t14 + 0.1834*t26 + 0.00678*t29) + 0.0144432421685319*(t14 - 0.1786*t17 - 0.0157*t41 + 0.1822*t45) + 0.0123498801335164*(t14 - 0.1831*t17 + 0.4*t41*t46 + 0.4*t45*(1. - 1.*t47) + 0.0014*(t45*t46 + t41*t47) + 0.5137*(-1.*t41*t46 + t45*t47)) + 0.0144432421685319*(t14 + 0.1786*t26 - 0.0157*t50 + 0.1822*t54) + 0.0123498801335164*(t14 + 0.1831*t26 + 0.4*t50*t55 + 0.4*t54*(1. - 1.*t56) + 0.0014*(t54*t55 + t50*t56) + 0.5137*(-1.*t50*t55 + t54*t56)) + 0.014665004722013*(t14 - 0.1893*t17 + 0.0253*t59 + 0.1435*t63) + 0.0075447061837341*(t14 - 0.18312*t17 + 0.5*t59*t64 + 0.5*t63*(1. - 1.*t65) + 0.00017*(t63*t64 + t59*t65) + 0.65203*(-1.*t59*t64 + t63*t65)) + 0.014665004722013*(t14 + 0.1893*t26 + 0.0253*t68 + 0.1435*t72) + 0.0075447061837341*(t14 + 0.18312*t26 + 0.5*t68*t73 + 0.5*t72*(1. - 1.*t74) + 0.00017*(t72*t73 + t68*t74) + 0.65203*(-1.*t68*t73 + t72*t74)) + 0.411025422400312*(t14 + 0.0018*t12*t4 + 0.4024*t8);
}

static void output2(double *p_output2,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  t1 = x[3];
  t2 = Sin(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t1);
  t6 = Cos(t4);
  t7 = t5*t6;
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = -1.*t2*t8*t9;
  t11 = t7 + t10;
  t12 = Cos(t3);
  t13 = x[11];
  t14 = Cos(t13);
  t15 = Sin(t13);
  t16 = t6*t2*t8;
  t17 = t5*t9;
  t18 = t16 + t17;
  t19 = x[1];
  t20 = 0.00025*t11;
  t21 = x[6];
  t22 = Cos(t21);
  t23 = Sin(t21);
  t24 = t12*t15*t2;
  t25 = t14*t18;
  t26 = t24 + t25;
  t27 = x[12];
  t28 = -1.*t14*t12*t2;
  t29 = t15*t18;
  t30 = t28 + t29;
  t31 = Cos(t27);
  t32 = Sin(t27);
  t33 = x[13];
  t34 = Cos(t33);
  t35 = Sin(t33);
  t36 = t12*t23*t2;
  t37 = t22*t18;
  t38 = t36 + t37;
  t39 = x[7];
  t40 = -1.*t22*t12*t2;
  t41 = t23*t18;
  t42 = t40 + t41;
  t43 = Cos(t39);
  t44 = Sin(t39);
  t45 = x[8];
  t46 = Cos(t45);
  t47 = Sin(t45);
  t48 = -1.*t32*t11;
  t49 = t31*t30;
  t50 = t48 + t49;
  t51 = x[14];
  t52 = t31*t11;
  t53 = t32*t30;
  t54 = t52 + t53;
  t55 = Sin(t51);
  t56 = Cos(t51);
  t57 = -1.*t35*t11;
  t58 = t34*t30;
  t59 = t57 + t58;
  t60 = x[15];
  t61 = t34*t11;
  t62 = t35*t30;
  t63 = t61 + t62;
  t64 = Sin(t60);
  t65 = Cos(t60);
  t66 = -1.*t44*t11;
  t67 = t43*t42;
  t68 = t66 + t67;
  t69 = x[9];
  t70 = t43*t11;
  t71 = t44*t42;
  t72 = t70 + t71;
  t73 = Sin(t69);
  t74 = Cos(t69);
  t75 = -1.*t47*t11;
  t76 = t46*t42;
  t77 = t75 + t76;
  t78 = x[10];
  t79 = t46*t11;
  t80 = t47*t42;
  t81 = t79 + t80;
  t82 = Sin(t78);
  t83 = Cos(t78);
  p_output2[0]=0.411025422400312*(-0.0018*t11 + t19 - 0.4024*t12*t2) + 0.245484455592049*(t19 + t20 - 0.1834*t26 + 0.00678*t30) + 0.245484455592049*(t19 + t20 + 0.1834*t38 + 0.00678*t42) + 0.0144432421685319*(t19 - 0.1786*t26 + 0.1822*t50 - 0.0157*t54) + 0.0123498801335164*(t19 - 0.1831*t26 + 0.4*t54*t55 + 0.4*t50*(1. - 1.*t56) + 0.5137*(-1.*t54*t55 + t50*t56) + 0.0014*(t50*t55 + t54*t56)) + 0.014665004722013*(t19 - 0.1893*t26 + 0.1435*t59 + 0.0253*t63) + 0.0075447061837341*(t19 - 0.18312*t26 + 0.5*t63*t64 + 0.5*t59*(1. - 1.*t65) + 0.65203*(-1.*t63*t64 + t59*t65) + 0.00017*(t59*t64 + t63*t65)) + 0.0144432421685319*(t19 + 0.1786*t38 + 0.1822*t68 - 0.0157*t72) + 0.0123498801335164*(t19 + 0.1831*t38 + 0.4*t72*t73 + 0.4*t68*(1. - 1.*t74) + 0.5137*(-1.*t72*t73 + t68*t74) + 0.0014*(t68*t73 + t72*t74)) + 0.014665004722013*(t19 + 0.1893*t38 + 0.1435*t77 + 0.0253*t81) + 0.0075447061837341*(t19 + 0.18312*t38 + 0.5*t81*t82 + 0.5*t77*(1. - 1.*t83) + 0.65203*(-1.*t81*t82 + t77*t83) + 0.00017*(t77*t82 + t81*t83));
}

static void output3(double *p_output3,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  t1 = x[3];
  t2 = Cos(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t4);
  t6 = Sin(t1);
  t7 = t5*t6;
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = t2*t8*t9;
  t11 = t7 + t10;
  t12 = Cos(t3);
  t13 = x[11];
  t14 = Cos(t13);
  t15 = Sin(t13);
  t16 = -1.*t2*t5*t8;
  t17 = t6*t9;
  t18 = t16 + t17;
  t19 = x[2];
  t20 = 0.00025*t11;
  t21 = x[6];
  t22 = Cos(t21);
  t23 = Sin(t21);
  t24 = -1.*t2*t12*t15;
  t25 = t14*t18;
  t26 = t24 + t25;
  t27 = x[12];
  t28 = t14*t2*t12;
  t29 = t15*t18;
  t30 = t28 + t29;
  t31 = Cos(t27);
  t32 = Sin(t27);
  t33 = x[13];
  t34 = Cos(t33);
  t35 = Sin(t33);
  t36 = -1.*t2*t12*t23;
  t37 = t22*t18;
  t38 = t36 + t37;
  t39 = x[7];
  t40 = t22*t2*t12;
  t41 = t23*t18;
  t42 = t40 + t41;
  t43 = Cos(t39);
  t44 = Sin(t39);
  t45 = x[8];
  t46 = Cos(t45);
  t47 = Sin(t45);
  t48 = -1.*t32*t11;
  t49 = t31*t30;
  t50 = t48 + t49;
  t51 = x[14];
  t52 = t31*t11;
  t53 = t32*t30;
  t54 = t52 + t53;
  t55 = Sin(t51);
  t56 = Cos(t51);
  t57 = -1.*t35*t11;
  t58 = t34*t30;
  t59 = t57 + t58;
  t60 = x[15];
  t61 = t34*t11;
  t62 = t35*t30;
  t63 = t61 + t62;
  t64 = Sin(t60);
  t65 = Cos(t60);
  t66 = -1.*t44*t11;
  t67 = t43*t42;
  t68 = t66 + t67;
  t69 = x[9];
  t70 = t43*t11;
  t71 = t44*t42;
  t72 = t70 + t71;
  t73 = Sin(t69);
  t74 = Cos(t69);
  t75 = -1.*t47*t11;
  t76 = t46*t42;
  t77 = t75 + t76;
  t78 = x[10];
  t79 = t46*t11;
  t80 = t47*t42;
  t81 = t79 + t80;
  t82 = Sin(t78);
  t83 = Cos(t78);
  p_output3[0]=0.411025422400312*(-0.0018*t11 + t19 + 0.4024*t12*t2) + 0.245484455592049*(t19 + t20 - 0.1834*t26 + 0.00678*t30) + 0.245484455592049*(t19 + t20 + 0.1834*t38 + 0.00678*t42) + 0.0144432421685319*(t19 - 0.1786*t26 + 0.1822*t50 - 0.0157*t54) + 0.0123498801335164*(t19 - 0.1831*t26 + 0.4*t54*t55 + 0.4*t50*(1. - 1.*t56) + 0.5137*(-1.*t54*t55 + t50*t56) + 0.0014*(t50*t55 + t54*t56)) + 0.014665004722013*(t19 - 0.1893*t26 + 0.1435*t59 + 0.0253*t63) + 0.0075447061837341*(t19 - 0.18312*t26 + 0.5*t63*t64 + 0.5*t59*(1. - 1.*t65) + 0.65203*(-1.*t63*t64 + t59*t65) + 0.00017*(t59*t64 + t63*t65)) + 0.0144432421685319*(t19 + 0.1786*t38 + 0.1822*t68 - 0.0157*t72) + 0.0123498801335164*(t19 + 0.1831*t38 + 0.4*t72*t73 + 0.4*t68*(1. - 1.*t74) + 0.5137*(-1.*t72*t73 + t68*t74) + 0.0014*(t68*t73 + t72*t74)) + 0.014665004722013*(t19 + 0.1893*t38 + 0.1435*t77 + 0.0253*t81) + 0.0075447061837341*(t19 + 0.18312*t38 + 0.5*t81*t82 + 0.5*t77*(1. - 1.*t83) + 0.65203*(-1.*t81*t82 + t77*t83) + 0.00017*(t77*t82 + t81*t83));
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

  double *x;
  double *p_output1,*p_output2,*p_output3;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (x).");
    }
  else if( nlhs > 3)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 32 && ncols == 1) && 
      !(mrows == 1 && ncols == 32))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "x is wrong.");
    }

  /*  Assign pointers to each input.  */
  x = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 1, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);
  plhs[1] = mxCreateDoubleMatrix((mwSize) 1, (mwSize) 1, mxREAL);
  p_output2 = mxGetPr(plhs[1]);
  plhs[2] = mxCreateDoubleMatrix((mwSize) 1, (mwSize) 1, mxREAL);
  p_output3 = mxGetPr(plhs[2]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);
  output2(p_output2,x);
  output3(p_output3,x);


}

#else // MATLAB_MEX_FILE

#include "pe_com_vec.hh"

namespace symbolic_expression
{
namespace basic
{

void pe_com_vec_raw(double *p_output1, double *p_output2, double *p_output3, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);
  output2(p_output2, x);
  output3(p_output3, x);

}

}
}

#endif // MATLAB_MEX_FILE
