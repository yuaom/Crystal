# Module headers / source
set( MODULE_HEADERS
	pch.h
	dllmain.h
	entrypoints.h )

set( MODULE_SOURCE 
	dllmain.cpp
	entrypoints.cpp )

source_group( "PCH" FILES 
	pch.cpp
	pch.h )

source_group( "Source" FILES
	dllmain.h
	dllmain.cpp
	entrypoints.h
	entrypoints.cpp )

# Precompiled Header
set_source_files_properties( pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )
foreach( src_file ${MODULE_SOURCE} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${MODULE_SOURCE} )
list(APPEND MODULE_SOURCE pch.cpp )

# Crystal DLL
add_library( Crystal SHARED ${MODULE_SOURCE} ${MODULE_HEADERS} )
target_include_directories(Crystal PRIVATE ${WDK_KM})
set_target_properties( Crystal PROPERTIES FOLDER "Crystal")