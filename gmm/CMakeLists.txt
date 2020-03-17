# GMM Library
file(GLOB _HEADERS "*.h")
file(GLOB _SOURCE "*.cpp")

add_library( GMM STATIC ${_HEADERS} ${_SOURCE} )

target_include_directories( GMM PRIVATE ${WDK_KM} )

set_target_properties( GMM PROPERTIES FOLDER "Common")
set_target_properties( GMM PROPERTIES CXX_STANDARD 17)
set_target_properties( GMM PROPERTIES CXX_STANDARD_REQUIRED ON)

get_target_property( CRYSTAL_GMM_FILES GMM SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTAL_GMM_FILES} )