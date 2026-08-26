#pragma once

#include "Screen.h"	
#include "User.h"

class UpdateUserScreen : public Screen
{
private:
	static void _UpdateUserRecord(User& user);
public:
	static void ShowUpdateUserScreen();
};