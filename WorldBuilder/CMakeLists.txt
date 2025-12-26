add_library(WorldBuilder 
    src/core/WorldBuilder.cpp
)

target_include_directories(WorldBuilder PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
