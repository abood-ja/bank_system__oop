#pragma once
#include "clsScreen.h"
class clsFindClientScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient& client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << client.getFirstName();
		cout << "\nLastName    : " << client.getLastName();
		cout << "\nFull Name   : " << client.getFullName();
		cout << "\nEmail       : " << client.getEmail();
		cout << "\nPhone       : " << client.getPhone();
		cout << "\nAcc. Number : " << client.getAccountNumber();
		cout << "\nPassword    : " << client.getPinCode();
		cout << "\nBalance     : " << client.getAccountBalance();
		cout << "\n___________________\n";
	}

public:
	static void showFindClientScreen() {
		string title = "\t  Find Client Screen";
		_DrawScreenHeader(title);
		string accountNumber;
		cout << "\nPlease enter account Number: ";
		accountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nAccount number is not found ,enter another one: ";
			accountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client = clsBankClient::find(accountNumber);
		if (!client.isEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClient(client);
	}
};

