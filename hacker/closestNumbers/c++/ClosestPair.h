#ifndef CLOSEST_PAIR_H_
	#define CLOSEST_PAIR_H_

	#include <vector>
	#include <utility>
	#include <cmath>
	#include <string>
	#include <algorithm>

	class ClosestPair
	{
			private:
				long _distance;
				const char UNSET = -1;
				std::vector<int> _list;
				long getDistance(const int number1, const int number2) const;
			
			public:
				ClosestPair();
				~ClosestPair();
				void addPair(const int number1, const int number2);
				const std::vector<int>& getList() const;
				const std::string toString() const;
				void sort();

	};

	ClosestPair::ClosestPair()
	{
		_distance = UNSET;
	}

	ClosestPair::~ClosestPair()
	{
	}

	void ClosestPair::addPair(const int number1, const int number2)
	{
		long distance = getDistance(number1, number2);

		if(distance < _distance || _distance == UNSET)
		{
			_list.clear();
			_distance = distance;
			_list.push_back(number1);
			_list.push_back(number2);
		}
		else if(distance == _distance)
		{
			_list.push_back(number1);
			_list.push_back(number2);
		}
	}

	inline long ClosestPair::getDistance(const int number1, const int number2) const
	{
		return std::abs(number1 - number2);
	}


	const std::vector<int>& ClosestPair::getList() const
	{
		return _list;
	}
	
	const std::string ClosestPair::toString() const
	{
		std::string allPairs;

		for(auto iterator = _list.begin(); iterator != _list.end(); iterator++)
		{
			allPairs += std::to_string(*iterator);
			allPairs += " ";
		}

		if(allPairs.size() > 0)
		{
			allPairs.substr(0, allPairs.size() - 1);
		}

		return allPairs;
	}

	void ClosestPair::sort()
	{
		std::sort(_list.begin(), _list.end());
	}

#endif
