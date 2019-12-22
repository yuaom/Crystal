file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

add_executable( RasterTests ${_HEADERS} ${_SOURCES} )

target_link_libraries( RasterTests PUBLIC gtest_main $<TARGET_FILE:Raster> )
set_target_properties( RasterTests PROPERTIES FOLDER "Raster")
set_target_properties( RasterTests PROPERTIES CXX_STANDARD 17)
set_target_properties( RasterTests PROPERTIES CXX_STANDARD_REQUIRED ON)
add_dependencies( RasterTests Raster )

get_target_property( CRYSTALRASTER_TESTS_FILES RasterTests SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALRASTER_TESTS_FILES} )