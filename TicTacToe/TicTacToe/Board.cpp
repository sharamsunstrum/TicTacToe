#include "Board.h" 
	
	void	 Board::B_DetectCursor(int& arg_y, int& arg_x)
	{

		bool detect = arg_x == xcursor && arg_y == ycursor;
		
		if (detect) tempboard[arg_y][arg_x] = CURSOR;

	}

	void	 Board::B_FixedBoardToTempBoard(int& arg_y, int& arg_x)
	{

		bool printboard = fixedboard[arg_y][arg_x] != NULL;

		if (printboard)	tempboard[arg_y][arg_x] = fixedboard[arg_y][arg_x];
		
	}



	void	 Board::B_PuttingX()
	{

		bool	placex = 
			fbutton && fixedboard[ycursor][xcursor] != X && fixedboard[ycursor][xcursor] != O;

		if (placex)
		{
			fixedboard[ycursor][xcursor] = X;

			B_OpponentAction();

			fbutton = false;
		}
		else 
		{
			fbutton = false;
		}
		
	}

	void	 Board::B_OpponentAction()
	{

		bool    row_0 = fixedboard[0][1] != NULL && fixedboard[0][3] != NULL && fixedboard[0][5];
		bool    row_1 = fixedboard[1][1] != NULL && fixedboard[1][3] != NULL && fixedboard[1][5];
		bool    row_2 = fixedboard[2][1] != NULL && fixedboard[2][3] != NULL && fixedboard[2][5];

		//The srand function set the intial value to 0 in this case
		srand((unsigned int)time(NULL));

		yopponent = rand() % 3;


		if (row_0)
		{

			if (yopponent == 0)
			{
				yopponent++;
			}
			if (row_1)
			{
				yopponent++;
			}
		}
		else if (row_1)
		{
			if (yopponent == 1)
			{
				yopponent++;
			}
			if (row_2)
			{
				yopponent -= 2;
			}
		}
		else if (row_2)
		{
			if (yopponent == 2)
			{
				yopponent--;
			}
		}

		

		// it's a bit complex, but it avoids to loop so the
		//performance is faster
		
		if(fixedboard[yopponent][1] != NULL)
		{
			srand(2);
			xopponent = rand() % 6;

			if (xopponent % 2 == 0)	xopponent++;

			if (fixedboard[yopponent][3] != NULL)
			{
				xopponent = 5;
			}
			else if (fixedboard[yopponent][5] != NULL)
			{
				xopponent = 3;
			}
		}
		else if (fixedboard[yopponent][3] != NULL)
		{
			srand(1);
			xopponent = rand() % 2;
			if (xopponent == 2)
			{
				xopponent = 5;
			}

			if (fixedboard[yopponent][5] != NULL)
			{
				xopponent = 1;
			}
		}
		else if (fixedboard[yopponent][5] != NULL)
		{
			
			xopponent = rand() % 3 + 1;
			if (xopponent % 2 == 0)	xopponent++;
		}
		else
		{
			xopponent = rand() % 6;

			if (xopponent % 2 == 0)	xopponent++;
		}

		fixedboard[yopponent][xopponent] = O;
		
		
	}

	void	 Board::B_New2DArray()
	{

		
		tempboard = new char* [Y_SIZEBOARD];
		
		for (int y = 0; y < Y_SIZEBOARD; y++) tempboard[y] = new char[X_SIZEBOARD];
		

	}

	void	 Board::B_Delete2DArray()
	{

		for (int y = 0; y < Y_SIZEBOARD; y++) delete[] tempboard[y];
		
		delete[] tempboard;
		tempboard = nullptr;

	}

	void	 Board::B_Draw2DBoard()
	{

		// I put it there so on each loop it doesn't activate the Random number
		B_PuttingX();
		
		for (int y = 0; y < Y_SIZEBOARD; y++)
		{
			for (int x = 0; x < X_SIZEBOARD; x++)
			{
				
				//if x (example:[y,x]) is a even number add a space into the array else add a '|' 
				(x % 2 == 0) ? tempboard[y][x] = BAR : tempboard[y][x] = SPACE;
				
				B_FixedBoardToTempBoard(y, x);

				B_DetectCursor(y, x);

				std::cout << tempboard[y][x];

			}

			std::cout << "\n";
		}

	}


