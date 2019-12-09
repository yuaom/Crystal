#include "pch.h"
#include "dllcontext.h"

namespace Crystal
{
    ////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<DllContext>    DllContext::m_pContext = nullptr;

    ////////////////////////////////////////////////////////////////////////////////
    void DllContext::OnDllProcessAttach( HINSTANCE hInstance )
    {
        if( m_pContext == nullptr )
        {
            m_pContext = std::make_unique<DllContext>( hInstance );
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    void DllContext::OnDllProcessDetach()
    {
        m_pContext.release();
    }

    ////////////////////////////////////////////////////////////////////////////////
    DllContext::DllContext( HINSTANCE hInst ) :
        m_pDebugVars( std::make_unique<DebugVariables>() ),
        m_pLog( std::make_unique<Log>() ),
        m_pDisplays( std::make_unique<Displays>() ),
        m_pKmdAdapterManger( std::make_unique<KmdAdapterManager>() ),
        m_ModuleHandle( static_cast<HMODULE>( hInst ) )
    {

    }

    ////////////////////////////////////////////////////////////////////////////////
    DllContext::~DllContext()
    {

    }

    ////////////////////////////////////////////////////////////////////////////////
    DllContext::ptr_t& DllContext::get()
    {
        return m_pContext;
    }

    ////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<Log>& DllContext::getLog()
    {
        return m_pLog;
    }

    ////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<DebugVariables>& DllContext::getDebugVars()
    {
        return m_pDebugVars;
    }

    ////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<Displays>& DllContext::getDisplays()
    {
        return m_pDisplays;
    }

    ////////////////////////////////////////////////////////////////////////////////
    std::unique_ptr<KmdAdapterManager>& DllContext::getKmdAdapterManager()
    {
        return m_pKmdAdapterManger;
    }

    ////////////////////////////////////////////////////////////////////////////////
    HMODULE DllContext::GetModuleHandle() const
    {
        return m_ModuleHandle;
    }
}