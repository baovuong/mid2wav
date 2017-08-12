cmake_minimum_required(VERSION 3.0)
project (mid2wav)

# setting stuff
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -std=c99")
set (CMAKE_REQUIRED_INCLUDES /usr/local/include)
#set (CMAKE_VERBOSE_MAKEFILE ON)
set (SRC_FILES src/main.c)

# output
add_executable (mid2wav ${SRC_FILES})

# libraries
find_package (FluidSynth REQUIRED)
find_package (Mp3Lame REQUIRED)

include_directories (${FLUIDSYNTH_INCLUDE_DIR})
include_directories (${MP3LAME_INCLUDE_DIR})

target_link_libraries (mid2wav ${FLUIDSYNTH_LIBRARY})
target_link_libraries (mid2wav ${MP3LAME_LIBRARY})