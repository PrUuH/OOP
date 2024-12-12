cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(main main.cpp)

add_executable(main_test test.cpp)

# Link your test executable with your main library and GoogleTest
target_link_libraries(main_test PRIVATE main GTest::gtest_main)

# Указываем директорию для исполняемых файлов
set_target_properties(main_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

# Discover and run your tests
include(GoogleTest)
gtest_discover_tests(main_test)