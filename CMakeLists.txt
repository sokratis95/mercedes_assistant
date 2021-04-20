cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(mercedes_assistant LANGUAGES CXX)

set(MAINFOLDER ${PROJECT_SOURCE_DIR})
list(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}")
list(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/tools")
list(APPEND CMAKE_PREFIX_PATH "${MAINFOLDER}/thirdparty")
set(CMAKE_MODULE_PATH "${MAINFOLDER}/tools/share/cmake")
set (CMAKE_CXX_FLAGS "-std=c++17")
set (CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN
    "-fsanitize=address -fno-optimize-sibling-calls -fsanitize-address-use-after-scope -fno-omit-frame-pointer -g -O1")

include(CompilerOptions)

add_executable(mercedes_assistant mercedes_assistant_main.cpp mercedes_assistant.cpp iohandler.cpp)

target_link_libraries(mercedes_assistant cpp_warnings)

option(with_test "Enables the test suite" ON)


if(with_test)
  include(FindLocalGTest)
  enable_testing()
  # create exacutables and
  # use add_test https://cmake.org/cmake/help/latest/command/add_test.html
  # also link with gtest, gtest_main  and cpp_warnings
 add_executable(mercedes_assistant_test mercedes_assistant.cpp mercedes_assistant.h iohandler.cpp iohandler.h mercedes_assistant_test.cpp)
 target_link_libraries(mercedes_assistant_test cpp_warnings gtest_main gtest)
  
  add_test(test mercedes_assistant_test)	

# Run the tests on every build
add_custom_target(testing_mercedes_assistant ALL DEPENDS mercedes_assistant_test COMMAND mercedes_assistant_test)
endif()  
