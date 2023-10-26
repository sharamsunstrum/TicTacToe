#pragma once 

#include <iostream>
#include <cstdlib> //  For random numbers, so the opponent can place his 'O'

#include "Cursor.h"



struct Opponent : public Cursor
{

	short		yopponent = NULL, 
		        xopponent = NULL;
	
};


class Board : public Opponent 
{

public:

	enum Size
	{

				Y_SIZEBOARD = 3,
				X_SIZEBOARD = 7

	};

	//It's a dynamic multidimensional array to update the Board
	char**		tempboard = nullptr;
	//I create the other pointers with the function  : void Board::CreatingBoardMultidimensionalArray();
	//And deallocate with : void Board::DeallocateMultidimensionalArray()

	//Place X and O into this array to make them permanent , so when it updates
	//it doesn't disapear
	char		fixedboard[Y_SIZEBOARD][X_SIZEBOARD] = {};

	
	void	    B_DetectCursor			    (int& , int&);
	void		B_FixedBoardToTempBoard     (int& , int&);

	void		B_PuttingX           ();
	void		B_OpponentAction     ();
	void	    B_New2DArray         ();
	void	    B_Delete2DArray      ();
	void	    B_Draw2DBoard        ();

};