#include <string>
#include <kwic.h>

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

std::string& getKeyword()
{
	return _keyword;
}

std::string& getTitle()
{
	return _title;
}

bool operator<(Kwic& kwic)
{
	if(&kwic != this)
	{
		if(_keyword.compare(kwic.getKeyword()) < 0)
		{
			return true;
		}
		else if(_keyword.compare(kwic.getKeyword()) == 0)
		{
			if(title.compare(kwic.getTitle()) < 0)
			{
				return true;
			}
		}
	}

	return false;
}
