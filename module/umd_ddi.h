#pragma once

namespace Crystal
{
	namespace UMD
	{
		void APIENTRY CheckCounterInfo(
			D3D10DDI_HDEVICE, _Out_ D3D10DDI_COUNTER_INFO* );
		void APIENTRY CheckMultisampleQualityLevels(
			D3D10DDI_HDEVICE, DXGI_FORMAT, UINT, _Out_ UINT* );
		void APIENTRY CheckFormatSupport(
			D3D10DDI_HDEVICE, DXGI_FORMAT, _Out_ UINT* );
	}
}