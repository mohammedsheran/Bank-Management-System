
#include "Currency.h"
#include <stdexcept>

std::string Currency::_RequireField(const std::string& str)
{
	if (!str.empty())
	{
		return str;
	}

	throw std::invalid_argument("Field can not be empty.");
}

float Currency::_ValidateRate(const float& rate)
{
	if (rate >= 0)
	{
		return rate;
	}

	throw std::invalid_argument("Field can not be less than zero.");
}

Currency::Currency(const Mode& mode) : _mode(mode) {}

Currency::Currency(const Mode& mode, const std::string& country, const std::string& code, const std::string& name, const float& rate)
	: _mode(mode), _country(_RequireField(country)), _code(_RequireField(code)), _name(_RequireField(name)), _rate(_ValidateRate(rate)){ }

std::string Currency::GetCountry() const
{
	return _country;
}

std::string Currency::GetCode() const
{
	return _code;
}

std::string Currency::GetName() const
{
	return _name;
}

void Currency::UpdateRate(const float& rate)
{
	_rate = _ValidateRate(rate);
}

float Currency::GetRate() const
{
	return _rate;
}

bool Currency::IsEmpty() const
{
	return _mode == Mode::Empty;
}