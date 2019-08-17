#
# project for mathlib
# 
project(mathlib C CXX)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/ *.c *.cc *.cpp *.h *.hpp *.hh *.hxx *.cxx)

add_library(mathlib STATIC ${SRCS})
target_compile_definitions(mathlib PUBLIC -DUSE_LIBQ_AS_HEADER_ONLY=1)
target_include_directories(mathlib PUBLIC ${ROOT}/src/libq/)
