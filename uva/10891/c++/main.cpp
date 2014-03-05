#include <iostream>

int optimalMove(int* array, int size)
{
	int max = 0;
	int pick = 0;
	int diff = 0;
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
	while(true)
	{
		int* array;
		int size;
		std::string allNumbers;
		size_t position = 0;
		size_t nextPosition = 0;
		int arrayCounter = 0;

		std::cin >> size >> std::ws;
		if(size <= 0)
		{
			break;
		}
		std::getline(std::cin, allNumbers);
		array = new int[size];

		do
		{
			position = nextPosition;
			nextPosition = allNumbers.find(' ', position + 1);
			if(position > 0)
			{
				position++;
			}
			array[arrayCounter] = atoi(allNumbers.substr(position, nextPosition - position).c_str());
			arrayCounter++;
		}
		while(nextPosition != std::string::npos);
		
		std::cout << optimalMove(array, size) << std::endl;
		delete[] array;
	}
	
	return 0;
}
