cmake_minimum_required(VERSION 3.15)
project(Quest_32_5)

set(CMAKE_CXX_STANDARD 17)

# JSON library
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# Main program
add_executable(${PROJECT_NAME} Quest_32_5/main.cpp)

# Link JSON
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Copy JSON files
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/Quest_32_5/movies.json
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMENT "Copying movies.json"
)