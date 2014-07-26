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

	return -1;
}

void Dealer::GetHoleCard(Card hole)
{
	this->cardHole = hole;
}

/* Return true if it's Blackjack */
bool Dealer::PeakHoldCard(void)
{
	if (vHand.size() >= 1)
	{
		if ((cardHole.GetValue() + vHand[0].GetScore()) == MaxScore)
			return true;
		else
			return false;
	}

	return false;
}

Card Dealer::ShowHoleCard(void)
{
	GetOneCard(cardHole);

	return cardHole;
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
