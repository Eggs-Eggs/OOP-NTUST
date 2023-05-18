/***********************************************************************
 * File: Point.h
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/30
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/30
 * Description: This program is declare the Class Point.
 * ***********************************************************************/
#pragma once

class Point
{
private:
	float position[2] = { 0 };
public:
	// Default constructor
	Point()
	{
		position[0] = 0;
		position[1] = 0;
	}
	// Setting constructor
	Point(const Point& point)
	{
		position[0] = point.position[0];
		position[1] = point.position[1];
	}
	~Point()
	{

	}

	//Set the data
	void Set(float, float);
	//Move the point
	void Move(float, float);
	//Rotate the point by 90 degrees clockwise around the origin
	void Rotate();
	//Reflect point in the origin
	void Reflect();

	//Get Horizontal
	float GetHorizontal();
	//Get Vertical
	float GetVertical();

};