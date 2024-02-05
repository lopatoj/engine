cmake_minimum_required(VERSION 3.3)
project(engine)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Including GLFW
add_subdirectory(glfw)
include_directories(glfw/include)

# Including GLAD
include_directories(glad/include)

# including shaders
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCE_FILES main.cpp glad/src/glad.c
        window.cpp
        window.h
        shader.cpp
        shader.h)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})
