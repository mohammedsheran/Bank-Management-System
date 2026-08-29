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
        MangeUsers,
        CurrencyExchange,
        Logout
	};

    static MainMenuOptions _ReadMainMenuOption();

    static void _ReturnToMainMenu();

    static void _ShowClientListScreen();

    static void _ShowAddClientScreen();

    static void _ShowDeleteClientScreen();

    static void _ShowUpdateClientScreen();

    static void _ShowFindClientScreen();

    static void _ShowTransactionsMenu();

    static void _ShowMangeUsersMenu();

    static void _ShowCurrencyExchangeMenu();

    static void _Logout();

    static void _HandleMainMenuOption(MainMenuOptions option);
public:
	static void ShowMainMenuScreen();
};

