
#include <vector>
#include <string>
#include <fstream>

#include "User.h"
#include "Libraries/StringUtils.h"

User::User(const Mode& mode) : Person(), _mode(mode) {}
User::User(const Mode& mode, const string& username) : Person(), _mode(mode), _username(RequireField(username)) {}
User::User(const Mode& mode, const string& firstName, const string& lastName, const string& email
	, const string& phoneNumber, const string& username, const string& Password, const short& permissions)
	: Person(firstName, lastName, email, phoneNumber), _username(RequireField(username)), _password(RequireField(Password)), _permissions(permissions)
{ 

}

string User::GetUsername() const
{
	return _username;
}

void User::SetPassword(const string& Password)
{
	_password = RequireField(Password);
}

string User::GetPassword() const
{
	return _password;
}

void User::SetPermissions(const short& permissions)
{
	_permissions = permissions;
}

enum class Permissions
{
	FullAccess = -1,
	ClientList = 1,
	AddClient = 2,
	DeleteClient = 4,
	UpdateClient = 8,
	FindClient = 16,
	Transactions = 32,
	ManageUsers = 64
};

short User::GetPermissions() const
{
	return _permissions;
}

bool User::CheckPassword(const string& Password) const
{
	return (_password == Password);
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

vector <User> User::_LoadUsers()
{
	vector <User> vUsers{};

	ifstream file{ "Users.txt" };

	if (!file)
	{
		cout << "Failed to open file: Users.txt\n";
		return {};
	}

	string line{};

	while (getline(file, line))
	{
		vUsers.push_back(_ConvertLineToUserObject(line));
	}

	file.close();

	return vUsers;
}
bool User::_SaveUsers(const vector <User>& vUsers)
{
	if (vUsers.empty())
	{
		return {};
	}

	ofstream file{ "Users.txt" };

	if (!file)
	{
		cout << "Failed to open file: Users.txt\n";
		return {};
	}

	for (const auto& user : vUsers)
	{
		if (!user._deletionFlag)
		{
			file << _ConvertUserObjectToLine(user) << '\n';
		}
	}

	file.close();

	return true;
}

User User::Find(const string& username)
{
	ifstream file{ "Users.txt" };

	if (!file)
	{
		cout << "Failed to open file: Users.txt\n";
		return User(Mode::Empty);
	}

	string line{};

	while (getline(file, line))
	{
		User user{ _ConvertLineToUserObject(line) };

		if (user.Username == username)
		{
			file.close();
			return user;
		}
	}

	file.close();

	return User(Mode::Empty);
}
User User::Find(const string& username, const string& Password)
{
	ifstream file{ "Users.txt" };

	if (!file)
	{
		cout << "Failed to open file: Users.txt\n";
		return User(Mode::Empty);
	}

	string line{};

	while (getline(file, line))
	{
		User user{ _ConvertLineToUserObject(line) };

		if (user.Username == username && user.CheckPassword(Password))
		{
			file.close();
			return user;
		}
	}

	file.close();

	return User(Mode::Empty);
}

bool User::IsUserExists(const string& username)
{
	User user{ User::Find(username) };

	return !user.IsEmpty();
}

User::OperationResult User::Execute()
{
	switch (_mode)
	{
	case User::Mode::Empty:
		return OperationResult::Failed;

	case User::Mode::Update:
		return _UpdateUser() 
			? OperationResult::Succeeded
			: OperationResult::Failed;

	case User::Mode::Add:
		if (!_AddUser())
		{
			return OperationResult::Failed;
		}

		_mode = Mode::Update;
		return OperationResult::Succeeded;
	}

	return OperationResult::Failed;
}

bool User::_AddUser() const
{
	ofstream file{ "Users.txt", ios::app };

	if (!file)
	{
		cout << "Failed to open file: Users.txt\n";
		return {};
	}

	file << _ConvertUserObjectToLine(*this) << '\n';

	file.close();

	return true;
}

User User::GetNewUserForAdd(const string& username)
{
	return User(Mode::Add, username);
}

bool User::_UpdateUser() const
{
	vector <User> vUsers{ _LoadUsers() };

	if (vUsers.empty())
	{
		return {};
	}

	for (auto& user : vUsers)
	{
		if (user.Username == Username)
		{
			user = *this;
			break;
		}
	}

	return _SaveUsers(vUsers);
}

void User::_Reset()
{
	ResetPerson();

	_mode = Mode::Empty;
	_username.clear();
	_password.clear();
	_permissions = 0;
}

bool User::DeleteUser()
{
	vector <User> vUsers{ _LoadUsers() };

	if (vUsers.empty())
	{
		return {};
	}

	for (auto& user : vUsers)
	{
		if (user.Username == Username)
		{
			user._deletionFlag = true;
			break;
		}
	}

	if (!_SaveUsers(vUsers))
	{
		return {};
	}

	_Reset();
	return true;
}

vector <User> User::GetUserList()
{
	return _LoadUsers();
}
