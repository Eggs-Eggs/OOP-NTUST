/***********************************************************************
 * File: Creature.cpp
 * Author: È~çòÖÙ
 * Create Date: 2023/5/3
 * Editor: È~çòÖÙ
 * Update Date: 2023/5/3
 * Description: This program is define Creature Class
 * ***********************************************************************/

#include "Creature.h"

//Constructor
Creature::Creature(string name)
{
	this->name = name;
	this->bornDayIndex = Diary::record.size() - 1;
}
Creature::Creature(string name, Creature& add)
{
	this->name = name;
	this->body = add.body;
	this->bornDayIndex = Diary::record.size() - 1;
}

/***********************************************************************
// Intent: overloading operator []
// Pre: input part name
// Post: return Creature Class
***********************************************************************/
Creature& Creature::operator[](string part)
{
	//check part exist
	for (int i = 0; i < this->body.size(); i++)
	{
		if (this->body[i].part == part)
		{
			index = i;
			return *this;
		}
	}

	//add new part
	allPart newPart;

	newPart.part = part;
	newPart.partTotal = 0;

	this->body.push_back(newPart);

	index = this->body.size() - 1;

	return *this;
}

/***********************************************************************
// Intent: overloading operator =
// Pre: input part total amount
// Post: return Creature Class
***********************************************************************/
Creature& Creature::operator=(int input)
{
	string output;

	// ckeck appeared , increased or decreased
	if (this->body[index].partTotal == 0 && input == 0)
	{
		//Do nothing
	}
	else if (this->body[index].partTotal == 0)
	{
		output = this->name + "'s " + this->body[index].part + " appeared (" + '0' + " -> " + to_string(input) + ").";

		Diary::NewEvent(this->name, output);
	}
	else if (this->body[index].partTotal < input)
	{
		output = this->name + "'s " + this->body[index].part + " increased (" + to_string(this->body[index].partTotal) + " -> " + to_string(input) + ").";

		Diary::NewEvent(this->name, output);
	}
	else if (this->body[index].partTotal > input)
	{
		output = this->name + "'s " + this->body[index].part + " decreased (" + to_string(this->body[index].partTotal) + " -> " + to_string(input) + ").";

		Diary::NewEvent(this->name, output);
	}

	//input data
	this->body[index].partTotal = input;

	return *this;
}

/***********************************************************************
// Intent: overloading operator +=
// Pre: input part total amount
// Post: return Creature Class
***********************************************************************/
Creature& Creature::operator+=(int input)
{
	return (*this = ((*this) + input));
}

/***********************************************************************
// Intent: overloading operator -=
// Pre: input part total amount
// Post: return Creature Class
***********************************************************************/
Creature& Creature::operator-=(int input)
{
	return (*this = ((*this) - input));
}

/***********************************************************************
// Intent: overloading operator +
// Pre: input part total amount
// Post: return add result
***********************************************************************/
int Creature::operator+(int input)
{
	return this->body[index].partTotal + input;
}

/***********************************************************************
// Intent: overloading operator +
// Pre: input part total amount
// Post: return sub result
***********************************************************************/
int Creature::operator-(int input)
{
	return this->body[index].partTotal - input;
}

/***********************************************************************
// Intent: print Creature log
// Pre: None
// Post: None
***********************************************************************/
void Creature::PrintLog()
{
	cout << this->name << "'s log:\n";

	for (int i = this->bornDayIndex; i < Diary::record.size(); i++)
	{
		cout << "Day " << Diary::record[i].day << endl;

		for (int j = 0; j < Diary::record[i].dayEvent.size(); j++)
		{
			//check Creature log's name 
			if (Diary::record[i].dayEvent[j].name == this->name)
			{
				for (int k = 0; k < Diary::record[i].dayEvent[j].allEvent.size(); k++)
				{
					cout << Diary::record[i].dayEvent[j].allEvent[k] << endl;
				}

				break;
			}
		}
	}
	cout << endl;
}

/***********************************************************************
// Intent: print Creature all part
// Pre: None
// Post: None
***********************************************************************/
void Creature::PrintStatus()
{
	//bubble sort
	for (int i = 0; i < this->body.size(); i++)
	{
		for (int j = 0; j < this->body.size() - i - 1; j++)
		{
			if (this->body[j].part > this->body[j + 1].part)
			{
				swap(this->body[j], this->body[j + 1]);
			}
		}
	}

	//print all part
	cout << this->name << "'s status:\n";

	for (int i = 0; i < this->body.size(); i++)
	{
		if (this->body[i].partTotal != 0)
			cout << this->body[i].part << " * " << this->body[i].partTotal << endl;
	}

	cout << endl;
}
