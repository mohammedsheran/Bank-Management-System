
#include "Client.h"
#include "Libraries/StringUtils.h"
#include "Libraries/Utils.h"

#include <string>
#include <fstream>

float Client::_ValidateBalance(const float& balance)
{
	if (balance >= 0)
	{
		return balance;
	}

	throw invalid_argument("Field can not be less than zero.");
}

Client::Client(const Mode& mode) : Person(), _mode(mode) {}
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
	cout << "\nFirst Name     : " << FirstName;
	cout << "\nLast Name      : " << LastName;
	cout << "\nFull Name      : " << GetFullName();
	cout << "\nEmail	       : " << Email;
	cout << "\nPhone Number   : " << PhoneNumber;
	cout << "\nAccount Number : " << _accountNumber;
	cout << "\nPIN Code       : " << _pinCode;
	cout << "\nAccount Balance: " << _accountBalance << '\n';
	cout << Utils::Divider(38) << '\n';
}

Client Client::_ConvertLineToClientObject(const string& line, const string& delimiter)
{
	vector <string> vString{ StringUtils::Split(line, delimiter) };

	if (vString.size() != 7)
		return Client(Mode::Empty);

	return Client(Mode::Update, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stod(vString[6]));
}
string Client::_ConvertClientObjectToLine(const Client& client, const string& separator)
{
	if (client._mode == Mode::Empty)
		return {};

	string line{};

	line += client.FirstName + separator;
	line += client.LastName + separator;
	line += client.Email + separator;
	line += client.PhoneNumber + separator;
	line += client._accountNumber + separator;
	line += client._pinCode + separator;
	line += to_string(client._accountBalance);

	return line;
}

Client Client::Find(const string& fileName, const string& accountNumber)
{
	ifstream file{ fileName };

	if (!file)
	{
		cout << "Failed to open file: " << fileName << '\n';
		return Client(Mode::Empty);
	}

	string line{};

	while (getline(file, line))
	{
		Client client{ _ConvertLineToClientObject(line) };

		if (client.AccountNumber == accountNumber)
		{
			file.close();
			return client;
		}
	}

	file.close();

	return Client(Mode::Empty);
}
Client Client::Find(const string& fileName, const string& accountNumber, const string& pinCode)
{
	ifstream file{ fileName };

	if (!file)
	{
		cout << "Failed to open file: " << fileName << '\n';
		return Client(Mode::Empty);
	}

	string line{};

	while (getline(file, line))
	{
		Client client{ _ConvertLineToClientObject(line) };

		if (client.AccountNumber == accountNumber && client.PinCode == pinCode)
		{
			file.close();
			return client;
		}
	}

	file.close();

	return Client(Mode::Empty);
}

bool Client::IsClientExists(const string& fileName, const string& accountNumber)
{
	Client client{ Find(fileName, accountNumber) };

	return !client.IsEmpty();
}
