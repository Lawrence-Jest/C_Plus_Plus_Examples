//TurtleGraphics.cpp to create the TurtleGraphics rules for processing assign6.cpp
//
//Lawrence Jest-A00583216
//March 1, 2018


#include <iostream>
#include <iomanip>
#include "TurtleGraphics.h"
#include <array>
#include <cstddef>

using namespace std;

//function displayFloor() to display the board the turtle will navigate
//
void TurtleGraphics::displayFloor() const
{
	for (size_t rows = 0; rows < m_Floor.size(); ++rows)	
	{
		cout << "\n";

		for (size_t columns = 0; columns < m_Floor[rows].size(); ++columns)		
		{
			if (m_Floor[rows][columns]==true) 
			{
				cout << setw(SET_WIDTH_FOR_DISPLAY) <<"*";
			}
			else 
			{
				cout << setw(SET_WIDTH_FOR_DISPLAY) << " ";
			}
		}
	}
	cout << "\n\n";
}


//ctor will init. floor to all "false" values, 
//as well as initialization of other data members
TurtleGraphics::TurtleGraphics(void)
{	
	
	for (size_t rows = 0; rows < m_Floor.size(); ++rows)	
	{
		for(size_t columns = 0; columns < m_Floor[rows].size(); ++columns)		
		{
			m_Floor[rows][columns] = false;			
		}
	}		
	Directions STARTING_DIRECTION = Directions::SOUTH;
	bool STARTING_PEN_POSITION = false;
	int STARTING_ROW = 0;
	int STARTING_COL = 0;
	
}


// will process
// the commands contained in array "commands"
void TurtleGraphics::processTurtleMoves(const array< int, ARRAY_SIZE> &myArray)
{

	static unsigned short  currentCommand = 0;
	static int currentRow = 0;
	static int currentColumn = 0;
	static bool currentPen = false;
	Directions currentFacing = Directions::SOUTH;	
	int movementAmount = 0;
	int counter = 0;
	
	
	//keep looping until end of line command is hit	
	while(currentCommand != TERMINAL_INT)
	{

		currentCommand = myArray[counter];		

			switch (static_cast<Cmds>(currentCommand))
			{
			case Cmds::PEN_UP: currentPen = false;
				break;

			case Cmds::PEN_DWN: currentPen = true;
				break;

			case Cmds::TURN_RIGHT:
				
				switch (static_cast<Directions>(currentFacing)) 
				{
				case Directions::SOUTH: currentFacing = Directions::WEST;
					break;

				case Directions::NORTH: currentFacing = Directions::EAST;
					break;

				case Directions::WEST: currentFacing = Directions::NORTH;
					break;

				case Directions::EAST: currentFacing = Directions::SOUTH;
					break;

				default:;//default switch(curretnFacing) for turn right
					break;
				}//end switch(curretnFacing) for Turn right
				;//end turn right case
				break;

			case Cmds::TURN_LEFT:
				
				switch (static_cast<Directions>(currentFacing))
				{
				case Directions::SOUTH: currentFacing = Directions::EAST;
					break;

				case Directions::NORTH: currentFacing = Directions::WEST;
					break;

				case Directions::WEST: currentFacing = Directions::SOUTH;
					break;

				case Directions::EAST: currentFacing = Directions::NORTH;
					break;
				default:;//default switch(currentFacing) for turn left
					break;
				}	//end switch(currentFacing) for Turn left			
				;//end turn left case				
				break;
				
			case Cmds::MOVE:

				counter++;
				movementAmount = myArray[counter];
				
				switch (static_cast<Directions>(currentFacing))
				{
				case Directions::SOUTH: 

					if (currentRow + movementAmount < NROWS)
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
					//move only possible amount
					movementAmount = (NROWS- ARRAY_LIMIT_CORRECTER) - currentRow;
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
				;//end case SOUTH
					break;

				case Directions::NORTH:

					if (currentRow - movementAmount > 0)
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
					//move only the amount possible
					movementAmount = currentRow;
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
				;//end case NORTH
					break;

				case Directions::WEST:

					if (currentColumn - movementAmount > 0)
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
					//move only the amount possible
					movementAmount = currentColumn;
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
					}
				;//end case WEST
					break;
					
				case Directions::EAST: 

					if (currentColumn + movementAmount < NCOLS)
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
						//move only the amount possible
						movementAmount = (NCOLS- ARRAY_LIMIT_CORRECTER) - currentColumn;

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
					}
				;//end case EAST
					break;

				default:;//default for switch move(curretnFacing)
					break;
				
				}//end switch(currentfacing) 
				;//end move case
					break;

			case Cmds::DISPLAY: displayFloor();
				break;
							
			default:;//default case for switch(currentCommand)
				break;

			}//end switch(currentCommand)

		counter++;//move forward one for the command arary 

	}//end while loop			
		
}




