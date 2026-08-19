#pragma once

#include <iostream>
#include <vector>
using namespace std;

class StringUtils
{
private:
	string _value{};

	static string _ValidateString(const string& str);

public:
	StringUtils() = default;

	StringUtils(const string& value);

	void SetValue(const string& value);

	string GetValue() const;

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static size_t Length(const string& str);

	size_t Length() const;

	static string UppercaseFirstLetterOfEachWord(string str);

	void UppercaseFirstLetterOfEachWord();

	static string LowercaseFirstLetterOfEachWord(string str);

	void LowercaseFirstLetterOfEachWord();

	static string ToUpper(string str);

	void ToUpper();

	static string ToLower(string str);

	void ToLower();

	static char InvertCase(char chr);

	static string InvertCase(string str);

	void InvertCase();

	enum class LetterCase
	{
		Uppercase = 1,
		LowerCase,
		All
	};

	static short CountLetters(const string& str, LetterCase letterCase = LetterCase::All);

	static short CountUppercase(const string& str);

	short CountUppercase() const;

	static short CountLowercase(const string& str);

	short CountLowercase() const;

	static short CountLetter(const string& str, const char& chr, const bool& matchCase = true);

	short CountLetter(const char& chr, const bool& matchCase = true) const;

	static bool IsVowel(char chr);

	static short CountVowels(const string& message);

	short CountVowels() const;

	static short CountWords(string str, const string& delimiter = " ");

	short CountWords(const string& delimiter = " ") const;

	static vector <string> Split(string str, const string& delimiter = " ");

	vector <string> Split(const string& delimiter = " ");

	static string TrimLeft(string str, const char& trimChar = ' ');

	void TrimLeft(const char& trimChar = ' ');

	static string TrimRight(string str, const char& trimChar = ' ');

	void TrimRight(const char& trimChar = ' ');

	static string Trim(string str, const char& trimChar = ' ');

	void Trim(const char& trimChar = ' ');

	static string Join(const vector <string>& vString, const string& separator = " ");

	static string Join(string arr[], const short& arrLength, const string& separator = " ");

	static string ReverseWords(const string& str, const string& separator = " ");

	void ReverseWords(const string& separator = " ");

	static string Replace(string message, const string& wordToReplace, const string& wordReplaceTo);

	string Replace(const string& wordToReplace, const string& wordReplaceTo);

	static string RemovePunctuations(const string& str);

	void RemovePunctuations();
};