file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalUmdDll Library
add_library( CrystalUmdDLL SHARED ${_HEADERS} ${_SOURCES} exports.def )

# Include Directories

# Target Properties
set_target_properties( CrystalUmdDLL PROPERTIES OUTPUT_NAME "CrystalUmd64" )
set_target_properties( CrystalUmdDLL PROPERTIES FOLDER "Umd")
set_target_properties( CrystalUmdDLL PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalUmdDLL PROPERTIES CXX_STANDARD_REQUIRED ON )

# Linked Libraries & Dependencies
target_link_libraries( CrystalUmdDLL PUBLIC $<TARGET_LINKER_FILE:CrystalUmd> )
target_link_libraries( CrystalUmdDLL PUBLIC $<TARGET_LINKER_FILE:Common> )
target_link_libraries( CrystalUmdDLL PUBLIC $<TARGET_LINKER_FILE:GMM> )

add_dependencies( CrystalUmdDLL CrystalUmd )
add_dependencies( CrystalUmdDLL Common )
add_dependencies( CrystalUmdDLL GMM )

# Sub-directories

# Folder Filters
get_target_property( CRYSTALUMDDLL_FILES CrystalUmdDLL SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALUMDDLL_FILES} )
