#
# Libq unit test
# 
project(libq_test C CXX)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR} *.c *.cc *.cpp *.h)

add_executable(libq_test ${SRCS})

target_link_libraries(libq_test libq)
target_include_directories(libq_test PUBLIC ${ROOT}/src/libq ${ROOT}/src/thirdparty/unitlib2)
