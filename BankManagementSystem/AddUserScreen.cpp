
#include "AddUserScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"

short AddUserScreen::_ReadUserPermissions()
{
	short permissions{};
	char answer{};

	cout << "\nGiving Permissions:\n";

    answer = InputUtils::ReadChar("Give full access?            (y/N): ");
    if (tolower(answer) == 'y')
    {
        return static_cast<short>(User::UserPermissions::FullAccess);
    }

    answer = InputUtils::ReadChar("Give client list access?     (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::ClientList);
    }

    answer = InputUtils::ReadChar("Give add client access?      (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::AddClient);
    }

    answer = InputUtils::ReadChar("Give delete client access?   (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::DeleteClient);
    }

    answer = InputUtils::ReadChar("Give update client access?   (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::UpdateClient);
    }

    answer = InputUtils::ReadChar("Give find client access?     (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::FindClient);
    }

    answer = InputUtils::ReadChar("Give transactions access?    (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::Transactions);
    }

    answer = InputUtils::ReadChar("Give manage users access?    (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::ManageUsers);
    }

    return permissions;
}

void AddUserScreen::_ReadUser(User& user)
{
	cout << "\nEnter client info.\n";

	user.FirstName = InputUtils::ReadString("\nEnter first name     : ");
	user.LastName = InputUtils::ReadString("Enter last name      : ");
	user.Email = InputUtils::ReadString("Enter email          : ");
	user.PhoneNumber = InputUtils::ReadString("Enter phone number   : ");
	user.Password = InputUtils::ReadString("Enter password        : ");

    user.Permissions = _ReadUserPermissions();
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