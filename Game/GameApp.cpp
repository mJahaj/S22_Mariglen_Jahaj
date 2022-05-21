#include "pch.h"

#include "GameApp.h"
#include "GameWindow.h"
//#include "glad/glad.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"
#include "KeyCodes.h"
//#include "GLFW/glfw3.h"


namespace Game
{

	GameApp::GameApp()
	{
		GAME_LOG("Running ..");
		//Enables glfw
		Game::GameWindow::Init();//no obj needed it just starts

		Game::GameWindow::GetWindow()->CreateWindow(1000, 800, "My Game Window");//anyone can access window params 

		Renderer::Init();
	}
	void GameApp::Run()		
	{



		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;


		while (true)//game loop, frame rendering 
		{
			Renderer::ClearScreen();
			//collect user input
			//update game world based on user input
			//generate next frame
			OnUpdate();

			


			//xPos = (xPos + 5);
			std::this_thread::sleep_until(mNextFrameTime);

			Game::GameWindow::GetWindow()->SwapBuffers();//does drawing
			Game::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;
		}
	}
	void GameApp::OnUpdate()
	{

	}
	void GameApp::SetKeyPressedCallback( std::function<void(const KeyPressedEvent&)>  keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}
	void GameApp::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvent&)> keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}
}