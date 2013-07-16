#pragma once
#include "Statistics.h"

class StreamLog :
	public Statistics
{
public:
	void Update(Table *, string text="");
	void Update(Gambler *, string text="");
	void Update(Hand, string text="");
	void Update(string text="");

	StreamLog(void);
	~StreamLog(void);
};
