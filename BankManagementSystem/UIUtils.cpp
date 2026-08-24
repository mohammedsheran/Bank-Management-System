
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