#include <string>
#include "Kwic.h"

Kwic::Kwic()
{
	_keyword = "";
	_title = "";
}

Kwic::Kwic(std::string keyword, std::string title)
{
	_keyword = keyword;
	_title = title;
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

bool Kwic::operator<(Kwic& kwic)
{
	if(&kwic != this)
	{
		if(_keyword.compare(kwic.getKeyword()) < 0)
		{
			return true;
		}
		else if(_keyword.compare(kwic.getKeyword()) == 0)
		{
			if(_title.compare(kwic.getTitle()) < 0)
			{
				return true;
			}
		}
	}

	return false;
}
