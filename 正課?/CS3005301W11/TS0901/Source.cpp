/***********************************************************************
 * File: Source.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/8
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/8
 * Description: This program is find reverses word
 * ***********************************************************************/

#include<iostream>
#include<string>
#include<vector>


using namespace std;

bool existWord(string input);

vector<string> allInput;

int main()
{
	string max;
	string input;

	while (cin >> input)
	{
		allInput.push_back(input);

		if (input.size() > max.size())
		{
			reverse(input.begin(), input.end());

			if (existWord(input))
				max = input;
		}
	}


	cout << max << endl;

	return 0;
}

/***********************************************************************
// Intent: Find the word exist
// Pre: Input a word
// Post: return 1 when reverse word exist 
***********************************************************************/
bool existWord(string input)
{
	for (int i = 0; i < allInput.size(); i++)
	{
		if (input == allInput[i])
			return true;
	}

	return false;
}
