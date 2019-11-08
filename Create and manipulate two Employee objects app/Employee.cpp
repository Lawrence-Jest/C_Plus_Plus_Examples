//Fig 3.14 from text 
//Assignment 1: Employee class function definitions
//
//Lawrence Jest
//Jan 20,2018

#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

const int SINGLE_CHAR_STRING_VALUE = 1; //char value for comparing string to 1.  firstName can be 0 char("") or atleast 2 chars.
const int NAME_STRING_LIMIT = 2; //char value for name string limit, our case is 2.

//constructor uses a MIL and then checks the Mil values.  
Employee::Employee(string firstNameInput, string lastNameInput, int salaryInput)
	:firstName(firstNameInput), lastName(lastNameInput), salary(salaryInput)
{
	if (firstNameInput.length() == SINGLE_CHAR_STRING_VALUE) {
		cerr << "Warning - invalid length string entered for first name in ctor: " << firstNameInput << "\n" << "The string that was entered will be used for now." <<  endl << endl;
	}	
	
	if (lastNameInput.length() < NAME_STRING_LIMIT) {
		cerr << "Warning - invalid length string entered for last name in ctor: " << lastNameInput << "\n" << "The string that was entered will be used for now." << endl << endl;
	}

	if (salaryInput < 0) {
		cerr << "Invalid salary amount specified in ctor: $" << salaryInput << "\n" << endl;
		salary = 0;
	}
}

//sets the string firstName with the passed in string setFirstNameInput argument.  string setFirstNameInput must be atleast 2 chars or an "".
void Employee::setFirstName( string setFirstNameInput)
{
	if (setFirstNameInput.length() >= NAME_STRING_LIMIT) {
		firstName = setFirstNameInput;
	}
	else {
		cerr << "ERROR - invalid length string entered for first name in setFirstName(): " << setFirstNameInput << endl;
		cout << "The first name was left unchanged: " << firstName << endl;
	}
	
}

//returns the string firstName.
string Employee::getFirstName() const
{	
	return firstName;	
}

//sets the string lastName with the passed in string setLastNameInput.  string setLastNameInput must be atleast 2 chars.
void Employee::setLastName(string setLastNameInput)
{
	if (setLastNameInput.length() >= NAME_STRING_LIMIT) {
		lastName = setLastNameInput;
	}
	else {
		cerr << "ERROR - invalid length string entered for last name in setLastName(): " << setLastNameInput << endl;
		cout << "The last name was left unchanged: " << lastName << endl;
	}	
}

//returns string lastName
string Employee::getLastName() const
{
	return lastName;
}

//sets int salary with the passsed in argument int setSalaryInput.  int setSalaryInput must be positive.
void Employee::setMonthlySalary(int setSalaryInput)
{
	if (setSalaryInput >= 0) {
		salary = setSalaryInput;
	}
	else {
		cerr << "ERROR - Invalid salary amount specified: $" << setSalaryInput << endl;
		cout << "Salary was left unchanged at: $" << salary <<  endl;		
	}
}

//returns int salary
int Employee::getMonthlySalary() const
{
	return salary;
}
