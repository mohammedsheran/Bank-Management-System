#pragma once

#include "Screen.h"
#include "User.h"

class UserListScreen : public Screen
{
private:
	static void _PrintUserRecord(const User& user);
public:
	static void ShowUserListScreen();
};