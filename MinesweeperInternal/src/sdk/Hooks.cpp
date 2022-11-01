#include "Hooks.h"
#include "../trampy/Trampy.h"
#include "Offsets.h"
#include "../features/AutoFlagger.h"

namespace Hooks
{
	namespace OnClick
	{
		Signature Original = NULL;

		char __stdcall Hooked(int x, int y)
		{
			return Original(x, y);
		}
	}

	namespace RightClick
	{
		Signature Original = NULL;

		void __stdcall Hooked(int x, int y)
		{
			AutoFlagger::GetInstance()->FlagClosest(x, y);
		}
	}

	namespace LeftClick
	{
		Signature Original = NULL;

		int __stdcall Hooked(int x, int y)
		{
			return Original(x, y);
		}
	}

	void Enable()
	{
		/* Initialize pointers to all functions using their offsets */

		PHOOK_DESCRIPTOR OnClickHook = Trampy::CreateHook((LPVOID) Offsets::Functions::OnClick, (LPVOID) Hooks::OnClick::Hooked, (LPVOID *) &OnClick::Original);

		PHOOK_DESCRIPTOR RightClickHook = Trampy::CreateHook((LPVOID) Offsets::Functions::RightClick, (LPVOID)Hooks::RightClick::Hooked, (LPVOID *) &RightClick::Original);

		PHOOK_DESCRIPTOR LeftClickHook = Trampy::CreateHook((LPVOID) Offsets::Functions::LeftClick, (LPVOID) Hooks::LeftClick::Hooked, (LPVOID *) &LeftClick::Original);

		Trampy::EnableAllHooks();
	}

	void Disable()
	{
		Trampy::DisableAllHooks();
	}
}
