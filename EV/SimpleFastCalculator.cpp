#include "SimpleFastCalculator.h"

ProbSet SimpleFastCalculator::ProbOfHandsDealerTurn(HandScore handPlayer, 
		HandScore handDealer)
{
	ProbSet pbSet;

	int iPScore;
	int iDScore;
	int iPSoft;
	int iDSoft;

	iPScore = handPlayer.iScore;
	iDScore = handDealer.iScore;

	if (handPlayer.bSoft)
		iPSoft = 1;
	else
		iPSoft = 0;

	if (handDealer.bSoft)
		iDSoft = 1;
	else
		iDSoft = 0;

	if (seDealer[iPScore][iDScore][iPSoft][iDSoft].bMark)
	{
		pbSet.dEV = seDealer[iPScore][iDScore][iPSoft][iDSoft].dEV;
	}
	else
	{
		seDealer[iPScore][iDScore][iPSoft][iDSoft].bMark = true;
		pbSet = SimpleCalculator::ProbOfHandsDealerTurn(handPlayer, handDealer);
		seDealer[iPScore][iDScore][iPSoft][iDSoft].dEV = pbSet.dEV;
	}

	return pbSet;
}

ProbSet SimpleFastCalculator::ProbOfHandsPlayerTurn(HandScore handPlayer, 
		HandScore handDealer, int action)
{
	ProbSet pbSet;

	int iPScore;
	int iDScore;
	int iPSoft;
	int iDSoft;

	iPScore = handPlayer.iScore;
	iDScore = handDealer.iScore;

	if (handPlayer.bSoft)
		iPSoft = 1;
	else
		iPSoft = 0;

	if (handDealer.bSoft)
		iDSoft = 1;
	else
		iDSoft = 0;

	if (sePlayer[iPScore][iDScore][iPSoft][iDSoft].bMark)
	{
		pbSet.dEV = sePlayer[iPScore][iDScore][iPSoft][iDSoft].dEV;
	}
	else
	{
		sePlayer[iPScore][iDScore][iPSoft][iDSoft].bMark = true;
		pbSet = SimpleCalculator::ProbOfHandsPlayerTurn(handPlayer, handDealer);
		sePlayer[iPScore][iDScore][iPSoft][iDSoft].dEV = pbSet.dEV;
	}

	return pbSet;
}

SimpleFastCalculator::SimpleFastCalculator(void)
{
}

SimpleFastCalculator::~SimpleFastCalculator(void)
{
}
