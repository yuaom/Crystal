#pragma once
#include "log.h"
#include "debugvars.h"
#include "display.h"

namespace Crystal
{
	class DllContext
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
		std::unique_ptr<Displays>&			getDisplays();

	private:
		static std::unique_ptr<DllContext>	m_pContext;

		std::unique_ptr<DebugVariables>	m_pDebugVars;
		std::unique_ptr<Log>			m_pLog;

		std::unique_ptr<Displays>		m_pDisplays;
	};
}