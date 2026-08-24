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

	static void _ReturnToManageUsersMenu();

	static void _HandleManageUsersMenuOption(ManageUserMenuOptions option);
public:
	static void ShowManageUsersMenu();
};