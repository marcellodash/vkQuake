#
# Project file for the engine
# 
project(engine C CXX)

#file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/ *.c *.cc *.cpp *.cxx *.h *.hpp *.hh *.hxx)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(Vulkan REQUIRED vulkan)

set(SRCS		bgmusic.c
				snd_codec.c
				snd_flac.c
				snd_wave.c
				snd_vorbis.c
				snd_opus.c
				snd_mikmod.c
				snd_xmp.c
				snd_umx.c
				snd_dma.c
				snd_mix.c
				snd_mem.c
				snd_sdl.c
				cd_sdl.c
				in_sdl.c
				gl_vidsdl.c
				net_bsd.c
				net_udp.c
				pl_linux.c
				sys_sdl_unix.c
				main_sdl.c
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
				gl_refrag.c
				gl_rlight.c
				gl_rmain.c
				gl_fog.c
				gl_rmisc.c
				r_part.c
				r_world.c
				gl_screen.c
				gl_sky.c
				gl_warp.c
				gl_draw.c
				image.c
				gl_texmgr.c
				gl_mesh.c
				gl_heap.c
				r_sprite.c
				r_alias.c
				r_brush.c
				gl_model.c
				strlcat.c
				strlcpy.c
				net_dgrm.c
				net_loop.c
				net_main.c
				chase.c
				cl_demo.c
				cl_input.c
				cl_main.c
				cl_parse.c
				cl_tent.c
				console.c
				keys.c
				menu.c
				sbar.c
				view.c
				wad.c
				cmd.c
				common.c
				crc.c
				cvar.c
				cfgfile.c
				host.c
				host_cmd.c
				mathlib.c
				pr_cmds.c
				pr_edict.c
				pr_exec.c
				sv_main.c
				sv_move.c
				sv_phys.c
				sv_user.c
				world.c
				zone.c)
				
if(DEFINED LINUX_BUILD)
	list(APPEND CMAKE_REQUIRED_LIBRARIES m glibc pthread c)
endif(DEFINED LINUX_BUILD)

add_executable(engine ${SRCS})

target_include_directories(engine PUBLIC ${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS} ${ROOT}/src/shaders/)
target_link_libraries(engine ${Vulkan_LIBRARIES} ${SDL_LIBRARY})

if(DEFINED LINUX_BUILD)
	target_link_libraries(engine -lm -ldl -lpthread)
endif(DEFINED LINUX_BUILD)
