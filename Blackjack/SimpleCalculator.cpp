#include "SimpleCalculator.h"

double SimpleCalculator::ProbOfGettingCard(int value)
{
	double prob;

	if (value == 10)
		prob = double(4)/double(13);
	else
		prob = double(1)/double(13);

	return prob;
}

bool SimpleCalculator::DealerHits(HandScore hand)
{
	if (hand.iScore < 17)
		return true;
	else
		return false;
}

HandScore SimpleCalculator::GetOneCard(HandScore hand, int iCardValue)
{
	HandScore handCurrent;
	int iNewScore;

	iNewScore = hand.iScore + iCardValue;

	if (iNewScore > 21)
	{
		if (iCardValue == 11)
		{
			iNewScore -= 10;
		}
		else if (hand.bSoft)
		{
			iNewScore -= 10;
			handCurrent.bSoft = false;
		}
	}
	else if (iCardValue == 11)
	{
		handCurrent.bSoft = true;
	}

	handCurrent.iScore = iNewScore;

	return handCurrent;
}

ProbSet SimpleCalculator::ProbOfHandsDealerTurn(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbCurrent;
	HandScore handCurrent;

	pbCurrent.dWin = 0;
	pbCurrent.dLose = 0;
	pbCurrent.dPush = 0;

	if (DealerHits(handDealer))
	{
		for (int i=2; i<=11; i++)
		{
			ProbSet pbNew;

			handCurrent = GetOneCard(handDealer, i);
			pbNew = ProbOfHandsDealerTurn(handPlayer, handCurrent);

			pbCurrent = ProbAfterGettingCard(pbCurrent, pbNew, i);
		}
	}
	else
	{
		if (handDealer.iScore > 21)
			pbCurrent.dWin = 1;
		else if (handDealer.iScore < handPlayer.iScore)
			pbCurrent.dWin = 1;
		else if (handDealer.iScore == handPlayer.iScore)
			pbCurrent.dPush = 1;
		else if (handDealer.iScore > handPlayer.iScore)
			pbCurrent.dLose = 1;
	}

	return pbCurrent;
}

ProbSet SimpleCalculator::ProbOfHandsPlayerTurn(HandScore handPlayer, 
		HandScore handDealer)
{
}

ProbSet SimpleCalculator::ProbAfterGettingCard(ProbSet pbCurrent, 
		ProbSet pbNextCard, int iCardValue)
{
	pbCurrent.dWin += ProbOfGettingCard(iCardValue) * pbNextCard.dWin;
	pbCurrent.dLose += ProbOfGettingCard(iCardValue) * pbNextCard.dLose;
	pbCurrent.dPush += ProbOfGettingCard(iCardValue) * pbNextCard.dPush;

	return pbCurrent;
}

void SimpleCalculator::ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
		int iDealerScore, bool bDealerSoft, Table * table)
{
	ProbSet pbCurrent;
	HandScore handPlayer;
	HandScore handDealer;

	handPlayer.iScore = iPlayerScore;
	handPlayer.bSoft = bPlayerSoft;
	handDealer.iScore = iDealerScore;
	handDealer.bSoft = bDealerSoft;

	pbCurrent = ProbOfHandsDealerTurn(handPlayer, handDealer);

	cout << fixed;
	cout << "Win " << pbCurrent.dWin << endl;
	cout << "Lose " << pbCurrent.dLose << endl;
	cout << "Push " << pbCurrent.dPush << endl;
}

SimpleCalculator::SimpleCalculator(void)
{
}

SimpleCalculator::~SimpleCalculator(void)
{
}
