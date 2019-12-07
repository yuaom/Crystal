#include "pch.h"
#include "display.h"

namespace Crystal
{
	////////////////////////////////////////////////////////////////////////////////
	/// @brief Constructs a display device from a descriptor and pin source
	/// @input desc display device desc
	/// @input VidPinSourceId vid pin source id
	Displays::Display::Display( 
		const DISPLAY_DEVICEW& desc, 
		uint32_t VidPinSourceId )
	{
		m_DeviceName		= std::wstring( desc.DeviceName );
		m_Desc				= desc;
		m_hMonitor			= NULL;
		m_VidPinSourceId	= VidPinSourceId;
	}

	////////////////////////////////////////////////////////////////////////////////
	const std::wstring& Displays::Display::GetDeviceName() const
	{
		return m_DeviceName;
	}

	////////////////////////////////////////////////////////////////////////////////
	uint32_t Displays::Display::GetVidPinSourceId() const
	{
		return m_VidPinSourceId;
	}

	////////////////////////////////////////////////////////////////////////////////
	void Displays::Display::SetMonitor( HMONITOR monitor )
	{
		m_hMonitor = monitor;
	}

	////////////////////////////////////////////////////////////////////////////////
	Displays::Displays()
	{
		DISPLAY_DEVICEW displayDesc = { 0 };
		displayDesc.cb = sizeof( DISPLAY_DEVICEW );
		uint32_t i = 0;
		while( EnumDisplayDevicesW( nullptr, i, &displayDesc, 0 ) )
		{
			m_Displays.emplace_back( displayDesc, i++ );
		}

		EnumDisplayMonitors( 
			nullptr, 
			nullptr, 
			MonitorEnumProc, 
			reinterpret_cast<LPARAM>( this ) );
	}

	////////////////////////////////////////////////////////////////////////////////
	Displays::~Displays()
	{

	}

	////////////////////////////////////////////////////////////////////////////////
	BOOL Displays::MonitorEnumProc( HMONITOR hMon, HDC hdc, LPRECT pRect, LPARAM lParam )
	{
		Displays* pDisplays = reinterpret_cast<Displays*>( lParam );

		MONITORINFOEXW mi;
		mi.cbSize = sizeof( mi );
		if( !GetMonitorInfoW( hMon, reinterpret_cast<MONITORINFO*>( &mi ) ) )
		{
			return FALSE;
		}
		else
		{
			for( auto& current : pDisplays->m_Displays )
			{
				if( current.GetDeviceName() == std::wstring( mi.szDevice ) )
				{
					current.SetMonitor( hMon );
				}
			}
		}

		return TRUE;
	}

	////////////////////////////////////////////////////////////////////////////////
	bool Displays::FindByName( 
		const std::wstring& name, 
		std::vector<Display>::iterator& out )
	{
		out = std::find_if(
			std::begin( m_Displays ), 
			std::end( m_Displays ), 
			[&name]( const Display& display )
			{
				return display.GetDeviceName() == name;
			}
		);

		return out != std::end( m_Displays );
	}
}