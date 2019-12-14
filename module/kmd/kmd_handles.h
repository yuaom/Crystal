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

            static std::unique_ptr<KmtHandleManager>& get();

            KmtHandleManager();

            ~KmtHandleManager();

            D3DKMT_HANDLE Allocate( void* pObj );
            void Free( D3DKMT_HANDLE kmtHandle );

        private:

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

            HANDLE* m_pHandleAllocation;
        };
    }
}
