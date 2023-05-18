// Name: 葉珧仲
// Date: March 9 ,2023
// Last Update: March 9 ,2023
// Problem statement: This C++ program add large number.
#include<iostream>
#include<string>
using namespace std;


struct BigInt
{
	string bigInt1;
	string bigInt2;
};

void changeBigInt(BigInt& bigInt);	//如果第一個數小於第二的數，就交換
void addBigInt(BigInt bigInt);	//將兩個大整數相加
void addBit(char number1, char number2, int& carry, string& result);	//單獨加一個位元
bool checknumber(string number);	//檢查是否都是數字組成，是的話回傳true

int main()
{
	int numberOfElement;	//一共要輸入幾組
	cin >> numberOfElement;
	getchar();
	BigInt* bigIntAdress;
	bigIntAdress = new BigInt[numberOfElement];
	for (int i = 0; i < numberOfElement; i++)
	{
		cin >> bigIntAdress[i].bigInt1;
		getchar();
		cin >> bigIntAdress[i].bigInt2;
		getchar();

	}
	for (int i = 0; i < numberOfElement; i++)
	{
		changeBigInt(bigIntAdress[i]);	//如果第一個數小於第二的數，就交換
		addBigInt(bigIntAdress[i]);	//將兩個大整數相加
	}
}

void changeBigInt(BigInt& bigInt)
{
	if (bigInt.bigInt2.length() > bigInt.bigInt1.length())
	{
		bigInt.bigInt2.swap(bigInt.bigInt1);
	}
}

void addBigInt(BigInt bigInt)
{
	int i = 0, j = 0;
	int carry = 0;	//進位
	i = bigInt.bigInt1.length();
	j = bigInt.bigInt2.length();
	string result;	//相加結果
	if (checknumber(bigInt.bigInt1) && checknumber(bigInt.bigInt2))	//檢查是否都是數字組成
	{
		for (; j >= 0;)
		{
			addBit(bigInt.bigInt1[i], bigInt.bigInt2[j], carry, result);
			i--;
			j--;
		}
		for (; i >= 0;)
		{
			addBit(bigInt.bigInt1[i], '0', carry, result);
			i--;
		}
		if (carry == 1)
		{
			result.insert(0, "1");
		}
		cout << result << endl;
	}
	else
	{
		cout << "Not a valid number, please try again." << endl;
	}

}

void addBit(char number1, char number2, int& carry, string& result)
{
	if (number1 + number2 - '0' + carry > '9')
	{
		switch (number1 + number2 - '0' + carry - 10)
		{
		case '0':
			result.insert(0, "0");
			break;
		case '1':
			result.insert(0, "1");
			break;
		case '2':
			result.insert(0, "2");
			break;
		case '3':
			result.insert(0, "3");
			break;
		case '4':
			result.insert(0, "4");
			break;
		case '5':
			result.insert(0, "5");
			break;
		case '6':
			result.insert(0, "6");
			break;
		case '7':
			result.insert(0, "7");
			break;
		case '8':
			result.insert(0, "8");
			break;
		case '9':
			result.insert(0, "9");
			break;
		}
		carry = 1;
	}
	else
	{
		switch (number1 + number2 + carry - '0')
		{
		case '0':
			result.insert(0, "0");
			break;
		case '1':
			result.insert(0, "1");
			break;
		case '2':
			result.insert(0, "2");
			break;
		case '3':
			result.insert(0, "3");
			break;
		case '4':
			result.insert(0, "4");
			break;
		case '5':
			result.insert(0, "5");
			break;
		case '6':
			result.insert(0, "6");
			break;
		case '7':
			result.insert(0, "7");
			break;
		case '8':
			result.insert(0, "8");
			break;
		case '9':
			result.insert(0, "9");
			break;
		}
		carry = 0;
	}
}
bool checknumber(string number)
{
	for (int i = 0; i < number.length(); i++)
	{
		if (number[i] < '0' || '9' < number[i])
		{
			return false;
		}
	}
	return true;
}