#pragma once
#include <Windows.h>
#include <stdio.h>
#include "sdk/Offsets.h"
#include "sdk/Hooks.h"
#include "sdk/GridManager.h"

void CreateConsole()
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	(void) freopen("CON", "w", stdout);
}

void CloseConsole()
{
	FreeConsole();
}

void SetAll()
{
	int count = 0;

	for (int x = 1; x <= g_GridManager->GetWidth(); x++)
	{
		for (int y = 1; y <= g_GridManager->GetHeight(); y++)
		{
			cell_t cell = g_GridManager->GetCell(x, y);

			if (cell & CELL_MINE)
				g_GridManager->SetCell(x, y, cell ^ 1);
			else
				g_GridManager->SetCell(x, y, 0);
		}
	}

	printf("%d\n", count);
}

enum EEmoji
{
	HAPPY = 0,
	SHOCKED,
	DEAD,
	COOL,
};

void RenderEmoji(EEmoji emoji)
{
	// updateEmoji states: 0-happy, 1-shocked, 2-dead, 3-cool

	int (__stdcall * setEmoji) (HDC hdc, int a2) = (int (__stdcall *) (HDC, int)) 0x10028D9;

	HWND hWnd = *(HWND *) Offsets::Globals::pHdc;
	HDC hdc = GetDC(hWnd);
	
	setEmoji(hdc, emoji);
}

void DrawBomb(int x, int y)
{
	// HDC indices: 0x0A-unblown bomb, 0x0C-blown bomb, 0x0F-empty

	HDC *hdcSrc = (HDC *) 0x1005A20; // 16 length
	HDC bombHdc = hdcSrc[0x0A];

	HWND hWnd = *(HWND *) 0x1005B24;
	HDC hdc = GetDC(hWnd);

	BitBlt(hdc, 16 * x - 4, 16 * y + 39, 16, 16, bombHdc, 0, 0, SRCCOPY);
}

/*
Clear all cells that aren't mines.
This results in an instant win.
*/
void ClearAll()
{
	/* For each column in the grid */
	for (int x = 1; x <= g_GridManager->GetWidth(); x++)
		/* For each row in the grid */
		for (int y = 1; y <= g_GridManager->GetHeight(); y++)
			/* If cell at current coordinates isn't mine */
			if (!(g_GridManager->GetCell(x, y) & CELL_MINE))
				/* Reveal non-mine cell */
				Hooks::LeftClick::Original(x, y);
}

void DrawAllBombs()
{
	/* For each column in the grid */
	for (int x = 1; x <= g_GridManager->GetWidth(); x++)
		/* For each row in the grid */
		for (int y = 1; y <= g_GridManager->GetHeight(); y++)
			/* If cell at current coordinates is mine */
			if (g_GridManager->GetCell(x, y) & CELL_MINE)
				/* Reveal mine cell */
				DrawBomb(x, y);
}

void Hang()
{
	while (!GetAsyncKeyState(VK_END));
}

/*
Runs actual hack & features.
*/
void RunHack()
{
	Hooks::Enable();

	//DrawAllBombs();

	//ClearAll();

	Hang();

	Hooks::Disable();
}

int WINAPI HackThread(HMODULE hModule)
{
	CreateConsole();

	RunHack();

	CloseConsole();

	FreeLibraryAndExitThread(hModule, 0);
	CloseHandle(hModule);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE) HackThread, hModule, 0, 0);
	}

	return TRUE;
}
