#pragma once
#include "clsScreen.h"

class clsCurrencyExchangeMainScreen:protected clsScreen
{
private:
	enum enCurrenciesMainMenuOptions {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
		eCurrencyCalculator = 4, eMainMenu = 5
	};
	static void _GoBackToCurrencyExchangeMainMenu()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to Currency Exchange main Menu...";
		system("pause>0");
		showCurrencyExchangeMainScreen();
	}
	static void _ShowCurrenciesListScreen()
	{
		cout << "\nCurriencies List Screen Will Be Here.\n";
	}
	static void _ShowFindCurrencyScreen()
	{
		cout << "\nFind Currency Screen Will Be Here.\n";

	}
	static void _ShowUpdateCurrencyRateScreen()
	{
		cout << "\nUpdate Currency Rate Screen Will Be Here.\n";

	}
	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "\nCurrency Calculator Screen Will Be Here.\n";

	}
	static short _ReadCurrencyMainMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return choice;
	}
	static void _PerformCurrencyMainMenuOption(enCurrenciesMainMenuOptions option)
	{
		switch (option)
		{
		case clsCurrencyExchangeMainScreen::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		case clsCurrencyExchangeMainScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		case clsCurrencyExchangeMainScreen::eUpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMainMenu();
			break;
		case clsCurrencyExchangeMainScreen::eMainMenu:
			break;
		}
	}
public:
	static void showCurrencyExchangeMainScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pShowCurrencyExchange))
		{
			return;
		}
		system("cls");
		string title = "\t  Currency Exchange Main Screen";
		_DrawScreenHeader(title);
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyMainMenuOption((enCurrenciesMainMenuOptions)_ReadCurrencyMainMenuOption());
	}
};

