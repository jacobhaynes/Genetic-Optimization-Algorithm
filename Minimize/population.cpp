/*
 * Population.cpp
 *
 *  Created on: Apr 20, 2010
 *      Author: jacob
 */
#include "population.h"
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
Population::Population(Constraint constraints[], int n)
{
	srand (time(NULL));
	for(int i = 0; i < POP_SIZE; i++)
	{
		members[i].initialize(constraints, n);
	}
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
/*Population::~Population()
{

}*/
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
void Population::assign_fitness()
{
    fitness_total[0] = 0;
    for(int i = 0; i < POP_SIZE; i++)
	{
		members[i].fitness_total = fitness_total[i];
		fitness_total[i] = members[i].fitness + fitness_total[i-1];
	}
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
void Population::get_cost(double (*cost)(double[]))
{
	for(int i = 0; i < POP_SIZE; i++)
	{
		members[i].get_cost(cost);
		if(i == POP_SIZE - 1) return;
	}
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
void Population::reorder(member& greatest)
{
	for(int i = 0; i < POP_SIZE; i++)
	{
		/*for(int c = i + 1; c < POP_SIZE; c++)
		{
			if(members[i].fitness > members[c].fitness)
			{
				member temp = members[i];
				members[i] = members[c];
				members[c] = temp;
			}
		}*/
		if(i == 0) i++;
		greatest = members[0];
		if(greatest.fitness < members[i].fitness)
			greatest = members[i];
	}
	//greatest = members[0];
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;i2c avr atmega32~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
void Population::reproduce(Constraint constraints[], int n)
{
	assign_fitness();
	//old population
	member old_members[POP_SIZE] = members;

	member mother;
	member father;
	//The crossover between father, mother and mutate
	int threshold_1 = MUTATION_RATE/.2, threshold_2 = MUTATION_RATE * 10.;
	//for each member of the population
	for(int i = 0; i < POP_SIZE; i++)
	{
		//Selects parents
		mother = old_members[binary_search(fitness_total, POP_SIZE, rand()%POP_SIZE)];
		father = old_members[binary_search(fitness_total, POP_SIZE, rand()%POP_SIZE)];
		//goes through each trait and selects where it comes from
		for(int c = 0; c < n; c++)
		{
			int rnd = rand() % 10;
			if(rnd <= threshold_1)
			{
				//gets trait from mother
			    members[i].values[c] = mother.values[c];
			}
			else if(rnd <= threshold_2)
			{
			    //gets trait from father
			    members[i].values[c] = father.values[c];
			}
			else
			{
			    //mutates (completely random)
				members[i].values[c] = (rand()/double(RAND_MAX))*(constraints[c].max -
				constraints[c].min) +
				constraints[c].min;
			}
			if(!constraints[c].within_constraint(members[i].values[c]))
			{
			    members[i].values[c] = (rand()/double(RAND_MAX))*(constraints[c].max -
				constraints[c].min) +
				constraints[c].min;
			}
		}
	}
}
//~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//




