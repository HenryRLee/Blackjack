#include "Card.h"
#include <string.h>

unsigned int Card::GetValue(void)
{
	return value;
}

Card::Card(void)
{
}

Card::Card(int id, int value, char name[])
{
	this->id = id;
	this->value = value;
	strncpy(this->name, name, sizeof(this->name));
}

Card::~Card(void)
{
}
