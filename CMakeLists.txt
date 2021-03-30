cmake_minimum_required(VERSION 3.14)
project(video-playground C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)

add_definitions(-DGL_SILENCE_DEPRECATION)

add_executable(video-playground src/main.cpp)
target_link_libraries(video-playground glfw)

if(APPLE)
    target_link_libraries(video-playground "-framework OpenGL")
endif()
