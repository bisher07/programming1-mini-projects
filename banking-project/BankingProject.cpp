// This project will allow the user to deposit / withdraw / checkBalance.

#include <iostream>
#include <iomanip>
using namespace std;

float balance = 0;

float deposit();
float withdraw();
void checkBalance(float balance);

int main()
{
    int userSelection;

    cout << "Welcome to ADIB" << endl;
    do
    {
        cout << "******************" << endl
             << "1. Deposit" << endl
             << "2. Withdraw" << endl
             << "3. Check Balance" << endl
             << "4. Exit" << endl
             << endl
             << "Select one option (1 - 4): ";
        cin >> userSelection;

        switch (userSelection)
        {
        case 1:
            balance += deposit();
            checkBalance(balance);
            break;
        case 2:
            balance -= withdraw();
            checkBalance(balance);
            break;
        case 3:
            checkBalance(balance);
            break;
        case 4:
            cout << endl
                 << "Thanks for visiting!";
            break;
        default:
            cout << "Please select a valid option." << endl
                 << endl;
        }

    } while (userSelection != 4);

    return 0;
}

float deposit()
{
    float money;

    cout << "Enter the amount: ";
    cin >> money;

    return money;
}

float withdraw()
{
    float money;

    cout << "Enter the amount: ";
    cin >> money;

    if (money > balance)
    {
        cerr << endl
             << "Your balance is less than this amount." << endl;
        return 0;
    }
    else
        return money;
}

void checkBalance(float balance)
{
    cout << endl
         << "Your balance is: " << "AED " << showpoint << fixed << setprecision(2) << balance << endl;
}
// showpoint --> always shows the decimal points.
// fixed --> express the number is fixed format(default format).
// setprecision(int n) --> always shows n decimal places after the decimal point. Also, it rounds the number in case there were more than n decimal places.