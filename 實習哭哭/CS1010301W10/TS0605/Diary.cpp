/***********************************************************************
 * File: Diary.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/3
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/3
 * Description: This program is define Diary Class
 * ***********************************************************************/

#include "Diary.h"

vector<event> Diary::record;

/***********************************************************************
// Intent: write a new day
// Pre: input day date
// Post: None
***********************************************************************/
void Diary::NewDay(string day)
{
	event newDay;

	newDay.day = day;

	record.push_back(newDay);
}

/***********************************************************************
// Intent: write a diary in newday
// Pre: input creature name and inputEvent
// Post: None
***********************************************************************/
void Diary::NewEvent(string name, string inputEvent)
{
	//check name exist
	for (int i = 0; i < record[record.size() - 1].dayEvent.size();i++)
	{
		if (name == record[record.size() - 1].dayEvent[i].name)
		{
			record[record.size() - 1].dayEvent[i].allEvent.push_back(inputEvent);
			return;
		}
	}

	dayEvent newDayEvent;
	newDayEvent.name = name;
	newDayEvent.allEvent.push_back(inputEvent);

	record[record.size() - 1].dayEvent.push_back(newDayEvent);
}
