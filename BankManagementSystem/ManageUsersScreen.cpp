
#include "ManageUsersScreen.h"
#include "Libraries/Utils.h"

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
