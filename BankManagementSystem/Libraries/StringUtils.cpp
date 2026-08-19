
#include "StringUtils.h"

string StringUtils::_ValidateString(const string& str)
{
	if (!str.empty())
	{
		return str;
	}

	throw invalid_argument("StringUtils value can not be empty.");
}

StringUtils::StringUtils(const string& value) : _value(value) {}

void StringUtils::SetValue(const string& value)
{
	_value = _ValidateString(value);
}

string StringUtils::GetValue() const
{
	return _value;
}

size_t StringUtils::Length(const string& str)
{
    return str.length();
}
 
size_t StringUtils::Length() const
{
    return Length(_value);
}

string StringUtils::UppercaseFirstLetterOfEachWord(string str) {
    if (str.empty())
    {
        return {};
    }

    bool isFirstLetter{ true };

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
        {
            str[i] = toupper(str[i]);
            isFirstLetter = false;
        }

        isFirstLetter = (str[i] == ' ') ? true : false;
    }

    return str;
}

void StringUtils::UppercaseFirstLetterOfEachWord()
{
    _value = UppercaseFirstLetterOfEachWord(_value);
}

string StringUtils::LowercaseFirstLetterOfEachWord(string str) {
    if (str.empty())
    {
        return {};
    }

    bool isFirstLetter{ true };

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && isFirstLetter)
        {
            str[i] = tolower(str[i]);
            isFirstLetter = false;
        }

        isFirstLetter = (str[i] == ' ') ? true : false;
    }

    return str;
}

void StringUtils::LowercaseFirstLetterOfEachWord()
{
    _value = LowercaseFirstLetterOfEachWord(_value);
}

string StringUtils::ToUpper(string str)
{
    if (str.empty())
    {
        return {};
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

void StringUtils::ToUpper()
{
    _value = ToUpper(_value);
}

string StringUtils::ToLower(string str)
{
    if (str.empty())
    {
        return {};
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }

    return str;
}

void StringUtils::ToLower()
{
    _value = ToLower(_value);
}

char StringUtils::InvertCase(char chr)
{
    return (isupper(chr)) ? tolower(chr) : toupper(chr);
}

string StringUtils::InvertCase(string str)
{
    if (str.empty())
    {
        return {};
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = InvertCase(str[i]);
    }

    return str;
}

void StringUtils::InvertCase()
{
    _value = InvertCase(_value);
}

short StringUtils::CountLetters(const string& str, LetterCase letterCase)
{
    if (str.empty())
    {
        return {};
    }

    short counter{};

    if (letterCase == LetterCase::All)
    {
        return static_cast<short>(str.length());
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        if (letterCase == LetterCase::Uppercase && isupper(str[i]))
        {
            counter++;
        }

        if (letterCase == LetterCase::LowerCase && islower(str[i]))
        {
            counter++;
        }
    }

    return counter;
}

short StringUtils::CountUppercase(const string& str)
{
    if (str.empty())
    {
        return {};
    }

    short counter{};

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            counter++;
        }
    }

    return counter;
}

short StringUtils::CountUppercase() const
{
    return CountUppercase(_value);
}

short StringUtils::CountLowercase(const string& str)
{
    if (str.empty())
    {
        return {};
    }

    short counter{};

    for (size_t i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
        {
            counter++;
        }
    }

    return counter;
}

short StringUtils::CountLowercase() const
{
    return CountLowercase(_value);
}

short StringUtils::CountLetter(const string& str, const char& chr, const bool& matchCase)
{
    if (str.empty())
    {
        return {};
    }

    short counter{};

    for (size_t i = 0; i < str.length(); i++)
    {
        if (matchCase)
        {
            if (str[i] == chr)
            {
                counter++;
            }
        }
        else
        {
            if (toupper(str[i]) == toupper(chr))
            {
                counter++;
            }
        }
    }

    return counter;
}

short StringUtils::CountLetter(const char& chr, const bool& matchCase) const
{
    return CountLetter(_value, chr, matchCase);
}

bool StringUtils::IsVowel(char chr)
{
    chr = tolower(chr);

    return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u');
}

short StringUtils::CountVowels(const string& str)
{
    if (str.empty())
    {
        return {};
    }

    short counter{};

    for (size_t i = 0; i < str.length(); i++)
    {
        if (IsVowel(str[i]))
        {
            counter++;
        }
    }

    return counter;
}

