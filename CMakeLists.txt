cmake_minimum_required(VERSION 3.14)
set(PROJECT_NAME "Adventure")
project(${PROJECT_NAME})

include_directories(include SFML_INCLUDE_DIR)

link_directories(SFML_LIBRARY_DIR)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "Adventure++/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package(SFML COMPONENTS system window graphics network audio)

target_link_libraries(${PROJECT_NAME} sfml-audio sfml-graphics sfml-window sfml-system)