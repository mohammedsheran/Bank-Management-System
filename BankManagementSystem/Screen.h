#pragma once

#include <iostream>

#include "User.h"

class Screen
{
protected:
	static void ShowScreenHeader(const std::string& title, const std::string& subTitle = "");
	static void PauseScreen(const std::string& message);
	static void ClearScreen();

	static bool CheckAccessRight(const User::UserPermissions& userPermissions);
};

