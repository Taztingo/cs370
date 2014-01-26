#include "roulette.h"
#include <iostream>
#include <vector>

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
