set( MODULE_HEADERS	dllmain.h )
set( MODULE_SOURCE dllmain.cpp )

# Crystal DLL
add_library( Crystal SHARED ${MODULE_SOURCE} ${MODULE_HEADERS} exports.def )
target_include_directories(Crystal PRIVATE ${WDK_KM} )
set_target_properties( Crystal PROPERTIES FOLDER "Crystal")
set_property(TARGET Crystal PROPERTY CXX_STANDARD 17)
set_property(TARGET Crystal PROPERTY CXX_STANDARD_REQUIRED ON)

# Sub-directories
add_subdirectory(pch)
add_subdirectory(umd)
add_subdirectory(kmd)

get_target_property( CRYSTAL_FILES Crystal SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_FILES} )