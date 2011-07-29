/*
 * constraints.cpp
 *
 *  Created on: Jun 30, 2010
 *      Author: jacob
 */

#include "constraint.h"

Constraint::Constraint()
{
	// TODO Auto-generated constructor stub

}

//sets up the Constraint
void Constraint::init(double minin, double maxin)
{
min = minin; //minimum the variable can be
max = maxin; //maximum the variable can be
}
//;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~;~//
//checks to see if the variable is within the constraint
bool Constraint::within_constraint(double in)
{
//if greater than max and less than min
return (in > max) && (in < min);
}
