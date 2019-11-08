// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Lawrence Jest-A00583216
// Date: Oct 13, 2018

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>

using namespace std;

const long long DEFAULT_DENOMINIATOR = 1;

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}


// default ctor
Fraction:: Fraction():numerator(0), denominator(DEFAULT_DENOMINIATOR)
{
	
}

// second ctor, which
// requires at least one long long argument
Fraction::Fraction(long long num, long long denom) 
{
	if (denom == 0) 
	{		
		cerr << "cannot enter 0 for denominator, setting it to "
			 << DEFAULT_DENOMINIATOR << ".";

		denom = DEFAULT_DENOMINIATOR;
	}
	numerator = num;
	denominator = denom;

	simplify();
}

// Adds RHS to the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::plusEq(const Fraction & RHS) 
{
	long long lcd = denominator * RHS.denominator;
	numerator = (numerator * RHS.denominator) + (RHS.numerator * denominator);
	denominator = lcd;

	simplify();

	return (*this); // returns the object which invoked the method
}

// Subtracts RHS from the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::minusEq(const Fraction & RHS) 
{
	long long lcd = denominator * RHS.denominator;
	numerator = (numerator * RHS.denominator) - (RHS.numerator * denominator);
	denominator = lcd;

	simplify();

	return (*this); // returns the object which invoked the method
}

// Divides RHS into the Fraction object invoked with this method
// (thereby modifying the Fraction object) and returns the result

const Fraction & Fraction::divideEq(const Fraction & RHS) 
{
	numerator = (numerator * RHS.denominator);
	denominator = (denominator * RHS.numerator);

	simplify();

	return (*this); // returns the object which invoked the method
}

// Returns the negation of the Fraction object
// invoked with the method but must NOT
// modify the actual Fraction object invoked
// with the method.
Fraction Fraction::negate()const 
{

	return Fraction(getNum() * -1, getDenom());  // Not magic number because it
												 // just flips sign.
	
}


// Returns numerator
long long Fraction::getNum()const 
{
	return numerator;
}

// Returns denominator
long long Fraction::getDenom()const 
{
	return denominator;
}

// Outputs to standard output stream the Fraction object
// in the format: numerator/denominator
void Fraction::display()const 
{
	cout << numerator << "/" << denominator;
}

// this method reduces the Fraction objects as much
//  as possible.  It also ensures that the denominator is
//  positive.
void Fraction::simplify() 
{

	long long gcdReturned = gcd(numerator, denominator); 
	numerator = numerator / gcdReturned;
	denominator = denominator / gcdReturned;

	if (denominator < 0) 
	{
		numerator *= -1;// Not magic number, only used to flip sign.
		denominator *= -1;// Not magic number only used to flip sign.
	}
	
}