
#include <iostream>

#include "DeleteClientScreen.h"
#include "Libraries/InputUtils.h"
#include "Client.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

using namespace std;

void DeleteClientScreen::ShowDeleteClientScreen()
{
    if (!Screen::CheckAccessRight(User::UserPermissions::DeleteClient))
    {
        Logger::Warning(LogMessages::accessDenied + " | Username: " + currentUser.Username + " | Operation: Delete Client");
        return;
    }

    Screen::ShowScreenHeader("Delete Client Screen");

    string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

    while (!Client::IsClientExists(accountNumber))
    {
        Logger::Warning(LogMessages::clientNotFound + " | Username: " + currentUser.Username + " | Account: " + accountNumber);
        cout << "\nClient \'" << accountNumber << "\' not found.\n";
        accountNumber = InputUtils::ReadString("Enter another account number: ");
    }

    Client client{ Client::Find(accountNumber) };

    UIUtils::PrintClientCard(client);

    char answer{ InputUtils::ReadChar("\nAre you sure you want to delete this client? (y/N): ") };

    if (tolower(answer) != 'y')
    {
        cout << "\nOperation cancelled.\n";
        Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Delete Client");
        return;
    }


    if (!client.DeleteClient())
    {
        cout << "\nFailed to delete client.\n";
        return;
    }

    cout << "\nClient deleted successfully.\n";
    UIUtils::PrintClientCard(client);
    Logger::Info(LogMessages::clientDeleted   + " | Username: " + currentUser.Username + " | Account: " + accountNumber);
}