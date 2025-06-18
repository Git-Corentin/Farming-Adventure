#
# Lines inspired by https://google.github.io/googletest/quickstart-cmake.html
#

# Note: include(GoogleTest)and enable_testing() already done in top CMakeLists.txt

add_executable(unitTests
  unitTests.cpp
)
target_link_libraries(unitTests GTest::gtest_main lib_core pugixml sfml-graphics)

add_custom_target(copy_test_resources ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/res)
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/res
                  DEPENDS ${CMAKE_SOURCE_DIR}/res
                  COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
                            ${CMAKE_SOURCE_DIR}/res
                            ${CMAKE_CURRENT_BINARY_DIR}/res
                  COMMENT "Copying resource files for unit tests")
add_dependencies(unitTests copy_test_resources)
# The next two lines enable CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(unitTests)

