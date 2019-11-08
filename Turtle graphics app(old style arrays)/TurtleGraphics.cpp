//TurtleGraphics.cpp to create the TurtleGraphics rules for processing assign6.cpp
//
//Lawrence Jest
//March 1, 2018


#include <iostream>
#include <iomanip>
#include "TurtleGraphics.h"

using namespace std;

//function displayFloor() to display the board the turtle will navigate
//
void TurtleGraphics::displayFloor() const
{
	for (int rows = 0; rows <= NROWS; ++rows)
	{
		cout << "\n";
		for (int columns = 0; columns <= NCOLS; ++columns)
		{
			if (m_Floor[rows][columns] == true) //change this to true at the end for the proper solution
			{
				cout << setw(1) << "*";
			}
			else
			{
				cout << setw(1) << "";//do nothing to not print the falses
			}
		}
	}
	cout << "\n\n";
}


//ctor will init. floor to all "false" values, 
//as well as initialization of other data members
TurtleGraphics::TurtleGraphics(void)
{
	for (int rows = 0; rows < NROWS; ++rows)
	{
		for (int columns = 0; columns < NCOLS; ++columns)
		{
			m_Floor[rows][columns] = false;
		}
	}

	Directions STARTING_DIRECTION = SOUTH;
	bool STARTING_PEN_POSITION = false;
	int STARTING_ROW = 0;
	int STARTING_COL = 0;

	//currentCommand = 0;
	//bool m_Floor[NROWS][NCOLS];
	//const int SET_DISPLAY_WIDTH = 5;
}


// will process
// the commands contained in array "commands"
void TurtleGraphics::processTurtleMoves(const int commands[])
{

	static int currentCommand = commands[0];
	static int currentRow = 0;
	static int currentColumn = 0;
	static bool currentPen = false;
	Directions currentFacing = SOUTH;
	int movementAmount = 0;
	int counter = 0;


	//keep looping until end of line command is hit
	while (currentCommand != 9)
	{
		currentCommand = *&(commands[counter]);



		switch (currentCommand)
		{
		case PEN_UP: currentPen = false;
			break;

		case PEN_DWN: currentPen = true;
			break;

		case TURN_RIGHT:

			switch (currentFacing)
			{
			case SOUTH: currentFacing = WEST;
				break;

			case NORTH: currentFacing = EAST;
				break;

			case WEST: currentFacing = NORTH;
				break;

			case EAST: currentFacing = SOUTH;
				break;
			}
			;//end turn right case
			break;

		case TURN_LEFT:

			switch (currentFacing)
			{
			case SOUTH: currentFacing = EAST;
				break;

			case NORTH: currentFacing = WEST;
				break;

			case WEST: currentFacing = SOUTH;
				break;

			case EAST: currentFacing = NORTH;
				break;
			}

			;//end turn left case				
			break;

		case MOVE:

			counter++;
			movementAmount = *&(commands[counter]);

			switch (currentFacing)
			{
			case SOUTH:  if (currentRow + movementAmount <= NROWS)
			{
				//move that amount
				for (int counter = 0; counter < movementAmount; ++counter)
				{
					if (currentPen)
					{
						m_Floor[currentRow][currentColumn] = true;
						++currentRow;
					}
					else
					{
						++currentRow;
					}
				}
			}
						 else
						 {
							 movementAmount = NROWS - currentRow;//move only the amount possible
																 //then move that amount
							 for (int counter = 0; counter < movementAmount; ++counter)
							 {
								 if (currentPen)
								 {
									 m_Floor[currentRow][currentColumn] = true;
									 ++currentRow;
								 }
								 else
								 {
									 ++currentRow;
								 }
							 }
						 }
						 ;//end case
						 break;

			case NORTH: if (currentRow - movementAmount >= 0)
			{
				//move that amount
				for (int counter = 0; counter < movementAmount; ++counter)
				{
					if (currentPen)
					{
						m_Floor[currentRow][currentColumn] = true;
						--currentRow;
					}
					else
					{
						--currentRow;
					}
				}
			}
						else
						{
							movementAmount = currentRow;//move only the amount possible
														//then move that amount
							for (int counter = 0; counter < movementAmount; ++counter)
							{
								if (currentPen)
								{
									m_Floor[currentRow][currentColumn] = true;
									--currentRow;
								}
								else
								{
									--currentRow;
								}
							}
						}
						;//end case
						break;

			case WEST:if (currentColumn - movementAmount >= 0)
			{
				//move that amount
				for (int counter = 0; counter < movementAmount; ++counter)
				{
					if (currentPen)
					{
						m_Floor[currentRow][currentColumn] = true;
						--currentColumn;
					}
					else
					{
						--currentColumn;
					}
				}
			}
					  else
					  {
						  movementAmount = currentColumn;//move only the amount possible
														 //then move that amount
						  for (int counter = 0; counter < movementAmount; ++counter)
						  {
							  if (currentPen)
							  {
								  m_Floor[currentRow][currentColumn] = true;
								  --currentColumn;
							  }
							  else
							  {
								  --currentColumn;
							  }
						  }
					  };//end case
					  break;

			case EAST: if (currentColumn + movementAmount <= NCOLS)
			{
				//move that amount
				for (int counter = 0; counter < movementAmount; ++counter)
				{
					if (currentPen)
					{
						m_Floor[currentRow][currentColumn] = true;
						++currentColumn;
					}
					else
					{
						++currentColumn;
					}
				}
			}
					   else
					   {
						   movementAmount = NCOLS - currentColumn;//move only the amount possible
																  //then move that amount
						   for (int counter = 0; counter < movementAmount; ++counter)
						   {
							   if (currentPen)
							   {
								   m_Floor[currentRow][currentColumn] = true;
								   ++currentColumn;
							   }
							   else
							   {
								   ++currentColumn;
							   }
						   }
					   };//end case
					   break;

			default:;//end case
				break;
			}

			;//end move case
			break;//break move case

		case DISPLAY: displayFloor();
			break;

		default:;//default case do nothing should never get here
			break;
		}
		counter++;//move forward one for the derefenced command arary 
	}


}




