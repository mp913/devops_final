cmake_minimum_required(VERSION 3.2)
project(DeaneryProject)

# use C++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# use Boost.Program_options
# set(Boost_USE_STATIC_LIBS ON)
# find_package(Boost COMPONENTS program_options REQUIRED)
# include_directories(${BOOST_INCLUDE_DIRS})

# executable files for app
add_executable(deanery_app main.cpp Deanery.cpp Group.cpp Student.cpp Deanery.h Group.h Student.h)
# target_link_libraries(hello_world_app ${Boost_LIBRARIES})