#include "pch.h"

#include "GameApp.h"
#include "GameWindow.h"
#include "glad/glad.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"


namespace Game
{
	void GameApp::Run()		
	{
		GAME_LOG("Running ..");
		//Enables glfw
		Game::GameWindow::Init();//no obj needed it just starts

		//GLFWwindow* window;

		Game::GameWindow::GetWindow()->CreateWindow(800, 600, "My Game Window");//anyone can access window params 
		
		// Shaders //
		//Game::Shader shader{ "../Game/Assets/Shaders/defaultVertex.glsl", "../Game/Assets/Shaders/defaultFragment.glsl" };
		//shader.SetUniform2Ints("windowSize", 800, 600);
		//shader.SetUniform3Ints("spriteCoord", 100, 200, 1.0);//sprite coords 100, 200
		//Game::Sprite star{ "../Game/Assets/Images/Star.png" };

		Renderer::Init();

		Game::Sprite star{ "../Game/Assets/Images/Star.png" };

		while (true)//game loop, frame rendering 
		{
			//collect user input
			//update game world based on user input
			//generate next frame
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Renderer::Draw(star, 50, 20, 1);

			

			Game::GameWindow::GetWindow()->SwapBuffers();
			Game::GameWindow::GetWindow()->CollectEvents();
		}
	}
	void GameApp::OnUpdate()
	{

	}
}