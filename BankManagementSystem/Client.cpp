
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
Client::Client(const Mode& mode, const string& accountNumber) : Person(), _mode(mode), _accountNumber(accountNumber) {}
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

Client Client::Find(const string& accountNumber)
{
	ifstream file{ "Clients.txt" };

	if (!file)
	{
		cout << "Failed to open file: Clients.txt\n";
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
Client Client::Find(const string& accountNumber, const string& pinCode)
{
	ifstream file{ "Clients.txt"};

	if (!file)
	{
		cout << "Failed to open file: Clients.txt\n";
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

bool Client::IsClientExists(const string& accountNumber)
{
	Client client{ Find(accountNumber) };

	return !client.IsEmpty();
}

vector <Client> Client::_LoadClients()
{
	vector <Client> vClients{};

	ifstream file{ "Clients.txt" };

	if (!file)
	{
		cout << "Failed to open file: Clients.txt\n";
		return {};
	}

	string line{};

	while (getline(file, line))
	{
		vClients.emplace_back(_ConvertLineToClientObject(line));
	}

	file.close();

	return vClients;
}
bool Client::_SaveClients(const vector <Client>& vClients)
{
	ofstream file{ "Clients.txt" };

	if (!file)
	{
		cout << "Failed to open file: Clients.txt\n";
		return {};
	}

	for (const auto& client : vClients)
	{
		if (!client._deletionFlag)
		{
			file << _ConvertClientObjectToLine(client) << '\n';
		}
	}

	file.close();

	return true;
}

bool Client::_UpdateClient()
{
	vector <Client> vClients{ _LoadClients() };

	for (auto& client : vClients)
	{
		if (client.AccountNumber == AccountNumber)
		{
			client = *this;
			break;
		}
	}

	return _SaveClients(vClients);
}

Client::OperationResult Client::Execute()
{
	switch (_mode)
	{
	case Client::Mode::Empty:
		return OperationResult::Failed;

	case Client::Mode::Update:
		return _UpdateClient() ?
			OperationResult::Succeeded :
			OperationResult::Failed;

	case Client::Mode::Add:
		if (!_AddClient())
		{
			return OperationResult::Failed;
		}

		_mode = Mode::Update;
		return OperationResult::Succeeded;
	}

	return OperationResult::Failed;
}

Client Client::GetNewClientForAdd(const string& accountNumber)
{
	return Client(Mode::Add, accountNumber);
}

bool Client::_AddClient()
{
	ofstream file{ "Clients.txt", ios::app };

	if (!file)
	{
		cout << "Failed to open file: Clients.txt\n";
		return {};
	}

	file << _ConvertClientObjectToLine(*this) << '\n';

	file.close();

	return true;
}

void Client::_Reset()
{
	ResetPerson();

	_mode = Mode::Empty;
	_accountNumber.clear();
	_pinCode.clear();
	_accountBalance = 0.f;
}

bool Client::DeleteClient()
{
	vector <Client> vClients{ _LoadClients() };

	for (auto& client : vClients)
	{
		if (client.AccountNumber == AccountNumber)
		{
			client._deletionFlag = true;
			break;
		}
	}
	if (!_SaveClients(vClients))
		return {};

	_Reset();
	return true;
}

vector <Client> Client::GetClientList()
{
	return _LoadClients();
}

