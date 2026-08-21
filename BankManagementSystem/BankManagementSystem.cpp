
#include <iostream>
#include "Client.h"
using namespace std;

int main()
{
    Client client{ Client::Find("Clients.txt", "A100")};

    client.PrintClientCard();

    cout << Client::IsClientExists("Clients.txt", "A1100");


    cout << endl;

    system("pause>nul");
}