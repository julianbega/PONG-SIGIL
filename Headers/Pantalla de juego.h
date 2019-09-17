#ifndef PANTALLA_DE_JUEGO_H
#define PANTALLA_DE_JUEGO_H

#include "..\Lib\sigil-vc2015\include\sl.h"
#include "PantallaMenu.h"
#include <string>
#include <iostream>
using namespace std;


void PVP(Player& Player1, Player& Player2, Ball& Pelota, int CurrentScreen);
void PVE(Player& Player1, Player& Player2, Ball& Pelota, int CurrentScreen);
void GameInit();
void Init();

#endif // !PANTALLA_DE_JUEGO_H

