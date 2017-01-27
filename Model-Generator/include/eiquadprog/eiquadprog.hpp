/**
 * @brief Port of QuadProg++ solver, separating header and definitions
 * @authors Benjamin Stephens, Gael Guennebaud, Angelo Furfaro, Lca Di Gaspero
 * @authors Eric Cousineau, Benjamin Morris, Ryan Sinnet 
 */

#ifndef _EIGEN_QUADSOLVE_HPP_
#define _EIGEN_QUADSOLVE_HPP_

/*
  FILE eiquadprog.h

  NOTE: This is doubly modified. Again. Yep. Ryan Sinnet and Eric Cousineau

  NOTE: this is a modified of uQuadProg++ package, working with Eigen data structures.
  uQuadProg++ is itself a port made by Angelo Furfaro of QuadProg++ originally developed by
  Luca Di Gaspero, working with ublas data structures.

  The quadprog_solve() function implements the algorithm of Goldfarb and Idnani
  for the solution of a (convex) Quadratic Programming problem
  by means of a dual method.

  The problem is in the form:

  min 0.5 * x G x + g0 x
  s.t.
  CE^T x + ce0 = 0
  CI^T x + ci0 >= 0

  The matrix and vectors dimensions are as follows:
  G: n * n
  g0: n

  CE: n * p
  ce0: p

  CI: n * m
  ci0: m

  x: n

  The function will return the cost of the solution written in the x vector or
  std::numeric_limits::infinity() if the problem is infeasible. In the latter case
  the value of the x vector is not correct.

  References: D. Goldfarb, A. Idnani. A numerically stable dual method for solving
  strictly convex quadratic programs. Mathematical Programming 27 (1983) pp. 1-33.

  Notes:
  1. pay attention in setting up the vectors ce0 and ci0.
  If the constraints of your problem are specified in the form
  A^T x = b and C^T x >= d, then you should set ce0 = -b and ci0 = -d.
  2. The matrix G is modified within the function since it is used to compute
  the G = L^T L cholesky factorization for further computations inside the function.
  If you need the original matrix G you should make a copy of it and pass the copy
  to the function.


  The author will be grateful if the researchers using this software will
  acknowledge the contribution of this modified function and of Di Gaspero's
  original version in their research papers.


  LICENSE

  Copyright (2012) Ryan Sinnet, Eric Cousineau, Benjamin Morris
  Copyright (2011) Benjamin Stephens
  Copyright (2010) Gael Guennebaud
  Copyright (2008) Angelo Furfaro
  Copyright (2006) Luca Di Gaspero


  This file is a porting of QuadProg++ routine, originally developed
  by Luca Di Gaspero, exploiting uBlas data structures for vectors and
  matrices instead of native C++ array.

  uquadprog is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  uquadprog is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with uquadprog; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

#ifdef _WIN32
#define __INF numeric_limits<double>::infinity()
#else
#define __INF __builtin_inf()
#endif


#include <stdexcept>
#include <Eigen/Dense>
#include <Eigen/Cholesky>
//#include <boost/lexical_cast.hpp>

//TODO Refactor into a class, storing the variables in that class so stuff doesn't have to be reallocated as much.

namespace eiquadprog
{

  class QPException : public std::runtime_error
  {
  public:
    inline QPException(const std::string &message)
      : std::runtime_error(message)
    { }
  };

  class QPInfeasibleSolutionException : public QPException
  {
  public:
    inline QPInfeasibleSolutionException()
      : QPException("QP solution infeasible")
    { }
  };

  class QPCannotAddConstraintException : public QPException
  {
  public:
    inline QPCannotAddConstraintException()
      : QPException("Cannot add QP constraint")
    { }
  };

  class QPConstraintCheckException : public QPException
  {
  public:
    //	std::string type;
    //	VectorXd x;
    inline QPConstraintCheckException(const std::string &type) //, const VectorXd &x)
      : QPException(type + " constraints violated") //, type(type), x(x)
    { }
    // http://stackoverflow.com/questions/6539009/gcc-exception-specification-of-default-destructor
    //	virtual ~QPConstraintCheckException(); // Could not get it to work
  };

  class QPIterMaxExceededException : public QPException
  {
  public:
    inline QPIterMaxExceededException(unsigned int iterMax)
      : QPException("Max iters exceeded: ")// + boost::lexical_cast<std::string>(iterMax))
    { }
  };

  /* solve_quadprog2 is used when the Cholesky decomposition of the G matrix is precomputed */
  double solve_quadprog2(Eigen::LLT<Eigen::MatrixXd, Eigen::Lower> &chol, const double c1, const Eigen::VectorXd &g0,
			 const Eigen::MatrixXd &CE, const Eigen::VectorXd &ce0,
			 const Eigen::MatrixXd &CI, const Eigen::VectorXd &ci0,
			 Eigen::VectorXd &x, const double eqTolerance, const unsigned int iterMax, unsigned int *iterOut = NULL);

  /* solve_quadprog is used for on-demand QP solving */
  double solve_quadprog(const Eigen::MatrixXd &G, const Eigen::VectorXd &g0,
			const Eigen::MatrixXd &CE, const Eigen::VectorXd &ce0,
			const Eigen::MatrixXd &CI, const Eigen::VectorXd &ci0,
			Eigen::VectorXd &x, const double eqTolerance, const unsigned int iterMax, unsigned int *iterOut = NULL);

}

#endif