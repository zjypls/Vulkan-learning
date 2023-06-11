cmake_minimum_required(VERSION 3.15)


project(Test)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${VK_HEADER} ${CMAKE_SOURCE_DIR}/BaseLib)
target_link_libraries(${PROJECT_NAME} PUBLIC vulkan-1 sdl2 BaseLib)