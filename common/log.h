#pragma once
#include <memory>

namespace Crystal
{
    namespace Common
    {
        class Log
        {
        public:

            enum MESSAGE_TYPE
            {
                MESSAGE_DLL_ENTRY,

                // Raster
                MESSAGE_RASTER_COMMAND
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
}

#if defined(_DEBUG)
#define LOG_DLL_ENTRY           Crystal::Common::Log::Message( Crystal::Common::Log::MESSAGE_DLL_ENTRY, __FUNCTION__ )
#define LOG_RASTER_COMMAND( x ) Crystal::Common::Log::Message( Crystal::Common::Log::MESSAGE_RASTER_COMMAND, x )
#else
#define LOG_DLL_ENTRY
#endif