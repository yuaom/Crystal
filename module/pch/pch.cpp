#include "pch.h"

HINSTANCE g_hInstance = 0;

namespace Utilities
{
    ////////////////////////////////////////////////////////////////////////////////
    bool GetEnvironmentVariable( 
        const std::wstring& name, 
        std::wstring& out )
    {
        out.resize( 100 );

        DWORD ret = GetEnvironmentVariableW( name.c_str(), out.data(), out.size() );

        out.shrink_to_fit();

        return ret != 0;
    }
}