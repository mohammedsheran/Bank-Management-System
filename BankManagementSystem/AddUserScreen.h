#pragma once

#include "Screen.h"
#include "User.h"

class AddUserScreen : public Screen
{
private:
	static short _ReadUserPermissions();
	static void _ReadUser(User& user);
public:
	static void ShowAddUserScreen();
};