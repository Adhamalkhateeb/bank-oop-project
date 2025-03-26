#pragma once
#include <iostream>
#include "../../Entities/clsUser.h"
#include <iomanip>
#include "../clsScreen.h"

class clsLoginRegisterScreen :protected clsScreen
{
    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord User)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << User.DateTime;
        cout << "| " << setw(20) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;

    }
public:
    static void ShowLoginRegisterList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLogins = clsUser::GetRegisterList();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLogins.size()) + ") Login(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "USerName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogins.size() == 0)
            cout << "\t\t\t\tNo Logins register Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord User : vLogins)
            {

                _PrintLoginRegisterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

