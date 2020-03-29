#include "pch.h"
#include "umd_adapter.h"
#include "umd_device.h"
#include "umd_caps.h"

namespace Crystal
{
    namespace UMD
    {
#pragma region Adapter
        ////////////////////////////////////////////////////////////////////////////////
        void Adapter::Create( D3D10DDIARG_OPENADAPTER* pOpenAdapter )
        {
            Adapter* pAdpater = new Adapter( pOpenAdapter );

            pOpenAdapter->hAdapter = MAKE_D3D10DDI_HADAPTER( pAdpater );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Adapter::Destroy( D3D10DDI_HADAPTER hAdapter )
        {
            Adapter* pAdapter = FromHandle( hAdapter );
            delete pAdapter;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Adapter* Adapter::FromHandle( D3D10DDI_HADAPTER handle )
        {
            return reinterpret_cast<Adapter*>( handle.pDrvPrivate );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Adapter::Adapter( D3D10DDIARG_OPENADAPTER* pOpenAdapter ) :
            m_hRuntimeHandle( pOpenAdapter->hRTAdapter ),
            m_Interface( pOpenAdapter->Interface ),
            m_Version( pOpenAdapter->Version )
        {
            memcpy_s(
                &m_AdapterCallbacks,
                sizeof( D3DDDI_ADAPTERCALLBACKS ),
                pOpenAdapter->pAdapterCallbacks,
                sizeof( D3DDDI_ADAPTERCALLBACKS ) );

            m_SupportedVersions = {
                D3DWDDM1_3_DDI_SUPPORTED
            };

            pOpenAdapter->pAdapterFuncs_2->pfnCalcPrivateDeviceSize = UMD::CalcPrivateDeviceSize;
            pOpenAdapter->pAdapterFuncs_2->pfnCreateDevice          = UMD::CreateDevice;
            pOpenAdapter->pAdapterFuncs_2->pfnCloseAdapter          = UMD::CloseAdapter;
            pOpenAdapter->pAdapterFuncs_2->pfnGetCaps               = UMD::GetCaps;
            pOpenAdapter->pAdapterFuncs_2->pfnGetSupportedVersions  = UMD::GetSupportedVersions;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Adapter::~Adapter()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the supported API versions
        const std::vector<uint64_t>& Adapter::GetSupportedVersions() const
        {
            return m_SupportedVersions;
        }

#pragma endregion
#pragma region DDI Entrypoints

        ////////////////////////////////////////////////////////////////////////////////
        HRESULT APIENTRY CloseAdapter( D3D10DDI_HADAPTER hAdapter )
        {
            LOG_DLL_ENTRY;

            Adapter::Destroy( hAdapter );

            return S_OK;
        }

#pragma endregion

    } // namespace UMD
} // namespace Crystal