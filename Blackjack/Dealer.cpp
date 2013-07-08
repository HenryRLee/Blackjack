#include "Dealer.h"
#include "Table.h"

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
			if (bHitOnSoft17)
			{
				return HIT;
			}
			else
			{
				if (vHand[iHand].iSoftScore > 0)
					return STAND;
				else
					return HIT;
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

Dealer::~Dealer(void)
{
}
