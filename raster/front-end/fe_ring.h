#pragma once

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        class RenderRing
        {
        public:
            static RenderRing* Create( uint32_t size );

            static void Destroy( RenderRing* &pRing );

            bool        Empty() const;
            bool        Full() const;
            uint32_t    Capacity() const;
            uint32_t    Size() const;
            void        Put( uint32_t item );
            uint32_t    Get();
            uint32_t    Head() const;
            uint32_t    Tail() const;

            void        ResetHead();

            uint32_t*   Checkout();
            uint32_t    CheckoutSize();
            void        Commit( uint32_t size );

        private:

            RenderRing( uint32_t size );

            ~RenderRing();

            std::mutex                  m_Mutex;
            std::unique_ptr<uint32_t[]> m_pBuffer;
            uint32_t                    m_Head;
            uint32_t                    m_Tail;
            uint32_t                    m_MaxSize;
            bool                        m_IsFull;
        };
    }
}