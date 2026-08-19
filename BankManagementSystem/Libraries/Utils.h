#pragma once

#include "Date.h"

#include <iostream>
using namespace std;

class Utils
{
public:
    enum class CharacterType
    {
        LowercaseLetter = 1,
        UppercaseLetter,
        SpecialCharacter,
        Digit,
        Mix
    };

	static void Srand();

	static int RandomNumber(const int& from, const int& to);

    static char GenerateRandomCharacter(CharacterType charType); 
    
    static string GenerateWord(CharacterType charType, const short& wordLength = 4);
    
    static string GenerateKey(CharacterType charType, const short& keyLength = 4);

    static void GenerateKeys(const short& numberOfKeys, CharacterType charType);

    static void Swap(int& firstNumber, int& secondNumber);

    static void Swap(double& firstNumber, double& secondNumber);

    static void Swap(string& firstString, string& secondString);

    static void Swap(Date& firstDate, Date& secondDate);

    static void Shuffle(int arr[], const short& arrLength);

    static void Shuffle(string arr[], const short& arrLength);
    
    static void FillArrayWithRandomNumbers(int arr[], const short& arrLength, const short& from, const short& to);

    static void FillArrayWithRandomWords(string arr[], const short& arrLength, CharacterType charType, const short& wordLength);

    static void FillArrayWithRandomKeys(string arr[], const short& arrLength, CharacterType charType);

    static string Tab(const short& numberOfTabs);

    static string Divider(const short& length);

    static string Encrypt(string message, const short& encryptionKey);

    static string Decrypt(string message, const short& decryptionKey);
    
    private:
        static CharacterType _GetRandomTypeForMix();
};