
#include "LoginScreen.h"
#include "Libraries/InputUtils.h"
#include "User.h"
#include "Global.h"
#include "MainScreen.h"

bool LoginScreen::_Login()
{
	bool loginFailed{};
	short loginAttempts{};

	do
	{

		if (loginFailed)
		{
			loginAttempts++;

			cout << "\nInvalid username or password.";
			if (loginAttempts != 3)
			{
				cout << "\nYou have \'" << (3 - loginAttempts) << "\' attempts left.\n\n";
			}
			else
			{
				cout << "\nYou have exceeded the maximum number of login attempts.\n\n";
				return {};
			}
		}
		

		string username{ InputUtils::ReadString("Enter an username: ") };
		string password{ InputUtils::ReadString("Enter a password : ") };

		currentUser = User::Find(username, password);

		loginFailed = currentUser.IsEmpty();

	} while (loginFailed);

	MainScreen::ShowMainMenuScreen();
	return true;
}

bool LoginScreen::ShowLoginScreen()
{
	Screen::ClearScreen();
	Screen::ShowScreenHeader("Login Screen");

	return _Login();
}