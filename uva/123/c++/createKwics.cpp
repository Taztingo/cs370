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

	//Gets a non const c string of the String
	for(auto iterator = title.begin(); iterator != title.end(); i++, iterator++)
	{
		titleString[i] = *iterator;
	}
	titleString[i] = '\0';

	int leftPointer = 0;
	int rightPointer = 0;
	while(true)
	{
		//Found a word
		if(titleString[rightPointer] == ' ' || titleString[rightPointer] == '\0')
		{
			//The token in the string
			std::string word = title.substr(leftPointer, rightPointer - leftPointer);
			
			//Finds a word that is not an exclusion
			if(!isExclusion(exclusions, word))
			{
				//Uppercases the word
				std::string titleCopy = title;
				titleCopy.replace(leftPointer, rightPointer - leftPointer, toUppercase(word));
			
				//Creates the kwic
				Kwic kwic(word, titleCopy);
				kwics.push_back(kwic);
			}

			//If it's not the last word reposition pointers
			if(titleString[rightPointer])
			{
				leftPointer = rightPointer + 1;
				rightPointer = rightPointer + 1;
			}
			else
			{
				break;
			}
		}
		else
		{
			rightPointer++;
		}
	}
}
