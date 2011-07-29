/*
 * constraints.h
 *
 *  Created on: Jun 30, 2010
 *      Author: jacob
 */

#ifndef CONSTRAINTS_H_
#define CONSTRAINTS_H_

class Constraint
{
public:
	double min; //minimum the variable can be
	double max; //maximum the variable can be
	Constraint();
	//;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
	//sets up the Constraint
	void init(double minin, double maxin);
	//;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
	//checks to see if the variable is within the constraint
	bool within_constraint(double in);
};

#endif /* CONSTRAINTS_H_ */
