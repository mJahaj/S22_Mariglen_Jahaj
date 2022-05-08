#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Game
{
	void OpenGLRenderer::Draw(Game::Sprite& picture, int xPos, int yPos, int zPos, Game::Shader shader)
	{
		
		int winWidth{ GameWindow::GetWindow()->GetWidth() };
		int winHeight{ GameWindow::GetWindow()->GetHeight() };

		shader.Bind();
		picture.Bind();
		

		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);//sprite coords 100, 200

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}