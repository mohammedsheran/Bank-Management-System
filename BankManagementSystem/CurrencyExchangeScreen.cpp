
#include "CurrencyExchangeScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"
#include "CurrencyListScreen.h"

void CurrencyExchangeScreen::ShowCurrencyExchangeMenuScreen()
{
	Screen::ClearScreen();

	if (!Screen::CheckAccessRight(User::UserPermissions::Transactions))
	{
		//Logger::Warning(LogMessages::accessDenied + " | Username: " + currentUser.Username + " | Operation: Transactions");
		return;
	}

	Screen::ShowScreenHeader("Currency Exchange Screen");

	cout << Utils::Tab(4) << "[1] Currency List."
		<< Utils::Tab(2) << "[3] Update Rate.\n";

	cout << Utils::Tab(4) << "[2] Find Currency."
		<< Utils::Tab(2) << "[5] Main Menu.\n";

	cout << Utils::Tab(4) << "[4] Currency Calculator.\n\n";

	cout << Utils::Divider(110) << '\n';

	_HandleCurrencyExchangeMenuOption(_ReadCurrencyExchangeMenuOption());
}

CurrencyExchangeScreen::CurrencyExchangeMenuOptions CurrencyExchangeScreen::_ReadCurrencyExchangeMenuOption()
{
	short option{ InputUtils::ReadNumberInRange("Choose what do you want to do [1-5]: ", static_cast<short>(1), static_cast<short>(5)) };
	return static_cast<CurrencyExchangeMenuOptions>(option);
}

void CurrencyExchangeScreen::_ReturnToCurrencyExchangeMenu()
{
	Screen::PauseScreen("Press any key to return to currency exchange menu...");

	ShowCurrencyExchangeMenuScreen();
}

void CurrencyExchangeScreen::_HandleCurrencyExchangeMenuOption(CurrencyExchangeMenuOptions option)
{
	switch (option)
	{
	case CurrencyExchangeScreen::CurrencyExchangeMenuOptions::CurrencyList:
		Screen::ClearScreen();
		_ShowCurrencyListScreen();
		break;

	case CurrencyExchangeScreen::CurrencyExchangeMenuOptions::FindCurrency:
		Screen::ClearScreen();
		_ShowFindCurrencyScreen();
		break;
	
	case CurrencyExchangeScreen::CurrencyExchangeMenuOptions::UpdateRate:
		Screen::ClearScreen();
		_ShowUpdateRateScreen();
		break;

	case CurrencyExchangeScreen::CurrencyExchangeMenuOptions::CurrencyCalculator:
		Screen::ClearScreen();
		_ShowCurrencyCalculatorScreen();
		break;

	case CurrencyExchangeScreen::CurrencyExchangeMenuOptions::MainMenu:
		return;
	}

	_ReturnToCurrencyExchangeMenu();
}

void CurrencyExchangeScreen::_ShowCurrencyListScreen()
{
	CurrencyListScreen::ShowCurrencyListScreen();
}

void CurrencyExchangeScreen::_ShowFindCurrencyScreen()
{
	std::cout << "Find Currency Scrren";

}

void CurrencyExchangeScreen::_ShowUpdateRateScreen()
{
	std::cout << "Update Rate Scrren";
}

void CurrencyExchangeScreen::_ShowCurrencyCalculatorScreen()
{
	std::cout << "Currency Calculator Scrren";
}