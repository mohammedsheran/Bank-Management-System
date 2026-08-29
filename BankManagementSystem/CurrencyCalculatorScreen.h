#pragma once

#include "Screen.h"
#include "Currency.h"

class CurrencyCalculatorScreen : public Screen
{
private:
	static Currency _GetCurrency(const string& message);

	static void _PrintCalculationResult(const float& amount, const Currency& currencyFrom, const Currency& currencyTo);
public:
	static void ShowCurrencyCalculatorScreen();
};