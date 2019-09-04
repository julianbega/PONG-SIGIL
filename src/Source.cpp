#include "sl.h"


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


void Win(int TextColor);

void Menu();
void PVP();
void PVE();

int main(int args, char *argv[])
{
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
	

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
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

		if (slGetKey(SL_KEY_UP) && Player2.Rec.Pos.y <= screenHeight - Player2.Rec.height/2)
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
		if (Pelota.Position.y <= 0 + Pelota.Radius)	{	Pelota.Arriba = true;	}
		if (Pelota.Position.y >= screenHeight - Pelota.Radius) { Pelota.Arriba = false; }
		if (Pelota.Position.x <= 0 + Pelota.Radius) { Pelota.Derecha = true; Player2.Puntos++; }
		if (Pelota.Position.x >= screenWidth - Pelota.Radius) { Pelota.Derecha = false; Player1.Puntos++;}
		}

		//// COLISIONES PALETAS PELOTA
		{
		if (Pelota.Position.x <= Player1.Rec.Pos.x + Player1.Rec.width / 2 + Pelota.Radius && Pelota.Position.y <=  Player1.Rec.Pos.y + Player1.Rec.height/2 && Pelota.Position.y >= Player1.Rec.Pos.y - Player1.Rec.height / 2)
		{
			Pelota.Derecha = true; 
		}
		if (Pelota.Position.x >= Player2.Rec.Pos.x - Player2.Rec.width / 2 - Pelota.Radius && Pelota.Position.y <= Player2.Rec.Pos.y + Player2.Rec.height / 2 && Pelota.Position.y >= Player2.Rec.Pos.y - Player2.Rec.height / 2)
		{
			Pelota.Derecha = false;
		}
		}

		


		slRectangleFill(Player1.Rec.Pos.x, Player1.Rec.Pos.y, Player1.Rec.width, Player1.Rec.height);
		slRectangleFill(Player2.Rec.Pos.x, Player2.Rec.Pos.y, Player2.Rec.width, Player2.Rec.height);
		slCircleFill(Pelota.Position.x, Pelota.Position.y, Pelota.Radius, Pelota.numVertices);

		slRender(); // draw everything
	}
	
	return 0;
}