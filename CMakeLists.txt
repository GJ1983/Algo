cmake_minimum_required(VERSION 2.8)

project(F_Network)
#set(CMAKE_BINARY_DIR, ${CMAKE_SOURCE_DIR}/bin )
#set(EXECUTABLE_OUTPUT_PATH, ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH, ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 11)

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(F_Network ${PROJECT_SOURCE_DIR}/F_Network.cpp)
add_executable(MarketPrice ${PROJECT_SOURCE_DIR}/MarketPrice.cpp)
#add_executable(Linked_list ${PROJECT_SOURCE_DIR}/Linked_list.cpp)
#add_executable(array_union ${PROJECT_SOURCE_DIR}/array_union.cpp)
