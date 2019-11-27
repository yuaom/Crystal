#pragma once

namespace Crystal
{
	struct DebugVariables
	{
		struct Entry
		{
			enum TYPE
			{
				TYPE_BOOL,
				TYPE_UINT,
				TYPE_STRING
			};

			bool										m_IsSet;
			TYPE										m_Type;
			std::variant<uint32_t, std::wstring>	m_Value;

			Entry( const wchar_t* name, TYPE type );

			uint32_t	asUint32();
			std::wstring&	asString();

			bool			isSet();
		};

		DebugVariables();

		Entry	EnableLog;
	};
}

#if defined(_DEBUG)
#define IS_DV_ENABLED( x )	Crystal::DllContext::get()->getDebugVars()->x.isSet()
#define DV_VALUE( x )		Crystal::DllContext::get()->getDebugVars()->x.asUint32()
#else
#define IS_DV_ENABLED( x )	false
#define DV_VALUE_UINT( x )	0
#endif