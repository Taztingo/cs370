#include "roulette.h"
#include <iostream>
#include <vector>

int main()
{	
	std::string input;
	std::vector<uint> vectorInput;
	
	while(true)
	{
		uint people;
		uint step;
		std::cin >> people >> step;		
		if(people > 0 && step > 0)
		{
			std::cout << roulette(people, step) << "\n";
		}
		else
		{
			break;
		}
	}
	return 0;
}
