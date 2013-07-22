#include "SimpleCalculator.h"

double SimpleCalculator::ProbOfGettingCard(int value)
{
	if (value == 10)
		return 4/13;
	else
		return 1/13;
}

bool SimpleCalculator::DealerHits(int iDealerScore, bool bDealerSoft)
{
	if (iDealerScore <= 17)
		return true;
	else
		return false;
}

void SimpleCalculator::GetOneCard(int &iScore, bool &bSoft, int iCardValue)
{
	int iNewScore;

	iNewScore = iScore + iCardValue;

	if (iNewScore > 21)
	{
		if (iCardValue == 11)
		{
			iNewScore -= 10;
		}
		else if (bSoft)
		{
			iNewScore -= 10;
			bSoft = false;
		}
	}
	else if (iCardValue == 11)
	{
		bSoft = true;
	}

	iScore = iNewScore;

}

ProbSet SimpleCalculator::ProbOfHandsDealerTurn(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft)
{
	ProbSet setCurrent;

	if (DealerHits(iDealerScore, bDealerSoft))
	{
		for (int i=2; i<=11; i++)
		{
			ProbSet setNew;

			GetOneCard(iDealerScore, bDealerSoft, i);
			setNew = ProbOfHandsDealerTurn(iPlayerScore, bPlayerSoft,
					iDealerScore, bDealerSoft);

			setCurrent = ProbOfNextCard(setNew, i);
		}
	}
	else
	{
		if (iDealerScore > 21)
			setCurrent.dWin = 1;
		else if (iDealerScore < iPlayerScore)
			setCurrent.dWin = 1;
		else if (iDealerScore == iPlayerScore)
			setCurrent.dPush = 1;
		else if (iDealerScore > iPlayerScore)
			setCurrent.dLose = 1;
	}

	return setCurrent;
}

ProbSet SimpleCalculator::ProbOfHandsPlayerTurn(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft)
{
}

ProbSet SimpleCalculator::ProbOfNextCard(ProbSet setNextCard, int iCardValue)
{
	ProbSet setNew;

	setNew.dWin += ProbOfGettingCard(iCardValue) * setNextCard.dWin;
	setNew.dLose += ProbOfGettingCard(iCardValue) * setNextCard.dLose;
	setNew.dPush += ProbOfGettingCard(iCardValue) * setNextCard.dPush;

	return setNew;
}

void SimpleCalculator::ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
		int iDealerScore, bool bDealerSoft, Table * table)
{
}

SimpleCalculator::SimpleCalculator(void)
{
}

SimpleCalculator::~SimpleCalculator(void)
{
}
