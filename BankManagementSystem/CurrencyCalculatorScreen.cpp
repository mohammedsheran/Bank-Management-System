
#include "CurrencyCalculatorScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"

Currency CurrencyCalculatorScreen::_GetCurrency(const string& message)
{
	string code{ InputUtils::ReadString(message) };

	while (!Currency::IsCurrecnyExists(code))
	{
		cout << "\nCurrency Code \'" << code << "\' not found.\n";
		code = InputUtils::ReadString("Enter another currency code: ");
	}

	return Currency::FindByCode(code);
}

void CurrencyCalculatorScreen::_PrintCalculationResult(const float& amount, const Currency& currencyFrom, const Currency& currencyTo)
{
	float amountInUSD{ currencyFrom.ConvertToUSD(amount) };

	cout << "\nConvert from:\n";
	UIUtils::PrintCurrencyCard(currencyFrom);

	cout << amount << ' ' << currencyFrom.Code
		<< " : " << amountInUSD << " USD\n";

	if (currencyTo.Code == "USD")
	{
		return;
	}

	float amountInOtherCurrency{ currencyFrom.ConvertToOtherCurrency(amount, currencyTo) };

	cout << "\nConverting from USD to:\n";
	UIUtils::PrintCurrencyCard(currencyTo);

	cout << amount << ' ' << currencyFrom.Code
		<< " : " << amountInOtherCurrency << ' ' << currencyTo.Code << '\n';
}

void CurrencyCalculatorScreen::ShowCurrencyCalculatorScreen()
{
	char answer{ 'y' };

	while (tolower(answer) == 'y')
	{
		Screen::ClearScreen();
		Screen::ShowScreenHeader("Currency Calculator Screen");

		Currency currencyFrom{ _GetCurrency("Enter a Currency Code (1): ") };
		Currency currencyTo{ _GetCurrency("Enter a Currency Code (2): ") };

		float amount{ InputUtils::ReadFloat("\nEnter An amount: ") };

		_PrintCalculationResult(amount, currencyFrom, currencyTo);

		answer = InputUtils::ReadChar("\nDo you want to perform another calculation? (y/N): ");
	}
}