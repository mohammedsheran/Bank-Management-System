
#include "TransferScreen.h"
#include "Libraries/InputUtils.h"
#include "Libraries/Utils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

Client TransferScreen::_ReadClient(const string& message)
{
	string accountNumber{ InputUtils::ReadString(message) };

	while (!Client::IsClientExists(accountNumber))
	{
		cout << "\nClient \'" << accountNumber << "\' not found.\n";
		accountNumber = InputUtils::ReadString("Enter another account number: ");
	}

	return Client::Find(accountNumber);
}

void TransferScreen::_PrintTransferClientCard(const Client& client)
{
	cout << "\nThe following are Client Record : \n";
	cout << Utils::Divider(38);
	cout << "\nFull Name      : " << client.GetFullName();
	cout << "\nAccount Number : " << client.AccountNumber;
	cout << "\nAccount Balance: " << client.AccountBalance << '\n';
	cout << Utils::Divider(38) << '\n';
}

void TransferScreen::ShowTransferScreen()
{
	Screen::ShowScreenHeader("Transfer Screen");

	Client sourceClient{ _ReadClient("Enter an account number to transfer from: ") };
	
	_PrintTransferClientCard(sourceClient);

	Client destinationClient{ _ReadClient("\nEnter an account number to transfer to: ") };

	if (sourceClient.AccountNumber == destinationClient.AccountNumber)
	{
		cout << "\nSource and destination accounts cannot be the same.\n";
		return;
	}

	_PrintTransferClientCard(destinationClient);

	double transferAmount{ InputUtils::ReadDouble("\nEnter a transfer amount: ") };

	char answer{ InputUtils::ReadChar("\nAre you sure you want to perform this transaction? (y/N): ") };

	if (tolower(answer) != 'y')
	{
		cout << "\nOperation cancelled.\n";
		Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Transfer");
		return;
	}

	if (!sourceClient.Transfer(transferAmount, destinationClient))
	{
		cout << "\nTransfer failed: Invalid amount or insufficient balance!";
		cout << "\nTransfer Amount: " << transferAmount;
		cout << "\nAvailable Balance: " << sourceClient.AccountBalance;
		cout << '\n';
		return;
	}

	cout << "\nTransfer completed successfully..\n";
	_PrintTransferClientCard(sourceClient);
	_PrintTransferClientCard(destinationClient);
}