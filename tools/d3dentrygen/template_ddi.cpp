#include "pch.h"

% for entry in entries:
////////////////////////////////////////////////////////////////////////////////
void WINAPI ${entry.name}(
    % for i in range(len(entry.params)):
    <%
        param_type,param_name = entry.params[i]
    %>${param_type} ${param_name}\
        %if i < len(entry.params)-1:
,
        %endif
    % endfor
 )
{
    LOG_DLL_ENTRY;
}

% endfor