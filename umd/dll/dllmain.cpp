#include "dllmain.h"
#include "../../common/common.h"

BOOL WINAPI DllMain(
    HINSTANCE const instance,
    DWORD     const reason,
    LPVOID    const reserved )
{
    switch( reason )
    {
    case DLL_PROCESS_ATTACH:
        // Load instrumentation and logging
        Crystal::Common::DebugVariables::OnDllProcessAttach();
        Crystal::Common::Log::OnDllProcessAttach();
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        Crystal::Common::Log::OnDllProcessDetach();
        Crystal::Common::DebugVariables::OnDllProcessDetach();
        break;
    }

    return TRUE;
}