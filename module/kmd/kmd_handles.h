#pragma once

namespace Crystal
{
    namespace KMD
    {
        class KmtHandleManager
        {
        public:
            static void OnDllProcessAttach();

            static void OnDllProcessDetach();

            KmtHandleManager();

            ~KmtHandleManager();

            static D3DKMT_HANDLE Allocate( void* pObj );

            static void Free( D3DKMT_HANDLE kmtHandle );

        private:

            static std::unique_ptr<KmtHandleManager>& get();

            static std::unique_ptr<KmtHandleManager> m_pHandles;

            union HANDLE
            {
                HANDLE( void* pObj ) : m_KmdObject( pObj ){}

                struct
                {
                    D3DKMT_HANDLE   m_KmtHandle;
                    UINT            Reserved;
                };

                void* m_KmdObject;
            };

            HANDLE*                     m_pHandleAllocation;
            uint32_t                    m_SizeUsed;
            std::stack<D3DKMT_HANDLE>   m_FreeList;
        };
    }
}
