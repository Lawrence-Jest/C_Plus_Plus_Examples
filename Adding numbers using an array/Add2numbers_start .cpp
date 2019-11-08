//
// Purpose:  Read in 2 positive integral numbers with up to MAX_DIGITS digits,
//  add them together and display the result.
//
// Note: If result is more than MAX_DIGITS, an INCORRECT result will be displayed.
// Therefore if reading in 2 numbers with n digits, and the result may be n+1
//  digits, MAX_DIGITS should be set to n+1 to ensure the correct result will be
// calculated and displayed.
//
// Author: Lawrence Jest
// Date:   March 24, 2018
//

#include <iostream>
#include <conio.h>


using namespace std;

// Function prototypes
void readNumber(unsigned short []);
void writeNumber(const unsigned short []);
void addNumbers(const unsigned short [], const unsigned short [],
				unsigned short []);

//global constants
const unsigned int MAX_DIGITS = 41; // Largest result that can be calculated!
const unsigned int NEWLINE_NUMBER = 65498; // new line ascii value for windows,
								//may be different on other operating systems
const unsigned int VALUE_TO_ADD_TO_NEXT_DIGIT = 1; // Add one to next digit
													//location 
const unsigned int DIGIT_LARGER_THAN_SINGLE_PLACE = 10; // Can only add single 
		//digits so anything over ten must be carried over to next array location

int main()
{
	//Declare variables
	unsigned short number1[MAX_DIGITS]{};
	unsigned short number2[MAX_DIGITS]{};
	unsigned short result[MAX_DIGITS]{};

	// Read in 2 numbers
	cout << "Enter in the first number (max " << MAX_DIGITS << " digits):"
		<< endl;

	readNumber(number1);

	cout << "\nEnter in the second number (max " << MAX_DIGITS << " digits):" 
		<< endl;
	readNumber(number2);

	// Add the 2 numbers into result
	addNumbers(number1, number2, result);

	// Display original numbers and answer
	cout << "\nThe result of adding the 2 numbers input is:\n\n ";
	writeNumber(number1);

	cout << "\n+";
	writeNumber(number2);
	
	cout << '\n';
	//cout << " ==============================" << endl;
	cout << " ";
	for (int loopCounter =0; loopCounter < MAX_DIGITS; ++loopCounter) 
	{
		cout << "=";
	}
	cout << "\n";
	cout << " ";
	writeNumber(result);

	cout << '\n' << endl;

	_getch(); // Causes execution to pause until char is entered

}

// Function reads in number up to MAX_DIGITS digits in length
void readNumber(unsigned short input[])
{
	char charDigit = 0; // Initialize charDigit
	unsigned short numericalRepresentationOfChar = 0; // Initialize 
												//numericalRepresentationOfChar
	int counter = 0; // Initialize counter
	unsigned short pushedArray[MAX_DIGITS]{}; // Temp array to hold pushed numbers
	int amountOfNumbersToBePushed = 0; // Initialize amountOfNumbersToBePushed
								//which will be how many numbers we need to push
	
	while (charDigit != '\n') // Check for newline character
	{
		charDigit = cin.get();
		
		numericalRepresentationOfChar = charDigit - '0'; // Change char into short
		
		if (numericalRepresentationOfChar != NEWLINE_NUMBER)// Dont want newline #
		{
			if (counter < MAX_DIGITS) // Check digits are MAX_DIGITS length only
			{
				input[counter] = numericalRepresentationOfChar;
			}			
		}

		++counter;

	}
	
	--counter; // Get rid of newline counter increase

	amountOfNumbersToBePushed = counter; // This lets us know how many
										//numbers to move
		
	if (counter <= MAX_DIGITS) // Check for MAX_DIGITS 
	{
		for (int arrayCount = 0; arrayCount < amountOfNumbersToBePushed;
			++arrayCount)
		{
			// The next line will push the numbers to the end of the array
			pushedArray[MAX_DIGITS - counter] = input[arrayCount];
			--counter;


		}
	}
	else 
	{
		counter = MAX_DIGITS; // Get rid of extra digits above MAX_DIGITS value

		amountOfNumbersToBePushed = MAX_DIGITS; // Dont loop through array more
												//than MAX_DIGITS times

		for (int arrayCount = 0; arrayCount < amountOfNumbersToBePushed;
			++arrayCount)
		{
			// The next line will push the numbers to the end of the array
			pushedArray[MAX_DIGITS - counter] = input[arrayCount];
			--counter;

		}

	}
	

	for (int arrayCount = 0; arrayCount < MAX_DIGITS; ++arrayCount) 
	{
		// The next line will save the pushed numbers back to the input array
		input[arrayCount] = pushedArray[arrayCount];
	}
	
}

// Function writes out number up to MAX_DIGITS digits in length
void writeNumber(const unsigned short output[])
{
	bool noZero = true; // Start true so as not to print zeroes before any
						//positive numbers are encountered
	
	for (int arrayCount = 0; arrayCount < MAX_DIGITS; ++arrayCount)
	{		
		if (output[arrayCount]==0) 
		{
			if (noZero == true)
			{
				cout << " "; // print space instead of zeroes
			}
			else 
			{
				cout<< output[arrayCount]; // Print zeroes after first positive
										  //number encountered
			}
			
		}
		else 
		{
			cout << output[arrayCount];
			noZero = false; // Set to false to start printing zeroes after
							//a number is encountered
		}
		
	}

}

//Function adds first 2 arrays (num1 and num2) and puts result in 3rd array ->sum
void addNumbers(const unsigned short num1[], const unsigned short num2[], 
				unsigned short sum[])
{
	int arrayPlace = 1; // Start at 1 so as not to stack overflow, 
	                   //this is location of sum array to write to
	unsigned short tempSum = 0; // Temporary value of array addition
	unsigned short tempSumOverTen = 0; // Temporary value of one's place 
									  //if addition of arrays is over 10	
	bool overTen = false; // bool value to check against if addition is over 10

	for (int arrayCount = 0; arrayCount < MAX_DIGITS; ++arrayCount) 
	{
		if (overTen == true)//check if the last sum was over ten and add 1 to sum
		{
			tempSum = num1[MAX_DIGITS - arrayPlace] +
					  num2[MAX_DIGITS - arrayPlace] +
					  VALUE_TO_ADD_TO_NEXT_DIGIT;

			overTen = false; //set to false to reset
		}
		else
		{
			tempSum = num1[MAX_DIGITS - arrayPlace] + 
					  num2[MAX_DIGITS - arrayPlace];
		}
		
		if (tempSum < DIGIT_LARGER_THAN_SINGLE_PLACE) // Check if last sum 
													 //was over 10
		{
			sum[MAX_DIGITS - arrayPlace] = tempSum;
		}
		else 
		{
			tempSumOverTen = tempSum - DIGIT_LARGER_THAN_SINGLE_PLACE; // get ones
													  //place of last sum over 10
			sum[MAX_DIGITS - arrayPlace] = tempSumOverTen; // put ones place in
															//array sum
			overTen = true; // Set to true to let the next iteration of for loop 
							//add 1 to sum
			
		}
		
		++arrayPlace; // increase arrayPlace to move backwards through the arrays

	}
	
}
