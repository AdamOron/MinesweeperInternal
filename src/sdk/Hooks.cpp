#include "Hooks.h"
#include "Offsets.h"

/*
@param T, the signature of the function.
@param pFunction, the pointer to the function.
@return pointer to the given function signature at the given address.
*/
template <typename T>
T GetFunction(uint32_t pFunction)
{
	return (T) pFunction;
}

namespace Hooks
{
	namespace OnClick
	{
		Signature Original = NULL;
	}

	namespace RightClick
	{
		Signature Original = NULL;
	}

	namespace LeftClick
	{
		Signature Original = NULL;
	}

	void Init()
	{
		/* Initialize pointers to all functions using their offsets */
		OnClick::Original = GetFunction<OnClick::Signature>(Offsets::Functions::OnClick);
		RightClick::Original = GetFunction<RightClick::Signature>(Offsets::Functions::RightClick);
		LeftClick::Original = GetFunction<LeftClick::Signature>(Offsets::Functions::LeftClick);
	}
}
