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

    static MainMenuOptions _ReadMainMenuOption();

    static void _ReturnToMainMenu();

    static void _HandleMainMenuOption(MainMenuOptions option);
public:
	static void ShowMainMenuScreen();
};

