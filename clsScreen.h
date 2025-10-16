#pragma once
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include <iostream>
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
	}
};

