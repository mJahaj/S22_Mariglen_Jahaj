#pragma once

#include "GameApp.h"

//macro creation
#define GAME_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}