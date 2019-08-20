project(plugin2)

file(GLOB_RECURSE CPP_SRC src/*.cpp)
file(GLOB_RECURSE CPP_INC src/*.hpp)

add_library(${PROJECT_NAME} SHARED ${CPP_SRC} ${CPP_INC})
target_link_libraries(${PROJECT_NAME} plugin_api)
target_include_directories(${PROJECT_NAME} PRIVATE src)
