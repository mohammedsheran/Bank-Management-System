
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
        client.AccountBalance = stod(inputValue);
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

int main()
{
    UpdateClient();

    cout << endl;

    system("pause>nul");
}