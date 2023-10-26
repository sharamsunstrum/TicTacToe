#pragma once

#include <conio.h> // For the Input



class Cursor
{ 

public:

	//			ASCII TABLE NUMBER WITH KEYBOARD INPUT
	enum Keyboard
	{

				 UP = 119, //'w'
				 DOWN = 115, //'s'
				 RIGHT = 100, //'d'
				 LEFT = 97, //'a'
				 F = 102, // 'f'
				 EXIT = 27 // 'Esc'
	
	};

	
	enum Sprites
	{

				 SPACE = ' ',
				 BAR = '|',
				 CURSOR = '^',
				 X = 'x',
				 O = 'o'
	
	
	};

	int	         xcursor  =  NULL; 
	int	         ycursor  =  NULL; 
	

	int			 inputkey =  NULL;
	bool		 fbutton  =  false;

	
	void		 C_ASCII_Input(int* arg_keyboardInput);
	void		 C_Exit();
	void		 C_MovingCursor();

};
