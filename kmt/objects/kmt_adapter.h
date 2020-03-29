#pragma once

namespace Crystal
{
    namespace KMT
    {
        ////////////////////////////////////////////////////////////////////////////////
        class KmtAdapter
        {
        public:
            KmtAdapter( const LUID& luid );

            ~KmtAdapter();

            D3DKMT_HANDLE   GetHandle();
            const LUID&     GetLUID();

        private:

            D3DKMT_HANDLE   m_Handle;
            LUID            m_LUID;
        };

        ////////////////////////////////////////////////////////////////////////////////
        class KmtAdapterManager
        {
        public:
            static void OnDllProcessAttach();

            static void OnDllProcessDetach();

            static std::unique_ptr<KmtAdapterManager>& get();

            KmtAdapterManager();

            ~KmtAdapterManager();

            template< typename ... ParamsT >
            KmtAdapter* CreateAdapter( ParamsT&&... p );

        private:

            static std::unique_ptr<KmtAdapterManager> m_pAdapters;

            std::vector<KmtAdapter*>    m_Adapters;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename... ParamsT >
        KmtAdapter* KmtAdapterManager::CreateAdapter( ParamsT&&... p )
        {
            LUID luid = { 0 };
            luid.LowPart = static_cast<DWORD>( m_Adapters.size() );

            m_Adapters.emplace_back( new KmtAdapter( luid, std::forward<ParamsT>( p )... ) );

            return m_Adapters.back();
        }
    }
}