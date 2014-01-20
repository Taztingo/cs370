#include "roulette.h"
#include <iostream>

uint roulette(uint people, uint step)
{
	std::list<uint>::iterator iterator;
	for(uint i = people; i > 0; i--)
		gl_myList.push_front(i);

	iterator = gl_myList.begin();
	while(people > 1)
	{
		iterator = advanceList(iterator, step - 1);
		uint replaceValue = *iterator; // Node n's value
		auto tempIterator = advanceList(iterator, step);
		uint newValue = *tempIterator; //Node n + step value

		*iterator = *tempIterator;
		iterator = gl_myList.erase(tempIterator);
			
		//Puts the iterator back to the correct spot, and sets it value
		while(*iterator != newValue && gl_myList.size() > 1)
		{
			iterator = advanceList(iterator, 1);

		}
		
		iterator = advanceList(iterator, 1);
		people--;
	}

	return *iterator;
}
