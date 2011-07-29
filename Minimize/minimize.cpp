/*
 * Optimize.cpp
 *
 *  Created on: May 19, 2010
 *      Author: jacob
 */
#include "minimize.h"
using namespace std;

void optimize(double (*cost)(double[]), /*This is the function that will calculate cost*/
		double constraint_in[], /*this vector will constrain the high and low of each constraint in a row
		EX: {2 (1st low), 5 (1st high), 1009 (2nd low), 29009 (2nd high).... */
		int n, /*This is the number of constraints, should be half of the length of th vector */
		double* solution)
{
	//Puts constraint in to Constraint Class
	Constraint constraint[n];
	for(int i = 0; i < n*2; i+=2)
	{
		constraint[i].init(constraint_in[i], constraint_in[i+1]);
	}
	Population population(constraint, n);
	member best_member;
	member temp_member;
	//bool end_condition = true;
	//Initially gets cost and such
	population.get_cost(cost);
	population.reorder(temp_member);
	best_member = temp_member;

	for(int i = 0; i < GENERATIONS; i++)
	{
		population.reproduce(constraint, n);
		population.get_cost(cost);
		population.reorder(temp_member);
		if(temp_member.fitness < best_member.fitness)
		{
			best_member = temp_member;
		}

	}
	for(int i = 0; i < n; i++)
	    {
		solution[i] = best_member.values[i];
	    }
/*	cout << "best_member value: " << best_member.values[0] << endl;
	cout << "best_member fitness: " << best_member.fitness << endl;
	cout << "solution[0]: " <<  solution[0] << endl;
	cout << "solution[1]: " << solution[1] << endl;*/
}

