#include "stdafx.h"
#include "Item.h"


Item::Item(std::string name)
	:Name(name)
{
}


Item::~Item()
{
}

std::string Item::GetName()
{
	return Name;
}
