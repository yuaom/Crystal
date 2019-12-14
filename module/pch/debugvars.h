#pragma once

namespace Crystal
{
    struct DebugVariables
    {
    public:
        struct Entry
        {
            enum TYPE
            {
                TYPE_BOOL,
                TYPE_UINT,
                TYPE_STRING
            };

            bool                                    m_IsSet;
            TYPE                                    m_Type;
            std::variant<uint32_t, std::wstring>    m_Value;

            Entry( const wchar_t* name, TYPE type );

            uint32_t        asUint32();
            std::wstring&   asString();

            bool            isSet();
        };

        static void OnDllProcessAttach();

        static void OnDllProcessDetach();

        DebugVariables();

        Entry    EnableLog;

        static std::unique_ptr<DebugVariables>& get();

    private:
        static std::unique_ptr<DebugVariables> m_pVars;
    };
}

#if defined(_DEBUG)
#define IS_DV_ENABLED( x )    Crystal::DebugVariables::get()->x.isSet()
#define DV_VALUE( x )         Crystal::DebugVariables::get()->x.asUint32()
#else
#define IS_DV_ENABLED( x )    false
#define DV_VALUE_UINT( x )    0
#endif