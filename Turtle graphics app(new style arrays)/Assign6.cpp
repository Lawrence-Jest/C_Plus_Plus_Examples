// Assign 6 Main Program - used to "test drive" the TurtleGraphics class
// File Name: Assign6.cpp
// Author: Bob Langelaan
// Date: Nov. 7, 2013

// This program implements Turtle Graphics

// include and using statments


#include "TurtleGraphics.h"
#include <iostream>
#include <array>
using namespace std;

int main()
{
   // Declarations

   array<int, TurtleGraphics::ARRAY_SIZE> cmds = {5,5,4,5,9,2,    // go to start of first letter and put pen down

	             // B
	             5,12, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,           
				 1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

				 1,5,5,3,5,22,2, // go to start of next letter and put pen down

				 // O
				 5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,                                  
				 1,3,5,1,2,5,10, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,7, 1,3,5,1,4,2,5,1,

				 1,3,5,19,2,     // go to start of next letter and put pen down

				 // B
				 5,12, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,           
				 1,3,5,12,3,5,5, 5,1,4,2,5,1, 1,3,5,1,2,5,2, 1,3,5,1,4,2,5,1, 1,3,5,1,2,5,11, 3,5,5,

				 // Test program bound checking and add border in the process

				 //   Uncomment next line when ready to test bound checking
				 1,5,100,2,4,5,100,4,5,100,4,5,100,4,5,100,4,5,100,

				 1,6,9}; // finish off

   std::array< int, TurtleGraphics::ARRAY_SIZE> cmds1 = { 5,3, 4, 5, 6, 2, 5, 1, 1,5,5,2,5,1,1,5,8,2,5,4,1,5,9,2,5,2,1, //row 1
	   5,9,2,5,4,1,5,8,2,5,1,1,5,5,2,5,1,1,3,

	   5,1,3,5,2,2,5,1,1,5,3,2,5,1,1,5,6,2,5,10,1,5,5,2,5,4,1,5,5,2,5,10,1,5,6,2,5,1,1,5,3,2,5,1,1,5,2, //row 2

	   4,5,1,4,5,2,2,5,7,1,5,4,2,5,12,1,5,3,2,5,6,1,5,3,2,5,12,1,5,4,2,5,7,1,5,1, //row 3

	   3,5,1,3,5,1,2,5,2,1,5,1,2,5,3,1,5,1,2,5,2,1,5,3,2,5,3,1,5,2,2,5,2,1,5,2,2,5,3,1,5,2,2,5,2,1,5,1,// row 4
	   2,5,2,1,5,1,2,5,2,1,5,2,2,5,3,1,5,2,2,5,2,1,5,2,2,5,3,1,5,3,2,5,2,1,5,1,2,5,3,1,5,1,2,5,2,1,4,

	   5,1,4,2,5,11,1,5,2,2,5,12,1,5,2,2,5,8,1,5,2,2,5,12,1,5,2,2,5,11,1,3, //row 5

	   5,1,3,5,1,2,5,1,1,5,1,2,5,7,1,5,1,2,5,1,1,5,5,2,5,2,1,5,2,2,5,2,1,5,7,2,5,1,1,5,2,2,5,1,1,5,7,2,//row 6
	   5,2,1,5,2,2,5,2,1,5,5,2,5,1,1,5,1,2,5,7,1,5,1,2,5,1,1,4,

	   5,1,4,5,1,2,5,1,1,5,1,2,5,1,1,5,5,2,5,1,1,5,1,2,5,1,1,5,4,2,5,2,1,5,1,2,5,2,1,5,1,2,5,2,1,5,5,2,//row 7
	   5,1,1,5,1,2,5,2,1,5,1,2,5,1,1,5,5,2,5,2,1,5,1,2,5,2,1,5,1,2,5,2,1,5,4,2,5,1,1,5,1,2,5,1,1,5,5,2,5,1,1,5,1,2,5,1,1,3,

	   5,1,3,5,4,2,5,2,1,5,1,2,5,2,1,5,5,2,5,2,1,5,8,2,5,2,1,5,2,2,5,1,1,5,1,2,5,1,1,5,2,2,5,1,1,5,1,2,//row 8
	   5,1,1,5,2,2,5,2,1,5,8,2,5,2,1,5,5,2,5,2,1,5,1,2,5,2,1,4,

	   5,4,4,5,9,2,5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,5,2,2,5,3,1,5,1,2,5,3,1,5,1,2,//row 9
	   5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,3,

	   5,1,3,5,2,2,5,1,1,5,2,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,2,2,5,1,1,5,4,2,5,1,1,5,4,2,//row 10
	   5,1,1,5,3,2,5,1,1,5,3,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,4,

	   5,1,4,5,1,2,5,3,1,5,1,2,5,2,1,5,2,2,5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,5,2,2,5,3,1,5,2,2,5,1,1,5,2,2,//row 11
	   5,3,1,5,1,2,5,2,1,5,3,2,5,1,1,3,

	   5,1,3,5,1,2,5,1,1,5,2,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,2,2,5,1,1,5,2,2,5,1,1,5,4,2,//row 12
	   5,1,1,5,3,2,5,1,1,5,5,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,3,2,5,1,1,4,

	   5,1,4,5,1,2,5,1,1,5,3,2,5,1,1,5,1,2,5,1,1,5,1,2,5,3,1,5,1,2,5,3,1,5,1,2,5,3,1,5,2,2,5,3,1,5,2,2,// row 13
	   5,1,1,5,2,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,1,2,5,1,1,5,2,2,5,1,1,3,

	   5,100,4,2,5,100,4,5,100,4,5,100,4,5,100,4,5,100,4,5,100,

	   6,9 };

   // go to start of first letter and put pen down
   std::array< int, TurtleGraphics::ARRAY_SIZE> cmds2 = { 5, 6, 4, 5, 11, 2,
	   //row 7
	   5, 9,  1, 5, 9,  2, 5, 7,  1, 5, 7,  2, 5, 2,  1, 5, 5,  2, 5, 10,
	   // row 8
	   2, 3, 5,1,   3, 5, 11, 1, 5, 5, 2, 5, 2, 1, 5, 6, 2, 5, 1, 1, 5, 7, 2, 5, 1, 1, 5, 7, 2, 5, 1, 1, 5, 8, 2, 5, 1, 1, 4,5,1,
	   // row 9
	   1,4,5,1,    2, 5, 1,  1, 5, 9, 2,  5, 1, 1, 5, 5, 2, 5, 1, 1, 5, 9, 2, 5, 1, 1, 5, 5, 2, 5, 2, 1, 5, 9, 2, 5, 2,
	   //row 10
	   1, 3, 5, 1,  1,3,5,1,   2, 5, 2, 1, 5, 9, 2, 5, 2, 1, 5, 15, 2, 5, 1, 1, 5, 5, 2, 5, 1, 1, 5, 9, 2, 5, 1,
	   // row 11
	   1, 4, 5, 1, 1,4,5,1,  2, 5, 1, 1, 5, 8, 2, 5, 1, 1, 5, 6, 2, 5, 1, 1, 5, 15, 2, 5, 2, 1, 5, 9, 2, 5, 2,
	   //row 12
	   1, 3, 5, 1,  1,3,5,1,  2,5, 2, 1, 5, 9, 2, 5, 2, 1, 5, 15, 2, 5, 1, 1, 5, 7, 2, 5, 9,
	   //row 13
	   1, 4, 5, 1,  1,4,5,1,  2, 5, 1,  1, 5, 8, 2, 5, 1, 1, 5, 6, 2, 5, 1, 1, 5, 15, 2, 5, 2, 1, 5, 9, 2, 5, 2,
	   //row 14
	   1, 3, 5, 1, 1,3,5,1,  2, 5, 2, 1, 5, 9, 2, 5, 2, 1, 5, 15, 2, 5, 1, 1, 5, 5, 2, 5, 1, 1, 5, 9, 2, 5, 1,
	   //row 15
	   1, 4, 5, 1,  1,4,5,1, 2, 5, 1, 1, 5, 9, 2, 5, 1, 1, 5, 5, 2, 5, 1, 1, 5, 9, 2, 5, 1, 1, 5, 5, 2, 5, 2, 1, 5, 9, 2, 5, 2,
	   //row 16
	   1, 3, 5, 1,  1,3,5,1,  2, 5, 2, 1, 5, 9, 2, 5, 2, 1, 5, 6, 2, 5, 1, 1, 5, 7, 2, 5, 1, 1, 5, 7, 2, 5, 1, 1, 5, 8, 2, 5, 1,
	   //row17
	   1, 4, 5, 1,  1,4,5,1,  2,  5, 9, 1, 5, 9, 2, 5, 7, 1, 5, 7, 2, 5, 2, 1, 5, 9, 2, 5, 2,
	   //Display border
	   1, 5, 100, 2, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100,
	   // finish off
	   1, 6, 9 };



   //my turtle path ARRAY_SIZE must be set to 1000
   std::array< int, TurtleGraphics::ARRAY_SIZE> cmds3 = { 5,3,4,5,20,3,2,5,7,4,4,5,4,3,5,3,3,5,4,4,4,5,7,3,5,1,1,	   //first letter

	   5,2,2,3,5,7,4,5,4,4,1,5,4,4,5,1,2,5,3,3,5,3,3,5,4,1, //second letter	   

	   5,2,2,3,5,7,4,5,4,1, //third letter

	   5,2,2,5,3,4,4,5,3,3,5,8,1,//fourth letter

	   3,5,6,3,5,1,2,5,7,4,5,3,4,5,7,4,5,3,//fifth letter

	   1,4,5,9,3,5,24,4,//go to next line
	   
	   2,5,7,4,5,2,4,5,3,4,4,5,3,4,5,2,4,5,7,3,5,1,1,//sixth letter

	   5,2,2,3,5,7,4,5,3,4,5,7,4,5,3,1,//seventh letter

	   3,3,5,6,3,2,5,7,4,5,1,1,5,3,2,4,5,2,4,5,1,3,5,1,5,1,4,5,3,3,5,3,3,5,4,3,5,4,1,//eighth letter

	   4,5,3,3,2,5,3,4,5,3,4,4,5,3,3,5,8,1, //nineth letter

	   3,5,6,3,5,1,2,5,7,4,5,2,1,4,5,1,3,2,5,1,1,4,5,1,2,5,1,5,3,1,4,5,1,2,3,5,1,1,4,5,1,2,5,1,1, //tenth letter 	                 
      														  
	   1, 5, 100, 2, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100, //Display border
	   
	   1, 6, 9 }; // finish off


	
   TurtleGraphics turtleOne;  // create a TurtleGraphics object

   turtleOne.processTurtleMoves(cmds3); // have turtle process commands

   system("pause");
   return 0;  // we are finished, let's go home
}
