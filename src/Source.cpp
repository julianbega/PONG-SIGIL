#include "sl.h"
using namespace std;
#include <string>
#include <iostream>

enum Colors { Red = 1, Blue, Green, Yellow};
const int screenWidth = 800;
const int screenHeight = 450;

bool CanHitP1 = false;
bool PlayPVP = false;
bool PlayPVE = false;
bool Play = false;
bool Victory = false;
bool P1Win = false;
int speed = 3;
struct Vector2
{
	int x;
	int y;
	
};

struct Rectangle
{
	Vector2 Pos;
	float width;
	float height;

} ;

struct Player
{
	Rectangle Rec;
	int ChooseColor;
	int Puntos;
	int TotalScore;

}Player1, Player2;

struct Ball
{
	Vector2 Position;
	float StandarSpeed;
	float Radius;
	float numVertices;
	bool Arriba;
	bool Derecha;
}Pelota;


void TextColor(int ColorName);
void Menu();
void PVP();
void PVE();
void Init();
void GameOver(int PW);

void main()
{
	Init();
	Menu();


}

void TextColor(int ColorName)
{
	switch (ColorName) {
	case 1:
		//Red
		slSetForeColor(3.0, 0.0, 0.0, 1.0);
		break;
	case 2:
		//Blue
		slSetForeColor(0.0, 0.0, 3.0, 1.0);
		break;
	case 3:
		//Green
		slSetForeColor(0.0, 3.0, 0.0, 1.0);
		break;
	case 4:
		//Yellow
		slSetForeColor(3.0, 1.8, 0.2, 1.0);
		break;
	default:
		break;
	}
}

void PVP()
{
	while (!slShouldClose())
	{
		//// CONTROLS
		{
			if (slGetKey('W') && Player1.Rec.Pos.y <= screenHeight - Player1.Rec.height / 2)
			{
				Player1.Rec.Pos.y = Player1.Rec.Pos.y + speed;
			}
			if (slGetKey('S') && Player1.Rec.Pos.y >= 0 + Player1.Rec.height / 2)
			{
				Player1.Rec.Pos.y = Player1.Rec.Pos.y - speed;
			}

			if (slGetKey(SL_KEY_UP) && Player2.Rec.Pos.y <= screenHeight - Player2.Rec.height / 2)
			{
				Player2.Rec.Pos.y = Player2.Rec.Pos.y + speed;
			}
			if (slGetKey(SL_KEY_DOWN) && Player2.Rec.Pos.y >= 0 + Player2.Rec.height / 2)
			{
				Player2.Rec.Pos.y = Player2.Rec.Pos.y - speed;
			}

		}

		//// MOVIMIENTOS PELOTA
		{
			if (Pelota.Arriba == true)
			{
				if (Pelota.Derecha == true)
				{
					Pelota.Position.x = Pelota.Position.x + Pelota.StandarSpeed;
					Pelota.Position.y = Pelota.Position.y + Pelota.StandarSpeed;
				}
				else
				{
					Pelota.Position.x = Pelota.Position.x - Pelota.StandarSpeed;
					Pelota.Position.y = Pelota.Position.y + Pelota.StandarSpeed;
				}
			}
			else
			{
				if (Pelota.Derecha == true)
				{
					Pelota.Position.x = Pelota.Position.x + Pelota.StandarSpeed;
					Pelota.Position.y = Pelota.Position.y - Pelota.StandarSpeed;
				}
				else
				{
					Pelota.Position.x = Pelota.Position.x - Pelota.StandarSpeed;
					Pelota.Position.y = Pelota.Position.y - Pelota.StandarSpeed;
				}
			}
		}

		//// COLISION PELOTA LIMITES
		{
			if (Pelota.Position.y <= 0 + Pelota.Radius) { Pelota.Arriba = true; }
			if (Pelota.Position.y >= screenHeight - Pelota.Radius) { Pelota.Arriba = false; }
			if (Pelota.Position.x <= 0 + Pelota.Radius) { Pelota.Derecha = true; Player2.Puntos++; }
			if (Pelota.Position.x >= screenWidth - Pelota.Radius) { Pelota.Derecha = false; Player1.Puntos++; }
		}

		//// COLISIONES PALETAS PELOTA
		{
			if (Pelota.Position.x <= Player1.Rec.Pos.x + Player1.Rec.width / 2 + Pelota.Radius && Pelota.Position.y <= Player1.Rec.Pos.y + Player1.Rec.height / 2 && Pelota.Position.y >= Player1.Rec.Pos.y - Player1.Rec.height / 2)
			{
				Pelota.Derecha = true;
			}
			if (Pelota.Position.x >= Player2.Rec.Pos.x - Player2.Rec.width / 2 - Pelota.Radius && Pelota.Position.y <= Player2.Rec.Pos.y + Player2.Rec.height / 2 && Pelota.Position.y >= Player2.Rec.Pos.y - Player2.Rec.height / 2)
			{
				Pelota.Derecha = false;
			}
		}


		slSetFontSize(11);
		TextColor(Red);
		slRectangleFill(Player1.Rec.Pos.x, Player1.Rec.Pos.y, Player1.Rec.width, Player1.Rec.height);
		TextColor(Blue);
		slRectangleFill(Player2.Rec.Pos.x, Player2.Rec.Pos.y, Player2.Rec.width, Player2.Rec.height);
		TextColor(Yellow);
		slCircleFill(Pelota.Position.x, Pelota.Position.y, Pelota.Radius, Pelota.numVertices);

		string PuntosP1 = (" Puntos Player 1: " + (to_string(Player1.Puntos)));
		string PuntosP2 = (" Puntos Player 2: " + (to_string(Player2.Puntos)));
		TextColor(Red);
		slText(20, screenHeight - 20, PuntosP1.c_str());
		TextColor(Blue);
		slText(screenWidth - 180, screenHeight - 20, PuntosP2.c_str());
		if (slGetKey(SL_KEY_ESCAPE))
		{
			Menu();
		}
		if (Player1.Puntos > 1) { GameOver(1); }
		if(Player2.Puntos > 1) {GameOver(2);}
	
		slRender(); // draw everything
	}
}

