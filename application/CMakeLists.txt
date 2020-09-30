project(application)

file(GLOB_RECURSE CPP_SRC src/*.cpp)
file(GLOB_RECURSE CPP_INC src/*.hpp)

add_executable(${PROJECT_NAME} ${CPP_SRC} ${CPP_INC})
target_link_libraries(${PROJECT_NAME} plugin_api)
target_include_directories(${PROJECT_NAME} PRIVATE src)

if(MSVC)
    #set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
