#pragma once

namespace Crystal
{
    class Log
    {
    public:

        enum MESSAGE_TYPE
        {
            MESSAGE_DLL_ENTRY
        };

        static void OnDllProcessAttach();

        static void OnDllProcessDetach();

        Log();
        ~Log();

        static void Message( MESSAGE_TYPE type, const char* str );

    private:
        static std::unique_ptr<Log> m_pLog;
    };
}

#if defined(_DEBUG)
#define LOG_DLL_ENTRY    Crystal::Log::Message( Crystal::Log::MESSAGE_DLL_ENTRY, __FUNCTION__ )
#else
#define LOG_DLL_ENTRY
#endif