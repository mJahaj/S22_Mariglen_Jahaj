#include "pch.h"

#include "GameApp.h"
#include "GameWindow.h"
#include "GLFW/glfw3.h"
namespace Game
{
	void GameApp::Run()		
	{
		GAME_LOG("Running ..");
		//Enables glfw
		Game::GameWindow::Init();//no obj needed it just starts

		//GLFWwindow* window;

		Game::GameWindow::GetWindow()->CreateWindow(800, 600, "My Game Window");//anyone can access window params 

		while (true)//game loop, frame rendering 
		{
			//collect user input
			//update game world based on user input
			//generate next frame
			OnUpdate();

			Game::GameWindow::GetWindow()->SwapBuffers();
			Game::GameWindow::GetWindow()->CollectEvents();
		}
	}
	void GameApp::OnUpdate()
	{

	}
}