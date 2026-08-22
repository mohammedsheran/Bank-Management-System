#pragma once

#include "Person.h"
#include <vector>

class Client : public Person
{
private:
	enum class Mode
	{
		Empty = 1,
		Update,
		Add,
	};

	Mode _mode{};
	string _accountNumber{};
	string _pinCode{};
	float _accountBalance{};
	bool _deletionFlag{};

	static float _ValidateBalance(const float& balance);

	static Client _ConvertLineToClientObject(const string& line, const string& delimiter = "#:#");
	static string _ConvertClientObjectToLine(const Client& client, const string& separator = "#:#");

	static vector <Client> _LoadClients();
	static bool _SaveClients(const vector <Client>& vClients);

	bool _UpdateClient();
	
	bool _AddClient();

	void _Reset();

public:
	Client(const Mode& mode);
	Client(const Mode& mode, const string& accountNumner);
	Client(const Mode& mode, const string& firstName, const string& lastName, const string& email
		, const string& phoneNumber, const string& accountNumber, const string& pinCode, const float& accountBalance);

	string GetAccountNumber() const;

	void SetPinCode(const string& pinCode);

	string GetPinCode() const;

	void SetAccountBalance(const float& accountBalance);

	float GetAccountBalance() const;

	_declspec(property(get = GetAccountNumber)) string AccountNumber;
	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	bool IsEmpty() const;

	void PrintClientCard() const;

	static Client Find(const string& accountNumber);
	static Client Find(const string& accountNumber, const string& pinCode);

	static bool IsClientExists(const string& accountNumber);

	enum class OperationResult
	{
		Failed,
		Succeeded
	};

	OperationResult Execute();

	static Client GetNewClientForAdd(const string& accountNumber);

	bool DeleteClient();
};