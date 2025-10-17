#pragma once
#include "clsScreen.h"

class clsFindCurrencyScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << currency.getCountry();
		cout << "\nCode       : " << currency.getCode();
		cout << "\nName       : " << currency.getName();
		cout << "\nRate(1$) = : " << currency.getRate();
		cout << "\n_____________________________\n";
	}
	static void _ShowResults(clsCurrency currency)
	{
		if (!currency.isEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:
	static void showFindCurrencyScreen()
	{
		short findBy;
		string title = "\t  Find Currency Screen";
		_DrawScreenHeader(title);
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;
		cin >> Answer;
		if (Answer == 1)
		{
			string currencyCode;
			cout << "\nPlease Enter CurrencyCode: ";
			currencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::findByCode(currencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string country;
			cout << "\nPlease Enter Country Name: ";
			country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::findByCountry(country);
			_ShowResults(Currency);
		}
	}
};

