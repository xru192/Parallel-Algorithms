project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run AddTwoIntegersAlgorithmTest.cpp
        AddThreeIntegersAlgorithmTest.cpp
        UtilsTest.cpp
        googletest/MultiplyTwoIntegersAlgorithm.cpp)

target_link_libraries(Google_Tests_run Algorithms_lib)
target_link_libraries(Google_Tests_run gtest gtest_main)
