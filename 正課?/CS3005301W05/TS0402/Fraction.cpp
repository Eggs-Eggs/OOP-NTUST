#include "Fraction.h"
#include<iomanip>

void Fraction::setNumerator(int nu)
{
	numerator = nu;
}

void Fraction::setDenominator(int de)
{
	denominator = de;
}

void Fraction::getDouble()
{
	//if numerator / denominator is integer,don't need output decimal part.
	if (numerator % denominator == 0)
		cout << fixed << setprecision(0);
	else
		cout << fixed << setprecision(6);

	cout << (double)numerator / (double)denominator;
	cout << endl;
}

void Fraction::outputReducedFraction()
{
	int commonFactor = 1;
	//find common factor.
	if (numerator > denominator)
	{
		for (int i = 1; i <= denominator; i++)
			if (numerator % i == 0 && denominator % i == 0)
				commonFactor = i;
	}
	else
	{
		for (int i = 1; i <= numerator; i++)
			if (numerator % i == 0 && denominator % i == 0)
				commonFactor = i;
	}

	//if denominator / commonFactor equal 1,just output numerator part.
	if (denominator / commonFactor == 1)
		cout << numerator / commonFactor;
	else
		cout << numerator / commonFactor << '/' << denominator / commonFactor;
	cout << endl;
}



