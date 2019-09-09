#
# Temp cmake stuff
# 
# Example:
# cmake ../ -DPLATFORM="x86" -DUSE_AVX=ON -DUSE_SSE41=ON
# make -j16
#
# Supported OS:
#	-	Linux
#	-	Windows
#
# Supported platforms:
#	-	x86
#	-	x64
#	-	aarch32 (with/without NEON or SVE)
#	-	aarch64 (with/without NEON or SVE)
cmake_minimum_required(VERSION 3.6)

option(VECTORIZE "Vectorize C/C++ code and math functions" ON)
option(LIBM_FOR_SIMD "Instead of using SIMD vectorization intrinsics, use libm stuff" OFF)
option(UNIX_CROSS "Build for windows on *nix operating systems" OFF)
option(USE_SSE41 "Use SSE4.1 (only valid for x86 stuff)" ON)
option(USE_AVX "Use AVX (only valid for x86 stuff)" ON)
option(USE_NEON "Use NEON instrinsics (AArch32/64 only)" ON)
option(USE_SVE "Use Scalable vector instructions (AArch32/64 only)" ON)
option(FAST_MATH "Enable/Disable fast math (Note that it's a good idea to keep this on!)" ON)
option(DEBUG "Enable debug" ON)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
set(SRCDIR ${CMAKE_HOME_DIRECTORY}/src)
set(THIRDPARTY ${CMAKE_HOME_DIRECTORY}/src/thirdparty/)
set(CODECS ${THIRDPARTY}/codecs/)
set(MISC ${THIRDPARTY}/misc/)

# Some useful strings that can be used to find libs on linux/win
# generally these will only be used on windows, since linux has /usr/lib, etc.
set(VULKAN_PATHS 	"???")
set(SDL2_PATHS 		"${THIRDPARTY}/SDL2")
set(VORBIS_PATHS 	"${CODECS}")
set(OPUS_PATHS 		"${CODECS}")

if(NOT DEFINED PLATFORM)
	message("No platform specified, defaulting to x86. You can specify this with -DPLATFORM=<x86, x64, aarch64, aarch32>")
	set(PLATFORM "x86")
endif(NOT DEFINED PLATFORM)

message("Building for ${CMAKE_SYSTEM_PROCESSOR}")

