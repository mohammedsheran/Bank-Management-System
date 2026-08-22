#pragma once

#include "Date.h"

#include <iostream> 
using namespace std;

class InputUtils
{
public:
    static int ReadInt(const string& message);

    static short ReadShort(const string& message);

    static float ReadFloat(const string& message);

    static double ReadDouble(const string& message);

    static int ReadPositiveNumber(const string& message);

    static short ReadNumberInRange(const string& message, const short& from, const short& to);

    static int ReadNumberInRange(const string& message, const int& from, const int& to);

    static double ReadNumberInRange(const string& message, const double& from, const double& to);

    static string ReadString(const string& message);

    static char ReadChar(const string& message);

    static bool IsNumberBetween(const short& number, const short& from, const short& to);

    static bool IsNumberBetween(const int& number, const int& from, const int& to);

    static bool IsNumberBetween(const float& number, const float& from, const float& to);

    static bool IsNumberBetween(const double& number, const double& from, const double& to);

    static bool IsDateBetween(const Date& date, Date from, Date to);

    static bool IsValidDate(const Date& date);
};