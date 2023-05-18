#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction f1, f2;
	f1.setNumerator(87);
	f1.setDenominator(39);
	f1.getDouble();
	f1.outputReducedFraction();

	f2.setNumerator(20);
	f2.setDenominator(60);
	f2.getDouble();
	f2.outputReducedFraction();
	return 0;
}