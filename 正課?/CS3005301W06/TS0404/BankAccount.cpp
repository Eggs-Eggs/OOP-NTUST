/***********************************************************************
 * File: Month.cpp
 * Author: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Create Date: 2023/3/28
 * Editor: »~ÁÚ÷Ÿ YE YAO ZHONG
 * Update Date: 2023/3/28
 * Description: This program is define the BankAccount class.
 * ***********************************************************************/

#include <iostream>
#include "BankAccount.h"

//set total money
int BankAccount::total = 0;

BankAccount::BankAccount()
{
	balance = 0;
	total += balance;
}

BankAccount::BankAccount(int input):balance(input)
{
	total += balance;
}

/***********************************************************************
// Intent: withdraw money
// Pre: an interger number
// Post: None
***********************************************************************/
void BankAccount:: withdraw(int output)
{
	total -= output;
	balance -= output;
}

/***********************************************************************
// Intent: save money
// Pre: an interger number
// Post: None
***********************************************************************/
void BankAccount::save(int input)
{
	total += input;
	balance += input;
}

int BankAccount::getBalance() { return balance; }
int BankAccount::getAllMoneyInBank() { return total; }
