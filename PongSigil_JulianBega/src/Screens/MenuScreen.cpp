#include "MenuScreen.h"

namespace Menu
{
void SelectSize()
{
	screenWidth = 800;
	screenHeight = 450;
	slWindow(screenWidth, screenHeight, "Resolution Menu", false);
	slSetFont(slLoadFont("../Lib/Fonts/white_rabbit.ttf"), screenHeight / 20);
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
		Draw::ScreenSizeMenu();
	}
	slClose();
	slWindow(screenWidth, screenHeight, "Pong", false);
	slSetFont(slLoadFont("../Lib/Fonts/white_rabbit.ttf"), screenHeight / 20);
	Draw::Menu();
}
void Main(Player& player1, Player& player2, Ball& ball, int& currentScreen)
{

		Update(currentScreen);
		Draw::Menu();
}

void Update(int& currentScreen)
{

		if (slGetKey(SL_KEY_ESCAPE))
		{
			currentScreen = End;
		}
		if (slGetKey(SL_KEY_ENTER))
		{
			currentScreen = GameplayScreen;
		}
}

}