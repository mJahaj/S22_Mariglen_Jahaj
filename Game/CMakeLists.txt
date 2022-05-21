set(HEADEr_FILES
	Game.h
	GameApp.h
	GameUtil.h 
	GameWindow.h
	WindowImplementation.h
	specificGlfw/GlfwWindow.h
	Sprite.h
	Shader.h
	Renderer.h
	SpriteImplementation.h
	ShaderImplementation.h
	RendererImplementation.h
	specificOpenGL/OpenGLSprite.h
	specificOpenGL/OpenGLShader.h
	specificOpenGL/OpenGLRenderer.h
	Events.h
	KeyCodes.h
	)

set(SOURCE_FILES 
	GameApp.cpp
	GameWindow.cpp
	specificGlfw/GlfwWindow.cpp
	Sprite.cpp
	Shader.cpp
	Renderer.cpp
	specificOpenGL/OpenGLSprite.cpp
	specificOpenGL/OpenGLShader.cpp
	specificOpenGL/OpenGLRenderer.cpp
	Events.cpp
	)

add_library(Game SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)
add_definitions(-DGAME_OPENGL) 

include_directories(../glfw/include)
include_directories(../Game)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(Game PRIVATE pch.h)

target_link_libraries(Game glfw glad stbi)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Game)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)