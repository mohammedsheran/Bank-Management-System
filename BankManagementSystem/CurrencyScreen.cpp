
#include "CurrencyScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

void CurrencyScreen::ShowCurrencyMenuScreen()
{
	Screen::ClearScreen();
	Screen::ShowScreenHeader("Currency Screen");

	cout << Utils::Tab(4) << "[1] Currency List."
		<< Utils::Tab(2) << "[3] Update Rate.\n";

	cout << Utils::Tab(4) << "[2] Find Currency."
		<< Utils::Tab(3) << "[5] Main Menu.\n";

	cout << Utils::Tab(4) << "[4] Currency Calculator.\n\n";

	cout << Utils::Divider(110) << '\n';
}

CurrencyScreen::CurrencyMenuOptions CurrencyScreen::_ReadCurrencyMenuOption()
{
	short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-5]: ", static_cast<short>(1), static_cast<short>(5)) };
	return static_cast<CurrencyMenuOptions>(option);
}

void CurrencyScreen::_ReturnToCurrencyMenu()
{
	Screen::PauseScreen("Press any key to return to Currency menu...");

	ShowCurrencyMenuScreen();
}


void CurrencyScreen::_HandleCurrencyMenuOption(CurrencyMenuOptions option)
{
	switch (option)
	{
	case CurrencyScreen::CurrencyMenuOptions::CurrencyList:
		Screen::ClearScreen();
		break;

	case CurrencyScreen::CurrencyMenuOptions::FindCurrency:
		Screen::ClearScreen();

		break;
	
	case CurrencyScreen::CurrencyMenuOptions::UpdateRate:
		Screen::ClearScreen();

		break;

	case CurrencyScreen::CurrencyMenuOptions::CurrencyCalculator:
		Screen::ClearScreen();

		break;

	case CurrencyScreen::CurrencyMenuOptions::MainMenu:
		return;
	}

	_ReturnToCurrencyMenu();
}

