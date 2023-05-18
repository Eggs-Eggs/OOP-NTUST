/***********************************************************************
 * File: Complex.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/1
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/1
 * Description: This program is compute complex number
 * ***********************************************************************/



#include "Complex.h"

//Constructor
Complex::Complex()
{
	realValue = 0;
	imaginaryValue = 0;
}
Complex::Complex(double r)
{
	realValue = r;
	imaginaryValue = 0;
}
Complex::Complex(double r, double i)
{
	realValue = r;
	imaginaryValue = i;
}

/***********************************************************************
// Intent: Get real number
// Pre: None
// Post: Return real number
***********************************************************************/
double Complex::real()
{
	return realValue;
}
/***********************************************************************
// Intent: Get imag number
// Pre: None
// Post: Return imag number
***********************************************************************/
double Complex::imag()
{
	return imaginaryValue;
}
/***********************************************************************
// Intent: Get norm number
// Pre: None
// Post: Return norm number
***********************************************************************/
double Complex::norm()
{
	return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2));
}

/***********************************************************************
// Intent: Get real number
// Pre: Input a Complex Class
// Post: Return real number
***********************************************************************/
double real(Complex c)
{
	return c.realValue;
}
/***********************************************************************
// Intent: Get imag number
// Pre: Input a Complex Class
// Post: Return imag number
***********************************************************************/
double imag(Complex c)
{
	return c.imaginaryValue;
}
/***********************************************************************
// Intent: Get norm number
// Pre: Input a Complex Class
// Post: Return norm number
***********************************************************************/
double norm(Complex c)
{
	return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
}

/***********************************************************************
// Intent: overloading operator +
// Pre: a number and Complex Class
// Post: return add result
***********************************************************************/
Complex operator+(double d, Complex c)
{
	return Complex(c.realValue + d, c.imaginaryValue);
}
/***********************************************************************
// Intent: overloading operator -
// Pre: a number and Complex Class
// Post: return subtract result
***********************************************************************/
Complex operator-(double d, Complex c)
{
	return Complex(d - c.realValue, -c.imaginaryValue);
}
/***********************************************************************
// Intent: overloading operator *
// Pre: a number and Complex Class
// Post: return multiplied result
***********************************************************************/
Complex operator*(double d, Complex c)
{
	return Complex(d * c.realValue, d * c.imaginaryValue);
}
/***********************************************************************
// Intent: overloading operator /
// Pre: a number and Complex Class
// Post: return divide result
***********************************************************************/
Complex operator/(double d, Complex c)
{
	double real, imaginary;
	real = (d * c.realValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	imaginary = -(d * c.imaginaryValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	return Complex(real, imaginary);
}

/***********************************************************************
// Intent: overloading operator ==
// Pre: two Complex Class
// Post: if two Complex Class equal return 1
***********************************************************************/
bool operator==(Complex c1, Complex c2)
{
	if (c1.real() == c2.real() && c1.imag() == c2.imag())
		return true;
	return false;
}

/***********************************************************************
// Intent: overloading operator <<
// Pre: Complex Class
// Post: show Complex
***********************************************************************/
ostream& operator<<(ostream& strm, const Complex& c)
{
	std::cout << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

/***********************************************************************
// Intent: overloading operator >>
// Pre: Complex Class
// Post: input Complex
***********************************************************************/
istream& operator>>(istream& strm, Complex& c)
{
	getchar();
	getchar();
	getchar();
	getchar();
	std::cin >> c.realValue;
	getchar();
	getchar();
	getchar();
	std::cin >> c.imaginaryValue;
	getchar();
	getchar();
	return strm;
}

/***********************************************************************
// Intent: overloading operator +
// Pre: two Complex Class
// Post: return add result
***********************************************************************/
Complex Complex::operator+(Complex c)
{
	return Complex(c.realValue + this->realValue, c.imaginaryValue + this->imaginaryValue);
}
/***********************************************************************
// Intent: overloading operator -
// Pre: two Complex Class
// Post: return add result
***********************************************************************/
Complex Complex::operator-(Complex c)
{
	return Complex(this->realValue - c.realValue, this->imaginaryValue - c.imaginaryValue);
}
/***********************************************************************
// Intent: overloading operator *
// Pre: two Complex Class
// Post: return add result
***********************************************************************/
Complex Complex::operator*(Complex c)
{
	return Complex(this->realValue * c.realValue - this->imaginaryValue * c.imaginaryValue, this->realValue * c.imaginaryValue + this->imaginaryValue * c.realValue);
}
/***********************************************************************
// Intent: overloading operator /
// Pre: two Complex Class
// Post: return add result
***********************************************************************/
Complex Complex::operator/(Complex c)
{
	double real, imaginary;
	real = (this->realValue * c.realValue + this->imaginaryValue * c.imaginaryValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	imaginary = (this->imaginaryValue * c.realValue - this->realValue * c.imaginaryValue) / (pow(c.realValue, 2) + pow(c.imaginaryValue, 2));
	return Complex(real, imaginary);
}
