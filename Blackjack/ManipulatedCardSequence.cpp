#include "ManipulatedCardSequence.h"
#include <random>

Card ManipulatedCardSequence::PopOneCard(void)
{
	Card cardPop;

	cardPop = vCard[0];

	vUsedCard.push_back(vCard[0]);
	vCard.erase(vCard.begin());

	return cardPop;
}

void ManipulatedCardSequence::ShuffleCards(void)
{
	for (int i=0; i<vUsedCard.size(); i++)
	{
		vCard.push_back(vUsedCard[i]);
	}

	vUsedCard.clear();
}

int ManipulatedCardSequence::TakeSpecificCard(int value, int num)
{
}

ManipulatedCardSequence::ManipulatedCardSequence(void)
{
	int iSequence[] = {11, 11, 11, 10, 10, 10};

	vCard.clear();
	vUsedCard.clear();

	for (int i=0; i<(sizeof(iSequence)/sizeof(int)); i++)
	{
		char name[8] = "";
		if (iSequence[i] == 11)
			snprintf(name, sizeof(name), "AinD");
		else
			snprintf(name, sizeof(name), "%dinD", iSequence[i]);

		Card card(0, iSequence[i], name);
		vCard.push_back(card);
	}
}

ManipulatedCardSequence::~ManipulatedCardSequence(void)
{
}
