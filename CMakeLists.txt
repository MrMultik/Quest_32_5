cmake_minimum_required(VERSION 3.15)
project(Practices)

set(CMAKE_CXX_STANDARD 17)

# ---------- Quest 32.5 ----------
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# Полные пути к файлам
set(QUEST_32_5_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_32_5/main.cpp"
)

set(QUEST_33_5_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_33_5/src/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_33_5/task1_cart.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_33_5/task2_fishing.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_33_5/task3_registry.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Quest_33_5/task4_average.cpp"
)

add_executable(Quest_32_5 ${QUEST_32_5_SOURCES})
target_link_libraries(Quest_32_5 PRIVATE nlohmann_json::nlohmann_json)

add_executable(Quest_33_5 ${QUEST_33_5_SOURCES})