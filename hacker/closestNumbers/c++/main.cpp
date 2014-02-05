#include <iostream>
#include "closest.h"

int main()
{
	int array[10];
	array[0] = 12;
	array[1] = 47;
	array[2] = 90;
	array[3] = 25;
	array[4] = -25;
	array[5] = -63;
	array[6] = -9;
	array[7] = 23;
	array[8] = -68;
	array[9] = 21;

	closest(array, 10);	
	return 0;
}
