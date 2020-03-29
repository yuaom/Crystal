file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalKmtDLL Library
add_library( CrystalKmtDLL SHARED ${_HEADERS} ${_SOURCES} exports.def )

# Include Directories
target_include_directories( CrystalKmtDLL PRIVATE $<TARGET_PROPERTY:Common,SOURCE_DIR> )
target_include_directories( CrystalKmtDLL PRIVATE $<TARGET_PROPERTY:CrystalKmt,SOURCE_DIR> )
target_include_directories( CrystalKmtDLL PRIVATE ${WDK_KM} )
target_include_directories( CrystalKmtDLL PRIVATE $<TARGET_PROPERTY:Raster,SOURCE_DIR> )

# Target Properties
set_target_properties( CrystalKmtDLL PROPERTIES OUTPUT_NAME "CrystalKmt64" )
set_target_properties( CrystalKmtDLL PROPERTIES FOLDER "Kmt")
set_target_properties( CrystalKmtDLL PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalKmtDLL PROPERTIES CXX_STANDARD_REQUIRED ON )

# Linked Libraries & Dependencies
target_link_libraries( CrystalKmtDLL PUBLIC $<TARGET_LINKER_FILE:CrystalKmt> )
target_link_libraries( CrystalKmtDLL PUBLIC $<TARGET_LINKER_FILE:Common> )
# target_link_libraries( CrystalKmtDLL PUBLIC $<TARGET_LINKER_FILE:GMM> )

add_dependencies( CrystalKmtDLL CrystalKmt )
add_dependencies( CrystalKmtDLL Common )
# add_dependencies( CrystalKmtDLL GMM )

# Sub-directories

# Folder Filters
get_target_property( CRYSTALKMT_FILES CrystalKmtDLL SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALKMT_FILES} )
