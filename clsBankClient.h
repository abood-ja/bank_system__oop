#pragma once
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"

class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
    {
        vector<string>vClientData = clsString::Split(line, seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
public:
    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double accountBalance) :
        clsPerson(firstName, lastName, email, phone)
    {
        _Mode = mode;
        _AccountNumber = accountNumber;
        _AccountBalance = accountBalance;

    }
    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    string getAccountNumber()
    {
        return _AccountNumber;
    }
    void setPinCode(string pinCode)
    {
        _PinCode = pinCode;
    }
    string getPinCode()
    {
        return _PinCode;
    }
    void setAccountBalance(double accountBalance)
    {
        _AccountBalance = accountBalance;
    }
    double getAccountBalance()
    {
        return _AccountBalance;
    }
    void print()
    {
        cout << "\nClient Card:";
        cout << "\n-----------------------------------";
        cout << "\nFirst Name: " << firstName;
        cout << "\nLast Name : " << lastName;
        cout << "\nFull Name : " << getFullName();
        cout << "\nEmail     : " << email;
        cout << "\nPhone     : " << phone;
        cout << "\nAcc Number: " << getAccountNumber();
        cout << "\nPassword  : " << pinCode;
        cout << "\nBalance   : " << accountBalance;
        cout << "\n-----------------------------------";

    }
    static clsBankClient find(string accountNumber)
    {
        vector<clsBankClient> vClients;
        fstream myFile;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                if (client.getAccountNumber() == accountNumber)
                {
                    myFile.close();
                    return client;

                }
                vClients.push_back(client);
            }
            myFile.close();
        }
        return _GetEmptyClientObject();
    }
    static clsBankClient find(string accountNumber, string pinCode)
    {
        vector<clsBankClient> vClients;
        fstream myFile;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                if (client.getAccountNumber() == accountNumber && client.pinCode == pinCode)
                {
                    myFile.close();
                    return client;

                }
                vClients.push_back(client);
            }
            myFile.close();
        }
        return _GetEmptyClientObject();
    }
    static bool isClientExist(string accountNumber)
    {
        clsBankClient client = find(accountNumber);
        return !(client.isEmpty());
    }
    __declspec(property(get = getAccountBalance, put = setAccountBalance))double accountBalance;
    __declspec(property(get = getPinCode, put = setPinCode))string pinCode;

};
