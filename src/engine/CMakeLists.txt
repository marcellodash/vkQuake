#
# Project file for the engine
# 
project(engine C CXX)

#file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/ *.cpp *.cppc *.cpppp *.cppxx *.h *.hpp *.hh *.hxx)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(Vulkan REQUIRED vulkan)

set(SRCS		bgmusic.cpp
				snd_codec.cpp
				snd_flac.cpp
				snd_wave.cpp
				snd_vorbis.cpp
				snd_opus.cpp
				snd_mikmod.cpp
				snd_xmp.cpp
				snd_umx.cpp
				snd_dma.cpp
				snd_mix.cpp
				snd_mem.cpp
				snd_sdl.cpp
				cd_sdl.cpp
				in_sdl.cpp
				gl_vidsdl.cpp
				net_bsd.cpp
				net_udp.cpp
				pl_linux.cpp
				sys_sdl_unix.cpp
				main_sdl.cpp
				${ROOT}/src/shaders/Compiled/alias_frag.c
				${ROOT}/src/shaders/Compiled/alias_alphatest_frag.c
				${ROOT}/src/shaders/Compiled/alias_vert.c
				${ROOT}/src/shaders/Compiled/basic_alphatest_frag.c
				${ROOT}/src/shaders/Compiled/screen_warp_comp.c
				${ROOT}/src/shaders/Compiled/screen_warp_rgba8_comp.c
				${ROOT}/src/shaders/Compiled/cs_tex_warp_comp.c
				${ROOT}/src/shaders/Compiled/basic_frag.c
				${ROOT}/src/shaders/Compiled/basic_notex_frag.c
				${ROOT}/src/shaders/Compiled/basic_vert.c
				${ROOT}/src/shaders/Compiled/sky_layer_frag.c
				${ROOT}/src/shaders/Compiled/sky_layer_vert.c
				${ROOT}/src/shaders/Compiled/postprocess_frag.c
				${ROOT}/src/shaders/Compiled/postprocess_vert.c
				${ROOT}/src/shaders/Compiled/world_frag.c
				${ROOT}/src/shaders/Compiled/world_vert.c
				${ROOT}/src/shaders/Compiled/showtris_frag.c
				${ROOT}/src/shaders/Compiled/showtris_vert.c
				gl_refrag.cpp
				gl_rlight.cpp
				gl_rmain.cpp
				gl_fog.cpp
				gl_rmisc.cpp
				r_part.cpp
				r_world.cpp
				gl_screen.cpp
				gl_sky.cpp
				gl_warp.cpp
				gl_draw.cpp
				image.cpp
				gl_texmgr.cpp
				gl_mesh.cpp
				gl_heap.cpp
				r_sprite.cpp
				r_alias.cpp
				r_brush.cpp
				gl_model.cpp
				strlcat.cpp
				strlcpy.cpp
				net_dgrm.cpp
				net_loop.cpp
				net_main.cpp
				chase.cpp
				cl_demo.cpp
				cl_input.cpp
				cl_main.cpp
				cl_parse.cpp
				cl_tent.cpp
				console.cpp
				keys.cpp
				menu.cpp
				sbar.cpp
				view.cpp
				wad.cpp
				cmd.cpp
				common.cpp
				crc.cpp
				cvar.cpp
				cfgfile.cpp
				host.cpp
				host_cmd.cpp
				mathlib.cpp
				pr_cmds.cpp
				pr_edict.cpp
				pr_exec.cpp
				sv_main.cpp
				sv_move.cpp
				sv_phys.cpp
				sv_user.cpp
				world.cpp
				zone.cpp)
				
if(DEFINED LINUX_BUILD)
	list(APPEND CMAKE_REQUIRED_LIBRARIES m glibc pthread c)
endif(DEFINED LINUX_BUILD)

add_executable(engine ${SRCS})

target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS} ${ROOT}/src/shaders/ ${ROOT}/src/libq ${ROOT}/src/mathlib ${ROOT}/src/)
target_link_libraries(engine ${Vulkan_LIBRARIES} ${SDL2_LIBRARIES})

if(DEFINED LINUX_BUILD)
	target_link_libraries(engine -lm -ldl -lpthread)
endif(DEFINED LINUX_BUILD)
