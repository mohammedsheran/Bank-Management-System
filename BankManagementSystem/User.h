#pragma once

#include <vector>

#include "Person.h"

class User : public Person
{
private:
	enum class Mode
	{
		Empty = 1,
		Update,
		Add
	};

	Mode _mode{};
	string _username{};
	string _password{};
	short _permissions{};
	bool _deletionFlag{};

	static User _ConvertLineToUserObject(const string& line, const string& delimiter = "#:#");
	static string _ConvertUserObjectToLine(const User& user, const string& separator = "#:#");

	static vector <User> _LoadUsers();
	static bool _SaveUsers(const vector <User>& vUsers);

	bool _AddUser() const;

	bool _UpdateUser() const;

	void _Reset();

public:
	User(const Mode& mode);
	User(const Mode& mode, const string& username);
	User(const Mode& mode, const string& firstName, const string& lastName, const string& email
		, const string& phoneNumber, const string& username, const string& password, const short& permissions);

	string GetUsername() const;

	void SetPassword(const string& Password);

	string GetPassword() const;

	enum class UserPermissions
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

	void SetPermissions(const short& permissions);

	short GetPermissions() const;

	__declspec(property(get = GetUsername)) string Username;
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	bool CheckPassword(const string& Password) const;

	bool IsEmpty() const;

	static User Find(const string& username);
	static User Find(const string& username, const string& Password);

	static bool IsUserExists(const string& username);

	enum class OperationResult
	{
		Failed = 1, 
		Succeeded
	};

	OperationResult Execute();

	static User GetNewUserForAdd(const string& username);

	bool DeleteUser();

	static vector <User> GetUserList();

	static void AddPermission(short& permissions, const UserPermissions& userPermissions);

	//static bool HasPermissions(const short& permissions, const UserPermissions& userPermissions);
};