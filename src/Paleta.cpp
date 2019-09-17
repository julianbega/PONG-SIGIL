#include "../Headers/Paleta.h"

void MovePlayer(Player& Player, int KeyUp, int KeyDown)
{
	if (slGetKey(KeyUp) && Player.Rec.Pos.y <= screenHeight - Player.Rec.height / 2)
	{
		Player.Rec.Pos.y = Player.Rec.Pos.y + 3;
	}
	if (slGetKey(KeyDown) && Player.Rec.Pos.y >= 0 + Player.Rec.height / 2)
	{
		Player.Rec.Pos.y = Player.Rec.Pos.y - 3;
	}
}
Player InitPlayer(int posX, int posY, int width, int height)
{
	Player player;
	player.Rec.Pos.x = posX;
	player.Rec.Pos.y = posY;
	player.Rec.width = width;
	player.Rec.height = height;
	player.Puntos = 0;
	player.TotalScore = 0;
	return player;
}