#include "pch.h"
#include "dllmain.h"

BOOL WINAPI DllMain(
	HINSTANCE const instance,
	DWORD     const reason,
	LPVOID    const reserved )
{
	// Perform actions based on the reason for calling.
	switch( reason )
	{
	case DLL_PROCESS_ATTACH:
		Log::OnDllProcessAttach();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		Log::OnDllProcessDetach();
		break;
	}

	return TRUE;
}