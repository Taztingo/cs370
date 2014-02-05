#ifndef CLOSEST_H_
	#define CLOSEST_H_

	#include <vector>
	#include <utility>
	#include <cmath>
	#include <string>
	#include <cstdlib>
	#include <iostream>

	class ClosestPair
	{
			private:
				long _distance;
				const char UNSET = -1;
				std::vector< std::pair<int, int> > _list;
				long getDistance(const int number1, const int number2) const;
			
			public:
				ClosestPair();
				~ClosestPair();
				void addPair(const int number1, const int number2);
				const std::vector< std::pair<int, int> >& getList() const;
				const std::string toString() const;

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
			std::pair<int, int> newPair(number1, number2);
			_list.push_back(newPair);	
		}
		else if(distance == _distance)
		{
			std::pair<int, int> newPair(number1, number2);
			_list.push_back(newPair);
		}
	}

	inline long ClosestPair::getDistance(const int number1, const int number2) const
	{
		return std::abs(number1 - number2);
	}


	const std::vector< std::pair<int, int> >& ClosestPair::getList() const
	{
		return _list;
	}
	
	const std::string ClosestPair::toString() const
	{
		std::string allPairs;

		for(auto iterator = _list.begin(); iterator != _list.end(); iterator++)
		{
			allPairs += std::to_string(iterator->first);
			allPairs += " ";
			allPairs += std::to_string(iterator->second);
			allPairs += " ";
		}

		if(allPairs.size() > 0)
		{
			allPairs.substr(0, allPairs.size() - 1);
		}

		return allPairs;
	}

#endif
