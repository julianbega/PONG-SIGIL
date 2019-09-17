#ifndef Pantalla_gameplay
#define Pantalla_gameplay
#include "..\Lib\sigil-vc2015\include\sl.h"
#include <string>
#include <iostream>
#include "PantallaMenu.h"
#include "Pantalla game over.h"
using namespace std;


enum Colors { Red = 1, Blue, Green, Yellow };
void TextColor(int ColorName);
void DrawGamePlay(Ball& Pelota, Player& Player1, Player& Player2, int& CurrentScreen);
void DrawMenu();
void DrawGameOver();

#endif // !Pantalla gameplay
