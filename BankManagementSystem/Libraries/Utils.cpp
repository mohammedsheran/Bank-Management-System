
#include "Utils.h"

void Utils::Srand()
{
	srand((unsigned)time(NULL));
}

int Utils::RandomNumber(const int& from, const int& to)
{
	return rand() % (to - from + 1) + from;
}

Utils::CharacterType Utils::_GetRandomTypeForMix()
{
    return static_cast<CharacterType>(RandomNumber(1, 4));
}

char Utils::GenerateRandomCharacter(CharacterType charType)
{
    if (charType == CharacterType::Mix)
    {
        charType = _GetRandomTypeForMix();
    }

    switch (charType)
    {
    case CharacterType::LowercaseLetter:
        return (char)RandomNumber(97, 122);
    case CharacterType::UppercaseLetter:
        return (char)RandomNumber(65, 90);
    case  CharacterType::SpecialCharacter:
        return (char)RandomNumber(32, 47);
    case CharacterType::Digit:
        return (char)RandomNumber(48, 57);
    default:
        return (char)RandomNumber(97, 122);
    }
}

string Utils::GenerateWord(CharacterType charType, const short& wordLength)
{
    string word{};

    for (short counter = 0; counter < wordLength; counter++)
    {
        word += GenerateRandomCharacter(charType);
    }

    return word;
}

string Utils::GenerateKey(CharacterType charType, const short& keyLength)
{
    string key{};

    for (short counter = 1; counter <= keyLength; counter++)
    {
        if (counter != keyLength)
        {
            key += GenerateWord(charType) + '-';
        }
        else
        {
            key += GenerateWord(charType);
        }
    }
    return key;
}

void Utils::GenerateKeys(const short& numberOfKeys, CharacterType charType)
{
    for (short counter = 0; counter < numberOfKeys; counter++)
    {
        cout << "\n Key [" << counter + 1 << "] : "
            << GenerateKey(charType);
    }
}

void Utils::Swap(int& firstNumber, int& secondNumber)
{
    int tempraryNumber{ firstNumber };

    firstNumber = secondNumber;
    secondNumber = tempraryNumber;
}

void Utils::Swap(double& firstNumber, double& secondNumber)
{
    double tempraryNumber{ firstNumber };

    firstNumber = secondNumber;
    secondNumber = tempraryNumber;
}

void Utils::Swap(string& firstString, string& secondString)
{
    string tempraryString{ firstString };

    firstString = secondString;
    secondString = tempraryString;
}

void Utils::Swap(Date& firstDate, Date& secondDate)
{
    Date tempraryDate{ firstDate };

    firstDate = secondDate;
    secondDate = tempraryDate;
}

void Utils::Shuffle(int arr[], const short& arrLength)
{
    for (short counter = 0; counter < arrLength; counter++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

void Utils::Shuffle(string arr[], const short& arrLength)
{
    for (short counter = 0; counter < arrLength; counter++)
    {
        Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
    }
}

void Utils::FillArrayWithRandomNumbers(int arr[], const short& arrLength, const short& from, const short& to)
{
    for (short counter = 0; counter < arrLength; counter++)
    {
        arr[counter] = RandomNumber(from, to);
    }
}

void Utils::FillArrayWithRandomWords(string arr[], const short& arrLength, CharacterType charType, const short& wordLength)
{
    for (short counter = 0; counter < arrLength; counter++)
    {
        arr[counter] = GenerateWord(charType, wordLength);
    }
}

void Utils::FillArrayWithRandomKeys(string arr[], const short& arrLength, CharacterType charType)
{
    for (short counter = 0; counter < arrLength; counter++)
    {
        arr[counter] = GenerateKey(charType);
    }
}

string Utils::Tab(const short& numberOfTabs)
{
    return string(numberOfTabs, '\t');
}

string Utils::Divider(const short& length)
{
    return string(length, '-');
}

string Utils::Encrypt(string message, const short& encryptionKey)
{
    for (short i = 0; i < message.length(); i++)
    {
        message[i] += encryptionKey;
    }

    return message;
}

string Utils::Decrypt(string message, const short& decryptionKey)
{
    for (short i = 0; i < message.length(); i++)
    {
        message[i] -= decryptionKey;

    }

    return message;
}
