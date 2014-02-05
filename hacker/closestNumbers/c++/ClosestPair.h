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
			
			public:
				ClosestPair();
				~ClosestPair();
				void addPair(int number1, int number2);
	};
#endif
