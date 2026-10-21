#include <iostream>
using namespace std;

// Function for Binary Search
int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int a[100], n, key, result;

    cout << "Enter number of elements (1-100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of elements!";
        return 1;
    }

    cout << "Enter array elements in ascending order:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    // Call Binary Search function
    result = binarySearch(a, n, key);

    if (result != -1)
    {
        cout << "Element found at position "
             << result + 1 << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}