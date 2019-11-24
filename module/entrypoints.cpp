#include "pch.h"
#include "entrypoints.h"

extern "C" __declspec(dllexport) HRESULT __cdecl OpenAdapter10(D3D10DDIARG_OPENADAPTER* arg1)
{
	return S_OK;
}