#pragma once

#include "Screen.h"
#include "Client.h"

class TransferScreen : public Screen
{
private:
	static Client _ReadClient(const string& message);
	static void _PrintTransferClientCard(const Client& client);

public:
	static void ShowTransferScreen();
};