#pragma once

#include <iostream>
using namespace std;

class Date
{
private:
	short _day{};
	short _month{};
	short _year{};

public:
	Date();

	Date(const string& str);

	Date(const short& day, const short& month, const short& year);

	Date(const int& days, const short& year);

	void SetDay(const short& day);
	
	short GetDay() const;

	void SetMonth(const short& month);

	short GetMonth() const;

	void SetYear(const short& year);

	short GetYear() const;

	__declspec(property(get = GetDay, put = SetDay)) short Day;
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;
	__declspec(property(get = GetYear, put = SetYear)) short Year;

	static bool IsLeapYear(const short& year);
	bool IsLeapYear() const;

	static short GetNumberOfDaysInYear(const short& year);
	short GetNumberOfDaysInYear() const;

	static short GetNumberOfHoursInYear(const short& year);
	short GetNumberOfHoursInYear() const;

	static int GetNumberOfMinutesInYear(const short& year);
	int GetNumberOfMinutesInYear() const;

	static int GetNumberOfSecondsInYear(const short& year);
	int GetNumberOfSecondsInYear() const;

	static short GetNumberOfHoursInMonth(const short& days);
	short GetNumberOfHoursInMonth() const;

	static int GetNumberOfMinutesInMonth(const short& days);
	int GetNumberOfMinutesInMonth() const;

	static int GetNumberOfSecondsInMonth(const short& days);
	int GetNumberOfSecondsInMonth() const;

	static short GetDaysInMonth(const short& month, const short& year);
	short GetDaysInMonth() const;

	static void ShowDate(const Date& date);
	void ShowDate() const;

	static short GetDayOfWeek(const short& day, const short& month, const short& year);
	static short GetDayOfWeek(const Date& date);
	short GetDayOfWeek() const;

	static string GetDayShortName(const short& dayOfWeek);
	string GetDayShortName() const;

	static string GetMonthShortName(const short& month);
	string GetMonthShortName() const;

	static void ShowMonthCalendar(const short& month, const short& year);
	void ShowMonthCalendar() const;

	static void ShowYearCalendar(const short& year);
	void ShowYearCalendar() const;

	static short GetDayOfYear(const short& day, const short& month, const short& year);
	short GetDayOfYear() const;

	static Date DateFromDayOfYear(const short& dayOfYear, const short& year);
	Date DateFromDayOfYear(const short& dayOfYear) const;

	static bool IsDate1BeforeDate2(const Date& date1, const Date& date2);
	bool IsDateBeforeDate2(const Date& date2) const;

	static bool IsDate1EqualsDate2(const Date& date1, const Date& date2);
	bool IsDateEqualDate2(const Date& date2) const;

	static Date AddDays(Date date, const short& daysToAdd);
	void AddDays(const short& daysToAdd);

	static bool IsFirstDayInMonth(const short& day);
	bool IsFirstDayInMonth() const;

	static bool IsFirstMonthInYear(const short& month);
	bool IsFirstMonthInYear() const;

	static bool IsLastDayInMonth(const Date& date);
	bool IsLastDayInMonth() const;

	static bool IsLastMonthInYear(const short& month);
	bool IsLastMonthInYear() const;

	static Date IncreaseDateByOneDay(Date date);
	void IncreaseDateByOneDay();

	static Date IncreaseDateByXDays(Date date, const short& days);
	void IncreaseDateByXDays(const short& days);

	static Date IncreaseDateByOneWeek(Date date);
	void IncreaseDateByOneWeek();

	static Date IncreaseDateByXWeek(Date date, const short& weeks);
	void IncreaseDateByXWeek(const short& weeks);

	static Date IncreaseDateByOneMonth(Date date);
	void IncreaseDateByOneMonth();

	static Date IncreaseDateByXMonth(Date date, const short& months);
	void IncreaseDateByXMonth(const short& months);

	static Date IncreaseDateByOneYear(Date date);
	void IncreaseDateByOneYear();

	static Date IncreaseDateByXYear(Date date, const short& years);
	void IncreaseDateByXYear(const short& years);

