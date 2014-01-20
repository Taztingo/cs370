#include "roulette.h"

uint roulette(uint people, uint step)
{
	std::list<uint>::iterator iterator;
	
	for(uint i = people; i > 0; i--)
		gl_myList.push_front(i);

	iterator = gl_myList.begin();

	while(people > 1)
	{
		for(uint i = 0; i < step; i++)
		{
			iterator++;
			if(iterator == gl_myList.end())
				iterator = gl_myList.begin();
			*iterator = kill(iterator, step);
		}
		people--;
	}

	return *iterator;
}
