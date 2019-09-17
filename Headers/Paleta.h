#ifndef PALETA_H
#define PALETA_H
#include "..\Lib\sigil-vc2015\include\sl.h"
#include <string>
#include <iostream>
using namespace std;
#include "GlobalShit.h"

struct Rectangle
{
	Vector2 Pos;
	float width;
	float height;

};
struct Player
{
	Rectangle Rec;
	int ChooseColor;
	int Puntos;
	int TotalScore;

};

void MovePlayer(Player& Player, int KeyUp, int KeyDown);
Player InitPlayer(int posX, int posY, int width, int height);


#endif // !PALETA_H