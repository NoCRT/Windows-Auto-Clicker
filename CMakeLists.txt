cmake_minimum_required(VERSION 3.0.0)
project(auto VERSION 0.1.0)

set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML/")

include(CTest)
enable_testing()

find_package(SFML 2.5.1 COMPONENTS system window REQUIRED)
add_executable(auto main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-audio)