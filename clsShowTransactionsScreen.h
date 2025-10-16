#pragma once
#include "clsScreen.h"
#include "clsShowDepositScreen.h"
#include "clsShowWithdrawScreen.h"
class clsShowTransactionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenuOptions { Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4 };
	static short _ReadTransactionsMenuOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
		return Choice;
	}
	static void _GoBackToTransactionsMenu() {
		cout << setw(37) << left << "" << "\nPress any key to go back to Transactions Menu...";
		system("pause>0");
		showTranscationsScreen();
	}
	static void _ShowDepositScreen() {
		clsShowDepositScreen::showDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsShowWithdrawScreen::showWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		cout << "\nTotal Balances Screen Will be here...\n";
	}
	static void _PerformTransactionsMenuOption(enTransactionsMenuOptions option) {
		switch (option)
		{
		case clsShowTransactionsScreen::Deposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::Withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::TotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		case clsShowTransactionsScreen::MainMenu:
			break;
		}
	}
public:
	static void showTranscationsScreen() {
		system("cls");
		string title = "\t  Transactions Screen";
		_DrawScreenHeader(title);
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}
};

