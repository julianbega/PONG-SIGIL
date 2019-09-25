#ifndef PANTALLAMENU_H
#define PANTALLAMENU_H

#include "..\Lib\sigil-vc2015\include\sl.h"

#include "Pantalla gameplay.h"
#include "Pelota.h"

using namespace std;

void MainMenu(Player& player1, Player& player2, Ball& pelota, int& currentScreen);
void MenuUpdate(int& currentScreen);
void SelectSizeMenu();

#endif // !PANTALLAMENU_H
