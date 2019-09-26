#ifndef PALETA_H
#define PALETA_H
#include "sl.h"
#include "GlobalStuff.h"

struct Rectangle
{
	Vector2 pos;
	double width;
	double height;

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
Player InitPlayer(int posX, int posY, int width, int height);
void MovePlayer(Player& player, int KeyUp, int KeyDown);
}

#endif // !PALETA_H