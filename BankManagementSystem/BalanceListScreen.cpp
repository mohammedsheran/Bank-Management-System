
#include <string>
#include <iomanip>

#include "BalanceListScreen.h"
#include "Libraries/Utils.h"

void BalanceListScreen::_PrintClientBalanceRecord(const Client& client)
{
    cout << "| " << left << setw(15) << client.AccountNumber
        << "| " << setw(40) << client.GetFullName()
        << "| " << setw(15) << client.AccountBalance
        << '\n';
}

void BalanceListScreen::ShowBalanceListScreen()
{
    vector <Client> vClients{ Client::GetClientList() };

    if (vClients.empty())
    {
        cout << "\nNo clients available.\n";
        return;
    }

    Screen::ShowScreenHeader("Balance List Screen",
        to_string(vClients.size()) + " Client(s).");

    cout << "| " << left << setw(15) << "Account Number"
        << "| " << setw(40) << "Client Name"
        << "| " << setw(15) << "Account Balance\n";

    cout << Utils::Divider(110) << '\n';

    float totalBalance{};

    for (const auto& client : vClients)
    {
        _PrintClientBalanceRecord(client);
        totalBalance += client.AccountBalance;
    }

    cout << Utils::Divider(110) << endl;
    cout << Utils::Tab(5) << "Total Balance: " << totalBalance << '\n';
    cout << Utils::Tab(4) << '(' << Utils::NumberToString(totalBalance) << ")\n";
}
