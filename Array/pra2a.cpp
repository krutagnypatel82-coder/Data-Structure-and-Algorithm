#include <iostream>
using namespace std;

void reverseArray(int *ptr, int size){
    cout << "Array element using reverse order :- " << endl;
    for(int i = size-1; i >= 0; i--){
        cout << *(ptr + i) << " ";
    }
}

int main(){
    int size;
    cout << "Enter size of an array :- ";
    cin >> size;
    if(size == 0){
        cout << "size of array is zero try again" << endl;
    }

    int array[size];
    cout << "Enter array elements :- ";
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }

    reverseArray(array, size);
    return 0;
}