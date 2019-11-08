//Asignment 08: Complex.cpp
//Member-function definitons for class Complex
//Lawrence Jest-A00583216
//March 17, 2018


#include "Complex.h"
#include <iostream>
#include <iomanip>

using namespace std;


//ctor to initialize the complex object using a MIL 
Complex::Complex(double memberone, double member2)
	:dataMemberOne(memberone),dataMemberTwo(member2)
{

}

//dispaly function to display the data members of the Complex object
//const to not change the data
void Complex::display(void) const
{
	cout << fixed << setprecision(4) << "( " << dataMemberOne << " , " 
		<< dataMemberTwo << " )" ;
}

//setDataMemberOne function to set the first data member in the COmplex object
//double& dataMemberOneInput: the reference to the first data member of the 
//Complex object to change
 void Complex::setDataMemberOne(double& dataMemberOneInput)
{
	 dataMemberOne = dataMemberOneInput;
}

 //getDataMemberOne function to return the first data member in the Complex 
 //object
double  Complex::getDataMemberOne(void) const
{
	return dataMemberOne;
	
}

//setDataMemberTwo function to set the second data member in the Complex object
//double& dataMemberTwoInput: the reference to the second data member of the 
//Complex object to change
void Complex::setDataMemberTwo(double& dataMemeberTwoInput)
{
	dataMemberTwo = dataMemeberTwoInput;
}

//getDataMemberTwo function to return the second data member in the Complex
//object
double  Complex::getDataMemberTwo(void) const
{
	return  dataMemberTwo;	
}

//plusEq function to take a Complex object reference as an argument and then
//do a simple complex number addition equation and return the Complex object that
//called the function in doing so changing the Complex object that called this
//function
const Complex & Complex::plusEq(const Complex& complexObject)
{	
	dataMemberOne = dataMemberOne + complexObject.getDataMemberOne();
	dataMemberTwo = dataMemberTwo + complexObject.getDataMemberTwo();
	return *this;
}

//minusEq function to take a Complex object reference as an argument and then
//do a simple complex number subtraction equation and return the Complex object 
//that called the function in doing so changing the Complex object that called 
//this function
 const Complex & Complex::minusEq(const Complex& complexObject)
{
	 dataMemberOne = dataMemberOne - complexObject.getDataMemberOne();
	 dataMemberTwo = dataMemberTwo - complexObject.getDataMemberTwo();
	return  *this;
}
