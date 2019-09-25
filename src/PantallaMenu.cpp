#include "../Headers/PantallaMenu.h"


void MainMenu(Player& player1, Player& player2, Ball& pelota, int& currentScreen){
	
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

void SelectSizeMenu() {
	screenWidth = 800;
	screenHeight = 450;
	slWindow(screenWidth, screenHeight, "Resolution Menu", false);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
	bool SizeIsSelected = false;
	while (!SizeIsSelected)
	{	
		if (slGetKey(SL_KEY_ENTER))
		{
			SizeIsSelected = true;
		}
		if (slGetKey('I'))
		{
			screenWidth = 1200;
			screenHeight = 675;
			SizeIsSelected = true;
		}
		if (slGetKey('O'))
		{
			screenWidth = 400;
			screenHeight = 225;
			SizeIsSelected = true;
		}
		Draw::ScreenMenu();
	}
	slClose();
	slWindow(screenWidth, screenHeight, "Pong", false);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), screenHeight/20);
	Draw::ScreenMenu();
	
}