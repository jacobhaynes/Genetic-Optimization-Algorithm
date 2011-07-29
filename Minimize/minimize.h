/* Optimize.h
 * Jacob Haynes Created on: May 18, 2010
 * This contains the main function for the algorithm */

#include "include.h"
#include <string>
//#include "member.h"

void optimize(double (*cost)(double[]),double constraint_in[], int n, double* solution);
