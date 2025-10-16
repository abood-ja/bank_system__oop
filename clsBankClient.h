#pragma once
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"

class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;
    static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
    {
        vector<string>vClientData = clsString::Split(line, seperator);
        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static vector< clsBankClient> _LoadClientsDataFromFile()
    {
        fstream myFile;
        vector<clsBankClient>vClients;
        myFile.open("Clients.txt", ios::in);
        if (myFile.is_open())
        {
            string line;
            
            while (getline(myFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                vClients.push_back(client);
            }
            myFile.close();
        }
        return vClients;

    }
    static string _ConvertClientObjectToLine(clsBankClient client, string seperator = "#//#")
    {
        string clientRecord = "";
        clientRecord += client.firstName + seperator;
        clientRecord += client.lastName + seperator;
        clientRecord += client.email + seperator;
        clientRecord += client.phone + seperator;
        clientRecord += client.getAccountNumber() + seperator;
        clientRecord += client.pinCode + seperator;
        clientRecord += to_string(client.accountBalance);
        return clientRecord;
    }
    static void _SaveClientsDataToFile(vector<clsBankClient>vClients)
    {
        fstream myFile;
        myFile.open("Clients.txt", ios::out);
        string dataLine;
        if (myFile.is_open())
        {
            for (clsBankClient& client : vClients)
            {
                if (client._MarkedForDelete == false) {
                    dataLine = _ConvertClientObjectToLine(client);
                    myFile << dataLine << endl;
                }
            }
            myFile.close();
        }

    }
    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }
     void _AddNew()
    {
         _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }
     void _Update()
     {



        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &client :_vClients)
        {
	        if (client.getAccountNumber()==this->getAccountNumber())
	        {
                client = *this;
                break;
	        }
        }
        _SaveClientsDataToFile(_vClients);
     }
public:
    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double accountBalance) :
        clsPerson(firstName, lastName, email, phone)
    {
        _Mode = mode;
        this->pinCode = pinCode;
        _AccountNumber = accountNumber;
        _AccountBalance = accountBalance;


    }
    bool isEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    static double getTotalBalances()
    {
        vector<clsBankClient>vClients = _LoadClientsDataFromFile();
        double total = 0;
        for (clsBankClient &client:vClients)
        {
            total += client.accountBalance;
        }
        return total;
    }
    bool getMarkedForDeleted()
    {
        return _MarkedForDelete;
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
    bool Delete()
    {
        vector<clsBankClient>_vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient &client:_vClients)
        {
	        if (client.getAccountNumber()==getAccountNumber())
	        {
                client._MarkedForDelete = true;
                break;
	        }
        }
        _SaveClientsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;

        
    }
    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        save();
    }
    enum enSaveResults { svFailedEmptyObject = 0,svSucceeded=1, svFailedAccountNumberExists=2};
    enSaveResults save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFailedEmptyObject;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddNewMode:
            if (isEmpty())
            {
                return enSaveResults::svFailedAccountNumberExists;
            }
            else
            {
                _AddNew();
                this->_Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
	    }
    }
    static clsBankClient getAddNewClientObject(string accountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "",0);
    }
    static vector<clsBankClient> getClientList() {
        return _LoadClientsDataFromFile();
    }
    __declspec(property(get = getAccountBalance, put = setAccountBalance))double accountBalance;
    __declspec(property(get = getPinCode, put = setPinCode))string pinCode;
};
