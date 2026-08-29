#pragma once

#include "Screen.h"

class CurrencyExchangeScreen : public Screen
{
private:
	enum class CurrencyExchangeMenuOptions
	{
		CurrencyList = 1,
		FindCurrency,
		UpdateRate,
		CurrencyCalculator,
		MainMenu
	};

	static CurrencyExchangeMenuOptions _ReadCurrencyExchangeMenuOption();

	static void _ReturnToCurrencyExchangeMenu();

	static void _HandleCurrencyExchangeMenuOption(CurrencyExchangeMenuOptions option);

	static void _ShowCurrencyListScreen();
	static void _ShowFindCurrencyScreen();
	static void _ShowUpdateRateScreen();
	static void _ShowCurrencyCalculatorScreen();

public:
	static void ShowCurrencyExchangeMenuScreen();
};
