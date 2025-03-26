#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
class clsUtile
{

public:

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int RandNum = rand() % (To - From + 1) + From;
        return RandNum;
    }

    enum enCharType { Smallletters = 1, CapitalLetter = 2, Digit = 3, MixChars = 4, specialcharacter = 5 };

    static char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::Smallletters:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::specialcharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        case enCharType::MixChars:
        {
            CharType = (enCharType)RandomNumber(1, 4);
            return char(GetRandomCharacter(CharType));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static string GenerateWord(enCharType charType, short Length)
    {
        string Word = "";
        for (short i = 0; i < Length; i++)
        {
            Word += GetRandomCharacter(charType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);
        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& Num1, int& Num2)
    {
        int Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double Temp;
        Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(string& S1, string& S2)
    {
        string Temp;
        Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(clsDate& D1, clsDate& D2)
    {
        clsDate::SwapDates(D1, D2);
    }

    static void ShuffleArray(int arr[], short arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void ShuffleArray(string arr[], short arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }
    }

    static void FillArrayWithRandomNumber(int arr[], short arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = RandomNumber(From, To);
        };
    }

    static void FillArrayWithRandomWords(string arr[], short arrLength, enCharType CharType, short wordlength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateWord(CharType, wordlength);
        };
    }

    static void FillArrayWithRandomKeys(string arr[], short arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = GenerateKey(CharType);
        };
    }

    static string EncryptText(string Text, short encryptionkey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + encryptionkey);
        }
        return Text;
    }

    static string DecryptText(string Text, short encryptionkey)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - encryptionkey);
        }
        return Text;
    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }
        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "",
            "One","Two","Three","Four","Five","Six","Seven",
            "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
            "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
            return arr[Number] + " ";
        }
        if (Number >= 20 && Number <= 99)
        {
            string arr[] = {
            "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
            ,"Ninety" };
            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }
        if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }
        if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " +
                NumberToText(Number % 100);
        }
        if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }
        if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " +
                NumberToText(Number % 1000);
        }
        if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }
        if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Millions " +
                NumberToText(Number % 1000000);
        }
        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number %
                1000000000);
        }
        else
        {
            return NumberToText(Number / 1000000000) + "Billions " +
                NumberToText(Number % 1000000000);
        }
    }

};




