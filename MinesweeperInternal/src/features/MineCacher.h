#pragma once
#include "Feature.h"

class MineCacher : public Feature<MineCacher>
{
private:


public:
	MineCacher();
	void RevealCell(int x, int y);
	void FlagCell(int x, int y);
};
