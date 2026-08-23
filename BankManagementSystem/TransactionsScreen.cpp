
#include "TransactionsScreen.h"
#include "Libraries/Utils.h"

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
