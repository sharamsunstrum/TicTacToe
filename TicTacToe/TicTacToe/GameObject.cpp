#include"GameObject.h"


	void	 GameObject::G_InputPlayer()
	{

		
		C_ASCII_Input(&inputkey);

	
		C_Exit();

		
		C_MovingCursor();

	}

	char	GameObject::G_WinCheck(char sprite)
	{
		
		bool	center = fixedboard[1][3] == sprite;

		bool	diagonal = 
			fixedboard[2][5] == sprite && fixedboard[0][1] == sprite ||
			fixedboard[2][1] == sprite && fixedboard[0][5] == sprite ;

		bool	horizontal =
			fixedboard[0][1] == sprite && fixedboard[0][3] == sprite && fixedboard[0][5] == sprite ||
			fixedboard[1][1] == sprite && fixedboard[1][3] == sprite && fixedboard[1][5] == sprite ||
			fixedboard[2][1] == sprite && fixedboard[2][3] == sprite && fixedboard[2][5] == sprite
			;
		bool	vertical = 
			fixedboard[0][1] == sprite && fixedboard[1][1] == sprite && fixedboard[2][1] == sprite ||
			fixedboard[0][3] == sprite && fixedboard[1][3] == sprite && fixedboard[2][3] == sprite ||
			fixedboard[0][5] == sprite && fixedboard[1][5] == sprite && fixedboard[2][5] == sprite
			;

		// This is to check all win direction
		if (center && diagonal || horizontal || vertical)
		{
			
				gameover = true;
				return sprite;

		}




		return NULL;
	}

	void	 GameObject::G_DrawFrame()
	{

		
		B_New2DArray();

		
		B_Draw2DBoard();

		
		B_Delete2DArray();

	}


	void	 GameObject::G_Update()
	{
		
		char x = NULL;
		char o = NULL;

		while (!gameover)
		{

			G_InputPlayer();

			//Clear the frame so I can redraw over
			system("cls");

			G_DrawFrame();

			 x = G_WinCheck(X);
			 o = G_WinCheck(O);

		}

		FinalMessage(x|o);

	}

	void	FinalMessage(char sprite)
	{

		switch (sprite)
		{
		case 'x':
			std::cout << " You Win ! " << "\n";
			break;
		case 'o':
			std::cout << " You Loose ! " << "\n";
			break;
		default:
			std::cout << " Draw ! " << "\n";
			break;
		}

	}
