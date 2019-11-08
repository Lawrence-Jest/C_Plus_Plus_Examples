//Assignment 8: Complex.H
//Declartion of class Complex
//Member functions are defined in Complex.cpp
//Lawrence Jest-A00583216
//March 17,2018


#pragma once


class Complex //Complex class
{
public:

	Complex(double memberOne = 1.0, double memberTwo = 0.0); //ctor 

	void display(void)const; //displays the complex number

	
	void setDataMemberOne(double& dataMemberOneInput); //setter for data member
														//one

	double  getDataMemberOne(void)const; //getter for data member one

	void setDataMemberTwo(double& dataMemeberTwoInput); //setter for data member 
														//two

	double  getDataMemberTwo(void)const; //getter for data member two

	const Complex& plusEq(const Complex& complexObject); //addition equation for
	//complex number object and return the result as a complex object and 
	//changing the Complex object that calls this function

	const Complex& minusEq(const Complex& complexObject); //subtraction equation
	//for complex number object and return the result as a complex object and 
	//changing the Complex object that calls this function


private:
	
	double dataMemberOne; //represents the first data member of the Complex 
						  //object

	double dataMemberTwo; //represents the second data member of the Complex
						  //object

};
