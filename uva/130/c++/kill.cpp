#include "roulette.h"

uint kill(std::list<uint>::iterator iterator, uint step)
{
	for(uint i = 0; i < step; i++)
	{
		iterator++;
		if(iterator == gl_myList.end())
			iterator = gl_myList.begin();
	}

	return *iterator;
}
