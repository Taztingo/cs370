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
	
	exclusions["is"] = 1;
	exclusions["the"] = 1;
	exclusions["of"] = 1;
	exclusions["and"] = 1;
	exclusions["a"] = 1;
	exclusions["but"] = 1;
	exclusions["as"] = 1;

	titles.push_back("descent of man");
	titles.push_back("the ascent of man");
	titles.push_back("the old man and the sea");
	titles.push_back("a portrait of the artist as a young man");
	titles.push_back("a man is a man but bubblesort is a dog");
	std::sort(titles.begin(), titles.end());

	for(auto i = 0; i < titles.size(); i++)
	{
		createKwics(exclusions, titles[i], kwics);
	}
	std::make_heap(kwics.begin(), kwics.end());

	for(auto i = kwics.begin(); i != kwics.end(); i++)
	{
		std::cout << i->getTitle() << " / Keyword: " << i->getKeyword() << "\n";
	}

	return 0;
}
