cmake_minimum_required(VERSION 3.0)

project(Ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SOURCE_FILES
  AppWrap.cpp
  AppWrap.hpp
  Application.cpp
  Application.hpp
  Camera.cpp
  Camera.hpp
  Face.cpp
  Face.hpp
  LineReader.cpp
  LineReader.hpp
  Object.cpp
  Object.hpp
  Model.cpp
  Model.hpp
  OffParser.cpp
  OffParser.hpp
  PrintMatrix.cpp
  PrintMatrix.hpp
  ProgramObject.cpp
  ProgramObject.hpp
  Projection.hpp
  Projection.cpp
  Shader.cpp
  Shader.hpp
  Light.cpp
  Light.hpp
  guicontrol.c
  guicontrol.h
  guicallback.c
  guicallback.h
  main.cpp
  main.hpp
  )


 add_definitions(-DGLM_FORCE_RADIANS)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.55.0 REQUIRED COMPONENTS regex)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_definitions(${GTK3_CFLAGS_OTHER})

link_directories(/usr/local/lib ${GTK3_LIBRARY_DIRS})

# set(CMAKE_AUTOMOC ON)
# find_package(Qt4 4.4.3 REQUIRED QtGui QtXml)

add_executable(
  3dstudio
  ${SOURCE_FILES})

include_directories(
  ${Boost_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIRS}
  ${GLEW_INCLUDE_DIRS}
  ${GLFW_INCLUDE_DIRS}
  ${GTK3_INCLUDE_DIRS}
  /home/dv14/dv14cks/cgv/glm)

target_link_libraries(3dstudio
  ${Boost_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
  ${GLFW_STATIC_LIBRARIES}
  ${GTK3_LIBRARIES})
