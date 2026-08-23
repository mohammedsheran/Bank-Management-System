
#include "TransactionsScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

void TransactionsScreen::ShowTransactionsMenuScreen()
{
    Screen::ClearScreen();
	Screen::ShowScreenHeader("Transactions Screen");

    cout << Utils::Tab(4) << "[1] Balance List."
        << Utils::Tab(2) << "[3] Withdraw.\n";

    cout << Utils::Tab(4) << "[2] Deposit."
        << Utils::Tab(3) << "[4] Main Menu.\n\n";

    cout << Utils::Divider(110) << '\n';
}

TransactionsScreen::TransactionsMenuOptions TransactionsScreen::_ReadTransactionsMenuOptions()
{
    short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-8]: ", static_cast<short>(1), static_cast<short>(4)) };
    return static_cast<TransactionsMenuOptions>(option);
}