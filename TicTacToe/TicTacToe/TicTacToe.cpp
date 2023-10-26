#include <iostream> 


#include "GameObject.h"



/////////////////////////--RULE--////////////////////////////////////
/*

	In front of each function place a letter that belong to the class

	for methods
	C_ = Cursor Class		    example:	C_function
	B_ = Board Class			example:	B_function
	G_ = GameObject Class	    example:	G_function
	OP_ = Opponent Class		example:	OP_function


*/


//	DRAWING REFERENCE SAMPLE
//--------------------------------


//	| |^|x|  3x7 caracters
//	| |o| |  ^ = cursor
//	| | |x|



int main()
{


	GameObject* gameobject = new GameObject(0,1);

	if (!gameobject) { std::cerr << " ERROR : Instantiate object gameobject failed. Line 49 : TicTacToe.cpp " << std::endl; return 1; }

	else
	{

		//I display a message, to inform the player of his controller
		auto message = []() {
			std::cout << "\t Welcome to Tic Tac Toe Game!!! Take a seat! And fight against our AI! \n";
			std::cout << "\t To move : WASD, to place your 'X' press F ... to Exit press ESC \n";
			std::cout << "\t \t To start the game press any key! ";
			};

		message();

		//Is to display everything, and update the frames
		gameobject->G_Update();

		delete gameobject;
		gameobject = nullptr;

		system("pause");
	}

	return 0;

}
