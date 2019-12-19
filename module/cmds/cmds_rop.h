#pragma once

namespace Crystal
{
    namespace Commands
    {
        struct CLEAR_RENDER_TARGET_VIEW
        {
            void Init()
            {
                Type = 0x1; // todo: replace with enum command type;
            }

            uint32_t        Type;
            D3DKMT_HANDLE   hAllocation;
            float           ClearValues[4];
        };
    }
}