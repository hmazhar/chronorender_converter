cmake_minimum_required(VERSION 2.8)
project(chronorender_converter)

# Additional packages
  
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
#SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ")
    ADD_EXECUTABLE(chronorender_converter main.cpp   )
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

