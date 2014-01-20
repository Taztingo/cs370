#ifndef TEST_H_
	#define TEST_H_

	#include <list>
	
	typedef unsigned int uint;
	static std::list<uint> gl_myList;
	uint roulette(uint people, uint step);
	uint kill(std::list<uint>::iterator iter, uint step);
#endif
