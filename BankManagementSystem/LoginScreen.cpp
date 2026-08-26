
#include "LoginScreen.h"
#include "Libraries/InputUtils.h"
#include "User.h"
#include "Global.h"
#include "MainScreen.h"

void LoginScreen::_Login()
{
	char loginFailed{};

	do
	{
		if (loginFailed)
		{
			cout << "\nInvalid username or password.\n";
		}

		string username{ InputUtils::ReadString("Enter an username: ") };
		string password{ InputUtils::ReadString("Enter a password: ") };

		currentUser = User::Find(username, password);

		loginFailed = currentUser.IsEmpty();

	} while (loginFailed);

	MainScreen::ShowMainMenuScreen();
}

void LoginScreen::ShowLoginScreen()
{
	Screen::ClearScreen();
	Screen::ShowScreenHeader("Login Screen");

	_Login();
}