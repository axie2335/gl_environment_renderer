cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

project(env_render)

add_executable(env_render src/main.cpp)
add_subdirectory(src)

find_package(SDL2 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_include_directories(env_render PUBLIC 
    ${SDL2_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS})

target_link_libraries(env_render PUBLIC
    ${SDL2_LIBRARIES}
    ${OpenCV_LIBS}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES})