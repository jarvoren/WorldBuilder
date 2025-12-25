add_executable(WorldBuilderTester 
    src/main.cpp
)

target_link_libraries(WorldBuilderTester PRIVATE WorldBuilder)

target_include_directories(WorldBuilderTester PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
