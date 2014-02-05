#ifndef CLOSEST_H_
	#define CLOSEST_H_

	#include <vector>
	#include <utility>
	#include <cmath>

	class ClosestPair
	{
			private:
				long _distance;
				std::vector<int> _list;
				void clear();
				long getDistance(int number1, int number2);
			
			public:
				ClosestPair();
				~ClosestPair();
				void addPair(int number1, int number2);
	};

	ClosestPair::ClosestPair()
	{
	}

	ClosestPair::~ClosestPair()
	{
	}

	void ClosestPair::clear()
	{
	}

	void ClosestPair::addPair(int number1, int number2)
	{
		long distance = getDistance(number1, number2);

		if(distance < _distance)
		{
			clear();
			_distance = distance;

			//case 1
		}
		else if(distance == _distance)
		{
			//case 2
		}
	}

	inline long ClosestPair::getDistance(int number1, int number2)
	{
		return std::abs(number1 - number2);
	}
#endif
