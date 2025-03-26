#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../Core Utility Classes/clsInputValidate.h"
#include "../../Entities/clsCurrency.h"
class clsFindCurrencyScreen : protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate(1$)  : " << Currency.Rate();
        cout << "\n___________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By [1] Code or [2] Country ? ";
        short Number = clsInputValidate<short>::ReadNumberBetween(1, 2);

        if (Number == 1)
        {
            cout << "\nPlease enter Currency Code: ";
            string CurrencyCode = clsInputValidate<short>::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            cout << "\nPlease enter Country: ";
            string CountryName = clsInputValidate<short>::ReadString();
            clsCurrency Country = clsCurrency::FindByCountry(CountryName);
            _ShowResults(Country);
        }

    }


};

