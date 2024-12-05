#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsLoginRegister
{
public:
	static void LoginRegister()
	{
		
		fstream File;
		File.open("LoginRegister.txt", ios::out | ios::app);
		if (File.is_open())
		{
			string Line = 
				clsDate::DateToString(clsDate()) + " - " + 
				CurrentUser.UserName + "#//#" + 
				CurrentUser.Password + "#//#" + 
				to_string(CurrentUser.Permissions);
			File << Line << "\n";
		}
		File.close();
	}
};

