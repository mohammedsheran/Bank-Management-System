#include "Person.h"

string Person::RequireField(const string& str)
{
	if (!str.empty())
	{
		return str;
	}

	throw invalid_argument("Field can not be empty.");
}

Person::Person(const string& firstName, const string& lastName, const string& email, const string& phoneNumber)
	: _firstName(RequireField(firstName)), _lastName(RequireField(lastName)), _email(RequireField(email)), _phoneNumber(RequireField(_phoneNumber))
{

}

void Person::SetFirstName(const string& firstName)
{
	_firstName = RequireField(firstName);
}
string Person::GetFirstName() const
{
	return _firstName;
}

void Person::SetLastName(const string& lastName)
{
	_lastName = RequireField(lastName);
}
string Person::GetLastName() const
{
	return _lastName;
}

void Person::SetEmail(const string& email)
{
	_email = RequireField(email);
}
string Person::GetEmail() const
{
	return _email;
}

void Person::SetPhoneNumber(const string& phoneNumber)
{
	_phoneNumber = RequireField(phoneNumber);
}
string Person::GetPhoneNumber() const
{
	return _phoneNumber;
}

string Person::GetFullName(const bool& lastNameFirst) const
{
	if (lastNameFirst)
	{
		return _lastName + " " + _firstName;
	}

	return _firstName + " " + _lastName;
}
