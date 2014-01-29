#include <iostream>
#include <vector>
typedef unsigned int uint;

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

int main()
{	
	std::vector<uint> vectorInput;
	uint people;
	uint step;
	
	while(true)
	{
		std::cin >> people >> step;
		vectorInput.push_back(people);
		vectorInput.push_back(step);
		
		if(people == 0 && step == 0)
		{
			for(uint outputCounter = 0; outputCounter < vectorInput.size() - 2; outputCounter += 2)
			{
				std::cout << roulette(vectorInput[outputCounter], vectorInput[outputCounter + 1]) << "\n";
			}
			break;
		}
	}
	return 0;
}
