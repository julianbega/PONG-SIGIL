#ifndef PANTALLA_DE_JUEGO_H
#define PANTALLA_DE_JUEGO_H

#include "..\Lib\sigil-vc2015\include\sl.h"

#include "PantallaMenu.h"

namespace Game
{
void PVP(Player& player1, Player& player2, Ball& pelota, int& currentScreen);
void PVE(Player& player1, Player& player2, Ball& pelota, int& currentScreen);
void loop();
void Update(Player& player1, Player& player2, Ball& pelota, int& currentScreen);
void Init(Player& player1, Player& player2, Ball& pelota, int& currentScreen);
}
#endif // !PANTALLA_DE_JUEGO_H

