#pragma once

#include <string>
#include <vector>

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

	static Currency _ConvertLineToCurrencyObject(const std::string& line, const std::string& delimiter = "#:#");
	static std::string _ConvertCurrencyObjectToLine(const Currency& currency, const std::string& separator = "#:#");

	static std::vector <Currency> _LoadCurrencies();
	static bool _SaveCurrencies(const std::vector <Currency>& vCurrencies);

	bool _UpdateCurrency();

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

	static Currency FindByCountry(std::string country);
	static Currency FindByCode(std::string code);

	static bool IsCurrecnyExists(const std::string& code);

	static std::vector <Currency> GetCurrecnyList();

	float ConvertToUSD(const float& amount) const;

	float ConvertToOtherCurrency(const float& amount, const Currency& currencyTo) const;
};