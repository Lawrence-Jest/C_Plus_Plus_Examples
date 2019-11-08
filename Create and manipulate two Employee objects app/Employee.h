#pragma once
//Fig 3.14 from text  
//Assignment 1: Employee object interface
//
//Lawrence Jest
//Jan 20,2018

#include <string>



class Employee {
public:

	Employee(std::string, std::string, int); //constructor to initialize object uses MIL and checks arguments for char limits.
	void setFirstName(std::string); //sets string firstName must be atleast 2 chars or "".
	std::string getFirstName() const; //returns string firstName.
	void setLastName(std::string); //sets string lastName must be atleast 2 chars.
	std::string getLastName() const; //returns string lastName.
	void setMonthlySalary(int); //sets int salary, must be positive.
	int getMonthlySalary() const; //returns int salary

private:

	std::string firstName;
	std::string lastName;
	int salary;

};