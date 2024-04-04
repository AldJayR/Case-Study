#include <iostream>
#include <string>
#include "admin_system.h"


// Admin System to be added by other members

using namespace std;

void adminInterface()
{
    cout << "--------------------------------------------------------------------------------\n";
    cout << "                               Admin Interface" << '\n';
    cout << "Welcome!" << '\n';

    constexpr int options = 3;

    string adminOptions[options] = {"Update Menu Items", "Update Menu Prices", "Change Password"};


    cout << "Admin Options: " << '\n';
    for (int i = 0; i < 3; i++)
    {
        cout << "(" << i + 1 << ")" << " " << adminOptions[i] << '\n';
    }
    int pick;
    cin >> pick;
}


void adminLogin(bool &passwordStatus)
{
    bool locked = true;
    int maxTrials = 3;

    while (locked)
    {
        cout << "Enter password: " << '\n';
        string password;
        getline(cin >> ws, password);

        string correctPassword = "diamond in the blue";

        if (password == correctPassword)
        {
            adminInterface();
            locked = false;
        }
        else
        {
            cout << "Incorrect password! Please try again! " << maxTrials << " attempts left" << '\n';
            --maxTrials;
            if (maxTrials > 0)
            {
                continue;
            }
            else
            {
                cout << "You have reached maximum attempt for entering the password!" << '\n';
                passwordStatus = true;
                break;
            }
        }
    }
}


