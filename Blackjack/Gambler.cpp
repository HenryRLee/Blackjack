#include "Gambler.h"

void Gambler::GetOneCard(Card card, int hand)
{
	if (vHand.size() < 1)
	{
		Hand firsthand;
		vHand.push_back(firsthand);
	}

	if (vHand.size() > hand)
	{
		vHand[hand].GetOneCard(card);
	}
}

void Gambler::CleanHands(void)
{
	for (int i=0; i<vHand.size(); i++)
	{
		vHand[i].CleanHands();
	}

	vHand.clear();

	if (vHand.size() < 1)
	{
		Hand firsthand;
		vHand.push_back(firsthand);
	}
}

void Gambler::LeaveTable(void)
{
	this->table = NULL;
}

vector <Hand> Gambler::ShowHand(int iHand)
{
	return vHand;
}

string Gambler::ShowName(void)
{
	return name;
}

Gambler::Gambler(void)
{
	Hand firsthand;
	vHand.push_back(firsthand);
}

Gambler::Gambler(string name)
{
	this->name = name;
}

Gambler::~Gambler(void)
{
}
