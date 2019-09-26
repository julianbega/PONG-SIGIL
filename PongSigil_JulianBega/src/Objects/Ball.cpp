#include "Ball.h"

namespace Pelota 
{

Ball InitPelota(float posX, float posY, float radius) 
{
		Ball Pelota;
		Pelota.Position.x = posX;
		Pelota.Position.y = posY;
		Pelota.Radius = radius;
		Pelota.numVertices = 50;
		Pelota.StandarSpeed = screenHeight;
		Pelota.Arriba = true;
		Pelota.Derecha = true;
		return Pelota;
}

void BallMovment(Ball& ball)
{
	if (ball.Arriba == true)
	{
		if (ball.Derecha == true)
		{
			ball.Position.x = ball.Position.x + ball.StandarSpeed* slGetDeltaTime();
			ball.Position.y = ball.Position.y + ball.StandarSpeed* slGetDeltaTime();
		}
		else
		{
			ball.Position.x = ball.Position.x - ball.StandarSpeed* slGetDeltaTime();
			ball.Position.y = ball.Position.y + ball.StandarSpeed* slGetDeltaTime();
		}
	}
	else
	{
		if (ball.Derecha == true)
		{
			ball.Position.x = ball.Position.x + ball.StandarSpeed* slGetDeltaTime();
			ball.Position.y = ball.Position.y - ball.StandarSpeed* slGetDeltaTime();
		}
		else
		{
			ball.Position.x = ball.Position.x - ball.StandarSpeed* slGetDeltaTime();
			ball.Position.y = ball.Position.y - ball.StandarSpeed* slGetDeltaTime();
		}
	}
}

void BallMovmentLimit(Ball& ball, Player& player1, Player& player2)
{
	if (ball.Position.y <= 0 + ball.Radius) { ball.Arriba = true; }
	if (ball.Position.y >= screenHeight - ball.Radius) { ball.Arriba = false; }
	if (ball.Position.x <= 0 + ball.Radius) { ball.Derecha = true; player2.puntos++; }
	if (ball.Position.x >= screenWidth - ball.Radius) { ball.Derecha = false; player1.puntos++; }
}

void BallColisionWithPlayers(Ball& ball, Player& player1, Player& player2)
{
	if (ball.Position.x-ball.Radius <= player1.rec.pos.x + player1.rec.width / 2 + ball.Radius && ball.Position.y-ball.Radius <= player1.rec.pos.y + player1.rec.height / 2 && ball.Position.y+ball.Radius >= player1.rec.pos.y - player1.rec.height / 2 && ball.Position.x + ball.Radius >= player1.rec.pos.x + player1.rec.width / 2 )
	{
		ball.Derecha = true;
	}
	if (ball.Position.x+ball.Radius >= player2.rec.pos.x - player2.rec.width / 2 - ball.Radius && ball.Position.y-ball.Radius <= player2.rec.pos.y + player2.rec.height / 2 && ball.Position.y+ ball.Radius >= player2.rec.pos.y - player2.rec.height / 2 && ball.Position.x - ball.Radius <= player2.rec.pos.x - player2.rec.width / 2)
	{
		ball.Derecha = false;
	}
}

}