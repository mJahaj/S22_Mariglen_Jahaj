#include "pch.h"
#include "Renderer.h"
#include "GameWindow.h"
#include "specificOpenGL/OpenGLRenderer.h"

namespace Game 
{
	void Renderer::Init()
	{
		if(mInstance == nullptr)
			mInstance = new Renderer;
	}

	void Renderer::Draw(Game::Sprite& picture, int xPos, int yPos, int zPos)
	{
		assert(mInstance != nullptr);

		mInstance->mImplementation->Draw(picture, xPos, yPos, zPos, mInstance->mShader);
	}

	Renderer::Renderer(): //colon symbol constructs mSHader right away
		mShader("../Game/Assets/Shaders/defaultVertex.glsl", "../Game/Assets/Shaders/defaultFragment.glsl")
	{
#ifdef GAME_OPENGL
		mImplementation = new OpenGLRenderer;
#else
		#Only_OpenGL_is_supported_for_now
#endif
	}
}
