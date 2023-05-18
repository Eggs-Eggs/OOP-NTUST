/***********************************************************************
 * File: Main.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/4/23
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/4/23
 * Description: This program is simulator memory.
 * ***********************************************************************/

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

// Transform to x16
string toData(long long int, int);
string toData(int ch);

// Set data
void setData(int position, string type, string data);
// Get data
int getData(int position, string type);

char* memory;
int memorySize;
int totalCom;	//total command

int main()
{
	cin >> memorySize >> totalCom;

	// Reset data
	memory = new char[memorySize * 2]{ 0 };
	for (int i = 0; i < memorySize * 2; i++)
		memory[i] = '0';

	for (int i = 0; i < totalCom; i++)
	{
		string command;

		cin >> command;

		if (command == "Set")
		{
			int position;
			string type;

			cin >> position >> type;

			if (type == "int")
			{
				long long int num;
				string result;

				cin >> num;
				result = toData(num, 8);

				if (result.length() > 8 || position + 4 > memorySize)
					cout << "Violation Access." << endl;

				while (result.length() > 8 || position + result.length() > memorySize * 2)
					result.erase(result.length() - 1, 1);

				setData(position, "int", result);
			}
			else if (type == "short")
			{
				long long int num;
				string result;

				cin >> num;
				result = toData(num, 4);

				if (result.length() > 4 || position + 4 > memorySize)
					cout << "Violation Access." << endl;

				while (result.length() > 4 || position + result.length() > memorySize * 2)
					result.erase(result.length() - 1, 1);

				setData(position, "short", result);

			}
			else if (type == "char")
			{
				int ch;
				string result;

				cin >> ch;

				getchar();

				result = toData(ch);

				setData(position, "char", result);
			}
			else if (type == "String")
			{
				string str;
				string result;

				getchar();
				getline(cin, str);

				if (position + str.length() > memorySize)
					cout << "Violation Access." << endl;

				reverse(str.begin(), str.end());

				while (position + str.length() > memorySize)
					str.erase(0, 1);
				reverse(str.begin(), str.end());

				for (int i = 0; i < str.length(); i++)
				{
					result = toData(str[i]);
					setData(position + i, "char", result);
				}
			}
		}
		else if (command == "Get")
		{
			int position;
			string type;

			cin >> position >> type;

			if (type == "int")
			{
				if (position + 4 > memorySize)
					cout << "Violation Access." << endl;
				else
					cout << getData(position, "int") << endl;
			}
			else if (type == "short")
			{
				if (position + 2 > memorySize)
					cout << "Violation Access." << endl;
				else
					cout << getData(position, "short") << endl;
			}
			else if (type == "char")
			{
				if (position + 1 > memorySize)
					cout << "Violation Access." << endl;
				else
					cout << getData(position, "char") << endl;
			}
			else if (type == "String")
			{
				while (1)
				{
					char ch = getData(position, "char");

					if (ch == '\0' || position >= memorySize)
					{
						cout << endl;
						break;
					}
					else
					{
						cout << ch;
						position++;
					}
				}
			}
		}
	}
}


string toData(long long int num, int length)
{
	string ans;
	do
	{
		int t = num % 16;

		if (0 <= t && t <= 9)
			ans += t + '0';
		else
			ans += t - 10 + 'A';

		num /= 16;
	} while (num != 0);

	while (ans.length() < length)
		ans.insert(ans.length(), 1, '0');

	for (int i = 0; i < ans.length(); i += 2)
	{
		char ch = ans[i];
		ans[i] = ans[i + 1];
		ans[i + 1] = ch;
	}

	return ans;
}

string toData(int ch)
{
	string ans;
	do
	{
		int t = ch % 16;

		if (0 <= t && t <= 9)
			ans += t + '0';
		else
			ans += t - 10 + 'A';
		ch /= 16;
	} while (ch != 0);

	reverse(ans.begin(), ans.end());

	while (ans.length() < 2)
		ans.insert(ans.length(), 1, '0');

	return ans;
}

int getData(int position, string type)
{
	if (position < memorySize)
	{
		if (type == "int")
		{
			int result = 0;

			for (int i = 0; i < 8; i += 2)
			{
				if ('0' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= '9')
					result += (memory[position * 2 + i + 1] - '0') * pow(16, i);
				else if ('A' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= 'F')
					result += (memory[position * 2 + i + 1] - 'A' + 10) * pow(16, i);

				if ('0' <= memory[position * 2 + i] && memory[position * 2 + i] <= '9')
					result += (memory[position * 2 + i] - '0') * pow(16, i + 1);
				else if ('A' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= 'F')
					result += (memory[position * 2 + i] - 'A' + 10) * pow(16, i + 1);
			}
			return result;
		}
		if (type == "short")
		{
			int result = 0;

			for (int i = 0; i < 4; i += 2)
			{
				if ('0' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= '9')
					result += (memory[position * 2 + i + 1] - '0') * pow(16, i);
				else if ('A' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= 'F')
					result += (memory[position * 2 + i + 1] - 'A' + 10) * pow(16, i);


				if ('0' <= memory[position * 2 + i] && memory[position * 2 + i] <= '9')
					result += (memory[position * 2 + i] - '0') * pow(16, i + 1);
				else if ('A' <= memory[position * 2 + i + 1] && memory[position * 2 + i + 1] <= 'F')
					result += (memory[position * 2 + i] - 'A' + 10) * pow(16, i + 1);
			}
			return result;
		}
		if (type == "char")
		{
			unsigned char result = 0;
			for (int i = 0; i < 2; i++)
			{
				if ('0' <= memory[position * 2 + i] && memory[position * 2 + i] <= '9')
				{
					result = (int)result + (memory[position * 2 + i] - '0') * pow(16, 1 - i);
				}
				else if ('A' <= memory[position * 2 + i] && memory[position * 2 + i] <= 'F')
				{
					result += (memory[position * 2 + i] - 'A' + 10) * pow(16, 1 - i);
				}
			}
			return result;
		}
	}
}

void setData(int position, string type, string data)
{
	if (position < memorySize)
	{
		if (type == "int")
		{
			for (int i = 0; i < 8; i++)
			{
				if (position * 2 + i > memorySize * 2)
					break;

				memory[position * 2 + i] = data[i];
			}
		}
		if (type == "short")
		{
			for (int i = 0; i < 4; i++)
			{
				if (position * 2 + i > memorySize * 2)
					break;

				memory[position * 2 + i] = data[i];
			}
		}
		if (type == "char")
		{
			for (int i = 0; i < 2; i++)
			{
				if (position * 2 + i > memorySize * 2)
					break;
				
				memory[position * 2 + i] = data[i];
			}
		}
	}
}