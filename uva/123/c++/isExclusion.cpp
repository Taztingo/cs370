#include "titles.h"
#include <string>
#include <unordered_map>

bool isExclusion(const std::unordered_map<std::string, int>& map, const std::string& word)
{
	return map.find(word) != map.end();
}