short StringUtils::CountVowels() const
{
    return CountVowels(_value);
}

short StringUtils::CountWords(string str, const string& delimiter)
{
    if (str.empty())
    {
        return {};
    }

    string word{};

    size_t position{};
    short counter{};

    while ((position = str.find(delimiter)) != string::npos)
    {
        word = str.substr(0, position);

        if (!word.empty())
        {
            counter++;
        }

        str.erase(0, position + delimiter.length());
    }

    if (!str.empty())
    {
        counter++;
    }

    return counter;
}

short StringUtils::CountWords(const string& delimiter) const
{
    return  CountWords(_value, delimiter);
}

vector <string> StringUtils::Split(string str, const string& delimiter)
{
    if (str.empty())
    {
        return {};
    }

    vector <string> vString{};

    string word{};
    size_t pos{};

    while ((pos = str.find(delimiter)) != string::npos)
    {
        word = str.substr(0, pos);

        if (!word.empty())
        {
            vString.push_back(move(word));
        }

        str.erase(0, pos + delimiter.length());
    }

    if (!str.empty())
    {
        vString.push_back(move(str));
    }

    return vString;
}

vector <string> StringUtils::Split(const string& delimiter)
{
    return Split(_value, delimiter);
}

string StringUtils::TrimLeft(string str, const char& trimChar) {
    if (str.empty())
    {
        return {};
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != trimChar)
        {
            return str.substr(i, str.length() - 1);
        }
    }

    return {};
}

void StringUtils::TrimLeft(const char& trimChar)
{
    _value = TrimLeft(_value, trimChar);
}
       
string StringUtils::TrimRight(string str, const char& trimChar)
{
    if (str.empty())
    {
        return {};
    }

    for (size_t i = str.length(); i-- > 0; )
    {
        if (str[i] != trimChar)
        {
            return str.substr(0, i + 1);
        }
    }

    return {};
}

void StringUtils::TrimRight(const char& trimChar)
{
    _value = TrimRight(_value, trimChar);
}
       
string StringUtils::Trim(string str, const char& trimChar)
{
    return TrimLeft(TrimRight(str));
}

void StringUtils::Trim(const char& trimChar)
{
    _value = Trim(_value, trimChar);
}

string StringUtils::Join(const vector <string>& vString, const string& separator)
{
    if (vString.empty())
    {
        return {};
    }

    string str{};

    for (const auto& word : vString)
    {
        str += word + separator;
    }

    return str.substr(0, str.length() - separator.length());
}

string StringUtils::Join(string arr[], const short& arrLength, const string& separator) 
{
    string str("");

    for (short i = 0; i < arrLength; i++)
    {
        str += arr[i] + separator;
    }

    return str.substr(0, str.length() - separator.length());
}

string StringUtils::ReverseWords(const string& str, const string& separator) 
{
    if (str.empty())
    {
        return {};
    }

    string tempraryStr("");

    vector <string> vString{ Split(str, separator) };

    vector <string>::iterator iter{ vString.end() };

    while (iter != vString.begin())
    {
        --iter;

        tempraryStr += *iter + separator;
    }

    return tempraryStr.substr(0, tempraryStr.length() - separator.length());
}

void StringUtils::ReverseWords(const string& separator)
{
    _value = ReverseWords(_value, separator);
}

string StringUtils::Replace(string str, const string& wordToReplace, const string& wordReplaceTo) {
    if (str.empty())
    {
        return {};
    }

    size_t position{};

    while ((position = str.find(wordToReplace)) != string::npos)
    {
        str = str.replace(position, wordToReplace.length(), wordReplaceTo);
    }

    return str;
}

string StringUtils::Replace(const string& wordToReplace, const string& wordReplaceTo)
{
    return Replace(_value, wordToReplace, wordReplaceTo);
}

string StringUtils::RemovePunctuations(const string& str)
{
    if (str.empty())
    {
        return {};
    }

    string tempraryStr{};

    for (size_t i = 0; i < str.length(); i++)
    {
        if (!ispunct(str[i]))
        {
            tempraryStr += str[i];
        }
    }

    return tempraryStr;
}

void StringUtils::RemovePunctuations()
{
    _value = RemovePunctuations(_value);
}