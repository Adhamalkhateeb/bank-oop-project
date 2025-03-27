#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core Utility Classes/clsInputValidate.h"
#include "../../Screens/Clients/clsClientListScreen.h"
#include "../../Screens/Clients/clsAddNewClientScreen.h"
#include "../../Screens/Clients/clsDeleteClientScreen.h"
#include "../../Screens/Clients//clsUpdateClientScreen.h"
#include "../../Screens/Clients/clsFindClientScreen.h"
#include "../../Screens/Transactions/clsTransactionScreen.h"
#include "../../Screens/Users/clsManageUsers.h"
#include "../../clsGlobal.h"
#include "../Authentication/clsLoginRegisterScreen.h"
#include "../../Screens/Currencies/clsCurrencyExchangeMainScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen
{

private:
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCuurencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {

        clsUpdateClientScreen::ShowUpdateMenuScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterList();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesExchangeMenu();
    }


    static void _LogOut()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eCuurencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eExit:
            system("cls");
            _LogOut();

            break;
        }

    }



public:


    static void ShowMainMenu()
    {
        system("color 0F");
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }
};

