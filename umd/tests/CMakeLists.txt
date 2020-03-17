file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalUmdTests Executable
add_executable( CrystalUmdTests ${_HEADERS} ${_SOURCES} )

# Include Directories
target_include_directories( CrystalUmdTests PRIVATE ${WDK_KM} )
target_include_directories( CrystalUmdTests PRIVATE $<TARGET_PROPERTY:CrystalUmd,SOURCE_DIR> )
target_include_directories( CrystalUmdTests PRIVATE $<TARGET_PROPERTY:Raster,SOURCE_DIR> )
target_include_directories( CrystalUmdTests PRIVATE $<TARGET_PROPERTY:Common,SOURCE_DIR> )

# Linked Libraries & Dependencies
target_link_libraries( CrystalUmdTests PUBLIC gtest_main )
target_link_libraries( CrystalUmdTests PUBLIC $<TARGET_LINKER_FILE:CrystalUmd> )
target_link_libraries( CrystalUmdTests PUBLIC $<TARGET_LINKER_FILE:Common> )
target_link_libraries( CrystalUmdTests PUBLIC $<TARGET_LINKER_FILE:GMM> )

add_dependencies( CrystalUmdTests CrystalUmd )
add_dependencies( CrystalUmdTests Common )
add_dependencies( CrystalUmdTests GMM )

# Target Properties
set_target_properties( CrystalUmdTests PROPERTIES FOLDER "Umd" )
set_target_properties( CrystalUmdTests PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalUmdTests PROPERTIES CXX_STANDARD_REQUIRED ON )

# Folder Filters
get_target_property( CRYSTALUMD_TESTS_FILES CrystalUmdTests SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALUMD_TESTS_FILES} )