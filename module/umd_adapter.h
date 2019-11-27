#pragma once

namespace Crystal
{
	namespace UMD
	{
#pragma region Adapter

		////////////////////////////////////////////////////////////////////////////////
		class Adapter
		{
		public:

			static void Create( D3D10DDIARG_OPENADAPTER* pOpenAdapter );

			static void Destroy( D3D10DDI_HADAPTER hAdapter );

			static Adapter* FromHandle( D3D10DDI_HADAPTER handle );

			const std::vector<uint64_t>& Adapter::GetSupportedVersions() const;

			// GetCaps Interfaces
			template< typename CapsT >	HRESULT GetCaps( CapsT ) const;
			template<>					HRESULT GetCaps( D3D11DDI_THREADING_CAPS* pThreading ) const;
			template<>					HRESULT GetCaps( D3D11DDI_3DPIPELINESUPPORT_CAPS* pPipelineSupport ) const;
			template<>					HRESULT GetCaps( D3D11DDI_SHADER_CAPS* pShader ) const;

		private:
			Adapter( D3D10DDIARG_OPENADAPTER* pOpenAdapter );

			~Adapter();

			D3D10DDI_HRTADAPTER		m_hRuntimeHandle;
			UINT					m_Interface;
			UINT					m_Version;
			std::vector<uint64_t>	m_SupportedVersions;

			D3DDDI_ADAPTERCALLBACKS	m_AdapterCallbacks;
		};

		////////////////////////////////////////////////////////////////////////////////
		template< typename CapsT >
		HRESULT Adapter::GetCaps( CapsT ) const
		{
			assert( 0 );
			return E_NOTIMPL;
		}

		////////////////////////////////////////////////////////////////////////////////
		template<>
		HRESULT Adapter::GetCaps( D3D11DDI_THREADING_CAPS* pThreading ) const
		{
			pThreading->Caps = 0;
			return S_OK;
		}

		////////////////////////////////////////////////////////////////////////////////
		template<>
		HRESULT Adapter::GetCaps( D3D11DDI_3DPIPELINESUPPORT_CAPS* pPipelineSupport ) const
		{
			pPipelineSupport->Caps =
				D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( D3D11DDI_3DPIPELINELEVEL_10_0 ) |
				D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( D3D11DDI_3DPIPELINELEVEL_10_1 ) |
				D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( D3D11DDI_3DPIPELINELEVEL_11_0 ) |
				D3D11DDI_ENCODE_3DPIPELINESUPPORT_CAP( D3D11_1DDI_3DPIPELINELEVEL_11_1 );
			return S_OK;
		}

		////////////////////////////////////////////////////////////////////////////////
		template<>
		HRESULT Adapter::GetCaps( D3D11DDI_SHADER_CAPS* pShaders ) const
		{
			// Don't currently support any shader extended features
			pShaders->Caps = 0;
			return S_OK;
		}

#pragma endregion
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY CloseAdapter( D3D10DDI_HADAPTER hAdapter );

#pragma endregion
	}
}