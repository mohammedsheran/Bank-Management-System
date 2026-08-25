#pragma once

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

public:
	User(const Mode& mode);
	User(const Mode& mode, const string& username);
	User(const Mode& mode, const string& firstName, const string& lastName, const string& email
		, const string& phoneNumber, const string& username, const string& password, const short& permissions);

	string GetUsername() const;

	void SetPassword(const string& password);

	void SetPermissions(const short& permissions);

	short GetPermissions() const;

	__declspec(property(get = GetUsername)) string Username;
	__declspec(property(put = Password)) string password;
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	bool CheckPassword(const string& password) const;

	bool IsEmpty() const;

	static User Find(const string& username);
	static User Find(const string& username, const string& password);

	static bool IsUserExists(const string& username);

};