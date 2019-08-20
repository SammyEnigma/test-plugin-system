cmake_minimum_required(VERSION 3.14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

project(test-plugin-system)

add_subdirectory(application)
add_subdirectory(plugin_api)
add_subdirectory(plugin1)
add_subdirectory(plugin2)
