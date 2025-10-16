#pragma once
#include "clsScreen.h"
class clsDeleteClientScreen:protected clsScreen
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
	static void showDeleteClientScreen() {
		string title = "\t  Delete Client Screen";
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
		_PrintClient(client);
		cout << "\nAre you sure you want to delete this client y/n? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (client.Delete())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(client);
			}
			else
			{
				cout << "\nError client was not deleted\n";
			}
		}
	}
};

