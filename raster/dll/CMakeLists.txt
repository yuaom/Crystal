file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

add_library( RasterDLL SHARED ${_HEADERS} ${_SOURCES} exports.def )

set_target_properties( RasterDLL PROPERTIES OUTPUT_NAME "CrystalRaster64" )
set_target_properties( RasterDLL PROPERTIES FOLDER "Raster")
set_target_properties( RasterDLL PROPERTIES CXX_STANDARD 17 )
set_target_properties( RasterDLL PROPERTIES CXX_STANDARD_REQUIRED ON )

get_target_property( CRYSTALRASTERDLL_FILES RasterDLL SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALRASTERDLL_FILES} )

target_link_libraries( RasterDLL PUBLIC $<TARGET_FILE:Common> )
target_link_libraries( RasterDLL PUBLIC $<TARGET_FILE:Raster> )

add_dependencies( RasterDLL Raster )
add_dependencies( RasterDLL Common )