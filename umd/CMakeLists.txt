# Add all source files
file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalUmd DLL
add_library( CrystalUmd SHARED ${_HEADERS} ${_SOURCES} exports.def )
target_include_directories( CrystalUmd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${WDK_KM} $<TARGET_PROPERTY:Raster,SOURCE_DIR> $<TARGET_PROPERTY:CrystalKmt,SOURCE_DIR> )

# CrystalUmd DLL Properties
set_target_properties( CrystalUmd PROPERTIES OUTPUT_NAME "CrystalUmd64" )
set_target_properties( CrystalUmd PROPERTIES FOLDER "umd" )
set_target_properties( CrystalUmd PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalUmd PROPERTIES CXX_STANDARD_REQUIRED ON )

# Dependencies
target_link_libraries( CrystalUmd PUBLIC $<TARGET_FILE:Common> )
target_link_libraries( CrystalUmd PUBLIC $<TARGET_FILE:GMM> )
add_dependencies( CrystalUmd Common )
add_dependencies( CrystalUmd GMM )

# Sub-directories
add_subdirectory(ddi)
add_subdirectory(views)
add_subdirectory(objects)

# Folder Filters
get_target_property( CRYSTALUMDDLL_FILES CrystalUmd SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALUMDDLL_FILES} )

# PCH
foreach( src_file ${CRYSTALUMDDLL_FILES} )
    set_source_files_properties( ${src_file} PROPERTIES COMPILE_FLAGS "/Yupch.h" )
endforeach( src_file ${CRYSTALUMDDLL_FILES} )
set_source_files_properties( pch.cpp PROPERTIES COMPILE_FLAGS "/Ycpch.h" )