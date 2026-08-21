
#include <iostream>
#include "Client.h"
using namespace std;

int main()
{
    Client* client{ Client::Find("Clients.txt", "A100")};

    if (client)
    {
        client->PrintClientCard();
        delete client;
    }

    cout << endl;

    system("pause>nul");
}