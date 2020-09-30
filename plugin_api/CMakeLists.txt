project(plugin_api)

file(GLOB_RECURSE SRC include/*.hpp src/*.hpp src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC include PRIVATE src)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC})

target_compile_definitions(${PROJECT_NAME} PRIVATE PLUGIN_API_LIBRARY)
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()
