#pragma once
#include <iostream>
#include <string>
#include "../Core Utility Classes/clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsCurrency
{

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;
    string _Country;
    string _Code;
    string _Currency;
    double _Rate;

    static clsCurrency  _ConvertLineToCurrencyObject(string Line, string separator = "#//#")
    {

        vector <string> vCurrency = clsString::Split(Line, separator);
        return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stod(vCurrency[3]));
    }

    static string  _ConvertCurrenciesObjectToLine(clsCurrency Currency, string separator = "#//#")
    {
        string stCurrencyRecord = "";

        stCurrencyRecord += Currency.Country() + separator;
        stCurrencyRecord += Currency.CurrencyCode() + separator;
        stCurrencyRecord += Currency.CurrencyName() + separator;
        stCurrencyRecord += to_string(Currency.Rate()) + separator;

        return stCurrencyRecord;
    }

    static  vector <clsCurrency> _LoadCurrencyDataFromFile()
    {

        vector <clsCurrency> vCurrency;

        fstream MyFile;
        MyFile.open("Data/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                vCurrency.push_back(Currency);
            }

            MyFile.close();

        }

        return vCurrency;

    }

    static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrency)
    {

        fstream MyFile;
        MyFile.open("Data/Currencies.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency& C : vCurrency)
            {

                DataLine = _ConvertCurrenciesObjectToLine(C);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencies;
        _vCurrencies = _LoadCurrencyDataFromFile();

        for (clsCurrency& C : _vCurrencies)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }
        }
        _SaveCurrenciesDataToFile(_vCurrencies);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }


public:

    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, double Rate)
    {
        _Mode = Mode;
        _Country = Country;
        _Code = CurrencyCode;
        _Currency = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _Code;
    }

    string CurrencyName()
    {
        return _Currency;
    }

    void UpdateRate(double NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }


    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Data/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCode(string Code)
    {
        Code = clsString::UpperAllString(Code);

        fstream MyFile;
        MyFile.open("Data/Currencies.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.CurrencyCode()) == Code)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();

        }
        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());

    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();
    }

    double ConvertToUSD(double Amount)
    {
        return (double)(Amount / Rate());
    }

    double ConvertToOtherCurrency(double Amount, clsCurrency Currency2)
    {
        double AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currency2.Rate());

    }

};

