//Fig_6_58.cpp to crete a a math program that outputs a multiplication question using the integers 0-9 and expects a correct answer from the user. if the user gets 
//it wrong a message is displayed. Possible responses to an incorrect answer: No.Please try again., Wrong.Try once more., Don't give up!, No.Keep trying.
//If the user answers correct a message is displayed.  Possible responses to a correct answer: Very good!, Excellent!, Nice work!, Keep up the good work!.
//the program asks a new question.  user exits with a -1.
//
//Lawrence Jest-A00583216
//Feb 3, 2018


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;


const int EXIT_INTEGER = -1;

const int FIRST_RANDOM_INTEGER_SCALE = 10;
const int SECOND_RANDOM_INTEGER_SCALE = 10;

const int RANDOM_CORRECT_MESSAGE_SCALE = 4;
const int RANDOM_CORRECT_MESSAGE_SHIFT = 1;

const int RANDOM_INCORRECT_MESSAGE_SCALE = 4;
const int RANDOM_INCORRECT_MESSAGE_SHIFT = 1;

 

void multiplication(); // function prototype
void correctMessage(); // function prototype
void incorrectMessage(); // function prototype


int main() 
{

	multiplication();

	cout << "That's all for now.  Bye." << '\n' << "Press any key to continue....";
	_getch(); // gets user input to close application

	return 0;
}


//function multilpication to create a multiplication eqution and get a user to try to answer it. display message for users answer accordingly and exit if int const EXIT_INTEGER is entered.
void multiplication() 
{
	int exitInteger = 0;

	srand(time(0)); // set the random seed

	cout << "Enter " << EXIT_INTEGER << " to End." << '\n';

	do  // get user input and loop until user input equals  EXIT_INTEGER.
	{
			
		int userAnswer = 0;		

		int firstRandomInteger = rand() % FIRST_RANDOM_INTEGER_SCALE; // get first random number scale between 0 - FIRST_RANDOM_INTEGER_SCALE.

		int secondRandomInteger = rand() % SECOND_RANDOM_INTEGER_SCALE; // get second random number scale between 0 - SECOND_RANDOM_INTEGER_SCALE.

		int correctEquationAnswer = firstRandomInteger * secondRandomInteger; // get correct answer to equation

		

		cout << "How much is " << firstRandomInteger << " times " << secondRandomInteger << " (" << EXIT_INTEGER << " to End)?";

		cin >> userAnswer; // user input

		exitInteger = userAnswer; // check for EXIT_INTEGER user input to signal exit program
		
		while (userAnswer != correctEquationAnswer && exitInteger != EXIT_INTEGER) // loop if incorrect answer.  also check for EXIT_INTEGER  user input and dont enter statement if it is continu to exit program
		{
			incorrectMessage();

			cin >> userAnswer;

			exitInteger = userAnswer;

		}
		
		if (userAnswer == correctEquationAnswer && exitInteger != EXIT_INTEGER) // display correct message.  check for EXIT_INTEGER user input and dont enter statement if it is continue to exit program
		{
			correctMessage();
			cout << '\n';

		}


	} while (exitInteger != EXIT_INTEGER); // exit on EXIT_INTEGER
	
	
	cout << '\n';

	
}


//function correctMessage to randomly display the correct message which will include "Very good!", "Excellent!", "Nice work!", "Keep up the good work!".

void correctMessage()
{
	
	int randomCorrectMessageChoice = rand() % RANDOM_CORRECT_MESSAGE_SCALE + RANDOM_CORRECT_MESSAGE_SHIFT; // random scale between 0 - RANDOM_CORRECT_MESSAGE_SCALE and shifted + RANDOM_CORRECT_MESSAGE_SHIFT.

	switch (randomCorrectMessageChoice) 
	{
	
	case 1:	
		cout << "Very good!" << '\n';		
		break;

	case 2: 
		cout << "Excellent!" << '\n';		
		break;
	
	case 3: 
		cout << "Nice work!" << '\n';		
		break;
	
	case 4: 
		cout << "Keep up the good work!" << '\n';		
		break;
	
	default: 
		cerr << "ERROR - An invalid value was encountered in switch statement in function correctMessage() \n";
		break;		

	}
	
}


//function incorrectMessage to randomly display the incorrect message which will include "No. Please try again.", "Wrong.Try once more.", "Don't give up!", "No.Keep trying.".

void incorrectMessage()
{

	int randomIncorrectMessageChoice = rand() % RANDOM_INCORRECT_MESSAGE_SCALE + RANDOM_INCORRECT_MESSAGE_SHIFT; // random scale between 0 - RANDOM_INCORRECT_MESSAGE_SCALE and shifted + RANDOM_INCORRECT_MESSAGE_SHIFT.

	switch (randomIncorrectMessageChoice) 
	{
			
	case 1:	
		cout << "No. Please try again." << '\n' << "? ";
		break;

	case 2:
		cout << "Wrong. Try once more." << '\n' << "? ";		
		break;

	case 3:
		cout << "Don't give up!" << '\n' << "? ";		
		break;

	case 4:
		cout << "No. Keep trying." << '\n' << "? ";		
		break;

	default:
		cerr << "ERROR - An invalid value was encountered in switch statement in function inCorrectMessage() \n";
		break;
		
	}
	
}