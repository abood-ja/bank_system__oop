#pragma once
#include "clsScreen.h"

class clsLoginRegisterScreen :protected clsScreen
{
private:
	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.dateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.userName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.permissions;
	}
public:
	static void showLoginRegisterScreen()
	{
		
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}
		vector<clsUser::stLoginRegisterRecord> vloginRegisterRecords = clsUser::getLoginRegisterList();
		string title = "\t  Login Register List Screen";
		string subTitle = "\t    (" + to_string(vloginRegisterRecords.size()) + ") Records(s).";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vloginRegisterRecords.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegisterRecord Record : vloginRegisterRecords)
			{

				PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}
};

