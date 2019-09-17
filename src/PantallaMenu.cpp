#include "../Headers/PantallaMenu.h"

void Menu(Player& Player1, Player& Player2, Ball& Pelota, int& CurrentScreen){
	MenuUpdate(CurrentScreen);
	DrawMenu();
}

void MenuUpdate(int& CurrentScreen) {

	if (slGetKey(SL_KEY_ESCAPE))
	{
		slClose();
	}
	if (slGetKey(SL_KEY_ENTER))
	{
		CurrentScreen = GameOverScreen;
	}
}