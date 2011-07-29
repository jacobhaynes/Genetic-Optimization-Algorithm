/* Population.h
 * Jacob Haynes Created on: Apr 20, 2010
 * This Class is a representation for the whole population and will
 * contain the functions to initialize the members, to choose the
 * parents and to make the parents reproduce.
 */
#include "include.h"
#ifndef POPULATION_H_
#define POPULATION_H_

class Population {
public:
	double fitness_total[POP_SIZE];
	member members[POP_SIZE];
	Population(Constraint constraints_in[], int n);
	//virtual ~Population();

	void assign_fitness();
	void get_cost(double (*cost)(double[]));
	void reorder(member& greatest);
	void reproduce(Constraint constraints[], int n);
};
#endif /* POPULATION_H_ */
