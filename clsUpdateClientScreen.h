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
        cout << "\nPlease Enter client Account Number: ";
        accountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::find(accountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";
            readClientInfo(Client1);
            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client1.save();
            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFailedEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;
            }

            }

        }

    }


};

