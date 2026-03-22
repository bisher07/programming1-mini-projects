#include <iostream>
using namespace std;

long long binaryAdder(long long a, long long b);

int main()
{
    long long a, b;

    cout << "  " << "Binary Adder\n"
         << "****************\n"
         << "Enter the first binary number: ";
    cin >> a;
    cout << "Enter the second binary number: ";
    cin >> b;

    cout << "****************\n"
         << "The sum of the two binary numbers is: " << binaryAdder(a, b);

    return 0;
}

long long binaryAdder(long long a, long long b)
{
    int remainder = 0, i = 0, sum[30];
    long long longSum = 0;

    while (a != 0 || b != 0) // This loop adds the two binary numbers until atleast one of them become 0.
    {
        sum[i] = ((a % 10) + (b % 10) + remainder) % 2;
        remainder = ((a % 10) + (b % 10) + remainder) / 2;
        i++;
        a /= 10;
        b /= 10;
    }

    if (a != 0) // If a has more digits than b, then a won't become zero in the loop above. This if-statement checks for this case and add the rest of a to the sum.
    {
        sum[i] = ((a % 10) + remainder) % 2;
        remainder = ((a % 10) + remainder) / 2;
        i++;
        a /= 10;
    }

    else if (b != 0) // If b has more digits than a, then a won't become zero in the loop above. This if-statement checks for this case and add the rest of b to the sum.
    {
        sum[i] = ((b % 10) + remainder) % 2;
        remainder = ((b % 10) + remainder) / 2;
        i++;
        b /= 10;
    }

    if (remainder != 0) // This if-statement checks wether there is a remainder and add it to the sum.
    {
        sum[i] = remainder;
        i++;
    }

    i--;

    for (i; i >= 0; i--) // This loop converts the array into an integer binary number.
    {
        longSum *= 10;
        longSum += sum[i];
    }

    return longSum;
}
