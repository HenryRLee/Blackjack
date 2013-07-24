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
	if ((handPlayer.iScore < 21) && ((action == HIT) || (action == NONE)))
	{
		ProbSet pbNew;

		pbHit.dWin = 0;
		pbHit.dLose = 0;
		pbHit.dPush = 0;

		for (int i=2; i<=11; i++)
		{
			HandScore handCurrent;

			handCurrent = GetOneCard(handPlayer, i);
			pbNew = ProbOfHandsPlayerTurn(handCurrent, handDealer);

			pbHit = ProbAfterGettingCard(pbHit, pbNew, i);
		}
	}
	/* Hit */

	/* Stand */
	if ((action == STAND) || (action == NONE))
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

ProbSet SimpleCalculator::ProbOfHandsPlayerDouble(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbDouble;
	ProbSet pbNew;

	pbDouble.dWin = 0;
	pbDouble.dLose = 0;
	pbDouble.dPush = 0;

	for (int i=2; i<=11; i++)
	{
		HandScore handCurrent;

		handCurrent = GetOneCard(handPlayer, i);
		pbNew = ProbOfHandsPlayerTurn(handCurrent, handDealer, STAND);

		pbDouble = ProbAfterGettingCard(pbDouble, pbNew, i);
	}

	return pbDouble;
}

ProbSet SimpleCalculator::ProbOfHandsPlayerSplit(HandScore handPlayer, 
		HandScore handDealer, int iTimesSplitted)
{
	ProbSet pbCurrent;
	ProbSet pbSplit;
	ProbSet pbHit;

	pbCurrent.dWin = 0;
	pbCurrent.dLose = 0;
	pbCurrent.dPush = 0;

	iTimesSplitted++;

	for (int i=2; i<=11; i++)
	{
		HandScore handCurrent;
		bool bSplitted = false;

		handCurrent = GetOneCard(handPlayer, i);
		pbHit = ProbOfHandsPlayerTurn(handCurrent, handDealer);

		if (i == handPlayer.iScore)
		{
			if (iTimesSplitted < iMaxTimesSplitted)
			{
				if (ResplitAces || (i!=11))
				{
					pbSplit = ProbOfHandsPlayerSplit(handPlayer, handDealer,
							iTimesSplitted);
					bSplitted = true;
				}
			}
		}

		if (bSplitted)
		{
			if (CalEdge(pbHit) > CalEdge(pbSplit)*(double)2)
				pbCurrent = ProbAfterGettingCard(pbCurrent, pbHit, i);
			else
				pbCurrent = ProbAfterGettingCard(pbCurrent, pbSplit, i);
		}
		else
		{
			pbCurrent = ProbAfterGettingCard(pbCurrent, pbHit, i);
		}
	}

	return pbCurrent;
}

ProbSet SimpleCalculator::ProbAfterGettingCard(ProbSet pbCurrent, ProbSet pbNextCard, int iCardValue, double multiplier)
{
	pbCurrent.dWin += ProbOfGettingCard(iCardValue) * 
		pbNextCard.dWin * multiplier;
	pbCurrent.dLose += ProbOfGettingCard(iCardValue) * 
		pbNextCard.dLose * multiplier;
	pbCurrent.dPush += ProbOfGettingCard(iCardValue) * 
		pbNextCard.dPush * multiplier;

	return pbCurrent;
}

void SimpleCalculator::ShowProbSet(int iPlayerScore, bool bPlayerSoft, 
		int iDealerScore, bool bDealerSoft, Table * table)
{
	ProbSet pbHit;
	ProbSet pbStand;
	ProbSet pbDouble;
	ProbSet pbSplit;
	HandScore handPlayer;
	HandScore handDealer;

	handPlayer.iScore = iPlayerScore;
	handPlayer.bSoft = bPlayerSoft;
	handDealer.iScore = iDealerScore;
	handDealer.bSoft = bDealerSoft;

	pbHit = ProbOfHandsPlayerTurn(handPlayer, handDealer, HIT);
	pbStand = ProbOfHandsPlayerTurn(handPlayer, handDealer, STAND);
	pbDouble = ProbOfHandsPlayerDouble(handPlayer, handDealer);

	cout << fixed;
	cout << "Hit: " << endl;
	cout << "Win " << pbHit.dWin << endl;
	cout << "Lose " << pbHit.dLose << endl;
	cout << "Push " << pbHit.dPush << endl;
	cout << "EV " << CalEdge(pbHit) << endl;
	cout << endl;

	cout << "Stand: " << endl;
	cout << "Win " << pbStand.dWin << endl;
	cout << "Lose " << pbStand.dLose << endl;
	cout << "Push " << pbStand.dPush << endl;
	cout << "EV " << CalEdge(pbStand) << endl;
	cout << endl;

	cout << "Double: " << endl;
	cout << "Win " << pbDouble.dWin << endl;
	cout << "Lose " << pbDouble.dLose << endl;
	cout << "Push " << pbDouble.dPush << endl;
	cout << "EV " << CalEdge(pbDouble)*2 << endl;
	cout << endl;

	if ((iPlayerScore >= 4) && (iPlayerScore%2 == 0))
	{
		handPlayer.iScore = iPlayerScore/2;
		if ((iPlayerScore == 12) && (bPlayerSoft))
			handPlayer.iScore = 11;

		handPlayer.bSoft = bPlayerSoft;

		pbSplit = ProbOfHandsPlayerSplit(handPlayer, handDealer, 0);
		cout << "Split: " << endl;
		cout << "Win " << pbSplit.dWin << endl;
		cout << "Lose " << pbSplit.dLose << endl;
		cout << "Push " << pbSplit.dPush << endl;
		cout << "EV " << CalEdge(pbSplit)*2 << endl;
	}
}

SimpleCalculator::SimpleCalculator(void)
{
	iMaxTimesSplitted = 3;
	ResplitAces = false;
}

SimpleCalculator::~SimpleCalculator(void)
{
}
