#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
using namespace std;
class clsCurrency
{
private:
	
	enum enMode{EmptyMode=1,UpdateMode=2};
	string _Country;
	string _Code;
	string _Name;
	double _Rate;
	enMode _Mode;
	static clsCurrency _ConvertLineToCurrencyObject(string line,string seperator="#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(line, seperator);
		return clsCurrency(vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stod(vCurrencyData[3]),enMode::UpdateMode);
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
	{
		string line = "";
		line += currency.getCountry() + seperator;
		line += currency.getCode() + seperator;
		line += currency.getName() + seperator;
		line += to_string(currency.getRate());
		return line;
	}
	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency>vCurrencies;
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				vCurrencies.push_back(currency);
			}
			myFile.close();
		}
		return vCurrencies;
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return  clsCurrency("", "", "", 0, enMode::EmptyMode);
	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream myFile;
		myFile.open("Currencies.txt", ios::out);
		string dataLine;
		if (myFile.is_open())
		{
			for (clsCurrency currency : vCurrencies)
			{
				dataLine = _ConvertCurrencyObjectToLine(currency);
				myFile << dataLine << endl;
			}
			myFile.close();
		}
	}
	void _Update()
	{
		vector<clsCurrency>vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency &currency:vCurrencies)
		{
			if (currency.getCode()==this->getCode())
			{
				currency = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencies);
	}
	
public:
	clsCurrency(string country, string code, string name, double rate,enMode mode)
	{
		this->_Country = country;
		this->_Code = code;
		this->_Name = name;
		this->_Rate = rate;
		this->_Mode = mode;
	}
	string getCountry()
	{
		return this->_Country;
	}
	string getCode()
	{
		return this->_Code;
	}
	string getName()
	{
		return this->_Name;
	}
	double getRate()
	{
		return _Rate;
	}
	void updateRate(double rate)
	{
		this->_Rate = rate;
		_Update();
	}
	static vector<clsCurrency> getCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}
	static clsCurrency findByCode(string code)
	{
		code = clsString::UpperAllString(code);
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (currency.getCode() == code)
				{
					myFile.close();
					return currency;
				}
			}
			
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency findByCountry(string country)
	{
		country = clsString::UpperAllString(country);
		fstream myFile;
		myFile.open("Currencies.txt", ios::in);
		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				if (currency.getCountry() == country)
				{
					myFile.close();
					return currency;
				}
			}

		}
		return _GetEmptyCurrencyObject();
	}
	static bool isCurrencyExist(string code)
	{
		clsCurrency currency = clsCurrency::findByCode(code);
		return (!currency.isEmpty());
	}
	bool isEmpty()
	{
		return (this->_Mode == enMode::EmptyMode);
	}
	

};

