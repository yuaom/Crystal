file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalKmtTests Executable
add_executable( CrystalKmtTests ${_HEADERS} ${_SOURCES} )

# Include Directories
target_include_directories( CrystalKmtTests PRIVATE ${WDK_KM} )
target_include_directories( CrystalKmtTests PRIVATE $<TARGET_PROPERTY:CrystalKmt,SOURCE_DIR> )
target_include_directories( CrystalKmtTests PRIVATE $<TARGET_PROPERTY:Raster,SOURCE_DIR> )
target_include_directories( CrystalKmtTests PRIVATE $<TARGET_PROPERTY:Common,SOURCE_DIR> )

# Linked Libraries & Dependencies
target_link_libraries( CrystalKmtTests PUBLIC gtest_main )
target_link_libraries( CrystalKmtTests PUBLIC $<TARGET_LINKER_FILE:CrystalKmt> )
target_link_libraries( CrystalKmtTests PUBLIC $<TARGET_LINKER_FILE:Common> )
# target_link_libraries( CrystalKmtTests PUBLIC $<TARGET_LINKER_FILE:GMM> )

add_dependencies( CrystalKmtTests CrystalUmd )
add_dependencies( CrystalKmtTests Common )
# add_dependencies( CrystalKmtTests GMM )

# Target Properties
set_target_properties( CrystalKmtTests PROPERTIES FOLDER "Kmt" )
set_target_properties( CrystalKmtTests PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalKmtTests PROPERTIES CXX_STANDARD_REQUIRED ON )

# Folder Filters
get_target_property( CRYSTALKMT_TESTS_FILES CrystalKmtTests SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALKMT_TESTS_FILES} )