#include "Card.h"

unsigned int Card::GetValue(void)
{
	return value;
}

string Card::GetName(void)
{
	return name;
}

Card::Card(void)
{
}

Card::Card(int id, int value, char name[])
{
	this->id = id;
	this->value = value;
	this->name.assign(name);
}

Card::~Card(void)
{
}
