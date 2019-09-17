#ifndef PELOTA_H
#define PELOTA_H
#include "GlobalShit.h"
#include "..\Lib\sigil-vc2015\include\sl.h"
#include "Paleta.h"
#include <string>
#include <iostream>
using namespace std;

struct Ball
{
	Vector2 Position;
	float StandarSpeed;
	float Radius;
	float numVertices;
	bool Arriba;
	bool Derecha;
};

Ball InitPelota(int posX, int posY, int radius);
void BallMovment(Ball& Pelota);
void BallMovmentLimit(Ball& Pelota, Player& Player1, Player& Player2);
void BallColisionWithPlayers(Ball& Pelota, Player& Player1, Player& Player2);
#endif // !PELOTA_H