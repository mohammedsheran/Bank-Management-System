#pragma once

#include <string>

class Currency
{
private:
	enum class Mode
	{
		Empty = 1,
		Update
	};

	Mode _mode{};
	std::string _country{};
	std::string _code{};
	std::string _name{};
	float _rate{};

	static std::string _RequireField(const std::string& str);
	
	static float _ValidateRate(const float& rate);

public:
	Currency(const Mode& mode);
	Currency(const Mode& mode, const std::string& country, const std::string& code, const std::string& name, const float& rate);

	std::string GetCountry() const;
	std::string GetCode() const;
	std::string GetName() const;

	void UpdateRate(const float& rate);
	float GetRate() const;

	__declspec(property(get = GetCountry)) std::string Country;
	__declspec(property(get = GetCode)) std::string Code;
	__declspec(property(get = GetName)) std::string Name;
	__declspec(property(get = GetRate)) float Rate;

	bool IsEmpty() const;

};