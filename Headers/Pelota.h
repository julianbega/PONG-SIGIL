#ifndef PELOTA_H
#define PELOTA_H

#include "GlobalStuff.h"
#include "Paleta.h"

#include <string>


struct Ball
{
	Vector2 Position;
	float StandarSpeed;
	float Radius;
	float numVertices;
	bool Arriba;
	bool Derecha;
};
namespace Pelota
{
	Ball InitPelota(int posX, int posY, int radius);
	void BallMovment(Ball& Pelota);
	void BallMovmentLimit(Ball& pelota, Player& player1, Player& player2);
	void BallColisionWithPlayers(Ball& pelota, Player& player1, Player& player2);
}
#endif // !PELOTA_H