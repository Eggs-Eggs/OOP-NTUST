/***********************************************************************
 * File: Polynomial.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/23
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/23
 * Description: This program is design polynomial Class
 * ***********************************************************************/

#pragma once

#include<math.h>
#include<iostream>

class Polynomial
{
public:
	// Constructor
	Polynomial();
	Polynomial(double* param, int size);

	// Copy constructor
	Polynomial(const Polynomial& poly);

	// Destructor
	~Polynomial();


	double* param;
	int size;

	int mySize();

	// Define operator =
	void operator =(const Polynomial& poly);
	// Define operator []
	double& operator [](int index);

};

// Constructor
Polynomial::Polynomial()
{
	param = new double;
	*param = 0;
	size = 0;
}
Polynomial::Polynomial(double* param, int size)
{
	this->param = new double[size];
	for (int i = 0; i < size; i++)
	{
		this->param[i] = param[i];
	}
	this->size = size;
}

// Copy constructor
inline Polynomial::Polynomial(const Polynomial& poly)
{
	this->size = poly.size;

	this->param = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->param[i] = poly.param[i];
	}
}

// Destructor
Polynomial::~Polynomial()
{
	delete[] this->param;
	this->param = 0;
}

// Return Polynomial size
int Polynomial::mySize()
{
	int result = this->size - 1;
	while (param[result] == 0)
	{
		if (result == 0)
			break;
		result--;
	}
	return ++result;
}

// Define operator =
void Polynomial::operator= (const Polynomial& poly)
{
	this->~Polynomial();

	this->size = poly.size;

	this->param = new double[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->param[i] = poly.param[i];
	}

}

// Define operator []
double& Polynomial::operator[](int index)
{
	if (index < this->size)
		return this->param[index];
	else
	{
		double* result = new double[index + 1] {};
		for (int i = 0; i < this->size; i++)
		{
			result[i] = this->param[i];
		}
		delete[] this->param;
		this->param = result;
		this->size = index +1;
		return this->param[index];
	}
}

// Evaluate Polynomial
double evaluate(Polynomial& poly, const double& var)
{
	double result = 0;
	for (int i = 0; i < poly.size; i++)
	{
		result += poly.param[i] * pow(var, i);
	}

	return result;
}

// Define operator +
Polynomial operator + (const Polynomial& poly1, const Polynomial& poly2)
{
	double* param;
	int size;
	Polynomial result;

	if (poly1.size > poly2.size)
	{
		param = new double[poly1.size];
		for (int i = 0; i < poly2.size; i++)
		{
			param[i] = poly1.param[i] + poly2.param[i];
		}
		for (int i = poly2.size; i < poly1.size; i++)
		{
			param[i] = poly1.param[i];
		}
		size = poly1.size;
	}
	else
	{
		param = new double[poly2.size];
		for (int i = 0; i < poly1.size; i++)
		{
			param[i] = poly1.param[i] + poly2.param[i];
		}
		for (int i = poly1.size; i < poly2.size; i++)
		{
			param[i] = poly2.param[i];

		}
		size = poly2.size;
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator + (int num, const Polynomial& poly)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		if (i == 0)
			param[i] = poly.param[i] + num;
		else
			param[i] = poly.param[i];
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator + (const Polynomial& poly, int num)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		if (i == 0)
			param[i] = poly.param[i] + num;
		else
			param[i] = poly.param[i];
	}


	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}

// Define operator -
Polynomial operator - (const Polynomial& poly1, const Polynomial& poly2)
{
	double* param;
	int size;
	Polynomial result;

	if (poly1.size > poly2.size)
	{
		param = new double[poly1.size];
		for (int i = 0; i < poly2.size; i++)
		{
			param[i] = poly1.param[i] - poly2.param[i];
		}
		for (int i = poly2.size; i < poly1.size; i++)
		{
			param[i] = poly1.param[i];
		}
		size = poly1.size;
	}
	else
	{
		param = new double[poly2.size];
		for (int i = 0; i < poly1.size; i++)
		{
			param[i] = poly1.param[i] - poly2.param[i];
		}
		for (int i = poly1.size; i < poly2.size; i++)
		{
			param[i] = -poly2.param[i];

		}
		size = poly2.size;
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator - (int num, const Polynomial& poly)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		if (i == 0)
			param[i] = num - poly.param[i];
		else
			param[i] = -poly.param[i];
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator - (const Polynomial& poly, int num)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		if (i == 0)
			param[i] = poly.param[i] - num;
		else
			param[i] = poly.param[i];
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}

// Define operator *
Polynomial operator * (const Polynomial& poly1, const Polynomial& poly2)
{
	double* param;
	int size;
	Polynomial result;

	size = poly1.size - 1 + poly2.size - 1 + 1;
	param = new double[size];

	for (int i = 0; i < size; i++)
	{
		param[i] = 0;
	}

	for (int i = 0; i < poly1.size; i++)
	{
		for (int j = 0; j < poly2.size; j++)
		{
			param[i + j] += poly1.param[i] * poly2.param[j];
		}
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator * (int num, const Polynomial& poly)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		param[i] = poly.param[i] * num;
	}


	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}
Polynomial operator * (const Polynomial& poly, int num)
{
	double* param;
	int size;
	Polynomial result;

	param = new double[poly.size];
	size = poly.size;

	for (int i = 0; i < poly.size; i++)
	{
		param[i] = poly.param[i] * num;
	}

	result.param = new double[size];
	for (int i = 0; i < size; i++)
	{
		result.param[i] = param[i];
	}
	result.size = size;
	return result;
}

