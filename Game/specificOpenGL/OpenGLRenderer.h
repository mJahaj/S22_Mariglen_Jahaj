#pragma once

#include "RendererImplementation.h"

namespace Game
{
	class OpenGLRenderer: public RendererImplementation
	{
	public:
		virtual void Draw(Game::Sprite& Picture, int xPos, int yPos, int zPos, Game::Shader shader) override;
		virtual void ClearScreen() override;
	};
}