#pragma once
#include "clsScreen.h"

class clsCurrencyCalculatorScreen:protected clsScreen
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
	static clsCurrency _GetCurrency()
	{
		string currencyCode;
		cout << "\nPlease Enter CurrencyCode: ";
		currencyCode = clsInputValidate::ReadString();
		clsCurrency currency = clsCurrency::findByCode(currencyCode);
		while (currency.isEmpty())
		{
			cout << "there's No Currency with this Code!, Enter another code: ";
			currencyCode = clsInputValidate::ReadString();
			currency = clsCurrency::findByCode(currencyCode);
		}
		return currency;
	}
	static double _ReadAmountOfMoney()
	{
		double amount;
		cout << "\nEnter Amount To Exchange: ";
		cin >> amount;
		while (amount<=0)
		{
			cout << "\nEnter Valid Amount: ";
			cin >> amount;
		}
		return amount;
	}
	static void _PrintCalculationsResults(float amount, clsCurrency currency1, clsCurrency currency2)
	{
		cout << "\nConvert From:\n";
		_PrintCurrency(currency1);

		float amountInUSD = currency1.convertToUSD(amount);

		cout << amount << " " << currency1.getCode()
			<< " = " << amountInUSD << " USD\n";

		if (currency2.getCode() == "USD")
		{
			return;
		}
		
		cout << "\nConverting from USD to:\n";
		cout << "\nTo:\n";
		_PrintCurrency(currency2);

		float amountInCurrrency2 = currency1.convertToOtherCurrency(amount, currency2);

		cout << amount << " " << currency1.getCode()
			<< " = " << amountInCurrrency2 << " " << currency2.getCode();
	}
public:
	static void showCurrencyCalculatorScreen()
	{
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tUpdate Currency Screen");
			clsCurrency currencyFrom = _GetCurrency();
			clsCurrency currencyTo = _GetCurrency();
			float amount = _ReadAmountOfMoney();
			_PrintCalculationsResults(amount, currencyFrom, currencyTo);
			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}

	}
};

