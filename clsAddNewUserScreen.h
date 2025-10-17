#pragma once
#include "clsScreen.h"
class clsAddNewUserScreen :protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& user)
	{
		cout << "\nEnter FirstName: ";
		user.firstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		user.lastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		user.email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		user.phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		user.password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		user.permissions = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet()
	{
		int permissions = 0;
		char answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nLogin Register? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pShowLoginRegister;
		}
		cout << "\nCurrency Exchange? y/n? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			permissions += clsUser::enPermissions::pShowCurrencyExchange;
		}

		return permissions;
	}
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
	static void ShowAddNewUserScreen()
	{
		string title = "\t  Add New User Screen";
		_DrawScreenHeader(title);
		string userName;
		cout << "\nPlease enter Account userName: ";
		userName = clsInputValidate::ReadString();
		while (clsUser::isUserExist(userName))
		{
			cout << "\nthis userName is already used, choose another one: ";
			userName = clsInputValidate::ReadString();
		}
		clsUser newUser = clsUser::GetAddNewUserObject(userName);
        _ReadUserInfo(newUser);
		clsUser::enSaveResults saveResult;
		saveResult = newUser.save();
        switch (saveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(newUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        }

	}

};

