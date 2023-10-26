#pragma once

#include "Board.h"


void	FinalMessage(char);


class GameObject : public Board
{
public:


	bool	gameover = false;


	GameObject (int y, int x) 
	{

			this -> xcursor = x;
			this -> ycursor = y;

	}

	~GameObject () {}



	void	G_InputPlayer ();
	char	G_WinCheck(char sprite);
	void	G_DrawFrame   ();
	void	G_Update      ();


};