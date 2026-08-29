
#include <iomanip>

#include "CurrencyListScreen.h"
#include "Libraries/Utils.h"
#include "Global.h"
#include "Logger.h"
#include "LogMessages.h"

void CurrencyListScreen::_PrintCurrencyRecord(const Currency& currency)
{
    cout << "| " << left << setw(30) << currency.Country
        << "| " << setw(8) << currency.Code
        << "| " << setw(45) << currency.Name
        << "| " << setw(10) << currency.Rate
        << '\n';
}

void CurrencyListScreen::ShowCurrencyListScreen()
{
	vector <Currency> vCurrencies{ Currency::GetCurrecnyList() };

    Screen::ShowScreenHeader("Currecny List Screen",
        to_string(vCurrencies.size()) + " Currency(s).");

    if (vCurrencies.empty())
    {
        cout << "\nNo currencies available.\n";
        return;
    }

    cout << "| " << left << setw(30) << "Country"
        << "| " << setw(8) << "Code"
        << "| " << setw(45) << "Name"
        << "| " << setw(10) << "Rate/(1$)"
        << '\n';

    cout << Utils::Divider(110) << '\n';

    for (const auto& currency : vCurrencies)
    {
        _PrintCurrencyRecord(currency);
    }

    cout << Utils::Divider(110) << endl;

    Logger::Info(LogMessages::currencyListDisplayed);
}
