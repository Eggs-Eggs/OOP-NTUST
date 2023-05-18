/***********************************************************************
 * File: Diary.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/3
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/3
 * Description: This program is declare Diary Class
 * ***********************************************************************/

#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct
{
	string name;
	vector<string> allEvent;
}dayEvent;


typedef struct
{
	string day;
	vector<dayEvent> dayEvent;
}event;

class Diary
{
public:
	static vector<event> record;

	static void NewDay(string day);
	static void NewEvent(string name,string inputEvent);
};

