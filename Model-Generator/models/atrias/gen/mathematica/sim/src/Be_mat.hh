/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:30 GMT-05:00
 */
#include <Eigen/Dense>

#ifdef MATLAB_MEX_FILE
// No need for external definitions
#else // MATLAB_MEX_FILE

namespace symbolic_expression
{
  namespace basic
  {

    void Be_mat_raw(double *p_output1, const double *x);

    inline void Be_mat(Eigen::MatrixXd &p_output1, const Eigen::VectorXd &x)
    {
      // Check
      // - Inputs
      assert_size_matrix(x, 32, 1);

	
      // - Outputs
      assert_size_matrix(p_output1, 16, 6);


      // set zero the matrix
      p_output1.setZero();


      // Call Subroutine with raw data
      Be_mat_raw(p_output1.data(), x.data());
    }
  
  }
}

#endif // MATLAB_MEX_FILE
