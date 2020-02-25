# Add all source files
file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalKmt DLL
add_library( CrystalKmt SHARED ${_HEADERS} ${_SOURCES} exports.def )
target_include_directories( CrystalKmt PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${WDK_KM} $<TARGET_PROPERTY:Raster,SOURCE_DIR> )

# CrystalKmt DLL Properties
set_target_properties( CrystalKmt PROPERTIES OUTPUT_NAME "CrystalKmt64" )
set_target_properties( CrystalKmt PROPERTIES FOLDER "kmt" )
set_target_properties( CrystalKmt PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalKmt PROPERTIES CXX_STANDARD_REQUIRED ON )

# Dependencies
target_link_libraries( CrystalKmt PUBLIC $<TARGET_FILE:Common> )
target_link_libraries( CrystalKmt PUBLIC $<TARGET_FILE:GMM> )
add_dependencies( CrystalKmt Common )
add_dependencies( CrystalKmt GMM )

# Sub-directories
add_subdirectory(ddi)
add_subdirectory(objects)

# Folder Filters
get_target_property( CRYSTALKMTDLL_FILES CrystalKmt SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALKMTDLL_FILES} )

# PCH
foreach( src_file ${CRYSTALKMTDLL_FILES} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${CRYSTALKMTDLL_FILES} )
set_source_files_properties( pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )