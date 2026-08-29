#pragma once

#include "Client.h"
#include "User.h"
#include "Currency.h"

class UIUtils
{
public:
	static void PrintClientCard(const Client& client);

	static void PrintUserCard(const User& user);

	static short ReadUserPermissions();

	static void PrintCurrencyCard(const Currency& currency);
};

