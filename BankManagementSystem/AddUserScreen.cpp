
#include "AddUserScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void AddUserScreen::_ReadUser(User& user)
{
	cout << "\nEnter client info.\n";

	user.FirstName = InputUtils::ReadString("\nEnter first name     : ");
	user.LastName = InputUtils::ReadString("Enter last name      : ");
	user.Email = InputUtils::ReadString("Enter email          : ");
	user.PhoneNumber = InputUtils::ReadString("Enter phone number   : ");
	user.Password = InputUtils::ReadString("Enter password       : ");

    user.Permissions = UIUtils::ReadUserPermissions();
}

void AddUserScreen::ShowAddUserScreen()
{
	Screen::ShowScreenHeader("Add User Screen");

	string username{ InputUtils::ReadString("Enter an username: ") };

	while (User::IsUserExists(username))
	{
		cout << "\nUser \'" << username << "\' already exists.\n";
		username = InputUtils::ReadString("Enter another username: ");
	}

	User user{ User::GetNewUserForAdd(username) };

	_ReadUser(user);

    User::OperationResult opResult{ user.Execute() };

    if (opResult == User::OperationResult::Failed)
    {
        cout << "\nFailed to add user.\n";
        return;
    }

    cout << "\nUser added successfully.\n";
    UIUtils::PrintUserCard(user);
}