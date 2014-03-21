#pragma once
#include "AdvancedCalculator.h"

class HashItem;

class AdvancedFastCalculator :
	public AdvancedCalculator
{
protected:
public:
	AdvancedFastCalculator(void);
	~AdvancedFastCalculator(void);
};

class HashItem
{
protected:
	vector <int> vUsedCards;
	bool bPlayerTurn;
	int iPlayerScore;
	bool bPlayerSoft;
	int iDealerScore;
	bool bDealerSoft;

	bool bAdditional;
	bool bDoubled;

	double dEV;

public:
	void SetItems(vector <int> usedcard, bool playerturn, int playerscore,
			bool playersoft, int dealerscore, bool dealersoft,
			bool additional = false, bool doubled = false)
	{
		vUsedCards = usedcard;
		bPlayerTurn = playerturn;
		iPlayerScore = playerscore;
		bPlayerSoft = playersoft;
		iDealerScore = dealerscore;
		bDealerSoft = dealersoft;
		bAdditional = additional;
		bDoubled = doubled;
	}

	void SetEV(double ev)
	{
		dEV = ev;
	}

	bool operator == (const HashItem item) const;

	unsigned int HashValue(void);

	HashItem(void)
	{
	}
};
