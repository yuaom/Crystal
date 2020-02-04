#pragma once

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Ring
        {
        public:
            Ring( uint32_t size );
            ~Ring();

            void*       GetAddress() const;
            uint32_t    GetMaxSize() const;

            void        SetTail( uint32_t offset );

        private:
            std::unique_ptr<uint32_t[]> m_CommandBuffer;
            uint32_t                    m_Tail;
            uint32_t                    m_Head;
            uint32_t                    m_MaxSize;
        };

        ////////////////////////////////////////////////////////////////////////////////
        class RenderRing
        {
        public:
            static RenderRing* Create( uint32_t count, uint32_t size );

            static void Destroy( RenderRing* &pRing );

            void                    AdvanceProducer();
            std::unique_ptr<Ring>&  GetProducerRing();
            void                    ProducerDone();

            void                    AdvanceConsumerHead();
            bool                    IsEmpty() const;
            std::unique_ptr<Ring>&  GetConsumerRing();

        private:

            RenderRing( uint32_t count, uint32_t size );

            ~RenderRing();

            std::mutex                          m_Mutex;
            std::vector<std::unique_ptr<Ring>>  m_Rings;

            uint32_t    m_ProducerHead;
            uint32_t    m_ConsumerHead;
            uint32_t    m_ConsumerTail;
        };
    }
}