#ifndef PANTALLAMENU_H
#define PANTALLAMENU_H

#include "Pelota.h"
#include "..\Lib\sigil-vc2015\include\sl.h"
#include "Pantalla gameplay.h"
#include "Pantalla de juego.h"
#include <string>
#include <iostream>
using namespace std;

void Menu(Player& Player1, Player& Player2, Ball& Pelota, int& CurrentScreen);
void MenuUpdate(int& CurrentScreen);

#endif // !PANTALLAMENU_H
