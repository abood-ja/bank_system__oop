#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
//void addNewClient()
//{
//	
//	string accNumber;
//	cout << "\nPlease enter account Number: ";
//	accNumber = clsInputValidate::ReadString();
//	while (clsBankClient::isClientExist(accNumber))
//	{
//		cout << "\nAccount number is already used, choose another one: ";
//		accNumber = clsInputValidate::ReadString();
//	}
//	clsBankClient newClient = clsBankClient::getAddNewClientObject(accNumber);
//	readClientInfo(newClient);
//	clsBankClient::enSaveResults saveResult;
//	saveResult = newClient.save();
//	switch (saveResult)
//	{
//	case clsBankClient::svSucceeded:
//		cout << "\nAccount Added successfully :-)\n";
//		newClient.print();
//		break;
//	case clsBankClient::svFailedEmptyObject:
//		cout << "\nError account was not saved because it's empty";
//		break;
//	case clsBankClient::svFailedAccountNumberExists:
//		cout << "\nError account was not saved because account number is used!\n";
//		break;
//	}
//}
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
//void deleteClient()
//{
//	string accountNumber;
//	cout << "\nPlease enter account Number: ";
//	accountNumber = clsInputValidate::ReadString();
//	while (!clsBankClient::isClientExist(accountNumber))
//	{
//		cout << "\nAccount number is not found ,enter another one: ";
//		accountNumber = clsInputValidate::ReadString();
//	}
//	clsBankClient client = clsBankClient::find(accountNumber);
//	client.print();
//	cout << "\nAre you sure you want to delete this client y/n? ";
//	char answer = 'n';
//	cin >> answer;
//	if (answer=='y'||answer=='Y')
//	{
//		if (client.Delete())
//		{
//			cout << "\nClient Deleted Successfully :-)\n";
//			client.print();
//		}
//		else
//		{
//			cout << "\nError client was not deleted\n";
//		}
//	}
//}
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