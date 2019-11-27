#pragma once

namespace Crystal
{
	namespace UMD
	{
		SIZE_T APIENTRY CalcPrivateDeviceSize( D3D10DDI_HADAPTER hAdapter, const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcPrivateDeviceSize );
		HRESULT APIENTRY CreateDevice( D3D10DDI_HADAPTER hAdapter, D3D10DDIARG_CREATEDEVICE* pCreateDevice );
	}
}