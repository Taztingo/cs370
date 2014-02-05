#include <iostream>
#include "ClosestPair.h"

void closest(int* array, int size)
{
	ClosestPair closestPairs;

	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			closestPairs.addPair(array[i], array[j]);
		}
	}

	std::cout << closestPairs.toString() << "\n";
}

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
