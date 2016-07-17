cmake_minimum_required(VERSION 2.8.4)
project(charles)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Boost 1.54 COMPONENTS program_options REQUIRED)
include_directories (${Boost_INCLUDE_DIR})

set (SOURCE_FILES
    main.cpp
)

add_executable (charles ${SOURCE_FILES})
target_link_libraries (charles ${Boost_LIBRARIES})

include_directories (
    src/
    thirdparty/
)
