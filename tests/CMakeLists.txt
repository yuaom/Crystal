file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

add_executable( Tests ${_HEADERS} ${_SOURCES} )

# Link to gtest_main & crystal lib
target_link_libraries( Tests PUBLIC gtest_main $<TARGET_FILE:Crystal> )

# Put into Tests folder
set_target_properties( Tests PROPERTIES FOLDER "Tests")

# c++17
set_property(TARGET Tests PROPERTY CXX_STANDARD 17)
set_property(TARGET Tests PROPERTY CXX_STANDARD_REQUIRED ON)

# Copy include directories from the Cyrstal LIB
get_target_property(CRYSTAL_INCLUDES Crystal INCLUDE_DIRECTORIES )
target_include_directories(Tests PRIVATE ${CRYSTAL_INCLUDES} )

# Add dependency to Crystal lib
add_dependencies( Tests Crystal )

# Automatically sort into folders
get_target_property( CRYSTAL_TESTS_FILES Tests SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_TESTS_FILES} )