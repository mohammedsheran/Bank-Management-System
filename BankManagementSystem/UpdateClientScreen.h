#pragma once

#include "Screen.h"
#include "Client.h"

class UpdateClientScreen : public Screen
{
private:
    static void _UpdateClientRecord(Client& client);
    
public:
    static void ShowUpdateClientScreen();
};