cmake_minimum_required( VERSION 3.16.0 )
project( Crystal )

# Module headers / source
set( MODULE_HEADERS
	module/pch.h
	module/dllmain.h
	module/entrypoints.h )

set( MODULE_SOURCE 
	module/dllmain.cpp
	module/entrypoints.cpp )

source_group( "PCH" FILES 
	module/pch.cpp
	module/pch.h )

source_group( "Source" FILES
	module/dllmain.h
	module/dllmain.cpp
	module/entrypoints.h
	module/entrypoints.cpp )

# Precompiled Header
set_source_files_properties( module/pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )
foreach( src_file ${MODULE_SOURCE} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${MODULE_SOURCE} )
list(APPEND MODULE_SOURCE module/pch.cpp )

# Crystal DLL
add_library( Crystal SHARED ${MODULE_SOURCE} ${MODULE_HEADERS} )