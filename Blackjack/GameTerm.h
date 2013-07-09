#pragma once

namespace GameTerm
{
	enum Action
	{
		HIT, STAND, DOUBLE, SPLIT, SURRENDER
	};

	enum Status
	{
		WON, LOST, PUSH, BJ, WAITING, BUSTED, SURRENDERED
	};

	enum
	{
		MaxTimesSplitted = 7,
		MaxHands= 8,
		MaxScore = 21
	};
};

