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
		Transfer,
		MainMenu
	};

	static TransactionsMenuOptions _ReadTransactionsMenuOptions();

	static void _ReturnToTransactionsMenu();

	static void _ShowBalanceListScreen();

	static void _ShowDepositScreen();

	static void _ShowWithdrawScreen();
	static void _ShowTransferScreen();

	static void _HandleTransactionsMenuOption(TransactionsMenuOptions option);

public:
	static void ShowTransactionsMenuScreen();
};

