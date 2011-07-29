#include "Minimize/minimize.h"
#include "matrix.h"
#include "mex.h"
#include <string>
using namespace std;
/*matlab_frontend.cpp
 *Jacob Haynes
 *This is the file that will be used to let the Genetic Algorithm
 *be used in matlab. It will take the constraints from the input
 *and convert them to a single dimentional array and get the lenght
 *It will also contain a funtion which can be pointed and will call the
 *matlab function */

//---------------------------------------------------------------------------//
//Global Variables
mxArray *solv; //For Cost Function
int array_size = 0;
int size = 0;
//---------------------------------------------------------------------------//
//
double cost(double array[]);
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
void mexFunction(int nhls, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	size = (int)*mxGetPr(prhs[3]);	
	double constraint[size*2];
    double answer[size];
	mxAssert(nrhs == , "Please input only array and " );
	solv = mxDuplicateArray(prhs[1]); 
     for(int i=0; i < size; i++)
     {
        //data[0] = *mxGetPr(prhs[2]);
        constraint[i*2] = -1000;
        constraint[i*2+1] = 1000;
     }
	optimize(cost, constraint, size, answer);
    plhs[0] = mxCreateDoubleScalar(answer[0]);
    plhs[1] = mxCreateDoubleScalar(answer[1]);
    plhs[2] = mxCreateDoubleScalar(answer[2]);
    return;
}
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
double cost(double array[])
{
	mxArray *costin[1];
    mxArray *out[2];
	out[0] = mxCreateDoubleScalar(array[0]);
	out[1] = solv;
	mexCallMATLAB(1, costin, 2, out, "J_nocomm");
	return *mxGetPr(costin[0]);
}
//---------------------------------------------------------------------------//