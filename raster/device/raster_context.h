#pragma once

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Context
        {
        public:
            static void Create();
            static void Destroy();

        private:
            Context();
            ~Context();
        };
    }
}