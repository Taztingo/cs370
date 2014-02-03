#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <ctype.h>

class Kwic
	{
		private:
			std::string _keyword;
			std::string _title;
			uint _priority;

		public:
			Kwic();
			Kwic(std::string keyword, std::string title, int id);
			virtual ~Kwic();
			const std::string& getKeyword() const;
			const std::string& getTitle() const;
			const uint getPriority() const;
			uint getPriority();
			std::string& getKeyword();
			std::string& getTitle();
			bool operator<(const Kwic& kwic) const;
	};

std::string toUppercase(std::string str)
{
	const char* cString = str.c_str();
	char* newStr = new char[str.size() + 1];
	int i;

	for(i = 0; i < str.size(); i++)
	{
		newStr[i] = toupper(cString[i]);
	}
	newStr[i] = '\0';

	std::string lowerString(newStr);
	delete[] newStr;
	return lowerString;
}

std::string toLowercase(std::string str)
{
	const char* cString = str.c_str();
	char* newStr = new char[str.size() + 1];
	int i;

	for(i = 0; i < str.size(); i++)
	{
		newStr[i] = tolower(cString[i]);
	}
	newStr[i] = '\0';

	std::string lowerString(newStr);
	delete[] newStr;
	return lowerString;
}

bool isExclusion(const std::unordered_map<std::string, int>& map, const std::string& word)
{
	return map.find(word) != map.end();
}

void createKwics(const std::unordered_map<std::string, int>& exclusions, const std::string& title, int id, std::vector<Kwic>& kwics)
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
				Kwic kwic(word, titleCopy, id);
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

Kwic::Kwic()
{
	_keyword = "";
	_title = "";
}

Kwic::Kwic(std::string keyword, std::string title, int id)
{
	_keyword = keyword;
	_title = title;
	_priority = id;
}

Kwic::~Kwic()
{

}

std::string& Kwic::getKeyword()
{
	return _keyword;
}

std::string& Kwic::getTitle()
{
	return _title;
}

uint Kwic::getPriority()
{
	return _priority;
}

const uint Kwic::getPriority() const
{
	return _priority;
}

const std::string& Kwic::getKeyword() const
{
	return _keyword;
}

const std::string& Kwic::getTitle() const
{
	return _title;
}

bool Kwic::operator<(const Kwic& kwic) const
{
	if(&kwic != this)
	{
		if(_keyword.compare(kwic.getKeyword()) < 0)
		{
			return true;
		}
		else if(_keyword.compare(kwic.getKeyword()) == 0)
		{
			if(_priority < kwic.getPriority())
			{
				return true;
			}
		}
	}

	return false;
}


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
			else if(stringValue.size() > 0)
			{
				exclusions[toLowercase(stringValue)] = 1;
			}
		}
		else
		{
			if(stringValue.size() == 0)
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
