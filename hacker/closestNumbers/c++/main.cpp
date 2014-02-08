#include <iostream>
#include "closest.h"

int main()
{
	int sizeOfList;
	std::string allNumbers;
	std::cin >> sizeOfList >> std::ws;
	std::getline(std::cin, allNumbers);

	size_t position = 0;
	size_t nextPosition = 0;
	int count = 0;
	int array[sizeOfList];
	do
	{
		position = nextPosition;
		nextPosition = allNumbers.find(' ', position + 1);
		if(position > 0)
			position++;
		array[count] = atoi(allNumbers.substr(position, nextPosition - position).c_str());
		count++;
	}
	while(nextPosition != std::string::npos);

	/*int array[sizeOfList];
	array[0] = 12;
	array[1] = 47;
	array[2] = 90;
	array[3] = 25;
	array[4] = -25;
	array[5] = -63;
	array[6] = -9;
	array[7] = 23;
	array[8] = -68;
	array[9] = 21;*/

	closest(array, sizeOfList);
	return 0;
}
