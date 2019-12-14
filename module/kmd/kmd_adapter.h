#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class KmdAdapter
        {
        public:
            using ptr_t = std::shared_ptr<KmdAdapter>;

            KmdAdapter();

            ~KmdAdapter();

            D3DKMT_HANDLE    GetHandle();

        private:

            D3DKMT_HANDLE    m_Handle;
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
            KmdAdapter::ptr_t& CreateAdapter( ParamsT&&... p );

        private:

            static std::unique_ptr<KmdAdapterManager> m_pAdapters;

            static D3DKMT_HANDLE ListIndexToKmtHandle( uint32_t i );
            static uint32_t KmtHandleToListIndex( D3DKMT_HANDLE handle );

            std::vector<KmdAdapter::ptr_t> m_Adapters;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename... ParamsT >
        KmdAdapter::ptr_t& KmdAdapterManager::CreateAdapter( ParamsT&&... p )
        {
            m_Adapters.emplace_back(
                std::move( std::make_shared<KmdAdapter>(
                    std::forward<ParamsT>( p )... ) ) );

            return m_Adapters.back();
        }
    }
}