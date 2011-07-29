/*member.cpp
 * Jacob Haynes Created on: Apr 20, 2010
 *This is a class that represents each member of the population
 *It has the functions to intialize and radomize the population
 *It also includes a funciton to call the cost funciton
 */

#include "include.h"
using namespace std;
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
member::member()
{

}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
/*member::~member()
{

//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~
}*/
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
/*sends everything to the cost function*/
double member::get_cost(double (*cost)(double[]))
{
	fitness = cost(values);
	return fitness;
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
void member::initialize(Constraint constraint[], int n)
{
	randomize(constraint, n);
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
/* this funciton will set all values to a random number within the constraint*/
void member::randomize(Constraint constraint[], int n)
{
	for(int i = 0; i < n; i++)
	{
		values[i] = (rand()/double(RAND_MAX))*(constraint[i].max -
			constraint[i].min) +
			constraint[i].min;
	}
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
