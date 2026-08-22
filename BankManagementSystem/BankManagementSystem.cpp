
#include <iostream>
#include <string>
#include "Client.h"
#include "Libraries/InputUtils.h"
using namespace std;

void UpdateClientRecord(Client& client)
{
    string inputValue{};

    cout << "\nEnter new values (leave empty to keep current).\n";

    inputValue = InputUtils::ReadString("\nEnter first name     : ");
    if (!inputValue.empty())
    {
        client.FirstName = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter last name      : ");
    if (!inputValue.empty())
    {
        client.LastName = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter email          : ");
    if (!inputValue.empty())
    {
        client.Email = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter phone number   : ");
    if (!inputValue.empty())
    {
        client.PhoneNumber = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter pin code       : ");
    if (!inputValue.empty())
    {
        client.PinCode = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter account balance: ");
    if (!inputValue.empty())
    {
        client.AccountBalance = stof(inputValue);
    }
}

bool UpdateClient()
{
    string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

    while (!Client::IsClientExists(accountNumber))
    {
        cout << "\nClient \'" << accountNumber << "\' not found.\n";
        accountNumber = InputUtils::ReadString("Enter another account number: ");
    }

    Client client{ Client::Find(accountNumber) };

    client.PrintClientCard();

    UpdateClientRecord(client);

    Client::OperationResult opResult{ client.Execute() };

    if (opResult == Client::OperationResult::Failed)
    {
        cout << "\nFailed to update client.\n";
        return {};
    }

    cout << "\nClient updated successfully.\n";
    return true;
}

void ReadNewClient(Client& client)
{
    cout << "\nEnter client info.\n";

    client.FirstName = InputUtils::ReadString("\nEnter first name     : ");
    client.LastName = InputUtils::ReadString("Enter last name      : ");
    client.Email = InputUtils::ReadString("Enter email          : ");
    client.PhoneNumber = InputUtils::ReadString("Enter phone number   : ");
    client.PinCode = InputUtils::ReadString("Enter pin code       : ");
    client.AccountBalance = InputUtils::ReadFloat("Enter account balamce: ");
}

bool AddClient()
{
    string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

    while (Client::IsClientExists(accountNumber))
    {
        cout << "\nClient \'" << accountNumber << "\' already exists.\n";
        accountNumber = InputUtils::ReadString("Enter another account number: ");
    }

    Client client{ Client::GetNewClientForAdd(accountNumber) };

    ReadNewClient(client);

    Client::OperationResult opResult{ client.Execute() };

    if (opResult == Client::OperationResult::Failed)
    {
        cout << "\nFailed to Add client.\n";
        return {};
    }

    cout << "\nClient Added successfully.\n";
    return true;
}

int main()
{
    AddClient();

    cout << endl;

    system("pause>nul");
}