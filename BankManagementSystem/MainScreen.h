#pragma once

#include "Screen.h"

class MainScreen : public Screen
{
private:
	enum class MainMenuOptions
	{
        ClientList = 1,
        AddClient,
        DeleteClient,
        UpdateClient,
        FindClient,
        Transactions,
        UserManagement,
        Logout
	};

    MainMenuOptions _ReadMainMenuOption();
public:
	static void ShowMainMenuScreen();
};

