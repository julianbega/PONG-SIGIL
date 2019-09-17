#include "../Headers/Pantalla de juego.h"

Ball Pelota;
Player Player1;
Player Player2;
int CurrentScreen;

void PVP(Player& Player1, Player& Player2, Ball& Pelota, int CurrentScreen)
{
	
		MovePlayer(Player1, 'W', 'S');
		MovePlayer(Player2, SL_KEY_UP, SL_KEY_DOWN);
		BallMovment(Pelota);
		BallMovmentLimit(Pelota, Player1, Player2);
		BallColisionWithPlayers(Pelota, Player1, Player2);
		DrawGamePlay(Pelota, Player1, Player2, CurrentScreen);
	
}

void GameInit() {

	Init();
	while (!slShouldClose())
	{
		switch (CurrentScreen)
		{
			case MenuScreen:
				Menu(Player1, Player2, Pelota, CurrentScreen);
			break;

			case GameplayScreen:
				PVP(Player1, Player2, Pelota, CurrentScreen);
			break;

			case GameOverScreen:
				GameOver(Player1, Player2, Pelota, CurrentScreen);
			break;
			
			default:
			break;
		}	
	}
}



void Init() {
	CurrentScreen = 1;
	Pelota = InitPelota(screenWidth / 2, screenHeight / 2, 9);
	Player1 = InitPlayer(40, 80, 20, 80);
	Player2 = InitPlayer(screenWidth - 40, 80, 20, 80);
	// set up our window and a few resources we need
	slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
	slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
}

