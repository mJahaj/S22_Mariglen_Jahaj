#include "pch.h"
#include "GameUtil.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "OpenGLSprite.h"

namespace Game 
{
	Game::OpenGLSprite::OpenGLSprite(const std::string& file)
	{	
		stbi_set_flip_vertically_on_load(true);

		int numChannels;
		unsigned char* data = stbi_load(file.c_str(), &mWidth, &mHeight, &numChannels, 0);

		if (data == NULL)
			GAME_LOG("ERROR: Texture didnt load");
		
		////////Start Of Draw Rectangel////////
		float vertices[] = {
			 0.0f,			0.0f,			0.0f, 0.0f, //bottom left
			 0.0f,			(float)mHeight, 0.0f, 1.0f, //top left
			 (float)mWidth, (float)mHeight, 1.0f, 1.0f, //top right
			 (float)mWidth, 0.0f,			1.0f, 0.0f  //bottom right
		};
		unsigned int indices[] = {
			0, 1, 2, //first triangle
			0, 2, 3 //second triangle
		};

		
		glGenVertexArrays(1, &mVAO);
		glGenBuffers(1, &mVBO);
		glGenBuffers(1, &mEBO);

		glBindVertexArray(mVAO);

		glBindBuffer(GL_ARRAY_BUFFER, mVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		// position attribute
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// color attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)8);
		glEnableVertexAttribArray(1);
		////////End Of Draw Rectangel////////

		//////// Texture Start ////////
		
		glGenTextures(1, &mTex);
		glBindTexture(GL_TEXTURE_2D, mTex); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
			// set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);////////////// change RGBA -> RGB
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		//////// Texture End /////////

	}

	int OpenGLSprite::GetWidth() const
	{
		return mWidth;
	}

	int OpenGLSprite::GetHeight() const
	{
		return mHeight;
	}

	void OpenGLSprite::Bind()
	{
		glBindVertexArray(mVAO);
		glBindTexture(GL_TEXTURE_2D, mTex); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

	}

	bool OpenGLSprite::IsBound() const
	{
		return false;
	}

}