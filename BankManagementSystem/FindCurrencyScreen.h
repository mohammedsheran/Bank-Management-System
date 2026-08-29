#pragma once

#include "Screen.h"
#include "Currency.h"

class FindCurrencyScreen : public Screen
{
private:
	static Currency _FindCurrency();
public:
	static void ShowFindCurrencyScreen();
};