cmake_minimum_required( VERSION 3.16.0 )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
project( Crystal )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release)

# WDK
if( NOT DEFINED WDK )
	message( FATAL_ERROR "WDK Undefined! Please use -DWDK=<path> to define the WDK install path." )
endif( NOT DEFINED WDK )

set( WDK_KM ${WDK}\\km )

message( STATUS "" )
message( STATUS "WDK Setup:")
message( STATUS "    WDK=${WDK}")
message( STATUS " WDK_KM=${WDK_KM}")
message( STATUS "" )

# Add testing projects
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(google/benchmark)
add_subdirectory(google/googletest/googletest)
set_target_properties( benchmark PROPERTIES FOLDER "Tests//Google")
set_target_properties( benchmark_main PROPERTIES FOLDER "Tests//Google")
set_target_properties( gtest PROPERTIES FOLDER "Tests//Google")
set_target_properties( gtest_main PROPERTIES FOLDER "Tests//Google")

# Add projects
add_subdirectory( common )
add_subdirectory( gmm )
add_subdirectory( kmt )
add_subdirectory( umd )
add_subdirectory( benchmarks )
add_subdirectory( raster )
add_subdirectory( samples/smoke )