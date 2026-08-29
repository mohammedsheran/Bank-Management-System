
#include "UpdateCurrencyRateScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"
#include "Libraries/Utils.h"



void UpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen()
{
	Screen::ShowScreenHeader("Update Currency Rate Screen");

	string code{ InputUtils::ReadString("Enter a currency code: ") };

	while (!Currency::IsCurrecnyExists(code))
	{
		cout << "\nCurrency Code \'" << code << "\' not found.\n";
		code = InputUtils::ReadString("Enter another currency code: ");
	}

	Currency currency{ Currency::FindByCode(code) };

	UIUtils::PrintCurrencyCard(currency);

	char answer{ InputUtils::ReadChar("\nAre you sure you want to update the rate of this currency? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		return;
	}

	cout << "\nUpdate currency rate: \n";
	cout << Utils::Divider(38);

	float rate{ InputUtils::ReadFloat("\nEnter a new rate: ") };

	currency.UpdateRate(rate);

	cout << "\nCurrency rate updated successfully.\n";

	UIUtils::PrintCurrencyCard(currency);
}
