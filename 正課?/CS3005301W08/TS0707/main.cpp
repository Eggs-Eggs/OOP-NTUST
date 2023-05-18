/***********************************************************************
 * File: Main.cpp
 * Author: 
 * Create Date: 2023/
 * Editor: 
 * Update Date: 2023/
 * Description: This program is 
 * ***********************************************************************/

#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

string add(string a, string b);
string sub(string a, string b);
string mul(string a, string b);

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		cout << add(a, b) << endl;
		cout << sub(a, b) << endl;
		cout << mul(a, b) << endl;
	}
	return 0;
}

string add(string a, string b)
{
	if (a.length() > b.length())
	{
		b.insert(0, a.length() - b.length(), '0');
	}
	if (a.length() < b.length())
	{
		a.insert(0, b.length() - a.length(), '0');
	}

	int carry = 0;
	int add = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string re;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] - '0' + b[i] - '0' + carry > 9)
		{
			add = a[i] - '0' + b[i] - '0' + carry - 10;
			carry = 1;
		}
		else
		{
			add = a[i] - '0' + b[i] - '0' + carry;
			carry = 0;
		}
		re.insert(0, 1, add + '0');
	}
	if (carry != 0)
		re.insert(0, 1, '1');
	return re;
}

string sub(string a, string b)
{
	if (a.length() > b.length())
	{
		b.insert(0, a.length() - b.length(), '0');
	}
	if (a.length() < b.length())
	{
		a.insert(0, b.length() - a.length(), '0');
	}
	string re;
	if (b > a)
	{
		re = sub(b, a);
		re.insert(0, 1, '-');
		return re;
	}
	else
	{
		int carry = 0;
		int add = 0;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (int i = 0; i < a.length(); i++)
		{
			if ((a[i] - '0') - (b[i] - '0') - carry < 0)
			{
				add = (a[i] - '0') - (b[i] - '0') - carry + 10;
				carry = 1;
			}
			else
			{
				add = (a[i] - '0') - (b[i] - '0') - carry;
				carry = 0;
			}
			re.insert(0, 1, add + '0');
		}
		while (re[0] == '0')
		{
			if (re.length() == 1)
				break;
			re.erase(0, 1);
		}
		return re;
	}


}


string mul(string a, string b)
{
	int carry = 0;
	int add = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string re;
	re.insert(0, a.length() + b.length(), '0');
	for (int i = 0; i < a.length(); i++)
	{
		int j = 0;
		carry = 0;
		for (j = 0; j < b.length(); j++)
		{

			add = ((a[i] - '0') * (b[j] - '0') + carry) % 10;
			carry = ((a[i] - '0') * (b[j] - '0') + carry) / 10;

			carry = carry + (re[i + j] - '0' + add) / 10;
			add = (re[i + j] - '0' + add) % 10;
			re[i + j] = add + '0';

		}
		re[i + j] += carry;
		
	}
	reverse(re.begin(), re.end());
	while (re[0] == '0')
	{
		if (re.length() == 1)
			break;
		re.erase(0, 1);
	}
	return re;
}









/*
#include <iostream>
#include <string>

using namespace std;

void addBig(string a, string b);
void subBig(string a, string b);
void mulBig(string a, string b);

int main()
{
	string bigInt1, bigInt2;
	while (cin >> bigInt1 >> bigInt2)
	{
		addBig(bigInt1, bigInt2);
		subBig(bigInt1, bigInt2);
		mulBig(bigInt1, bigInt2);
	}
	return 0;
}

void addBig(string a, string b)
{
	string result;
	int i = a.length() - 1;
	int j = b.length() - 1;
	bool carry = 0;
	int add = 0;
	while (1)
	{
		if ((a[i] - '0') + (b[j] - '0') + carry > 9)
		{
			add = (a[i] - '0') + (b[j] - '0') + carry - 10;
			carry = 1;
		}
		else
		{
			add = a[i] - '0' + b[j] - '0' + carry;
			carry = 0;
		}

		result.insert(0, 1, add + '0');

		i--;
		j--;

		if (i < 0 && j < 0)
			break;

		if (i < 0)
		{
			a[0] = '0';
			i = 0;
		}
		if (j < 0)
		{
			b[0] = '0';
			j = 0;
		}

	}
	if (carry)
		result.insert(0, 1, 1 + '0');
	cout << result << endl;
}

void subBig(string a, string b)
{
	string result;
	bool minus = 0;

	if (b.length() > a.length())
		minus = 1;
	if (b.length() == a.length() && b > a)
		minus = 1;

	int i = a.length() - 1;
	int j = b.length() - 1;
	bool carry = 0;
	int add = 0;
	while (1)
	{
		if ((a[i] - '0') - (b[j] - '0') - carry < 0)
		{
			add = (a[i] - '0') - (b[j] - '0') - carry + 10;
			carry = 1;
		}
		else
		{
			add = (a[i] - '0') - (b[j] - '0') - carry;
			carry = 0;
		}

		result.insert(0, 1, add + '0');

		i--;
		j--;

		if (i < 0 && j < 0)
			break;

		if (i < 0)
		{
			a[0] = '0';
			i = 0;
		}
		if (j < 0)
		{
			b[0] = '0';
			j = 0;
		}

	}

	if (result[0] == '0')
		while (1)
		{
			if (result[0] != '0' || result.length() == 1)
				break;
			result.erase(0, 1);

		}

	if (minus)
	{
		result[result.length() - 1] = 10 + '0' - (result[result.length() - 1] - '0');
		for (int i = 0; i < result.length() - 1; i++)
		{
			result[i] = 10 + '0' - (result[i] - '0') - 1;
		}
		result.insert(0, 1, '-');
	}

	cout << result << endl;
}

void mulBig(string a, string b)
{
	string result;
	result.insert(0, a.length() + b.length(), '0');
	int i = a.length() - 1;
	int j = b.length() - 1;
	int carry = 0;
	int add = 0;
	while (1)
	{
		int pos;
		carry = 0;
		for (i = a.length() - 1; i >= 0; i--)
		{
			pos = result.length() - 1 - (a.length() - 1 - i + b.length() - 1 - j);

			add = (((a[i] - '0') * (b[j] - '0')) + carry) % 10;
			carry = (((a[i] - '0') * (b[j] - '0')) + carry) / 10;

			carry += (result[pos] - '0' + add) / 10;
			add = (result[pos] - '0' + add) % 10;
			result[pos] = add + '0';
		}
		result[pos - 1] += carry;
		j--;
		if (j < 0)
			break;
	}
	if (carry == 0)
		result.erase(0, 1);
	else
		result[0] = carry + '0';

	if (result[0] == '0')
		while (1)
		{
			if (result[0] != '0' || result.length() == 1)
				break;
			result.erase(0, 1);

		}
	cout << result << endl;
}
*/