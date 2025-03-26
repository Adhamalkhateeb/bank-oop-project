#pragma once
#include "iostream"
#include "../clsScreen.h"
#include "../../Screens/Main/clsMainScreen.h"
#include "../../Entities/clsUser.h"
#include  "../../clsGlobal.h"


using namespace std;

class clsLoginScreen : protected clsScreen
{

private:
	static bool _Login()
	{
		bool LoginFailed = false;
		string UserName, password;
		short Trails = 3;

		do
		{
			if (LoginFailed)
			{
				Trails--;
				cout << "\nInvalid password/UserName!\n";
				cout << "You Have " << Trails << "Trail(s) to login\n";
			}

			if (Trails == 0)
			{
				system("color 4F");
				cout << "\nyou are locked\n\n";
				return false;
			}

			cout << "\nEnter USerName: ";
			cin >> UserName;
			cout << "Enter Password: ";
			cin >> password;

			CurrentUser = clsUser::Find(UserName, password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;
	}



public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		return _Login();
	}
};

