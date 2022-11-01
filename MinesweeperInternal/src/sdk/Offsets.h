#pragma once
#include <stdint.h>

/*
All memory offsets for the hack.
*/
namespace Offsets
{
	/*
	Offsets to important functions that we call/hook.
	*/
	namespace Functions
	{
		const ptrdiff_t RightClick = 0x100374F;
		const ptrdiff_t LeftClick = 0x1003512;
		const ptrdiff_t OnClick = 0x10031D4;
	}

	/*
	Offsets to global variables.
	*/
	namespace Globals
	{
		const ptrdiff_t dwGridManager = 0x1005334;
		const ptrdiff_t iRevealedCells = 0x10057A4;
		const ptrdiff_t iNonMines = 0x10057A0;
		const ptrdiff_t xGlobal = 0x1005118;
		const ptrdiff_t pHdc = 0x1005B24;
		const ptrdiff_t iMineAmount = 0x10056A4;
	}
	
	/*
	Offsets to member variables within their classes.
	*/
	namespace Members
	{
		/* Offsets for members of GridManager */
		const ptrdiff_t m_iWidth  = 0x0; // 0x1005334
		const ptrdiff_t m_iHeight = 0x4; // 0x1005338
		const ptrdiff_t m_dwCells = 0xC; // 0x1005340
	}
};
