# Common Library
file(GLOB _HEADERS "*.h")
file(GLOB _SOURCE "*.cpp")
add_library( Common STATIC ${_HEADERS} ${_SOURCE} )
set_target_properties( Common PROPERTIES FOLDER "Common")
set_target_properties( Common PROPERTIES CXX_STANDARD 17)
set_target_properties( Common PROPERTIES CXX_STANDARD_REQUIRED ON)

get_target_property( CRYSTALCOMMON_FILES Common SOURCES )
source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CRYSTALCOMMON_FILES} )