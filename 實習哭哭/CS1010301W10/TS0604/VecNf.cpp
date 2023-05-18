/***********************************************************************
 * File: VecNf.cpp
 * Author: È~çòÖÙ
 * Create Date: 2023/5/3
 * Editor: È~çòÖÙ
 * Update Date: 2023/5/3
 * Description: This program is define VecNf Class
 * ***********************************************************************/

#include "VecNf.h"

 //constructor
VecNf::VecNf()
{
	this->dest = new float[1];
	this->dest[0] = 0;
	this->cnt = 1;
}
VecNf::VecNf(float* dest, int cnt)
{
	this->dest = new float[cnt];
	for (int i = 0; i < cnt; i++)
	{
		this->dest[i] = dest[i];
	}
	this->cnt = cnt;
}
VecNf::VecNf(const VecNf& rhs)
{
	this->dest = new float[rhs.cnt];
	for (int i = 0; i < rhs.cnt; i++)
	{
		this->dest[i] = rhs.dest[i];
	}
	this->cnt = rhs.cnt;
}
//destructor
VecNf::~VecNf()
{
	delete[] this->dest;
	this->dest = nullptr;
}

/***********************************************************************
// Intent: overloding operator []
// Pre: input an index
// Post: return finding number
***********************************************************************/
float& VecNf::operator[](int index)
{
	if (index >= this->cnt)
	{
		float zero = 0;
		cout << "dimensions inconsistent\n";
		return zero;
	}
	else
		return this->dest[index];
}

/***********************************************************************
// Intent: overloding operator =
// Pre: assignment value
// Post: None
***********************************************************************/
void VecNf::operator=(const VecNf& rhs)
{
	cout << "ASSIGNMENT!!!\n";

	if (this == &rhs)
		return;

	this->dest = new float[rhs.cnt];

	for (int i = 0; i < rhs.cnt; i++)
	{
		this->dest[i] = rhs.dest[i];
	}

	this->cnt = rhs.cnt;

}

/***********************************************************************
// Intent: overloding operator +
// Pre: adding two vector
// Post: return VecNf Class
***********************************************************************/
VecNf VecNf::operator+(const VecNf& rhs)
{
	if (this->cnt == rhs.cnt)
	{
		float* newDest = new float[this->cnt];

		for (int i = 0; i < this->cnt; i++)
		{
			newDest[i] = this->dest[i] + rhs.dest[i];
		}

		VecNf result(newDest, this->cnt);

		delete[] newDest;
		return result;
	}
	else
	{
		cout << "dimensions inconsistent\n";
		return VecNf();
	}
}

/***********************************************************************
// Intent: overloding operator -
// Pre: subtracting two vector
// Post: return VecNf Class
***********************************************************************/
VecNf VecNf::operator-(const VecNf& rhs)
{
	if (this->cnt == rhs.cnt)
	{
		float* newDest = new float[this->cnt];

		for (int i = 0; i < this->cnt; i++)
		{
			newDest[i] = this->dest[i] - rhs.dest[i];
		}

		VecNf result(newDest, this->cnt);

		delete[] newDest;

		return result;
	}
	else
	{
		cout << "dimensions inconsistent\n";

		return VecNf();
	}
}

/***********************************************************************
// Intent: overloding operator *
// Pre: dot two vector
// Post: return dot result
***********************************************************************/
float VecNf::operator*(const VecNf& rhs)
{
	if (this->cnt == rhs.cnt)
	{
		float result = 0;

		for (int i = 0; i < this->cnt; i++)
		{
			result += this->dest[i] * rhs.dest[i];
		}

		return result;
	}
	else
	{
		cout << "dimensions inconsistent\n";

		return 0;
	}
}

/***********************************************************************
// Intent: return size
// Pre: None
// Post: return size
***********************************************************************/
int VecNf::Size()
{
	return this->cnt;
}

/***********************************************************************
// Intent: overloding operator *
// Pre: multiplied a vector
// Post: return VecNf Class
***********************************************************************/
VecNf operator*(float number, const VecNf& rhs)
{
	float* newDest = new float[rhs.cnt];

	for (int i = 0; i < rhs.cnt; i++)
	{
		newDest[i] = rhs.dest[i] * number;
	}

	VecNf result(newDest, rhs.cnt);

	delete[] newDest;

	return result;
}
VecNf operator*(const VecNf& rhs, float number)
{
	float* newDest = new float[rhs.cnt];

	for (int i = 0; i < rhs.cnt; i++)
	{
		newDest[i] = rhs.dest[i] * number;
	}

	VecNf result(newDest, rhs.cnt);

	delete[] newDest;

	return result;
}



