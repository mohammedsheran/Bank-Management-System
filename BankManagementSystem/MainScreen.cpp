
#include "MainScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"
#include "ClientListScreen.h"
#include "AddClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionsScreen.h"

void MainScreen::ShowMainMenuScreen()
{
    Screen::ClearScreen();
	Screen::ShowScreenHeader("Main Menu Screen");

    cout << Utils::Tab(4) << "[1] Show Client List."
        << Utils::Tab(2) << "[5] Find Client.\n";

    cout << Utils::Tab(4) << "[2] Add New Client."
        << Utils::Tab(2) << "[6] Transactions.\n";

    cout << Utils::Tab(4) << "[3] Delete Client."
        << Utils::Tab(2) << "[7] User Management.\n";

    cout << Utils::Tab(4) << "[4] Update Client."
        << Utils::Tab(2) << "[8] Logout.\n\n";

    cout << Utils::Divider(110) << '\n';

    _HandleMainMenuOption(_ReadMainMenuOption());
}

MainScreen::MainMenuOptions MainScreen::_ReadMainMenuOption()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-8]: ", static_cast<short>(1), static_cast<short>(8)) };
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
        Screen::ClearScreen();
        _ShowTransactionsMenu();
        break;
    case MainScreen::MainMenuOptions::MangeUsers:
        Screen::ClearScreen();
        _ShowMangeUsersMenu();
        break;
    case MainScreen::MainMenuOptions::Logout:
        Screen::ClearScreen();
        _ShowEndScreen();
        break;
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
    cout << "Mange User Menu" << endl;
}

void MainScreen::_ShowEndScreen()
{
    cout << "End Screen" << endl;
}