
#define R_VERSION_

#include "RPDE.hpp"

#include "mesh_objects.hpp"
#include "mesh.hpp"
#include "evaluator.hpp"


extern "C" {

//! This function manages the various option for the solution evaluation.
/*!
	This function is than one called from R code.
	Call's the walking algoritm for efficient point location inside the mesh.

	\param Rmesh an R-object containg the output mesh from Trilibrary
	\param RX an R-vector containing the x coordinates of the points to be evaluated
	\param RY an R-vector containing the y coordinates of the points to be evaluated
	\param Rcoef an R-vector the coeficients of the solution
	\param Rorder an R integer containg the order of the solution
	\param Rfast an R integer 0 for Naive location algorithm, 1 for Walking Algorithm (can miss location for non convex meshes)
*/
SEXP eval_FEM_fd(SEXP Rmesh, SEXP RX, SEXP RY, SEXP Rcoef, SEXP Rorder, SEXP Rfast)
{
	//Declare pointer to access data from C++

    double *X, *Y, *coef;
	int order;
	bool fast;

	int n_coef 	= length(Rcoef);
	int n_X 	= length(RX);

    // Cast all computation parameters
    X 			= REAL(RX);
    Y 			= REAL(RY);
    coef 		= REAL(Rcoef);
    order 		= INTEGER(Rorder)[0];
    fast 		= INTEGER(Rfast)[0];

	std::cout<<"Starting Evaluation"<<std::endl;

    SEXP result;
	PROTECT(result=allocVector(REALSXP, n_X));

    //Set the mesh

    if(order == 1)
    {
		Evaluator<1> evaluator(Rmesh);
		evaluator.eval(X, Y, n_X, coef, order, fast, REAL(result));
	}
	else if(order == 2)
	{
		Evaluator<2> evaluator(Rmesh);
		evaluator.eval(X, Y, n_X, coef, order, fast, REAL(result));
	}
	else
	{
		std::cout<<"Order not implemented"<<std::endl;
	}


	UNPROTECT(1);
    // result list
    return(result);
}

}



