#include <iostream>
#include "Screens/Authentication/clsLoginScreen.h"


int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }


    return 0;
}