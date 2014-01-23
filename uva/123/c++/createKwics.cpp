#include "titles.h"
#include "Kwic.h"
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <iostream>

void createKwics(const std::unordered_map<std::string, int>& exclusions, const std::string& title, std::vector<Kwic>& kwics)
{
	char* titleString = new char[title.size() + 1];
	int i = 0;
	for(auto iterator = title.begin(); iterator != title.end(); i++, iterator++)
	{
		titleString[i] = *iterator;
	}
	titleString[i] = '\0';
	
	char* token = strtok(titleString, " ");
	do
	{
		std::string tokenString(token);
		if(!isExclusion(exclusions, tokenString))
		{
			Kwic kwic(token, title);
			kwics.push_back(kwic);
		}
		//free(token);
	}
	while(token = strtok(NULL, " "));

	delete[] titleString;
}
