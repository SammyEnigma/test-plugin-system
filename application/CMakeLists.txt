project(application)

file(GLOB_RECURSE SRC src/*.cpp src/*.hpp)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} plugin_api)
target_include_directories(${PROJECT_NAME} PRIVATE src)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})
