#include "closest.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*char* inputString = (char*) malloc((sizeof(char) * MAX_SIZE_ARRAY * MAX_WORD) + 1);
	int sizeOfArray = atoi(gets(inputString));
	int count = 0;	
	int* array = (int*) malloc(sizeof(int) * MAX_SIZE_ARRAY);
	inputString[MAX_WORD * MAX_SIZE_ARRAY - 1] = ' ';
	inputString[MAX_WORD * MAX_SIZE_ARRAY] = '\0';

	char* nextToken;
	nextToken = strtok(inputString, " ");
	while(nextToken = strtok(inputString, " "))
	{
		array[count] = atoi(nextToken);
		count++;
	}
	
	closest(array, sizeOfArray);*/

	int sizeOfArray = 4;	
	int array[4];
	array[0] = 5;
	array[1] = 4;
	array[2] = 3;
	array[3] = 2;

	closest(array, sizeOfArray);
	return 0;
}
