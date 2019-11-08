//A00583216_Jest_Assign_02 class: to run client code for assignment 02 comp 2617 bcit
// Assignment 02 Roman Numeral to Hindu-Arabic numeral converter program
//
//Lawrence Jest
//Jan 28,2018

#include <iostream>
#include <cctype>
#include <conio.h>

using namespace std;




//client code to run Roman Numeral to Hindu-Arabic numeral  converter program
int main()
{
 const int ROMAN_NUMERAL_I = 1;
 const int ROMAN_NUMERAL_V = 5;
 const int ROMAN_NUMERAL_X = 10;
 const int ROMAN_NUMERAL_L = 50;
 const int ROMAN_NUMERAL_C = 100;
 const int ROMAN_NUMERAL_D = 500;
 const int ROMAN_NUMERAL_M = 1000;
 const int COUNTER_START_VALUE = 1;
 const int CIN_IGNORE_FIRST_ARGUMENT = 10000;

 int totalNumeralSum = 0;
 int counter = COUNTER_START_VALUE;
 int userInput = 0;
 char romanNumeralCharacter;
 bool invalidCharacterInput = false;
 int romanNumeralValue = 0;
 bool firstTimeThrough = true; 
 
 cout << "10 Roman numeral values will be input and converted into their equivalent Hindu - Arabic numeric values." << endl; //display message

 for (counter; counter <= 10; counter++) //loop ten times 
 {
	 totalNumeralSum = 0; //reset sum for each iteration of loop

	 romanNumeralValue = 0;//reset value for easch iteration of loop
	
	 cout << "\nInput Roman numeral # " << counter << ": "; //prompt user

	 while(((userInput = cin.get()) != '\n' ) && (invalidCharacterInput == false)) //get user input and check for new line char or bool invalidCharacterInput state
	 {
		
		 userInput = toupper(userInput); //upper case the user input

		 romanNumeralCharacter = userInput; //set char romanNumeralCharacter to  int userInput 

		 if ((romanNumeralCharacter == 'I') || (romanNumeralCharacter == 'V') || (romanNumeralCharacter == 'X') || (romanNumeralCharacter == 'L') || (romanNumeralCharacter == 'C') || (romanNumeralCharacter == 'D') || (romanNumeralCharacter == 'M')) //check for valid input
		 {


			 switch (romanNumeralCharacter) //depending on character add that much value to convert to hindu-arabic numerals.
			 {
			 case 'I': if (romanNumeralValue >= ROMAN_NUMERAL_I) //checks romanNumeralValue against the vaild I value, romanNumeralValue being the previuos read char, if that char was bigger it means plain addition of roman numerals
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_I;
			 }
					   else //if the previous char was smaller then this will be a compound roman numeral that involves subtraction
					   {
						   if (firstTimeThrough == true) //if first time thru will be smaller but thats ok, int totalNumeralSum can be set to this valid roman numeral value
						   {
							   totalNumeralSum = ROMAN_NUMERAL_I;
						   }
						   else //calculation for adding the compound roman numeral to the int totalNumeralSum
						   {
							   totalNumeralSum = totalNumeralSum + (ROMAN_NUMERAL_I - romanNumeralValue);
						   }

					   }

					   romanNumeralValue = ROMAN_NUMERAL_I; //set int romanNumeralValue to this roman numeral value to be a memory location for the last place read.
					   break;

			 case 'V': if (romanNumeralValue >= ROMAN_NUMERAL_V) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'V' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_V;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_V;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_V - romanNumeralValue);
						   }

					   }

					   romanNumeralValue = ROMAN_NUMERAL_V;
					   break;

			 case 'X': if (romanNumeralValue >= ROMAN_NUMERAL_X) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'X' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_X;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_X;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_X - romanNumeralValue);
						   }

					   }

					   romanNumeralValue = ROMAN_NUMERAL_X;
					   break;

			 case 'L': if (romanNumeralValue >= ROMAN_NUMERAL_L) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'L' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_L;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_L;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_L - romanNumeralValue);
						   }
					   }

					   romanNumeralValue = ROMAN_NUMERAL_L;
					   break;

			 case 'C': if (romanNumeralValue >= ROMAN_NUMERAL_C) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'C' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_C;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_C;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_C - romanNumeralValue);
						   }
					   }

					   romanNumeralValue = ROMAN_NUMERAL_C;
					   break;

			 case 'D': if (romanNumeralValue >= ROMAN_NUMERAL_D) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'D' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_D;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_D;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_D - romanNumeralValue);
						   }
					   }

					   romanNumeralValue = ROMAN_NUMERAL_D;
					   break;

			 case 'M': if (romanNumeralValue >= ROMAN_NUMERAL_M) //comments are as above for case 'I', should be exactly the same execpt each case deals with each roman numeral this case being 'M' 
			 {
				 totalNumeralSum = totalNumeralSum + ROMAN_NUMERAL_M;
			 }
					   else
					   {
						   if (firstTimeThrough == true)
						   {
							   totalNumeralSum = ROMAN_NUMERAL_M;
						   }
						   else
						   {
							   totalNumeralSum = totalNumeralSum - romanNumeralValue + (ROMAN_NUMERAL_M - romanNumeralValue);
						   }
					   }

					   romanNumeralValue = ROMAN_NUMERAL_M;
					   break;

			 default:	
				 cerr << "ERROR-invalid input-default case of romanNumeralCharacter switch selection in function main() \n";
				 break;

			 }

			 cout << romanNumeralCharacter; //show char romanNumeralCharacter for each iteration of while loop

		 }
		 else
		 {
			
			 invalidCharacterInput = true; //set bool invalidCharacterInput to true 
			 

		 }

		 firstTimeThrough = false; //first time thru will happen only the first time :)
		 
	 }

	 

	 if (invalidCharacterInput == false) //check if an invalid character was input and if not display conversion.
	 {
		 cout << " = " << totalNumeralSum << endl; //display conversion
	 }
	 else
	 {
		 cerr << romanNumeralCharacter << " Error - last character was not valid!!!" << endl; //error message if user input character was invalid
		 
		 cin.clear();

		 cin.ignore(CIN_IGNORE_FIRST_ARGUMENT, '\n'); //clear the rest of cin.get() up to CIN_IGNORE_FIRST_ARGUMENT chars, and end when '\n' is encountered
		 romanNumeralCharacter = 'i'; //set to valid data to clear bad data left in memory location

	 }

	 invalidCharacterInput = false; //reset the bool invalidCHaracterInput
	
 }
 cout << "\n\nTHAT'S ALL FOLKS :)";

cout << "\n\nPress any key to continue...."; // prompt to close program

_getch(); //close program

	return 0;
}
//end of program