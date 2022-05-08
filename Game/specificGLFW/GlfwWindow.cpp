#include "pch.h"

#include "glad/glad.h"
#include "GameUtil.h"
#include "GlfwWindow.h"

namespace Game
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			GAME_LOG("ERROR: GLFW Failed to start!")

	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);// cstr pointer to array of chars

		if (mGlfwWindow == nullptr)
		{
			GAME_LOG("ERROR: Window creation failed!");
			return false;
		}


		glfwMakeContextCurrent(mGlfwWindow);//open gl considers this to be its drawing place
		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			GAME_LOG("ERROR: GLAD Failed to start!")

		return true;
	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);//wrapper for swap buffer
	}

	void GlfwWindow::CollectEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return width;
	}

	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);

		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);
		glfwTerminate();
	}
}