cmake_minimum_required(VERSION 3.14)
project(video-playground C CXX)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glfw)
add_subdirectory(lib/FFmpeg)

add_definitions(-DGL_SILENCE_DEPRECATION)

if(APPLE)
    list(APPEND EXTRA_LIBS "-framework OpenGL")
endif()

list(APPEND SOURCES
  src/main.cpp
  src/load_frame.cpp
)
add_executable(video-playground ${SOURCES})
target_link_libraries(video-playground FFmpeg glfw ${EXTRA_LIBS})