	static Date IncreaseDateByXYearFaster(Date date, const short& years);
	void IncreaseDateByXYearFaster(const short& years);

	static Date IncreaseDateByOneDecade(Date date);
	void IncreaseDateByOneDecade();

	static Date IncreaseDateByXDecade(Date date, const short& decades);
	void IncreaseDateByXDecade(const short& decades);

	static Date IncreaseDateByXDecadeFaster(Date date, const short& decades);
	void IncreaseDateByXDecadeFaster(const short& decades);

	static Date IncreaseDateByOneCentury(Date date);
	void IncreaseDateByOneCentury();

	static Date IncreaseDateByOneMillennium(Date date);
	void IncreaseDateByOneMillennium();

	static Date DecreaseDateByOneDay(Date date);
	void DecreaseDateByOneDay();

	static Date DecreaseDateByXDays(Date date, const short& days);
	void DecreaseDateByXDays(const short& days);

	static Date DecreaseDateByOneWeek(Date date);
	void DecreaseDateByOneWeek();

	static Date DecreaseDateByXWeek(Date date, const short& weeks);
	void DecreaseDateByXWeek(const short& weeks);

	static Date DecreaseDateByOneMonth(Date date);
	void DecreaseDateByOneMonth();

	static Date DecreaseDateByXMonth(Date date, const short& months);
	void DecreaseDateByXMonth(const short& months);

	static Date DecreaseDateByOneYear(Date date);
	void DecreaseDateByOneYear();

	static Date DecreaseDateByXYear(Date date, const short& years);
	void DecreaseDateByXYear(const short& years);

	static Date DecreaseDateByXYearFaster(Date date, const short& years);
	void DecreaseDateByXYearFaster(const short& years);

	static Date DecreaseDateByOneDecade(Date date);
	void DecreaseDateByOneDecade();

	static Date DecreaseDateByXDecade(Date date, const short& decades);
	void DecreaseDateByXDecade(const short& decades);

	static Date DecreaseDateByXDecadeFaster(Date date, const short& decades);
	void DecreaseDateByXDecadeFaster(const short& decades);

	static Date DecreaseDateByOneCentury(Date date);
	void DecreaseDateByOneCentury();

	static Date DecreaseDateByOneMillennium(Date date);
	void DecreaseDateByOneMillennium();

	static int DifferenceInDays(Date date1, const Date& date2, const bool& includeEndDay = false);
	int DifferenceInDays(const Date& date, const bool& includeEndDay = false) const;

	static Date GetDate();

	static string GetDateTime();

	static bool IsEndOfWeek(const Date& date);
	bool IsEndOfWeek() const;

	static bool IsWeekend(const Date& date);
	bool IsWeekend() const;

	static bool IsBusinessDay(const Date& date);
	bool IsBusinessDay() const;

	static short DaysUntilEndOfWeek(Date date);
	short DaysUntilEndOfWeek() const;

	static short DaysUntilEndOfMonth(Date date);
	short DaysUntilEndOfMonth() const;
	
	static short DaysUntilEndOfYear(Date date);
	short DaysUntilEndOfYear() const;

	static short CalculateVacationDays(Date dateFrom, Date dateTo);
	short CalculateVacationDays(Date dateTo);

	static Date CalculateVacationReturnDate(Date date, short vecationDays);
	void CalculateVacationReturnDate(short vecationDays);

	static bool IsDate1AfterDate2(const Date& date1, const Date& date2);
	bool IsDate1AfterDate2(const Date& date2) const;

	enum class DateComparison
	{
		Before = -1,
		Equal,
		After
	};

	static DateComparison CompareDate(const Date& date1, const Date& date2);
	DateComparison CompareDate(const Date& date) const;

	static bool IsValidDate(const Date& date);
	bool IsValidDate() const;

	static string DateToString(const Date& date, const string& separator = "/");
	string DateToString(const string& separator = "/") const;

	static string FormatDate(const Date& date, const string& format = "dd-mm-yyyy");
	string FormatDate(const string& format = "dd-mm-yyyy") const;
};