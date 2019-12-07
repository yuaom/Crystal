#pragma once

namespace Crystal
{
	class Log
	{
	public:

		enum MESSAGE_TYPE
		{
			MESSAGE_DLL_ENTRY
		};

		Log();
		~Log();

		void Message( MESSAGE_TYPE type, const char* str );
	};
}

#if defined(_DEBUG)
#define LOG_DLL_ENTRY	Crystal::DllContext::get()->getLog()->Message( Crystal::Log::MESSAGE_DLL_ENTRY, __FUNCTION__ )
#else
#define LOG_DLL_ENTRY
#endif