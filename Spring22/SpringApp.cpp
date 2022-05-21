#include "SpringApp.h"

SpringApp::SpringApp()
{
	SetKeyPressedCallback([this](const Game::KeyPressedEvent& e) {
		switch (e.GetKeyCode())
		{
		case GAME_KEY_LEFT:
			mHorizontalSpeed = -5;
			mHero.SetActiveImage(1);//left image
			break;
		case GAME_KEY_RIGHT:
			mHorizontalSpeed = 5;
			mHero.SetActiveImage(0);// right image
			break;
		}
		});

	SetKeyReleasedCallback([this](const Game::KeyReleasedEvent& e) {
		mHorizontalSpeed = 0;
		});

	mDangers[0].SetX(400);
	mDangers[0].SetY(400);
}

void SpringApp::OnUpdate()
{
	mHero.SetX(mHero.GetX() + mHorizontalSpeed);

	if (mDangers[0].GetY() < 0)
		mEnemyVSpeed *= -1;
	else if (mDangers[0].GetY() > Game::GameWindow::GetWindow()->GetHeight() - mDangers[0].GetHeight())
		mEnemyVSpeed *= -1;

	mDangers[0].SetY(mDangers[0].GetY() + mEnemyVSpeed);

	if (Collide(mHero, mDangers[0]))
	{
		exit(0);
	}

	mHero.Draw();
	mDangers[0].Draw();
}

bool SpringApp::Collide(const Entity& one, const Entity& another)
{// x = left border
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };


	bool collideX{ false };
	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
		(anotherLeft <= oneLeft && oneLeft <= anotherRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
		(anotherBottom <= oneBottom && oneBottom <= anotherTop))
		collideY = true;

	return collideX && collideY;
}
