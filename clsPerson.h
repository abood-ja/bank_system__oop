#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string firstName, string lastName, string email, string phone)
    {
        _FirstName = firstName;
        _LastName = lastName;
        _Email = email;
        _Phone = phone;
    }
    void setFirstName(string firstName)
    {
        _FirstName = firstName;
    }
    void setLastName(string lastName)
    {
        _LastName = lastName;
    }
    void setEmail(string email)
    {
        _Email = email;
    }
    void setPhone(string phone)
    {
        _Phone = phone;
    }
    string getFirstName()
    {
        return _FirstName;
    }
    string getLastName()
    {
        return _LastName;
    }
    string getFullName()
    {
        return _FirstName + " " + _LastName;
    }
    string getEmail()
    {
        return  _Email;
    }
    string getPhone()
    {
        return _Phone;
    }
    __declspec(property(get = getFirstName, put = setFirstName))string firstName;
    __declspec(property(get = getLastName, put = setLastName))string lastName;
    __declspec(property(get = getEmail, put = setEmail))string email;
    __declspec(property(get = getPhone, put = setPhone))string phone;

};
