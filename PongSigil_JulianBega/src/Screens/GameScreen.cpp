#include "GameScreen.h"


namespace Game
{
	static void PVP(Player& player1, Player& player2, Ball& ball, int& currentScreen)
	{

		Paleta::MovePlayer(player1, 'W', 'S');
		Paleta::MovePlayer(player2, SL_KEY_UP, SL_KEY_DOWN);
		Pelota::BallMovment(ball);
		Pelota::BallMovmentLimit(ball, player1, player2);
		Pelota::BallColisionWithPlayers(ball, player1, player2);
		Draw::GamePlay(ball, player1, player2, currentScreen);
		if (player1.puntos > 1) 
		{
			currentScreen = GameOverScreen;
		}
		if (player2.puntos > 1) 
		{
			currentScreen = GameOverScreen;
		}
		if (GetKeyUp(SL_KEY_ESCAPE))
		{
			currentScreen = MenuScreen;
			Init(player1, player2, ball, currentScreen);
		}
	

	}

	static void PVE(Player& player1, Player& player2, Ball& ball, int& currentScreen)
	{
		Paleta::MovePlayer(player1, 'W', 'S');
		Paleta::MovePlayer(player2, SL_KEY_UP, SL_KEY_DOWN);
		Pelota::BallMovment(ball);
		Pelota::BallMovmentLimit(ball, player1, player2);
		Pelota::BallColisionWithPlayers(ball, player1, player2);
		Draw::GamePlay(ball, player1, player2, currentScreen);
		if (player1.puntos > 1) 
		{
			currentScreen = GameOverScreen;
		}
		if (player2.puntos > 1) 
		{
			currentScreen = GameOverScreen;
		}
		if (GetKeyUp(SL_KEY_ESCAPE))
		{
			currentScreen = MenuScreen;
		}


	}

	void StartGame() 
	{
		Menu::SelectSize();
		Ball ball;
		Player player1;
		Player player2;
		int currentScreen;
		Init(player1, player2, ball, currentScreen);
		UpdateLoop(player1, player2, ball, currentScreen);

	}

	static void UpdateLoop(Player& player1, Player& player2, Ball& ball, int& currentScreen)
	{
		bool gameIsRuning = true;
		while (gameIsRuning)
		{
			switch (currentScreen)
			{
			case MenuScreen:
				Menu::Main(player1, player2, ball, currentScreen);
				break;

			case GameplayScreen:
				PVP(player1, player2, ball, currentScreen);
				break;

			case GameOverScreen:
				GameOver(player1, player2, ball, currentScreen);
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

	static void Init(Player& player1, Player& player2, Ball& ball, int& currentScreen) 
	{
		currentScreen = 1;
		ball = Pelota::InitPelota(screenWidth / 2, screenHeight / 2, screenHeight /50);
		player1 = Paleta::InitPlayer(screenHeight / 10, screenWidth / 10, screenHeight / 22, screenWidth / 10);
		player2 = Paleta::InitPlayer(screenWidth - screenHeight / 10, screenWidth / 10, screenHeight / 22, screenWidth / 10);
		// set up our window and a few resources we need
		
	}
}