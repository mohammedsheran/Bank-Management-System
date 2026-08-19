
#include "InputUtils.h"

#include "Utils.h"

#include <string>

int InputUtils::ReadInt(const string& message)
{
    int number{};

    cout << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << " Invalid Input. Please Enter A Number : ";
        cin >> number;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return number;
}

short InputUtils::ReadShort(const string& message) 
{
    short number{};

    cout << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << " Invalid Input. Please Enter A Number : ";
        cin >> number;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return number;
}

float InputUtils::ReadFloat(const string& message) 
{
    float number{};

    cout << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << " Invalid Input. Please Enter A Number : ";
        cin >> number;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return number;
}

double InputUtils::ReadDouble(const string& message)
{
    double number{};

    cout << message;
    cin >> number;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << " Invalid Input. Please Enter A Number : ";
        cin >> number;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return number;
}

int InputUtils::ReadPositiveNumber(const string& message)
{
    int number{};
    do
    {
        number = ReadInt(message);

    } while (number <= 0);

    return number;
}

int InputUtils::ReadNumberInRange(const string& message, const int& from, const int& to)
{
    int number{};

    do
    {
        number = ReadInt(message);

        if ((number < from) || (number > to)) {
            cout << " Invalid Input!\n\n";
        }

    } while ((number < from) || (number > to));

    return number;
}

double InputUtils::ReadNumberInRange(const string& message, const double& from, const double& to)
{
    double number{};

    do
    {
        number = ReadDouble(message);

        if ((number < from) || (number > to)) {
            cout << " Invalid Input!\n\n";
        }

    } while ((number < from) || (number > to));

    return number;
}

string InputUtils::ReadString(const string& message)
{
    string str{};

    cout << message;
    //cin.ignore(1, '\n');
    //cin >> ws;
    getline(cin, str);

    return str;
}

char InputUtils::ReadChar(const string& message)
{
    char chr{};

    cout << message;
    cin >> chr;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return chr;
}

bool InputUtils::IsNumberBetween(const short& number, const short& from, const short& to)
{
    return !(number < from || number > to);
}

bool InputUtils::IsNumberBetween(const int& number, const int& from, const int& to)
{
    return !(number < from || number > to);
}

bool InputUtils::IsNumberBetween(const float& number, const float& from, const float& to)
{
    return !(number < from || number > to);
}

bool InputUtils::IsNumberBetween(const double& number, const double& from, const double& to)
{
    return !(number < from || number > to);
}

bool InputUtils::IsDateBetween(const Date& date, Date from, Date to)
{
    if (!Date::IsDate1BeforeDate2(from, to))
    {
        Utils::Swap(from, to);
    }

    return !(Date::IsDate1BeforeDate2(date, from) || Date::IsDate1AfterDate2(date, to));
}

bool InputUtils::IsValidDate(const Date& date)
{
    return Date::IsValidDate(date);
}
