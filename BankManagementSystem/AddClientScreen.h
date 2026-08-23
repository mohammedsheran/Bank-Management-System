#pragma once

#include "Screen.h"
#include "Client.h"

class AddClientScreen : public Screen
{
private:
	static void _ReadClient(Client& client);

public:
	static void ShowAddClientScreen();
};