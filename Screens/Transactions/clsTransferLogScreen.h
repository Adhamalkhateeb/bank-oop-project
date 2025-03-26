#pragma once
#include <iostream>
#include "../../Entities/clsBankClient.h"
#include <iomanip>
#include "../clsScreen.h"
class clsTransferLogScreen : protected clsScreen
{

    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLog Transfer)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << Transfer.DateTime;
        cout << "| " << setw(10) << left << Transfer.FromClient;
        cout << "| " << setw(10) << left << Transfer.ToClient;
        cout << "| " << setw(10) << left << Transfer.AmountTransferred;
        cout << "| " << setw(10) << left << Transfer.client1Balance;
        cout << "| " << setw(10) << left << Transfer.client2Balance;
        cout << "| " << setw(10) << left << Transfer.User;

    }
public:

    static void ShowTransferLogList()
    {

        vector <clsBankClient::stTransferLog> vTransfers = clsBankClient::GetTransfersList();
        string Title = "\t  Transfers Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransfers.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransfers.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLog Transfer : vTransfers)
            {

                _PrintTransferLogRecordLine(Transfer);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

