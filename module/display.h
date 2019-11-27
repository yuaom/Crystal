#pragma once

namespace Crystal
{
	////////////////////////////////////////////////////////////////////////////////
	class Displays
	{
	public:

		////////////////////////////////////////////////////////////////////////////////
		class Display
		{
		public:
			Display( const DISPLAY_DEVICEW& desc, std::uint32_t VidPinSourceId );

			const std::wstring& GetDeviceName() const;
			std::uint32_t		GetVidPinSourceId() const;

			void				SetMonitor( HMONITOR monitor );

		private:
			std::wstring	m_DeviceName;
			DISPLAY_DEVICEW m_Desc;
			HMONITOR		m_hMonitor;
			std::uint32_t	m_VidPinSourceId;
		};

		////////////////////////////////////////////////////////////////////////////////
		using find_result_itr_t = std::vector<Display>::iterator;

		Displays();

		~Displays();

		bool FindByName( const std::wstring& name, find_result_itr_t& out );

	private:
		std::vector<Display>	m_Displays;

		static BOOL MonitorEnumProc( HMONITOR hMon, HDC hdc, LPRECT pRect, LPARAM lParam );
	};
}