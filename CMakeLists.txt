cmake_minimum_required( VERSION 3.16.0 )
set_property( GLOBAL PROPERTY USE_FOLDERS ON )
project( Crystal )

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

# Add projects
add_subdirectory( module )
add_subdirectory( samples/smoke )