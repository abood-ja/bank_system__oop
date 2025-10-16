#pragma once
#include "clsScreen.h"
class clsDepositScreen :protected clsScreen
{
private:
	static double _ReadAmountOfMoneyToDeposit() {
		double amount = 0;
		cout << "\nPlease enter deposit amount? ";
		amount = clsInputValidate::ReadDblNumber();
		return amount;
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
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
	static void showDepositScreen() {
		string title = "\t   Deposit Screen";
		_DrawScreenHeader(title);
		string accountNumber = _ReadAccountNumber();
		while (!clsBankClient::isClientExist(accountNumber))
		{
			cout << "\nClient with [" << accountNumber << "] does not exist.\n";
			accountNumber = _ReadAccountNumber();
		}
		clsBankClient client = clsBankClient::find(accountNumber);
		_PrintClient(client);
		double amount = _ReadAmountOfMoneyToDeposit();
		while (amount <= 0) {
			cout << "Enter a Positive Amount!" << endl;
			amount = _ReadAmountOfMoneyToDeposit();
		}
		cout << "\nAre you sure you want to perform this transaction? (y/n) ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			client.deposit(amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << client.getAccountBalance();
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

	
};

