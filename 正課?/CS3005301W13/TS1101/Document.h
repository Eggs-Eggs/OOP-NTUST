#pragma once

#include<string>

using namespace std;

class Document
{
public:
	string text;

	Document(string text)
	{
		this->text = text;
	}

	string getText() const
	{
		return this->text;
	}

	Document& operator=(Document copy)
	{
		this->text = copy.text;

		return *this;
	}
};

