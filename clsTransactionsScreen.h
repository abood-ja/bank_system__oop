#pragma once
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
class clsTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenuOptions { Deposit = 1, Withdraw = 2, TotalBalance = 3,Transfer=4 ,MainMenu = 5 };
	static short _ReadTransactionsMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 4? ");
		return Choice;
	}
	static void _GoBackToTransactionsMenu() {
		cout << setw(37) << left << "" << "\nPress any key to go back to Transactions Menu...";
		system("pause>0");
		showTranscationsScreen();
	}
	static void _ShowDepositScreen() {
		clsDepositScreen::showDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::showWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		clsTotalBalanceScreen::showTotalBalancesScreen();
	}
	static void _ShowTransferScreen()
	{
		clsTransferScreen::showTransferScreen();
	}
	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions option) {
		switch (option)
		{
		case clsTransactionsScreen::Deposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::TotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::Transfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsTransactionsScreen::MainMenu:
			break;
		}
	}
public:
	static void showTranscationsScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		system("cls");
		string title = "\t  Transactions Screen";
		_DrawScreenHeader(title);
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}
};

