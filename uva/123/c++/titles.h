#ifndef TITLES_H_
	#define TITLES_H_

	#include <unordered_map>
	#include <vector>
	#include <string>
	#include "Kwic.h"
	bool isExclusion(const std::unordered_map<std::string, int>& map, const std::string& word);
	void createKwics(const std::unordered_map<std::string, int>& exclusions, const std::string& title, std::vector<Kwic>& kwics);

#endif
