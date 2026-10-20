#include <iostream>
using namespace std;

class Array {
public:
    int size = 10;
    int target, element, insertIndex, deleteIndex, foundIndex;
    int arr[100] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    void Search() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << "\nEnter element to search :- ";
        cin >> target;

        foundIndex = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                foundIndex = i;
                break;
            }
        }
        if (foundIndex != -1)
            cout << "Element found at Index :- " << foundIndex << endl;
        else
            cout << "Element not found" << endl;
    }

    void Traversal() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void Insertion() {
        cout << "Enter element and position :- ";
        cin >> element >> insertIndex;

        if (insertIndex < 0 || insertIndex > size) {
            cout << "Invalid Position" << endl;
            return;
        }
        for (int i = size; i > insertIndex; i--) {
            arr[i] = arr[i - 1];
        }
        arr[insertIndex] = element;
        size++;

        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void Deletation() {
        cout << "Enter position to delete :- ";
        cin >> deleteIndex;

        if (deleteIndex < 0 || deleteIndex >= size) {
            cout << "Invalid Position" << endl;
            return;
        }
        for (int i = deleteIndex; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Array a;
    int ch;
    cout << "\nEnter Choice : 1.Search 2.Traversal 3.Insertion 4.Deletation :- ";
    cin >> ch;

    switch (ch) {
        case 1: a.Search(); break;
        case 2: a.Traversal(); break;
        case 3: a.Insertion(); break;
        case 4: a.Deletation(); break;
        default: cout << "Invalid Choice!" << endl; break;
    }
    return 0;
}