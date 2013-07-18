#include "Dealer.h"
#include "Table.h"

string Dealer::ShowName(void)
{
	return "[Dealer]" + name;
}

void Dealer::JoinTable(Table * table)
{
	table->AddDealer(this);

	this->table = table;
}

int Dealer::MakeDecision(bool bHitOnSoft17, int iHand)
{
	if (vHand.size() > iHand)
	{
		int score;
		score = vHand[iHand].GetScore();

		if (score < 17)
		{
			return HIT;
		}
		else if (score > 17)
		{
			return STAND;
		}
		else if (score == 17)
		{
			if (!vHand[iHand].IsScoreSoft())
			{
				return STAND;
			}
			else
			{
				if (bHitOnSoft17)
					return HIT;
				else
					return STAND;
			}
		}
	}
	else
	{
		return -1;
	}
}

Dealer::Dealer(void)
{
}

Dealer::Dealer(string name)
{
	this->name = name;
}

Dealer::~Dealer(void)
{
}
