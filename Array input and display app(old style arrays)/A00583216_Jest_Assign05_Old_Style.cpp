//A00583216_Jest_Assign_05 to simulate Fig 7.14 from textbook
//
//Lawrence Jest
//Feb 25, 2018


#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


const int ARRAY_ROW_SIZE = 4;
const int ARRAY_COLUMN_SIZE = 5;
const int VALID_RANGE_MINIMUM = 10;
const int VALID_RANGE_MAXIMUM = 100;
const int SET_DISPLAY_WIDTH = 5;
int inputCounter = 1; //array starts at 0 but we want the number to be enetered to start at 1 for logical sense
int simpleArray[ARRAY_ROW_SIZE][ARRAY_COLUMN_SIZE]{};
int input;
bool isUnique();
void inputArray();
void displayArray();



int main()
{
	inputArray();
	displayArray();
	cout << "\n\n" << "press any key to continue" << endl; //pause program to see results
	_getch(); //this function does the pausing of the program
	return 0;
}

//function isUnique to walk the array and check if the int input is already in the array, 
//return true if the int input is unique
bool isUnique()
{
	for (int arrayRowPosition = 0; arrayRowPosition < ARRAY_ROW_SIZE; ++arrayRowPosition)
	{
		for (int arrayColumnPosition = 0; arrayColumnPosition < ARRAY_COLUMN_SIZE; ++arrayColumnPosition)
		{
			if (input == simpleArray[arrayRowPosition][arrayColumnPosition]) {
				return false;
			}

		}

	}
	cout << "The number: " << input << " is unique." << endl;
	return true;
}

//function inputArray() to walk through the array and accept an int input from the user 
//if it is in the valid range as set by const int validRangeMinimum and const int validRangeMaximum
void inputArray()
{

	for (int arrayRow = 0; arrayRow < ARRAY_ROW_SIZE; ++arrayRow)
	{
		for (int arrayColumn = 0; arrayColumn < ARRAY_COLUMN_SIZE; ++arrayColumn)
		{

			cout << "\nEnter #" << inputCounter << ": ";

			cin >> input;

			if (input < VALID_RANGE_MINIMUM || input > VALID_RANGE_MAXIMUM)
			{
				cout << "\nThe number you entered is out of the valid range (" << VALID_RANGE_MINIMUM << " - " << VALID_RANGE_MAXIMUM << ")\n";
				--arrayColumn;
			}
			else
			{
				if (isUnique())
				{
					simpleArray[arrayRow][arrayColumn] = input;
				}
				else
				{
					//do nothing
				}
				++inputCounter;
			}

		}
	}

}


//function displayArray() to walk through the array and print out the integers in the array
//and print nothing if the array element contains a 0. 
void displayArray()
{
	cout << "\nThe unique numbers are:\n";

	for (int arrayCounterRow = 0; arrayCounterRow < ARRAY_ROW_SIZE; ++arrayCounterRow)
	{
		cout << "\n";

		for (int arrayCounterColumn = 0; arrayCounterColumn < ARRAY_COLUMN_SIZE; ++arrayCounterColumn)
		{
			if (0 == simpleArray[arrayCounterRow][arrayCounterColumn])
			{
				//do nothing so as not to print the 0's because they are invalid numbers according to inputArray()
			}
			else
			{
				cout << setw(SET_DISPLAY_WIDTH) << simpleArray[arrayCounterRow][arrayCounterColumn];
			}

		}

	}

}












