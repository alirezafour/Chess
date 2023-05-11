cmake_minimum_required(VERSION 3.16..3.26)

# Silence warning about PROJECT_VERSION
cmake_policy(SET CMP0048 NEW)

#project setup
project(myTests
        VERSION 0.0.1
        LANGUAGES CXX
)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/src)
file(GLOB SOURCES
     ${CMAKE_SOURCE_DIR}/src/tile.cpp
     ${CMAKE_SOURCE_DIR}/src/coordination.cpp
     ${CMAKE_SOURCE_DIR}/src/tilecolor.cpp
)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include(CTest)

add_executable(${PROJECT_NAME} ${SOURCES} test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
