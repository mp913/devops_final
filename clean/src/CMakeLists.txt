cmake_minimum_required(VERSION 3.2)
project(CalculatorProject)

# use C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# use Boost.Program_options
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${BOOST_INCLUDE_DIRS})

# add executable file
add_executable(cpp_calculator_app main.cpp Calculator.h Calculator.cpp)
target_link_libraries(cpp_calculator_app ${Boost_LIBRARIES})