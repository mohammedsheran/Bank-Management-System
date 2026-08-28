
#include <iostream>

#include "FindClientScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void FindClientScreen::ShowFindClientScreen()
{
	if (!Screen::CheckAccessRight(User::UserPermissions::FindClient))
	{
		Logger::Warning(LogMessages::accessDenied + " | Username: " + currentUser.Username + " | Operation: Find Client");
		return;
	}

	Screen::ShowScreenHeader("Find Client Screeen");

	string accountNumber{ InputUtils::ReadString("\nEnter an account number: ") };

	while (!Client::IsClientExists(accountNumber))
	{
		Logger::Warning(LogMessages::clientNotFound + " | Username: " + currentUser.Username + " | Account: " + accountNumber);
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	Client client{ Client::Find(accountNumber) };

	cout << "\nClient was found.\n";
	UIUtils::PrintClientCard(client);
}
