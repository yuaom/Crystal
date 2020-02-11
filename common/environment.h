#pragma once
#include <string>

namespace Crystal
{
    namespace Common
    {
        ////////////////////////////////////////////////////////////////////////////////
        bool GetEnvironmentVar( const std::wstring& name, std::wstring& out );
    }
}