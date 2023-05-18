/***********************************************************************
 * File: Month.cpp
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/28
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/28
 * Description: This program is define the HotDogStand class.
 * ***********************************************************************/

#include "HotDogStand.h"
#include<iostream>

using namespace std;

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	standId = 0;
	hotDogSellAmount = 0;
	totalSellAmount += hotDogSellAmount;
}

HotDogStand::HotDogStand(const char* id)
{
	standId = id;
	hotDogSellAmount = 0;
	totalSellAmount += hotDogSellAmount;
}

HotDogStand::HotDogStand(const char* id, int amount)
{
	standId = id;
	hotDogSellAmount = amount;
	totalSellAmount += hotDogSellAmount;
}


HotDogStand::~HotDogStand()
{
}

/***********************************************************************
// Intent: sold one hot dog
// Pre: None
// Post: hot dog sell amount and total sell amount pluse one
***********************************************************************/
void HotDogStand::justSold()
{
	hotDogSellAmount++;
	totalSellAmount ++;
}

/***********************************************************************
// Intent: printf information of stand.
// Pre: None
// Post: stand name and its sells amount.
***********************************************************************/
void HotDogStand::print()
{
	cout << standId << " " << hotDogSellAmount << endl;
}

/***********************************************************************
// Intent: return hot dog sell amount
// Pre: None
// Post: return hotDogSellAmount
***********************************************************************/
int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

/***********************************************************************
// Intent: return all stand sold amount
// Pre: None
// Post: return allStandSoldAmount
***********************************************************************/
int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
