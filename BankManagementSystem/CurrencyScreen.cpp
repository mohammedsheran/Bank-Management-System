
#include "CurrencyScreen.h"
#include "Libraries/Utils.h"

void CurrencyScreen::ShowCurrencyScreen()
{
	Screen::ClearScreen();
	Screen::ShowScreenHeader("Currency Screen");

	cout << Utils::Tab(4) << "[1] Currency List."
		<< Utils::Tab(2) << "[3] Update Rate.\n";

	cout << Utils::Tab(4) << "[2] Find Currency."
		<< Utils::Tab(3) << "[5] Main Menu.\n";

	cout << Utils::Tab(4) << "[4] Calculater.\n\n";

	cout << Utils::Divider(110) << '\n';

}
