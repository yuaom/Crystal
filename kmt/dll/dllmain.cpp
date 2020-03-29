#include <pch.h>
#include <objects/kmt_adapter.h>
#include <objects/kmt_handles.h>
#include <kmt_entrypoints.h>

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

        // Load top level managers
        Crystal::KMT::KmtHandleManager::OnDllProcessAttach();
        Crystal::KMT::KmtAdapterManager::OnDllProcessAttach();
        break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:
        // Go in reverse order
        Crystal::KMT::KmtAdapterManager::OnDllProcessDetach();
        Crystal::KMT::KmtHandleManager::OnDllProcessDetach();

        Crystal::Common::Log::OnDllProcessDetach();
        Crystal::Common::DebugVariables::OnDllProcessDetach();
        break;
    }

    return TRUE;
}