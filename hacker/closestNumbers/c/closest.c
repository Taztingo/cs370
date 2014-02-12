#include <stdio.h>
#include <stdlib.h>
#include "closest.h"

void closest(int* array, int size)
{
	int distance = 0;
	int minDistance = -1;
	int newArray[size];
	int newArraySize = 0;
	int i = 0;
	int index = 0;

	qsort(array, size, sizeof(array[0]), compare);
	for(i = 0; i < size - 1; i++)
	{
		distance = array[i + 1] - array[i];
		if(distance < minDistance || minDistance == -1)
		{
			minDistance = distance;
			index = 0;
			newArray[index] = array[i];
			newArray[index + 1] = array[i + 1];
			newArraySize = 2;
			index += 2;
		}
		else if(distance == minDistance)
		{
			newArray[index] = array[i];
			newArray[index + 1] = array[i+1];
			newArraySize += 2;
			index += 2;
		}
	}

	printf("\n");
	for(i = 0; i < newArraySize; i++)
	{
		if(i != newArraySize - 1)
		{
			printf("%d ", newArray[i]);
		}
		else
		{
			printf("%d", newArray[i]);
		}
	}

}
