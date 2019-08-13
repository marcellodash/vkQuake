project(launcher C CXX)

file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/ *.c *.cc *.cpp *.h *.hpp *.hh)

add_executable(launcher ${SRCS})

target_include_directories(launcher PUBLIC ${ROOT}/src/libq)
target_link_libraries(launcher libq)