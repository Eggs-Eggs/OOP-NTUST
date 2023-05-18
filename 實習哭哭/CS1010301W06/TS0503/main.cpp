/***********************************************************************
 * File: Main.cpp
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/30
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/30
 * Description: This program is management the student data.
 * ***********************************************************************/

#include<iostream>
#include<string>

using namespace std;

typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

void write(char* s, string a);
int search(StRec* st, int stto, string f, string l, string p);

int main(void)
{
	string com;
	StRec st[10];
	int stto = 0;
	while (cin >> com)
	{
		string f, l, p;
		if (com == "print")
		{
			if (stto == 0)
				cout << "Print Error" << endl;
			else
			{
				for (int i = 0; i < stto; i++)
				{
					cout << st[i].firstName << " " << st[i].lastName << " " << st[i].phone << endl;
				}
			}
		}
		if (com == "insert")
		{
			cin >> f >> l >> p;
			if (stto == 9)
			{
				cout << "Insert Error" << endl;
			}
			else
			{
				
				write(st[stto].firstName, f);
				write(st[stto].lastName, l);
				write(st[stto].phone, p);
				stto++;
			}
		}
		if (com == "search")
		{
			cin >> f >> l >> p;
			int re = search(st, stto, f, l, p);
			if (re !=-1)
			{
				cout << re;
			}
			else
			{
				cout << "Search Error" << endl;
			}
		}
		if (com == "delete")
		{
			cin >> f >> l >> p;
			int re = search(st, stto, f, l, p);
			if (re != -1)
			{
				for (int i = re; i < stto; i++)
				{
					write(st[stto].firstName, st[stto + 1].firstName);
					write(st[stto].lastName, st[stto + 1].lastName);
					write(st[stto].phone, st[stto + 1].phone);
				}
				stto--;
			}
			else
			{
				cout << "Search Error" << endl;
			}
		}
	}
	return 0;
}

void write(char* s, string a)
{
	for (int i = 0; i < a.length(); i++)
	{
		s[i] = a[i];
		if (i == a.length() - 1)
		{
			s[i + 1] = '\0';
		}
	}
}

int search(StRec* st, int stto, string f, string l, string p)
{
	for (int i = 0; i < stto; i++)
	{
		if (!f.compare(st[i].firstName) && !l.compare(st[i].firstName) && !p.compare(st[i].firstName))
		{
			return i;
		}
	}
	return -1;
}





/*
#include<iostream>
#include<string>

using namespace std;

#define MAXSTUDENT 10

typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

// Write data in struct
void writeInData(char*, string);
// Search data in struct
int searchInData(StRec[], string, string, string);
// Delete data in struct
void deleteInData(StRec[], int, int&);
// Print data in struct
void printInData(StRec[], int);


int main(void)
{
	StRec student[MAXSTUDENT];

	string command;

	int totalStudent = 0;

	while (cin >> command)
	{
		string firstName, lastName, phone;

		if (command == "insert")
		{
			cin >> firstName >> lastName >> phone;

			// Check input.
			if (firstName.length() > 24 || lastName.length() > 29 || phone.length() > 14)
			{

				cout << "Input Error" << endl;
				continue;
			}

			int index = searchInData(student, firstName, lastName, phone);

			// Insert data if total student last than MAXSTUDENT and no repeat data.
			if (totalStudent < MAXSTUDENT && index == -1)
			{
				writeInData(student[totalStudent].firstName, firstName);
				writeInData(student[totalStudent].lastName, lastName);
				writeInData(student[totalStudent].phone, phone);
				totalStudent++;
			}
			else
			{
				cout << "Insert Error" << endl;
			}
		}
		else if (command == "search")
		{
			cin >> firstName >> lastName >> phone;

			// Check is legal input.
			if (firstName.length() > 24 || lastName.length() > 29 || phone.length() > 14)
			{
				cout << "Input Error" << endl;
				continue;
			}

			int index = searchInData(student, firstName, lastName, phone);

			// Search data if index exsit.
			if (index != -1)
			{
				cout << index << endl;
			}
			else
			{
				cout << "Search Error" << endl;
			}
		}
		else if (command == "delete")
		{
			cin >> firstName >> lastName >> phone;

			// Check is legal input.
			if (firstName.length() > 24 || lastName.length() > 29 || phone.length() > 14)
			{
				cout << "Input Error" << endl;
				continue;
			}

			int index = searchInData(student, firstName, lastName, phone);

			// Delete data if index exsit.
			if (index != -1)
			{
				deleteInData(student, index, totalStudent);
			}
			else
			{
				cout << "Delete Error" << endl;
			}
		}
		else if (command == "print")
		{
			// Print data if struct have data.
			if (totalStudent != 0)
				printInData(student, totalStudent);
			else
				cout << "Print Error" << endl;
		}
	}
	return 0;
}
*/
/***********************************************************************
// Intent: Write data in struct
// Pre: Means write new data in struct
// Post: Struct has been written
***********************************************************************/
/*
void writeInData(char* data, string info)
{
	for (int i = 0; i < info.length(); i++)
	{
		data[i] = info[i];
		data[i + 1] = '\0';
	}
}
*/
/***********************************************************************
// Intent: Search data in struct
// Pre: Should prepare all data about first name, last name,and phone number
// Post: If search successful return index otherwise return -1.
***********************************************************************/
/*
int searchInData(StRec data[], string infoFirstName, string infoLastName, string infoPhone)
{
	for (int i = 0; i < MAXSTUDENT; i++)
	{
		if (!(infoFirstName.compare(data[i].firstName)) && !(infoLastName.compare(data[i].lastName)) && !(infoPhone.compare(data[i].phone)))
		{
			return i;
		}
	}

	return -1;
}
*/
/***********************************************************************
// Intent: Delete data in struct.
// Pre: Should prepare index what you need delete and total student number.
// Post: Delete data in that index.
***********************************************************************/
/*
void deleteInData(StRec data[], int index, int& totalStudent)
{
	for (int i = index; i < totalStudent - 1; i++)
	{
		writeInData(data[i].firstName, data[i + 1].firstName);
		writeInData(data[i].lastName, data[i + 1].lastName);
		writeInData(data[i].phone, data[i + 1].phone);
	}

	totalStudent--;
}
*/
/***********************************************************************
// Intent: Print data in struct.
// Pre: Print all student data.
// Post: None.
***********************************************************************/
/*
void printInData(StRec data[], int totalStudent)
{
	for (int i = 0; i < totalStudent; i++)
	{
		cout << data[i].firstName << " " << data[i].lastName << " " << data[i].phone;
		cout << endl;
	}
}
*/