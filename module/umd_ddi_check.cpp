#include "pch.h"
#include "umd_ddi.h"

namespace Crystal
{
	namespace UMD
	{
		void APIENTRY CheckMultisampleQualityLevels(
			D3D10DDI_HDEVICE, DXGI_FORMAT, UINT, _Out_ UINT* )
		{
			LOG_DLL_ENTRY;
		}

		void APIENTRY CheckFormatSupport(
			D3D10DDI_HDEVICE, DXGI_FORMAT, _Out_ UINT* )
		{
			LOG_DLL_ENTRY;
		}

		void APIENTRY CheckCounterInfo(
			D3D10DDI_HDEVICE, _Out_ D3D10DDI_COUNTER_INFO* )
		{
			LOG_DLL_ENTRY;
		}
	}
}