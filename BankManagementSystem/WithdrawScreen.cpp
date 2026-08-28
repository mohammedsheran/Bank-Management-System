
#include <iostream>

#include "WithdrawScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void WithdrawScreen::ShowWithdrawScreen()
{
	Screen::ShowScreenHeader("Withdraw Screen");

	string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

	while (!Client::IsClientExists(accountNumber))
	{
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	Client client{ Client::Find(accountNumber) };

	UIUtils::PrintClientCard(client);

	double withdrawAmount{ InputUtils::ReadDouble("\nEnter a withdraw amount: ")};

	char answer{ InputUtils::ReadChar("\nAre you sure you want to perform this transaction? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Withdraw");
		return;
	}

	if (!client.Withdraw(withdrawAmount))
	{
		cout << "\nCan not withdraw, amount is invalid or insufficient balance!";
		cout << "\nAmount to withdraw is: " << withdrawAmount;
		cout << "\nYou balance is: " << client.AccountBalance;
		cout << '\n';

		return;
	}

	cout << "\nDone successfully, new balance is: " << client.AccountBalance << endl;
}
