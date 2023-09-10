cmake_minimum_required(VERSION 3.25.0)

if (NOT DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "You must set VCPKG_ROOT env variable")
endif()

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
project(GameOfLife VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_library(
  libgameoflife
  OBJECT
  src/gof.cpp
)

target_link_libraries(libgameoflife PUBLIC 
  sfml-system 
  sfml-graphics
  sfml-window
)

add_executable(GameOfLife main.cpp)
target_link_libraries(GameOfLife libgameoflife)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
