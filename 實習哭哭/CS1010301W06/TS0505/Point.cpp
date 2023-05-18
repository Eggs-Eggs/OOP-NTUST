/***********************************************************************
 * File: Point.cpp
 * Author: È~çòÖÙ YE YAO ZHONG
 * Create Date: 2023/3/30
 * Editor: È~çòÖÙ YE YAO ZHONG
 * Update Date: 2023/3/30
 * Description: This program is define the Class Point.
 * ***********************************************************************/
#include"Point.h"

 //Set the data
void Point::Set(float x, float y)
{
	this->position[0] = x;
	this->position[1] = y;
}

//Move the point
void Point::Move(float x, float y)
{
	this->position[0] += x;
	this->position[1] += y;
}

//Rotate the point by 90 degrees clockwise around the origin
void Point::Rotate()
{
	float x = this->position[0];
	float y = this->position[1];
	this->position[0] = y;
	if (x != 0)
		this->position[1] = -x;
}

//Reflect point in the origin
void Point::Reflect()
{
	if (this->position[0] != 0)
		this->position[0] = -this->position[0];
	if (this->position[1] != 0)
		this->position[1] = -this->position[1];
}

//Get Horizontal
float Point::GetHorizontal() { return this->position[0]; }
//Get Vertical
float Point::GetVertical() { return this->position[1]; }