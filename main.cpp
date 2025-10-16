#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
void PrintClientRecordLine(clsBankClient client)
{
	cout << "| " << setw(15) << left << client.getAccountNumber();
	cout << "| " << setw(20) << left << client.getFullName();
	cout << "| " << setw(12) << left << client.getPhone();
	cout << "| " << setw(20) << left << client.getEmail();
	cout << "| " << setw(10) << left << client.getPinCode();
	cout << "| " << setw(12) << left << client.getAccountBalance();
}
void PrintClientRecordBalanceLine(clsBankClient client)
{
	cout << "| " << setw(15) << left << client.getAccountNumber();
	cout << "| " << setw(40) << left << client.getFullName();
	cout << "| " << setw(12) << left << client.getAccountBalance();
}
void showTotalBalances()
{
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
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}
int main()
{
	clsMainScreen::showMainMenu();
	system("pause>0");
	return 0;
}