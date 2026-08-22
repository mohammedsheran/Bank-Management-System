
#include "ClientListScreen.h"

#include <string>
#include <iomanip>

#include "Libraries/Utils.h"

void ClientListScreen::_PrintClientRecord(const Client& client)
{
    cout << "| " << left << setw(15) << client.AccountNumber
        << "| " << setw(20) << client.GetFullName()
        << "| " << setw(12) << client.PhoneNumber
        << "| " << setw(20) << client.Email
        << "| " << setw(15) << client.PinCode
        << "| " << setw(15) << client.AccountBalance
        << '\n';
}

void ClientListScreen::ShowClientList()
{
    vector <Client> vClients{ Client::GetClientList() };

    if (vClients.empty())
    {
        cout << "\nNo clients available.\n";
        return;
    }

    Screen::ShowScreenHeader("Client List Screen",
        to_string(vClients.size()) + " Client(s).");

    cout << "| " << left << setw(15) << "Account Number"
        << "| " << setw(20) << "Client Name"
        << "| " << setw(12) << "Phone Number"
        << "| " << setw(20) << "Email"
        << "| " << setw(15) << "PIN Code"
        << "| " << setw(15) << "Account Balance\n";

    cout << Utils::Divider(110) << '\n';

    for (const auto& client : vClients)
    {
        _PrintClientRecord(client);
    }

    cout << Utils::Divider(110) << endl;
}