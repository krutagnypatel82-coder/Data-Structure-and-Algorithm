#include <iostream>
using namespace std;

// Function for Bubble Sort
void bubbleSort(int a[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function for Selection Sort
void selectionSort(int b[], int n)
{
    int minIndex, temp;

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (b[j] < b[minIndex])
            {
                minIndex = j;
            }
        }

        temp = b[i];
        b[i] = b[minIndex];
        b[minIndex] = temp;
    }
}

// Function to display the array
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int a[100], b[100], n;

    cout << "Enter number of elements (1-100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of elements!";
        return 1;
    }

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    // Call Bubble Sort function
    bubbleSort(a, n);

    // Call Selection Sort function
    selectionSort(b, n);

    cout << "\nArray after Bubble Sort: ";
    displayArray(a, n);

    cout << "Array after Selection Sort: ";
    displayArray(b, n);

    return 0;
}