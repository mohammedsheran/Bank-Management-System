
#include <iostream>
#include "Client.h"
using namespace std;

int main()
{
    Client client{ Client::Find("A100")};

    client.PrintClientCard();

    cout << Client::IsClientExists("A1100");


    cout << endl;

    system("pause>nul");
}