#include "NoStrategy.h"
#include "Hand.h"
#include "Table.h"

void NoStrategy::OutputDialogue(bitset <5> allowset)
{
	cout << "Input your Selection" << endl;
	cout << "Available options: ";

	if (allowset[HIT] == 1)
		cout << "HIT ";
	if (allowset[STAND] == 1)
		cout << "STAND ";
	if (allowset[DOUBLE] == 1)
		cout << "DOUBLE ";
	if (allowset[SPLIT] == 1)
		cout << "SPLIT ";
	if (allowset[SURRENDER] == 1)
		cout << "SURRENDER ";
	cout << endl;
}

int NoStrategy::InputSelection(bitset <5> allowset)
{
	string input;
	int action;

	cin >> input;

	if ((input.compare("HIT") && input.compare("Hit") && input.compare("H") &&
				input.compare("h") && input.compare("hit")) == 0) 
	{
		cout << "HIT" << endl;
		action = HIT;
	}
	else if ((input.compare("STAND") && input.compare("Stand") && 
				input.compare("S") && input.compare("s") && 
				input.compare("stand")) == 0) 
	{
		cout << "STAND" << endl;
		action = STAND;
	}
	else if ((input.compare("SPLIT") && input.compare("Split") && 
				input.compare("P") && input.compare("p") && 
				input.compare("split")) == 0) 
	{
		cout << "SPLIT" << endl;
		action = SPLIT;
	}
	else if ((input.compare("DOUBLE") && input.compare("Double") && 
				input.compare("D") && input.compare("d") && 
				input.compare("double")) == 0) 
	{
		cout << "DOUBLE" << endl;
		action = DOUBLE;
	}
	else if ((input.compare("SURRENDER") && input.compare("Surrender") && 
				input.compare("R") && input.compare("r") && 
				input.compare("surrender")) == 0) 
	{
		cout << "SURRENDER" << endl;
		action = SURRENDER;
	}
	else
	{
		cout << "Action not supported" << endl;
		return InputSelection(allowset);
	}

	if (allowset[action] == 0)
	{
		cout << "Action not available" << endl;
		return InputSelection(allowset);
	}
	else
	{
		return action;
	}
}

int NoStrategy::MakeDecision(Hand handCurrent, bitset <5> allowset, Table table)
{
	int action;

	OutputDialogue(allowset);
	action = InputSelection(allowset);

	return action;
}

NoStrategy::NoStrategy(void)
{
}

NoStrategy::~NoStrategy(void)
{
}
