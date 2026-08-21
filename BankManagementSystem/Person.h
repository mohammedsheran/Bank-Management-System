#pragma once

#include <iostream>
using namespace std;

class Person
{
private:
	string _firstName{};
	string _lastName{};
	string _email{};
	string _phoneNumber{};

protected:
	Person() = default;

	static string RequireField(const string& str);

public:
	Person(const string& firstName, const string& lastName, const string& email, const string& phoneNumber);

	void SetFirstName(const string& firstName);
	string GetFirstName() const;

	void SetLastName(const string& lastName);
	string GetLastName() const;

	void SetEmail(const string& email);
	string GetEmail() const;

	void SetPhoneNumber(const string& phoneNumber);
	string GetPhoneNumber() const;

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;
	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;

	string GetFullName(const bool& lastNameFirst = false) const;
};

