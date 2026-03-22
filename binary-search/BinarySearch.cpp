#include <iostream>
using namespace std;

int binarySearch(const int *sortedArray, int size, int target);

int main()
{
    int array[100];
    int element = 1;

    for (int i = 0; i < 100; i++)
    {
        array[i] = element;
        element++;
    }

    cout << binarySearch(array, 100, 25);

    return 0;
}

int binarySearch(const int *sortedArray, int size, int target) // Note that binary search won't work properly unless the passed array is sorted.
{
    int right = size - 1;
    int left = 0;
    int midPoint;

    while (right >= left) // When right equals left, it means all array elements have been checked, marking the final iteration of the loop.
    {
        midPoint = (right + left) / 2;
        if (target == *(sortedArray + midPoint))
            return midPoint;
        else if (target > *(sortedArray + midPoint))
            left = midPoint + 1;
        else
            right = midPoint - 1;
    }

    return -1; // -1 indicates that the target isn't found.
}