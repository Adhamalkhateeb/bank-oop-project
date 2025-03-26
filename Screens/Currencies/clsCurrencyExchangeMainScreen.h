#pragma once
#include <iostream>
#include <iomanip>
#include "../clsScreen.h"
#include "../../Core Utility Classes/clsInputValidate.h"
#include "../../Entities/clsUser.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalaculatorScreen.h"
using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeMenuOption {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3
        , eCurrencyClaculator = 4, eShowMainMenu = 5
    };

    static short ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowCurrenciesListScreen()
    {
        clsCurrencyListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << "\n\nPress any key to go back to CurrencyExchange Menu...";
        system("pause>0");
        ShowCurrenciesExchangeMenu();

    }

    static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOption CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case enCurrencyExchangeMenuOption::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOption::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOption::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchangeMenuOption::eCurrencyClaculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case enCurrencyExchangeMenuOption::eShowMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }

public:


    static void ShowCurrenciesExchangeMenu()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pCurrenciesExchange))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t  Currency Exchange main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Currencies List.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOption)ReadCurrencyExchangeMenuOption());
    }
};

