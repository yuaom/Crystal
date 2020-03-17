# Raster Library
file(GLOB _HEADERS "*.h")
file(GLOB _SOURCE "*.cpp")
add_library( Raster STATIC ${_HEADERS} ${_SOURCE} )
set_target_properties( Raster PROPERTIES FOLDER "Raster")
set_target_properties( Raster PROPERTIES CXX_STANDARD 17)
set_target_properties( Raster PROPERTIES CXX_STANDARD_REQUIRED ON)

add_subdirectory(pch)
add_subdirectory(cmds)
add_subdirectory(front-end)
add_subdirectory(device)

get_target_property( CRYSTALRASTER_FILES Raster SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALRASTER_FILES} )

# Raster Dll/Tests
add_subdirectory(dll)
add_subdirectory(tests)
