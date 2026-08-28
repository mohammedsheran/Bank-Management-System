
#include <iostream>

#include "DepositScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

using namespace std;

void DepositScreen::ShowDepositScreen()
{
	Screen::ShowScreenHeader("Deposit Screen");

	string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

	while (!Client::IsClientExists(accountNumber))
	{
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	Client client{ Client::Find(accountNumber) };

	UIUtils::PrintClientCard(client);
	
	double depositAmount{ InputUtils::ReadDouble("\nEnter a deposit amount: ")};

	char answer{ InputUtils::ReadChar("\nAre you sure you want to perform this transaction? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Deposit");
		return;
	}

	if (!client.Deposit(depositAmount))
	{
		cout << "\nCan not deposit, amount must be greater than zero!\n";
		return;
	}

	cout << "\nDone successfully, new balance is: " << client.AccountBalance << endl;
	Logger::Info(LogMessages::depositCompleted
		+ " | Username: " + currentUser.Username
		+ " | Account: " + accountNumber
		+ " | Amount: " + to_string(depositAmount)
		+ " | New Balance: " + to_string(client.AccountBalance));
}
