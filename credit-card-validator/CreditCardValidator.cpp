/*
1. Double every second digit from right to left, if doubled number is 2 digits, split them.
2. Add all single digits from step 1.
3. Add all odd numbers digits from right to left.
4. Sum results from steps 2 & 3.
5. If step 4 is divisible by 10, # is valid.

    3530    1113    3330    0000
*/

#include <iostream>
#include <string>
using namespace std;

void blanksRemover(string &cardNumber);
bool inputChecker(const string cardNumber);
int sumEvenDigits(const string cardNumber);
int sumOddDigits(const string cardNumber);

int main()
{
    string cardNumber;
    int sum = 0;

    cout << "    Credit Card Validator" << "\n***************************" << "\nEnter a credit card # : ";
    getline(cin, cardNumber);
    blanksRemover(cardNumber);

    while (!inputChecker(cardNumber))
    {
        cout << "Invalid Card Number.\nPlease enter a valid credit card number: ";
        getline(cin, cardNumber);
        blanksRemover(cardNumber);
    }

    sum = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);

    if (sum % 10 == 0)
        cout << "***************************\nThis Card Number Is Valid.";
    else
        cout << "***************************\nThis Card Number Is Invalid.";

    return 0;
}

void blanksRemover(string &cardNumber)
{
    for (int i = 0; i < cardNumber.length(); i++)
    {
        if (cardNumber[i] == ' ')
        {
            cardNumber.erase(i, 1);
            i--;
        }
    }
}

bool inputChecker(const string cardNumber)
{
    if (cardNumber.length() != 16)
        return false;
    else
    {
        for (int i = 0; i < cardNumber.length(); i++)
        {
            if (cardNumber[i] - '0' >= 0 && cardNumber[i] - '0' <= 9)
                continue;
            else
                return false;
        }
    }

    return true;
}

int sumEvenDigits(const string cardNumber)
{
    int index = cardNumber.length() - 2;
    int sum = 0;

    for (index; index >= 0; index -= 2)
    {
        if ((cardNumber[index] - '0') * 2 >= 10)
        {
            sum += (cardNumber[index] - '0') * 2 % 10;
            sum += (cardNumber[index] - '0') * 2 / 10;
        }
        else
            sum += (cardNumber[index] - '0') * 2;
    }

    return sum;
}

int sumOddDigits(const string cardNumber)
{
    int index = cardNumber.length() - 1;
    int sum = 0;

    for (index; index >= 0; index -= 2)
    {
        sum += (cardNumber[index] - '0');
    }

    return sum;
}