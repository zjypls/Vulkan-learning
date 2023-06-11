cmake_minimum_required(VERSION 3.15)

project(VulkanLearning)

set(VK_HEADER $ENV{VK_SDK_PATH}/Include)
set(VK_LIB $ENV{VK_SDK_PATH}/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Bin)
link_directories(${VK_LIB})

add_subdirectory(thirdparty)
add_subdirectory(BaseLib)
add_subdirectory(src)