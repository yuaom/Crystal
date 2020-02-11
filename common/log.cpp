#include <windows.h>
#include <assert.h>
#include "log.h"
#include "debugvars.h"

namespace Crystal
{
    namespace Common
    {
        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<Log>    Log::m_pLog = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        void Log::OnDllProcessAttach()
        {
            if( m_pLog == nullptr )
            {
                m_pLog = std::make_unique<Log>();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Log::OnDllProcessDetach()
        {
            m_pLog.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        Log::Log()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Log::~Log()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void Log::Message( MESSAGE_TYPE type, const char* str )
        {
            if( DV_VALUE( EnableLog ) )
            {
                std::stringstream s;
                s << "CRYSTAL : Module : ";

                switch( type )
                {
                case MESSAGE_DLL_ENTRY:         s << "DllEntry"; break;
                case MESSAGE_RASTER_COMMAND:    s << "RasterCommand"; break;
                default: assert( 0 ); break;
                }

                s << " : " << str << "\n";

                OutputDebugStringA( s.str().c_str() );
            }
        }
    }
}