#pragma once
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
class clsMainScreen:protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };
    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
        return Choice;
    }
    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::showClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::showAddNewClientScreen();
    }
    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::showDeleteClientScreen();
    }
    static void _ShowUpdateClientScreen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::showUpdateClientScreen();
        
    }
    static void _ShowFindClientScreen()
    {
        cout << "\nFind Client Screen Will be here...\n";
    }
    static void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menue Will be here...\n";
    }
    static void _ShowManageUsersMenue()
    {
        cout << "\nUsers Menue Will be here...\n";

    }
    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }
    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        showMainMenu();
    }
    static void _PerformMainMenuOption(enMainMenuOptions option)
    {
	    switch (option)
	    {
	    case eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
	    case eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
	    case eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
	    case eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
	    case eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
	    case eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
	    case eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenu();
            break;
	    case eExit:
            system("cls");
            _ShowEndScreen();
            _GoBackToMainMenu();
            break;
	    }
    }
public:
	static void showMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

