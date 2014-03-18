#pragma once

namespace GameTerm
{
	enum Action
	{
		STAND, HIT, DOUBLE, SPLIT, SURRENDER
	};

	enum Status
	{
		NONE, WON, LOST, PUSH, BJ, WAITING, BUSTED, SURRENDERED, DOUBLEDWAITING
	};

	enum
	{
		MaxTimesSplitted = 7,
		MaxHands= 8,
		MaxScore = 21
	};
};

