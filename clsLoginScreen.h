#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "global.h"
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		int failedLoginCount = 0;
		cout << "Enter Username: ";
		string userName;
		userName = clsInputValidate::ReadString();
		while (!clsUser::isUserExist(userName))
		{
			failedLoginCount++;
			if (failedLoginCount == 3)
			{
				cout << "\nYou are locked after 3 failed trials!! \n\n";
				system("pause>0");
				return false;
			}
			cout << "\nInvalid Username ,You have "<<3-failedLoginCount<<" Trie(s)\nEnter another one: ";
			userName = clsInputValidate::ReadString();
		}
		failedLoginCount = 0;
		cout << "Enter Password: ";
		string password;
		password = clsInputValidate::ReadString();
		clsUser user = clsUser::find(userName, password);

		while (user.isEmpty())
		{
			failedLoginCount++;
			if (failedLoginCount==3)
			{
				cout << "\nYou are locked after 3 failed trials!! \n\n";
				system("pause>0");
				return false;
			}
			cout << "\nWrong Password! ,You have " << 3 - failedLoginCount << " Trie(s)\nEnter another one: ";

			password = clsInputValidate::ReadString();
			user = clsUser::find(userName, password);
		}
		currentUser = user;
		clsMainScreen::showMainMenu();
	}
public:
	static bool showLoginScreen()
	{
		system("cls");
		string title = "\t  Login Screen";
		_DrawScreenHeader(title);
		return _Login();
	}
};
