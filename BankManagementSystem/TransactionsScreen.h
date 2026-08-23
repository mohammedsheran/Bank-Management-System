#pragma once

#include "Screen.h"

class TransactionsScreen : public Screen
{
private:
	enum class TransactionsMenuOptions
	{
		BalanceList = 1,
		Deposit,
		Withdraw,
		MainMenu
	};

	static TransactionsMenuOptions _ReadTransactionsMenuOptions();
public:
	static void ShowTransactionsMenuScreen();
};

