
#include "MainScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"
#include "ClientListScreen.h"
#include "AddClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsScreen.h"
#include "ManageUsersScreen.h"
#include "CurrencyExchangeScreen.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void MainScreen::ShowMainMenuScreen()
{
    Screen::ClearScreen();
	Screen::ShowScreenHeader("Main Menu Screen");

    cout << Utils::Tab(4) << "[1] Show Client List."
        << Utils::Tab(2) << "[6] Transactions.\n";

    cout << Utils::Tab(4) << "[2] Add New Client."
        << Utils::Tab(2) << "[7] Manage Users.\n";

    cout << Utils::Tab(4) << "[3] Delete Client."
        << Utils::Tab(2) << "[8] Currency Exchange.\n";

    cout << Utils::Tab(4) << "[4] Update Client."
        << Utils::Tab(2) << "[9] Logout.\n";

    cout << Utils::Tab(4) << "[5] Find Client.\n\n";

    cout << Utils::Divider(110) << '\n';

    _HandleMainMenuOption(_ReadMainMenuOption());
}

MainScreen::MainMenuOptions MainScreen::_ReadMainMenuOption()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-9]: ", static_cast<short>(1), static_cast<short>(9)) };
    return static_cast<MainMenuOptions>(option);
}

void MainScreen::_ReturnToMainMenu()
{
    Screen::PauseScreen("Press any key to return to main menu...");

    ShowMainMenuScreen();
}

void MainScreen::_HandleMainMenuOption(MainMenuOptions option)
{
    switch (option)
    {
    case MainScreen::MainMenuOptions::ClientList:
        Screen::ClearScreen();
        _ShowClientListScreen();
        break;
    case MainScreen::MainMenuOptions::AddClient:
        Screen::ClearScreen();
        _ShowAddClientScreen();
        break;
    case MainScreen::MainMenuOptions::DeleteClient:
        Screen::ClearScreen();
        _ShowDeleteClientScreen();
        break;
    case MainScreen::MainMenuOptions::UpdateClient:
        Screen::ClearScreen();
        _ShowUpdateClientScreen();
        break;
    case MainScreen::MainMenuOptions::FindClient:
        Screen::ClearScreen();
        _ShowFindClientScreen();
        break;
    case MainScreen::MainMenuOptions::Transactions:
        _ShowTransactionsMenu();
        break;
    case MainScreen::MainMenuOptions::MangeUsers:
        _ShowMangeUsersMenu();
        break;
    case MainScreen::MainMenuOptions::CurrencyExchange:
        _ShowCurrencyExchangeMenu();
        break;
    case MainScreen::MainMenuOptions::Logout:
        Screen::ClearScreen();
        _Logout();
        return;
    }

    _ReturnToMainMenu();
}

void MainScreen::_ShowClientListScreen()
{
    ClientListScreen::ShowClientList();
}

void MainScreen::_ShowAddClientScreen()
{
    AddClientScreen::ShowAddClientScreen();
}

void MainScreen::_ShowDeleteClientScreen()
{
    DeleteClientScreen::ShowDeleteClientScreen();
}

void MainScreen::_ShowUpdateClientScreen()
{
    UpdateClientScreen::ShowUpdateClientScreen();
}

void MainScreen::_ShowFindClientScreen()
{
    FindClientScreen::ShowFindClientScreen();
}

void MainScreen::_ShowTransactionsMenu()
{
    TransactionsScreen::ShowTransactionsMenuScreen();
}

void MainScreen::_ShowMangeUsersMenu()
{
    ManageUsersScreen::ShowManageUsersMenu();
}

void MainScreen::_ShowCurrencyExchangeMenu()
{
    CurrencyExchangeScreen::ShowCurrencyExchangeMenuScreen();
}

void MainScreen::_Logout()
{
    Logger::Info(LogMessages::loggedOut + " | " + currentUser.Username);
    currentUser = User::Find("", "");
}