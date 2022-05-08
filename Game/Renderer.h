#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "GameUtil.h"
namespace Game
{
	class GAME_API Renderer
	{
	public:
		static void Init();
		static void Draw(Game::Sprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();
		
		//Renderer::GetRenderer()->Draw(...
		// Renderer::Draw(..  if static
	private:
		inline static Renderer* mInstance{ nullptr };
		RendererImplementation* mImplementation{ nullptr };
		Renderer();
		Game::Shader mShader;
	};

}