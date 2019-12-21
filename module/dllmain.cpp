#include "pch.h"
#include "kmd_adapter.h"
#include "kmd_handles.h"
#include "kmd_entrypoints.h"

BOOL WINAPI DllMain(
    HINSTANCE const instance,
    DWORD     const reason,
    LPVOID    const reserved )
{
    switch( reason )
    {
    case DLL_PROCESS_ATTACH:
        g_hInstance = instance;

        // Load instrumentation and logging
        Crystal::DebugVariables::OnDllProcessAttach();
        Crystal::Log::OnDllProcessAttach();

        // Load generic managers
        Crystal::Displays::OnDllProcessAttach();

        // Load top level managers
        Crystal::KMD::KmtHandleManager::OnDllProcessAttach();
        Crystal::KMD::KmdAdapterManager::OnDllProcessAttach();
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        // Go in reverse order
        Crystal::KMD::KmdAdapterManager::OnDllProcessDetach();
        Crystal::KMD::KmtHandleManager::OnDllProcessDetach();

        Crystal::Displays::OnDllProcessDetach();

        Crystal::Log::OnDllProcessDetach();
        Crystal::DebugVariables::OnDllProcessDetach();

        g_hInstance = NULL;
        break;
    }

    return TRUE;
}