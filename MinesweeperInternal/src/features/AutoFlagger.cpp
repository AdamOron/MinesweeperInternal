#include "AutoFlagger.h"
#include "../hooklib/hook.h"
#include "../sdk/GridManager.h"
#include "../sdk/Hooks.h"

AutoFlagger::AutoFlagger() :
	m_Mines()
{
	CacheMines();
}

void AutoFlagger::CacheMines()
{
	m_Mines.clear();

	/* For each column in the grid */
	for (int x = 1; x <= g_GridManager->GetWidth(); x++)
		/* For each row in the grid */
		for (int y = 1; y <= g_GridManager->GetHeight(); y++)
			/* If cell at current coordinates is mine */
			if (g_GridManager->GetCell(x, y) & CELL_MINE)
				/* Cache mine */
				m_Mines.push_back({ x, y });
}

std::vector<CELL>::iterator AutoFlagger::GetRandom()
{
	if (m_Mines.empty())
		return m_Mines.end();

	return --m_Mines.end();
}

void AutoFlagger::FlagRandom()
{
	if (m_Mines.empty())
		return;

	auto randIter = GetRandom();

	CELL &randCell = *randIter;
	Hooks::RightClick::Original(randCell.x, randCell.y);

	m_Mines.erase(randIter);
}

inline int Dist(CELL &a, CELL &b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

std::vector<CELL>::iterator AutoFlagger::GetClosest(int x, int y)
{
	std::vector<CELL>::iterator closestIter = m_Mines.end();
	int closestDist = 100000;

	CELL selected = { x, y };

	for (auto iterator = m_Mines.begin(); iterator != m_Mines.end(); iterator++)
	{
		int dist = Dist(*iterator, selected);

		if (dist < closestDist)
		{
			closestDist = dist;
			closestIter = iterator;
		}
	}

	return closestIter;
}

void AutoFlagger::FlagClosest(int x, int y)
{
	auto closestIter = GetClosest(x, y);

	if (closestIter == m_Mines.end())
		return;

	CELL &closestCell = *closestIter;
	Hooks::RightClick::Original(closestCell.x, closestCell.y);

	m_Mines.erase(closestIter);
}
