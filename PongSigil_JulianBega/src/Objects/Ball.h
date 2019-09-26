#ifndef PELOTA_H
#define PELOTA_H

#include <string>

#include "GlobalStuff.h"
#include "Player.h"

struct Ball
{
	Vector2 Position;
	double StandarSpeed;
	double Radius;
	int numVertices;
	bool Arriba;
	bool Derecha;
};
namespace Pelota
{
	Ball InitPelota(float posX, float posY, float radius);
	void BallMovment(Ball& ball);
	void BallMovmentLimit(Ball& ball, Player& player1, Player& player2);
	void BallColisionWithPlayers(Ball& ball, Player& player1, Player& player2);
}
#endif // !PELOTA_H