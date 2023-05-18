#include<iostream>
#include<string>

using namespace std;

int main()
{
	string number;
	while (1)
	{
		getline(cin, number);
		if ("0" <= number && number <= "9")
		{
			cout << number << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}