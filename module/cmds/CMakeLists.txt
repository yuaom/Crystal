file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

foreach( src_file ${_SOURCES} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${_SOURCES} )

target_sources( Crystal PRIVATE ${_HEADERS} ${_SOURCES} )
target_include_directories(Crystal PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
