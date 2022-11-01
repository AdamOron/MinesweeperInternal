#pragma once

/*
This namespace is responsible for managing all function hooks.
Each function we hook has its own namespace within this namespace.
*/
namespace Hooks
{
	/*
	OnClick function.
	Called whenever a cell is clicked.
	We'll hook it to ensure the user doesn't click a mine.
	*/
	namespace OnClick
	{
		using Signature = char (__stdcall *) (int x, int y);
		extern Signature Original;

		char __stdcall Hooked(int x, int y);
	}

	/*
	RightClick function.
	We call it to apply flags/question marks to cells.
	*/
	namespace RightClick
	{
		using Signature = void (__stdcall *) (int x, int y);
		extern Signature Original;

		void __stdcall Hooked(int x, int y);
	}

	/*
	LeftClick function.
	We clal it to open cells.
	*/
	namespace LeftClick
	{
		using Signature = int (__stdcall *) (int x, int y);
		extern Signature Original;

		int __stdcall Hooked(int x, int y);
	}

	/*
	Initialize all function pointers and hooks.
	*/
	void Init();
}
