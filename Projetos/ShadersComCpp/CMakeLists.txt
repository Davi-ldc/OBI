cmake_minimum_required(VERSION 3.15)
project(ShadersComCpp)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 17)

add_executable(ShadersComCpp main.cpp)

find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

target_link_libraries(ShadersComCpp PRIVATE 
    SDL2::SDL2main
    SDL2::SDL2
    glad::glad
)

# Isso aqui resolve o problema do linker
set_target_properties(ShadersComCpp PROPERTIES
    WIN32_EXECUTABLE TRUE
)

file(COPY vertex.glsl DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY fragment.glsl DESTINATION ${CMAKE_CURRENT_BINARY_DIR})