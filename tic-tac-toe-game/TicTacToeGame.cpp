#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const char player = 'X';
const char computer = 'O';

void drawBoard(char spaces[]);
void getUserChoice(char spaces[]);
void getComputerChoice(char spaces[]);
bool checkForWinner(char spaces[]);
bool checkForTie(char spaces[]);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    cout << "          Tic Tac Toe" << endl
         << "********************************" << endl;

    while (true)
    {
        string result;

        drawBoard(spaces);
        getUserChoice(spaces);
        result = checkForWinner(spaces) ? "You Won!" : "Tie!";
        if (checkForWinner(spaces) || checkForTie(spaces))
        {
            cout << "********************************" << endl;
            drawBoard(spaces);
            cout << result << endl;
            break;
        }

        getComputerChoice(spaces);
        result = checkForWinner(spaces) ? "You Lost!" : "Tie!";
        if (checkForWinner(spaces) || checkForTie(spaces))
        {
            cout << "********************************" << endl;
            drawBoard(spaces);
            cout << result << endl;
            break;
        }
    }

    return 0;
}

void drawBoard(char spaces[])
{
    int index = -1;

    for (int i = 1; i <= 2; i++)
    {
        cout << "\t     |     |     " << endl
             << "\t  " << spaces[++index] << "  |" << "  " << spaces[++index] << "  |" << "  " << spaces[++index] << "  " << endl
             << "\t_____|_____|_____" << endl;
    }

    cout << "\t     |     |     " << endl
         << "\t  " << spaces[++index] << "  |" << "  " << spaces[++index] << "  |" << "  " << spaces[++index] << "  " << endl
         << "\t     |     |     " << endl;
}

void getUserChoice(char spaces[])
{
    int index;

    cout << "Enter a spot to place a marker (1-9): ";
    cin >> index;

    while (!(index >= 1 && index <= 9))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error. Please enter a number within the range (1-9): ";
        cin >> index;
    }

    while (spaces[--index] != ' ')
    {
        cout << "This spot is alrady taken. Enter another spot to place a marker (1-9): ";
        cin >> index;
    }

    spaces[index] = player;
}

void getComputerChoice(char spaces[])
{
    srand(time(0));
    int index = rand() % 10;

    while (spaces[index] != ' ')
    {
        index = rand() % 10;
    }

    spaces[index] = computer;
}

bool checkForWinner(char spaces[])
{
    bool result;

    if (spaces[0] == spaces[4] && spaces[0] == spaces[8])
        result = spaces[0] == player || spaces[0] == computer ? true : false;
    else if (spaces[2] == spaces[4] && spaces[2] == spaces[6])
        result = spaces[2] == player || spaces[2] == computer ? true : false;
    else if (spaces[0] == spaces[1] && spaces[0] == spaces[2])
        result = spaces[0] == player || spaces[0] == computer ? true : false;
    else if (spaces[3] == spaces[4] && spaces[3] == spaces[5])
        result = spaces[3] == player || spaces[3] == computer ? true : false;
    else if (spaces[6] == spaces[7] && spaces[6] == spaces[8])
        result = spaces[6] == player || spaces[6] == computer ? true : false;
    else if (spaces[0] == spaces[3] && spaces[0] == spaces[6])
        result = spaces[0] == player || spaces[0] == computer ? true : false;
    else if (spaces[1] == spaces[4] && spaces[1] == spaces[7])
        result = spaces[1] == player || spaces[1] == computer ? true : false;
    else if (spaces[2] == spaces[5] && spaces[2] == spaces[8])
        result = spaces[2] == player || spaces[2] == computer ? true : false;

    return result;
}

bool checkForTie(char spaces[])
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] != ' ')
            continue;
        else
            return false;
    }

    return true;
}