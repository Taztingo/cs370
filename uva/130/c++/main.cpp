#include "roulette.h"
#include <iostream>

int main()
{
	uint people = 1000;
	uint step = 2;
	std::cout << "The last person standing is: " << roulette(people, step) << "\n";
	
	return 0;
}
