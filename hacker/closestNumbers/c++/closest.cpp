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
