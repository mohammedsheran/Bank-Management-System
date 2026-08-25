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
	bool _deletionFlag{};
};