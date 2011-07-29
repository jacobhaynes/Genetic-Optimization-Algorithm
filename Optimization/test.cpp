/*
 * test.cpp
 *
 *  Created on: Apr 20, 2010
 *      Author: jacob
 */
#include "optimize.h"
#include <cmath>
using namespace std;

double cost(double values[])
{
    return values[0] - values[1]*values[1] + values[1];
}


int main()
{
	for(int i = 0; i < 20; i++)
	{
	double answer[2]  = {-17, -17};
	double constraint[4] = {0, 1, 0, 1};
	optimize(cost, constraint, 2, answer);
	cout << "Answer " << i << ": " << answer[0] << endl;
	}
	return 1;
}

