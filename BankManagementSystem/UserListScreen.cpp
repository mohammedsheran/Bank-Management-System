
#include <vector>
#include <string>
#include <iomanip>

#include "UserListScreen.h"
#include "Libraries/Utils.h"

void UserListScreen::_PrintUserRecord(const User& user)
{
    cout << "| " << left << setw(12) << user.Username
        << "| " << setw(25) << user.GetFullName()
        << "| " << setw(12) << user.PhoneNumber
        << "| " << setw(20) << user.Email
        << "| " << setw(10) << user.Password
        << "| " << setw(12) << user.Permissions
        << '\n';
}

void UserListScreen::ShowUserListScreen()
{
    vector <User> vUsers{ User::GetUserList() };

    Screen::ShowScreenHeader("User List Screen",
        to_string(vUsers.size()) + " User(s).");

    if (vUsers.empty())
    {
        cout << "\nNo Users available.\n";
        return;
    }

    cout << "| " << left << setw(12) << "Username"
        << "| " << setw(25) << "Full Name"
        << "| " << setw(12) << "Phone Number"
        << "| " << setw(20) << "Email"
        << "| " << setw(10) << "Password"
        << "| " << setw(12) << "Permissions"
        << '\n';

    cout << Utils::Divider(110) << endl;

    for (const auto& user : vUsers)
    {
        _PrintUserRecord(user);
    }

    cout << Utils::Divider(110) << endl;
}