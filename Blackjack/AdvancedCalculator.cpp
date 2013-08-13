#include "AdvancedCalculator.h"
#include "UsedCard.h"

void AdvancedCalculator::InitiateCardCounts(UsedCard * usedcard)
{
	vector <Card> vCard;

	vInitialCount.resize(13);

	for (int i=2; i<=11; i++)
	{
		vInitialCount[i] = 24;
	}

	/* iCount[0] marks the total counts */
	vInitialCount[0] = 312;
	vInitialCount[10] = 96;

	if (usedcard != NULL)
	{
		vCard = usedcard->ShowCards();

		for (int i=0; i<vCard.size(); i++)
		{
			int value;
			value = vCard[i].GetValue();

			vInitialCount[value]--;
			vInitialCount[0]--;
		}
	}
}

double AdvancedCalculator::ProbOfGettingCard(int value, vector <int> vRemaining)
{
	double prob;
	
	if (value < vRemaining.size())
	{
		prob = (double)vRemaining[value]/(double)vRemaining[0];
	}
	else
	{
		cout << "Error when calcualting ProbOfGettingCard" << endl;
	}

	return prob;
}

double AdvancedCalculator::ProbOfGettingCard(int value)
{
	double prob;

	if (value <= 11)
	{
		prob = (double)vInitialCount[value]/(double)vInitialCount[0];
	}

	return prob;
}

vector <int> AdvancedCalculator::CardFlowing(int value, vector <int> vRemaining)
{
	vector <int> vCurrent(vRemaining);

	if (value < vCurrent.size())
	{
		vCurrent[value]--;
		vCurrent[0]--;
	}
	else
	{
		cout << "Error when calcualting CardFlowing" << endl;
	}

	return vCurrent;
}

ProbSet AdvancedCalculator::ProbOfHandsDealerTurn(HandScore handPlayer, 
		HandScore handDealer, vector <int> vRemaining)
{
	ProbSet pbCurrent;

	if (DealerHits(handDealer))
	{
		for (int i=2; i<=11; i++)
		{
			ProbSet pbNew;
			HandScore handCurrent;
			vector <int> vCurrent(vRemaining);

			vCurrent = CardFlowing(i, vCurrent);
			handCurrent = GetOneCard(handDealer, i);
			pbNew = ProbOfHandsDealerTurn(handPlayer, handCurrent, vCurrent);

			pbCurrent = ProbAfterGettingCard(pbCurrent, pbNew, i, vRemaining);
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

ProbSet AdvancedCalculator::ProbOfHandsPlayerTurn(HandScore handPlayer, 
		HandScore handDealer, vector <int> vRemaining, int action)
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

	if (handPlayer.iScore == 21)
		action = STAND;

	/* Hit */
	if ((action == HIT) || (action == NONE))
	{
		ProbSet pbNew;

		for (int i=2; i<=11; i++)
		{
			HandScore handCurrent;
			vector <int> vCurrent(vRemaining);

			vCurrent = CardFlowing(i, vCurrent);
			handCurrent = GetOneCard(handPlayer, i);
			pbNew = ProbOfHandsPlayerTurn(handCurrent, handDealer, vCurrent);

			pbHit = ProbAfterGettingCard(pbHit, pbNew, i, vRemaining);
		}
	}
	/* Hit */

	/* Stand */
	if ((action == STAND) || (action == NONE))
	{
		pbStand = ProbOfHandsDealerTurn(handPlayer, handDealer, vRemaining);
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

ProbSet AdvancedCalculator::ProbOfHandsPlayerHit(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbHit;
	vector <int> vStart(vInitialCount);

	pbHit = ProbOfHandsPlayerTurn(handPlayer, handDealer, vStart, HIT);
	pbHit.dEV = CalEdge(pbHit);

	return pbHit;
}

ProbSet AdvancedCalculator::ProbOfHandsPlayerStand(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbStand;
	vector <int> vStart(vInitialCount);

	pbStand = ProbOfHandsPlayerTurn(handPlayer, handDealer, vStart, STAND);
	pbStand.dEV = CalEdge(pbStand);

	return pbStand;
}

ProbSet AdvancedCalculator::ProbOfHandsPlayerHitOrStand(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbCurrent;
	vector <int> vStart(vInitialCount);

	pbCurrent = ProbOfHandsPlayerTurn(handPlayer, handDealer, vStart);
	pbCurrent.dEV = CalEdge(pbCurrent);

	return pbCurrent;
}

ProbSet AdvancedCalculator::ProbOfHandsPlayerDouble(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbDouble;
	ProbSet pbNew;

	for (int i=2; i<=11; i++)
	{
		HandScore handCurrent;
		vector <int> vStart(vInitialCount);

		vStart = CardFlowing(i, vStart);
		handCurrent = GetOneCard(handPlayer, i);
		pbNew = ProbOfHandsPlayerTurn(handCurrent, handDealer, vStart, STAND);

		pbDouble = ProbAfterGettingCard(pbDouble, pbNew, i, vInitialCount);
	}

	pbDouble.dEV = CalEdge(pbDouble)*(double)2;

	return pbDouble;
}

ProbSet AdvancedCalculator::ProbAfterGettingCard(ProbSet pbCurrent, 
		ProbSet pbNextCard, int iCardValue, vector <int> vRemaining)
{
	pbCurrent.dWin += ProbOfGettingCard(iCardValue, vRemaining)
		* pbNextCard.dWin;

	pbCurrent.dLose += ProbOfGettingCard(iCardValue, vRemaining)
		* pbNextCard.dLose;

	pbCurrent.dPush += ProbOfGettingCard(iCardValue, vRemaining)
		* pbNextCard.dPush;

	return pbCurrent;
}

void AdvancedCalculator::ShowProbSetByAction(int iPlayerScore, bool bPlayerSoft,
		int iDealerScore, bool bDealerSoft, UsedCard * usedcard)
{
	InitiateCardCounts(usedcard);
	SimpleCalculator::ShowProbSetByAction(iPlayerScore, bPlayerSoft, 
			iDealerScore, bDealerSoft, usedcard);
}

void AdvancedCalculator::ShowProbSetByNextCard(int iPlayerScore, 
		bool bPlayerSoft, int iDealerScore, bool bDealerSoft, 
		UsedCard * usedcard)
{
	InitiateCardCounts(usedcard);
	SimpleCalculator::ShowProbSetByNextCard(iPlayerScore, bPlayerSoft, 
			iDealerScore, bDealerSoft, usedcard);
}

AdvancedCalculator::AdvancedCalculator(void)
{
}

AdvancedCalculator::~AdvancedCalculator(void)
{
}
