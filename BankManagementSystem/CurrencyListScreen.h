#pragma once

#include "Screen.h"
#include "Currency.h"

class CurrencyListScreen : public Screen
{
private:
	static void _PrintCurrencyRecord(const Currency& currency);

public:
	static void ShowCurrencyListScreen();
};