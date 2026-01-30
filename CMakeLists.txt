cmake_minimum_required(VERSION 3.15)
project(Practices)

set(CMAKE_CXX_STANDARD 17)

# Кодировка для Windows
if (MSVC)
    add_compile_options(/utf-8)
endif()

# Quest 33.5 - основная программа
add_executable(Quest_33_5 
    Quest_33_5/src/main.cpp
    Quest_33_5/task1_cart.cpp
    Quest_33_5/task2_fishing.cpp
    Quest_33_5/task3_registry.cpp
    Quest_33_5/task4_average.cpp
)

# Отдельные задания
add_executable(task1_cart Quest_33_5/task1_cart.cpp)
add_executable(task2_fishing Quest_33_5/task2_fishing.cpp)
add_executable(task3_registry Quest_33_5/task3_registry.cpp)
add_executable(task4_average Quest_33_5/task4_average.cpp)