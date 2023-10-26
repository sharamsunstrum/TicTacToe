#include "Cursor.h"
#include <iostream>

	void	 Cursor::C_ASCII_Input(int* arg_input)
	{

		//_getch() takes an input from the keyboard
		*arg_input = _getch();

	}


	void	 Cursor::C_Exit()
	{

		if(inputkey == EXIT)exit(EXIT_SUCCESS);

	}


	void	 Cursor::C_MovingCursor()
	{

		switch (inputkey)
		{
		case UP : 
			ycursor = std::abs((ycursor - 1) % 3); break;

		case DOWN : 
			ycursor = ((ycursor + 1) % 3);         break;

		case RIGHT :
			xcursor = ((xcursor + 2) % 6);         break;

		case LEFT :
			xcursor = std::abs((xcursor - 2) % 6); break;

		case F :
			fbutton = true;                        break;
			
		}
		//		-Explanation on the calculation of the coordinate-
		// Modulo the number so it doesn't go out of the multidimensional
		// array, and use std::abs because if it's 0 - 1 = -1... it change 
		// into 0-1 = 1 .

	}

