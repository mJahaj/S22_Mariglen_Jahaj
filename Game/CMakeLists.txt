add_library(Game SHARED Game.h GameApp.h GameUtil.h GameApp.cpp)

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG) 

target_precompile_headers(Game PRIVATE pch.h)