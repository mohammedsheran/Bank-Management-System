
#include "FindCurrencyScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

Currency FindCurrencyScreen::_FindCurrency()
{
	short answer{ InputUtils::ReadShort("Find by [1]: Country, [2]: Code? ") };

	if (answer == 1)
	{
		string country{ InputUtils::ReadString("\nEnter a country: ") };

		return Currency::FindByCountry(country);

	}

	string code{ InputUtils::ReadString("\nEnter a code: ") };

	return Currency::FindByCode(code);
}

void FindCurrencyScreen::ShowFindCurrencyScreen()
{
	Screen::ShowScreenHeader("Find Currency Screen");

	Currency currency{ _FindCurrency() };

	if (currency.IsEmpty())
	{
		cout << "\nCurrency not found.\n";
		Logger::Warning(LogMessages::currencyNotFound + " | Username: " + currentUser.Username + " | Currency Code: " + currency.Code);
		return;
	}

	cout << "\nCurrency found.\n";

	UIUtils::PrintCurrencyCard(currency);
	Logger::Info(LogMessages::currencyFound + " | Currency Code: " + currency.Code);
}
