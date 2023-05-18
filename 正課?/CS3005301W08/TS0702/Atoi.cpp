#include "Atoi.h"

void Atoi::SetString(string s)
{
	beTrans = s;
}

const string Atoi::GetString()
{
	return beTrans;
}

int Atoi::Length()
{
	if (beTrans[0] == '-')
		return beTrans.length() - 1;
	else
		return beTrans.length();
}

bool Atoi::IsDigital()
{
	for (int i = 0; i < beTrans.length(); i++)
	{
		if (i == 0)
		{
			if ((beTrans[i] < '0' || '9' < beTrans[i]) && beTrans[i] != '-')
				return false;
		}
		else
		{
			if (beTrans[i] < '0' || '9' < beTrans[i])
				return false;
		}
	}
	return true;
}

int Atoi::StringToInteger()
{
	int integer = 0;
	bool sing = 0, strat = 0;
	for (int i = 0; i < beTrans.length(); i++)
	{
		if (beTrans[i] == '-')
			sing = 1;

		if (!(strat == 0 && (beTrans[i] == '0' || beTrans[i] == '-')))
			strat = 1;

		if (strat)
		{
			integer *= 10;
			integer += beTrans[i] - '0';
		}
	}
	if (sing == 0)
		return integer;
	else
		return -integer;
}
