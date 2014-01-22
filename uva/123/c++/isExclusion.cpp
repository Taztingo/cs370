#include "titles.h"
#include <string>
#include <map>

bool isExclusion(const std::map<std::string, int>& map, const std::string& word)
{
	return map.find(word) != map.end();
}
