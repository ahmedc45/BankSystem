#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:
    

    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("Withdraw Screen");
        string Choose;
        cout << "Please enter AccountNumber: ";
        Choose = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(Choose))
        {
            cout << "Please enter AccountNumber: ";
            Choose = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(Choose);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDblNumber();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Amount < Client.AccountBalance)
            {
                Client.Withdraw(Amount);
                cout << "\nAmount Deposited Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance;
            }
            else
            {
                cout << "This Amount is big";
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }
};

