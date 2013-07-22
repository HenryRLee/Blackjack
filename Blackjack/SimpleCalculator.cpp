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
	ProbSet setCurrent;
	HandScore handCurrent;

	setCurrent.dWin = 0;
	setCurrent.dLose = 0;
	setCurrent.dPush = 0;

	if (DealerHits(handDealer))
	{
		for (int i=2; i<=11; i++)
		{
			ProbSet setNew;

			handCurrent = GetOneCard(handDealer, i);
			setNew = ProbOfHandsDealerTurn(handPlayer, handCurrent);

			setCurrent = ProbAfterGettingCard(setCurrent, setNew, i);
		}
	}
	else
	{
		if (handDealer.iScore > 21)
			setCurrent.dWin = 1;
		else if (handDealer.iScore < handPlayer.iScore)
			setCurrent.dWin = 1;
		else if (handDealer.iScore == handPlayer.iScore)
			setCurrent.dPush = 1;
		else if (handDealer.iScore > handPlayer.iScore)
			setCurrent.dLose = 1;
	}

	return setCurrent;
}

ProbSet SimpleCalculator::ProbOfHandsPlayerTurn(HandScore handPlayer, 
		HandScore handDealer)
{
}

ProbSet SimpleCalculator::ProbAfterGettingCard(ProbSet setCurrent, 
		ProbSet setNextCard, int iCardValue)
{
	setCurrent.dWin += ProbOfGettingCard(iCardValue) * setNextCard.dWin;
	setCurrent.dLose += ProbOfGettingCard(iCardValue) * setNextCard.dLose;
	setCurrent.dPush += ProbOfGettingCard(iCardValue) * setNextCard.dPush;

	return setCurrent;
}

void SimpleCalculator::ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
		int iDealerScore, bool bDealerSoft, Table * table)
{
	ProbSet setCurrent;
	HandScore handPlayer;
	HandScore handDealer;

	handPlayer.iScore = iPlayerScore;
	handPlayer.bSoft = bPlayerSoft;
	handDealer.iScore = iDealerScore;
	handDealer.bSoft = bDealerSoft;

	setCurrent = ProbOfHandsDealerTurn(handPlayer, handDealer);

	cout << fixed;
	cout << "Win " << setCurrent.dWin << endl;
	cout << "Lose " << setCurrent.dLose << endl;
	cout << "Push " << setCurrent.dPush << endl;
}

SimpleCalculator::SimpleCalculator(void)
{
}

SimpleCalculator::~SimpleCalculator(void)
{
}
