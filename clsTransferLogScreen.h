#pragma once
#include "clsScreen.h"

class clsTransferLogScreen:protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord transferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << transferLogRecord.dateTime;
        cout << "| " << setw(8) << left << transferLogRecord.transferFrom;
        cout << "| " << setw(8) << left << transferLogRecord.transferTo;
        cout << "| " << setw(8) << left << transferLogRecord.amount;
        cout << "| " << setw(10) << left << transferLogRecord.transferFromBalance;
        cout << "| " << setw(10) << left << transferLogRecord.transferToBalance;
        cout << "| " << setw(8) << left << transferLogRecord.userName;
    }
public:
	static void showTransferLogScreen()
	{
        vector<clsBankClient::stTransferLogRecord>vTransferLogRecords = clsBankClient::getTransferLogList();
		string title = "\t  Transfer Log List Screen";
        string subTitle = "\t    (" + to_string(vTransferLogRecords.size()) + ") Records(s).";
		_DrawScreenHeader(title,subTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vTransferLogRecords.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else
        {
	        for (clsBankClient::stTransferLogRecord record:vTransferLogRecords)
	        {
                PrintTransferLogRecordLine(record);
                cout << endl;
	        }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

