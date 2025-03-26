#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Entities/clsBankClient.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter First Name? ";
        Client.FirstName = clsInputValidate<short>::ReadString();

        cout << "\nEnter last Name? ";
        Client.LastName = clsInputValidate<short>::ReadString();

        cout << "\nEnter email? ";
        Client.Email = clsInputValidate<short>::ReadString();

        cout << "\nEnter Phone? ";
        Client.Phone = clsInputValidate<short>::ReadString();

        cout << "\nEnter PinCode? ";
        Client.PinCode = clsInputValidate<short>::ReadString();

        cout << "\nEnter AccountBalance? ";
        Client.AccountBalance = clsInputValidate<float>::ReadNumber();
    }

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
    static void ShowAddNewClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate<short>::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate<short>::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }


};

