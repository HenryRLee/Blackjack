#pragma once
#include "Statistics.h"

class LongTermStats :
	public Statistics
{
public:
	void Update(Table *, string text="");
	void Update(Gambler *, string text="");
	void Update(Hand, string text="");
	void Update(string text="");

	LongTermStats(void);
	~LongTermStats(void);
};
