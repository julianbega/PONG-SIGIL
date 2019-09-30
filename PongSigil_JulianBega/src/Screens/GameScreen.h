#ifndef PANTALLA_DE_JUEGO_H
#define PANTALLA_DE_JUEGO_H

#include "sl.h"

#include "MenuScreen.h"

namespace practicaprofesionaljulianbegapongsigil
{
const int pointsToWin = 2;

namespace Game
{
void PVP(Player& player1, Player& player2, Ball& ball, int& currentScreen);
void PVE(Player& player1, Player& player2, Ball& ball, int& currentScreen);
void StartGame();
void UpdateLoop(Player& player1, Player& player2, Ball& ball, int& currentScreen);
void Init(Player& player1, Player& player2, Ball& ball, int& currentScreen);
}

}

#endif // !PANTALLA_DE_JUEGO_H

