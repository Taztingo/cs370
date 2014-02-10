#include <iostream>
#include "closest.h"

int main()
{
	int sizeOfList;
	std::string allNumbers;
	std::cin >> sizeOfList >> std::ws;
	std::getline(std::cin, allNumbers);
	std::vector<int> vector;

	size_t position = 0;
	size_t nextPosition = 0;
	do
	{
		position = nextPosition;
		nextPosition = allNumbers.find(' ', position + 1);
		if(position > 0)
			position++;
		vector.push_back(atoi(allNumbers.substr(position, nextPosition - position).c_str()));
	}
	while(nextPosition != std::string::npos);

	closest(vector, sizeOfList);
	return 0;
}
