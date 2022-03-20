set(HEADEr_FILES
	Game.h
	GameApp.h
	GameUtil.h 
	GameWindow.h
	WindowImplementation.h
	specificGlfw/GlfwWindow.h
	)

set(SOURCE_FILES 
	GameApp.cpp
	GameWindow.cpp
	specificGlfw/GlfwWindow.cpp
	)

add_library(Game SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG) 

include_directories(../glfw/include)
include_directories(../Game)

target_precompile_headers(Game PRIVATE pch.h)

target_link_libraries(Game glfw)