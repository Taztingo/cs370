#include <iostream>
#include "titles.h"
#include <algorithm>
#include <vector>
#include <unordered_map>
#include "Kwic.h"

int main()
{
	std::unordered_map<std::string, int> exclusions;
	std::vector<std::string> titles;
	std::vector<Kwic> kwics;

	bool enteringExclusions = true;
	char enteredValue[1000];
	while(true)
	{
		std::cin.getline(enteredValue, 1000);
		std::string stringValue(enteredValue);
		if(enteringExclusions)
		{
			if(stringValue == "::")
			{
				enteringExclusions = false;
			}
			else
			{
				exclusions[toLowercase(stringValue)] = 1;
			}
		}
		else
		{
			if(stringValue == "::")
			{
				break;
			}

			titles.push_back(toLowercase(stringValue));
		}
	}

	int id = 0;
	for(auto i = 0; i < titles.size(); i++)
	{
		createKwics(exclusions, titles[i], id, kwics);
		id++;
	}
	std::sort(kwics.begin(), kwics.end());

	for(auto i = kwics.begin(); i != kwics.end(); i++)
	{
		std::cout << i->getTitle() << std::endl;
	}

	return 0;
}
