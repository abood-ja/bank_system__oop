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
int main()
{
	clsBankClient client1 = clsBankClient::find("A101");
	client1.print();
	clsBankClient client2 = clsBankClient::find("A101", "12345");
	client2.print();
	cout << clsBankClient::isClientExist("A1001231");
	system("pause>0");
	return 0;
}