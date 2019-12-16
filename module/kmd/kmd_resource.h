#pragma once

namespace Crystal
{
    namespace KMD
    {
        class Resource
        {
        public:

            static void Destroy( D3DKMT_HANDLE handle );

            Resource();

            ~Resource();

            D3DKMT_HANDLE    GetHandle();

        private:
            D3DKMT_HANDLE               m_Handle;
        };
    }
}