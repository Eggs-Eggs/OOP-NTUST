/***********************************************************************
 * File: Creature.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/3
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/3
 * Description: This program is declare Creature Class
 * ***********************************************************************/

#pragma once

#include "Diary.h"

typedef struct
{
	string part;
	int partTotal;

}allPart;


class Creature
{
public:
	int index;
	int bornDayIndex;
	string name;
	vector<allPart> body;


	Creature(string name);
	Creature(string name, Creature& add);

	Creature& operator[](string part);
	Creature& operator=(int input);
	Creature& operator+=(int input);
	Creature& operator-=(int input);
	int operator+(int input);
	int operator-(int input);

	void PrintLog();
	void PrintStatus();
};

