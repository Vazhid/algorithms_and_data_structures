cmake_minimum_required(VERSION 3.0.0)
project(TASK)

set(CMAKE_CXX_STANDARD 17)

add_executable( TASK
                task.hpp
                task.cpp
                listGraph.hpp
                listGraph.cpp
                matrixGraph.hpp
                matrixGraph.cpp 
                setGraph.hpp
                setGraph.cpp 
                arcGraph.hpp
                arcGraph.cpp )
