cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(graphics2d)
#c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#non-gui
set(SOURCE_FILES square.cpp)
set(HEADER_FILES square.h abstractshape.h vector.h)
set(GUI_FILES mainwindow.cpp mainwindow.h)


# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)

add_executable(graphics2d ${GUI_FILES} ${SOURCE_FILES} ${HEADER_FILES}  ${UI_FILES} main.cpp)

target_link_libraries(graphics2d Qt5::Widgets)

add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runUnitTests ${SOURCE_FILES} ${HEADER_FILES} test_vector.cpp)
# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main Qt5::Widgets)
