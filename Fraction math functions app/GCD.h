#pragma once
// Assignment 04 solution: GCD.h
// template gcd() to find the greatest common divisor for 2 inputs.
//
// Lawrence Jest-A00583216
// Oct 13,2018

#include <cmath>


template < class T >
T gcd(T firstValue, T secondValue)
{
	firstValue = abs(firstValue);
	secondValue = abs(secondValue);

	if (secondValue == 0)
		return firstValue;
	else
	{
		return gcd(secondValue, firstValue % secondValue);
	}

}