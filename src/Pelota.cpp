#include "../Headers/Pelota.h"

void BallMovment(Ball& Pelota)
{
	if (Pelota.Arriba == true)
	{
		if (Pelota.Derecha == true)
		{
			Pelota.Position.x = Pelota.Position.x + Pelota.StandarSpeed;
			Pelota.Position.y = Pelota.Position.y + Pelota.StandarSpeed;
		}
		else
		{
			Pelota.Position.x = Pelota.Position.x - Pelota.StandarSpeed;
			Pelota.Position.y = Pelota.Position.y + Pelota.StandarSpeed;
		}
	}
	else
	{
		if (Pelota.Derecha == true)
		{
			Pelota.Position.x = Pelota.Position.x + Pelota.StandarSpeed;
			Pelota.Position.y = Pelota.Position.y - Pelota.StandarSpeed;
		}
		else
		{
			Pelota.Position.x = Pelota.Position.x - Pelota.StandarSpeed;
			Pelota.Position.y = Pelota.Position.y - Pelota.StandarSpeed;
		}
	}
}
void BallMovmentLimit(Ball& Pelota, Player& Player1, Player& Player2)
{
	if (Pelota.Position.y <= 0 + Pelota.Radius) { Pelota.Arriba = true; }
	if (Pelota.Position.y >= screenHeight - Pelota.Radius) { Pelota.Arriba = false; }
	if (Pelota.Position.x <= 0 + Pelota.Radius) { Pelota.Derecha = true; Player2.Puntos++; }
	if (Pelota.Position.x >= screenWidth - Pelota.Radius) { Pelota.Derecha = false; Player1.Puntos++; }
}

void BallColisionWithPlayers(Ball& Pelota, Player& Player1, Player& Player2)
{
	if (Pelota.Position.x <= Player1.Rec.Pos.x + Player1.Rec.width / 2 + Pelota.Radius && Pelota.Position.y <= Player1.Rec.Pos.y + Player1.Rec.height / 2 && Pelota.Position.y >= Player1.Rec.Pos.y - Player1.Rec.height / 2)
	{
		Pelota.Derecha = true;
	}
	if (Pelota.Position.x >= Player2.Rec.Pos.x - Player2.Rec.width / 2 - Pelota.Radius && Pelota.Position.y <= Player2.Rec.Pos.y + Player2.Rec.height / 2 && Pelota.Position.y >= Player2.Rec.Pos.y - Player2.Rec.height / 2)
	{
		Pelota.Derecha = false;
	}
}

Ball InitPelota(int posX, int posY, int radius) {
	Ball Pelota;
	Pelota.Position.x = posX;
	Pelota.Position.y = posY;
	Pelota.Radius = radius;
	Pelota.numVertices = 50;
	Pelota.StandarSpeed = 4;
	Pelota.Arriba = true;
	Pelota.Derecha = true;
	return Pelota;
}