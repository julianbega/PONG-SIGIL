#include "../Headers/Pantalla game over.h"

void GameOver(Player& player1, Player& player2, Ball& pelota, int& currentScreen)
{
	
		if (slGetKey(SL_KEY_ESCAPE))
		{
			currentScreen = MenuScreen;
		}
		if (player1.puntos > player2.puntos)
		{
			Draw::gameOver(true);
		}
		else 
		{
			Draw::gameOver(false);
		}
		
}