#ifndef CLOSEST_H_
	#define CLOSEST_H_

	#include <vector>
	#include <utility>

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

	void addPair(int number1, int number2)
	{
	}

	long getDistance(int number1, int number2)
	{
		return 0;
	}
#endif
