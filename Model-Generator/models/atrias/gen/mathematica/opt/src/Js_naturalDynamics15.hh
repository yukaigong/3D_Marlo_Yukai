/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:47 GMT-05:00
 */
#include <Eigen/Dense>

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE

namespace symbolic_expression
{
  namespace basic
  {

    void Js_naturalDynamics15_raw(double *p_output1, const double *var);

    inline void Js_naturalDynamics15(Eigen::MatrixXd &p_output1, const Eigen::VectorXd &var)
    {
      // Check
      // - Inputs
      assert_size_matrix(var, 1, 1);

	
      // - Outputs
      assert_size_matrix(p_output1, 23, 2);


      // set zero the matrix
      p_output1.setZero();


      // Call Subroutine with raw data
      Js_naturalDynamics15_raw(p_output1.data(), var.data());
    }
  
  }
}

#endif // MATLAB_MEX_FILE
