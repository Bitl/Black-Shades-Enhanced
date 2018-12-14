find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenAL REQUIRED)
#TODO: find CMake Module
find_path(ALUT_INCLUDE_DIR NAMES "alut.h"
	AL
	)
find_library(ALUT_LIBRARY NAMES "alut")

#TODO: libvorbis
add_definitions("-DNOOGG")

include_directories(.)
include_directories(SYSTEM
	"${SDL_INCLUDE_DIR}"
	"${SDL_IMAGE_INCLUDE_DIRS}"
	"${OPENGL_INCLUDE_DIR}"
	"${GLUT_INCLUDE_DIR}"
	"${OPENAL_INCLUDE_DIR}"
	"${ALUT_INCLUDE_DIR}"
	)

#TODO: Windows rsc
add_executable(blackshades
	"Camera.cpp"
	"Decals.cpp"
	"Fog.cpp"
	"Frustum.cpp"
	"GameDraw.cpp"
	"GameInitDispose.cpp"
	"GameLoop.cpp"
	"GameTick.cpp"
	"Globals.cpp"
	"MacInput.cpp"
	"Main.cpp"
	"Maths.cpp"
	"Models.cpp"
	"Person.cpp"
	"Quaternions.cpp"
	"Serialize.cpp"
	"Skeleton.cpp"
	"SoundFX.cpp"
	"Sprites.cpp"
	"Support.cpp"
	"TGALoader.cpp"
	"Text.cpp"
	"Timer.cpp"
	
	"../blackshades.rc"
	)

set(SUPPORT_INCLUDE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Support.h")
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
	add_definitions("-include ${SUPPORT_INCLUDE_FILE}")
elseif(MSVC)
	add_definitions("/FI${SUPPORT_INCLUDE_FILE}")
else()
	message(FATAL_ERROR "Unable to set include file: unknown compiler")
endif()

target_link_libraries(blackshades
	"${SDL_LIBRARY}"
	"${SDL_IMAGE_LIBRARIES}"
	"${OPENGL_LIBRARIES}"
	"${GLUT_LIBRARIES}"
	"${OPENAL_LIBRARY}"
	"${ALUT_LIBRARY}"
	)
