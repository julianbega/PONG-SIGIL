#ifndef PALETA_H
#define PALETA_H
#include "..\Lib\sigil-vc2015\include\sl.h"
#include "GlobalShit.h"

struct Rectangle
{
	Vector2 pos;
	float width;
	float height;

};
struct Player
{
	Rectangle rec;
	int chooseColor;
	int puntos;
	int totalScore;

};
namespace Paleta
{
void MovePlayer(Player& player, int KeyUp, int KeyDown);
Player InitPlayer(int posX, int posY, int width, int height);
}

#endif // !PALETA_H