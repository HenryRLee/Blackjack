#include "StreamLog.h"
#include "Hand.h"
#include "Player.h"
#include "Dealer.h"
#include "Card.h"
#include "Table.h"

void StreamLog::Update(Table * table, string text)
{
	if (text.compare("") != 0)
		cout << text << endl;

	if (table != NULL)
	{
		if (table->dealer != NULL)
			Update(table->dealer);

		for (int i=0; i<(table->vPlayer.size()); i++)
		{
			Update(table->vPlayer[i]);
		}
	}
	else
	{
		cout << "Table does not exist" << endl;
	}
}

void StreamLog::Update(Gambler * gambler, string text)
{
	if (gambler != NULL)
	{
		vector <Hand> vHand;
		vHand = gambler->ShowHand();

		cout << gambler->ShowName() << " " << text << endl;

		for (int i=0; i<(vHand.size()); i++)
			Update(vHand[i]);
	}
	else
	{
		cout << "Gambler does not exist" << endl;
	}
}

void StreamLog::Update(Hand hand, string text)
{
	if (text.compare("") != 0)
		cout << text << endl;

	for (int i=0; i<(hand.vCard.size()); i++)
		cout << hand.vCard[i].ShowName() << " ";
	cout << "Score:" << hand.GetScore() << endl;
}

void StreamLog::Update(string text)
{
	if (text.compare("") != 0)
		cout << text << endl;
}

StreamLog::StreamLog(void)
{
}

StreamLog::~StreamLog(void)
{
}
