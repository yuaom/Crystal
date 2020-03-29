#pragma once

namespace Crystal
{
    namespace KMT
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
                HANDLE( void* pObj ) : m_KmtObject( pObj ){}

                struct
                {
                    D3DKMT_HANDLE   m_KmtHandle;
                    UINT            Reserved;
                };

                void* m_KmtObject;
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
            return reinterpret_cast<T*>( handle->m_KmtObject );
        }

        ////////////////////////////////////////////////////////////////////////////////
        template< typename DerivedT >
        class KmtObject
        {
        public:
            KmtObject();

            ~KmtObject();

            static DerivedT* FromHandle( D3DKMT_HANDLE handle );

            D3DKMT_HANDLE GetHandle() const;            

        private:
            D3DKMT_HANDLE m_Handle;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename DerivedT >
        KmtObject<DerivedT>::KmtObject() :
            m_Handle( KmtHandleManager::Allocate( this ) )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        template< typename DerivedT >
        KmtObject<DerivedT>::~KmtObject()
        {
            KmtHandleManager::Free( m_Handle );
        }

        ////////////////////////////////////////////////////////////////////////////////
        template< typename DerivedT >
        D3DKMT_HANDLE KmtObject<DerivedT>::GetHandle() const
        {
            return m_Handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        template< typename DerivedT >
        DerivedT* KmtObject<DerivedT>::FromHandle( D3DKMT_HANDLE handle )
        {
            return KmtHandleManager::To<DerivedT>( handle );
        }
    }
}
