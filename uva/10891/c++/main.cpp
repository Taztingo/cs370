#include <iostream>

int optimalMove(int* array, int size)
{
	int max = 0;
	int pick = 0;
	int diff;
	bool set = false;

	//Base Case
	if(size == 0)
	{
		return max;
	}
	
	//For each sub array for left pick
	for(int i = 0; i < size; i++)
	{
		pick += array[i];
		diff = pick - optimalMove(&array[i + 1], size - (i + 1));
		if(diff >= max || !set)
		{
			max = diff;
			set = true;
		}
	}
	
	//For each sub array for right pick
	pick = 0;
	for(int i = 0; i < size - 1; i++)
	{
		pick += array[size - (i + 1)];
		diff = pick - optimalMove(&array[0], size - (i + 1));
		if(diff >= max || !set)
		{
			max = diff;
			set = true;
		}
	}

	return max;
}

int main()
{
	int size = 9;
	int array[size];
	array[0] = -823;
	array[1] = 912;
	array[2] = -345;
	array[3] = 100000;
	array[4] = 867;
	array[5] = -222;
	array[6] = -991;
	array[7] = -3;
	array[8] = -40000;
	std::cout << "Max distance: " << optimalMove(array, size) << std::endl;
	return 0;
}
