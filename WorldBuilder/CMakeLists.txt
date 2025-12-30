add_library(WorldBuilder 
    src/core/worldbuilder.cpp
    src/core/passgenerators/passobject.cpp
    src/core/passgenerators/poissonplate.cpp
    src/core/passgenerators/passtranslator.cpp
)

target_include_directories(WorldBuilder PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
