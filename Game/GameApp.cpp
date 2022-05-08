#include "pch.h"

#include "GameApp.h"
#include "GameWindow.h"
//#include "glad/glad.h"

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

		int xPos{ star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)//game loop, frame rendering 
		{
			//collect user input
			//update game world based on user input
			//generate next frame
			OnUpdate();

			Renderer::ClearScreen();

			Renderer::Draw(star, xPos, 20, 1);

			xPos = (xPos + 1);
			std::this_thread::sleep_until(mNextFrameTime);

			Game::GameWindow::GetWindow()->SwapBuffers();//does drawing
			Game::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void GameApp::OnUpdate()
	{

	}
}