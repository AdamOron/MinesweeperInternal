#pragma once
#include "Feature.h"
#include <vector>

typedef struct _CELL
{
	int x, y;
} CELL, *PCELL;

class AutoFlagger : public Feature<AutoFlagger>
{
public:
	AutoFlagger();
	void CacheMines();
	void FlagRandom();
	void FlagClosest(int x, int y);

private:
	std::vector<CELL> m_Mines;
	std::vector<CELL>::iterator GetRandom();
	std::vector<CELL>::iterator GetClosest(int x, int y);
};
