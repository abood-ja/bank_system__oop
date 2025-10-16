#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen:protected clsScreen
{
private:
	static void readClientInfo(clsBankClient& client) {
		cout << "\nEnter FirstName: ";
		client.firstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		client.lastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		client.email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		client.phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode: ";
		client.pinCode = clsInputValidate::ReadString();
		cout << "\nEnter AccountBalance: ";
		client.accountBalance = clsInputValidate::ReadDblNumber();
	}
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
	static void showUpdateClientScreen() {
		string title = "\t  Update Client Screen";
		_DrawScreenHeader(title);
		string accountNumber = "";
			cout << "\nPlease enter client account number: ";
			accountNumber = clsInputValidate::ReadString();
			while (!clsBankClient::isClientExist(accountNumber))
			{
				cout << "\nAccount number is not found ,enter another one: ";
				accountNumber = clsInputValidate::ReadString();
			}
			clsBankClient client = clsBankClient::find(accountNumber);
			_PrintClient(client);
			cout << "\n\nUpdate client info:";
			cout << "\n____________________\n";
			readClientInfo(client);
			clsBankClient::enSaveResults saveResult;
			saveResult = client.save();
			switch (saveResult)
			{
			case clsBankClient::svSucceeded:
				cout << "\nAccount updated successfully :-)\n";
				_PrintClient(client);
				break;
			case clsBankClient::svFailedEmptyObject:
				cout << "\nError account was not saved because it's empty";
				break;
			}
	}

};

