#pragma once

#include "Screen.h"
#include "Client.h"

class BalanceListScreen : public Screen
{
private:
    static void _PrintClientBalanceRecord(const Client& client);

public:
	static void ShowBalanceListScreen();
};