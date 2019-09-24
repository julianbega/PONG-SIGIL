#include "../Headers/Pantalla de juego.h"


namespace Game
{
	void PVP(Player& player1, Player& player2, Ball& pelota, int& currentScreen)
	{

		Paleta::MovePlayer(player1, 'W', 'S');
		Paleta::MovePlayer(player2, SL_KEY_UP, SL_KEY_DOWN);
		Pelota::BallMovment(pelota);
		Pelota::BallMovmentLimit(pelota, player1, player2);
		Pelota::BallColisionWithPlayers(pelota, player1, player2);
		Draw::gamePlay(pelota, player1, player2, currentScreen);
		if (player1.puntos > 1) {
			currentScreen = GameOverScreen;
		}
		if (player2.puntos > 1) {
			currentScreen = GameOverScreen;
		}
		if (slGetKey('X'))
		{
			currentScreen = MenuScreen;
		}

	}

	void loop() {

		Ball pelota;
		Player player1;
		Player player2;
		int currentScreen;
		Init(player1, player2, pelota, currentScreen);
		Update(player1, player2, pelota, currentScreen);

	}

	void Update(Player& player1, Player& player2, Ball& pelota, int& currentScreen)
	{
		bool gameIsRuning = true;
		while (gameIsRuning)
		{
			switch (currentScreen)
			{
			case MenuScreen:
				Menu(player1, player2, pelota, currentScreen);
				break;

			case GameplayScreen:
				PVP(player1, player2, pelota, currentScreen);
				break;

			case GameOverScreen:
				GameOver(player1, player2, pelota, currentScreen);
				break;

			case End:
				gameIsRuning = false;
				break;
			default:
				break;
			}
		}
		slClose();
	}

	void Init(Player& player1, Player& player2, Ball& pelota, int& currentScreen) {
		currentScreen = 1;
		pelota = Pelota::InitPelota(screenWidth / 2, screenHeight / 2, 9);
		player1 = Paleta::InitPlayer(40, 80, 20, 80);
		player2 = Paleta::InitPlayer(screenWidth - 40, 80, 20, 80);
		// set up our window and a few resources we need
		slWindow(screenWidth, screenHeight, "Simple SIGIL Example", false);
		slSetFont(slLoadFont("../Fonts/white_rabbit.ttf"), 24);
	}
}