
#include "UpdateCurrencyRateScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"
#include "Libraries/Utils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"


void UpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen()
{
	Screen::ShowScreenHeader("Update Currency Rate Screen");

	string code{ InputUtils::ReadString("Enter a currency code: ") };

	while (!Currency::IsCurrecnyExists(code))
	{
		Logger::Warning(LogMessages::currencyNotFound + " | Username: " + currentUser.Username + " | Currency Code: " + code);
		cout << "\nCurrency Code \'" << code << "\' not found.\n";
		code = InputUtils::ReadString("Enter another currency code: ");
	}

	Currency currency{ Currency::FindByCode(code) };

	UIUtils::PrintCurrencyCard(currency);

	char answer{ InputUtils::ReadChar("\nAre you sure you want to update the rate of this currency? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Update Currency Rate");
		return;
	}

	cout << "\nUpdate currency rate: \n";
	cout << Utils::Divider(38);

	float oldRate{ currency.Rate };
	float newRate{ InputUtils::ReadFloat("\nEnter a new rate: ") };

	currency.UpdateRate(newRate);

	cout << "\nCurrency rate updated successfully.\n";

	UIUtils::PrintCurrencyCard(currency);

	Logger::Info(LogMessages::currencyRateUpdated 
		+ " | Username: " + currentUser.Username 
		+ " | Currency Code: " + currency.Code
		+ " | Old Rate: " + to_string(oldRate)
		+ " | New Rate: " + to_string(currency.Rate));
}
