file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

add_executable( Tests ${_HEADERS} ${_SOURCES} )
target_link_libraries( Tests gtest_main )
set_target_properties( Tests PROPERTIES FOLDER "Tests")

get_target_property( CRYSTAL_TESTS_FILES Tests SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_TESTS_FILES} )