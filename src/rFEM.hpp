#ifndef RFEM_HPP_
#define RFEM_HPP_

// Insert principal libraries
#ifdef R_VERSION_
#include <R.h>
#include <Rdefines.h>
#include <Rinternals.h> 
#endif

#include <stdint.h>

#include <cstdlib>
//#include <iomanip>
#include <limits>
#include <vector>

#include "Eigen/Eigen/Sparse"
#include "Eigen/Eigen/Dense"

typedef double Real;
typedef int UInt;

typedef Eigen::Matrix<Real,Eigen::Dynamic,Eigen::Dynamic> MatrixXr;
typedef Eigen::Matrix<Real,Eigen::Dynamic,1> VectorXr;
typedef Eigen::SparseMatrix<Real> SpMat;
typedef Eigen::SparseVector<Real> SpVec;
typedef Eigen::Triplet<Real> coeff;

#endif /* RFEM_HPP_ */
