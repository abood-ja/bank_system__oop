#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "global.h"
class clsLoginScreen:protected clsScreen
{
private:
	static void _Login()
	{
		cout << "Enter Username: ";
		string userName;
		userName = clsInputValidate::ReadString();
		while (!clsUser::isUserExist(userName))
		{
			cout << "\nInvalid Username ,enter another one: ";
			userName = clsInputValidate::ReadString();
		}
		cout << "Enter Password: ";
		string password;
		password = clsInputValidate::ReadString();
		clsUser user = clsUser::find(userName, password);
		while (user.isEmpty())
		{
			cout << "Wrong password! ,Enter another one: ";
			password = clsInputValidate::ReadString();
			user = clsUser::find(userName, password);
		}
		currentUser = user;
		clsMainScreen::showMainMenu();
	}
public:
	static void showLoginScreen()
	{
		system("cls");
		string title = "\t  Login Screen";
		_DrawScreenHeader(title);
		_Login();
	}
};
