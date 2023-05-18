/***********************************************************************
 * File: PrimeNumber.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/1
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/1
 * Description: This program is compute prime number
 * ***********************************************************************/

#include "PrimeNumber.h"

/***********************************************************************
// Intent: Check is prime number
// Pre: a number
// Post: return 1 if number is prime number
***********************************************************************/
bool isPrimeNumber(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

/***********************************************************************
// Intent: Get number
// Pre: None
// Post: number
***********************************************************************/
int PrimeNumber::get()
{
	return this->value;
}

//Constructor
PrimeNumber::PrimeNumber()
{
	value = 1;
}
PrimeNumber::PrimeNumber(int _value)
{
	this->value = _value;
}

/***********************************************************************
// Intent: overloading operator ++
// Pre: None
// Post: return next prime number
***********************************************************************/
PrimeNumber& PrimeNumber::operator++()
{
	PrimeNumber* result;

	this->value++;
	while (!isPrimeNumber(this->value))
	{
		this->value++;
	}

	result = new PrimeNumber(this->value);
	
	return *result;
}
PrimeNumber PrimeNumber::operator++(int)
{
	PrimeNumber result(this->value);

	this->value++;
	while (!isPrimeNumber(this->value))
	{
		this->value++;
	}

	return result;
}

/***********************************************************************
// Intent: overloading operator ++
// Pre: None
// Post: return previous prime number
***********************************************************************/
PrimeNumber& PrimeNumber::operator--()
{
	PrimeNumber* result;

	this->value--;
	while (!isPrimeNumber(this->value))
	{
		if (this->value == 2)
		{
			this->value = 1;
			break;
		}
		this->value--;
	}

	result = new PrimeNumber(this->value);

	return *result;
}
PrimeNumber PrimeNumber::operator--(int)
{
	PrimeNumber result(this->value);

	this->value--;
	while (!isPrimeNumber(this->value))
	{
		if (this->value == 2)
		{
			this->value = 1;
			break;
		}
		this->value--;
	}

	return result;
}
