#pragma once

namespace Crystal
{
    namespace KMD
    {
        class Allocation
        {
        public:

            static Allocation* Create( D3DDDI_ALLOCATIONINFO* pInfo );

            static void Destroy( D3DKMT_HANDLE handle );

            D3DKMT_HANDLE   GetHandle() const;

        private:

            Allocation( D3DDDI_ALLOCATIONINFO* pInfo );

            ~Allocation( void );

            void Allocate( D3DDDI_ALLOCATIONINFO* pInfo );

            D3DKMT_HANDLE   m_Handle;
        };
    }
}