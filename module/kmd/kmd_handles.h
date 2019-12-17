#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class KmtHandleManager
        {
        public:
            static void OnDllProcessAttach();

            static void OnDllProcessDetach();

            KmtHandleManager();

            ~KmtHandleManager();

            static D3DKMT_HANDLE Allocate( void* pObj );

            static void Free( D3DKMT_HANDLE kmtHandle );

            template< typename T >
            static T* To( D3DKMT_HANDLE kmtHandle );

        private:

            static KmtHandleManager* get();

            static KmtHandleManager* m_pHandles;

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

            size_t                      m_Base;
            HANDLE*                     m_pCurrent;
            uint32_t                    m_SizeUsed;
            std::stack<D3DKMT_HANDLE>   m_FreeList;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename T >
        static T* KmtHandleManager::To( D3DKMT_HANDLE kmtHandle )
        {
            const KmtHandleManager* mgr = get();
            HANDLE* handle = reinterpret_cast<HANDLE*>( mgr->m_Base + kmtHandle );
            return reinterpret_cast<T*>( handle->m_KmdObject );
        }

        ////////////////////////////////////////////////////////////////////////////////
        class KmtObject
        {
        public:
            KmtObject();

            ~KmtObject();

            D3DKMT_HANDLE GetHandle() const;

        private:
            D3DKMT_HANDLE m_Handle;
        };
    }
}
