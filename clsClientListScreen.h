#pragma once
#include"clsScreen.h"
#include <iostream>
#include "clsBankClient.h"
#include <iomanip>
class clsClientListScreen:protected clsScreen
{
private:
	static void  PrintClientRecordLine(clsBankClient client)
    {
        cout << "| " << setw(15) << left << client.getAccountNumber();
        cout << "| " << setw(20) << left << client.getFullName();
        cout << "| " << setw(12) << left << client.getPhone();
        cout << "| " << setw(20) << left << client.getEmail();
        cout << "| " << setw(10) << left << client.getPinCode();
        cout << "| " << setw(12) << left << client.getAccountBalance();
    }
public:
	static void showClientsList() {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector <clsBankClient> vClients = clsBankClient::getClientList();
        string title = "\t  Client List Screen";
        string subTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
        _DrawScreenHeader(title, subTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


	}
};

