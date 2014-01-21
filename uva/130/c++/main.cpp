#include "roulette.h"
#include <iostream>

int main()
{
	uint people = 5;
	uint step = 3;
	std::cout << "The last person standing is: " << roulette(people, step) << "\n";	
	return 0;
}
