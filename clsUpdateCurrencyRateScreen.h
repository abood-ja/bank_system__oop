#pragma once
#include "clsScreen.h"

class clsUpdateCurrencyRateScreen:protected clsScreen
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
	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float newRate = 0;
		newRate = clsInputValidate::ReadDblNumber();
		return newRate;
	}
public:
	static void showUpdateCurrencyRateScreen()
	{
		string title = "\t  Update Currency Rate Screen";
		_DrawScreenHeader(title);
		string currencyCode;
		cout << "\nPlease enter Currency Code: ";
		currencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::isCurrencyExist(currencyCode))
		{
			cout << "\nCurrency code is not found ,enter another one: ";
			currencyCode = clsInputValidate::ReadString();
		}
		clsCurrency currency = clsCurrency::findByCode(currencyCode);
		_PrintCurrency(currency);
		cout << "\nAre you sure you want to update this user y/n? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n____________________\n";
			currency.updateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(currency);
		}
		else
		{
			cout << "\nOperation Cancelled\n";
		}
	}
};

