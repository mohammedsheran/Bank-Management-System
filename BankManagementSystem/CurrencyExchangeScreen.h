#pragma once

#include "Screen.h"

class CurrencyExchangeScreen : public Screen
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

	static CurrencyMenuOptions _ReadCurrencyExchangeMenuOption();

	static void _ReturnToCurrencyExchangeMenu();

	static void _HandleCurrencyExchangeMenuOption(CurrencyMenuOptions option);

	static void _ShowCurrencyListScreen();
	static void _ShowFindCurrencyScreen();
	static void _ShowUpdateRateScreen();
	static void _ShowCurrencyCalculatorScreen();

public:
	static void ShowCurrencyExchangeMenuScreen();
};
