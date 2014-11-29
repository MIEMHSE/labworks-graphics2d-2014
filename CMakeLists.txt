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
set(SOURCE_FILES main.cpp square.cpp)
set(HEADER_FILES square.h abstractshape.h)
set(GUI_FILES mainwindow.cpp mainwindow.h)


# Widgets finds its own dependencies.
find_package(Qt5Widgets REQUIRED)

add_executable(graphics2d ${GUI_FILES} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(graphics2d Qt5::Widgets)