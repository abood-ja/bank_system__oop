#include "clsBankClient.h"
#include "clsInputValidate.h"
void readClientInfo(clsBankClient &client)
{
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
void updateClient()
{
	string accountNumber = "";
	cout << "\nPlease enter client account number: ";
	accountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::isClientExist(accountNumber))
	{
		cout << "\nAccount number is not found ,enter another one: ";
		accountNumber = clsInputValidate::ReadString();
	}
	clsBankClient client = clsBankClient::find(accountNumber);
	client.print();
	cout << "\n\nUpdate client info:";
	cout << "\n____________________\n";
	readClientInfo(client);
	clsBankClient::enSaveResults saveResult;
	saveResult = client.save();
	switch (saveResult)
	{
	case clsBankClient::svSucceeded:
		cout << "\nAccount updated successfully :-)\n";
		client.print();
		break;
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError account was not saved because it's empty";
		break;
	}
}
void addNewClient()
{
	
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
	switch (saveResult)
	{
	case clsBankClient::svSucceeded:
		cout << "\nAccount Added successfully :-)\n";
		newClient.print();
		break;
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError account was not saved because it's empty";
		break;
	case clsBankClient::svFailedAccountNumberExists:
		cout << "\nError account was not saved because account number is used!\n";
		break;
	}
}
int main()
{
	addNewClient();
	system("pause>0");
	return 0;
	
}