#pragma once

struct Log
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

#define LOG_DLL_ENTRY	Crystal::DllContext::get()->getLog()->Message( Log::MESSAGE_DLL_ENTRY, __FUNCTION__ )