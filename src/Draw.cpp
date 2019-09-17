#include "../Headers/Pantalla gameplay.h"



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

void DrawGamePlay(Ball& Pelota, Player& Player1, Player& Player2, int& CurrentScreen)
{
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
		Menu(Player1, Player2, Pelota, CurrentScreen);
	}
	if (Player1.Puntos > 1) { GameOver( Player1, Player2, Pelota, CurrentScreen); }
	if (Player2.Puntos > 1) { GameOver( Player1, Player2, Pelota, CurrentScreen); }

	slRender(); // draw everything
}

void DrawMenu() {
	TextColor(Green);
	slSetFontSize(30);
	slText(60, screenHeight / 2, "Presion esc para salir y enter para iniciar ");
	slRender();
}

void DrawGameOver() {
	slSetFontSize(30);

	TextColor(Red);
	slText(60, screenHeight / 2, "Player 1 victory");
	//Player 1 win

	TextColor(Blue);
	slText(60, screenHeight / 2, "Player 2 victory");
	//Player 2 win

	slRender();
}