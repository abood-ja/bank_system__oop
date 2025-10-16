#pragma once
#include "clsScreen.h"
class clsDeleteUserScreen:protected clsScreen
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
	static void showDeleteUserScreen()
	{
		string title = "\t  Delete User Screen";
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
		_PrintUser(user);
		cout << "\nAre you sure you want to delete this user y/n? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (user.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(user);
			}
			else
			{
				cout << "\nError user was not deleted\n";
			}
		}
		
	}
};

