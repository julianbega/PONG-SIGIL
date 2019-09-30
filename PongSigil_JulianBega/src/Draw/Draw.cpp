#include "Draw.h"

namespace practicaprofesionaljulianbegapongsigil
{

namespace Draw
{
void ScreenSizeMenu() 
{
	ChangeColor(Green);
	slSetFontSize(screenHeight / 15);
	slText(screenWidth / 13, 0 + screenHeight/10 , "Presione Enter para mantener 800 X 450");
	slText(screenWidth / 13, 0 + screenHeight / 6, "Presione O para 400 X 225");
	slText(screenWidth / 13, 0 + screenHeight / 4, "Presione I para 1200 X 675");
	slText(screenWidth / 13, 0 + screenHeight / 2, "Seleccione una resolucion");
	slRender();
}

void Menu() 
{
	ChangeColor(Green);
	slSetFontSize(screenHeight / 15);
	slText(screenWidth / 4, screenHeight - screenHeight/10, "Bienvenido a PONG SIGIL!! ");
	slText(screenWidth / 4 - screenWidth / 35, screenHeight - screenHeight / 4, "Presione enter para iniciar ");
	ChangeColor(Red);
	slText(screenWidth / 13, screenHeight / 2, "Player 1 ");
	slText(screenWidth / 13, screenHeight / 3, "Controls ");
	slText(screenWidth / 13, screenHeight / 4, "W = arriba ");
	slText(screenWidth / 13, screenHeight / 6, "S = abajo ");
	slText(screenWidth / 13, screenHeight / 8, "");
	ChangeColor(Blue);
	slText(screenWidth - screenWidth / 4 - screenWidth / 6,screenHeight / 2, "Player 2 ");
	slText(screenWidth - screenWidth / 4 - screenWidth / 5, screenHeight / 3, "Controls ");
	slText(screenWidth - screenWidth / 4 - screenWidth / 5, screenHeight / 4, "UpArrow = arriba ");
	slText(screenWidth - screenWidth / 4 - screenWidth / 5, screenHeight / 6, "DownArrow = abajo ");
	slText(screenWidth - screenWidth / 4 - screenWidth / 5, screenHeight / 8, "");
	slRender();
}

void GamePlay(Ball& pelota, Player& player1, Player& player2, int& currentScreen)
{
	slSetFontSize(screenHeight/40);
	ChangeColor(Red);
	slRectangleFill(player1.rec.pos.x, player1.rec.pos.y, player1.rec.width, player1.rec.height);
	ChangeColor(Blue);
	slRectangleFill(player2.rec.pos.x, player2.rec.pos.y, player2.rec.width, player2.rec.height);
	ChangeColor(Yellow);
	slCircleFill(pelota.Position.x, pelota.Position.y, pelota.Radius, pelota.numVertices);

	string PuntosP1 = (" Puntos Player 1: " + (to_string(player1.puntos)));
	string PuntosP2 = (" Puntos Player 2: " + (to_string(player2.puntos)));
	ChangeColor(Red);
	slText(screenHeight/10, screenHeight - screenHeight/22, PuntosP1.c_str());
	ChangeColor(Blue);
	slText(screenWidth - screenWidth/5, screenHeight - screenHeight / 22, PuntosP2.c_str());
	

	slRender(); // draw everything
}


void GameOver(bool P1Win) 
{
	slSetFontSize(screenHeight / 15);

	if (P1Win == true)
	{	
	ChangeColor(Red);
	slText(screenWidth/13, screenHeight / 2, "Player 1 victory");
	slText(screenWidth / 13, screenHeight / 4, "Esc para ir al menu");
	//Player 1 win
	}
	if (P1Win == false)
	{
	ChangeColor(Blue);
	slText(screenWidth / 13, screenHeight / 2, "Player 2 victory");
	slText(screenWidth / 13, screenHeight / 4, "Esc para ir al menu");
	//Player 2 win
	}
	slRender();
}

void ChangeColor(int colorName)
{
	switch (colorName) 
	{
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
	case 5:
		//White
		slSetForeColor(3.0, 1.8, 1.2, 1.0);
		break;
	case 6:
		//Orange
		slSetForeColor(3.0, 1.8, 0.2, 1.0);
		break;
	case 7:
		//Cyan
		slSetForeColor(0.0, 2.8, 1.2, 1.0);
		break;
	case 8:
		//Purple
		slSetForeColor(2.0, 0.0, 2.8, 1.0);
		break;
	default:
		break;
	}
}
}
}