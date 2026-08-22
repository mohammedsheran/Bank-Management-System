
#include "AddClientScreen.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

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

void AddClientScreen::_PrintClientCard(const Client& client)
{
    cout << "\nThe following are Client Record : \n";
    cout << Utils::Divider(38);
    cout << "\nFirst Name     : " << client.FirstName;
    cout << "\nLast Name      : " << client.LastName;
    cout << "\nFull Name      : " << client.GetFullName();
    cout << "\nEmail	       : " << client.Email;
    cout << "\nPhone Number   : " << client.PhoneNumber;
    cout << "\nAccount Number : " << client.AccountNumber;
    cout << "\nPIN Code       : " << client.PinCode;
    cout << "\nAccount Balance: " << client.AccountBalance << '\n';
    cout << Utils::Divider(38) << '\n';
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
    _PrintClientCard(client);
}

