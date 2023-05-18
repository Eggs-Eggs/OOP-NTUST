/***********************************************************************
 * File: password.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/8
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/8
 * Description: This program is record password
 * ***********************************************************************/

#pragma once

#include<iostream>
#include<string>

using namespace std;

namespace Authenticate
{
	string password;

	namespace Password
	{
		bool isValid()
		{
			bool nonLetter = 0;

			for (int i = 0; i < password.size(); i++)
			{
				if ((password[i] < 'a' || 'z' < password[i]) && (password[i] < 'A' || 'Z' < password[i]))
				{
					nonLetter = 1;
					break;
				}
			}
			if (nonLetter)
				return 1;
			else
				return 0;
		}
	}


	void inputPassword()
	{
		do
		{
			cout << "Enter your password (at least 8 characters " <<
				"and at least one non-letter)" << endl;
			cin >> password;
		} while (!Password::isValid());
	}

	string getPassword()
	{
		return password;
	}

}