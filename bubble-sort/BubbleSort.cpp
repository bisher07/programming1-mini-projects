#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int array[], int size);

int main()
{
    int size;

    cout << "           Bubble Sorting program\n"
         << "********************************************\n\n"
         << "Enter the size of the array: ";
    cin >> size;

    int array[size];

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter the element " << i << ": ";
        cin >> array[i - 1];
        cout << endl;
    }

    cout << "********************************************\n\n"
         << "The sorted array is: ";
    bubbleSort(array, size);

    return 0;
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++) // This loop handles the swapping proccess.
        {
            if (array[j + 1] < array[j])
            {
                swap(array[j + 1], array[j]);
                continue;
            }
            else
                continue;
        }
    }

    cout << "{";
    for (int i = 0; i < size; i++)
    {
        cout << ' ' << array[i] << ' ';
    }
    cout << "\b}";
}