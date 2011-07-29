/*
 * test.cpp
 *
 *  Created on: Apr 20, 2010
 *      Author: jacob
 */
#include "minimize.h"
#include <cmath>
using namespace std;

double cost(double values[])
{
    return values[0] + values[1];
}


int main()
{
	double answer[2] = {-17, -17};
	double constraint[4] = {-1, 1, -1, 1};
	optimize(cost, constraint, 2, answer);
	cout << "answer" << answer[0] << endl;
	return 1;
}

