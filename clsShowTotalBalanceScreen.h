#pragma once
#include "clsScreen.h"
class clsShowTotalBalanceScreen:protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient client)
	{
		cout << "| " << setw(15) << left << client.getAccountNumber();
		cout << "| " << setw(40) << left << client.getFullName();
		cout << "| " << setw(12) << left << client.getAccountBalance();
	}
public:
	static void showTotalBalancesScreen() {
		string title = "\t  Total Balance Screen";
		_DrawScreenHeader(title);
		vector<clsBankClient>vClients = clsBankClient::getClientList();
		cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		double TotalBalances = clsBankClient::getTotalBalances();
		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
	}
};

