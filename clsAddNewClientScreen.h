#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsAddNewClientScreen:protected clsScreen
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
	static void showAddNewClientScreen() {
		string title = "\t  Add New Client Screen";
		_DrawScreenHeader(title);
		string accNumber;
		cout << "\nPlease enter account Number: ";
		accNumber = clsInputValidate::ReadString();
		while (clsBankClient::isClientExist(accNumber))
		{
			cout << "\nAccount number is already used, choose another one: ";
			accNumber = clsInputValidate::ReadString();
		}
		clsBankClient newClient = clsBankClient::getAddNewClientObject(accNumber);
		readClientInfo(newClient);
		clsBankClient::enSaveResults saveResult;
		saveResult = newClient.save();
		switch (saveResult)
		{
		case clsBankClient::svSucceeded:
			cout << "\nAccount Added successfully :-)\n";
			_PrintClient(newClient);
			break;
		case clsBankClient::svFailedEmptyObject:
			cout << "\nError account was not saved because it's empty";
			break;
		case clsBankClient::svFailedAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
	}
};

