#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::map<std::string, int> exclusions;
	std::vector<std::string> titles;

	exclusions["is"] = 1;
	exclusions["the"] = 1;
	exclusions["of"] = 1;
	exclusions["and"] = 1;
	exclusions["a"] = 1;
	exclusions["but"] = 1;
	exclusions["as"] = 1;

	titles.push_back("Descent of Man");
	titles.push_back("The Ascent of Man");
	titles.push_back("The Old Man and The Sea");
	titles.push_back("A Portrait of the Artist As a Young Man");
	titles.push_back("A Man is a Man but Bubblesort IS A DOG");
	std::sort(titles.begin(), titles.end());

	for(auto i = titles.begin(); i != titles.end(); i++)
	{
		std::cout << *i << "\n";
	}

	return 0;
}
