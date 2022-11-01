#include "GridManager.h"
#include "Offsets.h"

/* The width of the cell array is a constant 32 */
#define GRID_WIDTH 32
/* Converts given 2D coordinates to a flattened index */
#define FLAT_COORDS(x, y) GRID_WIDTH * y + x

CGridManager::CGridManager()
{
	// Empty, will never be called.
}

cell_t CGridManager::GetCell(int x, int y) const
{
	return m_Cells[FLAT_COORDS(x, y)];
}

void CGridManager::SetCell(int x, int y, cell_t value)
{
	m_Cells[FLAT_COORDS(x, y)] = value;
}

int CGridManager::GetWidth() const
{
	return m_Width;
}

int CGridManager::GetHeight() const
{
	return m_Height;
}

int CGridManager::GetMineCount() const
{
	return *(int32_t *) Offsets::Globals::iNonMines;
}

CGridManager *g_GridManager = (CGridManager *) Offsets::Globals::dwGridManager;
