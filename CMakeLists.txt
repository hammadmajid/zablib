cmake_minimum_required(VERSION 3.10)

project(zablib VERSION 1.0.0)
set(PROJECT_DESCRIPTION "A header-only C++ libra")
set(PROJECT_LICENSE "MIT License")
set(PROJECT_HOMEPAGE_URL "https://github.com/hammadmajid/mee")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add library target
add_library(zablib INTERFACE)

# Specify the include directories
target_include_directories(zablib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Find GTest package
find_package(GTest REQUIRED)

# Testing setup
enable_testing()
add_executable(test_zablib tests/test_zablib.cpp)
target_include_directories(test_zablib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(test_zablib PRIVATE zablib GTest::GTest GTest::Main)
add_test(NAME zablib_test COMMAND test_zablib)

# Installation setup
install(TARGETS zablib EXPORT zablibTargets)
install(EXPORT zablibTargets
    FILE zablibTargets.cmake
    NAMESPACE zablib::
    DESTINATION lib/cmake/zablib
)
install(DIRECTORY include/ DESTINATION include)
