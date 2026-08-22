#pragma once

#include <iostream>

#include "Screen.h"
#include "Client.h"

class ClientListScreen : public Screen
{
private:
	static void _PrintClientRecord(const Client& client);

public:
	static void ShowClientList();
};

