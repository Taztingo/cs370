#include <string>
#include "Kwic.h"

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
