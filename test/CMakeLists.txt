#find_package(GTest REQUIRED)

add_executable(TestTest TestTest.cpp ..//big_integer.h ..//big_integer.cpp)

target_link_libraries(TestTest gtest gtest_main)


add_test(
        NAME TestTest
        COMMAND $<TARGET_FILE:${TestTest}> --gtest_output=xml:${CMAKE_BINARY_DIR}/test_results/TestTest.xml
)
