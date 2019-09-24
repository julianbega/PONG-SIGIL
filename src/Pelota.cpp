#include "../Headers/Pelota.h"

namespace Pelota 
{
void BallMovment(Ball& pelota)
{
	if (pelota.Arriba == true)
	{
		if (pelota.Derecha == true)
		{
			pelota.Position.x = pelota.Position.x + pelota.StandarSpeed* slGetDeltaTime();
			pelota.Position.y = pelota.Position.y + pelota.StandarSpeed* slGetDeltaTime();
		}
		else
		{
			pelota.Position.x = pelota.Position.x - pelota.StandarSpeed* slGetDeltaTime();
			pelota.Position.y = pelota.Position.y + pelota.StandarSpeed* slGetDeltaTime();
		}
	}
	else
	{
		if (pelota.Derecha == true)
		{
			pelota.Position.x = pelota.Position.x + pelota.StandarSpeed* slGetDeltaTime();
			pelota.Position.y = pelota.Position.y - pelota.StandarSpeed* slGetDeltaTime();
		}
		else
		{
			pelota.Position.x = pelota.Position.x - pelota.StandarSpeed* slGetDeltaTime();
			pelota.Position.y = pelota.Position.y - pelota.StandarSpeed* slGetDeltaTime();
		}
	}
}
void BallMovmentLimit(Ball& pelota, Player& player1, Player& player2)
{
	if (pelota.Position.y <= 0 + pelota.Radius) { pelota.Arriba = true; }
	if (pelota.Position.y >= screenHeight - pelota.Radius) { pelota.Arriba = false; }
	if (pelota.Position.x <= 0 + pelota.Radius) { pelota.Derecha = true; player2.puntos++; }
	if (pelota.Position.x >= screenWidth - pelota.Radius) { pelota.Derecha = false; player1.puntos++; }
}

void BallColisionWithPlayers(Ball& pelota, Player& player1, Player& player2)
{
	if (pelota.Position.x-pelota.Radius <= player1.rec.pos.x + player1.rec.width / 2 + pelota.Radius && pelota.Position.y-pelota.Radius <= player1.rec.pos.y + player1.rec.height / 2 && pelota.Position.y+pelota.Radius >= player1.rec.pos.y - player1.rec.height / 2 && pelota.Position.x + pelota.Radius >= player1.rec.pos.x + player1.rec.width / 2 )
	{
		pelota.Derecha = true;
	}
	if (pelota.Position.x+pelota.Radius >= player2.rec.pos.x - player2.rec.width / 2 - pelota.Radius && pelota.Position.y-pelota.Radius <= player2.rec.pos.y + player2.rec.height / 2 && pelota.Position.y+ pelota.Radius >= player2.rec.pos.y - player2.rec.height / 2 && pelota.Position.x - pelota.Radius <= player2.rec.pos.x - player2.rec.width / 2)
	{
		pelota.Derecha = false;
	}
}

Ball InitPelota(int posX, int posY, int radius) {
	Ball Pelota;
	Pelota.Position.x = posX;
	Pelota.Position.y = posY;
	Pelota.Radius = radius;
	Pelota.numVertices = 50;
	Pelota.StandarSpeed = 400;
	Pelota.Arriba = true;
	Pelota.Derecha = true;
	return Pelota;
}
}