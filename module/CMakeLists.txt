# Crystal LIB
add_library( Crystal STATIC )
target_include_directories( Crystal PRIVATE ${WDK_KM} $<TARGET_PROPERTY:Raster,SOURCE_DIR> )
set_target_properties( Crystal PROPERTIES FOLDER "Crystal")
set_target_properties( Crystal PROPERTIES CXX_STANDARD 17)
set_target_properties( Crystal PROPERTIES CXX_STANDARD_REQUIRED ON)

# Sub-directories
add_subdirectory(pch)
add_subdirectory(umd)
add_subdirectory(kmd)
add_subdirectory(gmm)

get_target_property( CRYSTAL_FILES Crystal SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_FILES} )

# Crystal DLL
add_library( CrystalDLL SHARED dllmain.h dllmain.cpp exports.def )
set_target_properties( CrystalDLL PROPERTIES OUTPUT_NAME "Crystal64" )
set_target_properties( CrystalDLL PROPERTIES FOLDER "Crystal")
set_target_properties( CrystalDLL PROPERTIES CXX_STANDARD 17)
set_target_properties( CrystalDLL PROPERTIES CXX_STANDARD_REQUIRED ON)

get_target_property( CRYSTALDLL_FILES CrystalDLL SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALDLL_FILES} )
target_link_libraries( CrystalDLL PUBLIC $<TARGET_FILE:Crystal> )
add_dependencies( CrystalDLL Crystal )

# Copy include directories from the Cyrstal LIB
get_target_property(CRYSTAL_INCLUDES Crystal INCLUDE_DIRECTORIES )
target_include_directories(CrystalDLL PRIVATE ${CRYSTAL_INCLUDES} )