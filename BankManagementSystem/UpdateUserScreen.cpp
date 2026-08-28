
#include "UpdateUserScreen.h"
#include "Libraries/InputUtils.h"
#include "UIUtils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void UpdateUserScreen::_UpdateUserRecord(User& user)
{
    string inputValue{};
    char answer{};

    cout << "\nEnter new values (leave empty to keep current).\n";

    inputValue = InputUtils::ReadString("\nEnter first name     : ");
    if (!inputValue.empty())
    {
        user.FirstName = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter last name      : ");
    if (!inputValue.empty())
    {
        user.LastName = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter email          : ");
    if (!inputValue.empty())
    {
        user.Email = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter phone number   : ");
    if (!inputValue.empty())
    {
        user.PhoneNumber = inputValue;
    }

    inputValue = InputUtils::ReadString("Enter password       : ");
    if (!inputValue.empty())
    {
        user.PhoneNumber = inputValue;
    }

    answer = InputUtils::ReadChar("Change permissions?   (y/N): ");
    if (tolower(answer) == 'y')
    {
        user.Permissions = UIUtils::ReadUserPermissions();
    }
}

void UpdateUserScreen::ShowUpdateUserScreen()
{
    Screen::ShowScreenHeader("Update User Screen");

    string username{ InputUtils::ReadString("Enter an username: ") };

    while (!User::IsUserExists(username))
    {
        Logger::Warning(LogMessages::userNotFound + " | Username: " + currentUser.Username + " | Target User: " + username);
        cout << "\nUser \'" << username << "\' not found.\n";
        username = InputUtils::ReadString("Enter another username: ");
    }

    User user{ User::Find(username) };

    UIUtils::PrintUserCard(user);

    char answer{ InputUtils::ReadChar("\nAre you sure you want to update this user? (y/N): ") };

    if (tolower(answer) != 'y')
    {
        cout << "\nOperation cancelled.\n";
        return;
    }

    _UpdateUserRecord(user);

    User::OperationResult opResult{ user.Execute() };

    if (opResult == User::OperationResult::Failed)
    {
        cout << "\nFailed to update user.\n";
        Logger::Warning(LogMessages::operationCancelled + " | Username: " + currentUser.Username + " | Operation: Update User");
        return;
    }

    cout << "\nUser updated successfully.\n";
    UIUtils::PrintUserCard(user);
    Logger::Info(LogMessages::userUpdated + " | Username: " + currentUser.Username + " | Target User: " + username);
}