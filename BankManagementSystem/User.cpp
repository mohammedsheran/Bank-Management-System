
#include "User.h"

User::User(const Mode& mode) : Person(), _mode(mode) {}
User::User(const Mode& mode, const string& username) : Person(), _mode(mode), _username(RequireField(username)) {}
User::User(const Mode& mode, const string& firstName, const string& lastName, const string& email
	, const string& phoneNumber, const string& username, const string& password, const short& permissions)
	: Person(firstName, lastName, email, phoneNumber), _username(RequireField(username)), _password(RequireField(password)), _permissions(permissions)
{ 

}

string User::GetUsername() const
{
	return _username;
}

void User::SetPassword(const string& password)
{
	_password = RequireField(password);
}

void User::SetPermissions(const short& permissions)
{
	_permissions = permissions;
}

short User::GetPermissions() const
{
	return _permissions;
}

bool User::CheckPassword(const string& password) const
{
	return (_password == password);
}

bool User::IsEmpty() const
{
	return (_mode == Mode::Empty);
}