#pragma once

struct Log
{
public:
	enum MESSAGE_TYPE
	{
		MESSAGE_DLL_ENTRY
	};

	static void OnDllProcessAttach();

	static void OnDllProcessDetach();

	static void Message( MESSAGE_TYPE type, const char* str );

private:

	static std::unique_ptr<Log>	m_pLog;
};

#define LOG_DLL_ENTRY	Log::Message( Log::MESSAGE_DLL_ENTRY, __FUNCTION__ )