set( PCH_HEADERS
	pch.h
	)

set( PCH_SOURCE 
	)

set_source_files_properties( pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )
foreach( src_file ${PCH_SOURCE} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${PCH_SOURCE} )
list( APPEND PCH_SOURCE pch.cpp )

target_sources( Raster PRIVATE ${PCH_SOURCE} ${PCH_HEADERS} )
target_include_directories( Raster PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )