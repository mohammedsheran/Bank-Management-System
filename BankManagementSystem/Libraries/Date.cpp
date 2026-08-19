#pragma warning (disable:4996)

#include "Date.h"

#include <ctime>
#include <vector>
#include <string>

#include "StringUtils.h"
#include "Utils.h"

Date::Date()
{
	time_t now{ time(nullptr) };
	tm* dateTime{ localtime(&now) };

	_day = dateTime->tm_mday;
	_month = dateTime->tm_mon + 1;
	_year = dateTime->tm_year + 1900;
}

Date::Date(const string& str)
{
    vector <string> vString{ StringUtils::Split(str, "/")};

    if (vString.size() != 3)
        return;

    _day = stoi(vString[0]);
    _month = stoi(vString[1]);
    _year = stoi(vString[2]);
}

Date::Date(const short& daye, const short& month, const short& year)
    :_day{ daye }, _month{ month }, _year{ year } { }

Date::Date(const int& dayOfYear, const short& year)
{
    *this = DateFromDayOfYear(dayOfYear, year);
}

void Date::SetDay(const short& day)
{
    _day = day;
}

short Date::GetDay() const
{
    return _day;
}

void Date::SetMonth(const short& month)
{
    _month = month;
}

short Date::GetMonth() const
{
    return _month;
}

void Date::SetYear(const short& year)
{
    _year = year;
}

short Date::GetYear() const
{
    return _year;
}

bool Date::IsLeapYear(const short& year)
{
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}

bool Date::IsLeapYear() const
{
    return IsLeapYear(_year);
}

short Date::GetNumberOfDaysInYear(const short& year)
{
    return (IsLeapYear(year)) ? 366 : 365;
}

short Date::GetNumberOfDaysInYear() const
{
    return GetNumberOfDaysInYear(_year);
}

short Date::GetNumberOfHoursInYear(const short& year)
{
    return GetNumberOfDaysInYear(year) * 24;
}

short Date::GetNumberOfHoursInYear() const
{
    return GetNumberOfHoursInYear(_year);
}

int Date::GetNumberOfMinutesInYear(const short& year)
{
    return GetNumberOfHoursInYear(year) * 60;
}

int Date::GetNumberOfMinutesInYear() const
{
    return GetNumberOfMinutesInYear(_year);
}

int Date::GetNumberOfSecondsInYear(const short& year)
{
    return GetNumberOfMinutesInYear(year) * 60;
}

int Date::GetNumberOfSecondsInYear() const
{
    return GetNumberOfSecondsInYear(_year);
}

short Date::GetNumberOfHoursInMonth(const short& days)
{
    return days * 24;
}

short Date::GetNumberOfHoursInMonth() const
{
    return GetNumberOfHoursInMonth(GetDaysInMonth(_month, _year));
}

int Date::GetNumberOfMinutesInMonth(const short& days)
{
    return GetNumberOfHoursInMonth(days) * 60;
}

int Date::GetNumberOfMinutesInMonth() const
{
    return GetNumberOfMinutesInMonth(GetDaysInMonth(_month, _year));
}

int Date::GetNumberOfSecondsInMonth(const short& days)
{
    return GetNumberOfMinutesInMonth(days) * 60;
}

int Date::GetNumberOfSecondsInMonth() const
{
    return GetNumberOfSecondsInMonth(GetDaysInMonth(_month, _year));
}

short Date::GetDayOfWeek(const short& day, const short& month, const short& year)
{
    short a{ (14 - month) / 12 };
    short y{ year - a };
    short m{ month + (12 * a) - 2 };

    return (day + y + (y / 4) - (y / 100) +
        (y / 400) + ((31 * m) / 12)) % 7;
}

short Date::GetDayOfWeek(const Date& date)
{
    return GetDayOfWeek(date.Day, date.Month, date.Year);
}

short Date::GetDayOfWeek() const
{
    return Date::GetDayOfWeek(*this);
}

string Date::GetDayShortName(const short& dayOfWeek)
{
    string DayNames[]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

    return DayNames[dayOfWeek];
}

string Date::GetDayShortName() const
{
    return GetDayShortName(GetDayOfWeek(_day, _month, _year));
}

string Date::GetMonthShortName(const short& month)
{
    string monthNames[]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec" };

    return monthNames[month - 1];
}

string Date::GetMonthShortName() const
{
    return GetMonthShortName(_month);
}

short Date::GetDaysInMonth(const short& month, const short& year)
{
    if (month < 1 || month > 12)
        return {};

    short monthDays[]{ 31, 28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : monthDays[month - 1];
}

short Date::GetDaysInMonth() const
{
    return GetDaysInMonth(_month, _year);
}

void Date::ShowDate(const Date& date)
{
    cout << DateToString(date);
}

void Date::ShowDate() const
{
    ShowDate(*this);
}

void Date::ShowMonthCalendar(const short& month, const short& year)
{
    cout << "\n  ";
    cout << Utils::Divider(15) << GetMonthShortName(month) << Utils::Divider(15);
    cout << '\n';

    short dayOrder{ GetDayOfWeek(1, month, year) };

    for (short day = 0; day < 7; day++)
        printf("%5s", GetDayShortName(day).c_str());

    cout << '\n';

    for (short order = 0; order < dayOrder; order++)
        cout << "     ";

    short monthLength{ GetDaysInMonth(month, year) };

    for (short day = 1; day <= monthLength; day++)
    {
        printf("%5d", day);

        if (++dayOrder == 7)
        {
            cout << '\n';
            dayOrder = 0;
        }
    }

    cout << "\n  ";
    cout << Utils::Divider(33);
}

void Date::ShowMonthCalendar() const
{
    ShowMonthCalendar(_month, _year);
}

void Date::ShowYearCalendar(const short& year)
{
    cout << "\n  ";
    cout << Utils::Divider(33) << '\n';

    cout << Utils::Tab(1) << "    Calendar - " << year;

    cout << "\n  ";
    cout << Utils::Divider(33);

    for (short month = 1; month <= 12; month++)
        ShowMonthCalendar(month, year);
}

void Date::ShowYearCalendar() const
{
    ShowYearCalendar(_year);
}

short Date::GetDayOfYear(const short& day, const short& month, const short& year)
{
    short counter{};

    for (short monthCounter = 1; monthCounter < month; monthCounter++)
    {
        counter += GetDaysInMonth(monthCounter, year);
    }

    counter += day;

    return counter;
}

short Date::GetDayOfYear() const
{
    return GetDayOfYear(_day, _month, _year);
}

Date Date::DateFromDayOfYear(const short& dayOfYear, const short& year)
{
    Date date;

    short remainingDays{ dayOfYear };

    date.Day = 0;
    date.Month = 1;
    date.Year = year;

    while (true)
    {
        date.Day = GetDaysInMonth(date.Month, date.Year);

        if (remainingDays > date.Day)
        {
            remainingDays -= date.Day;
            date.Month++;
        }
        else
        {
            date.Day = remainingDays;
            break;
        }
    }

    return date;
}

Date Date::DateFromDayOfYear(const short& dayOfYear) const
{
    return DateFromDayOfYear(dayOfYear, this->Year);
}

Date Date::AddDays(Date date, const short& daysToAdd)
{
    short remainingDays = daysToAdd + GetDayOfYear(date.Day, date.Month, date.Year);

    date.Month = 1;

    while (true)
    {
        date.Day = GetDaysInMonth(date.Month, date.Year);

        if (remainingDays > date.Day)
        {
            remainingDays -= date.Day;
            date.Month++;

            if (date.Month > 12)
            {
                date.Month = 1;
                date.Year++;
            }
        }
        else
        {
            date.Day = remainingDays;
            return date;
        }
    }

}

void Date::AddDays(const short& daysToAdd)
{
    *this =  AddDays(*this, daysToAdd);
}

bool Date::IsDate1BeforeDate2(const Date& date1, const Date& date2)
{
    return (date1.Year < date2.Year) ? true
        : (date1.Year == date2.Year ? (date1.Month < date2.Month ? true : (date1.Month == date2.Month ? date1.Day < date2.Day : false)) : false);
}

bool Date::IsDateBeforeDate2(const Date& date2) const
{
    return IsDate1BeforeDate2(*this, date2);
}

bool Date::IsDate1EqualsDate2(const Date& date1, const Date& date2)
{
    return (date1.Year == date2.Year) ? (date1.Month == date2.Month ? date1.Day == date2.Day : false) : false;
}

bool Date::IsDateEqualDate2(const Date& date2) const
{
    return IsDate1EqualsDate2(*this, date2);
}

bool Date::IsFirstDayInMonth(const short& day)
{
    return (day == 1);
}

bool Date::IsFirstDayInMonth() const
{
    return IsFirstDayInMonth(_day);
}

bool Date::IsFirstMonthInYear(const short& month)
{
    return (month == 1);
}

bool Date::IsFirstMonthInYear() const
{
    return IsFirstMonthInYear(_month);
}

bool Date::IsLastDayInMonth(const Date& date)
{
    return (date.Day == GetDaysInMonth(date.Month, date.Year));
}
    
bool Date::IsLastDayInMonth() const
{
    return IsLastDayInMonth(*this);
}
    
bool Date::IsLastMonthInYear(const short& month)
{
    return (month == 12);
}
     
bool Date::IsLastMonthInYear() const
{
    return IsLastMonthInYear(_month);
}

Date Date::IncreaseDateByOneDay(Date date)
{
    if (IsLastDayInMonth(date))
    {

        if (IsLastMonthInYear(date.Month))
        {

            date.Day = 1;
            date.Month = 1;
            date.Year++;
        }

        else
        {

            date.Day = 1;
            date.Month++;
        }
    }
    else
    {

        date.Day++;
    }

    return date;
}

void Date::IncreaseDateByOneDay()
{
    *this = IncreaseDateByOneDay(*this);
}

Date Date::IncreaseDateByXDays(Date date, const short& days)
{
    for (short counter = 0; counter < days; counter++)
    {
        date = IncreaseDateByOneDay(date);
    }

    return date;
}

void Date::IncreaseDateByXDays(const short& days)
{
    *this = IncreaseDateByXDays(*this, days);
}

Date Date::IncreaseDateByOneWeek(Date date)
{
    return IncreaseDateByXDays(date, 7);
}

void Date::IncreaseDateByOneWeek()
{
    *this = IncreaseDateByOneWeek(*this);
}

Date Date::IncreaseDateByXWeek(Date date, const short& weeks)
{
    for (short counter = 0; counter < weeks; counter++)
    {
        date = IncreaseDateByOneWeek(date);
    }

    return date;
}

void Date::IncreaseDateByXWeek(const short& weeks)
{
    *this = IncreaseDateByXWeek(*this, weeks);
}

Date Date::IncreaseDateByOneMonth(Date date)
{
    if (IsLastMonthInYear(date.Month))
    {
        date.Month = 1;
        date.Year++;
    }
    else
        date.Month++;

    short daysInCurrentMonth = GetDaysInMonth(date.Month, date.Year);

    if (date.Day > daysInCurrentMonth)
        date.Day = daysInCurrentMonth;

    return date;
}

void Date::IncreaseDateByOneMonth()
{
    *this = IncreaseDateByOneMonth(*this);
}

Date Date::IncreaseDateByXMonth(Date date, const short& months)
{
    for (short counter = 0; counter < months; counter++)
    {
        date = IncreaseDateByOneMonth(date);
    }

    return date;
}

void Date::IncreaseDateByXMonth(const short& months)
{
    *this = IncreaseDateByXMonth(*this, months);
}

Date Date::IncreaseDateByOneYear(Date date)
{
    date.Year++;
    return date;
}

void Date::IncreaseDateByOneYear()
{
    *this = IncreaseDateByOneYear(*this);
}

Date Date::IncreaseDateByXYear(Date date, const short& years)
{
    for (short counter = 0; counter < years; counter++)
    {
        date = IncreaseDateByOneYear(date);
    }

    return date;
}

void Date::IncreaseDateByXYear(const short& years)
{
    *this = IncreaseDateByXYear(*this, years);
}

Date Date::IncreaseDateByXYearFaster(Date date, const short& years)
{
    date.Year += years;

    return date;
}

void Date::IncreaseDateByXYearFaster(const short& years)
{
    *this = IncreaseDateByXYearFaster(*this, years);
}

Date Date::IncreaseDateByOneDecade(Date date)
{
    date.Year += 10;

    return date;
}

void Date::IncreaseDateByOneDecade()
{
    *this = IncreaseDateByOneDecade(*this);
}

Date Date::IncreaseDateByXDecade(Date date, const short& decades)
{
    for (short i = 0; i < decades; i++)
    {
        date = IncreaseDateByOneDecade(date);
    }

    return date;
}

void Date::IncreaseDateByXDecade(const short& decades)
{
    *this = IncreaseDateByXDecade(*this, decades);
}

Date Date::IncreaseDateByXDecadeFaster(Date date, const short& decades)
{
    date.Year += (decades * 10);

    return date;
}

void Date::IncreaseDateByXDecadeFaster(const short& decades)
{
    *this = IncreaseDateByXDecadeFaster(*this, decades);
}

Date Date::IncreaseDateByOneCentury(Date date)
{
    date.Year += 100;

    return date;
}

void Date::IncreaseDateByOneCentury()
{
    *this = IncreaseDateByOneCentury(*this);
}

Date Date::IncreaseDateByOneMillennium(Date date)
{
    date.Year += 1000;

    return date;
}

void Date::IncreaseDateByOneMillennium()
{
    *this = IncreaseDateByOneMillennium(*this);
}

Date Date::DecreaseDateByOneDay(Date date)
{
    if (IsFirstDayInMonth(date.Day))
    {
        if (IsFirstMonthInYear(date.Month))
        {
            date.Month = 12;
            date.Day = 31;
            date.Year--;
        }
        else
        {
            date.Month--;
            date.Day = GetDaysInMonth(date.Month, date.Year);
        }
    }
    else
        date.Day--;

    return date;
}

void Date::DecreaseDateByOneDay()
{
    *this = DecreaseDateByOneDay(*this);
}

Date Date::DecreaseDateByXDays(Date date, const short& days)
{
    for (short counter = 0; counter < days; counter++)
    {
        date = DecreaseDateByOneDay(date);
    }

    return date;
}

void Date::DecreaseDateByXDays(const short& days)
{
    *this = DecreaseDateByXDays(*this, days);
}

Date Date::DecreaseDateByOneWeek(Date date)
{
    return DecreaseDateByXDays(date, 7);
}

void Date::DecreaseDateByOneWeek()
{
    *this = DecreaseDateByOneWeek(*this);
}

Date Date::DecreaseDateByXWeek(Date date, const short& weeks)
{
    for (short counter = 0; counter < weeks; counter++)
    {
        date = DecreaseDateByOneWeek(date);
    }

    return date;
}

void Date::DecreaseDateByXWeek(const short& weeks)
{
    *this = DecreaseDateByXWeek(*this, weeks);
}

Date Date::DecreaseDateByOneMonth(Date date)
{
    if (IsFirstMonthInYear(date.Month))
    {
        date.Month = 12;
        date.Year--;
    }
    else
        date.Month--;

    short daysInCurrentMonth = GetDaysInMonth(date.Month, date.Year);

    if (date.Day > daysInCurrentMonth)
        date.Day = daysInCurrentMonth;

    return date;
}

void Date::DecreaseDateByOneMonth()
{
    *this = DecreaseDateByOneMonth(*this);
}

Date Date::DecreaseDateByXMonth(Date date, const short& months)
{
    for (short counter = 0; counter < months; counter++)
    {
        date = DecreaseDateByOneMonth(date);
    }

    return date;
}

void Date::DecreaseDateByXMonth(const short& months)
{
    *this = DecreaseDateByXMonth(*this, months);
}

Date Date::DecreaseDateByOneYear(Date date)
{
    date.Year--;

    return date;
}

void Date::DecreaseDateByOneYear()
{
    *this = DecreaseDateByOneYear(*this);
}

Date Date::DecreaseDateByXYear(Date date, const short& years)
{
    for (short counter = 0; counter < years; counter++)
    {
        date = DecreaseDateByOneYear(date);
    }

    return date;
}

void Date::DecreaseDateByXYear(const short& years)
{
    *this = DecreaseDateByXYear(*this, years);
}

Date Date::DecreaseDateByXYearFaster(Date date, const short& years)
{
    date.Year -= years;

    return date;
}

void Date::DecreaseDateByXYearFaster(const short& years)
{
    *this = DecreaseDateByXYearFaster(*this, years);
}

Date Date::DecreaseDateByOneDecade(Date date)
{
    date.Year -= 10;

    return date;
}

void Date::DecreaseDateByOneDecade()
{
    *this = DecreaseDateByOneDecade(*this);
}

Date Date::DecreaseDateByXDecade(Date date, const short& decades)
{
    for (short i = 0; i < decades; i++)
    {
        date = DecreaseDateByOneDecade(date);
    }

    return date;
}

void Date::DecreaseDateByXDecade(const short& decades)
{
    *this = DecreaseDateByXDecade(*this, decades);
}

Date Date::DecreaseDateByXDecadeFaster(Date date, const short& decades)
{
    date.Year -= (decades * 10);

    return date;
}

void Date::DecreaseDateByXDecadeFaster(const short& decades)
{
    *this = DecreaseDateByXDecadeFaster(*this, decades);
}

Date Date::DecreaseDateByOneCentury(Date date)
{
    date.Year -= 100;

    return date;
}

void Date::DecreaseDateByOneCentury()
{
    *this = DecreaseDateByOneCentury(*this);
}

Date Date::DecreaseDateByOneMillennium(Date date)
{
    date.Year -= 1000;

    return date;
}

void Date::DecreaseDateByOneMillennium()
{
    *this = DecreaseDateByOneMillennium(*this);
}

int Date::DifferenceInDays(Date date1, const Date& date2, const bool& includeEndDay)
{
    int differenceDays{};

    while (IsDate1BeforeDate2(date1, date2)) {
        differenceDays++;
        date1 = IncreaseDateByOneDay(date1);
    }

    return (includeEndDay) ? ++differenceDays : differenceDays;
}

int Date::DifferenceInDays(const Date& date, const bool& includeEndDay) const
{
    return DifferenceInDays(*this, date, includeEndDay);
}

Date Date::GetDate()
{
    time_t now{ time(nullptr) };
    tm* dateTime{ localtime(&now) };

    int day{ dateTime->tm_mday };
    int month{ dateTime->tm_mon + 1 };
    int year{ dateTime->tm_year + 1900 };

    return Date(day, month, year);
}

bool Date::IsEndOfWeek(const Date& date)
{
    return (GetDayOfWeek(date) == 6);
}

bool Date::IsEndOfWeek() const
{
    return IsEndOfWeek(*this);
}

bool Date::IsWeekend(const Date& date)
{
    short dayOrder = GetDayOfWeek(date);
    return (dayOrder == 5 || dayOrder == 6);
}

bool Date::IsWeekend() const
{
    return IsWeekend(*this);
}

bool Date::IsBusinessDay(const Date& date)
{
    return (!Date::IsWeekend(date));
}

bool Date::IsBusinessDay() const
{
    return Date::IsBusinessDay(*this);
}

short Date::DaysUntilEndOfWeek(Date date)
{
    return 6 - GetDayOfWeek(date);
}

short Date::DaysUntilEndOfWeek() const
{
    return DaysUntilEndOfWeek(*this);
}

short Date::DaysUntilEndOfMonth(Date date)
{
    Date endOfMonthDate{
        GetDaysInMonth(date.Month, date.Year),
        date.Month,
        date.Year
    };

    return DifferenceInDays(date, endOfMonthDate, true);
}

short Date::DaysUntilEndOfMonth() const
{
    return DaysUntilEndOfMonth(*this);
}

short Date::DaysUntilEndOfYear(Date date)
{
    Date endOfYearDate(31, 12, date.Year + 1);

    return DifferenceInDays(date, endOfYearDate, true);
}

short Date::DaysUntilEndOfYear() const
{
    return DaysUntilEndOfYear(*this);
}

short Date::CalculateVacationDays(Date dateFrom, Date dateTo)
{
    short counter{};

    while (IsDate1BeforeDate2(dateFrom, dateTo))
    {
        if (IsBusinessDay(dateFrom))
            counter++;

        dateFrom = IncreaseDateByOneDay(dateFrom);
    }

    return counter;
}

short Date::CalculateVacationDays(Date dateTo)
{
    return CalculateVacationDays(*this, dateTo);
}

Date Date::CalculateVacationReturnDate(Date date, short vecationDays)
{
    short weekednDays{ 0 };

    while (IsWeekend(date))
        date = IncreaseDateByOneDay(date);

    for (short i = 0; i < vecationDays + weekednDays; i++)
    {
        if (IsWeekend(date))
            weekednDays++;

        date = IncreaseDateByOneDay(date);
    }

    while (IsWeekend(date))
        date = IncreaseDateByOneDay(date);

    return date;
}

void Date::CalculateVacationReturnDate(short vecationDays)
{
    *this = CalculateVacationReturnDate(*this, vecationDays);
}

bool Date::IsDate1AfterDate2(const Date& date1, const Date& date2)
{
    return !(IsDate1BeforeDate2(date1, date2) ||
        IsDate1EqualsDate2(date1, date2));
}

bool Date::IsDate1AfterDate2(const Date& date2) const
{
    return IsDate1AfterDate2(*this, date2);
}

Date::DateComparison Date::CompareDate(const Date& date1, const Date& date2)
{
    if (IsDate1BeforeDate2(date1, date2))
        return DateComparison::Before;

    if (IsDate1EqualsDate2(date1, date2))
        return DateComparison::Equal;

    return DateComparison::After;
}

Date::DateComparison Date::CompareDate(const Date& date) const
{
    return CompareDate(*this, date);
}

bool Date::IsValidDate(const Date& date)
{
    if (date.Year < 1)
        return {};

    if (date.Month < 1 || date.Month > 12)
        return {};

    if (date.Day < 1 || date.Day > GetDaysInMonth(date.Month, date.Year))
        return {};

    return { true };
}

bool Date::IsValidDate() const
{
    return IsValidDate(*this);
}

string Date::DateToString(const Date& date, const string& separator)
{
    string strDate{};

    strDate = to_string(date.Day) + separator;
    strDate += to_string(date.Month) + separator;
    strDate += to_string(date.Year);

    return strDate;
}

string Date::DateToString(const string& separator) const
{
    return DateToString(*this, separator);
}

string Date::FormatDate(const Date& date, const string& format)
{
    string formattedDate{ format };

    formattedDate = StringUtils::Replace(formattedDate, "dd", to_string(date.Day));
    formattedDate = StringUtils::Replace(formattedDate, "mm", to_string(date.Month));
    formattedDate = StringUtils::Replace(formattedDate, "yyyy", to_string(date.Year));

    return formattedDate;
}

string Date::FormatDate(const string& format) const
{
    return FormatDate(*this, format);
}