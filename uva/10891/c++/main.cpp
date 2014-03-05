#include <iostream>
#include <stack>
#include <unordered_map>

std::unordered_map<std::string, int> map;

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
	std::string key;
	for(int i = 0; i < size; i++)
	{
		pick += array[i];
		
		key += std::to_string(array[i]) + " ";
		if(map.find(key) != map.end())
		{
			map[key] = optimalMove(&array[i + 1], size - (i + 1));
		}

		diff = pick - map[key];
		if(diff >= max || !set)
		{
			max = diff;
			set = true;
		}
	}
	
	//For each sub array for right pick
	pick = 0;
	key = "";
	for(int i = 0; i < size - 1; i++)
	{
		pick += array[size - (i + 1)];
		
		key += std::to_string(array[i]) + " ";
		if(map.find(key) == map.end())
		{
			map[key] = optimalMove(&array[0], size - (i + 1));
		}

		diff = pick - map[key];
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
	std::string output;

	while(true)
	{
		int* array;
		std::string allNumbers;
		int size;
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
		
		output += std::to_string(optimalMove(array, size)) + "\n";
		delete[] array;
	}

	std::cout << output;
	
	return 0;
}
