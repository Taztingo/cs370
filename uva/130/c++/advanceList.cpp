#include "roulette.h"
#include <iostream>

std::list<uint>::iterator advanceList(std::list<uint>::iterator start, uint step)
{
	for(uint i = 0; i < step; i++)
	{
		start++;
		if(*start == 0)
			start++;
		if(start == gl_myList.end())
		{
			start = gl_myList.begin();
		}
	}

	return start;
}
