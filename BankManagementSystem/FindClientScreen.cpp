
#include <iostream>

#include "FindClientScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"

void FindClientScreen::ShowFindClientScreen()
{
	Screen::ShowScreenHeader("Find Client Screeen");

	string accountNumber{ InputUtils::ReadString("\nEnter an account number: ") };

	while (!Client::IsClientExists(accountNumber))
	{
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	Client client{ Client::Find(accountNumber) };

	cout << "\nClient was found.\n";
	UIUtils::PrintClientCard(client);
}
