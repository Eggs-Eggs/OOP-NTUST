/***********************************************************************
 * File: Month.cpp
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/28
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/28
 * Description: This program is define the Month class.
 * ***********************************************************************/

#include "Month.h"
#include<iostream>

using namespace std;


Month::Month()
{
	month = 1;
}

Month::Month(char first, char second, char third)
{
	if (first == 'J' && second == 'a' && third == 'n')
		month = 1;
	else if (first == 'F' && second == 'e' && third == 'b')
		month = 2;
	else if (first == 'M' && second == 'a' && third == 'r')
		month = 3;
	else if (first == 'A' && second == 'p' && third == 'r')
		month = 4;
	else if (first == 'M' && second == 'a' && third == 'y')
		month = 5;
	else if (first == 'J' && second == 'u' && third == 'n')
		month = 6;
	else if (first == 'J' && second == 'u' && third == 'l')
		month = 7;
	else if (first == 'A' && second == 'u' && third == 'g')
		month = 8;
	else if (first == 'S' && second == 'e' && third == 'p')
		month = 9;
	else if (first == 'O' && second == 'c' && third == 't')
		month = 10;
	else if (first == 'N' && second == 'o' && third == 'v')
		month = 11;
	else if (first == 'D' && second == 'e' && third == 'c')
		month = 12;
	else
		month = 1;


}

Month::Month(int monthInt)
{
	if (1 <= monthInt && monthInt <= 12)
		month = monthInt;
	else
		month = 1;
}


Month::~Month()
{
}

/***********************************************************************
// Intent: set month
// Pre: input month in interger
// Post: set month
***********************************************************************/
void Month::inputInt()
{
	int x;

	cin >> x;

	if (1 <= x && x <= 12)
		this->month = x;
	else
		this->month = 1;

}

/***********************************************************************
// Intent: set month
// Pre: input the letter of the abbreviation of month
// Post: set month
***********************************************************************/
void Month::inputStr()
{
	char a, b, c;

	cin >> a >> b >> c;

	if (a == 'J' && b == 'a' && c == 'n')
		month = 1;
	else if (a == 'F' && b == 'e' && c == 'b')
		month = 2;
	else if (a == 'M' && b == 'a' && c == 'r')
		month = 3;
	else if (a == 'A' && b == 'p' && c == 'r')
		month = 4;
	else if (a == 'M' && b == 'a' && c == 'y')
		month = 5;
	else if (a == 'J' && b == 'u' && c == 'n')
		month = 6;
	else if (a == 'J' && b == 'u' && c == 'l')
		month = 7;
	else if (a == 'A' && b == 'u' && c == 'g')
		month = 8;
	else if (a == 'S' && b == 'e' && c == 'p')
		month = 9;
	else if (a == 'O' && b == 'c' && c == 't')
		month = 10;
	else if (a == 'N' && b == 'o' && c == 'v')
		month = 11;
	else if (a == 'D' && b == 'e' && c == 'c')
		month = 12;
	else
		month = 1;
}

/***********************************************************************
// Intent: output month in interger
// Pre: None
// Post: output month in interger
***********************************************************************/
void Month::outputInt()
{
	cout << month;
}

/***********************************************************************
// Intent: output month abbreviation
// Pre: None
// Post: output the letter of the abbreviation of month
***********************************************************************/
void Month::outputStr()
{
	switch (month)
	{
	case 1:
		cout << "Jan";
		break;
	case 2:
		cout << "Feb";
		break;
	case 3:
		cout << "Mar";
		break;
	case 4:
		cout << "Apr";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "Jun";
		break;
	case 7:
		cout << "Jul";
		break;
	case 8:
		cout << "Aug";
		break;
	case 9:
		cout << "Sep";
		break;
	case 10:
		cout << "Oct";
		break;
	case 11:
		cout << "Nov";
		break;
	case 12:
		cout << "Dec";
		break;
	default:
		break;
	}
}

/***********************************************************************
// Intent: increment month value
// Pre: find next month
// Post: return next month
***********************************************************************/
Month Month::nextMonth()
{
	Month month;
	if (1 <= this->month < 12)
	{
		Month month(this->month + 1);
		return month;
	}
	else if (this->month == 12)
	{
		Month month(1);
		return month;
	}
}
