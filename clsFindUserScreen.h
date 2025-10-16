#pragma once
#include "clsScreen.h"
class clsFindUserScreen:protected clsScreen
{
private:
    static void _PrintUser(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.getFirstName();
        cout << "\nLastName    : " << user.getLastName();
        cout << "\nFull Name   : " << user.getFullName();
        cout << "\nEmail       : " << user.getEmail();
        cout << "\nPhone       : " << user.getPhone();
        cout << "\nUser Name   : " << user.getUserName();
        cout << "\nPassword    : " << user.getPassword();
        cout << "\nPermissions : " << user.getPermissions();
        cout << "\n___________________\n";
    }
public:
	static void ShowFindUserScreen()
	{
        string title = "\t  Find User Screen";
        _DrawScreenHeader(title);
        string userName;
        cout << "\nPlease enter Account Username: ";
        userName = clsInputValidate::ReadString();
        while (!clsUser::isUserExist(userName))
        {
            cout << "\nUsername is not found ,enter another one: ";
            userName = clsInputValidate::ReadString();
        }
        clsUser user = clsUser::find(userName);
        if (!user.isEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }
        _PrintUser(user);
	}
};

