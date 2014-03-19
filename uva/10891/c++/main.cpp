#include <iostream>
#include <unordered_map>
#include <map>

std::unordered_map<std::string, int> map;

int optimalMove(int* array, int size, int start)
{
	std::string key;
	int max = 0;
	int pick = 0;
	int diff = 0;
	bool set = false;

	//Subarray name
	key = std::to_string(start) + " " + std::to_string(size);

	//Nothing left, or key was found
	if(size == 0 || map.find(key) != map.end())
	{
		return map[key];
	}
	
	//For each sub array from left pick
	for(int i = 0; i < size; i++)
	{
		pick += array[i];
		diff = pick - optimalMove(&array[i + 1], size - (i + 1), start+i+1);

		if(diff >= max || !set)
		{
			max = diff;
			set = true;
		}
	}
	
	//For each sub array from right pick
	pick = 0;
	for(int i = 0; i < size - 1; i++)
	{
		pick += array[size - (i + 1)];
		diff = pick - optimalMove(&array[0], size - (i + 1), start);

		if(diff >= max || !set)
		{
			max = diff;
			set = true;
		}
	}

	map[key] = max;
	return max;
}

int main()
{
	std::string output;

	while(true)
	{
		std::string allNumbers;
		int* array;
		int size;

		//Grab size from input
		std::cin >> size >> std::ws;
		if(size <= 0)
		{
			break;
		}
		array = new int[size];

		//Grab actual input
		for(int i = 0; i < size; i++)
		{
			std::cin >> array[i];
		}
	
		//Append output
		output += std::to_string(optimalMove(array, size, 0)) + "\n";
		
		//Reset map, and array
		map.clear();
		delete[] array;
	}

	std::cout << output;
	
	return 0;
}
