#pragma once
#include "clsScreen.h"

class clsTransferScreen:protected clsScreen
{
private:
	static string _ReadAccountNumberToTransferFrom()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number To Transfer From? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
	static string _ReadAccountNumberToTransferTo()
	{
		string AccountNumber = "";
		cout << "\nPlease enter Account Number To Transfer To? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
	static clsBankClient _GetAccountToTransferFrom()
	{
		string accountNumberToTransferFrom = _ReadAccountNumberToTransferFrom();
		while (!clsBankClient::isClientExist(accountNumberToTransferFrom)) {
			cout << "\nClient with [" << accountNumberToTransferFrom << "] does not exist.\n";
			accountNumberToTransferFrom = _ReadAccountNumberToTransferFrom();
		}
		  return clsBankClient::find(accountNumberToTransferFrom);
	}
	static clsBankClient _GetAccountToTransferTo()
	{
		string accountNumberToTransferTo = _ReadAccountNumberToTransferTo();
		while (!clsBankClient::isClientExist(accountNumberToTransferTo)) {
			cout << "\nClient with [" << accountNumberToTransferTo << "] does not exist.\n";
			accountNumberToTransferTo = _ReadAccountNumberToTransferTo();
		}
		return clsBankClient::find(accountNumberToTransferTo);
	}
	static double _ReadAmountOfMoneyToTransfer() {
		double amount = 0;
		cout << "\nPlease enter The Money amount? ";
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
	static void showTransferScreen()
	{
		string title = "\t  Transfer Screen";
		_DrawScreenHeader(title);
		clsBankClient clientToTransferFrom = _GetAccountToTransferFrom();
		_PrintClient(clientToTransferFrom);
		clsBankClient clientToTransferTo = _GetAccountToTransferTo();
		_PrintClient(clientToTransferTo);

		double amountToTransfer = _ReadAmountOfMoneyToTransfer();
		while (amountToTransfer <= 0) {
			cout << "Enter a Positive Amount!" << endl;
			amountToTransfer = _ReadAmountOfMoneyToTransfer();
		}
		cout << "\nAre you sure you want to perform this transaction? (y/n) ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (clientToTransferFrom.transfer(amountToTransfer,clientToTransferTo)) {
				cout << "\nTransfer Done Successfully.\n";
				_PrintClient(clientToTransferFrom);
				_PrintClient(clientToTransferTo);
			}
			else
			{
				cout << "\nAmount Exceeds the available Balance!\n" << endl;
			}
		}
		else
		{
			cout << "\nTransfer Failed.\n";
		}
	}
};

