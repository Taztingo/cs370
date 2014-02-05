#ifndef CLOSEST_H_
	#define CLOSEST_H_

	#include <vector>
	#include <utility>
	#include <cmath>

	class ClosestPair
	{
			private:
				long _distance;
				const char UNSET = -1;
				std::vector< std::pair<int, int> > _list;
				long getDistance(int number1, int number2);
			
			public:
				ClosestPair();
				~ClosestPair();
				void addPair(int number1, int number2);
	};

	ClosestPair::ClosestPair()
	{
		_distance = UNSET;
	}

	ClosestPair::~ClosestPair()
	{
	}

	void ClosestPair::addPair(int number1, int number2)
	{
		long distance = getDistance(number1, number2);

		if(distance < _distance || _distance == UNSET)
		{
			_list.clear();
			_distance = distance;
			std::pair<int, int> newPair(number1, number2);
			_list.push_back(newPair);	
		}
		else if(distance == _distance)
		{
			std::pair<int, int> newPair(number1, number2);
			_list.push_back(newPair);
		}
	}

	inline long ClosestPair::getDistance(int number1, int number2)
	{
		return std::abs(number1 - number2);
	}
#endif
