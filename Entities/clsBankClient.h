#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "../Core Utility Classes/clsString.h"
#include "../Core Utility Classes/clsInputValidate.h"
#include "../Core Utility Classes/clsUtil.h"
#include <vector>
#include <fstream>
#include "../clsGlobal.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

    struct stTransferLog;



    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static stTransferLog _ConvertTransferLogLineToRecord(string Line, string Separator = "#//#")
    {
        stTransferLog TransferLogRecord;


        vector <string> TransferLogdataline = clsString::Split(Line, Separator);
        TransferLogRecord.DateTime = TransferLogdataline[0];
        TransferLogRecord.FromClient = TransferLogdataline[1];
        TransferLogRecord.ToClient = TransferLogdataline[2];
        TransferLogRecord.AmountTransferred = stof(TransferLogdataline[3]);
        TransferLogRecord.client1Balance = stod(TransferLogdataline[4]);
        TransferLogRecord.client2Balance = stod(TransferLogdataline[5]);
        TransferLogRecord.User = TransferLogdataline[6];

        return TransferLogRecord;

    }

    static clsBankClient  _ConvertLineToClientObject(string Line, string separator = "#//#")
    {

        vector <string> vClients = clsString::Split(Line, separator);
        return clsBankClient(enMode::UpdateMode, vClients[0], vClients[1], vClients[2], vClients[3],
            vClients[4], vClients[5], stod(vClients[6]));
    }

    static string  _ConvertClientObjectToLine(clsBankClient Client, string separator = "#//#")
    {
        string stClientRecord = "";

        stClientRecord += Client.FirstName + separator;
        stClientRecord += Client.LastName + separator;
        stClientRecord += Client.Email + separator;
        stClientRecord += Client.Phone + separator;
        stClientRecord += Client.AccountNumber() + separator;
        stClientRecord += Client.PinCode + separator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient& C : vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
    }


    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
        string UserName, string Separator = "#//#")
    {
        string TransferLogRecord = "";
        TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
        TransferLogRecord += AccountNumber() + Separator;
        TransferLogRecord += DestinationClient.AccountNumber() + Separator;
        TransferLogRecord += to_string(Amount) + Separator;
        TransferLogRecord += to_string(AccountBalance) + Separator;
        TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
    {

        fstream MyFile;
        MyFile.open("Data/TransferLog.txt", ios::out | ios::app);
        string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

        if (MyFile.is_open())
        {


            MyFile << DataLine << endl;

            MyFile.close();

        }

    }

    static  vector <stTransferLog> _LoadTransfersDataFromFile()
    {

        vector <stTransferLog> vTransfers;

        fstream MyFile;
        MyFile.open("Data/TransferLog.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                stTransferLog Transfers = _ConvertTransferLogLineToRecord(Line);

                vTransfers.push_back(Transfers);
            }

            MyFile.close();

        }

        return vTransfers;

    }


public:

    struct stTransferLog
    {
        string DateTime;
        string FromClient;
        string ToClient;
        float AmountTransferred;
        double client1Balance;
        double client2Balance;
        string User;

    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkForDelete;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    static clsBankClient Find(string AccountNumber)
    {

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Data/Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if ((Client.AccountNumber() == AccountNumber) && (Client.PinCode == PinCode))
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {

            _Update();

            return enSaveResults::svSucceeded;

            break;
        }
        case enMode::AddNewMode:
        {
            if (IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
            break;
        }
        }
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C._MarkForDelete = true;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = GetClientList();
        double TotalBalances = 0;
        for (clsBankClient& C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }

        return TotalBalances;
    }

    void Deposit(double depositAmount)
    {
        _AccountBalance += depositAmount;
        Save();
    }

    bool WithDraw(double withDrawAmount)
    {
        stTransferLog Transfer;
        if (_AccountBalance < withDrawAmount)
        {
            return false;
        }
        else
        {
            _AccountBalance -= withDrawAmount;
            Save();
        }
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
    {
        stTransferLog Transfer;
        if (Amount > AccountBalance)
        {
            return false;
        }

        WithDraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    static vector <stTransferLog> GetTransfersList()
    {
        return _LoadTransfersDataFromFile();
    }
};