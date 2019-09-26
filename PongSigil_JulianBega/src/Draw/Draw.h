#ifndef Pantalla_gameplay
#define Pantalla_gameplay

#include "sl.h"

#include "MenuScreen.h"
#include "GameOverScreen.h"


namespace Draw
{
void ScreenSizeMenu();
void Menu();
void GamePlay(Ball& pelota, Player& player1, Player& player2, int& currentScreen);
void GameOver(bool P1Win);
void ChangeColor(int ColorName);
}

enum Colors { Red = 1, Blue, Green, Yellow, White, Orange, Cyan, Purple };
#endif // !Pantalla gameplay
