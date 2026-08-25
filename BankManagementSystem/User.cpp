
#include <vector>
#include <string>

#include "User.h"
#include "Libraries/StringUtils.h"

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

User User::_ConvertLineToUserObject(const string& line, const string& delimiter)
{
	vector <string> vString{ StringUtils::Split(line, delimiter) };

	if (vString.size() != 7)
	{
		return User(Mode::Empty);
	}

	return User(Mode::Update, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5], stoi(vString[6]));
}
string User::_ConvertUserObjectToLine(const User& user, const string& separator)
{
	if (user.IsEmpty())
	{
		return {};
	}
	
	string line{};

	line += user.FirstName + separator;
	line += user.LastName + separator;
	line += user.Email + separator;
	line += user.PhoneNumber + separator;
	line += user._username + separator;
	line += user._password + separator;
	line += to_string(user._permissions);

	return line;
}