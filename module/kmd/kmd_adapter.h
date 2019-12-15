#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class KmdAdapter
        {
        public:
            KmdAdapter( const LUID& luid );

            ~KmdAdapter();

            D3DKMT_HANDLE   GetHandle();
            const LUID&     GetLUID();

        private:

            D3DKMT_HANDLE   m_Handle;
            LUID            m_LUID;
        };

        ////////////////////////////////////////////////////////////////////////////////
        class KmdAdapterManager
        {
        public:
            static void OnDllProcessAttach();

            static void OnDllProcessDetach();

            static std::unique_ptr<KmdAdapterManager>& get();

            KmdAdapterManager();

            ~KmdAdapterManager();

            template< typename ... ParamsT >
            KmdAdapter* CreateAdapter( ParamsT&&... p );

        private:

            static std::unique_ptr<KmdAdapterManager> m_pAdapters;

            std::vector<KmdAdapter*>    m_Adapters;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename... ParamsT >
        KmdAdapter* KmdAdapterManager::CreateAdapter( ParamsT&&... p )
        {
            LUID luid = { 0 };
            luid.LowPart = static_cast<DWORD>( m_Adapters.size() );

            m_Adapters.emplace_back( new KmdAdapter( luid, std::forward<ParamsT>( p )... ) );

            return m_Adapters.back();
        }
    }
}