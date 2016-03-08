/*
 *  Copyright 2016 Henry Lee
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once
#include "Blackjack.h"
#include "Card.h"
#include "GameTerm.h"

using namespace GameTerm;

class Hand
{
protected:
	int iScore;
	int iSoftScore;

public:
	vector <Card> vCard;

	int iStatus;

	long long iBet;

	int GetScore(void);
	bool IsScoreSoft(void);

	void GetOneCard(class Card);
	Card RemoveLastCard(void);

	void CleanHands(void);

	Hand(void);
	~Hand(void);
};
