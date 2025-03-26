#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Entities/clsBankClient.h"
#include "../../Core Utility Classes/clsUtil.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(45) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static void ShowTotalBalancesList()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string Title = "\t  Total Balances Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(45) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();


        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << left << "" << "\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtile::NumberToText(TotalBalances) << ")";
    }

};

