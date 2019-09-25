#ifndef Pantalla_gameplay
#define Pantalla_gameplay

#include "..\Lib\sigil-vc2015\include\sl.h"

#include "PantallaMenu.h"
#include "Pantalla game over.h"
enum Colors { Red = 1, Blue, Green, Yellow, White, Orange, Cyan, Purple };
namespace Draw
{
void ChangeColor(int ColorName);
void gamePlay(Ball& pelota, Player& player1, Player& player2, int& currentScreen);
void menu();
void ScreenMenu();
void gameOver(bool P1Win);
}
#endif // !Pantalla gameplay
