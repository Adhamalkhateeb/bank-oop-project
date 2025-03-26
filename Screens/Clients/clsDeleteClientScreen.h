#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Entities/clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n________________________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n_______________________________\n";


    }
public:
    static void ShowDeleteClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\t  Delete Client Screen");

        cout << "Please enter client account number? ";
        string AccNumber = clsInputValidate<short>::ReadString();

        while (!clsBankClient::IsClientExist(AccNumber))
        {
            cout << "\nAccount Number is Not Found ,choose another one: ";
            AccNumber = clsInputValidate<short>::ReadString();
        }

        clsBankClient DeleteClient = clsBankClient::Find(AccNumber);
        _PrintClient(DeleteClient);

        char Answer = 'N';

        cout << "Are you sure you want delete this client Y/N ? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (DeleteClient.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";

                _PrintClient(DeleteClient);
            }
            else
            {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};

