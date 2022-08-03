cmake_minimum_required(VERSION 3.20)
project(MAX3SAT)

set(CMAKE_CXX_STANDARD 23)

add_executable(MAX3SAT main.cpp CGAOptimizer.cpp CGAOptimizer.h CMax3SatProblem.cpp CMax3SatProblem.h CGAIndividual.cpp CGAIndividual.h Clause.cpp Clause.h)
