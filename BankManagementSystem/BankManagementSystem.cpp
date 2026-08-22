
#include <iostream>
#include <string>
#include <iomanip>
#include "Client.h"
#include "Libraries/InputUtils.h"
#include "Libraries/Utils.h"
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

bool DeleteClient()
{
    string accountNumber{ InputUtils::ReadString("Enter an account number: ") };

    while (!Client::IsClientExists(accountNumber))
    {
        cout << "\nClient \'" << accountNumber << "\' not found.\n";
        accountNumber = InputUtils::ReadString("Enter another account number: ");
    }

    Client client{ Client::Find(accountNumber) };

    client.PrintClientCard();

    char answer{ InputUtils::ReadChar("\nAre you sure you want to delete this client? (y/N): ") };

    if (tolower(answer) != 'y')
    {
        cout << "\nOperation cancelled.\n";
        return {};
    }


    if (!client.DeleteClient())
    {
        cout << "\nFailed to delete client.\n";
        return {};
    }

    cout << "\nClient deleted successfully.\n";
    return true;
}

void PrintClientRecord(const Client& client)
{
    cout << "| " << left << setw(15) << client.AccountNumber
        << "| " << setw(20) << client.GetFullName()
        << "| " << setw(12) << client.PhoneNumber
        << "| " << setw(20) << client.Email
        << "| " << setw(15) << client.PinCode
        << "| " << setw(15) << client.AccountBalance
        << '\n';
}

void ShowClientList()
{
    vector <Client> vClients{ Client::GetClientList() };

    if (vClients.empty())
    {
        cout << "\nNo clients available.\n";
        return;
    }

    cout << Utils::Tab(5) << "Client List (" << vClients.size() << ") Client(s)\n";
    cout << Utils::Divider(110) << '\n';

    cout << "| " << left << setw(15) << "Account Number"
        << "| " << setw(20) << "Client Name"
        << "| " << setw(12) << "Phone Number"
        << "| " << setw(20) << "Email"
        << "| " << setw(15) << "PIN Code"
        << "| " << setw(15) << "Account Balance\n";

    cout << Utils::Divider(110) << '\n';

    for (const auto& client : vClients)
    {
        PrintClientRecord(client);
    }

    cout << Utils::Divider(110) << endl;
}

void PrintClientBalanceRecord(const Client& client)
{
    cout << "| " << left << setw(15) << client.AccountNumber
        << "| " << setw(40) << client.GetFullName()
        << "| " << setw(15) << client.AccountBalance
        << '\n';
}

void ShowBalanceList()
{
    {
        vector <Client> vClients{ Client::GetClientList() };

        if (vClients.empty())
        {
            cout << "\nNo clients available.\n";
            return;
        }

        cout << Utils::Tab(5) << "Balance List (" << vClients.size() << ") Client(s)\n";
        cout << Utils::Divider(110) << '\n';

        cout << "| " << left << setw(15) << "Account Number"
            << "| " << setw(40) << "Client Name"
            << "| " << setw(15) << "Account Balance\n";

        cout << Utils::Divider(110) << '\n';

        float totalBalance{};

        for (const auto& client : vClients)
        {
            PrintClientBalanceRecord(client);
            totalBalance += client.AccountBalance;
        }

        cout << Utils::Divider(110) << endl;
        cout << Utils::Tab(5) << "Total Balance: " << totalBalance << '\n';
        cout << Utils::Tab(4) << '(' << Utils::NumberToString(totalBalance) << ")\n";
    }
}

int main()
{
    ShowBalanceList();

    cout << endl;

    system("pause>nul");
}