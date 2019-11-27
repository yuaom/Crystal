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

		private:
			Adapter( D3D10DDIARG_OPENADAPTER* pOpenAdapter );

			~Adapter();

			D3D10DDI_HRTADAPTER	m_hRuntimeHandle;
			UINT				m_Interface;
			UINT				m_Version;

			D3DDDI_ADAPTERCALLBACKS	m_AdapterCallbacks;
		};

#pragma endregion
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY CloseAdapter( D3D10DDI_HADAPTER hAdapter );

#pragma endregion
	}
}