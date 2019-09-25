#ifndef GLOBAL_H
#define GLOBAL_H

#include "..\Lib\sigil-vc2015\include\sl.h"

enum Pantallas { MenuScreen = 1, GameplayScreen, GameOverScreen, End };
extern int screenWidth;
extern int screenHeight;
struct Vector2
{
	int x;
	int y;
};

bool GetKeyUp(int Key);

extern bool EscKeyWasPress;
extern bool AKeyWasPress;
extern bool LeftKeyWasPress;
extern bool EscKeyIsPress;
extern bool AKeyIsPress;
extern bool LeftKeyIsPress;

#endif

