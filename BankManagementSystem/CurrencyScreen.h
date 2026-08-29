#pragma once

#include "Screen.h"

class CurrencyScreen : public Screen
{
private:
	enum class CurrencyMenuOptions
	{
		CurrencyList = 1,
		FindCurrency,
		UpdateRate,
		CurrencyCalculator,
		MainMenu
	};

	CurrencyMenuOptions _ReadCurrencyMenuOption();

public:
	static void ShowCurrencyMenuScreen();
};
