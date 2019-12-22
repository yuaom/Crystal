add_executable( Smoke Main.cpp )
target_link_libraries( Smoke d3d11.lib )
set_target_properties( Smoke PROPERTIES FOLDER "Samples")