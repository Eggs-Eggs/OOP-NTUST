/***********************************************************************
 * File: VecNf.h
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/3
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/3
 * Description: This program is declare VecNf Class
 * ***********************************************************************/

#pragma once

#include<iostream>

using namespace std;

class VecNf
{
public:

	float* dest;
	int cnt;


	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);
	~VecNf();

	float& operator [] (int index);
	void operator = (const VecNf& rhs);
	VecNf operator + (const VecNf& rhs);
	VecNf operator - (const VecNf& rhs);
	float operator * (const VecNf& rhs);

	friend VecNf operator * (float number, const VecNf& rhs);
	friend VecNf operator * (const VecNf& rhs, float number);

	int Size();
};

