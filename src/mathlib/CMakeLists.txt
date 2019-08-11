#
# project for mathlib
# 
project(mathlib C CXX)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/ *.c *.cc *.cpp *.h *.hpp *.hh *.hxx *.cxx)

add_library(mathlib STATIC ${SRCS})
