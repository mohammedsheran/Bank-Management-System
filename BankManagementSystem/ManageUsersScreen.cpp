
#include "ManageUsersScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"
#include "UserListScreen.h"
#include "AddUserScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"

void ManageUsersScreen::ShowManageUsersMenu()
{
    Screen::ClearScreen();
	Screen::ShowScreenHeader("Manage Users Screen");

    cout << Utils::Tab(4) << "[1] Show User List."
        << Utils::Tab(2) << "[4] Update User.\n";

    cout << Utils::Tab(4) << "[2] Add New User."
        << Utils::Tab(2) << "[5] Find User.\n";

    cout << Utils::Tab(4) << "[3] Delete User."
        << Utils::Tab(2) << "[6] Main Menu.\n\n";

    cout << Utils::Divider(110) << '\n';

    _HandleManageUsersMenuOption(_ReadManageUsersMenuOption());
}

ManageUsersScreen::ManageUserMenuOptions ManageUsersScreen::_ReadManageUsersMenuOption()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-6]: ", static_cast<short>(1), static_cast<short>(6)) };
    return static_cast<ManageUserMenuOptions>(option);
}

void ManageUsersScreen::_ReturnToManageUsersMenu()
{
    Screen::PauseScreen("\nPress any key to return to manage users menu...");

    ShowManageUsersMenu();
}

void ManageUsersScreen::_HandleManageUsersMenuOption(ManageUserMenuOptions option)
{
    switch (option)
    {
    case ManageUsersScreen::ManageUserMenuOptions::UserList:
        Screen::ClearScreen();
        _ShowUserListScreen();
        break;

    case ManageUsersScreen::ManageUserMenuOptions::AddUser:
        Screen::ClearScreen();
        _ShowAddUserScreen();
        break;

    case ManageUsersScreen::ManageUserMenuOptions::DeleteUser:
        Screen::ClearScreen();
        _ShowDeleteUserScreen();
        break;

    case ManageUsersScreen::ManageUserMenuOptions::UpdateUser:
        Screen::ClearScreen();
        _ShowUpdateUserScreen();
        break;

    case ManageUsersScreen::ManageUserMenuOptions::FindUser:
        Screen::ClearScreen();
        _ShowFindUserScreen();
        break;

    case ManageUsersScreen::ManageUserMenuOptions::MainMenu:
        return;
    }

    _ReturnToManageUsersMenu();
}

void ManageUsersScreen::_ShowUserListScreen()
{
    UserListScreen::ShowUserListScreen();
}

void ManageUsersScreen::_ShowAddUserScreen()
{
    AddUserScreen::ShowAddUserScreen();
}

void ManageUsersScreen::_ShowDeleteUserScreen()
{
    DeleteUserScreen::ShowDeleteUserScreen();
}

void ManageUsersScreen::_ShowUpdateUserScreen()
{
    UpdateUserScreen::ShowUpdateUserScreen();
}

void ManageUsersScreen::_ShowFindUserScreen()
{
    cout << "Find User Screen";
}
