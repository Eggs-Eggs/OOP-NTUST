/***********************************************************************
 * File: user.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/8
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/8
 * Description: This program is record username
 * ***********************************************************************/

#pragma once

#include<iostream>
#include<string>

using namespace std;

namespace Authenticate
{

	string username;

	namespace Name
	{
		bool isValid()
		{
			bool nonLetter = 0;

			for (int i = 0; i < username.size(); i++)
			{
				if ((username[i] < 'a' || 'z' < username[i]) && (username[i] < 'A' || 'Z' < username[i]))
				{
					nonLetter = 1;
					break;
				}
			}

			if (username.size() == 8 && nonLetter == 0)
				return 1;
			else
				return 0;
		}
	}


	void inputUserName()
	{
		do
		{
			cout << "Enter your username (8 letters only)" << endl;
			cin >> username;
		} while (!Name::isValid());
	}

	string getUserName()
	{
		return username;
	}



}
