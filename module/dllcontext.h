#pragma once
#include "log.h"
#include "debugvars.h"

namespace Crystal
{
	struct DllContext
	{
	public:
		using ptr_t = std::unique_ptr<DllContext>;

		DllContext::DllContext();

		DllContext::~DllContext();

		static void OnDllProcessAttach();

		static void OnDllProcessDetach();

		static ptr_t& get();

		std::unique_ptr<Log>&				getLog();
		std::unique_ptr<DebugVariables>&	getDebugVars();

	private:
		static std::unique_ptr<DllContext>	m_pContext;

		std::unique_ptr<DebugVariables>	m_pDebugVars;
		std::unique_ptr<Log>			m_pLog;
	};
}