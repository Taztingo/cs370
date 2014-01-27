#include <string>
#include <ctype.h>

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
