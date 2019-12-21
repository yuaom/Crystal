#pragma once
#include "umd_device.h"
#include "gmm.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Forward declarations
        struct Device;

        ////////////////////////////////////////////////////////////////////////////////
        class CommandBuffer
        {
        public:
            static CommandBuffer*   Create( Device* pDevice, uint32_t size );
            static CommandBuffer*   Create( size_t placement, uint32_t size, CommandBuffer* pExisting = nullptr );
            static void             Destroy( CommandBuffer* pCmdBuffer );

            byte*   GetSpace( uint32_t size );
            bool    HasSpace( uint32_t size ) const;
            size_t  GetAddress() const;

            constexpr uint32_t  SizeUsed() const;

        private:
            CommandBuffer( Device* pDevice = nullptr );

            ~CommandBuffer();

            void Allocate( uint32_t size );

            Device* m_pDevice;

            byte*       m_pBuffer;
            uint32_t    m_SizeTotal;
            uint32_t    m_SizeUsed;

            D3DKMT_HANDLE           m_AllocationHandle;
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
        };

        ////////////////////////////////////////////////////////////////////////////////
        constexpr uint32_t CommandBuffer::SizeUsed() const { return m_SizeUsed; };
    }
}