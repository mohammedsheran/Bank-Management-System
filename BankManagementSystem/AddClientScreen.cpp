
#include "AddClientScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"

void AddClientScreen::_ReadClient(Client& client)
{
    cout << "\nEnter client info.\n";

    client.FirstName = InputUtils::ReadString("\nEnter first name     : ");
    client.LastName = InputUtils::ReadString("Enter last name      : ");
    client.Email = InputUtils::ReadString("Enter email          : ");
    client.PhoneNumber = InputUtils::ReadString("Enter phone number   : ");
    client.PinCode = InputUtils::ReadString("Enter pin code       : ");
    client.AccountBalance = InputUtils::ReadFloat("Enter account balance: ");
}

void AddClientScreen::ShowAddClientScreen()
{
    Screen::ShowScreenHeader("Add Client Screen");

    string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

    while (Client::IsClientExists(accountNumber))
    {
        cout << "\nClient \'" << accountNumber << "\' already exists.\n";
        accountNumber = InputUtils::ReadString("Enter another account number: ");
    }

    Client client{ Client::GetNewClientForAdd(accountNumber) };

    _ReadClient(client);

    Client::OperationResult opResult{ client.Execute() };

    if (opResult == Client::OperationResult::Failed)
    {
        cout << "\nFailed to Add client.\n";
        return;
    }

    cout << "\nClient Added successfully.\n";
    UIUtils::_PrintClientCard(client);
}
