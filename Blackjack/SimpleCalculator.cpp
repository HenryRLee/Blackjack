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

double SimpleCalculator::CalEdge(ProbSet pb)
{
	double edge;

	edge = pb.dWin - pb.dLose;

	return edge;
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
			hand.bSoft = false;
		}
	}
	else if (iCardValue == 11)
	{
		hand.bSoft = true;
	}

	hand.iScore = iNewScore;

	return hand;
}

ProbSet SimpleCalculator::ProbOfHandsDealerTurn(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbCurrent;

	pbCurrent.dWin = 0;
	pbCurrent.dLose = 0;
	pbCurrent.dPush = 0;

	if (DealerHits(handDealer))
	{
		for (int i=2; i<=11; i++)
		{
			ProbSet pbNew;
			HandScore handCurrent;

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
		HandScore handDealer, int action)
{
	ProbSet pbHit;
	ProbSet pbStand;

	/* Bust */
	if (handPlayer.iScore > 21)
	{
		pbStand.dWin = 0;
		pbStand.dLose = 1;
		pbStand.dPush = 0;

		return pbStand;
	}

	/* Hit */
	if ((handPlayer.iScore < 21) && (action != STAND))
	{
		pbHit.dWin = 0;
		pbHit.dLose = 0;
		pbHit.dPush = 0;

		for (int i=2; i<=11; i++)
		{
			ProbSet pbNew;
			HandScore handCurrent;

			handCurrent = GetOneCard(handPlayer, i);
			pbNew = ProbOfHandsPlayerTurn(handCurrent, handDealer);

			pbHit = ProbAfterGettingCard(pbHit, pbNew, i);
		}
	}
	/* Hit */

	/* Stand */
	if (action != HIT)
	{
		pbStand = ProbOfHandsDealerTurn(handPlayer, handDealer);
	}
	/* Stand */

	if (action == NONE)
	{
		if (CalEdge(pbHit) > CalEdge(pbStand))
			return pbHit;
		else
			return pbStand;
	}
	else if (action == HIT)
	{
		return pbHit;
	}
	else if (action == STAND)
	{
		return pbStand;
	}
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
	ProbSet pbHit;
	ProbSet pbStand;
	HandScore handPlayer;
	HandScore handDealer;

	handPlayer.iScore = iPlayerScore;
	handPlayer.bSoft = bPlayerSoft;
	handDealer.iScore = iDealerScore;
	handDealer.bSoft = bDealerSoft;

	pbHit = ProbOfHandsPlayerTurn(handPlayer, handDealer, HIT);
	pbStand = ProbOfHandsPlayerTurn(handPlayer, handDealer, STAND);

	cout << fixed;
	cout << "Hit: " << endl;
	cout << "Win " << pbHit.dWin << endl;
	cout << "Lose " << pbHit.dLose << endl;
	cout << "Push " << pbHit.dPush << endl;
	cout << "Edge " << CalEdge(pbHit) << endl;
	cout << endl;

	cout << "Stand: " << endl;
	cout << "Win " << pbStand.dWin << endl;
	cout << "Lose " << pbStand.dLose << endl;
	cout << "Push " << pbStand.dPush << endl;
	cout << "Edge " << CalEdge(pbStand) << endl;
	cout << endl;
}

SimpleCalculator::SimpleCalculator(void)
{
}

SimpleCalculator::~SimpleCalculator(void)
{
}
