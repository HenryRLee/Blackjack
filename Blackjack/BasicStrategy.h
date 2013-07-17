#pragma once
#include "Strategy.h"

class BasicStrategy :
	public Strategy
{
protected:
	enum
	{
		H = HIT, S = STAND, P = SPLIT, D = DOUBLE, R = SURRENDER,
		RH = R*10+H, RS = R*10+S, DH = D*10+H, DS = D*10+S
	};

public:
	int MakeDecision(Hand handCurrent, bitset <5> allowset, Table table);

	BasicStrategy(void);
	~BasicStrategy(void);
};
