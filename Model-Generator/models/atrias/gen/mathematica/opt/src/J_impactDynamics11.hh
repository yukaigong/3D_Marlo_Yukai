/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:57 GMT-05:00
 */
#include <Eigen/Dense>

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE

namespace symbolic_expression
{
  namespace basic
  {

    void J_impactDynamics11_raw(double *p_output1, const double *var);

    inline void J_impactDynamics11(Eigen::MatrixXd &p_output1, const Eigen::VectorXd &var)
    {
      // Check
      // - Inputs
      assert_size_matrix(var, 48, 1);

	
      // - Outputs
      assert_size_matrix(p_output1, 24, 1);


      // set zero the matrix
      p_output1.setZero();


      // Call Subroutine with raw data
      J_impactDynamics11_raw(p_output1.data(), var.data());
    }
  
  }
}

#endif // MATLAB_MEX_FILE
