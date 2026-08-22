
#include "MainScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

void MainScreen::ShowMainMenuScreen()
{
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
}

MainScreen::MainMenuOptions MainScreen::_ReadMainMenuOption()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-8]", 1, 8) };
    return static_cast<MainMenuOptions>(option);
}