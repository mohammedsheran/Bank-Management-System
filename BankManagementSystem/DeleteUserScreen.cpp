
#include "DeleteUserScreen.h"
#include "Libraries/InputUtils.h"
#include "Libraries/StringUtils.h"
#include "User.h"
#include "UIUtils.h"

void DeleteUserScreen::ShowDeleteUserScreen()
{
    Screen::ShowScreenHeader("Delete User Screen");

    string username{ InputUtils::ReadString("Enter an username: ") };

    if (StringUtils::ToLower(username) == "admin")
    {
        cout << "\nYou can not delete this user.\n";
        return;
    }

    while (!User::IsUserExists(username))
    {
        cout << "\nUser \'" << username << "\' not found.\n";
        username = InputUtils::ReadString("Enter another username: ");
    }

    User user{ User::Find(username) };

    UIUtils::PrintUserCard(user);

    char answer{ InputUtils::ReadChar("\nAre you sure you want to delete this user? (y/N): ") };

    if (tolower(answer) != 'y')
    {
        cout << "\nOperation cancelled.\n";
        return;
    }


    if (!user.DeleteUser())
    {
        cout << "\nFailed to delete user.\n";
        return;
    }

    cout << "\nUser deleted successfully.\n";
    UIUtils::PrintUserCard(user);
}