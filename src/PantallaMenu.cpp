#include "../Headers/PantallaMenu.h"

void Menu(Player& player1, Player& player2, Ball& pelota, int& currentScreen){
	MenuUpdate(currentScreen);
	Draw::menu();
}

void MenuUpdate(int& currentScreen) {

	if (slGetKey(SL_KEY_ESCAPE))
	{
		currentScreen = End;
	}
	if (slGetKey(SL_KEY_ENTER))
	{
		currentScreen = GameplayScreen;
	}
}