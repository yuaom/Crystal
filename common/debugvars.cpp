#include "debugvars.h"
#include "environment.h"

namespace Crystal
{
    namespace Common
    {
        ////////////////////////////////////////////////////////////////////////////////
        DebugVariables::Entry::Entry(
            const wchar_t* name,
            DebugVariables::Entry::TYPE type )
            : m_Type( type )
        {
            std::wstring key( L"Crystal_" );
            key += name;

            std::wstring value;
            m_IsSet = GetEnvironmentVar( key, value );

            if( m_IsSet )
            {
                switch( m_Type )
                {
                case TYPE_UINT:
                {
                    uint32_t uintValue = 0;
                    std::wstringstream s( value );
                    s >> uintValue;
                    m_Value = uintValue;
                }
                break;
                default:
                    m_Value = value;
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t DebugVariables::Entry::asUint32()
        {
            return std::get<uint32_t>( m_Value );
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::wstring& DebugVariables::Entry::asString()
        {
            return std::get<std::wstring>( m_Value );
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool DebugVariables::Entry::isSet()
        {
            return m_IsSet;
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DebugVariables> DebugVariables::m_pVars = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        DebugVariables::DebugVariables() :
            EnableLog( L"EnableLog", Entry::TYPE_UINT )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void DebugVariables::OnDllProcessAttach()
        {
            if( m_pVars == nullptr )
            {
                m_pVars = std::make_unique<DebugVariables>();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void DebugVariables::OnDllProcessDetach()
        {
            m_pVars.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DebugVariables>& DebugVariables::get()
        {
            return m_pVars;
        }
    }
}