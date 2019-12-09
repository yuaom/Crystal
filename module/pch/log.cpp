#include "pch.h"
#include "log.h"

namespace Crystal
{
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
            case MESSAGE_DLL_ENTRY:    s << "DllEntry"; break;
            default: assert( 0 ); break;
            }

            s << " : " << str << "\n";

            OutputDebugStringA( s.str().c_str() );
        }
    }

}