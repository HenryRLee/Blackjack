#include "Dealer.h"
#include "Table.h"

void Dealer::JoinTable(Table * table)
{
	table->AddDealer(this);

	this->table = table;
}

Dealer::Dealer(void)
{
}

Dealer::~Dealer(void)
{
}
