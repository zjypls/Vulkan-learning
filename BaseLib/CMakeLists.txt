cmake_minimum_required(VERSION 3.15)

project(BaseLib)

file(GLOB srcs *.cpp *.h)

add_library(${PROJECT_NAME} STATIC ${srcs})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty ${VK_HEADER})
target_link_libraries(${PROJECT_NAME} PUBLIC vulkan-1)