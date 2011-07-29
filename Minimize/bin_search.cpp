/* bin_search.cpp
 * Jacob Haynes jacob.haynes@colorado.edu
 * Created On: May 19th 2010 for RECUV
 * This is an algorithm for find a location based on a number in a double array
 * This requires a sorted array going from low to high*/

#include "bin_search.h"
using namespace std;
//---------------------------------------------------------------------------//
int binary_search(double array[], int n, double value)
{/* bin_search.cpp
 * Jacob Haynes jacob.haynes@colorado.edu
 * May 19th 2010
 * This is an algorithm for find a location based on a number in a double array
 * This requires a sorted array going from low to high*/
    int high = n; //highest possible position
    int low = 0; //lowest possible position
    int mid = (high + low) /2; //middle position in array

    //go while the mid is less than the value or one below mid is greater than the value
    // stop if high and low have a difference of 1
    while((array[mid] <= value || array[mid - 1] > value) && (high - low) > 1)
	{
	    mid = (high + low)/2; //set mid to the midpoint
	    if(array[mid] < value) low = mid + 1; //set low if the guess was to low
	    else high = mid - 1; //set high if the guess was to high
	}
    return n - mid;
}
//---------------------------------------------------------------------------//
