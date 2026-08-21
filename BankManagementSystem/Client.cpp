
#include "Client.h"
#include "Libraries/StringUtils.h"
#include "Libraries/Utils.h"

#include <string>

float Client::_ValidateBalance(const float& balance)
{
	if (balance >= 0)
	{
		return balance;
	}

	throw invalid_argument("Field can not be less than zero.");
}

Client::Client(const Mode& mode, const string& firstName, const string& lastName, const string& email
	, const string& phoneNumber, const string& accountNumber, const string& pinCode, const float& accountBalance)
	: Person(firstName, lastName, email, phoneNumber), _mode(mode), _accountNumber(Person::RequireField(accountNumber)), _pinCode(Person::RequireField(pinCode)), _accountBalance(_ValidateBalance(accountBalance))
{

}

string Client::GetAccountNumber() const
{
	return _accountNumber;
}

void Client::SetPinCode(const string& pinCode)
{
	_pinCode = RequireField(pinCode);
}

string Client::GetPinCode() const
{
	return _pinCode;
}

void Client::SetAccountBalance(const float& accountBalance)
{
	_accountBalance = _ValidateBalance(accountBalance);
}

float Client::GetAccountBalance() const
{
	return _accountBalance;
}

bool Client::IsEmpty() const
{
	return (_mode == Mode::Empty);
}

void Client::PrintClientCard() const
{
	cout << "\nThe following are Client Record : \n";
	cout << Utils::Divider(38);
	cout << "\nFirst Name	   : " << FirstName;
	cout << "\nLast Name	   : " << LastName;
	cout << "\nFull Name	   : " << GetFullName();
	cout << "\nEmail	       : " << Email;
	cout << "\nPhone Number	   : " << PhoneNumber;
	cout << "\nAccount Number  : " << _accountNumber;
	cout << "\nPIN Code        : " << _pinCode;
	cout << "\nAccount Balance : " << _accountBalance << '\n';
	cout << Utils::Divider(38) << '\n';
}