#pragma once

#include "Person.h"
#include <vector>

class Client : public Person
{
private:
	enum class Mode
	{
		Empty = 1,
		Update
	};

	Mode _mode{};
	string _accountNumber{};
	string _pinCode{};
	float _accountBalance{};

	static float _ValidateBalance(const float& balance);

public:
	Client(const Mode& mode, const string& firstName, const string& lastName, const string& email
		, const string& phoneNumber, const string& accountNumber, const string& pinCode, const float& accountBalance);

	string GetAccountNumber() const;

	void SetPinCode(const string& pinCode);

	string GetPinCode() const;

	void SetAccountBalance(const float& accountBalance);

	float GetAccountBalance() const;

	_declspec(property(get = GetAccountNumber)) string AccountNumber;
	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance)) string AccountBalance;

	bool IsEmpty() const;

	void PrintClientCard() const;

};