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

	static void _ReturnToCurrencyMenu();

	static void _HandleCurrencyMenuOption(CurrencyMenuOptions option);

public:
	static void ShowCurrencyMenuScreen();
};
