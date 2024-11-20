#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
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
    static void FindClientScreen()
    {
        string Find;
        cout << "Please enter an account number: ";
        Find = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(Find))
        {
            string Find;
            cout << "Please enter an account number: ";
            Find = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(Find);
        Client.Print();
    }
    


};