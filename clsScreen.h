#pragma once
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include <iostream>
#include "clsUser.h"
#include "global.h"

class clsScreen
{
protected:
	static void _DrawScreenHeader(string title,string subTitle="")
	{
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\tUser: " << currentUser.getFullName() << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())<< "\n\n";
        
	}
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!currentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

