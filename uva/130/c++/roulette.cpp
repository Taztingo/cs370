#include "roulette.h"
#include <vector>

uint roulette(uint people, uint step)
{
	std::vector<uint> array;
	uint position = 0;
	uint digger = 0;
	
	//Add everyone to circle
	for(uint i = 1; i <= people; i++)
		array.push_back(i);
	
	//Loop until one person is left
	while(array.size() > 1)
	{
		//Find next person to kill
		if(people == array.size())
			position = (position + step - 1) % array.size();
		else
			position = (position + step) % array.size();

		//Dig the grave
		digger = (position + step) % array.size();	
		array[position] = array[digger];
		array.erase(array.begin() + digger);

		//Fix index out of bounds when person
		if(position == array.size())
			position--;
		if(digger == 0)
			position--;
	}

	return array[0];
}
