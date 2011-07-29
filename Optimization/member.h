/* member.h
 *Jacob Haynes Created on: Apr 20, 2010
 *This is a class that represents each member of the population
 *It has the functions to initialize and randomize the population
 *It also includes a function to call the cost function
 */
#include "include.h"
using namespace std;

#ifndef MEMBER_H_
#define MEMBER_H_

class member
{
public:
	Constraint constraint[];
	//the individual fitness of the member
	double fitness;
	//Where it is in terms of all of the organisms
	//Used for selecting parents
	double fitness_total;
	double values[NUMBER_OF_CONSTRAINTS];

	member();
	//virtual ~member();

	void initialize(Constraint constraint[], int n);
	double get_cost(double (*cost)(double[]));
	void randomize(Constraint constraint[], int n);
};

#endif /* MEMBER_H_ */
