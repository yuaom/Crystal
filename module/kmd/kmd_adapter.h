#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class KmdAdapter
        {
        public:
            KmdAdapter();

            ~KmdAdapter();

            D3DKMT_HANDLE   GetHandle();

        private:

            D3DKMT_HANDLE   m_Handle;
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

            static D3DKMT_HANDLE ListIndexToKmtHandle( uint32_t i );
            static uint32_t KmtHandleToListIndex( D3DKMT_HANDLE handle );

            std::vector<KmdAdapter*>    m_Adapters;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename... ParamsT >
        KmdAdapter* KmdAdapterManager::CreateAdapter( ParamsT&&... p )
        {
            m_Adapters.emplace_back( new KmdAdapter( std::forward<ParamsT>( p )... ) );

            return m_Adapters.back();
        }
    }
}