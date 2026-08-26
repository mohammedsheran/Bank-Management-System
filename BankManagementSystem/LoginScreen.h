#pragma once

#include "Screen.h"

class LoginScreen : public Screen
{
private:
	static bool _Login();
public:
	static bool ShowLoginScreen();
};