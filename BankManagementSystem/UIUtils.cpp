
#include "UIUtils.h"
#include "Libraries/Utils.h"
#include "Libraries/InputUtils.h"

void UIUtils::PrintClientCard(const Client& client)
{
    cout << "\nThe following are Client Record : \n";
    cout << Utils::Divider(38);
    cout << "\nFirst Name     : " << client.FirstName;
    cout << "\nLast Name      : " << client.LastName;
    cout << "\nFull Name      : " << client.GetFullName();
    cout << "\nEmail	       : " << client.Email;
    cout << "\nPhone Number   : " << client.PhoneNumber;
    cout << "\nAccount Number : " << client.AccountNumber;
    cout << "\nPIN Code       : " << client.PinCode;
    cout << "\nAccount Balance: " << client.AccountBalance << '\n';
    cout << Utils::Divider(38) << '\n';
}

void UIUtils::PrintUserCard(const User& user)
{
    cout << "\nThe following are User Record : \n";
    cout << Utils::Divider(38);
    cout << "\nFirst Name  : " << user.FirstName;
    cout << "\nLast Name   : " << user.LastName;
    cout << "\nFull Name   : " << user.GetFullName();
    cout << "\nEmail	    : " << user.Email;
    cout << "\nPhone Number: " << user.PhoneNumber;
    cout << "\nUsername    : " << user.Username;
    cout << "\nPassword    : " << user.Password;
    cout << "\nPermissions : " << user.Permissions << '\n';
    cout << Utils::Divider(38) << '\n';
}

short UIUtils::ReadUserPermissions()
{
    short permissions{};
    char answer{};

    cout << "\nGiving Permissions:\n";

    answer = InputUtils::ReadChar("Give full access?                 (y/N): ");
    if (tolower(answer) == 'y')
    {
        return static_cast<short>(User::UserPermissions::FullAccess);
    }

    answer = InputUtils::ReadChar("Give client list access?          (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::ClientList);
    }

    answer = InputUtils::ReadChar("Give add client access?           (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::AddClient);
    }

    answer = InputUtils::ReadChar("Give delete client access?        (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::DeleteClient);
    }

    answer = InputUtils::ReadChar("Give update client access?        (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::UpdateClient);
    }

    answer = InputUtils::ReadChar("Give find client access?          (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::FindClient);
    }

    answer = InputUtils::ReadChar("Give transactions access?         (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::Transactions);
    }
    answer = InputUtils::ReadChar("Give manage users access?         (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::ManageUsers);
    }
    answer = InputUtils::ReadChar("Give currency exchange access?    (y/N): ");
    if (tolower(answer) == 'y')
    {
        User::AddPermission(permissions, User::UserPermissions::CurrencyExchange);
    }

    return permissions;
}