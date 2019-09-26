#include "Player.h"

namespace Paleta
{

Player InitPlayer(int posX, int posY, int width, int height)
{
		Player player;
		player.rec.pos.x = posX;
		player.rec.pos.y = posY;
		player.rec.width = width;
		player.rec.height = height;
		player.puntos = 0;
		player.totalScore = 0;
		return player;
}

void MovePlayer(Player& player, int KeyUp, int KeyDown)
{
	if (slGetKey(KeyUp) && player.rec.pos.y <= screenHeight - player.rec.height / 2)
	{
		player.rec.pos.y = player.rec.pos.y + (screenHeight * 2/3) * slGetDeltaTime();
	}
	if (slGetKey(KeyDown) && player.rec.pos.y >= 0 + player.rec.height / 2)
	{
		player.rec.pos.y = player.rec.pos.y - (screenHeight * 2/3) * slGetDeltaTime();
	}
}

}