if(NOT UNIX_CROSS AND ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	set(LINUX_BUILD 1)
	add_definitions(-DLINUX -D_LINUX)
	set(VULKAN_PATHS 	)
	set(SDL2_PATHS		)
	set(VORBIS_PATHS 	)
	set(OPUS_PATHS 		)
	include_directories(/usr/include/x86_64-linux-gnu)
endif(NOT UNIX_CROSS AND ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")

if(${CMAKE_SYSTEM_NAME} EQUAL "Windows" OR ${UNIX_CROSS})
	set(WINDOWS_BUILD 1)
endif(${CMAKE_SYSTEM_NAME} EQUAL "Windows" OR ${UNIX_CROSS})
#
# Platform vars and stuff
#
if(${PLATFORM} STREQUAL "x86")
	add_definitions(-D_x86_ -D_X86_ -D_i386 -D_I386)
	set(X86_BUILD 1)
	link_directories(${THIRDPARTY}/misc/x86 ${THIRDPARTY}/codecs/x86)
endif(${PLATFORM} STREQUAL "x86")

if(${PLATFORM} STREQUAL "x64")
	add_definitions(-D_x64_ -DX64)
	set(X64_BUILD 1)
	link_directories(${THIRDPARTY}/misc/x64 ${THIRDPARTY}/codecs/x64)
endif(${PLATFORM} STREQUAL "x64")

if(${PLATFORM} STREQUAL "aarch32")
	add_definitions(-DARM32 -D_ARM32_ -D_AARCH32_ -DAARCH32)
	set(AARCH64_BUILD 1)
endif(${PLATFORM} STREQUAL "aarch32")

if(${PLATFORM} STREQUAL "aarch64")
	add_definitions(-DARM64 -D_ARM64_ -D_AARCH64_ -DAARCH64)
	set(AARCH64_BUILD 1)
endif(${PLATFORM} STREQUAL "aarch64")

if(LINUX_BUILD EQUAL 1 AND DEFINED X86_BUILD)
	set(PLAT_SUBDIR linux32)
endif(LINUX_BUILD EQUAL 1 AND DEFINED X86_BUILD)

if(LINUX_BUILD EQUAL 1 AND DEFINED X64_BUILD)
	set(PLAT_SUBDIR linux64)
endif(LINUX_BUILD EQUAL 1 AND DEFINED X64_BUILD)

if(DEFINED WINDOWS_BUILD AND DEFINED X86_BUILD)
	set(PLAT_SUBDIR win32)
endif(DEFINED WINDOWS_BUILD AND DEFINED X86_BUILD)

if(DEFINED WINDOWS_BUILD AND DEFINED X64_BUILD)
	set(PLAT_SUBDIR win64)
endif(DEFINED WINDOWS_BUILD AND DEFINED X64_BUILD)

# TODO: Look at GCC options more for ARM
if(DEFINED AARCH32_BUILD OR DEFINED AARCH64_BUILD)
	set(USE_AVX OFF)
	set(USE_SSE41 OFF)
endif(DEFINED AARCH32_BUILD OR DEFINED AARCH64_BUILD)

# Fast math lets us take shortcuts, like using _mm_rcp and _mm_mul instead of _mm_div
if(FAST_MATH)
	add_definitions(-DFASTMATH -D_FASTMATH)
endif(FAST_MATH)

if(DEFINED X64_BUILD OR DEFINED X86_BUILD)
	if(USE_AVX)
		add_definitions(-DUSE_AVX)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mavx")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
	endif(USE_AVX)
	if(USE_SSE41)
		add_definitions(-DUSE_SSE41)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -msse4.1")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1")
	endif(USE_SSE41)
endif(DEFINED X64_BUILD OR DEFINED X86_BUILD)

if(LINUX_BUILD EQUAL 1)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} 		-O2 -Wall -Wno-trigraphs -Wno-ignored-attributes -Wno-sign-compare -Wno-unused-function -Wno-unused-variable ")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} 	-O2 -Wall -Wno-trigraphs -Wno-ignored-attributes -Wno-sign-compare -Wno-unused-function -Wno-unused-variable ")
	set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -ldl -lm")
	if(DEBUG)
		add_definitions(-DDEBUG -D_DEBUG)
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -gdwarf-4")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -gdwarf-4")
	else()
		add_definitions(-DNDEBUG -DRELEASE -D_NDEBUG)
	endif(DEBUG)
	if(DEFINED X64_BUILD)
		set(CMAKE_IGNORE_PATH "${CMAKE_IGNORE_PATH} /usr/lib/i386-linux-gnu/")
		set(CMAKE_LIBRARY_PATH "${CMAKE_LIBRARY_PATH} /usr/lib/x86_64-linux-gnu/")
		set(CMAKE_LIBRARY_ARCHITECTURE "x86_64")
	endif(DEFINED X64_BUILD)
	if(DEFINED X86_BUILD)
		set(CMAKE_IGNORE_PATH "${CMAKE_IGNORE_PATH} /usr/lib/x86_64-linux-gnu/")
		set(CMAKE_LIBRARY_PATH "${CMAKE_LIBRARY_PATH} /usr/lib/i386-linux-gnu/")
		set(CMAKE_LIBRARY_ARCHITECTURE "i386")
		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
		set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -m32")
	endif(DEFINED X86_BUILD)
endif(LINUX_BUILD EQUAL 1 )

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ROOT}/lib/${PLAT_SUBDIR}/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ROOT}/bin/${PLAT_SUBDIR}/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ROOT}/bin/${PLAT_SUBDIR}/")

add_subdirectory(src)
