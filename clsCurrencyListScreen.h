#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyListScreen :protected clsScreen
{
private:
	static void printCurrencyRecordLine(clsCurrency currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << currency.getCountry();
		cout << "| " << setw(8) << left << currency.getCode();
		cout << "| " << setw(45) << left << currency.getName();
		cout << "| " << setw(10) << left << currency.getRate();
	}
public:
	static void showCurrencyListScreen()
	{
		vector<clsCurrency>vCurrencies = clsCurrency::getCurrenciesList();
		string title = "\t  Currencies List Screen";
		string subTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";
		_DrawScreenHeader(title);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
		if (vCurrencies.size()==0)
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency currency : vCurrencies)
			{
				printCurrencyRecordLine(currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

	}
};

