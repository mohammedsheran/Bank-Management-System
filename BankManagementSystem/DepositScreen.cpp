
#include <iostream>

#include "DepositScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"

using namespace std;

double DepositScreen::_ReadDepositAmount()
{
	double depositAmount{ InputUtils::ReadDouble("\nEnter a deposit amount: ") };

	while (depositAmount <= 0)
	{
		cout << "\nAmount must be greater than 0.\n";
		depositAmount = InputUtils::ReadDouble("Enter a valid amount: ");
	}

	return depositAmount;
}

void DepositScreen::ShowDepositScreen()
{
	Screen::ShowScreenHeader("Deposit Screen");

	string accountNumber{ InputUtils::ReadString("\nEnter an account number: ") };

	while (!Client::IsClientExists(accountNumber))
	{
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	Client client{ Client::Find(accountNumber) };

	UIUtils::_PrintClientCard(client);
	
	double depositAmount{ _ReadDepositAmount() };

	char answer{ InputUtils::ReadChar("\nAre you sure you want to perform this transaction? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		return;
	}

	client.Deposit(depositAmount);
	cout << "\nDone successfully, new balance is: " << client.AccountBalance << endl;
}
