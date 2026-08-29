
#include "Currency.h"
#include "Libraries/StringUtils.h"

#include <stdexcept>
#include <fstream>

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

Currency Currency::_ConvertLineToCurrencyObject(const std::string& line, const std::string& delimiter)
{
	std::vector <std::string> vString{ StringUtils::Split(line, delimiter) };

	if (vString.size() != 4)
	{
		return Currency(Mode::Empty);
	}

	return Currency(Mode::Update, vString[0], vString[1], vString[2], stof(vString[3]));
}

std::string Currency::_ConvertCurrencyObjectToLine(const Currency& currency, const std::string& separator)
{
	if (currency.IsEmpty())
	{
		return {};
	}

	std::string line{};

	line += currency._country + separator;
	line += currency._code + separator;
	line += currency._name + separator;
	line += to_string(currency._rate);

	return line;
}

std::vector <Currency> Currency::_LoadCurrencies()
{
	std::vector <Currency> vCurrencies{};

	std::ifstream file{ "Currencies.txt" };

	if (!file)
	{
		cout << "Failed to open file: Currencies.txt\n";
		return{};
	}

	std::string line{};

	while (getline(file, line))
	{
		vCurrencies.push_back(_ConvertLineToCurrencyObject(line));
	}

	file.close();

	return vCurrencies;
}

bool Currency::_SaveScurrencies(const std::vector <Currency>& vCurrencies)
{
	if (vCurrencies.empty())
	{
		return {};
	}

	std::ofstream file{ "Currencies.txt" };

	if (!file)
	{
		cout << "Failed to open file: Currencies.txt\n";
		return {};
	}

	for (const auto& currency : vCurrencies)
	{
		file << _ConvertCurrencyObjectToLine(currency) << '\n';
	}

	file.close();
	return true;
}

Currency Currency::FindByCountry(std::string country)
{
	std::ifstream file{ "Currencies.txt" };

	if (!file)
	{
		cout << "Failed to open file: Currencies.txt\n";
		return Currency(Mode::Empty);
	}

	country = StringUtils::ToUpper(country);

	std::string line{};

	while (getline(file, line))
	{
		Currency currency{ _ConvertLineToCurrencyObject(line) };

		if (StringUtils::ToUpper(currency.Country) == country)
		{
			file.close();
			return currency;
		}
	}

	file.close();

	return Currency(Mode::Empty);
}

Currency Currency::FindByCode(std::string code)
{
	std::ifstream file{ "Currencies.txt" };

	if (!file)
	{
		cout << "Failed to open file: Currencies.txt\n";
		return Currency(Mode::Empty);
	}

	code = StringUtils::ToUpper(code);

	std::string line{};

	while (getline(file, line))
	{
		Currency currency{ _ConvertLineToCurrencyObject(line) };

		if (StringUtils::ToUpper(currency.Code) == code)
		{
			file.close();
			return currency;
		}
	}

	file.close();

	return Currency(Mode::Empty);
}