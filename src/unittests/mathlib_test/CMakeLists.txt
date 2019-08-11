#
# Libq unit test
# 
project(mathlib_test C CXX)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR} *.c *.cc *.cpp *.h)

add_executable(mathlib_test ${SRCS})

target_link_libraries(mathlib_test mathlib)
target_include_directories(mathlib_test PUBLIC ${ROOT}/src/mathlib)
