#include "GameScreen.h"

namespace practicaprofesionaljulianbegapongsigil
{
	int screenHeight = 450;
	int screenWidth = 800;
namespace Game
{
	 void PVP(Player& player1, Player& player2, Ball& ball, int& currentScreen)
	{

		Paleta::MovePlayer(player1, 'W', 'S');
		Paleta::MovePlayer(player2, SL_KEY_UP, SL_KEY_DOWN);
		Pelota::BallMovment(ball);
		Pelota::BallMovmentLimit(ball, player1, player2);
		Pelota::BallColisionWithPlayers(ball, player1, player2);
		Draw::GamePlay(ball, player1, player2, currentScreen);
		if (player1.puntos > pointsToWin)
		{
			currentScreen = GameOverScreen;
			Init(player1, player2, ball, currentScreen);
		}
		if (player2.puntos > pointsToWin)
		{
			currentScreen = GameOverScreen;
			Init(player1, player2, ball, currentScreen);
		}
		if (KeyManager::GetKeyUp(SL_KEY_ESCAPE, slGetKey(SL_KEY_ESCAPE)))
		{
			currentScreen = MenuScreen;
			Init(player1, player2, ball, currentScreen);

		}
	

	}

	 void PVE(Player& player1, Player& player2, Ball& ball, int& currentScreen)
	{
		Paleta::MovePlayer(player1, 'W', 'S');
		Paleta::MovePlayer(player2, SL_KEY_UP, SL_KEY_DOWN);
		Pelota::BallMovment(ball);
		Pelota::BallMovmentLimit(ball, player1, player2);
		Pelota::BallColisionWithPlayers(ball, player1, player2);
		Draw::GamePlay(ball, player1, player2, currentScreen);
		if (player1.puntos > pointsToWin)
		{
			currentScreen = GameOverScreen;
			player1.puntos = 0;
			player2.puntos = 0;
		}
		if (player2.puntos > pointsToWin)
		{
			currentScreen = GameOverScreen;
			player1.puntos = 0;
			player2.puntos = 0;
		}
		if (KeyManager::GetKeyUp(SL_KEY_ESCAPE, slGetKey(SL_KEY_ESCAPE)))
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
		int currentScreen = 1;
		Init(player1, player2, ball, currentScreen);
		UpdateLoop(player1, player2, ball, currentScreen);

	}

	 void UpdateLoop(Player& player1, Player& player2, Ball& ball, int& currentScreen)
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

			KeyManager::Update(SL_KEY_ESCAPE, slGetKey(SL_KEY_ESCAPE));
			KeyManager::Update('A', slGetKey('A'));
			KeyManager::Update(SL_KEY_LEFT, slGetKey(SL_KEY_LEFT));
		}
		slClose();
	}

	 void Init(Player& player1, Player& player2, Ball& ball, int& currentScreen) 
	{
		ball = Pelota::InitPelota(static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2, static_cast<float>(screenHeight) /50);
		player1 = Paleta::InitPlayer(screenHeight / 10, screenWidth / 3, screenHeight / 22, screenWidth / 10);
		player2 = Paleta::InitPlayer(screenWidth - screenHeight / 10, screenWidth / 3, screenHeight / 22, screenWidth / 10);
		// set up our window and a few resources we need
		
	}
}
}
