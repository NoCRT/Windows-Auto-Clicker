cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(misc_dealer VERSION 0.1.0)

set(SFML_DIR "libs/sfml-2.5.1/lib/cmake/SFML/")
#file(GLOB_RECURSE FILES files/*.cpp files/*.h files/*.hpp)

# avalable : graphics audio window system network 
# requires openal32. -d = debug prefix
find_package(SFML 2.5.1 COMPONENTS system window REQUIRED)

add_executable(${PROJECT_NAME} main.cpp) #${FILES})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window)