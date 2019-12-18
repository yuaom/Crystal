file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

add_executable( Benchmarks ${_HEADERS} ${_SOURCES} )
target_link_libraries( Benchmarks benchmark_main )
set_target_properties( Benchmarks PROPERTIES FOLDER "Tests")

get_target_property( CRYSTAL_BENCHMARK_FILES Benchmarks SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_BENCHMARK_FILES} )