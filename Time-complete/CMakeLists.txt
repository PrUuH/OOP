cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
option(BUILD_TESTS "Build the tests" OFF) # разобраться - cmake -S. -Bbuild -DBUILD_TESTS=ON и соотв. cmake -S. -Bbuild -DBUILD_TESTS=OFF

# Добавляем библиотеку time
add_library(time time.cpp)

# Добавляем исполняемый файл для основной программы
add_executable(time_executable time.cpp)

# Если включены тесты, добавляем их
if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Добавляем тестовое приложение
    add_executable(time_test test_time.cpp)

    # Связываем тестовое приложение с библиотекой и GoogleTest
    target_link_libraries(time_test PRIVATE time GTest::gtest_main)

    # Находим тесты
    include(GoogleTest)
    gtest_discover_tests(time_test)
endif()

# Связываем основное приложение с библиотекой time
target_link_libraries(time_executable PRIVATE time)