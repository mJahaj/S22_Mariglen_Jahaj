#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
namespace Game
{
	class Renderer
	{
	public:
		static void Init();
		static void Draw(Game::Sprite& picture, int xPos, int yPos, int zPos);
		
		//Renderer::GetRenderer()->Draw(...
		// Renderer::Draw(..  if static
	private:
		inline static Renderer* mInstance{ nullptr };
		RendererImplementation* mImplementation{ nullptr };
		Renderer();
		Game::Shader mShader;
	};

}