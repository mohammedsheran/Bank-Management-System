
#include "ManageUsersScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

void ManageUsersScreen::ShowManageUsersMenu()
{
	Screen::ShowScreenHeader("Manage Users Screen");

    cout << Utils::Tab(4) << "[1] Show User List."
        << Utils::Tab(2) << "[4] Update User.\n";

    cout << Utils::Tab(4) << "[2] Add New User."
        << Utils::Tab(2) << "[5] Find User.\n";

    cout << Utils::Tab(4) << "[3] Delete User."
        << Utils::Tab(2) << "[6] Main Menu.\n\n";

    cout << Utils::Divider(110) << '\n';
}

ManageUsersScreen::ManageUserMenuOptions ManageUsersScreen::_ReadManageUsersMenuOption()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-6]: ", static_cast<short>(1), static_cast<short>(6)) };
    return static_cast<ManageUserMenuOptions>(option);
}
