#include <iostream>
#include "ClosestPair.h"
#include <vector>

void closest(std::vector<int>& vector, int size)
{
	ClosestPair closestPairs;

	std::sort(vector.begin(), vector.end());
	for(int i = 0; i < size - 1; i++)
	{
		closestPairs.addPair(vector[i], vector[i + 1]);
	}

	//closestPairs.sort();
	std::cout << closestPairs.toString();
}
