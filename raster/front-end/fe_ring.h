#pragma once

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Ring
        {
        public:
            using ptr_t = std::unique_ptr<Ring>;

            Ring( uint32_t size );
            ~Ring();

            uint32_t*   GetAddress();
            uint32_t    GetMaxSize() const;
            uint32_t    GetCommandCount() const;

            void        SetTail( uint32_t offset );

        private:
            std::vector<byte>   m_CommandBuffer;
            uint32_t            m_Tail;
            uint32_t            m_Head;
        };

        ////////////////////////////////////////////////////////////////////////////////
        class RenderRing
        {
        public:
            static RenderRing* Create( uint32_t count, uint32_t size );

            static void Destroy( RenderRing* &pRing );

            void            AdvanceWriteHead();
            void            AdvanceReadHead();

            void            WriteComplete();

            Ring::ptr_t&    GetRead();
            Ring::ptr_t&    GetWrite();

            bool            HasWork() const;

        private:

            RenderRing( uint32_t count, uint32_t size );

            ~RenderRing();

            std::mutex                          m_Mutex;
            std::vector<std::unique_ptr<Ring>>  m_Rings;

            uint32_t    m_WriteHead;
            uint32_t    m_ReadHead;
            uint32_t    m_ReadTail;
        };
    }
}