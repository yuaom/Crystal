file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

# CrystalUmd Library
add_library( CrystalUmd STATIC ${_HEADERS} ${_SOURCES} )

# Include Directories
target_include_directories( CrystalUmd PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} )
target_include_directories( CrystalUmd PRIVATE ${WDK_PATHS} )
target_include_directories( CrystalUmd PRIVATE $<TARGET_PROPERTY:Raster,SOURCE_DIR> )
target_include_directories( CrystalUmd PRIVATE $<TARGET_PROPERTY:CrystalKmt,SOURCE_DIR> )
target_include_directories( CrystalUmd PRIVATE $<TARGET_PROPERTY:Common,SOURCE_DIR> )

# Target Properties
set_target_properties( CrystalUmd PROPERTIES FOLDER "Umd" )
set_target_properties( CrystalUmd PROPERTIES CXX_STANDARD 17 )
set_target_properties( CrystalUmd PROPERTIES CXX_STANDARD_REQUIRED ON )

# Linked Libraries & Dependencies
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

# DLL/Tests
add_subdirectory(dll)
add_subdirectory(tests)