#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Card
{
private:
	int id;
	unsigned int value;
	string name;
public:
	unsigned int GetValue(void);
	string ShowName(void);

	Card(void);
	Card(int id, int value, char name[]);
	~Card(void);
};

