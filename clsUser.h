#pragma once
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"

class clsUser:public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1,AddNewMode=2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete=false;
	static clsUser _ConvertLinetoUserObject(string Line, string seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}
	static string _ConvertUserObjectToLine(clsUser user, string seperator = "#//#")
	{
		string line = "";
		line += user.getFirstName() + seperator;
		line += user.getLastName() + seperator;
		line += user.getEmail() + seperator;
		line += user.getPhone() + seperator;
		line += user.getUserName() + seperator;
		line += user.getPassword() + seperator;
		line += to_string(user.getPermissions() )+ seperator;
		return line;
	}
	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser>vUsers;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return vUsers;
	}
	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{

		fstream myFile;
		myFile.open("Users.txt", ios::out);
		string dataLine;

		if (myFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U.MarkedForDeleted() == false)
				{
					dataLine = _ConvertUserObjectToLine(U);
					myFile << dataLine << endl;
				}
			}
			myFile.close();
		}
	}
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	void _Update()
	{
		vector<clsUser>vUsers = _LoadUsersDataFromFile();
		for (clsUser &user:vUsers)
		{
			if (user.userName== this->userName)
			{
				user = *this;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}
	void _AddDataLineToFile(string stDataLine)
	{
		fstream myFile;
		myFile.open("Users.txt", ios::out | ios::app);
		if (myFile.is_open())
		{
			myFile << stDataLine << endl;
			myFile.close();
		}
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
public:
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}
	bool isEmpty()
	{
		return (this->_Mode== enMode::EmptyMode);
	}
	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	void setUserName(string userName)
	{
		this->_UserName = userName;
	}
	string getUserName()
	{
		return this->_UserName;
	}
	void setPassword(string password)
	{
		this->_Password = password;
	}
	string getPassword()
	{
		return this->_Password;
	}
	void setPermissions(int permissions)
	{
		this->_Permissions = permissions;
	}
	int getPermissions()
	{
		return this->_Permissions;
	}
	static clsUser find(string userName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser user = _ConvertLinetoUserObject(Line);
				if (user.userName == userName)
				{
					MyFile.close();
					return user;
				}
			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}
	static clsUser find(string userName,string password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser user = _ConvertLinetoUserObject(Line);
				if (user.userName == userName&&user.password==password)
				{
					MyFile.close();
					return user;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
	 enSaveResults save()
	 {
		 switch (_Mode)
		 {
		 case enMode::EmptyMode:
		 {
			 if (isEmpty())
			 {
				 return enSaveResults::svFaildEmptyObject;
			 }
		 }

		 case enMode::UpdateMode:
		 {
			 _Update();
			 return enSaveResults::svSucceeded;
			 break;
		 }
		 case enMode::AddNewMode:
		 {
			 if (clsUser::isUserExist(_UserName))
			 {
				 return enSaveResults::svFaildUserExists;
			 }
			 else
			 {
				 _AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResults::svSucceeded;
			 }
			 break;
		 }
		 }
	 }
	static bool isUserExist(string userName)
	{
		clsUser user = find(userName);
		return !user.isEmpty();
	}
	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}
	static vector <clsUser> getUsersList()
	{
		return _LoadUsersDataFromFile();
	}
	bool _Delete()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile();
		for (clsUser& user : vUsers)
		{
			if (user.userName == _UserName)
			{
				user._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}
	__declspec(property(get = getUserName, put = setUserName)) string userName;
	__declspec(property(get = getPassword, put = setPassword)) string password;
	__declspec(property(get = getPermissions, put = setPermissions)) int permissions;
};

