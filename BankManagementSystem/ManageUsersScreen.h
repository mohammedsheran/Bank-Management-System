#pragma once

#include "Screen.h"

class ManageUsersScreen : public Screen
{
private:
	enum class ManageUserMenuOptions
	{
		UserList = 1,
		AddUser,
		DeleteUser,
		UpdateUser,
		FindUser,
		MainMenu
	};

	static ManageUserMenuOptions _ReadManageUsersMenuOption();
public:
	static void ShowManageUsersMenu();
};