#ifndef PANTALLAMENU_H
#define PANTALLAMENU_H

#include "sl.h"

#include "Draw.h"
#include "Ball.h"
 

using namespace std;

namespace Menu
{
	void SelectSize();
	void Main(Player& player1, Player& player2, Ball& ball, int& currentScreen);
	void Update(int& currentScreen);
}

#endif // !PANTALLAMENU_H