void Init() {
	Player1.Rec.Pos.x = 40;
	Player1.Rec.Pos.y = 80;
	Player1.Rec.width = 20;
	Player1.Rec.height = 80;
	Player2.Rec.Pos.x = screenWidth - 40;
	Player2.Rec.Pos.y = 80;
	Player2.Rec.width = 20;
	Player2.Rec.height = 80;
	Player1.Puntos = 0;
	Player1.TotalScore = 0;
	Player2.Puntos = 0;
	Player2.TotalScore = 0;
	Pelota.Position.x = screenWidth / 2;
	Pelota.Position.y = screenHeight / 2;
	Pelota.Radius = 9;
	Pelota.numVertices = 50;
	Pelota.StandarSpeed = 4;
	Pelota.Arriba = true;
	Pelota.Derecha = true;
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
	
}
void Menu() 
{
	while (!slShouldClose())
	{
		TextColor(Green);
		slSetFontSize(30);
		slText(60, screenHeight/2, "Presion esc para salir y enter para iniciar ");
		if (slGetKey(SL_KEY_ESCAPE))
		{
			slClose();
			
		}
		if (slGetKey(SL_KEY_ENTER))
		{
			PVP();
		}
		
		slRender();
	}
}

void GameOver(int PW)
{
	while (!slShouldClose())
	{
		slSetFontSize(30);
		if (PW == 1)
		{
			TextColor(Red);
			slText(60, screenHeight / 2, "Player 1 victory");
			//Player 1 win
		}
		if (PW == 2)
		{
			TextColor(Blue);
			slText(60, screenHeight / 2, "Player 2 victory");
			//Player 2 win
		}
		if (slGetKey(SL_KEY_ESCAPE))
		{
			Menu();
		}
		slRender();
	}

}