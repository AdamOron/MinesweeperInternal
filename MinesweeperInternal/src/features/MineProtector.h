#pragma once
#include "Feature.h"

class MineProtector : public Feature<MineProtector>
{
public:
	MineProtector();
	void Protect(int x, int y);
};
