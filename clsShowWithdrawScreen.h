#pragma once
#include "clsScreen.h"
class clsShowWithdrawScreen:protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
	static double _ReadAmountOfMoneyToWithDraw() {
		double amount = 0;
		cout << "\nPlease enter Withdraw amount? ";
		amount = clsInputValidate::ReadDblNumber();
		return amount;
	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.getFirstName();
		cout << "\nLastName    : " << Client.getLastName();
		cout << "\nFull Name   : " << Client.getFullName();
		cout << "\nEmail       : " << Client.getEmail();
		cout << "\nPhone       : " << Client.getPhone();
		cout << "\nAcc. Number : " << Client.getAccountNumber();
		cout << "\nPassword    : " << Client.getPinCode();
		cout << "\nBalance     : " << Client.getAccountBalance();
		cout << "\n___________________\n";

	}
public:
	static void showWithdrawScreen() {
		string title = "\t   Withdraw Screen";
		_DrawScreenHeader(title);
		string accountNumber = _ReadAccountNumber();
		while (!clsBankClient::isClientExist(accountNumber)) {
			cout << "\nClient with [" << accountNumber << "] does not exist.\n";
			accountNumber = _ReadAccountNumber();
		}
		clsBankClient client = clsBankClient::find(accountNumber);
		_PrintClient(client);
		double amount = _ReadAmountOfMoneyToWithDraw();
		while (amount <= 0) {
			cout << "Enter a Positive Amount!" << endl;
			amount = _ReadAmountOfMoneyToWithDraw();
		}
		cout << "\nAre you sure you want to perform this transaction? (y/n) ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (client.withdraw(amount)) {
			cout << "\nAmount Withdrew Successfully.\n";
			cout << "\nNew Balance Is: " << client.getAccountBalance();
			}
			else {
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << amount;
				cout << "\nYour Balance is: " << client.getAccountBalance();
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

