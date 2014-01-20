#ifndef TEST_H_
	#define TEST_H_

	#include <list>
	
	typedef unsigned int uint;
	static std::list<uint> gl_myList;
	uint roulette(uint people, uint step);
	void kill(std::list<uint>::iterator& iterator, uint step);
	std::list<uint>::iterator advanceList(std::list<uint>::iterator start, uint step);
#endif
