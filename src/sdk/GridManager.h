#pragma once

using cell_t = char;

/* Flag for a cell that's a mine */
#define CELL_MINE 0x80
/* Flag for a cell that's flagged */
#define CELL_FLAGGED 0x0E
/* Flag for a cell that's question mark-ed */
#define CELL_QMARKED 0x0D
/* Flag for a cell that's opened */
#define CELL_OPENED 0x40
/* Flag for a cell that's not opened */
#define CELL_UNOPENED 0x0F

/*
This class manages the grid and all of its cells.
It contains both the width & height of the grid, as well as the array of the cells.
Offers utility functions to access/modify the grid.
*/
class CGridManager
{
private:
	/* The Width & Height of the Grid are adjacent in memory */
	int m_Width; // 0x0
	int m_Height; // 0x4
	/* There's a NULL 4 byte padding between the Height and the Cell array */
	char _padding[4]; // 0x8
	/* The Grid itself is stored as a char[] */
	cell_t m_Cells[]; // 0xC

	/*
	Private default constructor, to prevent anyone from instantiating this class.
	This class should only be accessed directly from memory (via casting).
	*/
	CGridManager();

public:
	/*
	@param x, the x-coordinate of the cell.
	@param y, the y-coordinate of the cell.
	@return the value of the cell at the given coordinates.
	*/
	cell_t GetCell(int x, int y) const;
	/*
	@param x, the x-coordinate of the cell.
	@param y, the y-coordinate of the cell.
	@param value, the desired value of the cell.

	Sets the value of the cell at the given coordinates to the given value.
	*/
	void SetCell(int x, int y, cell_t value);
	/*
	@param return the width of the grid.
	*/
	int GetWidth() const;
	/*
	@param return the height of the grid.
	*/
	int GetHeight() const;
};

/*
We'll save a global instance to the GridManager, as there should only be one.
*/
extern CGridManager *g_GridManager;
