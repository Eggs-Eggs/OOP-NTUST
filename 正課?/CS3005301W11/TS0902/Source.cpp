/***********************************************************************
 * File: Source.cpp
 * Author: »~ÁÚ÷Ÿ
 * Create Date: 2023/5/8
 * Editor: »~ÁÚ÷Ÿ
 * Update Date: 2023/5/8
 * Description: This program is record UserName and password
 * ***********************************************************************/

#include"user.h"
#include"password.h"

using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();
    cout << "Your username is " << getUserName() <<
        " and your password is: " <<
        getPassword() << endl;
    return 0;
}
