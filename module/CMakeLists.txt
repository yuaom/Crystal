# Module headers / source
set( MODULE_HEADERS
	# PCH/DLL
	log.h
	dllcontext.h
	debugvars.h
	display.h
	pch.h
	dllmain.h

	# KMD
	kmd_adapter.h
	kmd_entrypoints.h 

	# UMD
	umd_exports.h
	umd_adapter.h
	umd_device.h
	umd_caps.h

	# UMD/DDI
	umd_ddi.h
	)

set( MODULE_SOURCE 
	# PCH/DLL
	log.cpp
	dllcontext.cpp
	debugvars.cpp
	display.cpp
	dllmain.cpp

	# KMD
	kmd_adapter.cpp
	kmd_entrypoints.cpp 

	# UMD
	umd_exports.cpp
	umd_adapter.cpp
	umd_device.cpp
	umd_caps.cpp

	# UMD/DDI
	umd_ddi_dynamic.cpp
	umd_ddi_check.cpp
	)

source_group( "PCH" FILES 
	debugvars.h
	debugvars.cpp
	pch.cpp
	pch.h
	log.cpp
	log.h
	)

# Project Filters
source_group( "Source" FILES
	display.h
	display.cpp
	dllcontext.h
	dllcontext.cpp
	dllmain.h
	dllmain.cpp
	)

source_group( "Source\\KMD" FILES
	kmd_adapter.h
	kmd_adapter.cpp
	kmd_entrypoints.h
	kmd_entrypoints.cpp
	)

source_group( "Source\\UMD" FILES
	umd_exports.h
	umd_exports.cpp
	umd_adapter.h
	umd_adapter.cpp
	umd_device.cpp
	umd_device.h
	umd_caps.h
	umd_caps.cpp
	)

source_group( "Source\\UMD\\DDI" FILES
	umd_ddi.h
	umd_ddi_dynamic.cpp
	umd_ddi_check.cpp
	)

# Precompiled Header
set_source_files_properties( pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )
foreach( src_file ${MODULE_SOURCE} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${MODULE_SOURCE} )
list(APPEND MODULE_SOURCE pch.cpp )

# Crystal DLL
add_library( Crystal SHARED ${MODULE_SOURCE} ${MODULE_HEADERS} exports.def )
target_include_directories(Crystal PRIVATE ${WDK_KM})
set_target_properties( Crystal PROPERTIES FOLDER "Crystal")
set_property(TARGET Crystal PROPERTY CXX_STANDARD 17)
set_property(TARGET Crystal PROPERTY CXX_STANDARD_REQUIRED ON)