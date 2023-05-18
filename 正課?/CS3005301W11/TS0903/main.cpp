/***********************************************************************
 * File: main.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/8
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/8
 * Description: This program is record words connect
 * ***********************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct letter
{
	char ch;
	vector<letter*> connet;
};

letter allLetter[256];

//Chaeck two words are smae
bool chaeckSmae(string a, string b);
//Find word and word connent
bool findConnent(letter* first, unsigned char target, vector<letter*> appeartAddress);

char result1, result2;

bool isFind = 0;

int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < 256; i++)
		{
			allLetter[i].ch = i;
			allLetter[i].connet.clear();
		}

		//connent word
		for (int i = 0; i < m; i++)
		{
			unsigned char ch1, ch2;

			cin >> ch1 >> ch2;

			allLetter[ch1].connet.push_back(&allLetter[ch2]);
		}

		//check word
		for (int i = 0; i < n; i++)
		{
			string str1, str2;

			cin >> str1 >> str2;

			if (chaeckSmae(str1, str2))
				cout << "yes";
			else
				cout << "no";
			cout << endl;
		}
	}

	return 0;
}

/***********************************************************************
// Intent: Check two words are same.
// Pre: Two words
// Post: Return 1 when both word are same.
***********************************************************************/
bool chaeckSmae(string a, string b)
{
	//Check two letter lengthen are same.
	if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			isFind = 0;

			//Input letter & target letter & appear letter
			if (findConnent(&allLetter[a[i]], allLetter[b[i]].ch, vector<letter*>()) == 0)
				return false;
		}
		return true;
	}
	else
		return false;
}

/***********************************************************************
// Intent: Check two letter are same.
// Pre: Input a letter struct and target letter and vector<letter*> to record appear letter.
// Post: Return 1 when both letter are same.
***********************************************************************/
bool findConnent(letter* first, unsigned char target, vector<letter*> appeartAddress)
{
	if (first->ch == target)
		isFind = 1;

	for (int i = 0; i < first->connet.size(); i++)
	{
		bool appear = 0;

		for (int j = 0; j < appeartAddress.size(); j++)
		{
			if (first->connet[i] == appeartAddress[j])
				appear = 1;
		}

		if (appear == 0)
		{
			//Add appeart letter address
			appeartAddress.push_back(first);

			findConnent(first->connet[i], target, appeartAddress);
		}

	}

	if (isFind == 1)
		return 1;
	else
		return 0;
}
