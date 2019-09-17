#include "../Headers/Pantalla game over.h"

void GameOver(Player& Player1, Player& Player2, Ball& Pelota, int& CurrentScreen)
{
	
		if (slGetKey(SL_KEY_ESCAPE))
		{
			CurrentScreen = MenuScreen;
		}
		DrawGameOver();
}