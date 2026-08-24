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

	static void _ShowUserListScreen();

	static void _ShowAddUserScreen();

	static void _ShowDeleteUserScreen();

	static void _ShowUpdateUserScreen();

	static void _ShowFindUserScreen();

public:
	static void ShowManageUsersMenu();
};