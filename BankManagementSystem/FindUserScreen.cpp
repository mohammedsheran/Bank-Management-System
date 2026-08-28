
#include "FindUserScreen.h"
#include "Libraries/InputUtils.h"
#include "User.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void FindUserScreen::ShowFindUserScreen()
{
	Screen::ShowScreenHeader("Find Client Screeen");

	string username{ InputUtils::ReadString("\nEnter an username: ") };

	while (!User::IsUserExists(username))
	{
		Logger::Warning(LogMessages::userNotFound + " | Username: " + currentUser.Username + " | Target User: " + username);
		cout << "\nUser \'" << username << "\' not found.\n";
		username = InputUtils::ReadString("Enter another username: ");
	}

	User user{ User::Find(username) };

	cout << "\nUser was found.\n";
	UIUtils::PrintUserCard(user);
}